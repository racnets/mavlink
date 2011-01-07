// MESSAGE HUCH_CTRL_HOVER_STATE PACKING

#define MAVLINK_MSG_ID_HUCH_CTRL_HOVER_STATE 110

typedef struct __mavlink_huch_ctrl_hover_state_t 
{
	float uss; ///< Ultrasonic range measurement in mm
	float baro; ///< Barometric measurement in mm
	float accz; ///< Accelerometer measurement in mm/s^2
	float ir1; ///< Infrared range measurement in mm
	float ir2; ///< Infrared range measurement in mm
	float kal_s0; ///< Kalman state component 0 (pos)
	float kal_s1; ///< Kalman state component 1 (vel)
	float kal_s2; ///< Kalman state component 2 (acc)

} mavlink_huch_ctrl_hover_state_t;



/**
 * @brief Pack a huch_ctrl_hover_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param uss Ultrasonic range measurement in mm
 * @param baro Barometric measurement in mm
 * @param accz Accelerometer measurement in mm/s^2
 * @param ir1 Infrared range measurement in mm
 * @param ir2 Infrared range measurement in mm
 * @param kal_s0 Kalman state component 0 (pos)
 * @param kal_s1 Kalman state component 1 (vel)
 * @param kal_s2 Kalman state component 2 (acc)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_ctrl_hover_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, float uss, float baro, float accz, float ir1, float ir2, float kal_s0, float kal_s1, float kal_s2)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_CTRL_HOVER_STATE;

	i += put_float_by_index(uss, i, msg->payload); // Ultrasonic range measurement in mm
	i += put_float_by_index(baro, i, msg->payload); // Barometric measurement in mm
	i += put_float_by_index(accz, i, msg->payload); // Accelerometer measurement in mm/s^2
	i += put_float_by_index(ir1, i, msg->payload); // Infrared range measurement in mm
	i += put_float_by_index(ir2, i, msg->payload); // Infrared range measurement in mm
	i += put_float_by_index(kal_s0, i, msg->payload); // Kalman state component 0 (pos)
	i += put_float_by_index(kal_s1, i, msg->payload); // Kalman state component 1 (vel)
	i += put_float_by_index(kal_s2, i, msg->payload); // Kalman state component 2 (acc)

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

/**
 * @brief Pack a huch_ctrl_hover_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param uss Ultrasonic range measurement in mm
 * @param baro Barometric measurement in mm
 * @param accz Accelerometer measurement in mm/s^2
 * @param ir1 Infrared range measurement in mm
 * @param ir2 Infrared range measurement in mm
 * @param kal_s0 Kalman state component 0 (pos)
 * @param kal_s1 Kalman state component 1 (vel)
 * @param kal_s2 Kalman state component 2 (acc)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_ctrl_hover_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, float uss, float baro, float accz, float ir1, float ir2, float kal_s0, float kal_s1, float kal_s2)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_CTRL_HOVER_STATE;

	i += put_float_by_index(uss, i, msg->payload); // Ultrasonic range measurement in mm
	i += put_float_by_index(baro, i, msg->payload); // Barometric measurement in mm
	i += put_float_by_index(accz, i, msg->payload); // Accelerometer measurement in mm/s^2
	i += put_float_by_index(ir1, i, msg->payload); // Infrared range measurement in mm
	i += put_float_by_index(ir2, i, msg->payload); // Infrared range measurement in mm
	i += put_float_by_index(kal_s0, i, msg->payload); // Kalman state component 0 (pos)
	i += put_float_by_index(kal_s1, i, msg->payload); // Kalman state component 1 (vel)
	i += put_float_by_index(kal_s2, i, msg->payload); // Kalman state component 2 (acc)

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, i);
}

/**
 * @brief Encode a huch_ctrl_hover_state struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param huch_ctrl_hover_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_huch_ctrl_hover_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_ctrl_hover_state_t* huch_ctrl_hover_state)
{
	return mavlink_msg_huch_ctrl_hover_state_pack(system_id, component_id, msg, huch_ctrl_hover_state->uss, huch_ctrl_hover_state->baro, huch_ctrl_hover_state->accz, huch_ctrl_hover_state->ir1, huch_ctrl_hover_state->ir2, huch_ctrl_hover_state->kal_s0, huch_ctrl_hover_state->kal_s1, huch_ctrl_hover_state->kal_s2);
}

/**
 * @brief Send a huch_ctrl_hover_state message
 * @param chan MAVLink channel to send the message
 *
 * @param uss Ultrasonic range measurement in mm
 * @param baro Barometric measurement in mm
 * @param accz Accelerometer measurement in mm/s^2
 * @param ir1 Infrared range measurement in mm
 * @param ir2 Infrared range measurement in mm
 * @param kal_s0 Kalman state component 0 (pos)
 * @param kal_s1 Kalman state component 1 (vel)
 * @param kal_s2 Kalman state component 2 (acc)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_ctrl_hover_state_send(mavlink_channel_t chan, float uss, float baro, float accz, float ir1, float ir2, float kal_s0, float kal_s1, float kal_s2)
{
	mavlink_message_t msg;
	mavlink_msg_huch_ctrl_hover_state_pack_chan(mavlink_system.sysid, mavlink_system.compid, chan, &msg, uss, baro, accz, ir1, ir2, kal_s0, kal_s1, kal_s2);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE HUCH_CTRL_HOVER_STATE UNPACKING

/**
 * @brief Get field uss from huch_ctrl_hover_state message
 *
 * @return Ultrasonic range measurement in mm
 */
