#include <cstdio>

#include "mbed.h"
#include "rtos.h"
#undef MBED_CONF_APP_ESP8266_DEBUG
#include "EthernetInterface.h"
#include "MQTTThreadedClient.h"
#include "mbedtls/platform.h"
//#include "m2mresource.h"

using namespace MQTT;

const uint8_t DS_D_C[] =
{ 0x30, 0x82, 0x02, 0x70, 0x30, 0x82, 0x02, 0x15,
 0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x11, 0x00,
 0xee, 0x9f, 0x75, 0x81, 0xea, 0x7f, 0x4d, 0x4d,
 0xa0, 0x23, 0xc5, 0x76, 0xbf, 0x67, 0x05, 0x74,
 0x30, 0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce,
 0x3d, 0x04, 0x03, 0x02, 0x30, 0x81, 0xa2, 0x31,
 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06,
 0x13, 0x02, 0x47, 0x42, 0x31, 0x17, 0x30, 0x15,
 0x06, 0x03, 0x55, 0x04, 0x08, 0x0c, 0x0e, 0x43,
 0x61, 0x6d, 0x62, 0x72, 0x69, 0x64, 0x67, 0x65,
 0x73, 0x68, 0x69, 0x72, 0x65, 0x31, 0x12, 0x30,
 0x10, 0x06, 0x03, 0x55, 0x04, 0x07, 0x0c, 0x09,
 0x43, 0x61, 0x6d, 0x62, 0x72, 0x69, 0x64, 0x67,
 0x65, 0x31, 0x10, 0x30, 0x0e, 0x06, 0x03, 0x55,
 0x04, 0x0a, 0x0c, 0x07, 0x41, 0x52, 0x4d, 0x20,
 0x4c, 0x74, 0x64, 0x31, 0x29, 0x30, 0x27, 0x06,
 0x03, 0x55, 0x04, 0x0b, 0x0c, 0x20, 0x30, 0x31,
 0x36, 0x30, 0x63, 0x34, 0x65, 0x37, 0x30, 0x36,
 0x38, 0x39, 0x30, 0x61, 0x35, 0x38, 0x30, 0x61,
 0x30, 0x31, 0x30, 0x36, 0x32, 0x35, 0x30, 0x30,
 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x31, 0x29,
 0x30, 0x27, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c,
 0x20, 0x30, 0x31, 0x36, 0x34, 0x36, 0x63, 0x36,
 0x32, 0x30, 0x62, 0x38, 0x34, 0x31, 0x61, 0x64,
 0x39, 0x65, 0x39, 0x35, 0x64, 0x64, 0x38, 0x61,
 0x38, 0x30, 0x33, 0x63, 0x30, 0x30, 0x30, 0x30,
 0x30, 0x30, 0x1e, 0x17, 0x0d, 0x31, 0x38, 0x30,
 0x37, 0x30, 0x35, 0x32, 0x31, 0x33, 0x38, 0x34,
 0x32, 0x5a, 0x17, 0x0d, 0x32, 0x38, 0x30, 0x37,
 0x30, 0x35, 0x32, 0x31, 0x33, 0x38, 0x34, 0x32,
 0x5a, 0x30, 0x81, 0xa2, 0x31, 0x0b, 0x30, 0x09,
 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x47,
 0x42, 0x31, 0x17, 0x30, 0x15, 0x06, 0x03, 0x55,
 0x04, 0x08, 0x0c, 0x0e, 0x43, 0x61, 0x6d, 0x62,
 0x72, 0x69, 0x64, 0x67, 0x65, 0x73, 0x68, 0x69,
 0x72, 0x65, 0x31, 0x12, 0x30, 0x10, 0x06, 0x03,
 0x55, 0x04, 0x07, 0x0c, 0x09, 0x43, 0x61, 0x6d,
 0x62, 0x72, 0x69, 0x64, 0x67, 0x65, 0x31, 0x10,
 0x30, 0x0e, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x0c,
 0x07, 0x41, 0x52, 0x4d, 0x20, 0x4c, 0x74, 0x64,
 0x31, 0x29, 0x30, 0x27, 0x06, 0x03, 0x55, 0x04,
 0x0b, 0x0c, 0x20, 0x30, 0x31, 0x36, 0x30, 0x63,
 0x34, 0x65, 0x37, 0x30, 0x36, 0x38, 0x39, 0x30,
 0x61, 0x35, 0x38, 0x30, 0x61, 0x30, 0x31, 0x30,
 0x36, 0x32, 0x35, 0x30, 0x30, 0x30, 0x30, 0x30,
 0x30, 0x30, 0x30, 0x31, 0x29, 0x30, 0x27, 0x06,
 0x03, 0x55, 0x04, 0x03, 0x0c, 0x20, 0x30, 0x31,
 0x36, 0x34, 0x36, 0x63, 0x36, 0x32, 0x30, 0x62,
 0x38, 0x34, 0x31, 0x61, 0x64, 0x39, 0x65, 0x39,
 0x35, 0x64, 0x64, 0x38, 0x61, 0x38, 0x30, 0x33,
 0x63, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x59,
 0x30, 0x13, 0x06, 0x07, 0x2a, 0x86, 0x48, 0xce,
 0x3d, 0x02, 0x01, 0x06, 0x08, 0x2a, 0x86, 0x48,
 0xce, 0x3d, 0x03, 0x01, 0x07, 0x03, 0x42, 0x00,
 0x04, 0xe4, 0xb5, 0xdb, 0xc4, 0x5a, 0xdd, 0x0e,
 0xe7, 0xdf, 0xdc, 0x7a, 0x16, 0xa9, 0x16, 0xc4,
 0x0b, 0xa5, 0xe8, 0x95, 0x00, 0xdc, 0xb1, 0x5a,
 0x7e, 0x4a, 0x4c, 0x8b, 0x47, 0xd5, 0xef, 0xd7,
 0xae, 0xea, 0xda, 0xcf, 0xc3, 0x4e, 0xbe, 0x0c,
 0x4f, 0xd7, 0xb0, 0x2b, 0x57, 0x4b, 0x31, 0xc9,
 0x4f, 0x33, 0xde, 0x30, 0x33, 0x60, 0xda, 0xd3,
 0xda, 0x59, 0xba, 0x7a, 0x5f, 0xb4, 0x74, 0x07,
 0x29, 0xa3, 0x2a, 0x30, 0x28, 0x30, 0x12, 0x06,
 0x09, 0x2b, 0x06, 0x01, 0x04, 0x01, 0xa0, 0x20,
 0x81, 0x49, 0x04, 0x05, 0x02, 0x03, 0x40, 0x00,
 0x91, 0x30, 0x12, 0x06, 0x03, 0x55, 0x1d, 0x13,
 0x01, 0x01, 0xff, 0x04, 0x08, 0x30, 0x06, 0x01,
 0x01, 0xff, 0x02, 0x01, 0x00, 0x30, 0x0a, 0x06,
 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03,
 0x02, 0x03, 0x49, 0x00, 0x30, 0x46, 0x02, 0x21,
 0x00, 0x93, 0xf3, 0x92, 0x7d, 0xaf, 0xbd, 0x12,
 0x43, 0xf1, 0x24, 0x32, 0x77, 0x93, 0x27, 0x10,
 0x90, 0xc0, 0xe2, 0x09, 0xe1, 0x07, 0xc6, 0xcb,
 0xa0, 0xb9, 0x9b, 0x70, 0xe6, 0x3a, 0x82, 0xcb,
 0x52, 0x02, 0x21, 0x00, 0xb7, 0x9b, 0xe1, 0x47,
 0x2b, 0x93, 0x93, 0x2c, 0x65, 0xb6, 0x5d, 0x36,
 0xad, 0xda, 0xa3, 0x3c, 0x09, 0x67, 0xcc, 0x03,
 0xbe, 0xd5, 0xd2, 0xdc, 0x3f, 0x82, 0x62, 0x3c,
 0x86, 0xe2, 0x91, 0x94 };

