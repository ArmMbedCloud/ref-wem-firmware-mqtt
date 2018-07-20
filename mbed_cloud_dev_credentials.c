
/*
 * Copyright (c) 2018 ARM Limited. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __MBED_CLOUD_DEV_CREDENTIALS_H__
#define __MBED_CLOUD_DEV_CREDENTIALS_H__

#include <inttypes.h>

const char MBED_CLOUD_DEV_BOOTSTRAP_ENDPOINT_NAME[] = "0164b8f2f0126e129df9253e03c00000";
const char MBED_CLOUD_DEV_ACCOUNT_ID[] = "0161a9405c790a580a01210e00000000";
const char MBED_CLOUD_DEV_BOOTSTRAP_SERVER_URI[] = "coaps://bootstrap.us-east-1.mbedcloud.com:5684?aid=0161a9405c790a580a01210e00000000";

const uint8_t MBED_CLOUD_DEV_BOOTSTRAP_DEVICE_CERTIFICATE[] =
{ 0x30, 0x82, 0x02, 0x6e, 0x30, 0x82, 0x02, 0x14,
 0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x10, 0x4f,
 0xee, 0x4f, 0x4a, 0xba, 0xa9, 0x44, 0xc9, 0xa3,
 0x6b, 0x9b, 0xba, 0x41, 0xf5, 0x49, 0x38, 0x30,
 0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d,
 0x04, 0x03, 0x02, 0x30, 0x81, 0xa2, 0x31, 0x0b,
 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13,
 0x02, 0x47, 0x42, 0x31, 0x17, 0x30, 0x15, 0x06,
 0x03, 0x55, 0x04, 0x08, 0x0c, 0x0e, 0x43, 0x61,
 0x6d, 0x62, 0x72, 0x69, 0x64, 0x67, 0x65, 0x73,
 0x68, 0x69, 0x72, 0x65, 0x31, 0x12, 0x30, 0x10,
 0x06, 0x03, 0x55, 0x04, 0x07, 0x0c, 0x09, 0x43,
 0x61, 0x6d, 0x62, 0x72, 0x69, 0x64, 0x67, 0x65,
 0x31, 0x10, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x04,
 0x0a, 0x0c, 0x07, 0x41, 0x52, 0x4d, 0x20, 0x4c,
 0x74, 0x64, 0x31, 0x29, 0x30, 0x27, 0x06, 0x03,
 0x55, 0x04, 0x0b, 0x0c, 0x20, 0x30, 0x31, 0x36,
 0x31, 0x61, 0x39, 0x34, 0x30, 0x35, 0x63, 0x37,
 0x39, 0x30, 0x61, 0x35, 0x38, 0x30, 0x61, 0x30,
 0x31, 0x32, 0x31, 0x30, 0x65, 0x30, 0x30, 0x30,
 0x30, 0x30, 0x30, 0x30, 0x30, 0x31, 0x29, 0x30,
 0x27, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x20,
 0x30, 0x31, 0x36, 0x34, 0x62, 0x38, 0x66, 0x32,
 0x66, 0x30, 0x31, 0x32, 0x36, 0x65, 0x31, 0x32,
 0x39, 0x64, 0x66, 0x39, 0x32, 0x35, 0x33, 0x65,
 0x30, 0x33, 0x63, 0x30, 0x30, 0x30, 0x30, 0x30,
 0x30, 0x1e, 0x17, 0x0d, 0x31, 0x38, 0x30, 0x37,
 0x32, 0x30, 0x31, 0x38, 0x32, 0x38, 0x30, 0x36,
 0x5a, 0x17, 0x0d, 0x32, 0x38, 0x30, 0x37, 0x32,
 0x30, 0x31, 0x38, 0x32, 0x38, 0x30, 0x36, 0x5a,
 0x30, 0x81, 0xa2, 0x31, 0x0b, 0x30, 0x09, 0x06,
 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x47, 0x42,
 0x31, 0x17, 0x30, 0x15, 0x06, 0x03, 0x55, 0x04,
 0x08, 0x0c, 0x0e, 0x43, 0x61, 0x6d, 0x62, 0x72,
 0x69, 0x64, 0x67, 0x65, 0x73, 0x68, 0x69, 0x72,
 0x65, 0x31, 0x12, 0x30, 0x10, 0x06, 0x03, 0x55,
 0x04, 0x07, 0x0c, 0x09, 0x43, 0x61, 0x6d, 0x62,
 0x72, 0x69, 0x64, 0x67, 0x65, 0x31, 0x10, 0x30,
 0x0e, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x0c, 0x07,
 0x41, 0x52, 0x4d, 0x20, 0x4c, 0x74, 0x64, 0x31,
 0x29, 0x30, 0x27, 0x06, 0x03, 0x55, 0x04, 0x0b,
 0x0c, 0x20, 0x30, 0x31, 0x36, 0x31, 0x61, 0x39,
 0x34, 0x30, 0x35, 0x63, 0x37, 0x39, 0x30, 0x61,
 0x35, 0x38, 0x30, 0x61, 0x30, 0x31, 0x32, 0x31,
 0x30, 0x65, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30,
 0x30, 0x30, 0x31, 0x29, 0x30, 0x27, 0x06, 0x03,
 0x55, 0x04, 0x03, 0x0c, 0x20, 0x30, 0x31, 0x36,
 0x34, 0x62, 0x38, 0x66, 0x32, 0x66, 0x30, 0x31,
 0x32, 0x36, 0x65, 0x31, 0x32, 0x39, 0x64, 0x66,
 0x39, 0x32, 0x35, 0x33, 0x65, 0x30, 0x33, 0x63,
 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x59, 0x30,
 0x13, 0x06, 0x07, 0x2a, 0x86, 0x48, 0xce, 0x3d,
 0x02, 0x01, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce,
 0x3d, 0x03, 0x01, 0x07, 0x03, 0x42, 0x00, 0x04,
 0x69, 0x88, 0x6c, 0x08, 0x35, 0x33, 0x42, 0x3d,
 0x1c, 0x0a, 0x3a, 0x63, 0xfc, 0x9d, 0x47, 0x33,
 0x3f, 0x17, 0x71, 0x3d, 0xf3, 0x9b, 0x9b, 0x3f,
 0x2a, 0xa0, 0xa7, 0x73, 0xf2, 0x5f, 0xbd, 0x6b,
 0x46, 0xca, 0x66, 0x61, 0x88, 0xb8, 0xbd, 0x42,
 0xa4, 0x15, 0xbe, 0x32, 0x5a, 0x4f, 0x8e, 0xfb,
 0x12, 0xea, 0x0f, 0x61, 0xab, 0xca, 0xd4, 0xfb,
 0xa9, 0x3a, 0xa4, 0x92, 0xff, 0xb1, 0xc6, 0x95,
 0xa3, 0x2a, 0x30, 0x28, 0x30, 0x12, 0x06, 0x09,
 0x2b, 0x06, 0x01, 0x04, 0x01, 0xa0, 0x20, 0x81,
 0x49, 0x04, 0x05, 0x02, 0x03, 0x40, 0x00, 0x91,
 0x30, 0x12, 0x06, 0x03, 0x55, 0x1d, 0x13, 0x01,
 0x01, 0xff, 0x04, 0x08, 0x30, 0x06, 0x01, 0x01,
 0xff, 0x02, 0x01, 0x00, 0x30, 0x0a, 0x06, 0x08,
 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03, 0x02,
 0x03, 0x48, 0x00, 0x30, 0x45, 0x02, 0x21, 0x00,
 0xf6, 0x77, 0x3f, 0x60, 0x35, 0xc8, 0x52, 0x29,
 0xb2, 0x5b, 0x35, 0x40, 0x01, 0x92, 0xbc, 0x38,
 0xb9, 0x34, 0x8e, 0x63, 0xf2, 0xef, 0xde, 0xac,
 0x06, 0xaa, 0xa5, 0xec, 0x40, 0x9e, 0x97, 0x1e,
 0x02, 0x20, 0x41, 0x5d, 0x6f, 0xdb, 0x67, 0xd9,
 0xfd, 0xcb, 0x07, 0x88, 0x80, 0x77, 0xe4, 0x43,
 0x0d, 0x47, 0xdd, 0xa6, 0xa0, 0xb5, 0x47, 0x04,
 0xfe, 0xbf, 0x2b, 0x54, 0x1b, 0x8b, 0x4b, 0xed,
 0x7a, 0xce };

const uint8_t MBED_CLOUD_DEV_BOOTSTRAP_SERVER_ROOT_CA_CERTIFICATE[] =
{ 0x30, 0x82, 0x02, 0x1f, 0x30, 0x82, 0x01, 0xc5,
 0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x10, 0x3c,
 0x63, 0x38, 0x70, 0x08, 0xd3, 0xc9, 0x8a, 0x4c,
 0x72, 0x1f, 0x8f, 0x45, 0xeb, 0xd8, 0xf3, 0x30,
 0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d,
 0x04, 0x03, 0x02, 0x30, 0x67, 0x31, 0x0b, 0x30,
 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02,
 0x47, 0x42, 0x31, 0x17, 0x30, 0x15, 0x06, 0x03,
 0x55, 0x04, 0x08, 0x13, 0x0e, 0x43, 0x61, 0x6d,
 0x62, 0x72, 0x69, 0x64, 0x67, 0x65, 0x73, 0x68,
 0x69, 0x72, 0x65, 0x31, 0x12, 0x30, 0x10, 0x06,
 0x03, 0x55, 0x04, 0x07, 0x13, 0x09, 0x43, 0x61,
 0x6d, 0x62, 0x72, 0x69, 0x64, 0x67, 0x65, 0x31,
 0x10, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x04, 0x0a,
 0x13, 0x07, 0x41, 0x52, 0x4d, 0x20, 0x4c, 0x74,
 0x64, 0x31, 0x19, 0x30, 0x17, 0x06, 0x03, 0x55,
 0x04, 0x03, 0x13, 0x10, 0x41, 0x52, 0x4d, 0x20,
 0x42, 0x6f, 0x6f, 0x74, 0x73, 0x74, 0x72, 0x61,
 0x70, 0x20, 0x43, 0x41, 0x30, 0x20, 0x17, 0x0d,
 0x31, 0x37, 0x30, 0x34, 0x30, 0x33, 0x31, 0x34,
 0x30, 0x33, 0x33, 0x36, 0x5a, 0x18, 0x0f, 0x32,
 0x30, 0x35, 0x32, 0x30, 0x34, 0x30, 0x33, 0x31,
 0x34, 0x31, 0x33, 0x33, 0x36, 0x5a, 0x30, 0x67,
 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04,
 0x06, 0x13, 0x02, 0x47, 0x42, 0x31, 0x17, 0x30,
 0x15, 0x06, 0x03, 0x55, 0x04, 0x08, 0x13, 0x0e,
 0x43, 0x61, 0x6d, 0x62, 0x72, 0x69, 0x64, 0x67,
 0x65, 0x73, 0x68, 0x69, 0x72, 0x65, 0x31, 0x12,
 0x30, 0x10, 0x06, 0x03, 0x55, 0x04, 0x07, 0x13,
 0x09, 0x43, 0x61, 0x6d, 0x62, 0x72, 0x69, 0x64,
 0x67, 0x65, 0x31, 0x10, 0x30, 0x0e, 0x06, 0x03,
 0x55, 0x04, 0x0a, 0x13, 0x07, 0x41, 0x52, 0x4d,
 0x20, 0x4c, 0x74, 0x64, 0x31, 0x19, 0x30, 0x17,
 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x10, 0x41,
 0x52, 0x4d, 0x20, 0x42, 0x6f, 0x6f, 0x74, 0x73,
 0x74, 0x72, 0x61, 0x70, 0x20, 0x43, 0x41, 0x30,
 0x59, 0x30, 0x13, 0x06, 0x07, 0x2a, 0x86, 0x48,
 0xce, 0x3d, 0x02, 0x01, 0x06, 0x08, 0x2a, 0x86,
 0x48, 0xce, 0x3d, 0x03, 0x01, 0x07, 0x03, 0x42,
 0x00, 0x04, 0x3b, 0xd3, 0xfe, 0xb0, 0xd9, 0xa4,
 0x72, 0xe1, 0x11, 0x11, 0x59, 0xba, 0x06, 0x2d,
 0xf8, 0x26, 0xd5, 0x65, 0x98, 0xaa, 0xcf, 0x2a,
 0x5f, 0xc6, 0x87, 0xa5, 0x6b, 0x0e, 0x30, 0x15,
 0xe8, 0x12, 0x16, 0x49, 0x90, 0xe3, 0xf9, 0x3e,
 0xf9, 0x3d, 0xde, 0xf5, 0x5a, 0x1f, 0x03, 0x44,
 0xbb, 0x81, 0x7a, 0xc9, 0x71, 0x6d, 0x6c, 0xc2,
 0x42, 0x3b, 0x55, 0xdb, 0x86, 0xad, 0x2c, 0xc0,
 0xcf, 0xe4, 0xa3, 0x51, 0x30, 0x4f, 0x30, 0x0b,
 0x06, 0x03, 0x55, 0x1d, 0x0f, 0x04, 0x04, 0x03,
 0x02, 0x01, 0x86, 0x30, 0x0f, 0x06, 0x03, 0x55,
 0x1d, 0x13, 0x01, 0x01, 0xff, 0x04, 0x05, 0x30,
 0x03, 0x01, 0x01, 0xff, 0x30, 0x1d, 0x06, 0x03,
 0x55, 0x1d, 0x0e, 0x04, 0x16, 0x04, 0x14, 0x84,
 0xc0, 0xf5, 0x82, 0xe9, 0x5d, 0xa5, 0xe0, 0xaa,
 0x74, 0x6f, 0xf7, 0x81, 0x8f, 0x4b, 0xe8, 0x9e,
 0xde, 0x5d, 0x80, 0x30, 0x10, 0x06, 0x09, 0x2b,
 0x06, 0x01, 0x04, 0x01, 0x82, 0x37, 0x15, 0x01,
 0x04, 0x03, 0x02, 0x01, 0x00, 0x30, 0x0a, 0x06,
 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03,
 0x02, 0x03, 0x48, 0x00, 0x30, 0x45, 0x02, 0x20,
 0x19, 0x24, 0x0b, 0xc4, 0xac, 0x9d, 0x2b, 0x15,
 0xf8, 0xc3, 0x0c, 0x0b, 0xf6, 0xac, 0xb3, 0xa1,
 0xeb, 0x83, 0xfe, 0x1c, 0x4a, 0x96, 0x44, 0xc6,
 0xa0, 0xbb, 0x56, 0x5c, 0x84, 0x13, 0xc9, 0x0f,
 0x02, 0x21, 0x00, 0xbd, 0x89, 0x1c, 0x54, 0x98,
 0xa5, 0xd0, 0x98, 0xc7, 0x0c, 0x08, 0x2f, 0xd9,
 0x1b, 0xb8, 0x7e, 0xbf, 0x84, 0x3a, 0xfb, 0x8a,
 0x43, 0x1a, 0x8e, 0xac, 0xdc, 0xa8, 0x66, 0x3d,
 0xe3, 0xf9, 0xdc };

const uint8_t MBED_CLOUD_DEV_BOOTSTRAP_DEVICE_PRIVATE_KEY[] =
{ 0x30, 0x81, 0x93, 0x02, 0x01, 0x00, 0x30, 0x13,
 0x06, 0x07, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x02,
 0x01, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d,
 0x03, 0x01, 0x07, 0x04, 0x79, 0x30, 0x77, 0x02,
 0x01, 0x01, 0x04, 0x20, 0x65, 0xe2, 0x93, 0x75,
 0xac, 0x94, 0x6a, 0x90, 0xac, 0xdb, 0x5d, 0xd1,
 0xc3, 0x8a, 0xfc, 0xcb, 0x5d, 0xdb, 0xbe, 0xd8,
 0x23, 0x74, 0x60, 0xa5, 0x03, 0x60, 0x7c, 0x3c,
 0xf9, 0x8e, 0x34, 0x3c, 0xa0, 0x0a, 0x06, 0x08,
 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x03, 0x01, 0x07,
 0xa1, 0x44, 0x03, 0x42, 0x00, 0x04, 0x69, 0x88,
 0x6c, 0x08, 0x35, 0x33, 0x42, 0x3d, 0x1c, 0x0a,
 0x3a, 0x63, 0xfc, 0x9d, 0x47, 0x33, 0x3f, 0x17,
 0x71, 0x3d, 0xf3, 0x9b, 0x9b, 0x3f, 0x2a, 0xa0,
 0xa7, 0x73, 0xf2, 0x5f, 0xbd, 0x6b, 0x46, 0xca,
 0x66, 0x61, 0x88, 0xb8, 0xbd, 0x42, 0xa4, 0x15,
 0xbe, 0x32, 0x5a, 0x4f, 0x8e, 0xfb, 0x12, 0xea,
 0x0f, 0x61, 0xab, 0xca, 0xd4, 0xfb, 0xa9, 0x3a,
 0xa4, 0x92, 0xff, 0xb1, 0xc6, 0x95 };

const uint8_t MBED_CLOUD_DEV_LWM2M_SERVER_ROOT_CA_CERTIFICATE[] =
{ 0x30, 0x82, 0x02, 0x30, 0x30, 0x82, 0x01, 0xd5,
0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x10, 0x26,
0xf9, 0x08, 0xfc, 0xf1, 0xc0, 0x46, 0xa4, 0x4a,
0x4d, 0x2c, 0xf1, 0x94, 0x27, 0xf9, 0x1f, 0x30,
0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d,
0x04, 0x03, 0x02, 0x30, 0x6f, 0x31, 0x0b, 0x30,
0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02,
0x47, 0x42, 0x31, 0x17, 0x30, 0x15, 0x06, 0x03,
0x55, 0x04, 0x08, 0x13, 0x0e, 0x43, 0x61, 0x6d,
0x62, 0x72, 0x69, 0x64, 0x67, 0x65, 0x73, 0x68,
0x69, 0x72, 0x65, 0x31, 0x12, 0x30, 0x10, 0x06,
0x03, 0x55, 0x04, 0x07, 0x13, 0x09, 0x43, 0x61,
0x6d, 0x62, 0x72, 0x69, 0x64, 0x67, 0x65, 0x31,
0x10, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x04, 0x0a,
0x13, 0x07, 0x41, 0x52, 0x4d, 0x20, 0x4c, 0x74,
0x64, 0x31, 0x21, 0x30, 0x1f, 0x06, 0x03, 0x55,
0x04, 0x03, 0x13, 0x18, 0x41, 0x52, 0x4d, 0x20,
0x49, 0x6e, 0x74, 0x65, 0x67, 0x72, 0x61, 0x74,
0x69, 0x6f, 0x6e, 0x20, 0x4c, 0x57, 0x4d, 0x32,
0x4d, 0x20, 0x43, 0x41, 0x30, 0x20, 0x17, 0x0d,
0x31, 0x37, 0x30, 0x32, 0x31, 0x32, 0x31, 0x30,
0x33, 0x37, 0x35, 0x32, 0x5a, 0x18, 0x0f, 0x32,
0x30, 0x35, 0x32, 0x30, 0x32, 0x31, 0x32, 0x31,
0x30, 0x34, 0x37, 0x35, 0x32, 0x5a, 0x30, 0x6f,
0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04,
0x06, 0x13, 0x02, 0x47, 0x42, 0x31, 0x17, 0x30,
0x15, 0x06, 0x03, 0x55, 0x04, 0x08, 0x13, 0x0e,
0x43, 0x61, 0x6d, 0x62, 0x72, 0x69, 0x64, 0x67,
0x65, 0x73, 0x68, 0x69, 0x72, 0x65, 0x31, 0x12,
0x30, 0x10, 0x06, 0x03, 0x55, 0x04, 0x07, 0x13,
0x09, 0x43, 0x61, 0x6d, 0x62, 0x72, 0x69, 0x64,
0x67, 0x65, 0x31, 0x10, 0x30, 0x0e, 0x06, 0x03,
0x55, 0x04, 0x0a, 0x13, 0x07, 0x41, 0x52, 0x4d,
0x20, 0x4c, 0x74, 0x64, 0x31, 0x21, 0x30, 0x1f,
0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x18, 0x41,
0x52, 0x4d, 0x20, 0x49, 0x6e, 0x74, 0x65, 0x67,
0x72, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x4c,
0x57, 0x4d, 0x32, 0x4d, 0x20, 0x43, 0x41, 0x30,
0x59, 0x30, 0x13, 0x06, 0x07, 0x2a, 0x86, 0x48,
0xce, 0x3d, 0x02, 0x01, 0x06, 0x08, 0x2a, 0x86,
0x48, 0xce, 0x3d, 0x03, 0x01, 0x07, 0x03, 0x42,
0x00, 0x04, 0xba, 0xea, 0x80, 0x01, 0x2d, 0xf0,
0xe1, 0xb6, 0xc5, 0x5f, 0xf9, 0x76, 0x84, 0x31,
0xa9, 0x29, 0xa1, 0xc7, 0xa8, 0xfd, 0xa0, 0xad,
0xd9, 0x94, 0xe7, 0xec, 0x5a, 0x33, 0xa1, 0x2c,
0x8e, 0x36, 0x43, 0x9b, 0x18, 0xdf, 0xce, 0x71,
0x14, 0x24, 0xb1, 0xfb, 0x16, 0x34, 0x0e, 0x43,
0xfc, 0x23, 0x77, 0xd4, 0x13, 0xd7, 0x11, 0xaa,
0x39, 0x60, 0xab, 0xa2, 0xdf, 0x24, 0xb3, 0xeb,
0xa0, 0xc5, 0xa3, 0x51, 0x30, 0x4f, 0x30, 0x0b,
0x06, 0x03, 0x55, 0x1d, 0x0f, 0x04, 0x04, 0x03,
0x02, 0x01, 0x86, 0x30, 0x0f, 0x06, 0x03, 0x55,
0x1d, 0x13, 0x01, 0x01, 0xff, 0x04, 0x05, 0x30,
0x03, 0x01, 0x01, 0xff, 0x30, 0x1d, 0x06, 0x03,
0x55, 0x1d, 0x0e, 0x04, 0x16, 0x04, 0x14, 0x7b,
0xa1, 0xa5, 0x94, 0xa5, 0xe5, 0x8f, 0x95, 0x5d,
0xd4, 0xce, 0xdc, 0x0f, 0x8a, 0xbe, 0xad, 0x9a,
0x6b, 0x66, 0x3e, 0x30, 0x10, 0x06, 0x09, 0x2b,
0x06, 0x01, 0x04, 0x01, 0x82, 0x37, 0x15, 0x01,
0x04, 0x03, 0x02, 0x01, 0x00, 0x30, 0x0a, 0x06,
0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03,
0x02, 0x03, 0x49, 0x00, 0x30, 0x46, 0x02, 0x21,
0x00, 0xd2, 0x06, 0x28, 0xc5, 0x31, 0x3a, 0x11,
0x8d, 0xb6, 0xcb, 0x2b, 0x3f, 0xdd, 0x2a, 0x9a,
0x13, 0x30, 0x52, 0x77, 0xaa, 0xda, 0xda, 0xcb,
0xce, 0xb9, 0x5c, 0xe4, 0x32, 0x1c, 0x02, 0xfa,
0x30, 0x02, 0x21, 0x00, 0xb3, 0x82, 0x24, 0xa2,
0xb1, 0x67, 0x6b, 0x69, 0x07, 0x0e, 0xcd, 0x77,
0x74, 0x99, 0x06, 0x9c, 0x59, 0xb2, 0x00, 0xc0,
0xb3, 0xbb, 0x37, 0x5b, 0xc0, 0x1b, 0xfb, 0xd9,
0x70, 0x98, 0xb9, 0x1e };

const char MBED_CLOUD_DEV_MANUFACTURER[] = "dev_manufacturer";

const char MBED_CLOUD_DEV_MODEL_NUMBER[] = "dev_model_num";

const char MBED_CLOUD_DEV_SERIAL_NUMBER[] = "0";

const char MBED_CLOUD_DEV_DEVICE_TYPE[] = "dev_device_type";

const char MBED_CLOUD_DEV_HARDWARE_VERSION[] = "dev_hardware_version";

const uint32_t MBED_CLOUD_DEV_MEMORY_TOTAL_KB = 0;

const uint32_t MBED_CLOUD_DEV_BOOTSTRAP_DEVICE_CERTIFICATE_SIZE = sizeof(MBED_CLOUD_DEV_BOOTSTRAP_DEVICE_CERTIFICATE);
const uint32_t MBED_CLOUD_DEV_BOOTSTRAP_SERVER_ROOT_CA_CERTIFICATE_SIZE = sizeof(MBED_CLOUD_DEV_BOOTSTRAP_SERVER_ROOT_CA_CERTIFICATE);
const uint32_t MBED_CLOUD_DEV_BOOTSTRAP_DEVICE_PRIVATE_KEY_SIZE = sizeof(MBED_CLOUD_DEV_BOOTSTRAP_DEVICE_PRIVATE_KEY);

#endif //__MBED_CLOUD_DEV_CREDENTIALS_H__