static inline float mavlink_msg_huch_ctrl_hover_state_get_uss(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload)[0];
	r.b[2] = (msg->payload)[1];
	r.b[1] = (msg->payload)[2];
	r.b[0] = (msg->payload)[3];
	return (float)r.f;
}

/**
 * @brief Get field baro from huch_ctrl_hover_state message
 *
 * @return Barometric measurement in mm
 */
static inline float mavlink_msg_huch_ctrl_hover_state_get_baro(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field accz from huch_ctrl_hover_state message
 *
 * @return Accelerometer measurement in mm/s^2
 */
static inline float mavlink_msg_huch_ctrl_hover_state_get_accz(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field ir1 from huch_ctrl_hover_state message
 *
 * @return Infrared range measurement in mm
 */
static inline float mavlink_msg_huch_ctrl_hover_state_get_ir1(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field ir2 from huch_ctrl_hover_state message
 *
 * @return Infrared range measurement in mm
 */
static inline float mavlink_msg_huch_ctrl_hover_state_get_ir2(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field kal_s0 from huch_ctrl_hover_state message
 *
 * @return Kalman state component 0 (pos)
 */
static inline float mavlink_msg_huch_ctrl_hover_state_get_kal_s0(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field kal_s1 from huch_ctrl_hover_state message
 *
 * @return Kalman state component 1 (vel)
 */
static inline float mavlink_msg_huch_ctrl_hover_state_get_kal_s1(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field kal_s2 from huch_ctrl_hover_state message
 *
 * @return Kalman state component 2 (acc)
 */
static inline float mavlink_msg_huch_ctrl_hover_state_get_kal_s2(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Decode a huch_ctrl_hover_state message into a struct
 *
 * @param msg The message to decode
 * @param huch_ctrl_hover_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_huch_ctrl_hover_state_decode(const mavlink_message_t* msg, mavlink_huch_ctrl_hover_state_t* huch_ctrl_hover_state)
{
	huch_ctrl_hover_state->uss = mavlink_msg_huch_ctrl_hover_state_get_uss(msg);
	huch_ctrl_hover_state->baro = mavlink_msg_huch_ctrl_hover_state_get_baro(msg);
	huch_ctrl_hover_state->accz = mavlink_msg_huch_ctrl_hover_state_get_accz(msg);
	huch_ctrl_hover_state->ir1 = mavlink_msg_huch_ctrl_hover_state_get_ir1(msg);
	huch_ctrl_hover_state->ir2 = mavlink_msg_huch_ctrl_hover_state_get_ir2(msg);
	huch_ctrl_hover_state->kal_s0 = mavlink_msg_huch_ctrl_hover_state_get_kal_s0(msg);
	huch_ctrl_hover_state->kal_s1 = mavlink_msg_huch_ctrl_hover_state_get_kal_s1(msg);
	huch_ctrl_hover_state->kal_s2 = mavlink_msg_huch_ctrl_hover_state_get_kal_s2(msg);
}
