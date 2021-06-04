/*******************************************************************************
*  (c) 2021 Zondax GmbH
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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Modules names
static const char* STR_MO_EQBALANCES = "EqBalances";
static const char* STR_MO_VESTING = "Vesting";
static const char* STR_MO_SUBACCOUNTS = "Subaccounts";
static const char* STR_MO_EQLOCKDROP = "EqLockdrop";

// Methods names
static const char* STR_ME_LOCK = "Lock";
static const char* STR_ME_UNLOCK_EXTERNAL = "Unlock external";
static const char* STR_ME_VEST = "Vest";
static const char* STR_ME_TRANSFER = "Transfer";
static const char* STR_ME_TRANSFER_TO_SUBACCOUNT = "Transfer to subaccount";
static const char* STR_ME_TRANSFER_FROM_SUBACCOUNT = "Transfer from subaccount";
// Items names
static const char* STR_IT__ratio = "Ratio";
static const char* STR_IT__remark = "Remark";
static const char* STR_IT_pages = "Pages";
static const char* STR_IT_code = "Code";
static const char* STR_IT_changes_trie_config = "Changes trie config";
static const char* STR_IT_items = "Items";
static const char* STR_IT_keys = "Keys";
static const char* STR_IT_prefix = "Prefix";
static const char* STR_IT__subkeys = "Subkeys";
static const char* STR_IT_equivocation_proof = "Equivocation proof";
static const char* STR_IT_key_owner_proof = "Key owner proof";
static const char* STR_IT_now = "Now";
static const char* STR_IT_index = "Index";
static const char* STR_IT_new_ = "New";
static const char* STR_IT_freeze = "Freeze";
static const char* STR_IT_dest = "Dest";
static const char* STR_IT_value = "Amount";
static const char* STR_IT_who = "Who";
static const char* STR_IT_new_free = "New free";
static const char* STR_IT_new_reserved = "New reserved";
static const char* STR_IT_source = "Source";
static const char* STR_IT_new_uncles = "New uncles";
static const char* STR_IT_controller = "Controller";
static const char* STR_IT_payee = "Payee";
static const char* STR_IT_max_additional = "Amount";
static const char* STR_IT_num_slashing_spans = "Num slashing spans";
static const char* STR_IT_prefs = "Prefs";
static const char* STR_IT_targets = "Targets";
static const char* STR_IT_additional = "Additional";
static const char* STR_IT_factor = "Factor";
static const char* STR_IT_invulnerables = "Invulnerables";
static const char* STR_IT_stash = "Stash";
static const char* STR_IT_era = "Era";
static const char* STR_IT_slash_indices = "Slash indices";
static const char* STR_IT_validator_stash = "Validator stash";
static const char* STR_IT_new_history_depth = "New history depth";
static const char* STR_IT__era_items_deleted = "Era items deleted";
static const char* STR_IT_winners = "Winners";
static const char* STR_IT_compact = "Compact";
static const char* STR_IT_score = "Score";
static const char* STR_IT_size = "Size";
static const char* STR_IT_proof = "Proof";
static const char* STR_IT_delay = "Delay";
static const char* STR_IT_best_finalized_block_number = "Best finalized block number";
static const char* STR_IT_heartbeat = "Heartbeat";
static const char* STR_IT__signature = "Signature";
static const char* STR_IT_proposal_hash = "Proposal hash";
static const char* STR_IT_proposal = "Proposal";
static const char* STR_IT_seconds_upper_bound = "Seconds upper bound";
static const char* STR_IT_ref_index = "Ref index";
static const char* STR_IT_vote = "Vote";
static const char* STR_IT_voting_period = "Voting period";
static const char* STR_IT_which = "Which";
static const char* STR_IT_to = "To";
static const char* STR_IT_conviction = "Conviction";
static const char* STR_IT_balance = "Balance";
static const char* STR_IT_encoded_proposal = "Encoded proposal";
static const char* STR_IT_proposal_len_upper_bound = "Proposal len upper bound";
static const char* STR_IT_target = "Target";
static const char* STR_IT_maybe_ref_index = "Maybe ref index";
static const char* STR_IT_prop_index = "Prop index";
static const char* STR_IT_new_members = "New members";
static const char* STR_IT_prime = "Prime";
static const char* STR_IT_old_count = "Old count";
static const char* STR_IT_length_bound = "Length bound";
static const char* STR_IT_threshold = "Threshold";
static const char* STR_IT_approve = "Approve";
static const char* STR_IT_proposal_weight_bound = "Proposal weight bound";
static const char* STR_IT_votes = "Votes";
static const char* STR_IT_candidate_count = "Candidate count";
static const char* STR_IT_renouncing = "Renouncing";
static const char* STR_IT_has_replacement = "Has replacement";
static const char* STR_IT__num_voters = "Num voters";
static const char* STR_IT__num_defunct = "Num defunct";
static const char* STR_IT_remove = "Remove";
static const char* STR_IT_add = "Add";
static const char* STR_IT_members = "Members";
static const char* STR_IT_beneficiary = "Beneficiary";
static const char* STR_IT_proposal_id = "Proposal id";
static const char* STR_IT_ethereum_signature = "Ethereum signature";
static const char* STR_IT_vesting_schedule = "Vesting schedule";
static const char* STR_IT_statement = "Statement";
static const char* STR_IT_old = "Old";
static const char* STR_IT_maybe_preclaim = "Maybe preclaim";
static const char* STR_IT_calls = "Calls";
static const char* STR_IT_call = "Call";
static const char* STR_IT_account = "Account";
static const char* STR_IT_info = "Info";
static const char* STR_IT_subs = "Subs";
static const char* STR_IT_reg_index = "Reg index";
static const char* STR_IT_max_fee = "Max fee";
static const char* STR_IT_fee = "Fee";
static const char* STR_IT_fields = "Fields";
static const char* STR_IT_judgement = "Judgement";
static const char* STR_IT_sub = "Sub";
static const char* STR_IT_data = "Data";
static const char* STR_IT_pos = "Pos";
static const char* STR_IT_tip = "Tip";
static const char* STR_IT_candidate = "Candidate";
static const char* STR_IT_founder = "Founder";
static const char* STR_IT_max_members = "Max members";
static const char* STR_IT_rules = "Rules";
static const char* STR_IT_forgive = "Forgive";
static const char* STR_IT_max = "Max";
static const char* STR_IT_lost = "Lost";
static const char* STR_IT_rescuer = "Rescuer";
static const char* STR_IT_friends = "Friends";
static const char* STR_IT_delay_period = "Delay period";
static const char* STR_IT_schedule = "Schedule";
static const char* STR_IT_when = "When";
static const char* STR_IT_maybe_periodic = "Maybe periodic";
static const char* STR_IT_priority = "Priority";
static const char* STR_IT_id = "Id";
static const char* STR_IT_after = "After";
static const char* STR_IT_real = "Real";
static const char* STR_IT_force_proxy_type = "Force proxy type";
static const char* STR_IT_delegate = "Delegate";
static const char* STR_IT_proxy_type = "Proxy type";
static const char* STR_IT_spawner = "Spawner";
static const char* STR_IT_height = "Height";
static const char* STR_IT_ext_index = "Ext index";
static const char* STR_IT_call_hash = "Call hash";
static const char* STR_IT_other_signatories = "Other signatories";
static const char* STR_IT_maybe_timepoint = "Maybe timepoint";
static const char* STR_IT_store_call = "Store call";
static const char* STR_IT_max_weight = "Max weight";
static const char* STR_IT_timepoint = "Timepoint";
static const char* STR_IT_description = "Description";
static const char* STR_IT_bounty_id = "Bounty id";
static const char* STR_IT_curator = "Curator";
static const char* STR_IT_reason = "Reason";
static const char* STR_IT_hash = "Hash";
static const char* STR_IT_tip_value = "Tip value";
static const char* STR_IT_solution = "Solution";
static const char* STR_IT_witness = "Witness";
static const char* STR_IT_remark = "Remark";
static const char* STR_IT_config = "Config";
static const char* STR_IT_amount = "Amount";
static const char* STR_IT_duration = "Duration";
static const char* STR_IT_para = "Para";
static const char* STR_IT_new_code = "New code";
static const char* STR_IT_new_head = "New head";
static const char* STR_IT_expected_at = "Expected at";
static const char* STR_IT_up_to = "Up to";
static const char* STR_IT_recipient = "Recipient";
static const char* STR_IT_proposed_max_capacity = "Proposed max capacity";
static const char* STR_IT_proposed_max_message_size = "Proposed max message size";
static const char* STR_IT_sender = "Sender";
static const char* STR_IT_channel_id = "Channel id";
static const char* STR_IT_genesis_head = "Genesis head";
static const char* STR_IT_validation_code = "Validation code";
static const char* STR_IT_deposit = "Deposit";
static const char* STR_IT_other = "Other";
static const char* STR_IT_leaser = "Leaser";
static const char* STR_IT_period_begin = "Period begin";
static const char* STR_IT_period_count = "Period count";
static const char* STR_IT_lease_period_index = "Lease period index";
static const char* STR_IT_auction_index = "Auction index";
static const char* STR_IT_first_slot = "First slot";
static const char* STR_IT_last_slot = "Last slot";
static const char* STR_IT_cap = "Cap";
static const char* STR_IT_first_period = "First period";
static const char* STR_IT_last_period = "Last period";
static const char* STR_IT_end = "End";
static const char* STR_IT_verifier = "Verifier";
static const char* STR_IT_signature = "Signature";
static const char* STR_IT_memo = "Memo";
static const char* STR_IT_message = "Message";
static const char* STR_IT_assets = "Assets";
static const char* STR_IT_dest_weight = "Dest weight";
static const char* STR_IT_currency = "Currency";
static const char* STR_IT_subaccount = "Subaccount";
#ifdef __cplusplus
}
#endif
