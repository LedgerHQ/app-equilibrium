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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V1.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_EQBALANCES_V1       9  // EQ Pallet
#define PD_CALL_VESTING_V1          22 // EQ Pallet
#define PD_CALL_SUBACCOUNTS_V1      25 // EQ Pallet
#define PD_CALL_EQLOCKDROP_V1       33 // EQ Pallet

/// Pallet EqBalances
#define PD_CALL_EQBALANCES_TRANSFER_V1 0
typedef struct {
    eq_Currency_t currency;
    pd_AccountId_V1_t to;
    pd_Balance_t amount;
} pd_eqbalances_transfer_V1_t;

/// Pallet Vesting
#define PD_CALL_VESTING_VEST_V1 0
typedef struct {
} pd_vesting_vest_V1_t;

/// Pallet EqSubaccounts
#define PD_CALL_SUBACCOUNTS_TRANSFER_TO_SUBACCOUNT_V1 0
typedef struct {
    eq_Subaccount_t subAccType;
    eq_Currency_t currency;
    pd_Balance_t amount;
} pd_subaccounts_transfer_to_subaccount_V1_t;

#define PD_CALL_SUBACCOUNTS_TRANSFER_FROM_SUBACCOUNT_V1 1
typedef struct {
    eq_Subaccount_t subAccType;
    eq_Currency_t currency;
    pd_Balance_t amount;
} pd_subaccounts_transfer_from_subaccount_V1_t;

/// Pallet EqLockdrop
#define PD_CALL_EQLOCKDROP_LOCK_V1 0
typedef struct {
    pd_Balance_t amount;
} pd_eqlockdrop_lock_V1_t;

#define PD_CALL_EQLOCKDROP_UNLOCK_EXTERNAL_V1 1
typedef struct {
} pd_eqlockdrop_unlock_external_V1_t;

typedef union {
    pd_eqlockdrop_lock_V1_t eqlockdrop_lock_V1;
    pd_eqlockdrop_unlock_external_V1_t eqlockdrop_unlock_external_V1;
    pd_vesting_vest_V1_t vesting_vest_V1;
    pd_eqbalances_transfer_V1_t eqbalances_transfer_V1;
    pd_subaccounts_transfer_to_subaccount_V1_t subaccounts_transfer_to_subaccount_V1;
    pd_subaccounts_transfer_from_subaccount_V1_t subaccounts_transfer_from_subaccount_V1;
} pd_MethodBasic_V1_t;


typedef union {
} pd_MethodNested_V1_t;

typedef union {
    pd_MethodBasic_V1_t basic;
    pd_MethodNested_V1_t nested;
} pd_Method_V1_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
