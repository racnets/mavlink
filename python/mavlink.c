#include <stdio.h>
#include <string.h>
#include "../include/huch/mavlink.h"
#include "mavlink-local.h"

void mavlink_message_from_data(mavlink_message_t* msg, char* data, int len) {
	mavlink_huch_attitude_t attitude;
	mavlink_status_t status;
	int i;
	printf("x: size mavlink_message_t: %d\n", sizeof(mavlink_message_t));
	printf("x: %d, %d\n", strlen(data), len);
	// memcpy(msg, (uint8_t*)data+1, len); // +1?

	for( i=0; i<len; i++) {
		if( mavlink_parse_char(0, data[i], msg, &status)) {
			printf("mavlink.c: mavlink parse msg complete\n");
		}	
	}

	printf("x: msg: len: %d, seq: %d, sysid: %d, compid: %d, msgid: %d, payload: %s, ck_a: %d, ck_b %d\n",
				 msg->len, msg->seq, msg->sysid, msg->compid, msg->msgid, msg->payload, msg->ck_a, msg->ck_b);
	mavlink_msg_huch_attitude_decode(msg, &attitude);
	// attitude = (mavlink_huch_attitude_t*)msg->payload;
	printf("x: '%s'\n", msg->payload);
	printf("x: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
				 attitude.xacc, attitude.yacc, attitude.zacc, attitude.zaccraw,
				 attitude.xaccmean, attitude.yaccmean, attitude.zaccmean,
				 attitude.xgyro, attitude.ygyro, attitude.zgyro,
				 attitude.xgyroint, attitude.ygyroint, attitude.zgyroint,
				 attitude.xmag, attitude.ymag, attitude.zmag
				 );
	// printf("x: %d\n", mavlink_msg_huch_attitude_get_xacc(msg));
	return; // &msg;
}
