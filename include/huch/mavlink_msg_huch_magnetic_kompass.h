// MESSAGE HUCH_MAGNETIC_KOMPASS PACKING

#define MAVLINK_MSG_ID_HUCH_MAGNETIC_KOMPASS 116

typedef struct __mavlink_huch_magnetic_kompass_t 
{
	uint64_t usec; ///< timestamp in microseconds
	float data_x; ///< magnetic field x-direction in Gs
	float data_y; ///< magnetic field y-direction in Gs
	float data_z; ///< magnetic field z-direction in Gs

} mavlink_huch_magnetic_kompass_t;



/**
 * @brief Send a huch_magnetic_kompass message
 *
 * @param usec timestamp in microseconds
 * @param data_x magnetic field x-direction in Gs
 * @param data_y magnetic field y-direction in Gs
 * @param data_z magnetic field z-direction in Gs
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_magnetic_kompass_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint64_t usec, float data_x, float data_y, float data_z)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_MAGNETIC_KOMPASS;

	i += put_uint64_t_by_index(usec, i, msg->payload); //timestamp in microseconds
	i += put_float_by_index(data_x, i, msg->payload); //magnetic field x-direction in Gs
	i += put_float_by_index(data_y, i, msg->payload); //magnetic field y-direction in Gs
	i += put_float_by_index(data_z, i, msg->payload); //magnetic field z-direction in Gs

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_huch_magnetic_kompass_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, uint64_t usec, float data_x, float data_y, float data_z)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_MAGNETIC_KOMPASS;

	i += put_uint64_t_by_index(usec, i, msg->payload); //timestamp in microseconds
	i += put_float_by_index(data_x, i, msg->payload); //magnetic field x-direction in Gs
	i += put_float_by_index(data_y, i, msg->payload); //magnetic field y-direction in Gs
	i += put_float_by_index(data_z, i, msg->payload); //magnetic field z-direction in Gs

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, i);
}

static inline uint16_t mavlink_msg_huch_magnetic_kompass_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_magnetic_kompass_t* huch_magnetic_kompass)
{
	return mavlink_msg_huch_magnetic_kompass_pack(system_id, component_id, msg, huch_magnetic_kompass->usec, huch_magnetic_kompass->data_x, huch_magnetic_kompass->data_y, huch_magnetic_kompass->data_z);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_magnetic_kompass_send(mavlink_channel_t chan, uint64_t usec, float data_x, float data_y, float data_z)
{
	mavlink_message_t msg;
	mavlink_msg_huch_magnetic_kompass_pack_chan(mavlink_system.sysid, mavlink_system.compid, chan, &msg, usec, data_x, data_y, data_z);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE HUCH_MAGNETIC_KOMPASS UNPACKING

/**
 * @brief Get field usec from huch_magnetic_kompass message
 *
 * @return timestamp in microseconds
 */
static inline uint64_t mavlink_msg_huch_magnetic_kompass_get_usec(const mavlink_message_t* msg)
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
 * @brief Get field data_x from huch_magnetic_kompass message
 *
 * @return magnetic field x-direction in Gs
 */
static inline float mavlink_msg_huch_magnetic_kompass_get_data_x(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint64_t))[0];
	r.b[2] = (msg->payload+sizeof(uint64_t))[1];
	r.b[1] = (msg->payload+sizeof(uint64_t))[2];
	r.b[0] = (msg->payload+sizeof(uint64_t))[3];
	return (float)r.f;
}

/**
 * @brief Get field data_y from huch_magnetic_kompass message
 *
 * @return magnetic field y-direction in Gs
 */
static inline float mavlink_msg_huch_magnetic_kompass_get_data_y(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint64_t)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(uint64_t)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(uint64_t)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(uint64_t)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field data_z from huch_magnetic_kompass message
 *
 * @return magnetic field z-direction in Gs
 */
static inline float mavlink_msg_huch_magnetic_kompass_get_data_z(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

static inline void mavlink_msg_huch_magnetic_kompass_decode(const mavlink_message_t* msg, mavlink_huch_magnetic_kompass_t* huch_magnetic_kompass)
{
	huch_magnetic_kompass->usec = mavlink_msg_huch_magnetic_kompass_get_usec(msg);
	huch_magnetic_kompass->data_x = mavlink_msg_huch_magnetic_kompass_get_data_x(msg);
	huch_magnetic_kompass->data_y = mavlink_msg_huch_magnetic_kompass_get_data_y(msg);
	huch_magnetic_kompass->data_z = mavlink_msg_huch_magnetic_kompass_get_data_z(msg);
}