const uint8_t DS_LWM2M_R_C[] =
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

const uint8_t DS_BOOTSTRAP_R_C[] =
{ 0x30, 0x82, 0x02, 0x35, 0x30, 0x82, 0x01, 0xdb,
 0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x10, 0x5c,
 0x27, 0xa5, 0x76, 0x7d, 0x58, 0x85, 0x8a, 0x43,
 0x91, 0xa0, 0x61, 0xab, 0xcf, 0xa6, 0x59, 0x30,
 0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d,
 0x04, 0x03, 0x02, 0x30, 0x72, 0x31, 0x0b, 0x30,
 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02,
 0x47, 0x42, 0x31, 0x17, 0x30, 0x15, 0x06, 0x03,
 0x55, 0x04, 0x08, 0x13, 0x0e, 0x43, 0x61, 0x6d,
 0x62, 0x72, 0x69, 0x64, 0x67, 0x65, 0x73, 0x68,
 0x69, 0x72, 0x65, 0x31, 0x12, 0x30, 0x10, 0x06,
 0x03, 0x55, 0x04, 0x07, 0x13, 0x09, 0x43, 0x61,
 0x6d, 0x62, 0x72, 0x69, 0x64, 0x67, 0x65, 0x31,
 0x10, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x04, 0x0a,
 0x13, 0x07, 0x41, 0x52, 0x4d, 0x20, 0x4c, 0x74,
 0x64, 0x31, 0x24, 0x30, 0x22, 0x06, 0x03, 0x55,
 0x04, 0x03, 0x13, 0x1b, 0x41, 0x52, 0x4d, 0x20,
 0x49, 0x6e, 0x74, 0x65, 0x67, 0x72, 0x61, 0x74,
 0x69, 0x6f, 0x6e, 0x20, 0x42, 0x6f, 0x6f, 0x74,
 0x73, 0x74, 0x72, 0x61, 0x70, 0x43, 0x41, 0x30,
 0x20, 0x17, 0x0d, 0x31, 0x37, 0x30, 0x35, 0x31,
 0x35, 0x31, 0x39, 0x34, 0x39, 0x31, 0x31, 0x5a,
 0x18, 0x0f, 0x32, 0x30, 0x35, 0x32, 0x30, 0x35,
 0x31, 0x35, 0x31, 0x39, 0x35, 0x39, 0x31, 0x30,
 0x5a, 0x30, 0x72, 0x31, 0x0b, 0x30, 0x09, 0x06,
 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x47, 0x42,
 0x31, 0x17, 0x30, 0x15, 0x06, 0x03, 0x55, 0x04,
 0x08, 0x13, 0x0e, 0x43, 0x61, 0x6d, 0x62, 0x72,
 0x69, 0x64, 0x67, 0x65, 0x73, 0x68, 0x69, 0x72,
 0x65, 0x31, 0x12, 0x30, 0x10, 0x06, 0x03, 0x55,
 0x04, 0x07, 0x13, 0x09, 0x43, 0x61, 0x6d, 0x62,
 0x72, 0x69, 0x64, 0x67, 0x65, 0x31, 0x10, 0x30,
 0x0e, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13, 0x07,
 0x41, 0x52, 0x4d, 0x20, 0x4c, 0x74, 0x64, 0x31,
 0x24, 0x30, 0x22, 0x06, 0x03, 0x55, 0x04, 0x03,
 0x13, 0x1b, 0x41, 0x52, 0x4d, 0x20, 0x49, 0x6e,
 0x74, 0x65, 0x67, 0x72, 0x61, 0x74, 0x69, 0x6f,
 0x6e, 0x20, 0x42, 0x6f, 0x6f, 0x74, 0x73, 0x74,
 0x72, 0x61, 0x70, 0x43, 0x41, 0x30, 0x59, 0x30,
 0x13, 0x06, 0x07, 0x2a, 0x86, 0x48, 0xce, 0x3d,
 0x02, 0x01, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce,
 0x3d, 0x03, 0x01, 0x07, 0x03, 0x42, 0x00, 0x04,
 0x8b, 0x7c, 0x86, 0xc3, 0x88, 0x54, 0xe6, 0x5f,
 0xe0, 0x57, 0x4e, 0x1b, 0xac, 0x29, 0x82, 0xea,
 0x7d, 0x91, 0x00, 0x63, 0xa7, 0x4a, 0x05, 0xbc,
 0x54, 0xc5, 0x71, 0x27, 0x33, 0x19, 0x1b, 0x2e,
 0xfa, 0x41, 0xf8, 0x7a, 0x9a, 0x0c, 0x5d, 0xfc,
 0xb3, 0x37, 0x01, 0x99, 0xc5, 0xc9, 0xbe, 0x78,
 0x5b, 0x1d, 0xec, 0xb0, 0x1a, 0x1d, 0xdc, 0xe4,
 0x6f, 0x57, 0x04, 0xf4, 0x3a, 0xca, 0xa8, 0xd2,
 0xa3, 0x51, 0x30, 0x4f, 0x30, 0x0b, 0x06, 0x03,
 0x55, 0x1d, 0x0f, 0x04, 0x04, 0x03, 0x02, 0x01,
 0x86, 0x30, 0x0f, 0x06, 0x03, 0x55, 0x1d, 0x13,
 0x01, 0x01, 0xff, 0x04, 0x05, 0x30, 0x03, 0x01,
 0x01, 0xff, 0x30, 0x1d, 0x06, 0x03, 0x55, 0x1d,
 0x0e, 0x04, 0x16, 0x04, 0x14, 0x13, 0xef, 0x69,
 0xfa, 0x62, 0x3f, 0x00, 0x86, 0xf4, 0x05, 0xb8,
 0xb6, 0xe6, 0xb2, 0xf1, 0xdb, 0x69, 0x10, 0xb4,
 0x39, 0x30, 0x10, 0x06, 0x09, 0x2b, 0x06, 0x01,
 0x04, 0x01, 0x82, 0x37, 0x15, 0x01, 0x04, 0x03,
 0x02, 0x01, 0x00, 0x30, 0x0a, 0x06, 0x08, 0x2a,
 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03, 0x02, 0x03,
 0x48, 0x00, 0x30, 0x45, 0x02, 0x21, 0x00, 0xa2,
 0x50, 0x88, 0x0f, 0x55, 0xe8, 0x26, 0x49, 0xe6,
 0xf5, 0x71, 0x86, 0x33, 0x29, 0x05, 0x4c, 0xf9,
 0xfd, 0x1f, 0x14, 0x98, 0x92, 0x85, 0xd9, 0x5c,
 0x48, 0x02, 0x9e, 0xc2, 0x79, 0xa8, 0x59, 0x02,
 0x20, 0x3e, 0xfe, 0x3c, 0xa0, 0xbf, 0xd3, 0x0f,
 0x15, 0x83, 0x56, 0xbc, 0xf2, 0xfa, 0x16, 0x26,
 0x7a, 0xc1, 0x68, 0xaa, 0xbc, 0x91, 0x3c, 0x69,
 0x44, 0x36, 0xf9, 0x74, 0xa1, 0x82, 0x76, 0x7a,
 0x6e };

