/*******************************************************************************
*   (c) 2021 Zondax GmbH
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/
#include <zxmacros.h>
#include "ristretto.h"
#include "cx.h"
#include "rslib.h"

void fe25519_add_sdk(fe25519_sdk h, const fe25519_sdk f, const fe25519_sdk g)
{
    cx_math_addm(h, f, g, ED25519_FIELD_SIZE, ED25519_SCALAR_BYTES);
}

void fe25519_sub_sdk(fe25519_sdk h, const fe25519_sdk f, const fe25519_sdk g)
{
    cx_math_subm(h, f, g, ED25519_FIELD_SIZE, ED25519_SCALAR_BYTES);
}

void fe25519_mul_sdk(fe25519_sdk h, const fe25519_sdk f, const fe25519_sdk g)
{
    cx_math_multm(h, f, g, ED25519_FIELD_SIZE, ED25519_SCALAR_BYTES);
}

void fe25519_sq_sdk(fe25519_sdk h, const fe25519_sdk f)
{
    cx_math_multm(h, f, f, ED25519_FIELD_SIZE, ED25519_SCALAR_BYTES);
}

void fe25519_1_sdk(fe25519_sdk h)
{
    MEMZERO(&h[0], sizeof(fe25519_sdk));
    h[ED25519_SCALAR_BYTES-1] = 1;
}

int fe25519_iszero_sdk(fe25519_sdk h)
{
    return cx_math_is_zero(h,ED25519_SCALAR_BYTES);
}

int fe25519_isnegative_sdk(const fe25519_sdk f)
{
    return f[ED25519_SCALAR_BYTES-1] & 1;
}

void fe25519_neg_sdk(fe25519_sdk h, const fe25519_sdk f)
{
    cx_math_subm(h, ED25519_FIELD_ZERO, f, ED25519_FIELD_SIZE, ED25519_SCALAR_BYTES);
}

void fe25519_copy_sdk(const fe25519_sdk h, const fe25519_sdk f)
{
    MEMCPY((void *) h, f, sizeof(fe25519_sdk));
}

//TODO: check this for constant-time
void fe25519_cmov_sdk(fe25519_sdk f, const fe25519_sdk g, unsigned int b)
{
    uint8_t mask = (uint8_t) (-(int8_t) b);
    uint8_t h[ED25519_SCALAR_BYTES];
    uint8_t x[ED25519_SCALAR_BYTES];
    for(int i = 0; i < ED25519_SCALAR_BYTES; i++){
        h[i] = f[i];
        x[i] = h[i] ^ g[i];
        x[i] &= mask;
        f[i] = f[i] ^ x[i];
    }
}

void fe25519_cneg_sdk(fe25519_sdk h, const fe25519_sdk f, unsigned int b)
{
    fe25519_sdk negf;

    fe25519_neg_sdk(negf, f);
    fe25519_copy_sdk(h, f);
    fe25519_cmov_sdk(h, negf, b);
}

void fe25519_abs_sdk(fe25519_sdk h, const fe25519_sdk f)
{
    fe25519_cneg_sdk(h, f, fe25519_isnegative_sdk(f));
}

void fe25519_tobytes_sdk(unsigned char *s, const fe25519_sdk f)
{
    uint8_t tmp = 0;
    MEMCPY(s, f, sizeof(fe25519_sdk));
    SWAP_ENDIAN(&s[0], tmp);
}

void fe25519_pow22523_sdk(fe25519_sdk out, const fe25519_sdk z)
{
    cx_math_powm(out, z, ED25519_POW225, ED25519_SCALAR_BYTES, ED25519_FIELD_SIZE, ED25519_SCALAR_BYTES);
}

int ristretto255_sqrt_ratio_m1_sdk(fe25519_sdk x, const fe25519_sdk u, const fe25519_sdk v)
{
    fe25519_sdk v3;
    fe25519_sdk vxx;
    fe25519_sdk m_root_check, p_root_check, f_root_check;
    fe25519_sdk x_sqrtm1;
    int     has_m_root, has_p_root, has_f_root;

    fe25519_sq_sdk(v3, v);
    fe25519_mul_sdk(v3, v3, v); /* v3 = v^3 */
    fe25519_sq_sdk(x, v3);
    fe25519_mul_sdk(x, x, u);
    fe25519_mul_sdk(x, x, v); /* x = uv^7 */

    fe25519_pow22523_sdk(x, x); /* x = (uv^7)^((q-5)/8) */
    fe25519_mul_sdk(x, x, v3);
    fe25519_mul_sdk(x, x, u); /* x = uv^3(uv^7)^((q-5)/8) */

    fe25519_sq_sdk(vxx, x);
    fe25519_mul_sdk(vxx, vxx, v); /* vx^2 */
    fe25519_sub_sdk(m_root_check, vxx, u); /* vx^2-u */
    fe25519_add_sdk(p_root_check, vxx, u); /* vx^2+u */
    fe25519_mul_sdk(f_root_check, u, fe25519_sqrtm1_sdk); /* u*sqrt(-1) */
    fe25519_add_sdk(f_root_check, vxx, f_root_check); /* vx^2+u*sqrt(-1) */
    has_m_root = fe25519_iszero_sdk(m_root_check);
    has_p_root = fe25519_iszero_sdk(p_root_check);
    has_f_root = fe25519_iszero_sdk(f_root_check);
    fe25519_mul_sdk(x_sqrtm1,x, fe25519_sqrtm1_sdk);

    fe25519_cmov_sdk(x, x_sqrtm1, has_p_root | has_f_root);
    fe25519_abs_sdk(x, x);

    return has_m_root | has_p_root;
}

