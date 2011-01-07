// MESSAGE HUCH_MK_IMU PACKING

#define MAVLINK_MSG_ID_HUCH_MK_IMU 112

typedef struct __mavlink_huch_mk_imu_t 
{
	uint64_t usec; ///< Timestamp (microseconds since UNIX epoch)
	int16_t xacc; ///< Calibrated X acceleration (mg)
	int16_t yacc; ///< Calibrated Y acceleration (mg)
	int16_t zacc; ///< Calibrated Z acceleration (mg)
	int16_t xgyro; ///< Uncalibrated angular speed around X axis (0.1 deg/sec)
	int16_t ygyro; ///< Uncalibrated angular speed around Y axis (0.1 deg/sec)
	int16_t zgyro; ///< Uncalibrated angular speed around Z axis (0.1 deg/sec)

} mavlink_huch_mk_imu_t;



/**
 * @brief Pack a huch_mk_imu message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usec Timestamp (microseconds since UNIX epoch)
 * @param xacc Calibrated X acceleration (mg)
 * @param yacc Calibrated Y acceleration (mg)
 * @param zacc Calibrated Z acceleration (mg)
 * @param xgyro Uncalibrated angular speed around X axis (0.1 deg/sec)
 * @param ygyro Uncalibrated angular speed around Y axis (0.1 deg/sec)
 * @param zgyro Uncalibrated angular speed around Z axis (0.1 deg/sec)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_mk_imu_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint64_t usec, int16_t xacc, int16_t yacc, int16_t zacc, int16_t xgyro, int16_t ygyro, int16_t zgyro)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_MK_IMU;

	i += put_uint64_t_by_index(usec, i, msg->payload); // Timestamp (microseconds since UNIX epoch)
	i += put_int16_t_by_index(xacc, i, msg->payload); // Calibrated X acceleration (mg)
	i += put_int16_t_by_index(yacc, i, msg->payload); // Calibrated Y acceleration (mg)
	i += put_int16_t_by_index(zacc, i, msg->payload); // Calibrated Z acceleration (mg)
	i += put_int16_t_by_index(xgyro, i, msg->payload); // Uncalibrated angular speed around X axis (0.1 deg/sec)
	i += put_int16_t_by_index(ygyro, i, msg->payload); // Uncalibrated angular speed around Y axis (0.1 deg/sec)
	i += put_int16_t_by_index(zgyro, i, msg->payload); // Uncalibrated angular speed around Z axis (0.1 deg/sec)

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

/**
 * @brief Pack a huch_mk_imu message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec Timestamp (microseconds since UNIX epoch)
 * @param xacc Calibrated X acceleration (mg)
 * @param yacc Calibrated Y acceleration (mg)
 * @param zacc Calibrated Z acceleration (mg)
 * @param xgyro Uncalibrated angular speed around X axis (0.1 deg/sec)
 * @param ygyro Uncalibrated angular speed around Y axis (0.1 deg/sec)
 * @param zgyro Uncalibrated angular speed around Z axis (0.1 deg/sec)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_mk_imu_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, uint64_t usec, int16_t xacc, int16_t yacc, int16_t zacc, int16_t xgyro, int16_t ygyro, int16_t zgyro)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_MK_IMU;

	i += put_uint64_t_by_index(usec, i, msg->payload); // Timestamp (microseconds since UNIX epoch)
	i += put_int16_t_by_index(xacc, i, msg->payload); // Calibrated X acceleration (mg)
	i += put_int16_t_by_index(yacc, i, msg->payload); // Calibrated Y acceleration (mg)
	i += put_int16_t_by_index(zacc, i, msg->payload); // Calibrated Z acceleration (mg)
	i += put_int16_t_by_index(xgyro, i, msg->payload); // Uncalibrated angular speed around X axis (0.1 deg/sec)
	i += put_int16_t_by_index(ygyro, i, msg->payload); // Uncalibrated angular speed around Y axis (0.1 deg/sec)
	i += put_int16_t_by_index(zgyro, i, msg->payload); // Uncalibrated angular speed around Z axis (0.1 deg/sec)

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, i);
}

/**
 * @brief Encode a huch_mk_imu struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param huch_mk_imu C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_huch_mk_imu_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_mk_imu_t* huch_mk_imu)
{
	return mavlink_msg_huch_mk_imu_pack(system_id, component_id, msg, huch_mk_imu->usec, huch_mk_imu->xacc, huch_mk_imu->yacc, huch_mk_imu->zacc, huch_mk_imu->xgyro, huch_mk_imu->ygyro, huch_mk_imu->zgyro);
}

/**
 * @brief Send a huch_mk_imu message
 * @param chan MAVLink channel to send the message
 *
 * @param usec Timestamp (microseconds since UNIX epoch)
 * @param xacc Calibrated X acceleration (mg)
 * @param yacc Calibrated Y acceleration (mg)
 * @param zacc Calibrated Z acceleration (mg)
 * @param xgyro Uncalibrated angular speed around X axis (0.1 deg/sec)
 * @param ygyro Uncalibrated angular speed around Y axis (0.1 deg/sec)
 * @param zgyro Uncalibrated angular speed around Z axis (0.1 deg/sec)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_mk_imu_send(mavlink_channel_t chan, uint64_t usec, int16_t xacc, int16_t yacc, int16_t zacc, int16_t xgyro, int16_t ygyro, int16_t zgyro)
{
	mavlink_message_t msg;
	mavlink_msg_huch_mk_imu_pack_chan(mavlink_system.sysid, mavlink_system.compid, chan, &msg, usec, xacc, yacc, zacc, xgyro, ygyro, zgyro);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE HUCH_MK_IMU UNPACKING

/**
 * @brief Get field usec from huch_mk_imu message
 *
 * @return Timestamp (microseconds since UNIX epoch)
 */