const uint8_t DS_P_K[] =
{ 0x30, 0x81, 0x93, 0x02, 0x01, 0x00, 0x30, 0x13,
 0x06, 0x07, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x02,
 0x01, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d,
 0x03, 0x01, 0x07, 0x04, 0x79, 0x30, 0x77, 0x02,
 0x01, 0x01, 0x04, 0x20, 0xec, 0xd6, 0xd7, 0x34,
 0x4d, 0xc3, 0x7f, 0xb5, 0xc4, 0x78, 0x49, 0x7e,
 0x94, 0x7d, 0x18, 0xd8, 0x3b, 0x71, 0x25, 0xbc,
 0x0b, 0x35, 0xee, 0x68, 0xbf, 0x63, 0xc9, 0x5a,
 0xde, 0xe4, 0xed, 0xf3, 0xa0, 0x0a, 0x06, 0x08,
 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x03, 0x01, 0x07,
 0xa1, 0x44, 0x03, 0x42, 0x00, 0x04, 0xe4, 0xb5,
 0xdb, 0xc4, 0x5a, 0xdd, 0x0e, 0xe7, 0xdf, 0xdc,
 0x7a, 0x16, 0xa9, 0x16, 0xc4, 0x0b, 0xa5, 0xe8,
 0x95, 0x00, 0xdc, 0xb1, 0x5a, 0x7e, 0x4a, 0x4c,
 0x8b, 0x47, 0xd5, 0xef, 0xd7, 0xae, 0xea, 0xda,
 0xcf, 0xc3, 0x4e, 0xbe, 0x0c, 0x4f, 0xd7, 0xb0,
 0x2b, 0x57, 0x4b, 0x31, 0xc9, 0x4f, 0x33, 0xde,
 0x30, 0x33, 0x60, 0xda, 0xd3, 0xda, 0x59, 0xba,
 0x7a, 0x5f, 0xb4, 0x74, 0x07, 0x29 };


