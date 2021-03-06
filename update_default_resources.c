
//----------------------------------------------------------------------------
//   The confidential and proprietary information contained in this file may
//   only be used by a person authorised under and to the extent permitted
//   by a subsisting licensing agreement from ARM Limited or its affiliates.
//
//          (C) COPYRIGHT 2013-2017 ARM Limited or its affiliates.
//              ALL RIGHTS RESERVED
//
//   This entire notice must be reproduced on all copies of this file
//   and copies of this file may only be made by a person if such person is
//   permitted to do so under the terms of a subsisting license agreement
//   from ARM Limited or its affiliates.
//----------------------------------------------------------------------------

#ifdef MBED_CLOUD_CLIENT_USER_CONFIG_FILE
#include MBED_CLOUD_CLIENT_USER_CONFIG_FILE
#endif

#include <stdint.h>

#ifdef MBED_CLOUD_DEV_UPDATE_ID
const uint8_t arm_uc_vendor_id[] = {
    0xfa, 0x6b, 0x4a, 0x53, 0xd5, 0xad, 0x5f, 0xdf, 0xbe, 0x9d, 0xe6, 0x63, 0xe4, 0xd4, 0x1f, 0xfe
};
const uint16_t arm_uc_vendor_id_size = sizeof(arm_uc_vendor_id);

const uint8_t arm_uc_class_id[]  = {
    0xa0, 0xde, 0x7b, 0xaf, 0x19, 0x18, 0x53, 0xf1, 0xab, 0x4, 0x93, 0x26, 0x78, 0x7c, 0x7a, 0xc1
};
const uint16_t arm_uc_class_id_size = sizeof(arm_uc_class_id);
#endif

#ifdef MBED_CLOUD_DEV_UPDATE_CERT
const uint8_t arm_uc_default_fingerprint[] =  {
    0x7, 0x2a, 0x34, 0x1d, 0xb2, 0x58, 0x6, 0xed, 0xe5, 0xbf, 0x31, 0xa8, 0x67, 0xe6, 0xb, 0xe6,
    0x8d, 0x9c, 0xe1, 0xab, 0x1d, 0xb5, 0x74, 0xfd, 0x6f, 0x21, 0x86, 0xea, 0x69, 0x58, 0x29, 0x5
};
const uint16_t arm_uc_default_fingerprint_size =
    sizeof(arm_uc_default_fingerprint);

const uint8_t arm_uc_default_subject_key_identifier[] =  {
    0x95, 0xbd, 0x1e, 0x2f, 0x99, 0xbd, 0x3e, 0x18, 0x52, 0xcb, 0xc9, 0x7f, 0xf, 0x3b, 0x99, 0xba,
    0x2f, 0x7c, 0x85, 0xed
};
const uint16_t arm_uc_default_subject_key_identifier_size =
    sizeof(arm_uc_default_subject_key_identifier);

