// partial python wrapper for mavlink library
%module mavlink

 // this goes into _wrap.c
%{
#define SWIG_FILE_WITH_INIT
#include "../include/huch/mavlink.h"
#include "mavlink-local.h"
%}

// this is advertised to the target language

// this could be used with swig  -I/usr/include -I/usr/include/linux -includeall
// but it produces errors

// #include "../include/huch/mavlink.h"

// generic types
typedef unsigned char uint8_t;
typedef short int16_t;

// mavlink types
typedef struct __mavlink_message {
	uint8_t len;     ///< Length of payload
	uint8_t seq;     ///< Sequence of packet
	uint8_t sysid;   ///< ID of message sender system/aircraft
	uint8_t compid;  ///< ID of the message sender component
	uint8_t msgid;   ///< ID of message in payload
	uint8_t payload[MAVLINK_MAX_PAYLOAD_LEN]; ///< Payload data, ALIGNMENT IMPORTANT ON MCU
	uint8_t ck_a;    ///< Checksum high byte
	uint8_t ck_b;    ///< Checksum low byte
} mavlink_message_t;

typedef struct __mavlink_huch_attitude_t 
{
	int16_t xacc; ///< 
	int16_t yacc; ///< 
	int16_t zacc; ///< 
	int16_t zaccraw; ///< 
	int16_t xaccmean; ///< 
	int16_t yaccmean; ///< 
	int16_t zaccmean; ///< 
	int16_t xgyro; ///< 
	int16_t ygyro; ///< 
	int16_t zgyro; ///< 
	int32_t xgyroint; ///< 
	int32_t ygyroint; ///< 
	int32_t zgyroint; ///< 
	int16_t xmag; ///< 
	int16_t ymag; ///< 
	int16_t zmag; ///< 

} mavlink_huch_attitude_t;

// custom functions
// mavlink_message_t* mavlink_message_from_data(mavlink_message_t* msg, char* data, int len);
void mavlink_message_from_data(mavlink_message_t* msg, char* data, int len);

// mavlink functions
static inline void mavlink_msg_huch_attitude_decode(const mavlink_message_t* msg, mavlink_huch_attitude_t* huch_attitude);
 
