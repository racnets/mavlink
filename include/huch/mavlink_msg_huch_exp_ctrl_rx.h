// MESSAGE HUCH_EXP_CTRL_RX PACKING

#define MAVLINK_MSG_ID_HUCH_EXP_CTRL_RX 107

typedef struct __mavlink_huch_exp_ctrl_rx_t 
{
	uint8_t version; ///< 
	uint16_t value0; ///< 
	uint16_t value1; ///< 
	uint16_t value2; ///< 
	uint16_t value3; ///< 

} mavlink_huch_exp_ctrl_rx_t;



/**
 * @brief Send a huch_exp_ctrl_rx message
 *
 * @param version 
 * @param value0 
 * @param value1 
 * @param value2 
 * @param value3 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_exp_ctrl_rx_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint8_t version, uint16_t value0, uint16_t value1, uint16_t value2, uint16_t value3)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_EXP_CTRL_RX;

	i += put_uint8_t_by_index(version, i, msg->payload); //
	i += put_uint16_t_by_index(value0, i, msg->payload); //
	i += put_uint16_t_by_index(value1, i, msg->payload); //
	i += put_uint16_t_by_index(value2, i, msg->payload); //
	i += put_uint16_t_by_index(value3, i, msg->payload); //

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_huch_exp_ctrl_rx_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, uint8_t version, uint16_t value0, uint16_t value1, uint16_t value2, uint16_t value3)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_EXP_CTRL_RX;

	i += put_uint8_t_by_index(version, i, msg->payload); //
	i += put_uint16_t_by_index(value0, i, msg->payload); //
	i += put_uint16_t_by_index(value1, i, msg->payload); //
	i += put_uint16_t_by_index(value2, i, msg->payload); //
	i += put_uint16_t_by_index(value3, i, msg->payload); //

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, i);
}

static inline uint16_t mavlink_msg_huch_exp_ctrl_rx_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_exp_ctrl_rx_t* huch_exp_ctrl_rx)
{
	return mavlink_msg_huch_exp_ctrl_rx_pack(system_id, component_id, msg, huch_exp_ctrl_rx->version, huch_exp_ctrl_rx->value0, huch_exp_ctrl_rx->value1, huch_exp_ctrl_rx->value2, huch_exp_ctrl_rx->value3);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_exp_ctrl_rx_send(mavlink_channel_t chan, uint8_t version, uint16_t value0, uint16_t value1, uint16_t value2, uint16_t value3)
{
	mavlink_message_t msg;
	mavlink_msg_huch_exp_ctrl_rx_pack_chan(mavlink_system.sysid, mavlink_system.compid, chan, &msg, version, value0, value1, value2, value3);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE HUCH_EXP_CTRL_RX UNPACKING

/**
 * @brief Get field version from huch_exp_ctrl_rx message
 *
 * @return 
 */
static inline uint8_t mavlink_msg_huch_exp_ctrl_rx_get_version(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload)[0];
}

/**
 * @brief Get field value0 from huch_exp_ctrl_rx message
 *
 * @return 
 */
static inline uint16_t mavlink_msg_huch_exp_ctrl_rx_get_value0(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint8_t))[0];
	r.b[0] = (msg->payload+sizeof(uint8_t))[1];
	return (uint16_t)r.s;
}

/**
 * @brief Get field value1 from huch_exp_ctrl_rx message
 *
 * @return 
 */
static inline uint16_t mavlink_msg_huch_exp_ctrl_rx_get_value1(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint8_t)+sizeof(uint16_t))[0];
	r.b[0] = (msg->payload+sizeof(uint8_t)+sizeof(uint16_t))[1];
	return (uint16_t)r.s;
}

/**
 * @brief Get field value2 from huch_exp_ctrl_rx message
 *
 * @return 
 */
static inline uint16_t mavlink_msg_huch_exp_ctrl_rx_get_value2(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint16_t))[0];
	r.b[0] = (msg->payload+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint16_t))[1];
	return (uint16_t)r.s;
}

/**
 * @brief Get field value3 from huch_exp_ctrl_rx message
 *
 * @return 
 */
static inline uint16_t mavlink_msg_huch_exp_ctrl_rx_get_value3(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint16_t)+sizeof(uint16_t))[0];
	r.b[0] = (msg->payload+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint16_t)+sizeof(uint16_t))[1];
	return (uint16_t)r.s;
}

static inline void mavlink_msg_huch_exp_ctrl_rx_decode(const mavlink_message_t* msg, mavlink_huch_exp_ctrl_rx_t* huch_exp_ctrl_rx)
{
	huch_exp_ctrl_rx->version = mavlink_msg_huch_exp_ctrl_rx_get_version(msg);
	huch_exp_ctrl_rx->value0 = mavlink_msg_huch_exp_ctrl_rx_get_value0(msg);
	huch_exp_ctrl_rx->value1 = mavlink_msg_huch_exp_ctrl_rx_get_value1(msg);
	huch_exp_ctrl_rx->value2 = mavlink_msg_huch_exp_ctrl_rx_get_value2(msg);
	huch_exp_ctrl_rx->value3 = mavlink_msg_huch_exp_ctrl_rx_get_value3(msg);
}
