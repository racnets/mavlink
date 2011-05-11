// MESSAGE HUCH_HC_RAW PACKING

#define MAVLINK_MSG_ID_HUCH_HC_RAW 120

typedef struct __mavlink_huch_hc_raw_t 
{
	uint64_t usec; ///< timestamp in microseconds
	int32_t raw0; ///< raw altitude readings for logging and playback to controller
	int32_t raw1; ///< raw altitude readings for logging and playback to controller
	int32_t raw2; ///< raw altitude readings for logging and playback to controller
	int32_t raw3; ///< raw altitude readings for logging and playback to controller
	int32_t raw4; ///< raw altitude readings for logging and playback to controller

} mavlink_huch_hc_raw_t;



/**
 * @brief Pack a huch_hc_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usec timestamp in microseconds
 * @param raw0 raw altitude readings for logging and playback to controller
 * @param raw1 raw altitude readings for logging and playback to controller
 * @param raw2 raw altitude readings for logging and playback to controller
 * @param raw3 raw altitude readings for logging and playback to controller
 * @param raw4 raw altitude readings for logging and playback to controller
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_hc_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint64_t usec, int32_t raw0, int32_t raw1, int32_t raw2, int32_t raw3, int32_t raw4)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_HC_RAW;

	i += put_uint64_t_by_index(usec, i, msg->payload); // timestamp in microseconds
	i += put_int32_t_by_index(raw0, i, msg->payload); // raw altitude readings for logging and playback to controller
	i += put_int32_t_by_index(raw1, i, msg->payload); // raw altitude readings for logging and playback to controller
	i += put_int32_t_by_index(raw2, i, msg->payload); // raw altitude readings for logging and playback to controller
	i += put_int32_t_by_index(raw3, i, msg->payload); // raw altitude readings for logging and playback to controller
	i += put_int32_t_by_index(raw4, i, msg->payload); // raw altitude readings for logging and playback to controller

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

/**
 * @brief Pack a huch_hc_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec timestamp in microseconds
 * @param raw0 raw altitude readings for logging and playback to controller
 * @param raw1 raw altitude readings for logging and playback to controller
 * @param raw2 raw altitude readings for logging and playback to controller
 * @param raw3 raw altitude readings for logging and playback to controller
 * @param raw4 raw altitude readings for logging and playback to controller
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_hc_raw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, uint64_t usec, int32_t raw0, int32_t raw1, int32_t raw2, int32_t raw3, int32_t raw4)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_HC_RAW;

	i += put_uint64_t_by_index(usec, i, msg->payload); // timestamp in microseconds
	i += put_int32_t_by_index(raw0, i, msg->payload); // raw altitude readings for logging and playback to controller
	i += put_int32_t_by_index(raw1, i, msg->payload); // raw altitude readings for logging and playback to controller
	i += put_int32_t_by_index(raw2, i, msg->payload); // raw altitude readings for logging and playback to controller
	i += put_int32_t_by_index(raw3, i, msg->payload); // raw altitude readings for logging and playback to controller
	i += put_int32_t_by_index(raw4, i, msg->payload); // raw altitude readings for logging and playback to controller

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, i);
}

/**
 * @brief Encode a huch_hc_raw struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param huch_hc_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_huch_hc_raw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_hc_raw_t* huch_hc_raw)
{
	return mavlink_msg_huch_hc_raw_pack(system_id, component_id, msg, huch_hc_raw->usec, huch_hc_raw->raw0, huch_hc_raw->raw1, huch_hc_raw->raw2, huch_hc_raw->raw3, huch_hc_raw->raw4);
}

/**
 * @brief Send a huch_hc_raw message
 * @param chan MAVLink channel to send the message
 *
 * @param usec timestamp in microseconds
 * @param raw0 raw altitude readings for logging and playback to controller
 * @param raw1 raw altitude readings for logging and playback to controller
 * @param raw2 raw altitude readings for logging and playback to controller
 * @param raw3 raw altitude readings for logging and playback to controller
 * @param raw4 raw altitude readings for logging and playback to controller
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_hc_raw_send(mavlink_channel_t chan, uint64_t usec, int32_t raw0, int32_t raw1, int32_t raw2, int32_t raw3, int32_t raw4)
{
	mavlink_message_t msg;
	mavlink_msg_huch_hc_raw_pack_chan(mavlink_system.sysid, mavlink_system.compid, chan, &msg, usec, raw0, raw1, raw2, raw3, raw4);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE HUCH_HC_RAW UNPACKING

/**
 * @brief Get field usec from huch_hc_raw message
 *
 * @return timestamp in microseconds
 */
