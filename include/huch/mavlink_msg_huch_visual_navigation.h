// MESSAGE HUCH_VISUAL_NAVIGATION PACKING

#define MAVLINK_MSG_ID_HUCH_VISUAL_NAVIGATION 118

typedef struct __mavlink_huch_visual_navigation_t 
{
	float alt_velocity; ///< altitude velocity
	float alt_absolute; ///< altitude absolute value
	float home_beta; ///< home direction
	float home_distance; ///< home distance
	float visual_compass; ///< visual compass
	float ego_beta; ///< lateral movement direction
	float ego_speed; ///< lateral movement speed
	int16_t keypoints; ///< tracked keypoints
	int16_t error; ///< error code
	float debug; ///< debug information

} mavlink_huch_visual_navigation_t;



/**
 * @brief Pack a huch_visual_navigation message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param alt_velocity altitude velocity
 * @param alt_absolute altitude absolute value
 * @param home_beta home direction
 * @param home_distance home distance
 * @param visual_compass visual compass
 * @param ego_beta lateral movement direction
 * @param ego_speed lateral movement speed
 * @param keypoints tracked keypoints
 * @param error error code
 * @param debug debug information
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_visual_navigation_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, float alt_velocity, float alt_absolute, float home_beta, float home_distance, float visual_compass, float ego_beta, float ego_speed, int16_t keypoints, int16_t error, float debug)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_VISUAL_NAVIGATION;

	i += put_float_by_index(alt_velocity, i, msg->payload); // altitude velocity
	i += put_float_by_index(alt_absolute, i, msg->payload); // altitude absolute value
	i += put_float_by_index(home_beta, i, msg->payload); // home direction
	i += put_float_by_index(home_distance, i, msg->payload); // home distance
	i += put_float_by_index(visual_compass, i, msg->payload); // visual compass
	i += put_float_by_index(ego_beta, i, msg->payload); // lateral movement direction
	i += put_float_by_index(ego_speed, i, msg->payload); // lateral movement speed
	i += put_int16_t_by_index(keypoints, i, msg->payload); // tracked keypoints
	i += put_int16_t_by_index(error, i, msg->payload); // error code
	i += put_float_by_index(debug, i, msg->payload); // debug information

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

/**
 * @brief Pack a huch_visual_navigation message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param alt_velocity altitude velocity
 * @param alt_absolute altitude absolute value
 * @param home_beta home direction
 * @param home_distance home distance
 * @param visual_compass visual compass
 * @param ego_beta lateral movement direction
 * @param ego_speed lateral movement speed
 * @param keypoints tracked keypoints
 * @param error error code
 * @param debug debug information
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_visual_navigation_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, float alt_velocity, float alt_absolute, float home_beta, float home_distance, float visual_compass, float ego_beta, float ego_speed, int16_t keypoints, int16_t error, float debug)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_VISUAL_NAVIGATION;

	i += put_float_by_index(alt_velocity, i, msg->payload); // altitude velocity
	i += put_float_by_index(alt_absolute, i, msg->payload); // altitude absolute value
	i += put_float_by_index(home_beta, i, msg->payload); // home direction
	i += put_float_by_index(home_distance, i, msg->payload); // home distance
	i += put_float_by_index(visual_compass, i, msg->payload); // visual compass
	i += put_float_by_index(ego_beta, i, msg->payload); // lateral movement direction
	i += put_float_by_index(ego_speed, i, msg->payload); // lateral movement speed
	i += put_int16_t_by_index(keypoints, i, msg->payload); // tracked keypoints
	i += put_int16_t_by_index(error, i, msg->payload); // error code
	i += put_float_by_index(debug, i, msg->payload); // debug information

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
	return mavlink_msg_huch_visual_navigation_pack(system_id, component_id, msg, huch_visual_navigation->alt_velocity, huch_visual_navigation->alt_absolute, huch_visual_navigation->home_beta, huch_visual_navigation->home_distance, huch_visual_navigation->visual_compass, huch_visual_navigation->ego_beta, huch_visual_navigation->ego_speed, huch_visual_navigation->keypoints, huch_visual_navigation->error, huch_visual_navigation->debug);
}

/**
 * @brief Send a huch_visual_navigation message
 * @param chan MAVLink channel to send the message
 *
 * @param alt_velocity altitude velocity
 * @param alt_absolute altitude absolute value
 * @param home_beta home direction
 * @param home_distance home distance
 * @param visual_compass visual compass
 * @param ego_beta lateral movement direction
 * @param ego_speed lateral movement speed
 * @param keypoints tracked keypoints
 * @param error error code
 * @param debug debug information
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_visual_navigation_send(mavlink_channel_t chan, float alt_velocity, float alt_absolute, float home_beta, float home_distance, float visual_compass, float ego_beta, float ego_speed, int16_t keypoints, int16_t error, float debug)
{
	mavlink_message_t msg;
	mavlink_msg_huch_visual_navigation_pack_chan(mavlink_system.sysid, mavlink_system.compid, chan, &msg, alt_velocity, alt_absolute, home_beta, home_distance, visual_compass, ego_beta, ego_speed, keypoints, error, debug);
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
 * @brief Get field alt_absolute from huch_visual_navigation message
 *
 * @return altitude absolute value
 */