//#define AMAZON_CERT
#define MBED_CLOUD_CERT

#ifdef MBED_CLOUD_CERT
       #include "mbed_cloud_dev_credentials.c"
       bool isDER = true;
       static const char * clientID = "mbed-sample";
       static const char * topic_1 = "topic/test";
       const char* hostname = "ingest.mqtt.data.mbedcloudintegration.net";
#elif defined(AMAZON_CERT)
  bool isDER = false;
  #include "amazon_mqtt_conf_new.h"   // TLS handshake issue??
  //#include "amazon_mqtt_conf.h"
#elif defined(LOCAL_CERT)
      #include "local_mqtt_conf.h"
      bool isDER=false;
#endif

int arrivedcount = 0;

#include "MQTTDataProvider.h"

long epochtime = 1528406876;   // Thursday, June 7, 2018 9:27:56 PM
static const float sample_values[62] =
      {
        0.0,
        0.09983341664682815,
        0.19866933079506122,
        0.2955202066613396,
        0.3894183423086505,
        0.479425538604203,
        0.5646424733950355,
        0.6442176872376911,
        0.7173560908995228,
        0.7833269096274833,
        0.8414709848078965,
        0.8912073600614354,
        0.9320390859672264,
        0.963558185417193,
        0.9854497299884603,
        0.9974949866040544,
        0.9995736030415051,
        0.9916648104524686,
        0.9738476308781951,
        0.9463000876874145,
        0.9092974268256817,
        0.8632093666488738,
        0.8084964038195901,
        0.74570521217672,
        0.6754631805511506,
        0.5984721441039564,
        0.5155013718214642,
        0.4273798802338298,
        0.33498815015590466,
        0.23924932921398198,
        0.1411200080598672,
        0.04158066243329049,
        -0.058374143427580086,
        -0.15774569414324865,
        -0.25554110202683167,
        -0.35078322768961984,
        -0.44252044329485246,
        -0.5298361409084934,
        -0.6118578909427193,
        -0.6877661591839741,
        -0.7568024953079282,
        -0.8182771110644108,
        -0.8715757724135881,
        -0.9161659367494549,
        -0.9516020738895161,
        -0.977530117665097,
        -0.9936910036334645,
        -0.9999232575641008,
        -0.9961646088358406,
        -0.9824526126243325,
        -0.9589242746631385,
        -0.9258146823277321,
        -0.8834546557201531,
        -0.8322674422239008,
        -0.7727644875559871,
        -0.7055403255703919,
        -0.6312666378723208,
        -0.5506855425976376,
        -0.4646021794137566,
        -0.373876664830236,
        -0.27941549819892586,
        -0.13216250427209502
 };

