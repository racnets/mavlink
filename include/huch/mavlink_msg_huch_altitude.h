// MESSAGE HUCH_ALTITUDE PACKING

#define MAVLINK_MSG_ID_HUCH_ALTITUDE 110

typedef struct __mavlink_huch_altitude_t 
{
	uint64_t usec; ///< timestamp in microseconds
	float altitude; ///< absolute altitude in meter

} mavlink_huch_altitude_t;



/**
 * @brief Send a huch_altitude message
 *
 * @param usec timestamp in microseconds
 * @param altitude absolute altitude in meter
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_altitude_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint64_t usec, float altitude)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_ALTITUDE;

	i += put_uint64_t_by_index(usec, i, msg->payload); //timestamp in microseconds
	i += put_float_by_index(altitude, i, msg->payload); //absolute altitude in meter

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_huch_altitude_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_altitude_t* huch_altitude)
{
	return mavlink_msg_huch_altitude_pack(system_id, component_id, msg, huch_altitude->usec, huch_altitude->altitude);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_altitude_send(mavlink_channel_t chan, uint64_t usec, float altitude)
{
	mavlink_message_t msg;
	mavlink_msg_huch_altitude_pack(mavlink_system.sysid, mavlink_system.compid, &msg, usec, altitude);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE HUCH_ALTITUDE UNPACKING

/**
 * @brief Get field usec from huch_altitude message
 *
 * @return timestamp in microseconds
 */
static inline uint64_t mavlink_msg_huch_altitude_get_usec(const mavlink_message_t* msg)
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
 * @brief Get field altitude from huch_altitude message
 *
 * @return absolute altitude in meter
 */
static inline float mavlink_msg_huch_altitude_get_altitude(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint64_t))[0];
	r.b[2] = (msg->payload+sizeof(uint64_t))[1];
	r.b[1] = (msg->payload+sizeof(uint64_t))[2];
	r.b[0] = (msg->payload+sizeof(uint64_t))[3];
	return (float)r.f;
}

static inline void mavlink_msg_huch_altitude_decode(const mavlink_message_t* msg, mavlink_huch_altitude_t* huch_altitude)
{
	huch_altitude->usec = mavlink_msg_huch_altitude_get_usec(msg);
	huch_altitude->altitude = mavlink_msg_huch_altitude_get_altitude(msg);
}