void ristretto255_p3_tobytes_sdk(unsigned char *s, const ge25519_p3_sdk *h)
{
    fe25519_sdk den1, den2;
    fe25519_sdk den_inv;
    fe25519_sdk eden;
    fe25519_sdk inv_sqrt;
    fe25519_sdk ix, iy;
    fe25519_sdk one;
    fe25519_sdk s_;
    fe25519_sdk t_z_inv;
    fe25519_sdk u1, u2;
    fe25519_sdk u1_u2u2;
    fe25519_sdk x_, y_;
    fe25519_sdk x_z_inv;
    fe25519_sdk z_inv;
    fe25519_sdk zmy;
    int     rotate;

    fe25519_add_sdk(u1, h->Z, h->Y);       /* u1 = Z+Y */
    fe25519_sub_sdk(zmy, h->Z, h->Y);      /* zmy = Z-Y */
    fe25519_mul_sdk(u1, u1, zmy);          /* u1 = (Z+Y)*(Z-Y) */
    fe25519_mul_sdk(u2, h->X, h->Y);       /* u2 = X*Y */

    fe25519_sq_sdk(u1_u2u2, u2);           /* u1_u2u2 = u2^2 */
    fe25519_mul_sdk(u1_u2u2, u1, u1_u2u2); /* u1_u2u2 = u1*u2^2 */

    fe25519_1_sdk(one);
    ristretto255_sqrt_ratio_m1_sdk(inv_sqrt, one, u1_u2u2);

    fe25519_mul_sdk(den1, inv_sqrt, u1);
    fe25519_mul_sdk(den2, inv_sqrt, u2);
    fe25519_mul_sdk(z_inv, den1, den2);
    fe25519_mul_sdk(z_inv, z_inv, h->T);

    fe25519_mul_sdk(ix, h->X, fe25519_sqrtm1_sdk);
    fe25519_mul_sdk(iy, h->Y, fe25519_sqrtm1_sdk);

    fe25519_mul_sdk(eden, den1, ed25519_invsqrtamd_sdk);

    fe25519_mul_sdk(t_z_inv, h->T, z_inv);
    rotate = fe25519_isnegative_sdk(t_z_inv);

    fe25519_copy_sdk(x_, h->X);
    fe25519_copy_sdk(y_, h->Y);
    fe25519_copy_sdk(den_inv, den2);

    fe25519_cmov_sdk(x_, iy, rotate);

    fe25519_cmov_sdk(y_, ix, rotate);
    fe25519_cmov_sdk(den_inv, eden, rotate);

    fe25519_mul_sdk(x_z_inv, x_, z_inv);
    fe25519_cneg_sdk(y_, y_, fe25519_isnegative_sdk(x_z_inv));

    fe25519_sub_sdk(s_, h->Z, y_);
    fe25519_mul_sdk(s_, den_inv, s_);
    fe25519_abs_sdk(s, s_);
}


int crypto_scalarmult_ristretto255_base_sdk(unsigned char *q,const unsigned char *n)
{
    unsigned char *t = q;
    unsigned int   i;
    for (i = 0; i < ED25519_SCALAR_BYTES; ++i) {
        t[i] = n[ED25519_SCALAR_BYTES-1-i];
    }
    t[0] &= 127;

    uint8_t Pxy[ED25519_SDKPOINT_BYTES];
    memcpy(Pxy, ED25519_GEN, sizeof(Pxy));
    cx_ecfp_scalar_mult(CX_CURVE_Ed25519, Pxy, sizeof(Pxy), t, ED25519_SCALAR_BYTES);

    ge25519_p3_sdk Q_sdk;
    MEMZERO(&Q_sdk, sizeof(ge25519_p3_sdk));
    MEMCPY(Q_sdk.X, &Pxy[1],ED25519_SCALAR_BYTES);
    MEMCPY(Q_sdk.Y, &Pxy[1+ED25519_SCALAR_BYTES],ED25519_SCALAR_BYTES);
    fe25519_1_sdk(Q_sdk.Z);
    fe25519_mul_sdk(Q_sdk.T, Q_sdk.X,Q_sdk.Y);

    ristretto255_p3_tobytes_sdk(q, &Q_sdk);

    if (fe25519_iszero_sdk(q)) {
        return -1;
    }

    fe25519_tobytes_sdk(q,q);

    return 0;
}