void messageArrived(MessageData& md)
{
    Message &message = md.message;
    printf("Arrived Callback 1 : qos %d, retained %d, dup %d, packetid %d\r\n", message.qos, message.retained, message.dup, message.id);
    printf("Payload [%.*s]\r\n", message.payloadlen, (char*)message.payload);
    ++arrivedcount;
}

string MQTTDataProvider::getDataOld(int i){
     //returns JSON in format which was used in 1st demo with plottting
     if (i == sizeof(sample_values) / sizeof(sample_values[0])) {
                i = 0;
      }

     char BUFFER[MAX_MQTT_PAYLOAD_SIZE];
     sprintf(BUFFER, "{\"DeviceID\":\"53791ab8k93e000000000001001003sf\",\"Resource\":\"phase\",\"Value\":%.3f,\"TimeStamp\":%ld}", sample_values[i], epochtime);

     string json = BUFFER;
     return json;
}

string MQTTDataProvider::getData(int i){

    //returns JSON as described here: https://confluence.arm.com/display/IoTBU/Message+Structure
    char str_time[32];
    sprintf(str_time, "%ld", epochtime);

    string json="{\"f\": \"1\",";
    json += "\"id\": \"";
    json += deviceId;
    json += "\",";
    json += "\"d\": [";

    size_t j=0; // resource counter - it is used to print or not to print the comma after }
    for( std::map<string,DeviceResource*>::const_iterator it = resources.begin(); it != resources.end(); ++it )
    {
         //printf ("%d=>  str_resource key=%s  value=%s \r\n",j,(it->first).c_str(), (it->second)->get_value_string().c_str());


         j++;
         json += "{";
         json += "\"";
         json += it->first;   //resource_path
         json += "\": [";
             json += "{";
             json += "\"t\": ";
             json +=str_time;
             json += ",";

             json += "\"v\": {";

             json += "\"";
             json += (it->second)->resource_type();
             json += "\":";
             json += "\"";
             json += (it->second)->get_value_string();
             json += "\"";
             json += "}";
         json += "}";
         json += "]";

         json += "}";
         if (resources.size() > j) json += ",";
         json += "";

    }

    json += "]}";

    printf(" ===> END getData() counter=%d \r\n", i);
    return json;
}