static inline uint64_t mavlink_msg_huch_hc_raw_get_usec(const mavlink_message_t* msg)
{
	generic_64bit r;
	r.b[7] = (msg->payload)[0];
	r.b[6] = (msg->payload)[1];
	r.b[5] = (msg->payload)[2];
	r.b[4] = (msg->payload)[3];
	r.b[3] = (msg->payload)[4];
	r.b[2] = (msg->payload)[5];
	r.b[1] = (msg->payload)[6];
	r.b[0] = (msg->payload)[7];
	return (uint64_t)r.ll;
}

/**
 * @brief Get field raw0 from huch_hc_raw message
 *
 * @return raw altitude readings for logging and playback to controller
 */
static inline int32_t mavlink_msg_huch_hc_raw_get_raw0(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint64_t))[0];
	r.b[2] = (msg->payload+sizeof(uint64_t))[1];
	r.b[1] = (msg->payload+sizeof(uint64_t))[2];
	r.b[0] = (msg->payload+sizeof(uint64_t))[3];
	return (int32_t)r.i;
}

/**
 * @brief Get field raw1 from huch_hc_raw message
 *
 * @return raw altitude readings for logging and playback to controller
 */
static inline int32_t mavlink_msg_huch_hc_raw_get_raw1(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint64_t)+sizeof(int32_t))[0];
	r.b[2] = (msg->payload+sizeof(uint64_t)+sizeof(int32_t))[1];
	r.b[1] = (msg->payload+sizeof(uint64_t)+sizeof(int32_t))[2];
	r.b[0] = (msg->payload+sizeof(uint64_t)+sizeof(int32_t))[3];
	return (int32_t)r.i;
}

/**
 * @brief Get field raw2 from huch_hc_raw message
 *
 * @return raw altitude readings for logging and playback to controller
 */
static inline int32_t mavlink_msg_huch_hc_raw_get_raw2(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint64_t)+sizeof(int32_t)+sizeof(int32_t))[0];
	r.b[2] = (msg->payload+sizeof(uint64_t)+sizeof(int32_t)+sizeof(int32_t))[1];
	r.b[1] = (msg->payload+sizeof(uint64_t)+sizeof(int32_t)+sizeof(int32_t))[2];
	r.b[0] = (msg->payload+sizeof(uint64_t)+sizeof(int32_t)+sizeof(int32_t))[3];
	return (int32_t)r.i;
}

/**
 * @brief Get field raw3 from huch_hc_raw message
 *
 * @return raw altitude readings for logging and playback to controller
 */
static inline int32_t mavlink_msg_huch_hc_raw_get_raw3(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint64_t)+sizeof(int32_t)+sizeof(int32_t)+sizeof(int32_t))[0];
	r.b[2] = (msg->payload+sizeof(uint64_t)+sizeof(int32_t)+sizeof(int32_t)+sizeof(int32_t))[1];
	r.b[1] = (msg->payload+sizeof(uint64_t)+sizeof(int32_t)+sizeof(int32_t)+sizeof(int32_t))[2];
	r.b[0] = (msg->payload+sizeof(uint64_t)+sizeof(int32_t)+sizeof(int32_t)+sizeof(int32_t))[3];
	return (int32_t)r.i;
}

/**
 * @brief Get field raw4 from huch_hc_raw message
 *
 * @return raw altitude readings for logging and playback to controller
 */
static inline int32_t mavlink_msg_huch_hc_raw_get_raw4(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint64_t)+sizeof(int32_t)+sizeof(int32_t)+sizeof(int32_t)+sizeof(int32_t))[0];
	r.b[2] = (msg->payload+sizeof(uint64_t)+sizeof(int32_t)+sizeof(int32_t)+sizeof(int32_t)+sizeof(int32_t))[1];
	r.b[1] = (msg->payload+sizeof(uint64_t)+sizeof(int32_t)+sizeof(int32_t)+sizeof(int32_t)+sizeof(int32_t))[2];
	r.b[0] = (msg->payload+sizeof(uint64_t)+sizeof(int32_t)+sizeof(int32_t)+sizeof(int32_t)+sizeof(int32_t))[3];
	return (int32_t)r.i;
}

/**
 * @brief Decode a huch_hc_raw message into a struct
 *
 * @param msg The message to decode
 * @param huch_hc_raw C-struct to decode the message contents into
 */
static inline void mavlink_msg_huch_hc_raw_decode(const mavlink_message_t* msg, mavlink_huch_hc_raw_t* huch_hc_raw)
{
	huch_hc_raw->usec = mavlink_msg_huch_hc_raw_get_usec(msg);
	huch_hc_raw->raw0 = mavlink_msg_huch_hc_raw_get_raw0(msg);
	huch_hc_raw->raw1 = mavlink_msg_huch_hc_raw_get_raw1(msg);
	huch_hc_raw->raw2 = mavlink_msg_huch_hc_raw_get_raw2(msg);
	huch_hc_raw->raw3 = mavlink_msg_huch_hc_raw_get_raw3(msg);
	huch_hc_raw->raw4 = mavlink_msg_huch_hc_raw_get_raw4(msg);
}