static inline uint64_t mavlink_msg_huch_mk_imu_get_usec(const mavlink_message_t* msg)
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
 * @brief Get field xacc from huch_mk_imu message
 *
 * @return Calibrated X acceleration (mg)
 */
static inline int16_t mavlink_msg_huch_mk_imu_get_xacc(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint64_t))[0];
	r.b[0] = (msg->payload+sizeof(uint64_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field yacc from huch_mk_imu message
 *
 * @return Calibrated Y acceleration (mg)
 */
static inline int16_t mavlink_msg_huch_mk_imu_get_yacc(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint64_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(uint64_t)+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field zacc from huch_mk_imu message
 *
 * @return Calibrated Z acceleration (mg)
 */
static inline int16_t mavlink_msg_huch_mk_imu_get_zacc(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint64_t)+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(uint64_t)+sizeof(int16_t)+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field xgyro from huch_mk_imu message
 *
 * @return Uncalibrated angular speed around X axis (0.1 deg/sec)
 */
static inline int16_t mavlink_msg_huch_mk_imu_get_xgyro(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint64_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(uint64_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field ygyro from huch_mk_imu message
 *
 * @return Uncalibrated angular speed around Y axis (0.1 deg/sec)
 */
static inline int16_t mavlink_msg_huch_mk_imu_get_ygyro(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint64_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(uint64_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field zgyro from huch_mk_imu message
 *
 * @return Uncalibrated angular speed around Z axis (0.1 deg/sec)
 */
static inline int16_t mavlink_msg_huch_mk_imu_get_zgyro(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint64_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(uint64_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Decode a huch_mk_imu message into a struct
 *
 * @param msg The message to decode
 * @param huch_mk_imu C-struct to decode the message contents into
 */
static inline void mavlink_msg_huch_mk_imu_decode(const mavlink_message_t* msg, mavlink_huch_mk_imu_t* huch_mk_imu)
{
	huch_mk_imu->usec = mavlink_msg_huch_mk_imu_get_usec(msg);
	huch_mk_imu->xacc = mavlink_msg_huch_mk_imu_get_xacc(msg);
	huch_mk_imu->yacc = mavlink_msg_huch_mk_imu_get_yacc(msg);
	huch_mk_imu->zacc = mavlink_msg_huch_mk_imu_get_zacc(msg);
	huch_mk_imu->xgyro = mavlink_msg_huch_mk_imu_get_xgyro(msg);
	huch_mk_imu->ygyro = mavlink_msg_huch_mk_imu_get_ygyro(msg);
	huch_mk_imu->zgyro = mavlink_msg_huch_mk_imu_get_zgyro(msg);
}
