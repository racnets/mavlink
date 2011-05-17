// MESSAGE HUCH_VISUAL_NAVIGATION PACKING

#define MAVLINK_MSG_ID_HUCH_VISUAL_NAVIGATION 118

typedef struct __mavlink_huch_visual_navigation_t 
{
	float alt_velocity; ///< altitude velocity
	float psi_warping; ///< warping compass estimate
	float psi_vc; ///< visual compass estimate
	float beta; ///< home direction
	int32_t distance; ///< minimal image distance 
	int16_t home; ///< home signal (0/1)
	int16_t outlier; ///< current outlier count

} mavlink_huch_visual_navigation_t;



/**
 * @brief Pack a huch_visual_navigation message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param alt_velocity altitude velocity
 * @param psi_warping warping compass estimate
 * @param psi_vc visual compass estimate
 * @param beta home direction
 * @param distance minimal image distance 
 * @param home home signal (0/1)
 * @param outlier current outlier count
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_visual_navigation_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, float alt_velocity, float psi_warping, float psi_vc, float beta, int32_t distance, int16_t home, int16_t outlier)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_VISUAL_NAVIGATION;

	i += put_float_by_index(alt_velocity, i, msg->payload); // altitude velocity
	i += put_float_by_index(psi_warping, i, msg->payload); // warping compass estimate
	i += put_float_by_index(psi_vc, i, msg->payload); // visual compass estimate
	i += put_float_by_index(beta, i, msg->payload); // home direction
	i += put_int32_t_by_index(distance, i, msg->payload); // minimal image distance 
	i += put_int16_t_by_index(home, i, msg->payload); // home signal (0/1)
	i += put_int16_t_by_index(outlier, i, msg->payload); // current outlier count

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

/**
 * @brief Pack a huch_visual_navigation message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param alt_velocity altitude velocity
 * @param psi_warping warping compass estimate
 * @param psi_vc visual compass estimate
 * @param beta home direction
 * @param distance minimal image distance 
 * @param home home signal (0/1)
 * @param outlier current outlier count
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_visual_navigation_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, float alt_velocity, float psi_warping, float psi_vc, float beta, int32_t distance, int16_t home, int16_t outlier)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_VISUAL_NAVIGATION;

	i += put_float_by_index(alt_velocity, i, msg->payload); // altitude velocity
	i += put_float_by_index(psi_warping, i, msg->payload); // warping compass estimate
	i += put_float_by_index(psi_vc, i, msg->payload); // visual compass estimate
	i += put_float_by_index(beta, i, msg->payload); // home direction
	i += put_int32_t_by_index(distance, i, msg->payload); // minimal image distance 
	i += put_int16_t_by_index(home, i, msg->payload); // home signal (0/1)
	i += put_int16_t_by_index(outlier, i, msg->payload); // current outlier count

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, i);
}

/**
 * @brief Encode a huch_visual_navigation struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param huch_visual_navigation C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_huch_visual_navigation_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_visual_navigation_t* huch_visual_navigation)
{
	return mavlink_msg_huch_visual_navigation_pack(system_id, component_id, msg, huch_visual_navigation->alt_velocity, huch_visual_navigation->psi_warping, huch_visual_navigation->psi_vc, huch_visual_navigation->beta, huch_visual_navigation->distance, huch_visual_navigation->home, huch_visual_navigation->outlier);
}

/**
 * @brief Send a huch_visual_navigation message
 * @param chan MAVLink channel to send the message
 *
 * @param alt_velocity altitude velocity
 * @param psi_warping warping compass estimate
 * @param psi_vc visual compass estimate
 * @param beta home direction
 * @param distance minimal image distance 
 * @param home home signal (0/1)
 * @param outlier current outlier count
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_visual_navigation_send(mavlink_channel_t chan, float alt_velocity, float psi_warping, float psi_vc, float beta, int32_t distance, int16_t home, int16_t outlier)
{
	mavlink_message_t msg;
	mavlink_msg_huch_visual_navigation_pack_chan(mavlink_system.sysid, mavlink_system.compid, chan, &msg, alt_velocity, psi_warping, psi_vc, beta, distance, home, outlier);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE HUCH_VISUAL_NAVIGATION UNPACKING

/**
 * @brief Get field alt_velocity from huch_visual_navigation message
 *
 * @return altitude velocity
 */
static inline float mavlink_msg_huch_visual_navigation_get_alt_velocity(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload)[0];
	r.b[2] = (msg->payload)[1];
	r.b[1] = (msg->payload)[2];
	r.b[0] = (msg->payload)[3];
	return (float)r.f;
}

/**
 * @brief Get field psi_warping from huch_visual_navigation message
 *
 * @return warping compass estimate
 */
static inline float mavlink_msg_huch_visual_navigation_get_psi_warping(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field psi_vc from huch_visual_navigation message
 *
 * @return visual compass estimate
 */
static inline float mavlink_msg_huch_visual_navigation_get_psi_vc(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field beta from huch_visual_navigation message
 *
 * @return home direction
 */
static inline float mavlink_msg_huch_visual_navigation_get_beta(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field distance from huch_visual_navigation message
 *
 * @return minimal image distance 
 */
static inline int32_t mavlink_msg_huch_visual_navigation_get_distance(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[3];
	return (int32_t)r.i;
}

/**
 * @brief Get field home from huch_visual_navigation message
 *
 * @return home signal (0/1)
 */
static inline int16_t mavlink_msg_huch_visual_navigation_get_home(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(int32_t))[0];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(int32_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field outlier from huch_visual_navigation message
 *
 * @return current outlier count
 */
static inline int16_t mavlink_msg_huch_visual_navigation_get_outlier(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(int32_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(int32_t)+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Decode a huch_visual_navigation message into a struct
 *
 * @param msg The message to decode
 * @param huch_visual_navigation C-struct to decode the message contents into
 */
static inline void mavlink_msg_huch_visual_navigation_decode(const mavlink_message_t* msg, mavlink_huch_visual_navigation_t* huch_visual_navigation)
{
	huch_visual_navigation->alt_velocity = mavlink_msg_huch_visual_navigation_get_alt_velocity(msg);
	huch_visual_navigation->psi_warping = mavlink_msg_huch_visual_navigation_get_psi_warping(msg);
	huch_visual_navigation->psi_vc = mavlink_msg_huch_visual_navigation_get_psi_vc(msg);
	huch_visual_navigation->beta = mavlink_msg_huch_visual_navigation_get_beta(msg);
	huch_visual_navigation->distance = mavlink_msg_huch_visual_navigation_get_distance(msg);
	huch_visual_navigation->home = mavlink_msg_huch_visual_navigation_get_home(msg);
	huch_visual_navigation->outlier = mavlink_msg_huch_visual_navigation_get_outlier(msg);
}
