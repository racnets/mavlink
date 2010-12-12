// MESSAGE HUCH_FC_ALTITUDE PACKING

#define MAVLINK_MSG_ID_HUCH_FC_ALTITUDE 104

typedef struct __mavlink_huch_fc_altitude_t 
{
	int16_t baro; ///< 
	int16_t baroref; ///< 

} mavlink_huch_fc_altitude_t;



/**
 * @brief Send a huch_fc_altitude message
 *
 * @param baro 
 * @param baroref 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_fc_altitude_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, int16_t baro, int16_t baroref)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_FC_ALTITUDE;

	i += put_int16_t_by_index(baro, i, msg->payload); //
	i += put_int16_t_by_index(baroref, i, msg->payload); //

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_huch_fc_altitude_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_fc_altitude_t* huch_fc_altitude)
{
	return mavlink_msg_huch_fc_altitude_pack(system_id, component_id, msg, huch_fc_altitude->baro, huch_fc_altitude->baroref);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_fc_altitude_send(mavlink_channel_t chan, int16_t baro, int16_t baroref)
{
	mavlink_message_t msg;
	mavlink_msg_huch_fc_altitude_pack(mavlink_system.sysid, mavlink_system.compid, &msg, baro, baroref);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE HUCH_FC_ALTITUDE UNPACKING

/**
 * @brief Get field baro from huch_fc_altitude message
 *
 * @return 
 */
static inline int16_t mavlink_msg_huch_fc_altitude_get_baro(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload)[0];
	r.b[0] = (msg->payload)[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field baroref from huch_fc_altitude message
 *
 * @return 
 */
static inline int16_t mavlink_msg_huch_fc_altitude_get_baroref(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

static inline void mavlink_msg_huch_fc_altitude_decode(const mavlink_message_t* msg, mavlink_huch_fc_altitude_t* huch_fc_altitude)
{
	huch_fc_altitude->baro = mavlink_msg_huch_fc_altitude_get_baro(msg);
	huch_fc_altitude->baroref = mavlink_msg_huch_fc_altitude_get_baroref(msg);
}
