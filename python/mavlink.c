#include <stdio.h>
#include <string.h>
#include "../include/huch/mavlink.h"
#include "mavlink-local.h"

void mavlink_message_from_data(mavlink_message_t* msg, char* data, int len) {
	// mavlink_message_t message;
	printf("x: size mavlink_msg: %d\n", sizeof(mavlink_message_t));
	printf("x: %d, %d\n", strlen(data), len);
	memcpy(msg, (uint8_t*)data, len);
	printf("x: msg: len: %d, seq: %d, sysid: %d, compid: %d, msgid: %d, payload: %s, ck_a: %d, ck_b %d\n",
				 msg->len, msg->seq, msg->sysid, msg->compid, msg->msgid, msg->payload, msg->ck_a, msg->ck_b);
	return; // &msg;
}