const uint8_t arm_uc_default_certificate[] = {
    0x30, 0x82, 0x1, 0x7f, 0x30, 0x82, 0x1, 0x25, 0xa0, 0x3, 0x2, 0x1, 0x2, 0x2, 0x14, 0x2f,
    0x1d, 0xfa, 0x4a, 0xde, 0x1f, 0xd, 0x9, 0x71, 0x0, 0xb4, 0x59, 0x80, 0xe4, 0xfb, 0x80, 0xf6,
    0x28, 0x7, 0x13, 0x30, 0xa, 0x6, 0x8, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x4, 0x3, 0x2, 0x30,
    0x12, 0x31, 0x10, 0x30, 0xe, 0x6, 0x3, 0x55, 0x4, 0x3, 0xc, 0x7, 0x61, 0x72, 0x6d, 0x2e,
    0x63, 0x6f, 0x6d, 0x30, 0x1e, 0x17, 0xd, 0x31, 0x38, 0x30, 0x37, 0x32, 0x30, 0x31, 0x38, 0x31,
    0x31, 0x34, 0x33, 0x5a, 0x17, 0xd, 0x31, 0x38, 0x31, 0x30, 0x31, 0x38, 0x31, 0x38, 0x31, 0x31,
    0x34, 0x33, 0x5a, 0x30, 0x12, 0x31, 0x10, 0x30, 0xe, 0x6, 0x3, 0x55, 0x4, 0x3, 0xc, 0x7,
    0x61, 0x72, 0x6d, 0x2e, 0x63, 0x6f, 0x6d, 0x30, 0x59, 0x30, 0x13, 0x6, 0x7, 0x2a, 0x86, 0x48,
    0xce, 0x3d, 0x2, 0x1, 0x6, 0x8, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x3, 0x1, 0x7, 0x3, 0x42,
    0x0, 0x4, 0x3, 0x1a, 0xb, 0x30, 0xa, 0x3d, 0x69, 0xea, 0x10, 0xfa, 0xca, 0x89, 0x9c, 0x9c,
    0x4d, 0xd9, 0xb2, 0xbb, 0x5d, 0xe5, 0x70, 0x8c, 0x32, 0xef, 0x12, 0x24, 0x91, 0x63, 0xe9, 0x40,
    0x65, 0x94, 0xa7, 0xf9, 0xae, 0x4, 0x60, 0xf9, 0x7b, 0x9b, 0x21, 0x65, 0x21, 0xf6, 0x5f, 0xc8,
    0x46, 0xa2, 0x88, 0xd2, 0x6b, 0xff, 0xe2, 0xc4, 0xa5, 0xf9, 0x72, 0xde, 0x8a, 0x15, 0x93, 0xea,
    0x2, 0xf7, 0xa3, 0x59, 0x30, 0x57, 0x30, 0xb, 0x6, 0x3, 0x55, 0x1d, 0xf, 0x4, 0x4, 0x3,
    0x2, 0x7, 0x80, 0x30, 0x14, 0x6, 0x3, 0x55, 0x1d, 0x11, 0x4, 0xd, 0x30, 0xb, 0x82, 0x9,
    0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x68, 0x6f, 0x73, 0x74, 0x30, 0x13, 0x6, 0x3, 0x55, 0x1d, 0x25,
    0x4, 0xc, 0x30, 0xa, 0x6, 0x8, 0x2b, 0x6, 0x1, 0x5, 0x5, 0x7, 0x3, 0x3, 0x30, 0x1d,
    0x6, 0x3, 0x55, 0x1d, 0xe, 0x4, 0x16, 0x4, 0x14, 0x95, 0xbd, 0x1e, 0x2f, 0x99, 0xbd, 0x3e,
    0x18, 0x52, 0xcb, 0xc9, 0x7f, 0xf, 0x3b, 0x99, 0xba, 0x2f, 0x7c, 0x85, 0xed, 0x30, 0xa, 0x6,
    0x8, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x4, 0x3, 0x2, 0x3, 0x48, 0x0, 0x30, 0x45, 0x2, 0x21,
    0x0, 0xba, 0x67, 0x44, 0x70, 0xcb, 0x4, 0x33, 0xc7, 0x63, 0x95, 0xee, 0xa9, 0xc6, 0x87, 0x22,
    0x18, 0x99, 0x24, 0x6c, 0xfa, 0x22, 0x68, 0xea, 0xea, 0x18, 0x68, 0x3b, 0x16, 0x92, 0xf5, 0x5,
    0x6e, 0x2, 0x20, 0x16, 0xff, 0xd2, 0x9c, 0x2a, 0x4a, 0x49, 0xc3, 0xbd, 0x31, 0xfd, 0x8b, 0xff,
    0x1c, 0xed, 0xe9, 0xdf, 0xcf, 0xef, 0x57, 0x85, 0x5d, 0xcc, 0x9d, 0x14, 0xb6, 0x8d, 0x3f, 0x34,
    0x85, 0x9a, 0x10
};
const uint16_t arm_uc_default_certificate_size = sizeof(arm_uc_default_certificate);
#endif


#ifdef MBED_CLOUD_DEV_UPDATE_PSK
const uint8_t arm_uc_default_psk[] = {
    
};
const uint8_t arm_uc_default_psk_size = sizeof(arm_uc_default_psk);
const uint16_t arm_uc_default_psk_bits = sizeof(arm_uc_default_psk)*8;

const uint8_t arm_uc_default_psk_id[] = {
    
};
const uint8_t arm_uc_default_psk_id_size = sizeof(arm_uc_default_psk_id);
#endif