void MQTTDataProvider::run(NetworkInterface *network){

    Thread msgSender(osPriorityNormal); // there are optional args: stack_size, etc

    //NetworkInterface* network = easy_connect(true); //use if no Mbed Cloud Client
    //NetworkInterface* network = easy_get_netif(true); // already created by Mbed Cloud Client
    // do not create new connection, because it will raise the error:
    // error NSAPI_ERROR_IS_CONNECTED  -3015 socket is already connected (error code is defined in nsapi_types.h)
    if (!network) {
        mbedtls_printf("===ERROR=== easy_get_netif inside MQTTDataProvider::run \r\n");
        return ;
    }

    int port = 8883;

#ifdef MBED_CLOUD_CERT
      // DER format
      MQTTThreadedClient mqtt(network, (const unsigned char*)(MBED_CLOUD_DEV_LWM2M_SERVER_ROOT_CA_CERTIFICATE), (const unsigned char*)MBED_CLOUD_DEV_BOOTSTRAP_DEVICE_CERTIFICATE, (const unsigned char*)MBED_CLOUD_DEV_BOOTSTRAP_DEVICE_PRIVATE_KEY, isDER);

      // printf ("MBED_CLOUD_DEV_BOOTSTRAP_SERVER_ROOT_CA_CERTIFICATE sizeof=  %d \r\n", sizeof(DS_MBED_CLOUD_DEV_BOOTSTRAP_SERVER_ROOT_CA_CERTIFICATE));  // do not use it!
      // printf (" MBED_CLOUD_DEV_LWM2M_SERVER_ROOT_CA_CERTIFICATE    sizeof=  %d \r\n", sizeof(DS_MBED_CLOUD_DEV_LWM2M_SERVER_ROOT_CA_CERTIFICATE));  //   use it!

      mqtt.ssl_ca_len          = sizeof(MBED_CLOUD_DEV_LWM2M_SERVER_ROOT_CA_CERTIFICATE);
      mqtt.ssl_client_cert_len = sizeof(MBED_CLOUD_DEV_BOOTSTRAP_DEVICE_CERTIFICATE);
      mqtt.ssl_client_pkey_len = sizeof(MBED_CLOUD_DEV_BOOTSTRAP_DEVICE_PRIVATE_KEY);

#else
      // PEM format
      MQTTThreadedClient mqtt(network, (const unsigned char*)TLS_CA_PEM, (const unsigned char*)TLS_CLIENT_CERT, (const unsigned char*)TLS_CLIENT_PKEY, isDER);
#endif

    MQTTPacket_connectData logindata = MQTTPacket_connectData_initializer;
    logindata.MQTTVersion = 3;


    logindata.clientID.cstring = (char *)  clientID;

    mqtt.setConnectionParameters(hostname, port, logindata);
    mqtt.addTopicHandler(topic_1, messageArrived);

    msgSender.start(mbed::callback(&mqtt, &MQTTThreadedClient::startListener));


    int i=0;
    while(true)
    {
         Thread::wait(1000);
         PubMessage message;
         message.qos = QOS0;
         message.id = 123;

         // if (i > 3) continue;  // This is temporary statement to concentrate on TLS handshake issue

         strcpy(&message.topic[0], topic_1);


         string json=getData(i);  //temporary commented to concentrate on TLS handshake issue
         // string json=getDataOld(i); //old JSON format
         //string json="X";  // just a placeholder

         if  (json.length() >= MAX_MQTT_PAYLOAD_SIZE){
            printf("ERROR json lengh > %d  \r\n", MAX_MQTT_PAYLOAD_SIZE);
            break;
         }

         sprintf(&message.payload[0], "%s", json.c_str());
         epochtime++; // TODO  use system time call here

         message.payloadlen = strlen((const char *) &message.payload[0]);
         printf("i=%d  topic=%s payload=%s \r\n", i,  &message.topic[0],   &message.payload[0] );
         int ret = mqtt.publish(message);
         if (ret) printf("ERROR mqtt.publish() ret=%d  ", ret);
         if (ret) Thread::wait(6000);

         i++;
     }

}
