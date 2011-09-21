#include <stdio.h>
#include <string.h>
#include "../include/huch/mavlink.h"
#include "mavlink-local.h"

void mavlink_message_from_data(mavlink_message_t* msg, char* data, int len) {
	mavlink_huch_attitude_t attitude;
	mavlink_status_t status;
	int i;
	//printf("x: size mavlink_message_t: %d\n", sizeof(mavlink_message_t));
	//printf("x: %d, %d\n", strlen(data), len);
	// memcpy(msg, (uint8_t*)data+1, len); // +1?

	for( i=0; i<len; i++) {
		if( mavlink_parse_char(0, data[i], msg, &status)) {
			//printf("mavlink.c: mavlink parse msg complete\n");
		}	
	}

	/* printf("x: msg: len: %d, seq: %d, sysid: %d, compid: %d, msgid: %d, payload: %s, ck_a: %d, ck_b %d\n", */
	/* 			 msg->len, msg->seq, msg->sysid, msg->compid, msg->msgid, msg->payload, msg->ck_a, msg->ck_b); */
	mavlink_msg_huch_attitude_decode(msg, &attitude);
	// attitude = (mavlink_huch_attitude_t*)msg->payload;
	/* printf("x: '%s'\n", msg->payload); */
	/* printf("x: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", */
	/* 			 attitude.xacc, attitude.yacc, attitude.zacc, attitude.zaccraw, */
	/* 			 attitude.xaccmean, attitude.yaccmean, attitude.zaccmean, */
	/* 			 attitude.xgyro, attitude.ygyro, attitude.zgyro, */
	/* 			 attitude.xgyroint, attitude.ygyroint, attitude.zgyroint, */
	/* 			 attitude.xmag, attitude.ymag, attitude.zmag */
	/* 			 ); */
	// printf("x: %d\n", mavlink_msg_huch_attitude_get_xacc(msg));
	return; // &msg;
}

void mavlink_param_set_param_id(mavlink_param_set_t* param, char* str) {
	//printf("haha: %s\n", str);
	strncpy(param->param_id, (char *)str, 15);
}

char* mavlink_param_get_param_id(mavlink_param_set_t* param) {
	//printf("haha: %s\n", str);
	//strncpy(param->param_id, str, 15);
	return (char *)param->param_id;
}

char* mavlink_msg_to_send_buffer_2(const mavlink_message_t* msg) {
	uint8_t buffer[256];
	char tmp[5];
	char retbuf[1024];
	int i;
	
	retbuf[0] = '\0';

	*(buffer+0) = MAVLINK_STX; ///< Start transmit
	//printf("python/mavlink.c: msg->len: %d\n", msg->len);
	memcpy((buffer+1), msg, msg->len + MAVLINK_CORE_HEADER_LEN); ///< Core header plus payload
	*(buffer + msg->len + MAVLINK_CORE_HEADER_LEN + 1) = msg->ck_a;
	*(buffer + msg->len + MAVLINK_CORE_HEADER_LEN + 2) = msg->ck_b;
	//printf("python/mavlink.c: ck_a: %d, ck_b: %d\n", msg->ck_a, msg->ck_b);
	for(i=0; i< (msg->len + MAVLINK_CORE_HEADER_LEN + 3); i++) {
		//printf("python/mavlink.c: buf: %u\n", buffer[i]);
		sprintf(tmp, "%u,", buffer[i]);
		strcat(retbuf,tmp);
		//tmp[0] = '\0';
	}
	/* printf("python/mavlink.c: len: %d, retbuf: '%s'\n", */
	/* 			 msg->len + MAVLINK_CORE_HEADER_LEN + 2, */
	/* 			 retbuf); */
	return(retbuf);
	/* return msg->len + MAVLINK_NUM_NON_PAYLOAD_BYTES; */
	/* return 0; */
}
