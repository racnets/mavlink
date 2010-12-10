// MESSAGE HUCH_EXP_CTRL PACKING

#define MAVLINK_MSG_ID_HUCH_EXP_CTRL 102

typedef struct __mavlink_huch_exp_ctrl_t 
{
	uint8_t status; ///< 
	int8_t rx[9]; ///< 
	int8_t tx[2]; ///< 

} mavlink_huch_exp_ctrl_t;

#define MAVLINK_MSG_HUCH_EXP_CTRL_FIELD_RX_LEN 9
#define MAVLINK_MSG_HUCH_EXP_CTRL_FIELD_TX_LEN 2


/**
 * @brief Send a huch_exp_ctrl message
 *
 * @param status 
 * @param rx 
 * @param tx 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_exp_ctrl_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint8_t status, const int8_t* rx, const int8_t* tx)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_EXP_CTRL;

	i += put_uint8_t_by_index(status, i, msg->payload); //
	i += put_array_by_index(rx, 9, i, msg->payload); //
	i += put_array_by_index(tx, 2, i, msg->payload); //

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_huch_exp_ctrl_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, uint8_t status, const int8_t* rx, const int8_t* tx)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_EXP_CTRL;

	i += put_uint8_t_by_index(status, i, msg->payload); //
	i += put_array_by_index(rx, 9, i, msg->payload); //
	i += put_array_by_index(tx, 2, i, msg->payload); //

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, i);
}

static inline uint16_t mavlink_msg_huch_exp_ctrl_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_exp_ctrl_t* huch_exp_ctrl)
{
	return mavlink_msg_huch_exp_ctrl_pack(system_id, component_id, msg, huch_exp_ctrl->status, huch_exp_ctrl->rx, huch_exp_ctrl->tx);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_exp_ctrl_send(mavlink_channel_t chan, uint8_t status, const int8_t* rx, const int8_t* tx)
{
	mavlink_message_t msg;
	mavlink_msg_huch_exp_ctrl_pack_chan(mavlink_system.sysid, mavlink_system.compid, chan, &msg, status, rx, tx);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE HUCH_EXP_CTRL UNPACKING

/**
 * @brief Get field status from huch_exp_ctrl message
 *
 * @return 
 */
static inline uint8_t mavlink_msg_huch_exp_ctrl_get_status(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload)[0];
}

/**
 * @brief Get field rx from huch_exp_ctrl message
 *
 * @return 
 */
static inline uint16_t mavlink_msg_huch_exp_ctrl_get_rx(const mavlink_message_t* msg, int8_t* r_data)
{

	memcpy(r_data, msg->payload+sizeof(uint8_t), 9);
	return 9;
}

/**
 * @brief Get field tx from huch_exp_ctrl message
 *
 * @return 
 */
static inline uint16_t mavlink_msg_huch_exp_ctrl_get_tx(const mavlink_message_t* msg, int8_t* r_data)
{

	memcpy(r_data, msg->payload+sizeof(uint8_t)+9, 2);
	return 2;
}

static inline void mavlink_msg_huch_exp_ctrl_decode(const mavlink_message_t* msg, mavlink_huch_exp_ctrl_t* huch_exp_ctrl)
{
	huch_exp_ctrl->status = mavlink_msg_huch_exp_ctrl_get_status(msg);
	mavlink_msg_huch_exp_ctrl_get_rx(msg, huch_exp_ctrl->rx);
	mavlink_msg_huch_exp_ctrl_get_tx(msg, huch_exp_ctrl->tx);
}