static inline float mavlink_msg_huch_visual_navigation_get_alt_absolute(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field home_beta from huch_visual_navigation message
 *
 * @return home direction
 */
static inline float mavlink_msg_huch_visual_navigation_get_home_beta(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field home_distance from huch_visual_navigation message
 *
 * @return home distance
 */
static inline float mavlink_msg_huch_visual_navigation_get_home_distance(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field visual_compass from huch_visual_navigation message
 *
 * @return visual compass
 */
static inline float mavlink_msg_huch_visual_navigation_get_visual_compass(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field ego_beta from huch_visual_navigation message
 *
 * @return lateral movement direction
 */
static inline float mavlink_msg_huch_visual_navigation_get_ego_beta(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field ego_speed from huch_visual_navigation message
 *
 * @return lateral movement speed
 */
static inline float mavlink_msg_huch_visual_navigation_get_ego_speed(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field keypoints from huch_visual_navigation message
 *
 * @return tracked keypoints
 */
static inline int16_t mavlink_msg_huch_visual_navigation_get_keypoints(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[0];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field error from huch_visual_navigation message
 *
 * @return error code
 */
static inline int16_t mavlink_msg_huch_visual_navigation_get_error(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field debug from huch_visual_navigation message
 *
 * @return debug information
 */
static inline float mavlink_msg_huch_visual_navigation_get_debug(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(int16_t)+sizeof(int16_t))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(int16_t)+sizeof(int16_t))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(int16_t)+sizeof(int16_t))[3];
	return (float)r.f;
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
	huch_visual_navigation->alt_absolute = mavlink_msg_huch_visual_navigation_get_alt_absolute(msg);
	huch_visual_navigation->home_beta = mavlink_msg_huch_visual_navigation_get_home_beta(msg);
	huch_visual_navigation->home_distance = mavlink_msg_huch_visual_navigation_get_home_distance(msg);
	huch_visual_navigation->visual_compass = mavlink_msg_huch_visual_navigation_get_visual_compass(msg);
	huch_visual_navigation->ego_beta = mavlink_msg_huch_visual_navigation_get_ego_beta(msg);
	huch_visual_navigation->ego_speed = mavlink_msg_huch_visual_navigation_get_ego_speed(msg);
	huch_visual_navigation->keypoints = mavlink_msg_huch_visual_navigation_get_keypoints(msg);
	huch_visual_navigation->error = mavlink_msg_huch_visual_navigation_get_error(msg);
	huch_visual_navigation->debug = mavlink_msg_huch_visual_navigation_get_debug(msg);
}
