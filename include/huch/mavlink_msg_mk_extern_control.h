// MESSAGE MK_EXTERN_CONTROL PACKING

#define MAVLINK_MSG_ID_MK_EXTERN_CONTROL 101

typedef struct __mavlink_mk_extern_control_t 
{
	uint8_t remote_buttons; ///< 
	int8_t nick; ///< 
	int8_t roll; ///< 
	int8_t yaw; ///< 
	uint16_t gas; ///< 
	uint16_t height; ///< 
	uint8_t AP_flags; ///< 
	uint8_t frame; ///< 
	uint8_t config; ///< 

} mavlink_mk_extern_control_t;



/**
 * @brief Send a mk_extern_control message
 *
 * @param remote_buttons 
 * @param nick 
 * @param roll 
 * @param yaw 
 * @param gas 
 * @param height 
 * @param AP_flags 
 * @param frame 
 * @param config 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mk_extern_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint8_t remote_buttons, int8_t nick, int8_t roll, int8_t yaw, uint16_t gas, uint16_t height, uint8_t AP_flags, uint8_t frame, uint8_t config)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_MK_EXTERN_CONTROL;

	i += put_uint8_t_by_index(remote_buttons, i, msg->payload); //
	i += put_int8_t_by_index(nick, i, msg->payload); //
	i += put_int8_t_by_index(roll, i, msg->payload); //
	i += put_int8_t_by_index(yaw, i, msg->payload); //
	i += put_uint16_t_by_index(gas, i, msg->payload); //
	i += put_uint16_t_by_index(height, i, msg->payload); //
	i += put_uint8_t_by_index(AP_flags, i, msg->payload); //
	i += put_uint8_t_by_index(frame, i, msg->payload); //
	i += put_uint8_t_by_index(config, i, msg->payload); //

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_mk_extern_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mk_extern_control_t* mk_extern_control)
{
	return mavlink_msg_mk_extern_control_pack(system_id, component_id, msg, mk_extern_control->remote_buttons, mk_extern_control->nick, mk_extern_control->roll, mk_extern_control->yaw, mk_extern_control->gas, mk_extern_control->height, mk_extern_control->AP_flags, mk_extern_control->frame, mk_extern_control->config);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mk_extern_control_send(mavlink_channel_t chan, uint8_t remote_buttons, int8_t nick, int8_t roll, int8_t yaw, uint16_t gas, uint16_t height, uint8_t AP_flags, uint8_t frame, uint8_t config)
{
	mavlink_message_t msg;
	mavlink_msg_mk_extern_control_pack(mavlink_system.sysid, mavlink_system.compid, &msg, remote_buttons, nick, roll, yaw, gas, height, AP_flags, frame, config);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE MK_EXTERN_CONTROL UNPACKING

/**
 * @brief Get field remote_buttons from mk_extern_control message
 *
 * @return 
 */
static inline uint8_t mavlink_msg_mk_extern_control_get_remote_buttons(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload)[0];
}

/**
 * @brief Get field nick from mk_extern_control message
 *
 * @return 
 */
static inline int8_t mavlink_msg_mk_extern_control_get_nick(const mavlink_message_t* msg)
{
	return (int8_t)(msg->payload+sizeof(uint8_t))[0];
}

/**
 * @brief Get field roll from mk_extern_control message
 *
 * @return 
 */
static inline int8_t mavlink_msg_mk_extern_control_get_roll(const mavlink_message_t* msg)
{
	return (int8_t)(msg->payload+sizeof(uint8_t)+sizeof(int8_t))[0];
}

/**
 * @brief Get field yaw from mk_extern_control message
 *
 * @return 
 */
static inline int8_t mavlink_msg_mk_extern_control_get_yaw(const mavlink_message_t* msg)
{
	return (int8_t)(msg->payload+sizeof(uint8_t)+sizeof(int8_t)+sizeof(int8_t))[0];
}

/**
 * @brief Get field gas from mk_extern_control message
 *
 * @return 
 */
static inline uint16_t mavlink_msg_mk_extern_control_get_gas(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint8_t)+sizeof(int8_t)+sizeof(int8_t)+sizeof(int8_t))[0];
	r.b[0] = (msg->payload+sizeof(uint8_t)+sizeof(int8_t)+sizeof(int8_t)+sizeof(int8_t))[1];
	return (uint16_t)r.s;
}

/**
 * @brief Get field height from mk_extern_control message
 *
 * @return 
 */
static inline uint16_t mavlink_msg_mk_extern_control_get_height(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint8_t)+sizeof(int8_t)+sizeof(int8_t)+sizeof(int8_t)+sizeof(uint16_t))[0];
	r.b[0] = (msg->payload+sizeof(uint8_t)+sizeof(int8_t)+sizeof(int8_t)+sizeof(int8_t)+sizeof(uint16_t))[1];
	return (uint16_t)r.s;
}

/**
 * @brief Get field AP_flags from mk_extern_control message
 *
 * @return 
 */
static inline uint8_t mavlink_msg_mk_extern_control_get_AP_flags(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload+sizeof(uint8_t)+sizeof(int8_t)+sizeof(int8_t)+sizeof(int8_t)+sizeof(uint16_t)+sizeof(uint16_t))[0];
}

/**
 * @brief Get field frame from mk_extern_control message
 *
 * @return 
 */
static inline uint8_t mavlink_msg_mk_extern_control_get_frame(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload+sizeof(uint8_t)+sizeof(int8_t)+sizeof(int8_t)+sizeof(int8_t)+sizeof(uint16_t)+sizeof(uint16_t)+sizeof(uint8_t))[0];
}

/**
 * @brief Get field config from mk_extern_control message
 *
 * @return 
 */
static inline uint8_t mavlink_msg_mk_extern_control_get_config(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload+sizeof(uint8_t)+sizeof(int8_t)+sizeof(int8_t)+sizeof(int8_t)+sizeof(uint16_t)+sizeof(uint16_t)+sizeof(uint8_t)+sizeof(uint8_t))[0];
}

static inline void mavlink_msg_mk_extern_control_decode(const mavlink_message_t* msg, mavlink_mk_extern_control_t* mk_extern_control)
{
	mk_extern_control->remote_buttons = mavlink_msg_mk_extern_control_get_remote_buttons(msg);
	mk_extern_control->nick = mavlink_msg_mk_extern_control_get_nick(msg);
	mk_extern_control->roll = mavlink_msg_mk_extern_control_get_roll(msg);
	mk_extern_control->yaw = mavlink_msg_mk_extern_control_get_yaw(msg);
	mk_extern_control->gas = mavlink_msg_mk_extern_control_get_gas(msg);
	mk_extern_control->height = mavlink_msg_mk_extern_control_get_height(msg);
	mk_extern_control->AP_flags = mavlink_msg_mk_extern_control_get_AP_flags(msg);
	mk_extern_control->frame = mavlink_msg_mk_extern_control_get_frame(msg);
	mk_extern_control->config = mavlink_msg_mk_extern_control_get_config(msg);
}
