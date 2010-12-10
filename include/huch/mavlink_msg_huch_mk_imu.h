// MESSAGE HUCH_MK_IMU PACKING

#define MAVLINK_MSG_ID_HUCH_MK_IMU 112

typedef struct __mavlink_huch_mk_imu_t 
{
	int16_t xacc; ///< Calibrated X acceleration (mg)
	int16_t yacc; ///< Calibrated Y acceleration (mg)
	int16_t zacc; ///< Calibrated Z acceleration (mg)
	int16_t xgyro; ///< Uncalibrated angular speed around X axis (0.1 deg/sec)
	int16_t ygyro; ///< Uncalibrated angular speed around Y axis (0.1 deg/sec)
	int16_t zgyro; ///< Uncalibrated angular speed around Z axis (0.1 deg/sec)

} mavlink_huch_mk_imu_t;



/**
 * @brief Send a huch_mk_imu message
 *
 * @param xacc Calibrated X acceleration (mg)
 * @param yacc Calibrated Y acceleration (mg)
 * @param zacc Calibrated Z acceleration (mg)
 * @param xgyro Uncalibrated angular speed around X axis (0.1 deg/sec)
 * @param ygyro Uncalibrated angular speed around Y axis (0.1 deg/sec)
 * @param zgyro Uncalibrated angular speed around Z axis (0.1 deg/sec)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_mk_imu_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, int16_t xacc, int16_t yacc, int16_t zacc, int16_t xgyro, int16_t ygyro, int16_t zgyro)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_MK_IMU;

	i += put_int16_t_by_index(xacc, i, msg->payload); //Calibrated X acceleration (mg)
	i += put_int16_t_by_index(yacc, i, msg->payload); //Calibrated Y acceleration (mg)
	i += put_int16_t_by_index(zacc, i, msg->payload); //Calibrated Z acceleration (mg)
	i += put_int16_t_by_index(xgyro, i, msg->payload); //Uncalibrated angular speed around X axis (0.1 deg/sec)
	i += put_int16_t_by_index(ygyro, i, msg->payload); //Uncalibrated angular speed around Y axis (0.1 deg/sec)
	i += put_int16_t_by_index(zgyro, i, msg->payload); //Uncalibrated angular speed around Z axis (0.1 deg/sec)

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_huch_mk_imu_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_mk_imu_t* huch_mk_imu)
{
	return mavlink_msg_huch_mk_imu_pack(system_id, component_id, msg, huch_mk_imu->xacc, huch_mk_imu->yacc, huch_mk_imu->zacc, huch_mk_imu->xgyro, huch_mk_imu->ygyro, huch_mk_imu->zgyro);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_mk_imu_send(mavlink_channel_t chan, int16_t xacc, int16_t yacc, int16_t zacc, int16_t xgyro, int16_t ygyro, int16_t zgyro)
{
	mavlink_message_t msg;
	mavlink_msg_huch_mk_imu_pack(mavlink_system.sysid, mavlink_system.compid, &msg, xacc, yacc, zacc, xgyro, ygyro, zgyro);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE HUCH_MK_IMU UNPACKING

/**
 * @brief Get field xacc from huch_mk_imu message
 *
 * @return Calibrated X acceleration (mg)
 */
static inline int16_t mavlink_msg_huch_mk_imu_get_xacc(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload)[0];
	r.b[0] = (msg->payload)[1];
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
	r.b[1] = (msg->payload+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(int16_t))[1];
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
	r.b[1] = (msg->payload+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(int16_t)+sizeof(int16_t))[1];
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
	r.b[1] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[1];
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
	r.b[1] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[1];
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
	r.b[1] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

static inline void mavlink_msg_huch_mk_imu_decode(const mavlink_message_t* msg, mavlink_huch_mk_imu_t* huch_mk_imu)
{
	huch_mk_imu->xacc = mavlink_msg_huch_mk_imu_get_xacc(msg);
	huch_mk_imu->yacc = mavlink_msg_huch_mk_imu_get_yacc(msg);
	huch_mk_imu->zacc = mavlink_msg_huch_mk_imu_get_zacc(msg);
	huch_mk_imu->xgyro = mavlink_msg_huch_mk_imu_get_xgyro(msg);
	huch_mk_imu->ygyro = mavlink_msg_huch_mk_imu_get_ygyro(msg);
	huch_mk_imu->zgyro = mavlink_msg_huch_mk_imu_get_zgyro(msg);
}
