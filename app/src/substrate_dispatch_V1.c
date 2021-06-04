/*******************************************************************************
*  (c) 2019 Zondax GmbH
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

#include "substrate_dispatch_V1.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

/// Pallet EqBalances
__Z_INLINE parser_error_t _readMethod_eqbalances_transfer_V1(
    parser_context_t* c, pd_eqbalances_transfer_V1_t* m)
{
    CHECK_ERROR(_readCurrency(c, &m->currency));
    CHECK_ERROR(_readAccountId_V1(c, &m->to));
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

/// Pallet Vesting
__Z_INLINE parser_error_t _readMethod_vesting_vest_V1(
    parser_context_t* c, pd_vesting_vest_V1_t* m)
{
    return parser_ok;
}

/// Pallet Subaccounts
__Z_INLINE parser_error_t _readMethod_subaccounts_transfer_to_subaccount_V1(
    parser_context_t* c, pd_subaccounts_transfer_to_subaccount_V1_t* m)
{
    CHECK_ERROR(_readSubAccount_V1(c, &m->subAccType));
    CHECK_ERROR(_readCurrency(c, &m->currency));
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_subaccounts_transfer_from_subaccount_V1(
        parser_context_t* c, pd_subaccounts_transfer_from_subaccount_V1_t* m)
{
    CHECK_ERROR(_readSubAccount_V1(c, &m->subAccType));
    CHECK_ERROR(_readCurrency(c, &m->currency));
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}


/// Pallet EqLockdrop
__Z_INLINE parser_error_t _readMethod_eqlockdrop_lock_V1(
    parser_context_t* c, pd_eqlockdrop_lock_V1_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_eqlockdrop_unlock_external_V1(
    parser_context_t* c, pd_eqlockdrop_unlock_external_V1_t* m)
{
    return parser_ok;
}


parser_error_t _readMethod_V1(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V1_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    /// Pallet EqBalances
    case 2304: /* module 9 call 0 */
        CHECK_ERROR(_readMethod_eqbalances_transfer_V1(c, &method->basic.eqbalances_transfer_V1))
        break;

    /// Pallet Vesting
    case 5632: /* module 22 call 0 */
        CHECK_ERROR(_readMethod_vesting_vest_V1(c, &method->basic.vesting_vest_V1))
        break;

    /// Pallet Subaccounts
    case 6400: /* module 25 call 0 */
        CHECK_ERROR(_readMethod_subaccounts_transfer_to_subaccount_V1(c, &method->basic.subaccounts_transfer_to_subaccount_V1))
        break;
    case 6401: /* module 25 call 1 */
        CHECK_ERROR(_readMethod_subaccounts_transfer_from_subaccount_V1(c, &method->basic.subaccounts_transfer_from_subaccount_V1))
        break;


    /// Pallet EqLockdrop
    case 8448: /* module 33 call 0 */
        CHECK_ERROR(_readMethod_eqlockdrop_lock_V1(c, &method->basic.eqlockdrop_lock_V1))
        break;
    case 8449: /* module 33 call 1 */
        CHECK_ERROR(_readMethod_eqlockdrop_unlock_external_V1(c, &method->basic.eqlockdrop_unlock_external_V1))
        break;


    default:
        return parser_not_supported;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V1(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 9:
        return STR_MO_EQBALANCES;
    case 22:
        return STR_MO_VESTING;
    case 25:
        return STR_MO_SUBACCOUNTS;
    case 33:
        return STR_MO_EQLOCKDROP;

    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2304: /* module 9 call 0 */    // EqBalances:transfer
        return STR_ME_TRANSFER;
    case 5632: /* module 22 call 0 */   // Vesting:vest
        return STR_ME_VEST;

    case 6400: /* module 25 call 0 */
        return STR_ME_TRANSFER_TO_SUBACCOUNT;     // Subaccounts:transfer_to_subaccount
    case 6401: /* module 25 call 1 */
        return STR_ME_TRANSFER_FROM_SUBACCOUNT;   // Subaccounts:transfer_from_subaccount

    case 8448: /* module 33 call 0 */ // EqLockdrop:lock
        return STR_ME_LOCK;
    case 8449: /* module 33 call 1 */ // EqLockdrop:unlock_external
        return STR_ME_UNLOCK_EXTERNAL;

    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2304: /* module 9 call 0 */ // EqBalances:transfer
        return 3;
    case 5632: /* module 22 call 0 */ // EqVesting:vest
        return 0;
    case 6400: /* module 25 call 0 */ // EqSubaccounts:transfer_to_subaccount
        return 3;
    case 6401: /* module 25 call 1 */ // EqSubaccounts:transfer_from_subaccount
        return 3;
    case 8448: /* module 33 call 0 */ // EqLockdrop:lock
        return 1;
    case 8449: /* module 33 call 0 */ // EqLockdrop:unlock_external
        return 0;
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V1(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 2304: /* module 9 call 0 */ // EqBalances:transfer(currency, to, amount)
        switch (itemIdx) {
            case 0:
                return STR_IT_currency;
            case 1:
                return STR_IT_to;
            case 2:
                return STR_IT_value;
            default:
                return NULL;
        }
    case 6400: /* module 25 call 0 */ // Subaccounts:transfer_to_subaccount  (SubAccType, Currency, amount)
    case 6401: /* module 25 call 1 */ // Subaccounts:transfer_from_subaccount(SubAccType, Currency, amount)
        switch (itemIdx) {
            case 0:
                return STR_IT_subaccount;
            case 1:
                return STR_IT_currency;
            case 2:
                return STR_IT_value;
            default:
                return NULL;
        }
    case 8448: /* module 33 call 0 */ // EqLockdrop:lock(amount)
        switch (itemIdx)
        {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V1(
    pd_Method_V1_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 2304: /* module 9 call 0 */ // EqBalances:transfer(currency, to, amount)
        switch (itemIdx) {
            case 0: /* utility_batch_V1 - calls */;
                return _toStringCurrency_V1(
                        &m->basic.eqbalances_transfer_V1.currency,
                        outValue, outValueLen,
                        pageIdx, pageCount);
            case 1:
                return _toStringAccountId_V1(
                        &m->basic.eqbalances_transfer_V1.to,
                        outValue, outValueLen,
                        pageIdx, pageCount);
            case 2:
                return _toStringBalanceCurrency_V1(
                        &m->basic.eqbalances_transfer_V1.amount,
                        &m->basic.eqbalances_transfer_V1.currency,
                        outValue, outValueLen,
                        pageIdx, pageCount);
            default:
                return parser_no_data;
        }
        case 6400: /* module 25 call 0 */ // Subaccounts:transfer_to_subaccount  (SubAccType, Currency, amount)
        case 6401: /* module 25 call 1 */ // Subaccounts:transfer_from_subaccount(SubAccType, Currency, amount)
            switch (itemIdx) {
                case 0: /* utility_batch_V1 - calls */;
                    return _toStringSubaccount_V1(
                            &m->basic.subaccounts_transfer_to_subaccount_V1.subAccType,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1:
                    return _toStringCurrency_V1(
                            &m->basic.subaccounts_transfer_to_subaccount_V1.currency,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2:
                    return _toStringBalanceCurrency_V1(
                            &m->basic.subaccounts_transfer_to_subaccount_V1.amount,
                            &m->basic.subaccounts_transfer_to_subaccount_V1.currency,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
    case 8448: /* module 33 call 0 */ // EqLockdrop:lock(amount)
        switch (itemIdx)
        {
        case 0 /* eqlockdrop_lock_V1 */:
            return _toStringBalance(
                &m->basic.eqlockdrop_lock_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V1(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    return false;
}

bool _getMethod_IsNestingSupported_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2304: // EQBalances:transfer
    case 5632: // EQVesting:vest
    case 8448: // EQLockdrop:Lock
    case 8449: // EQLockdrop:Unlock external
        return false;
    default:
        return true;
    }
}
