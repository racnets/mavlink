// MESSAGE HUCH_WARPING PACKING

#define MAVLINK_MSG_ID_HUCH_WARPING 118

typedef struct __mavlink_huch_warping_t 
{
	float alpha; ///< warping movement direction
	float psi; ///< warping compass
	float rho; ///< warping relative distance
	int32_t distance; ///< minimal image distance
	float psi_estimate; ///< compass estimate
	float beta; ///< home direction

} mavlink_huch_warping_t;



/**
 * @brief Pack a huch_warping message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param alpha warping movement direction
 * @param psi warping compass
 * @param rho warping relative distance
 * @param distance minimal image distance
 * @param psi_estimate compass estimate
 * @param beta home direction
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_warping_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, float alpha, float psi, float rho, int32_t distance, float psi_estimate, float beta)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_WARPING;

	i += put_float_by_index(alpha, i, msg->payload); // warping movement direction
	i += put_float_by_index(psi, i, msg->payload); // warping compass
	i += put_float_by_index(rho, i, msg->payload); // warping relative distance
	i += put_int32_t_by_index(distance, i, msg->payload); // minimal image distance
	i += put_float_by_index(psi_estimate, i, msg->payload); // compass estimate
	i += put_float_by_index(beta, i, msg->payload); // home direction

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

/**
 * @brief Pack a huch_warping message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param alpha warping movement direction
 * @param psi warping compass
 * @param rho warping relative distance
 * @param distance minimal image distance
 * @param psi_estimate compass estimate
 * @param beta home direction
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_warping_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, float alpha, float psi, float rho, int32_t distance, float psi_estimate, float beta)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_WARPING;

	i += put_float_by_index(alpha, i, msg->payload); // warping movement direction
	i += put_float_by_index(psi, i, msg->payload); // warping compass
	i += put_float_by_index(rho, i, msg->payload); // warping relative distance
	i += put_int32_t_by_index(distance, i, msg->payload); // minimal image distance
	i += put_float_by_index(psi_estimate, i, msg->payload); // compass estimate
	i += put_float_by_index(beta, i, msg->payload); // home direction

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, i);
}

/**
 * @brief Encode a huch_warping struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param huch_warping C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_huch_warping_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_warping_t* huch_warping)
{
	return mavlink_msg_huch_warping_pack(system_id, component_id, msg, huch_warping->alpha, huch_warping->psi, huch_warping->rho, huch_warping->distance, huch_warping->psi_estimate, huch_warping->beta);
}

/**
 * @brief Send a huch_warping message
 * @param chan MAVLink channel to send the message
 *
 * @param alpha warping movement direction
 * @param psi warping compass
 * @param rho warping relative distance
 * @param distance minimal image distance
 * @param psi_estimate compass estimate
 * @param beta home direction
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_warping_send(mavlink_channel_t chan, float alpha, float psi, float rho, int32_t distance, float psi_estimate, float beta)
{
	mavlink_message_t msg;
	mavlink_msg_huch_warping_pack_chan(mavlink_system.sysid, mavlink_system.compid, chan, &msg, alpha, psi, rho, distance, psi_estimate, beta);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE HUCH_WARPING UNPACKING

/**
 * @brief Get field alpha from huch_warping message
 *
 * @return warping movement direction
 */
static inline float mavlink_msg_huch_warping_get_alpha(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload)[0];
	r.b[2] = (msg->payload)[1];
	r.b[1] = (msg->payload)[2];
	r.b[0] = (msg->payload)[3];
	return (float)r.f;
}

/**
 * @brief Get field psi from huch_warping message
 *
 * @return warping compass
 */
static inline float mavlink_msg_huch_warping_get_psi(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field rho from huch_warping message
 *
 * @return warping relative distance
 */
static inline float mavlink_msg_huch_warping_get_rho(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field distance from huch_warping message
 *
 * @return minimal image distance
 */
static inline int32_t mavlink_msg_huch_warping_get_distance(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float))[3];
	return (int32_t)r.i;
}

/**
 * @brief Get field psi_estimate from huch_warping message
 *
 * @return compass estimate
 */
static inline float mavlink_msg_huch_warping_get_psi_estimate(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(int32_t))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(int32_t))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(int32_t))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(int32_t))[3];
	return (float)r.f;
}

/**
 * @brief Get field beta from huch_warping message
 *
 * @return home direction
 */
static inline float mavlink_msg_huch_warping_get_beta(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(int32_t)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(int32_t)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(int32_t)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(int32_t)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Decode a huch_warping message into a struct
 *
 * @param msg The message to decode
 * @param huch_warping C-struct to decode the message contents into
 */
static inline void mavlink_msg_huch_warping_decode(const mavlink_message_t* msg, mavlink_huch_warping_t* huch_warping)
{
	huch_warping->alpha = mavlink_msg_huch_warping_get_alpha(msg);
	huch_warping->psi = mavlink_msg_huch_warping_get_psi(msg);
	huch_warping->rho = mavlink_msg_huch_warping_get_rho(msg);
	huch_warping->distance = mavlink_msg_huch_warping_get_distance(msg);
	huch_warping->psi_estimate = mavlink_msg_huch_warping_get_psi_estimate(msg);
	huch_warping->beta = mavlink_msg_huch_warping_get_beta(msg);
}
