//
// Created by overseven on 21.06.2021.
//


#include <stdint.h>
#include "network.h"


static const char* NETWORK_DOT = "DOT";
static const char* NETWORK_EQ = "EQ";
static const char* NETWORK_KSM = "KSM";
static const char* NETWORK_GENS = "GENS";
//static const char* NETWORK_HYDRADX = "HDX";
static const char* NETWORK_ERROR = "ERROR";

static const char* GENESIS_DOT   = "91b171bb158e2d3848fa23a9f1c25182fb8e20313b2c1eb49219da7a70ce90c3";
static const char* GENESIS_EQ    = "6f1a800de3daff7f5e037ddf66ab22ce03ab91874debeddb1086f5f7dbd48925";
static const char* GENESIS_KSM   = "b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe";
static const char* GENESIS_GENS  = "9257ffd5c87d636ff534a0b8d3ff3c7de2b166dd1704c1268938906f3bb58203";
//static const char* GENESIS_HYDRA = "d2a620c27ec5cbc5621ff9a522689895074f7cca0d08e7134a7804e1a3ba86fc";
static const char* GENESIS_ERROR = "00";

const char *get_network_name(uint8_t id) {
    switch (id) {
        case Network_DOT:
            return NETWORK_DOT;
        case Network_EQ:
            return NETWORK_EQ;
        case Network_KSM:
            return NETWORK_KSM;
        case Network_GENS:
            return NETWORK_GENS;
//        case Network_HYDRADX:
//            return NETWORK_HYDRADX;
        default:
            return NETWORK_ERROR;
    }
}

//  Full list of der. paths: https://github.com/satoshilabs/slips/blob/master/slip-0044.md
uint32_t get_network_derivation_path(uint8_t id) {
    switch (id) {

        case Network_DOT:
            return (0x80000000 | 0x162); // 354 = m/44/354/0/0/0
        case Network_EQ:
            return (0x80000000 | 0x5f5e0fd); // 99999997
        case Network_KSM:
            return (0x80000000 | 0x1b2); // 434
        case Network_GENS:
            return (0x80000000 | 0x5f5e0fc); // 99999996
//        case Network_HYDRADX:
//            return (0x80000000 | 0x0485944); // 4741444
        default:
            return 0;
    }
}

const char* get_network_genesis_hash(uint8_t id){
    switch (id) {
        case Network_DOT:
            return GENESIS_DOT;
        case Network_EQ:
            return GENESIS_EQ;
        case Network_KSM:
            return GENESIS_KSM;
        case Network_GENS:
            return GENESIS_GENS;
//        case Network_HYDRADX:
//            return GENESIS_HYDRA;
        default:
            return GENESIS_ERROR;
    }
}

// https://polkadot.subscan.io/tools/ss58_transform
uint8_t get_network_address_type(uint8_t id){
//    return 42;

    switch (id) {
        case Network_DOT:
            return 0;
        case Network_EQ:
            return 67;
        case Network_KSM:
            return 2;
        case Network_GENS:
            return 67;
//        case Network_HYDRADX:
//            return 63;
        default:
            return 0;
    }

}