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

#define PD_CALL_SYSTEM_V1 0
#define PD_CALL_BABE_V1 1
#define PD_CALL_TIMESTAMP_V1 2
#define PD_CALL_INDICES_V1 3
#define PD_CALL_BALANCES_V1 4
#define PD_CALL_AUTHORSHIP_V1 5
#define PD_CALL_STAKING_V1 6
#define PD_CALL_OFFENCES_V1 7
#define PD_CALL_SESSION_V1 8
#define PD_CALL_GRANDPA_V1 10
#define PD_CALL_IMONLINE_V1 11
#define PD_CALL_AUTHORITYDISCOVERY_V1 12
#define PD_CALL_DEMOCRACY_V1 13
#define PD_CALL_COUNCIL_V1 14
#define PD_CALL_TECHNICALCOMMITTEE_V1 15
#define PD_CALL_PHRAGMENELECTION_V1 16
#define PD_CALL_TECHNICALMEMBERSHIP_V1 17
#define PD_CALL_TREASURY_V1 18
#define PD_CALL_CLAIMS_V1 19
#define PD_CALL_UTILITY_V1 24
#define PD_CALL_IDENTITY_V1 25
#define PD_CALL_SOCIETY_V1 26
#define PD_CALL_RECOVERY_V1 27
#define PD_CALL_VESTING_V1 28
#define PD_CALL_SCHEDULER_V1 29
#define PD_CALL_PROXY_V1 30
#define PD_CALL_MULTISIG_V1 31
#define PD_CALL_EQLOCKDROP_V1 33 // EQ Pallete
#define PD_CALL_BOUNTIES_V1 35
#define PD_CALL_TIPS_V1 36
#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_V1 37
#define PD_CALL_GILT_V1 38
#define PD_CALL_PARACHAINSCONFIGURATION_V1 51
#define PD_CALL_PARASSHARED_V1 52
#define PD_CALL_PARASINCLUSION_V1 53
#define PD_CALL_PARASINHERENT_V1 54
#define PD_CALL_PARASSCHEDULER_V1 55
#define PD_CALL_PARAS_V1 56
#define PD_CALL_PARASINITIALIZER_V1 57
#define PD_CALL_PARASDMP_V1 58
#define PD_CALL_PARASUMP_V1 59
#define PD_CALL_PARASHRMP_V1 60
#define PD_CALL_PARASSESSIONINFO_V1 61
#define PD_CALL_REGISTRAR_V1 70
#define PD_CALL_SLOTS_V1 71
#define PD_CALL_AUCTIONS_V1 72
#define PD_CALL_CROWDLOAN_V1 73
#define PD_CALL_XCMPALLET_V1 99

#define PD_CALL_STAKING_BOND_V1 0
typedef struct {
    pd_LookupSource_V1_t controller;
    pd_CompactBalanceOf_t value;
    pd_RewardDestination_V1_t payee;
} pd_staking_bond_V1_t;

#define PD_CALL_STAKING_BOND_EXTRA_V1 1
typedef struct {
    pd_CompactBalanceOf_t max_additional;
} pd_staking_bond_extra_V1_t;

#define PD_CALL_STAKING_UNBOND_V1 2
typedef struct {
    pd_CompactBalanceOf_t value;
} pd_staking_unbond_V1_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V1 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V1_t;

#define PD_CALL_STAKING_VALIDATE_V1 4
typedef struct {
    pd_ValidatorPrefs_V1_t prefs;
} pd_staking_validate_V1_t;

#define PD_CALL_STAKING_NOMINATE_V1 5
typedef struct {
    pd_VecLookupSource_V1_t targets;
} pd_staking_nominate_V1_t;

#define PD_CALL_STAKING_CHILL_V1 6
typedef struct {
} pd_staking_chill_V1_t;

#define PD_CALL_STAKING_SET_PAYEE_V1 7
typedef struct {
    pd_RewardDestination_V1_t payee;
} pd_staking_set_payee_V1_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V1 18
typedef struct {
    pd_AccountId_V1_t validator_stash;
    pd_EraIndex_V1_t era;
} pd_staking_payout_stakers_V1_t;

#define PD_CALL_STAKING_REBOND_V1 19
typedef struct {
    pd_CompactBalanceOf_t value;
} pd_staking_rebond_V1_t;

