//
// Created by overseven on 21.06.2021.
//


#include <stdint.h>
#include "network.h"

static const char* NETWORK_EQ = "EQ";
static const char* NETWORK_DOT = "DOT";
static const char* GENESIS_EQ    = "6f1a800de3daff7f5e037ddf66ab22ce03ab91874debeddb1086f5f7dbd48925";
static const char* GENESIS_DOT   = "91b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3";

static const char* NETWORK_ERROR = "ERROR";
static const char* GENESIS_ERROR = "00";

const char *get_network_name(uint8_t id) {
    switch (id) {
        case Network_EQ:
            return NETWORK_EQ;
        case Network_DOT:
            return NETWORK_DOT;
        default:
            return NETWORK_ERROR;
    }
}

//  Full list of der. paths: https://github.com/satoshilabs/slips/blob/master/slip-0044.md
uint32_t get_network_derivation_path(uint8_t id) {
    switch (id) {
        case Network_EQ:
            return (0x80000000 | 0x5f5e0fd); // 99999997
        case Network_DOT:
            return (0x80000000 | 0x162); // 354 = m/44/354/0/0/0
        default:
            return 0;
    }
}

const char* get_network_genesis_hash(uint8_t id){
    switch (id) {
        case Network_EQ:
            return GENESIS_EQ;
        case Network_DOT:
            return GENESIS_DOT;
        default:
            return GENESIS_ERROR;
    }
}

// https://polkadot.subscan.io/tools/ss58_transform
uint8_t get_network_address_type(uint8_t id){
    switch (id) {
        case Network_EQ:
            return 68;
        case Network_DOT:
            return 0;
        default:
            return 0;
    }
}