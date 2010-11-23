// MESSAGE HUCH_HMC5843 PACKING

#define MAVLINK_MSG_ID_HUCH_HMC5843 108

typedef struct __mavlink_huch_hmc5843_t 
{
	float data_x; ///< magnetic field x-direction in Gs
	float data_y; ///< magnetic field y-direction in Gs
	float data_z; ///< magnetic field z-direction in Gs
	uint32_t timestamp; ///< time in us

} mavlink_huch_hmc5843_t;



/**
 * @brief Send a huch_hmc5843 message
 *
 * @param data_x magnetic field x-direction in Gs
 * @param data_y magnetic field y-direction in Gs
 * @param data_z magnetic field z-direction in Gs
 * @param timestamp time in us
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_hmc5843_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, float data_x, float data_y, float data_z, uint32_t timestamp)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_HMC5843;

	i += put_float_by_index(data_x, i, msg->payload); //magnetic field x-direction in Gs
	i += put_float_by_index(data_y, i, msg->payload); //magnetic field y-direction in Gs
	i += put_float_by_index(data_z, i, msg->payload); //magnetic field z-direction in Gs
	i += put_uint32_t_by_index(timestamp, i, msg->payload); //time in us

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_huch_hmc5843_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_hmc5843_t* huch_hmc5843)
{
	return mavlink_msg_huch_hmc5843_pack(system_id, component_id, msg, huch_hmc5843->data_x, huch_hmc5843->data_y, huch_hmc5843->data_z, huch_hmc5843->timestamp);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_hmc5843_send(mavlink_channel_t chan, float data_x, float data_y, float data_z, uint32_t timestamp)
{
	mavlink_message_t msg;
	mavlink_msg_huch_hmc5843_pack(mavlink_system.sysid, mavlink_system.compid, &msg, data_x, data_y, data_z, timestamp);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE HUCH_HMC5843 UNPACKING

/**
 * @brief Get field data_x from huch_hmc5843 message
 *
 * @return magnetic field x-direction in Gs
 */
static inline float mavlink_msg_huch_hmc5843_get_data_x(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload)[0];
	r.b[2] = (msg->payload)[1];
	r.b[1] = (msg->payload)[2];
	r.b[0] = (msg->payload)[3];
	return (float)r.f;
}

/**
 * @brief Get field data_y from huch_hmc5843 message
 *
 * @return magnetic field y-direction in Gs
 */
static inline float mavlink_msg_huch_hmc5843_get_data_y(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field data_z from huch_hmc5843 message
 *
 * @return magnetic field z-direction in Gs
 */
static inline float mavlink_msg_huch_hmc5843_get_data_z(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field timestamp from huch_hmc5843 message
 *
 * @return time in us
 */
static inline uint32_t mavlink_msg_huch_hmc5843_get_timestamp(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float))[3];
	return (uint32_t)r.i;
}

static inline void mavlink_msg_huch_hmc5843_decode(const mavlink_message_t* msg, mavlink_huch_hmc5843_t* huch_hmc5843)
{
	huch_hmc5843->data_x = mavlink_msg_huch_hmc5843_get_data_x(msg);
	huch_hmc5843->data_y = mavlink_msg_huch_hmc5843_get_data_y(msg);
	huch_hmc5843->data_z = mavlink_msg_huch_hmc5843_get_data_z(msg);
	huch_hmc5843->timestamp = mavlink_msg_huch_hmc5843_get_timestamp(msg);
}
