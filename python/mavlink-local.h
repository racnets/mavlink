#ifndef _MAVLINK_LOCAL_H
#define _MAVLINK_LOCAL_H

void mavlink_message_from_data(mavlink_message_t* msg, char* data, int len);
// check param_set
// FIXME: need these to set the int8_t typed param id string
void mavlink_param_set_param_id(mavlink_param_set_t* param, char* str);
char* mavlink_param_get_param_id(mavlink_param_set_t* param);

// sending stuff
char* mavlink_msg_to_send_buffer_2(const mavlink_message_t* msg);

#endif