#define PD_CALL_SESSION_SET_KEYS_V1 0
typedef struct {
    pd_Keys_V1_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V1_t;

#define PD_CALL_SESSION_PURGE_KEYS_V1 1
typedef struct {
} pd_session_purge_keys_V1_t;

#define PD_CALL_UTILITY_BATCH_V1 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V1_t;

#define PD_CALL_UTILITY_BATCH_ALL_V1 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V1_t;

#define PD_CALL_EQLOCKDROP_LOCK_V1 0
typedef struct {
    pd_Balance_t amount;
} pd_eqlockdrop_lock_V1_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V1 9
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_with_event_V1_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION_V1 0
typedef struct {
    pd_BabeEquivocationProof_V1_t equivocation_proof;
    pd_KeyOwnerProof_V1_t key_owner_proof;
} pd_babe_report_equivocation_V1_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION_UNSIGNED_V1 1
typedef struct {
    pd_BabeEquivocationProof_V1_t equivocation_proof;
    pd_KeyOwnerProof_V1_t key_owner_proof;
} pd_babe_report_equivocation_unsigned_V1_t;

#define PD_CALL_BABE_PLAN_CONFIG_CHANGE_V1 2
typedef struct {
    pd_NextConfigDescriptor_V1_t config;
} pd_babe_plan_config_change_V1_t;

#define PD_CALL_TIMESTAMP_SET_V1 0
typedef struct {
    pd_CompactMoment_V1_t now;
} pd_timestamp_set_V1_t;

#define PD_CALL_INDICES_CLAIM_V1 0
typedef struct {
    pd_AccountIndex_V1_t index;
} pd_indices_claim_V1_t;

#define PD_CALL_INDICES_TRANSFER_V1 1
typedef struct {
    pd_AccountId_V1_t new_;
    pd_AccountIndex_V1_t index;
} pd_indices_transfer_V1_t;

#define PD_CALL_INDICES_FREE_V1 2
typedef struct {
    pd_AccountIndex_V1_t index;
} pd_indices_free_V1_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V1 3
typedef struct {
    pd_AccountId_V1_t new_;
    pd_AccountIndex_V1_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V1_t;

#define PD_CALL_INDICES_FREEZE_V1 4
typedef struct {
    pd_AccountIndex_V1_t index;
} pd_indices_freeze_V1_t;

#define PD_CALL_AUTHORSHIP_SET_UNCLES_V1 0
typedef struct {
    pd_VecHeader_t new_uncles;
} pd_authorship_set_uncles_V1_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V1 8
typedef struct {
    pd_LookupSource_V1_t controller;
} pd_staking_set_controller_V1_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V1 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V1_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V1 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V1_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT_V1 11
typedef struct {
    pd_Percent_V1_t factor;
} pd_staking_scale_validator_count_V1_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V1 12
typedef struct {
} pd_staking_force_no_eras_V1_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V1 13
typedef struct {
} pd_staking_force_new_era_V1_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V1 14
typedef struct {
    pd_VecAccountId_V1_t invulnerables;
} pd_staking_set_invulnerables_V1_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V1 15
typedef struct {
    pd_AccountId_V1_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V1_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V1 16
typedef struct {
} pd_staking_force_new_era_always_V1_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V1 17
typedef struct {
    pd_EraIndex_V1_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V1_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V1 20
typedef struct {
    pd_CompactEraIndex_V1_t new_history_depth;
    pd_Compactu32_t _era_items_deleted;
} pd_staking_set_history_depth_V1_t;

#define PD_CALL_STAKING_REAP_STASH_V1 21
typedef struct {
    pd_AccountId_V1_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V1_t;

#define PD_CALL_STAKING_KICK_V1 22
typedef struct {
    pd_VecLookupSource_V1_t who;
} pd_staking_kick_V1_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_V1 0
typedef struct {
    pd_GrandpaEquivocationProof_V1_t equivocation_proof;
    pd_KeyOwnerProof_V1_t key_owner_proof;
} pd_grandpa_report_equivocation_V1_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_UNSIGNED_V1 1
typedef struct {
    pd_GrandpaEquivocationProof_V1_t equivocation_proof;
    pd_KeyOwnerProof_V1_t key_owner_proof;
} pd_grandpa_report_equivocation_unsigned_V1_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V1 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V1_t;

#define PD_CALL_IMONLINE_HEARTBEAT_V1 0
typedef struct {
    pd_Heartbeat_t heartbeat;
    pd_Signature_V1_t _signature;
} pd_imonline_heartbeat_V1_t;

#define PD_CALL_DEMOCRACY_PROPOSE_V1 0
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactBalanceOf_t value;
} pd_democracy_propose_V1_t;

#define PD_CALL_DEMOCRACY_SECOND_V1 1
typedef struct {
    pd_CompactPropIndex_V1_t proposal;
    pd_Compactu32_t seconds_upper_bound;
} pd_democracy_second_V1_t;

#define PD_CALL_DEMOCRACY_VOTE_V1 2
typedef struct {
    pd_CompactReferendumIndex_V1_t ref_index;
    pd_AccountVote_V1_t vote;
} pd_democracy_vote_V1_t;

#define PD_CALL_DEMOCRACY_EMERGENCY_CANCEL_V1 3
typedef struct {
    pd_ReferendumIndex_V1_t ref_index;
} pd_democracy_emergency_cancel_V1_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_V1 4
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_V1_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_MAJORITY_V1 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_majority_V1_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_DEFAULT_V1 6
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_default_V1_t;

#define PD_CALL_DEMOCRACY_FAST_TRACK_V1 7
typedef struct {
    pd_Hash_t proposal_hash;
    pd_BlockNumber_t voting_period;
    pd_BlockNumber_t delay;
} pd_democracy_fast_track_V1_t;

#define PD_CALL_DEMOCRACY_VETO_EXTERNAL_V1 8
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_veto_external_V1_t;

#define PD_CALL_DEMOCRACY_CANCEL_REFERENDUM_V1 9
typedef struct {
    pd_CompactReferendumIndex_V1_t ref_index;
} pd_democracy_cancel_referendum_V1_t;

#define PD_CALL_DEMOCRACY_CANCEL_QUEUED_V1 10
typedef struct {
    pd_ReferendumIndex_V1_t which;
} pd_democracy_cancel_queued_V1_t;

#define PD_CALL_DEMOCRACY_DELEGATE_V1 11
typedef struct {
    pd_AccountId_V1_t to;
    pd_Conviction_V1_t conviction;
    pd_BalanceOf_t balance;
} pd_democracy_delegate_V1_t;

#define PD_CALL_DEMOCRACY_UNDELEGATE_V1 12
typedef struct {
} pd_democracy_undelegate_V1_t;

#define PD_CALL_DEMOCRACY_CLEAR_PUBLIC_PROPOSALS_V1 13
typedef struct {
} pd_democracy_clear_public_proposals_V1_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_V1 14
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_V1_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_OPERATIONAL_V1 15
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_operational_V1_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_V1 16
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_V1_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_OPERATIONAL_V1 17
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_operational_V1_t;

#define PD_CALL_DEMOCRACY_REAP_PREIMAGE_V1 18
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t proposal_len_upper_bound;
} pd_democracy_reap_preimage_V1_t;

#define PD_CALL_DEMOCRACY_UNLOCK_V1 19
typedef struct {
    pd_AccountId_V1_t target;
} pd_democracy_unlock_V1_t;

#define PD_CALL_DEMOCRACY_REMOVE_VOTE_V1 20
typedef struct {
    pd_ReferendumIndex_V1_t index;
} pd_democracy_remove_vote_V1_t;

#define PD_CALL_DEMOCRACY_REMOVE_OTHER_VOTE_V1 21
typedef struct {
    pd_AccountId_V1_t target;
    pd_ReferendumIndex_V1_t index;
} pd_democracy_remove_other_vote_V1_t;

#define PD_CALL_DEMOCRACY_ENACT_PROPOSAL_V1 22
typedef struct {
    pd_Hash_t proposal_hash;
    pd_ReferendumIndex_V1_t index;
} pd_democracy_enact_proposal_V1_t;

#define PD_CALL_DEMOCRACY_BLACKLIST_V1 23
typedef struct {
    pd_Hash_t proposal_hash;
    pd_OptionReferendumIndex_V1_t maybe_ref_index;
} pd_democracy_blacklist_V1_t;

#define PD_CALL_DEMOCRACY_CANCEL_PROPOSAL_V1 24
typedef struct {
    pd_CompactPropIndex_V1_t prop_index;
} pd_democracy_cancel_proposal_V1_t;

#define PD_CALL_COUNCIL_SET_MEMBERS_V1 0
typedef struct {
    pd_VecAccountId_V1_t new_members;
    pd_OptionAccountId_V1_t prime;
    pd_MemberCount_V1_t old_count;
} pd_council_set_members_V1_t;

#define PD_CALL_COUNCIL_EXECUTE_V1 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_execute_V1_t;

#define PD_CALL_COUNCIL_PROPOSE_V1 2
typedef struct {
    pd_CompactMemberCount_V1_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_propose_V1_t;

#define PD_CALL_COUNCIL_VOTE_V1 3
typedef struct {
    pd_Hash_t proposal;
    pd_CompactProposalIndex_V1_t index;
    pd_bool_t approve;
} pd_council_vote_V1_t;

#define PD_CALL_COUNCIL_CLOSE_V1 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactProposalIndex_V1_t index;
    pd_CompactWeight_V1_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_V1_t;

#define PD_CALL_COUNCIL_DISAPPROVE_PROPOSAL_V1 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_council_disapprove_proposal_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V1 0
typedef struct {
    pd_VecAccountId_V1_t new_members;
    pd_OptionAccountId_V1_t prime;
    pd_MemberCount_V1_t old_count;
} pd_technicalcommittee_set_members_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V1 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V1 2
typedef struct {
    pd_CompactMemberCount_V1_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V1 3
typedef struct {
    pd_Hash_t proposal;
    pd_CompactProposalIndex_V1_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V1 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactProposalIndex_V1_t index;
    pd_CompactWeight_V1_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V1 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V1_t;

#define PD_CALL_PHRAGMENELECTION_VOTE_V1 0
typedef struct {
    pd_VecAccountId_V1_t votes;
    pd_CompactBalanceOf_t value;
} pd_phragmenelection_vote_V1_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_VOTER_V1 1
typedef struct {
} pd_phragmenelection_remove_voter_V1_t;

#define PD_CALL_PHRAGMENELECTION_SUBMIT_CANDIDACY_V1 2
typedef struct {
    pd_Compactu32_t candidate_count;
} pd_phragmenelection_submit_candidacy_V1_t;

#define PD_CALL_PHRAGMENELECTION_RENOUNCE_CANDIDACY_V1 3
typedef struct {
    pd_Renouncing_V1_t renouncing;
} pd_phragmenelection_renounce_candidacy_V1_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_MEMBER_V1 4
typedef struct {
    pd_LookupSource_V1_t who;
    pd_bool_t has_replacement;
} pd_phragmenelection_remove_member_V1_t;

#define PD_CALL_PHRAGMENELECTION_CLEAN_DEFUNCT_VOTERS_V1 5
typedef struct {
    pd_u32_t _num_voters;
    pd_u32_t _num_defunct;
} pd_phragmenelection_clean_defunct_voters_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V1 0
typedef struct {
    pd_AccountId_V1_t who;
} pd_technicalmembership_add_member_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V1 1
typedef struct {
    pd_AccountId_V1_t who;
} pd_technicalmembership_remove_member_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V1 2
typedef struct {
    pd_AccountId_V1_t remove;
    pd_AccountId_V1_t add;
} pd_technicalmembership_swap_member_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V1 3
typedef struct {
    pd_VecAccountId_V1_t members;
} pd_technicalmembership_reset_members_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V1 4
typedef struct {
    pd_AccountId_V1_t new_;
} pd_technicalmembership_change_key_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V1 5
typedef struct {
    pd_AccountId_V1_t who;
} pd_technicalmembership_set_prime_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V1 6
typedef struct {
} pd_technicalmembership_clear_prime_V1_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V1 0
typedef struct {
    pd_CompactBalanceOf_t value;
    pd_LookupSource_V1_t beneficiary;
} pd_treasury_propose_spend_V1_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V1 1
typedef struct {
    pd_CompactProposalIndex_V1_t proposal_id;
} pd_treasury_reject_proposal_V1_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V1 2
typedef struct {
    pd_CompactProposalIndex_V1_t proposal_id;
} pd_treasury_approve_proposal_V1_t;

#define PD_CALL_CLAIMS_CLAIM_V1 0
typedef struct {
    pd_AccountId_V1_t dest;
    pd_EcdsaSignature_V1_t ethereum_signature;
} pd_claims_claim_V1_t;

#define PD_CALL_CLAIMS_MINT_CLAIM_V1 1
typedef struct {
    pd_EthereumAddress_V1_t who;
    pd_BalanceOf_t value;
    pd_OptionTupleBalanceOfBalanceOfBlockNumber_V1_t vesting_schedule;
    pd_OptionStatementKind_V1_t statement;
} pd_claims_mint_claim_V1_t;

#define PD_CALL_CLAIMS_CLAIM_ATTEST_V1 2
typedef struct {
    pd_AccountId_V1_t dest;
    pd_EcdsaSignature_V1_t ethereum_signature;
    pd_Bytes_t statement;
} pd_claims_claim_attest_V1_t;

#define PD_CALL_CLAIMS_ATTEST_V1 3
typedef struct {
    pd_Bytes_t statement;
} pd_claims_attest_V1_t;

#define PD_CALL_CLAIMS_MOVE_CLAIM_V1 4
typedef struct {
    pd_EthereumAddress_V1_t old;
    pd_EthereumAddress_V1_t new_;
    pd_OptionAccountId_V1_t maybe_preclaim;
} pd_claims_move_claim_V1_t;

#define PD_CALL_UTILITY_AS_DERIVATIVE_V1 1
typedef struct {
    pd_u16_t index;
    pd_Call_t call;
} pd_utility_as_derivative_V1_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V1 0
typedef struct {
    pd_AccountId_V1_t account;
} pd_identity_add_registrar_V1_t;

#define PD_CALL_IDENTITY_SET_IDENTITY_V1 1
typedef struct {
    pd_IdentityInfo_V1_t info;
} pd_identity_set_identity_V1_t;

#define PD_CALL_IDENTITY_SET_SUBS_V1 2
typedef struct {
    pd_VecTupleAccountIdData_V1_t subs;
} pd_identity_set_subs_V1_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V1 3
typedef struct {
} pd_identity_clear_identity_V1_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V1 4
typedef struct {
    pd_CompactRegistrarIndex_V1_t reg_index;
    pd_CompactBalanceOf_t max_fee;
} pd_identity_request_judgement_V1_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V1 5
typedef struct {
    pd_RegistrarIndex_V1_t reg_index;
} pd_identity_cancel_request_V1_t;

#define PD_CALL_IDENTITY_SET_FEE_V1 6
typedef struct {
    pd_CompactRegistrarIndex_V1_t index;
    pd_CompactBalanceOf_t fee;
} pd_identity_set_fee_V1_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V1 7
typedef struct {
    pd_CompactRegistrarIndex_V1_t index;
    pd_AccountId_V1_t new_;
} pd_identity_set_account_id_V1_t;

#define PD_CALL_IDENTITY_SET_FIELDS_V1 8
typedef struct {
    pd_CompactRegistrarIndex_V1_t index;
    pd_IdentityFields_V1_t fields;
} pd_identity_set_fields_V1_t;

#define PD_CALL_IDENTITY_PROVIDE_JUDGEMENT_V1 9
typedef struct {
    pd_CompactRegistrarIndex_V1_t reg_index;
    pd_LookupSource_V1_t target;
    pd_IdentityJudgement_V1_t judgement;
} pd_identity_provide_judgement_V1_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V1 10
typedef struct {
    pd_LookupSource_V1_t target;
} pd_identity_kill_identity_V1_t;

#define PD_CALL_IDENTITY_ADD_SUB_V1 11
typedef struct {
    pd_LookupSource_V1_t sub;
    pd_Data_t data;
} pd_identity_add_sub_V1_t;

#define PD_CALL_IDENTITY_RENAME_SUB_V1 12
typedef struct {
    pd_LookupSource_V1_t sub;
    pd_Data_t data;
} pd_identity_rename_sub_V1_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V1 13
typedef struct {
    pd_LookupSource_V1_t sub;
} pd_identity_remove_sub_V1_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V1 14
typedef struct {
} pd_identity_quit_sub_V1_t;

#define PD_CALL_SOCIETY_BID_V1 0
typedef struct {
    pd_BalanceOf_t value;
} pd_society_bid_V1_t;

#define PD_CALL_SOCIETY_UNBID_V1 1
typedef struct {
    pd_u32_t pos;
} pd_society_unbid_V1_t;

#define PD_CALL_SOCIETY_VOUCH_V1 2
typedef struct {
    pd_AccountId_V1_t who;
    pd_BalanceOf_t value;
    pd_BalanceOf_t tip;
} pd_society_vouch_V1_t;

#define PD_CALL_SOCIETY_UNVOUCH_V1 3
typedef struct {
    pd_u32_t pos;
} pd_society_unvouch_V1_t;

#define PD_CALL_SOCIETY_VOTE_V1 4
typedef struct {
    pd_LookupSource_V1_t candidate;
    pd_bool_t approve;
} pd_society_vote_V1_t;

#define PD_CALL_SOCIETY_DEFENDER_VOTE_V1 5
typedef struct {
    pd_bool_t approve;
} pd_society_defender_vote_V1_t;

#define PD_CALL_SOCIETY_PAYOUT_V1 6
typedef struct {
} pd_society_payout_V1_t;

#define PD_CALL_SOCIETY_FOUND_V1 7
typedef struct {
    pd_AccountId_V1_t founder;
    pd_u32_t max_members;
    pd_Bytes_t rules;
} pd_society_found_V1_t;

#define PD_CALL_SOCIETY_UNFOUND_V1 8
typedef struct {
} pd_society_unfound_V1_t;

#define PD_CALL_SOCIETY_JUDGE_SUSPENDED_MEMBER_V1 9
typedef struct {
    pd_AccountId_V1_t who;
    pd_bool_t forgive;
} pd_society_judge_suspended_member_V1_t;

#define PD_CALL_SOCIETY_JUDGE_SUSPENDED_CANDIDATE_V1 10
typedef struct {
    pd_AccountId_V1_t who;
    pd_SocietyJudgement_V1_t judgement;
} pd_society_judge_suspended_candidate_V1_t;

#define PD_CALL_SOCIETY_SET_MAX_MEMBERS_V1 11
typedef struct {
    pd_u32_t max;
} pd_society_set_max_members_V1_t;

#define PD_CALL_RECOVERY_AS_RECOVERED_V1 0
typedef struct {
    pd_AccountId_V1_t account;
    pd_Call_t call;
} pd_recovery_as_recovered_V1_t;

#define PD_CALL_RECOVERY_SET_RECOVERED_V1 1
typedef struct {
    pd_AccountId_V1_t lost;
    pd_AccountId_V1_t rescuer;
} pd_recovery_set_recovered_V1_t;

#define PD_CALL_RECOVERY_CREATE_RECOVERY_V1 2
typedef struct {
    pd_VecAccountId_V1_t friends;
    pd_u16_t threshold;
    pd_BlockNumber_t delay_period;
} pd_recovery_create_recovery_V1_t;

#define PD_CALL_RECOVERY_INITIATE_RECOVERY_V1 3
typedef struct {
    pd_AccountId_V1_t account;
} pd_recovery_initiate_recovery_V1_t;

#define PD_CALL_RECOVERY_VOUCH_RECOVERY_V1 4
typedef struct {
    pd_AccountId_V1_t lost;
    pd_AccountId_V1_t rescuer;
} pd_recovery_vouch_recovery_V1_t;

#define PD_CALL_RECOVERY_CLAIM_RECOVERY_V1 5
typedef struct {
    pd_AccountId_V1_t account;
} pd_recovery_claim_recovery_V1_t;

#define PD_CALL_RECOVERY_CLOSE_RECOVERY_V1 6
typedef struct {
    pd_AccountId_V1_t rescuer;
} pd_recovery_close_recovery_V1_t;

#define PD_CALL_RECOVERY_REMOVE_RECOVERY_V1 7
typedef struct {
} pd_recovery_remove_recovery_V1_t;

#define PD_CALL_RECOVERY_CANCEL_RECOVERED_V1 8
typedef struct {
    pd_AccountId_V1_t account;
} pd_recovery_cancel_recovered_V1_t;

#define PD_CALL_VESTING_VEST_V1 0
typedef struct {
} pd_vesting_vest_V1_t;

#define PD_CALL_VESTING_VEST_OTHER_V1 1
typedef struct {
    pd_LookupSource_V1_t target;
} pd_vesting_vest_other_V1_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V1 2
typedef struct {
    pd_LookupSource_V1_t target;
    pd_VestingInfo_V1_t schedule;
} pd_vesting_vested_transfer_V1_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER_V1 3
typedef struct {
    pd_LookupSource_V1_t source;
    pd_LookupSource_V1_t target;
    pd_VestingInfo_V1_t schedule;
} pd_vesting_force_vested_transfer_V1_t;

#define PD_CALL_SCHEDULER_SCHEDULE_V1 0
typedef struct {
    pd_BlockNumber_t when;
    pd_OptionPeriod_V1_t maybe_periodic;
    pd_Priority_V1_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_V1_t;

#define PD_CALL_SCHEDULER_CANCEL_V1 1
typedef struct {
    pd_BlockNumber_t when;
    pd_u32_t index;
} pd_scheduler_cancel_V1_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_V1 2
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t when;
    pd_OptionPeriod_V1_t maybe_periodic;
    pd_Priority_V1_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_named_V1_t;

#define PD_CALL_SCHEDULER_CANCEL_NAMED_V1 3
typedef struct {
    pd_Bytes_t id;
} pd_scheduler_cancel_named_V1_t;

#define PD_CALL_SCHEDULER_SCHEDULE_AFTER_V1 4
typedef struct {
    pd_BlockNumber_t after;
    pd_OptionPeriod_V1_t maybe_periodic;
    pd_Priority_V1_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_after_V1_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_AFTER_V1 5
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t after;
    pd_OptionPeriod_V1_t maybe_periodic;
    pd_Priority_V1_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_named_after_V1_t;

#define PD_CALL_PROXY_ADD_PROXY_V1 1
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_ProxyType_V1_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V1_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V1 2
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_ProxyType_V1_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V1_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V1 3
typedef struct {
} pd_proxy_remove_proxies_V1_t;

#define PD_CALL_PROXY_ANONYMOUS_V1 4
typedef struct {
    pd_ProxyType_V1_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V1_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V1 5
typedef struct {
    pd_AccountId_V1_t spawner;
    pd_ProxyType_V1_t proxy_type;
    pd_u16_t index;
    pd_CompactBlockNumber_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V1_t;

#define PD_CALL_PROXY_ANNOUNCE_V1 6
typedef struct {
    pd_AccountId_V1_t real;
    pd_CallHashOf_V1_t call_hash;
} pd_proxy_announce_V1_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V1 7
typedef struct {
    pd_AccountId_V1_t real;
    pd_CallHashOf_V1_t call_hash;
} pd_proxy_remove_announcement_V1_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V1 8
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_CallHashOf_V1_t call_hash;
} pd_proxy_reject_announcement_V1_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V1 9
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_AccountId_V1_t real;
    pd_OptionProxyType_V1_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V1_t;

#define PD_CALL_BOUNTIES_PROPOSE_BOUNTY_V1 0
typedef struct {
    pd_CompactBalanceOf_t value;
    pd_Bytes_t description;
} pd_bounties_propose_bounty_V1_t;

#define PD_CALL_BOUNTIES_APPROVE_BOUNTY_V1 1
typedef struct {
    pd_CompactBountyIndex_V1_t bounty_id;
} pd_bounties_approve_bounty_V1_t;

#define PD_CALL_BOUNTIES_PROPOSE_CURATOR_V1 2
typedef struct {
    pd_CompactBountyIndex_V1_t bounty_id;
    pd_LookupSource_V1_t curator;
    pd_CompactBalanceOf_t fee;
} pd_bounties_propose_curator_V1_t;

#define PD_CALL_BOUNTIES_UNASSIGN_CURATOR_V1 3
typedef struct {
    pd_CompactBountyIndex_V1_t bounty_id;
} pd_bounties_unassign_curator_V1_t;

#define PD_CALL_BOUNTIES_ACCEPT_CURATOR_V1 4
typedef struct {
    pd_CompactBountyIndex_V1_t bounty_id;
} pd_bounties_accept_curator_V1_t;

#define PD_CALL_BOUNTIES_AWARD_BOUNTY_V1 5
typedef struct {
    pd_CompactBountyIndex_V1_t bounty_id;
    pd_LookupSource_V1_t beneficiary;
} pd_bounties_award_bounty_V1_t;

#define PD_CALL_BOUNTIES_CLAIM_BOUNTY_V1 6
typedef struct {
    pd_CompactBountyIndex_V1_t bounty_id;
} pd_bounties_claim_bounty_V1_t;

#define PD_CALL_BOUNTIES_CLOSE_BOUNTY_V1 7
typedef struct {
    pd_CompactBountyIndex_V1_t bounty_id;
} pd_bounties_close_bounty_V1_t;

#define PD_CALL_BOUNTIES_EXTEND_BOUNTY_EXPIRY_V1 8
typedef struct {
    pd_CompactBountyIndex_V1_t bounty_id;
    pd_Bytes_t _remark;
} pd_bounties_extend_bounty_expiry_V1_t;

#define PD_CALL_TIPS_REPORT_AWESOME_V1 0
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V1_t who;
} pd_tips_report_awesome_V1_t;

#define PD_CALL_TIPS_RETRACT_TIP_V1 1
typedef struct {
    pd_Hash_t hash;
} pd_tips_retract_tip_V1_t;

#define PD_CALL_TIPS_TIP_NEW_V1 2
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V1_t who;
    pd_CompactBalanceOf_t tip_value;
} pd_tips_tip_new_V1_t;

#define PD_CALL_TIPS_TIP_V1 3
typedef struct {
    pd_Hash_t hash;
    pd_CompactBalanceOf_t tip_value;
} pd_tips_tip_V1_t;

#define PD_CALL_TIPS_CLOSE_TIP_V1 4
typedef struct {
    pd_Hash_t hash;
} pd_tips_close_tip_V1_t;

#define PD_CALL_TIPS_SLASH_TIP_V1 5
typedef struct {
    pd_Hash_t hash;
} pd_tips_slash_tip_V1_t;

#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_SUBMIT_UNSIGNED_V1 0
typedef struct {
    pd_RawSolution_V1_t solution;
    pd_SolutionOrSnapshotSize_V1_t witness;
} pd_electionprovidermultiphase_submit_unsigned_V1_t;

#define PD_CALL_GILT_PLACE_BID_V1 0
typedef struct {
    pd_CompactBalanceOf_t amount;
    pd_u32_t duration;
} pd_gilt_place_bid_V1_t;

#define PD_CALL_GILT_RETRACT_BID_V1 1
typedef struct {
    pd_CompactBalanceOf_t amount;
    pd_u32_t duration;
} pd_gilt_retract_bid_V1_t;

#define PD_CALL_GILT_SET_TARGET_V1 2
typedef struct {
    pd_CompactPerquintill_V1_t target;
} pd_gilt_set_target_V1_t;

#define PD_CALL_GILT_THAW_V1 3
typedef struct {
    pd_CompactActiveIndex_V1_t index;
} pd_gilt_thaw_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_VALIDATION_UPGRADE_FREQUENCY_V1 0
typedef struct {
    pd_BlockNumber_t new_;
} pd_parachainsconfiguration_set_validation_upgrade_frequency_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_VALIDATION_UPGRADE_DELAY_V1 1
typedef struct {
    pd_BlockNumber_t new_;
} pd_parachainsconfiguration_set_validation_upgrade_delay_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_CODE_RETENTION_PERIOD_V1 2
typedef struct {
    pd_BlockNumber_t new_;
} pd_parachainsconfiguration_set_code_retention_period_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_MAX_CODE_SIZE_V1 3
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_max_code_size_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_MAX_POV_SIZE_V1 4
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_max_pov_size_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_MAX_HEAD_DATA_SIZE_V1 5
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_max_head_data_size_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_PARATHREAD_CORES_V1 6
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_parathread_cores_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_PARATHREAD_RETRIES_V1 7
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_parathread_retries_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_GROUP_ROTATION_FREQUENCY_V1 8
typedef struct {
    pd_BlockNumber_t new_;
} pd_parachainsconfiguration_set_group_rotation_frequency_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_CHAIN_AVAILABILITY_PERIOD_V1 9
typedef struct {
    pd_BlockNumber_t new_;
} pd_parachainsconfiguration_set_chain_availability_period_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_THREAD_AVAILABILITY_PERIOD_V1 10
typedef struct {
    pd_BlockNumber_t new_;
} pd_parachainsconfiguration_set_thread_availability_period_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_SCHEDULING_LOOKAHEAD_V1 11
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_scheduling_lookahead_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_MAX_VALIDATORS_PER_CORE_V1 12
typedef struct {
    pd_Optionu32_t new_;
} pd_parachainsconfiguration_set_max_validators_per_core_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_MAX_VALIDATORS_V1 13
typedef struct {
    pd_Optionu32_t new_;
} pd_parachainsconfiguration_set_max_validators_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_DISPUTE_PERIOD_V1 14
typedef struct {
    pd_SessionIndex_V1_t new_;
} pd_parachainsconfiguration_set_dispute_period_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_DISPUTE_POST_CONCLUSION_ACCEPTANCE_PERIOD_V1 15
typedef struct {
    pd_BlockNumber_t new_;
} pd_parachainsconfiguration_set_dispute_post_conclusion_acceptance_period_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_DISPUTE_MAX_SPAM_SLOTS_V1 16
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_dispute_max_spam_slots_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_DISPUTE_CONCLUSION_BY_TIME_OUT_PERIOD_V1 17
typedef struct {
    pd_BlockNumber_t new_;
} pd_parachainsconfiguration_set_dispute_conclusion_by_time_out_period_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_NO_SHOW_SLOTS_V1 18
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_no_show_slots_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_N_DELAY_TRANCHES_V1 19
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_n_delay_tranches_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_ZEROTH_DELAY_TRANCHE_WIDTH_V1 20
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_zeroth_delay_tranche_width_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_NEEDED_APPROVALS_V1 21
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_needed_approvals_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_RELAY_VRF_MODULO_SAMPLES_V1 22
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_relay_vrf_modulo_samples_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_MAX_UPWARD_QUEUE_COUNT_V1 23
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_max_upward_queue_count_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_MAX_UPWARD_QUEUE_SIZE_V1 24
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_max_upward_queue_size_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_MAX_DOWNWARD_MESSAGE_SIZE_V1 25
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_max_downward_message_size_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_PREFERRED_DISPATCHABLE_UPWARD_MESSAGES_STEP_WEIGHT_V1 26
typedef struct {
    pd_Weight_V1_t new_;
} pd_parachainsconfiguration_set_preferred_dispatchable_upward_messages_step_weight_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_MAX_UPWARD_MESSAGE_SIZE_V1 27
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_max_upward_message_size_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_MAX_UPWARD_MESSAGE_NUM_PER_CANDIDATE_V1 28
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_max_upward_message_num_per_candidate_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_HRMP_OPEN_REQUEST_TTL_V1 29
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_hrmp_open_request_ttl_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_HRMP_SENDER_DEPOSIT_V1 30
typedef struct {
    pd_Balance_t new_;
} pd_parachainsconfiguration_set_hrmp_sender_deposit_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_HRMP_RECIPIENT_DEPOSIT_V1 31
typedef struct {
    pd_Balance_t new_;
} pd_parachainsconfiguration_set_hrmp_recipient_deposit_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_HRMP_CHANNEL_MAX_CAPACITY_V1 32
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_hrmp_channel_max_capacity_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_HRMP_CHANNEL_MAX_TOTAL_SIZE_V1 33
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_hrmp_channel_max_total_size_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_HRMP_MAX_PARACHAIN_INBOUND_CHANNELS_V1 34
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_hrmp_max_parachain_inbound_channels_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_HRMP_MAX_PARATHREAD_INBOUND_CHANNELS_V1 35
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_hrmp_max_parathread_inbound_channels_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_HRMP_CHANNEL_MAX_MESSAGE_SIZE_V1 36
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_hrmp_channel_max_message_size_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_HRMP_MAX_PARACHAIN_OUTBOUND_CHANNELS_V1 37
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_hrmp_max_parachain_outbound_channels_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_HRMP_MAX_PARATHREAD_OUTBOUND_CHANNELS_V1 38
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_hrmp_max_parathread_outbound_channels_V1_t;

#define PD_CALL_PARACHAINSCONFIGURATION_SET_HRMP_MAX_MESSAGE_NUM_PER_CANDIDATE_V1 39
typedef struct {
    pd_u32_t new_;
} pd_parachainsconfiguration_set_hrmp_max_message_num_per_candidate_V1_t;

#define PD_CALL_PARASINHERENT_ENTER_V1 0
typedef struct {
    pd_ParachainsInherentData_V1_t data;
} pd_parasinherent_enter_V1_t;

#define PD_CALL_PARAS_FORCE_SET_CURRENT_CODE_V1 0
typedef struct {
    pd_ParaId_V1_t para;
    pd_ValidationCode_V1_t new_code;
} pd_paras_force_set_current_code_V1_t;

#define PD_CALL_PARAS_FORCE_SET_CURRENT_HEAD_V1 1
typedef struct {
    pd_ParaId_V1_t para;
    pd_HeadData_V1_t new_head;
} pd_paras_force_set_current_head_V1_t;

#define PD_CALL_PARAS_FORCE_SCHEDULE_CODE_UPGRADE_V1 2
typedef struct {
    pd_ParaId_V1_t para;
    pd_ValidationCode_V1_t new_code;
    pd_BlockNumber_t expected_at;
} pd_paras_force_schedule_code_upgrade_V1_t;

#define PD_CALL_PARAS_FORCE_NOTE_NEW_HEAD_V1 3
typedef struct {
    pd_ParaId_V1_t para;
    pd_HeadData_V1_t new_head;
} pd_paras_force_note_new_head_V1_t;

#define PD_CALL_PARAS_FORCE_QUEUE_ACTION_V1 4
typedef struct {
    pd_ParaId_V1_t para;
} pd_paras_force_queue_action_V1_t;

#define PD_CALL_PARASINITIALIZER_FORCE_APPROVE_V1 0
typedef struct {
    pd_BlockNumber_t up_to;
} pd_parasinitializer_force_approve_V1_t;

#define PD_CALL_PARASHRMP_HRMP_INIT_OPEN_CHANNEL_V1 0
typedef struct {
    pd_ParaId_V1_t recipient;
    pd_u32_t proposed_max_capacity;
    pd_u32_t proposed_max_message_size;
} pd_parashrmp_hrmp_init_open_channel_V1_t;

#define PD_CALL_PARASHRMP_HRMP_ACCEPT_OPEN_CHANNEL_V1 1
typedef struct {
    pd_ParaId_V1_t sender;
} pd_parashrmp_hrmp_accept_open_channel_V1_t;

#define PD_CALL_PARASHRMP_HRMP_CLOSE_CHANNEL_V1 2
typedef struct {
    pd_HrmpChannelId_V1_t channel_id;
} pd_parashrmp_hrmp_close_channel_V1_t;

#define PD_CALL_PARASHRMP_FORCE_CLEAN_HRMP_V1 3
typedef struct {
    pd_ParaId_V1_t para;
} pd_parashrmp_force_clean_hrmp_V1_t;

#define PD_CALL_PARASHRMP_FORCE_PROCESS_HRMP_OPEN_V1 4
typedef struct {
} pd_parashrmp_force_process_hrmp_open_V1_t;

#define PD_CALL_PARASHRMP_FORCE_PROCESS_HRMP_CLOSE_V1 5
typedef struct {
} pd_parashrmp_force_process_hrmp_close_V1_t;

#define PD_CALL_REGISTRAR_REGISTER_V1 0
typedef struct {
    pd_ParaId_V1_t id;
    pd_HeadData_V1_t genesis_head;
    pd_ValidationCode_V1_t validation_code;
} pd_registrar_register_V1_t;

#define PD_CALL_REGISTRAR_FORCE_REGISTER_V1 1
typedef struct {
    pd_AccountId_V1_t who;
    pd_BalanceOf_t deposit;
    pd_ParaId_V1_t id;
    pd_HeadData_V1_t genesis_head;
    pd_ValidationCode_V1_t validation_code;
} pd_registrar_force_register_V1_t;

#define PD_CALL_REGISTRAR_DEREGISTER_V1 2
typedef struct {
    pd_ParaId_V1_t id;
} pd_registrar_deregister_V1_t;

#define PD_CALL_REGISTRAR_SWAP_V1 3
typedef struct {
    pd_ParaId_V1_t id;
    pd_ParaId_V1_t other;
} pd_registrar_swap_V1_t;

#define PD_CALL_REGISTRAR_FORCE_REMOVE_LOCK_V1 4
typedef struct {
    pd_ParaId_V1_t para;
} pd_registrar_force_remove_lock_V1_t;

#define PD_CALL_REGISTRAR_RESERVE_V1 5
typedef struct {
} pd_registrar_reserve_V1_t;

#define PD_CALL_SLOTS_FORCE_LEASE_V1 0
typedef struct {
    pd_ParaId_V1_t para;
    pd_AccountId_V1_t leaser;
    pd_BalanceOf_t amount;
    pd_LeasePeriodOf_V1_t period_begin;
    pd_LeasePeriodOf_V1_t period_count;
} pd_slots_force_lease_V1_t;

#define PD_CALL_SLOTS_CLEAR_ALL_LEASES_V1 1
typedef struct {
    pd_ParaId_V1_t para;
} pd_slots_clear_all_leases_V1_t;

#define PD_CALL_SLOTS_TRIGGER_ONBOARD_V1 2
typedef struct {
    pd_ParaId_V1_t para;
} pd_slots_trigger_onboard_V1_t;

#define PD_CALL_AUCTIONS_NEW_AUCTION_V1 0
typedef struct {
    pd_CompactBlockNumber_t duration;
    pd_CompactLeasePeriodOf_V1_t lease_period_index;
} pd_auctions_new_auction_V1_t;

#define PD_CALL_AUCTIONS_BID_V1 1
typedef struct {
    pd_CompactParaId_V1_t para;
    pd_CompactAuctionIndex_V1_t auction_index;
    pd_CompactLeasePeriodOf_V1_t first_slot;
    pd_CompactLeasePeriodOf_V1_t last_slot;
    pd_CompactBalanceOf_t amount;
} pd_auctions_bid_V1_t;

#define PD_CALL_AUCTIONS_CANCEL_AUCTION_V1 2
typedef struct {
} pd_auctions_cancel_auction_V1_t;

#define PD_CALL_CROWDLOAN_CREATE_V1 0
typedef struct {
    pd_CompactParaId_V1_t index;
    pd_CompactBalanceOf_t cap;
    pd_CompactLeasePeriodOf_V1_t first_period;
    pd_CompactLeasePeriodOf_V1_t last_period;
    pd_CompactBlockNumber_t end;
    pd_OptionMultiSigner_V1_t verifier;
} pd_crowdloan_create_V1_t;

#define PD_CALL_CROWDLOAN_CONTRIBUTE_V1 1
typedef struct {
    pd_CompactParaId_V1_t index;
    pd_CompactBalanceOf_t value;
    pd_OptionMultiSignature_V1_t signature;
} pd_crowdloan_contribute_V1_t;

#define PD_CALL_CROWDLOAN_WITHDRAW_V1 2
typedef struct {
    pd_AccountId_V1_t who;
    pd_CompactParaId_V1_t index;
} pd_crowdloan_withdraw_V1_t;

#define PD_CALL_CROWDLOAN_REFUND_V1 3
typedef struct {
    pd_CompactParaId_V1_t index;
} pd_crowdloan_refund_V1_t;

#define PD_CALL_CROWDLOAN_DISSOLVE_V1 4
typedef struct {
    pd_CompactParaId_V1_t index;
} pd_crowdloan_dissolve_V1_t;

#define PD_CALL_CROWDLOAN_EDIT_V1 5
typedef struct {
    pd_CompactParaId_V1_t index;
    pd_CompactBalanceOf_t cap;
    pd_CompactLeasePeriodOf_V1_t first_period;
    pd_CompactLeasePeriodOf_V1_t last_period;
    pd_CompactBlockNumber_t end;
    pd_OptionMultiSigner_V1_t verifier;
} pd_crowdloan_edit_V1_t;

#define PD_CALL_CROWDLOAN_ADD_MEMO_V1 6
typedef struct {
    pd_ParaId_V1_t index;
    pd_Bytes_t memo;
} pd_crowdloan_add_memo_V1_t;

#define PD_CALL_CROWDLOAN_POKE_V1 7
typedef struct {
    pd_ParaId_V1_t index;
} pd_crowdloan_poke_V1_t;

#define PD_CALL_XCMPALLET_SEND_V1 0
typedef struct {
    pd_MultiLocation_V1_t dest;
    pd_Xcm_V1_t message;
} pd_xcmpallet_send_V1_t;

#define PD_CALL_XCMPALLET_TELEPORT_ASSETS_V1 1
typedef struct {
    pd_MultiLocation_V1_t dest;
    pd_MultiLocation_V1_t beneficiary;
    pd_VecMultiAsset_V1_t assets;
    pd_Weight_V1_t dest_weight;
} pd_xcmpallet_teleport_assets_V1_t;

#define PD_CALL_XCMPALLET_EXECUTE_V1 2
typedef struct {
    pd_Xcm_V1_t message;
    pd_Weight_V1_t max_weight;
} pd_xcmpallet_execute_V1_t;

#endif

typedef union {
    pd_staking_bond_V1_t staking_bond_V1;
    pd_staking_bond_extra_V1_t staking_bond_extra_V1;
    pd_staking_unbond_V1_t staking_unbond_V1;
    pd_staking_withdraw_unbonded_V1_t staking_withdraw_unbonded_V1;
    pd_staking_validate_V1_t staking_validate_V1;
    pd_staking_nominate_V1_t staking_nominate_V1;
    pd_staking_chill_V1_t staking_chill_V1;
    pd_staking_set_payee_V1_t staking_set_payee_V1;
    pd_staking_payout_stakers_V1_t staking_payout_stakers_V1;
    pd_staking_rebond_V1_t staking_rebond_V1;
    pd_session_set_keys_V1_t session_set_keys_V1;
    pd_session_purge_keys_V1_t session_purge_keys_V1;
    pd_utility_batch_V1_t utility_batch_V1;
    pd_utility_batch_all_V1_t utility_batch_all_V1;
    pd_eqlockdrop_lock_V1_t eqlockdrop_lock_V1;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_remark_with_event_V1_t system_remark_with_event_V1;
    pd_babe_report_equivocation_V1_t babe_report_equivocation_V1;
    pd_babe_report_equivocation_unsigned_V1_t babe_report_equivocation_unsigned_V1;
    pd_babe_plan_config_change_V1_t babe_plan_config_change_V1;
    pd_timestamp_set_V1_t timestamp_set_V1;
    pd_indices_claim_V1_t indices_claim_V1;
    pd_indices_transfer_V1_t indices_transfer_V1;
    pd_indices_free_V1_t indices_free_V1;
    pd_indices_force_transfer_V1_t indices_force_transfer_V1;
    pd_indices_freeze_V1_t indices_freeze_V1;
    pd_authorship_set_uncles_V1_t authorship_set_uncles_V1;
    pd_staking_set_controller_V1_t staking_set_controller_V1;
    pd_staking_set_validator_count_V1_t staking_set_validator_count_V1;
    pd_staking_increase_validator_count_V1_t staking_increase_validator_count_V1;
    pd_staking_scale_validator_count_V1_t staking_scale_validator_count_V1;
    pd_staking_force_no_eras_V1_t staking_force_no_eras_V1;
    pd_staking_force_new_era_V1_t staking_force_new_era_V1;
    pd_staking_set_invulnerables_V1_t staking_set_invulnerables_V1;
    pd_staking_force_unstake_V1_t staking_force_unstake_V1;
    pd_staking_force_new_era_always_V1_t staking_force_new_era_always_V1;
    pd_staking_cancel_deferred_slash_V1_t staking_cancel_deferred_slash_V1;
    pd_staking_set_history_depth_V1_t staking_set_history_depth_V1;
    pd_staking_reap_stash_V1_t staking_reap_stash_V1;
    pd_staking_kick_V1_t staking_kick_V1;
    pd_grandpa_report_equivocation_V1_t grandpa_report_equivocation_V1;
    pd_grandpa_report_equivocation_unsigned_V1_t grandpa_report_equivocation_unsigned_V1;
    pd_grandpa_note_stalled_V1_t grandpa_note_stalled_V1;
    pd_imonline_heartbeat_V1_t imonline_heartbeat_V1;
    pd_democracy_propose_V1_t democracy_propose_V1;
    pd_democracy_second_V1_t democracy_second_V1;
    pd_democracy_vote_V1_t democracy_vote_V1;
    pd_democracy_emergency_cancel_V1_t democracy_emergency_cancel_V1;
    pd_democracy_external_propose_V1_t democracy_external_propose_V1;
    pd_democracy_external_propose_majority_V1_t democracy_external_propose_majority_V1;
    pd_democracy_external_propose_default_V1_t democracy_external_propose_default_V1;
    pd_democracy_fast_track_V1_t democracy_fast_track_V1;
    pd_democracy_veto_external_V1_t democracy_veto_external_V1;
    pd_democracy_cancel_referendum_V1_t democracy_cancel_referendum_V1;
    pd_democracy_cancel_queued_V1_t democracy_cancel_queued_V1;
    pd_democracy_delegate_V1_t democracy_delegate_V1;
    pd_democracy_undelegate_V1_t democracy_undelegate_V1;
    pd_democracy_clear_public_proposals_V1_t democracy_clear_public_proposals_V1;
    pd_democracy_note_preimage_V1_t democracy_note_preimage_V1;
    pd_democracy_note_preimage_operational_V1_t democracy_note_preimage_operational_V1;
    pd_democracy_note_imminent_preimage_V1_t democracy_note_imminent_preimage_V1;
    pd_democracy_note_imminent_preimage_operational_V1_t democracy_note_imminent_preimage_operational_V1;
    pd_democracy_reap_preimage_V1_t democracy_reap_preimage_V1;
    pd_democracy_unlock_V1_t democracy_unlock_V1;
    pd_democracy_remove_vote_V1_t democracy_remove_vote_V1;
    pd_democracy_remove_other_vote_V1_t democracy_remove_other_vote_V1;
    pd_democracy_enact_proposal_V1_t democracy_enact_proposal_V1;
    pd_democracy_blacklist_V1_t democracy_blacklist_V1;
    pd_democracy_cancel_proposal_V1_t democracy_cancel_proposal_V1;
    pd_council_set_members_V1_t council_set_members_V1;
    pd_council_execute_V1_t council_execute_V1;
    pd_council_propose_V1_t council_propose_V1;
    pd_council_vote_V1_t council_vote_V1;
    pd_council_close_V1_t council_close_V1;
    pd_council_disapprove_proposal_V1_t council_disapprove_proposal_V1;
    pd_technicalcommittee_set_members_V1_t technicalcommittee_set_members_V1;
    pd_technicalcommittee_execute_V1_t technicalcommittee_execute_V1;
    pd_technicalcommittee_propose_V1_t technicalcommittee_propose_V1;
    pd_technicalcommittee_vote_V1_t technicalcommittee_vote_V1;
    pd_technicalcommittee_close_V1_t technicalcommittee_close_V1;
    pd_technicalcommittee_disapprove_proposal_V1_t technicalcommittee_disapprove_proposal_V1;
    pd_phragmenelection_vote_V1_t phragmenelection_vote_V1;
    pd_phragmenelection_remove_voter_V1_t phragmenelection_remove_voter_V1;
    pd_phragmenelection_submit_candidacy_V1_t phragmenelection_submit_candidacy_V1;
    pd_phragmenelection_renounce_candidacy_V1_t phragmenelection_renounce_candidacy_V1;
    pd_phragmenelection_remove_member_V1_t phragmenelection_remove_member_V1;
    pd_phragmenelection_clean_defunct_voters_V1_t phragmenelection_clean_defunct_voters_V1;
    pd_technicalmembership_add_member_V1_t technicalmembership_add_member_V1;
    pd_technicalmembership_remove_member_V1_t technicalmembership_remove_member_V1;
    pd_technicalmembership_swap_member_V1_t technicalmembership_swap_member_V1;
    pd_technicalmembership_reset_members_V1_t technicalmembership_reset_members_V1;
    pd_technicalmembership_change_key_V1_t technicalmembership_change_key_V1;
    pd_technicalmembership_set_prime_V1_t technicalmembership_set_prime_V1;
    pd_technicalmembership_clear_prime_V1_t technicalmembership_clear_prime_V1;
    pd_treasury_propose_spend_V1_t treasury_propose_spend_V1;
    pd_treasury_reject_proposal_V1_t treasury_reject_proposal_V1;
    pd_treasury_approve_proposal_V1_t treasury_approve_proposal_V1;
    pd_claims_claim_V1_t claims_claim_V1;
    pd_claims_mint_claim_V1_t claims_mint_claim_V1;
    pd_claims_claim_attest_V1_t claims_claim_attest_V1;
    pd_claims_attest_V1_t claims_attest_V1;
    pd_claims_move_claim_V1_t claims_move_claim_V1;
    pd_utility_as_derivative_V1_t utility_as_derivative_V1;
    pd_identity_add_registrar_V1_t identity_add_registrar_V1;
    pd_identity_set_identity_V1_t identity_set_identity_V1;
    pd_identity_set_subs_V1_t identity_set_subs_V1;
    pd_identity_clear_identity_V1_t identity_clear_identity_V1;
    pd_identity_request_judgement_V1_t identity_request_judgement_V1;
    pd_identity_cancel_request_V1_t identity_cancel_request_V1;
    pd_identity_set_fee_V1_t identity_set_fee_V1;
    pd_identity_set_account_id_V1_t identity_set_account_id_V1;
    pd_identity_set_fields_V1_t identity_set_fields_V1;
    pd_identity_provide_judgement_V1_t identity_provide_judgement_V1;
    pd_identity_kill_identity_V1_t identity_kill_identity_V1;
    pd_identity_add_sub_V1_t identity_add_sub_V1;
    pd_identity_rename_sub_V1_t identity_rename_sub_V1;
    pd_identity_remove_sub_V1_t identity_remove_sub_V1;
    pd_identity_quit_sub_V1_t identity_quit_sub_V1;
    pd_society_bid_V1_t society_bid_V1;
    pd_society_unbid_V1_t society_unbid_V1;
    pd_society_vouch_V1_t society_vouch_V1;
    pd_society_unvouch_V1_t society_unvouch_V1;
    pd_society_vote_V1_t society_vote_V1;
    pd_society_defender_vote_V1_t society_defender_vote_V1;
    pd_society_payout_V1_t society_payout_V1;
    pd_society_found_V1_t society_found_V1;
    pd_society_unfound_V1_t society_unfound_V1;
    pd_society_judge_suspended_member_V1_t society_judge_suspended_member_V1;
    pd_society_judge_suspended_candidate_V1_t society_judge_suspended_candidate_V1;
    pd_society_set_max_members_V1_t society_set_max_members_V1;
    pd_recovery_as_recovered_V1_t recovery_as_recovered_V1;
    pd_recovery_set_recovered_V1_t recovery_set_recovered_V1;
    pd_recovery_create_recovery_V1_t recovery_create_recovery_V1;
    pd_recovery_initiate_recovery_V1_t recovery_initiate_recovery_V1;
    pd_recovery_vouch_recovery_V1_t recovery_vouch_recovery_V1;
    pd_recovery_claim_recovery_V1_t recovery_claim_recovery_V1;
    pd_recovery_close_recovery_V1_t recovery_close_recovery_V1;
    pd_recovery_remove_recovery_V1_t recovery_remove_recovery_V1;
    pd_recovery_cancel_recovered_V1_t recovery_cancel_recovered_V1;
    pd_vesting_vest_V1_t vesting_vest_V1;
    pd_vesting_vest_other_V1_t vesting_vest_other_V1;
    pd_vesting_vested_transfer_V1_t vesting_vested_transfer_V1;
    pd_vesting_force_vested_transfer_V1_t vesting_force_vested_transfer_V1;
    pd_scheduler_schedule_V1_t scheduler_schedule_V1;
    pd_scheduler_cancel_V1_t scheduler_cancel_V1;
    pd_scheduler_schedule_named_V1_t scheduler_schedule_named_V1;
    pd_scheduler_cancel_named_V1_t scheduler_cancel_named_V1;
    pd_scheduler_schedule_after_V1_t scheduler_schedule_after_V1;
    pd_scheduler_schedule_named_after_V1_t scheduler_schedule_named_after_V1;
    pd_proxy_add_proxy_V1_t proxy_add_proxy_V1;
    pd_proxy_remove_proxy_V1_t proxy_remove_proxy_V1;
    pd_proxy_remove_proxies_V1_t proxy_remove_proxies_V1;
    pd_proxy_anonymous_V1_t proxy_anonymous_V1;
    pd_proxy_kill_anonymous_V1_t proxy_kill_anonymous_V1;
    pd_proxy_announce_V1_t proxy_announce_V1;
    pd_proxy_remove_announcement_V1_t proxy_remove_announcement_V1;
    pd_proxy_reject_announcement_V1_t proxy_reject_announcement_V1;
    pd_proxy_proxy_announced_V1_t proxy_proxy_announced_V1;
    pd_bounties_propose_bounty_V1_t bounties_propose_bounty_V1;
    pd_bounties_approve_bounty_V1_t bounties_approve_bounty_V1;
    pd_bounties_propose_curator_V1_t bounties_propose_curator_V1;
    pd_bounties_unassign_curator_V1_t bounties_unassign_curator_V1;
    pd_bounties_accept_curator_V1_t bounties_accept_curator_V1;
    pd_bounties_award_bounty_V1_t bounties_award_bounty_V1;
    pd_bounties_claim_bounty_V1_t bounties_claim_bounty_V1;
    pd_bounties_close_bounty_V1_t bounties_close_bounty_V1;
    pd_bounties_extend_bounty_expiry_V1_t bounties_extend_bounty_expiry_V1;
    pd_tips_report_awesome_V1_t tips_report_awesome_V1;
    pd_tips_retract_tip_V1_t tips_retract_tip_V1;
    pd_tips_tip_new_V1_t tips_tip_new_V1;
    pd_tips_tip_V1_t tips_tip_V1;
    pd_tips_close_tip_V1_t tips_close_tip_V1;
    pd_tips_slash_tip_V1_t tips_slash_tip_V1;
    pd_electionprovidermultiphase_submit_unsigned_V1_t electionprovidermultiphase_submit_unsigned_V1;
    pd_gilt_place_bid_V1_t gilt_place_bid_V1;
    pd_gilt_retract_bid_V1_t gilt_retract_bid_V1;
    pd_gilt_set_target_V1_t gilt_set_target_V1;
    pd_gilt_thaw_V1_t gilt_thaw_V1;
    pd_parachainsconfiguration_set_validation_upgrade_frequency_V1_t parachainsconfiguration_set_validation_upgrade_frequency_V1;
    pd_parachainsconfiguration_set_validation_upgrade_delay_V1_t parachainsconfiguration_set_validation_upgrade_delay_V1;
    pd_parachainsconfiguration_set_code_retention_period_V1_t parachainsconfiguration_set_code_retention_period_V1;
    pd_parachainsconfiguration_set_max_code_size_V1_t parachainsconfiguration_set_max_code_size_V1;
    pd_parachainsconfiguration_set_max_pov_size_V1_t parachainsconfiguration_set_max_pov_size_V1;
    pd_parachainsconfiguration_set_max_head_data_size_V1_t parachainsconfiguration_set_max_head_data_size_V1;
    pd_parachainsconfiguration_set_parathread_cores_V1_t parachainsconfiguration_set_parathread_cores_V1;
    pd_parachainsconfiguration_set_parathread_retries_V1_t parachainsconfiguration_set_parathread_retries_V1;
    pd_parachainsconfiguration_set_group_rotation_frequency_V1_t parachainsconfiguration_set_group_rotation_frequency_V1;
    pd_parachainsconfiguration_set_chain_availability_period_V1_t parachainsconfiguration_set_chain_availability_period_V1;
    pd_parachainsconfiguration_set_thread_availability_period_V1_t parachainsconfiguration_set_thread_availability_period_V1;
    pd_parachainsconfiguration_set_scheduling_lookahead_V1_t parachainsconfiguration_set_scheduling_lookahead_V1;
    pd_parachainsconfiguration_set_max_validators_per_core_V1_t parachainsconfiguration_set_max_validators_per_core_V1;
    pd_parachainsconfiguration_set_max_validators_V1_t parachainsconfiguration_set_max_validators_V1;
    pd_parachainsconfiguration_set_dispute_period_V1_t parachainsconfiguration_set_dispute_period_V1;
    pd_parachainsconfiguration_set_dispute_post_conclusion_acceptance_period_V1_t parachainsconfiguration_set_dispute_post_conclusion_acceptance_period_V1;
    pd_parachainsconfiguration_set_dispute_max_spam_slots_V1_t parachainsconfiguration_set_dispute_max_spam_slots_V1;
    pd_parachainsconfiguration_set_dispute_conclusion_by_time_out_period_V1_t parachainsconfiguration_set_dispute_conclusion_by_time_out_period_V1;
    pd_parachainsconfiguration_set_no_show_slots_V1_t parachainsconfiguration_set_no_show_slots_V1;
    pd_parachainsconfiguration_set_n_delay_tranches_V1_t parachainsconfiguration_set_n_delay_tranches_V1;
    pd_parachainsconfiguration_set_zeroth_delay_tranche_width_V1_t parachainsconfiguration_set_zeroth_delay_tranche_width_V1;
    pd_parachainsconfiguration_set_needed_approvals_V1_t parachainsconfiguration_set_needed_approvals_V1;
    pd_parachainsconfiguration_set_relay_vrf_modulo_samples_V1_t parachainsconfiguration_set_relay_vrf_modulo_samples_V1;
    pd_parachainsconfiguration_set_max_upward_queue_count_V1_t parachainsconfiguration_set_max_upward_queue_count_V1;
    pd_parachainsconfiguration_set_max_upward_queue_size_V1_t parachainsconfiguration_set_max_upward_queue_size_V1;
    pd_parachainsconfiguration_set_max_downward_message_size_V1_t parachainsconfiguration_set_max_downward_message_size_V1;
    pd_parachainsconfiguration_set_preferred_dispatchable_upward_messages_step_weight_V1_t parachainsconfiguration_set_preferred_dispatchable_upward_messages_step_weight_V1;
    pd_parachainsconfiguration_set_max_upward_message_size_V1_t parachainsconfiguration_set_max_upward_message_size_V1;
    pd_parachainsconfiguration_set_max_upward_message_num_per_candidate_V1_t parachainsconfiguration_set_max_upward_message_num_per_candidate_V1;
    pd_parachainsconfiguration_set_hrmp_open_request_ttl_V1_t parachainsconfiguration_set_hrmp_open_request_ttl_V1;
    pd_parachainsconfiguration_set_hrmp_sender_deposit_V1_t parachainsconfiguration_set_hrmp_sender_deposit_V1;
    pd_parachainsconfiguration_set_hrmp_recipient_deposit_V1_t parachainsconfiguration_set_hrmp_recipient_deposit_V1;
    pd_parachainsconfiguration_set_hrmp_channel_max_capacity_V1_t parachainsconfiguration_set_hrmp_channel_max_capacity_V1;
    pd_parachainsconfiguration_set_hrmp_channel_max_total_size_V1_t parachainsconfiguration_set_hrmp_channel_max_total_size_V1;
    pd_parachainsconfiguration_set_hrmp_max_parachain_inbound_channels_V1_t parachainsconfiguration_set_hrmp_max_parachain_inbound_channels_V1;
    pd_parachainsconfiguration_set_hrmp_max_parathread_inbound_channels_V1_t parachainsconfiguration_set_hrmp_max_parathread_inbound_channels_V1;
    pd_parachainsconfiguration_set_hrmp_channel_max_message_size_V1_t parachainsconfiguration_set_hrmp_channel_max_message_size_V1;
    pd_parachainsconfiguration_set_hrmp_max_parachain_outbound_channels_V1_t parachainsconfiguration_set_hrmp_max_parachain_outbound_channels_V1;
    pd_parachainsconfiguration_set_hrmp_max_parathread_outbound_channels_V1_t parachainsconfiguration_set_hrmp_max_parathread_outbound_channels_V1;
    pd_parachainsconfiguration_set_hrmp_max_message_num_per_candidate_V1_t parachainsconfiguration_set_hrmp_max_message_num_per_candidate_V1;
    pd_parasinherent_enter_V1_t parasinherent_enter_V1;
    pd_paras_force_set_current_code_V1_t paras_force_set_current_code_V1;
    pd_paras_force_set_current_head_V1_t paras_force_set_current_head_V1;
    pd_paras_force_schedule_code_upgrade_V1_t paras_force_schedule_code_upgrade_V1;
    pd_paras_force_note_new_head_V1_t paras_force_note_new_head_V1;
    pd_paras_force_queue_action_V1_t paras_force_queue_action_V1;
    pd_parasinitializer_force_approve_V1_t parasinitializer_force_approve_V1;
    pd_parashrmp_hrmp_init_open_channel_V1_t parashrmp_hrmp_init_open_channel_V1;
    pd_parashrmp_hrmp_accept_open_channel_V1_t parashrmp_hrmp_accept_open_channel_V1;
    pd_parashrmp_hrmp_close_channel_V1_t parashrmp_hrmp_close_channel_V1;
    pd_parashrmp_force_clean_hrmp_V1_t parashrmp_force_clean_hrmp_V1;
    pd_parashrmp_force_process_hrmp_open_V1_t parashrmp_force_process_hrmp_open_V1;
    pd_parashrmp_force_process_hrmp_close_V1_t parashrmp_force_process_hrmp_close_V1;
    pd_registrar_register_V1_t registrar_register_V1;
    pd_registrar_force_register_V1_t registrar_force_register_V1;
    pd_registrar_deregister_V1_t registrar_deregister_V1;
    pd_registrar_swap_V1_t registrar_swap_V1;
    pd_registrar_force_remove_lock_V1_t registrar_force_remove_lock_V1;
    pd_registrar_reserve_V1_t registrar_reserve_V1;
    pd_slots_force_lease_V1_t slots_force_lease_V1;
    pd_slots_clear_all_leases_V1_t slots_clear_all_leases_V1;
    pd_slots_trigger_onboard_V1_t slots_trigger_onboard_V1;
    pd_auctions_new_auction_V1_t auctions_new_auction_V1;
    pd_auctions_bid_V1_t auctions_bid_V1;
    pd_auctions_cancel_auction_V1_t auctions_cancel_auction_V1;
    pd_crowdloan_create_V1_t crowdloan_create_V1;
    pd_crowdloan_contribute_V1_t crowdloan_contribute_V1;
    pd_crowdloan_withdraw_V1_t crowdloan_withdraw_V1;
    pd_crowdloan_refund_V1_t crowdloan_refund_V1;
    pd_crowdloan_dissolve_V1_t crowdloan_dissolve_V1;
    pd_crowdloan_edit_V1_t crowdloan_edit_V1;
    pd_crowdloan_add_memo_V1_t crowdloan_add_memo_V1;
    pd_crowdloan_poke_V1_t crowdloan_poke_V1;
    pd_xcmpallet_send_V1_t xcmpallet_send_V1;
    pd_xcmpallet_teleport_assets_V1_t xcmpallet_teleport_assets_V1;
    pd_xcmpallet_execute_V1_t xcmpallet_execute_V1;
#endif
} pd_MethodBasic_V1_t;

#define PD_CALL_BALANCES_TRANSFER_V1 0
typedef struct {
    pd_LookupSource_V1_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_V1_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V1 3
typedef struct {
    pd_LookupSource_V1_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_keep_alive_V1_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V1 0
typedef struct {
    pd_Perbill_V1_t _ratio;
} pd_system_fill_block_V1_t;

#define PD_CALL_SYSTEM_REMARK_V1 1
typedef struct {
    pd_Bytes_t _remark;
} pd_system_remark_V1_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V1 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V1_t;

#define PD_CALL_SYSTEM_SET_CODE_V1 3
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_V1_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V1 4
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_without_checks_V1_t;

#define PD_CALL_SYSTEM_SET_CHANGES_TRIE_CONFIG_V1 5
typedef struct {
    pd_OptionChangesTrieConfiguration_V1_t changes_trie_config;
} pd_system_set_changes_trie_config_V1_t;

#define PD_CALL_SYSTEM_SET_STORAGE_V1 6
typedef struct {
    pd_VecKeyValue_V1_t items;
} pd_system_set_storage_V1_t;

#define PD_CALL_SYSTEM_KILL_STORAGE_V1 7
typedef struct {
    pd_VecKey_V1_t keys;
} pd_system_kill_storage_V1_t;

#define PD_CALL_SYSTEM_KILL_PREFIX_V1 8
typedef struct {
    pd_Key_V1_t prefix;
    pd_u32_t _subkeys;
} pd_system_kill_prefix_V1_t;

#define PD_CALL_BALANCES_SET_BALANCE_V1 1
typedef struct {
    pd_LookupSource_V1_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V1_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V1 2
typedef struct {
    pd_LookupSource_V1_t source;
    pd_LookupSource_V1_t dest;
    pd_CompactBalance_t value;
} pd_balances_force_transfer_V1_t;

#define PD_CALL_PROXY_PROXY_V1 0
typedef struct {
    pd_AccountId_V1_t real;
    pd_OptionProxyType_V1_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V1_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V1 0
typedef struct {
    pd_VecAccountId_V1_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V1_t;

#define PD_CALL_MULTISIG_AS_MULTI_V1 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_OptionTimepoint_V1_t maybe_timepoint;
    pd_OpaqueCall_V1_t call;
    pd_bool_t store_call;
    pd_Weight_V1_t max_weight;
} pd_multisig_as_multi_V1_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V1 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_OptionTimepoint_V1_t maybe_timepoint;
    pd_u8_array_32_V1_t call_hash;
    pd_Weight_V1_t max_weight;
} pd_multisig_approve_as_multi_V1_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V1 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_Timepoint_V1_t timepoint;
    pd_u8_array_32_V1_t call_hash;
} pd_multisig_cancel_as_multi_V1_t;

#endif

typedef union {
    pd_balances_transfer_V1_t balances_transfer_V1;
    pd_balances_transfer_keep_alive_V1_t balances_transfer_keep_alive_V1;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V1_t system_fill_block_V1;
    pd_system_remark_V1_t system_remark_V1;
    pd_system_set_heap_pages_V1_t system_set_heap_pages_V1;
    pd_system_set_code_V1_t system_set_code_V1;
    pd_system_set_code_without_checks_V1_t system_set_code_without_checks_V1;
    pd_system_set_changes_trie_config_V1_t system_set_changes_trie_config_V1;
    pd_system_set_storage_V1_t system_set_storage_V1;
    pd_system_kill_storage_V1_t system_kill_storage_V1;
    pd_system_kill_prefix_V1_t system_kill_prefix_V1;
    pd_balances_set_balance_V1_t balances_set_balance_V1;
    pd_balances_force_transfer_V1_t balances_force_transfer_V1;
    pd_proxy_proxy_V1_t proxy_proxy_V1;
    pd_multisig_as_multi_threshold_1_V1_t multisig_as_multi_threshold_1_V1;
    pd_multisig_as_multi_V1_t multisig_as_multi_V1;
    pd_multisig_approve_as_multi_V1_t multisig_approve_as_multi_V1;
    pd_multisig_cancel_as_multi_V1_t multisig_cancel_as_multi_V1;
#endif
} pd_MethodNested_V1_t;

typedef union {
    pd_MethodBasic_V1_t basic;
    pd_MethodNested_V1_t nested;
} pd_Method_V1_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
