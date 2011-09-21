// MESSAGE HUCH_SIM_CTRL PACKING

#define MAVLINK_MSG_ID_HUCH_SIM_CTRL 122

typedef struct __mavlink_huch_sim_ctrl_t 
{
	uint64_t usec; ///< timestamp in microseconds
	int16_t cmd; ///< command
	float arg; ///< command argument

} mavlink_huch_sim_ctrl_t;



/**
 * @brief Pack a huch_sim_ctrl message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usec timestamp in microseconds
 * @param cmd command
 * @param arg command argument
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_sim_ctrl_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint64_t usec, int16_t cmd, float arg)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_SIM_CTRL;

	i += put_uint64_t_by_index(usec, i, msg->payload); // timestamp in microseconds
	i += put_int16_t_by_index(cmd, i, msg->payload); // command
	i += put_float_by_index(arg, i, msg->payload); // command argument

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

/**
 * @brief Pack a huch_sim_ctrl message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec timestamp in microseconds
 * @param cmd command
 * @param arg command argument
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_sim_ctrl_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, uint64_t usec, int16_t cmd, float arg)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_SIM_CTRL;

	i += put_uint64_t_by_index(usec, i, msg->payload); // timestamp in microseconds
	i += put_int16_t_by_index(cmd, i, msg->payload); // command
	i += put_float_by_index(arg, i, msg->payload); // command argument

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, i);
}

/**
 * @brief Encode a huch_sim_ctrl struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param huch_sim_ctrl C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_huch_sim_ctrl_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_sim_ctrl_t* huch_sim_ctrl)
{
	return mavlink_msg_huch_sim_ctrl_pack(system_id, component_id, msg, huch_sim_ctrl->usec, huch_sim_ctrl->cmd, huch_sim_ctrl->arg);
}

/**
 * @brief Send a huch_sim_ctrl message
 * @param chan MAVLink channel to send the message
 *
 * @param usec timestamp in microseconds
 * @param cmd command
 * @param arg command argument
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_sim_ctrl_send(mavlink_channel_t chan, uint64_t usec, int16_t cmd, float arg)
{
	mavlink_message_t msg;
	mavlink_msg_huch_sim_ctrl_pack_chan(mavlink_system.sysid, mavlink_system.compid, chan, &msg, usec, cmd, arg);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE HUCH_SIM_CTRL UNPACKING

/**
 * @brief Get field usec from huch_sim_ctrl message
 *
 * @return timestamp in microseconds
 */
static inline uint64_t mavlink_msg_huch_sim_ctrl_get_usec(const mavlink_message_t* msg)
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
 * @brief Get field cmd from huch_sim_ctrl message
 *
 * @return command
 */
static inline int16_t mavlink_msg_huch_sim_ctrl_get_cmd(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint64_t))[0];
	r.b[0] = (msg->payload+sizeof(uint64_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field arg from huch_sim_ctrl message
 *
 * @return command argument
 */
static inline float mavlink_msg_huch_sim_ctrl_get_arg(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint64_t)+sizeof(int16_t))[0];
	r.b[2] = (msg->payload+sizeof(uint64_t)+sizeof(int16_t))[1];
	r.b[1] = (msg->payload+sizeof(uint64_t)+sizeof(int16_t))[2];
	r.b[0] = (msg->payload+sizeof(uint64_t)+sizeof(int16_t))[3];
	return (float)r.f;
}

/**
 * @brief Decode a huch_sim_ctrl message into a struct
 *
 * @param msg The message to decode
 * @param huch_sim_ctrl C-struct to decode the message contents into
 */
static inline void mavlink_msg_huch_sim_ctrl_decode(const mavlink_message_t* msg, mavlink_huch_sim_ctrl_t* huch_sim_ctrl)
{
	huch_sim_ctrl->usec = mavlink_msg_huch_sim_ctrl_get_usec(msg);
	huch_sim_ctrl->cmd = mavlink_msg_huch_sim_ctrl_get_cmd(msg);
	huch_sim_ctrl->arg = mavlink_msg_huch_sim_ctrl_get_arg(msg);
}
