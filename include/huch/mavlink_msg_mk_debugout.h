// MESSAGE MK_DEBUGOUT PACKING

#define MAVLINK_MSG_ID_MK_DEBUGOUT 100

typedef struct __mavlink_mk_debugout_t 
{
	int8_t debugout[66]; ///< 66 bytes of Debugout data. See qk_datatypes.h

} mavlink_mk_debugout_t;

#define MAVLINK_MSG_MK_DEBUGOUT_FIELD_DEBUGOUT_LEN 66


/**
 * @brief Send a mk_debugout message
 *
 * @param debugout 66 bytes of Debugout data. See qk_datatypes.h
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mk_debugout_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const int8_t* debugout)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_MK_DEBUGOUT;

	i += put_array_by_index(debugout, 66, i, msg->payload); //66 bytes of Debugout data. See qk_datatypes.h

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_mk_debugout_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const int8_t* debugout)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_MK_DEBUGOUT;

	i += put_array_by_index(debugout, 66, i, msg->payload); //66 bytes of Debugout data. See qk_datatypes.h

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, i);
}

static inline uint16_t mavlink_msg_mk_debugout_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mk_debugout_t* mk_debugout)
{
	return mavlink_msg_mk_debugout_pack(system_id, component_id, msg, mk_debugout->debugout);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mk_debugout_send(mavlink_channel_t chan, const int8_t* debugout)
{
	mavlink_message_t msg;
	mavlink_msg_mk_debugout_pack_chan(mavlink_system.sysid, mavlink_system.compid, chan, &msg, debugout);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE MK_DEBUGOUT UNPACKING

/**
 * @brief Get field debugout from mk_debugout message
 *
 * @return 66 bytes of Debugout data. See qk_datatypes.h
 */
static inline uint16_t mavlink_msg_mk_debugout_get_debugout(const mavlink_message_t* msg, int8_t* r_data)
{

	memcpy(r_data, msg->payload, 66);
	return 66;
}

static inline void mavlink_msg_mk_debugout_decode(const mavlink_message_t* msg, mavlink_mk_debugout_t* mk_debugout)
{
	mavlink_msg_mk_debugout_get_debugout(msg, mk_debugout->debugout);
}
