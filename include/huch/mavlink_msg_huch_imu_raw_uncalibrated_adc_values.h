// MESSAGE HUCH_IMU_RAW_UNCALIBRATED_ADC_VALUES PACKING

#define MAVLINK_MSG_ID_HUCH_IMU_RAW_UNCALIBRATED_ADC_VALUES 111

typedef struct __mavlink_huch_imu_raw_uncalibrated_adc_values_t 
{
	uint16_t xacc; ///< X acceleration (adc units)
	uint16_t yacc; ///< Y acceleration (adc units)
	uint16_t zacc; ///< Z acceleration (adc units)
	uint16_t xgyro; ///< Angular speed around X axis (adc units)
	uint16_t ygyro; ///< Angular speed around Y axis (adc units)
	uint16_t zgyro; ///< Angular speed around Z axis (adc units)

} mavlink_huch_imu_raw_uncalibrated_adc_values_t;



/**
 * @brief Send a huch_imu_raw_uncalibrated_adc_values message
 *
 * @param xacc X acceleration (adc units)
 * @param yacc Y acceleration (adc units)
 * @param zacc Z acceleration (adc units)
 * @param xgyro Angular speed around X axis (adc units)
 * @param ygyro Angular speed around Y axis (adc units)
 * @param zgyro Angular speed around Z axis (adc units)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_imu_raw_uncalibrated_adc_values_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint16_t xacc, uint16_t yacc, uint16_t zacc, uint16_t xgyro, uint16_t ygyro, uint16_t zgyro)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_IMU_RAW_UNCALIBRATED_ADC_VALUES;

	i += put_uint16_t_by_index(xacc, i, msg->payload); //X acceleration (adc units)
	i += put_uint16_t_by_index(yacc, i, msg->payload); //Y acceleration (adc units)
	i += put_uint16_t_by_index(zacc, i, msg->payload); //Z acceleration (adc units)
	i += put_uint16_t_by_index(xgyro, i, msg->payload); //Angular speed around X axis (adc units)
	i += put_uint16_t_by_index(ygyro, i, msg->payload); //Angular speed around Y axis (adc units)
	i += put_uint16_t_by_index(zgyro, i, msg->payload); //Angular speed around Z axis (adc units)

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_huch_imu_raw_uncalibrated_adc_values_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_imu_raw_uncalibrated_adc_values_t* huch_imu_raw_uncalibrated_adc_values)
{
	return mavlink_msg_huch_imu_raw_uncalibrated_adc_values_pack(system_id, component_id, msg, huch_imu_raw_uncalibrated_adc_values->xacc, huch_imu_raw_uncalibrated_adc_values->yacc, huch_imu_raw_uncalibrated_adc_values->zacc, huch_imu_raw_uncalibrated_adc_values->xgyro, huch_imu_raw_uncalibrated_adc_values->ygyro, huch_imu_raw_uncalibrated_adc_values->zgyro);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_imu_raw_uncalibrated_adc_values_send(mavlink_channel_t chan, uint16_t xacc, uint16_t yacc, uint16_t zacc, uint16_t xgyro, uint16_t ygyro, uint16_t zgyro)
{
	mavlink_message_t msg;
	mavlink_msg_huch_imu_raw_uncalibrated_adc_values_pack(mavlink_system.sysid, mavlink_system.compid, &msg, xacc, yacc, zacc, xgyro, ygyro, zgyro);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE HUCH_IMU_RAW_UNCALIBRATED_ADC_VALUES UNPACKING

/**
 * @brief Get field xacc from huch_imu_raw_uncalibrated_adc_values message
 *
 * @return X acceleration (adc units)
 */
static inline uint16_t mavlink_msg_huch_imu_raw_uncalibrated_adc_values_get_xacc(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload)[0];
	r.b[0] = (msg->payload)[1];
	return (uint16_t)r.s;
}

/**
 * @brief Get field yacc from huch_imu_raw_uncalibrated_adc_values message
 *
 * @return Y acceleration (adc units)
 */
static inline uint16_t mavlink_msg_huch_imu_raw_uncalibrated_adc_values_get_yacc(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint16_t))[0];
	r.b[0] = (msg->payload+sizeof(uint16_t))[1];
	return (uint16_t)r.s;
}

/**
 * @brief Get field zacc from huch_imu_raw_uncalibrated_adc_values message
 *
 * @return Z acceleration (adc units)
 */
static inline uint16_t mavlink_msg_huch_imu_raw_uncalibrated_adc_values_get_zacc(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint16_t)+sizeof(uint16_t))[0];
	r.b[0] = (msg->payload+sizeof(uint16_t)+sizeof(uint16_t))[1];
	return (uint16_t)r.s;
}

/**
 * @brief Get field xgyro from huch_imu_raw_uncalibrated_adc_values message
 *
 * @return Angular speed around X axis (adc units)
 */
static inline uint16_t mavlink_msg_huch_imu_raw_uncalibrated_adc_values_get_xgyro(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint16_t)+sizeof(uint16_t)+sizeof(uint16_t))[0];
	r.b[0] = (msg->payload+sizeof(uint16_t)+sizeof(uint16_t)+sizeof(uint16_t))[1];
	return (uint16_t)r.s;
}

/**
 * @brief Get field ygyro from huch_imu_raw_uncalibrated_adc_values message
 *
 * @return Angular speed around Y axis (adc units)
 */
static inline uint16_t mavlink_msg_huch_imu_raw_uncalibrated_adc_values_get_ygyro(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint16_t)+sizeof(uint16_t)+sizeof(uint16_t)+sizeof(uint16_t))[0];
	r.b[0] = (msg->payload+sizeof(uint16_t)+sizeof(uint16_t)+sizeof(uint16_t)+sizeof(uint16_t))[1];
	return (uint16_t)r.s;
}

/**
 * @brief Get field zgyro from huch_imu_raw_uncalibrated_adc_values message
 *
 * @return Angular speed around Z axis (adc units)
 */
static inline uint16_t mavlink_msg_huch_imu_raw_uncalibrated_adc_values_get_zgyro(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint16_t)+sizeof(uint16_t)+sizeof(uint16_t)+sizeof(uint16_t)+sizeof(uint16_t))[0];
	r.b[0] = (msg->payload+sizeof(uint16_t)+sizeof(uint16_t)+sizeof(uint16_t)+sizeof(uint16_t)+sizeof(uint16_t))[1];
	return (uint16_t)r.s;
}

static inline void mavlink_msg_huch_imu_raw_uncalibrated_adc_values_decode(const mavlink_message_t* msg, mavlink_huch_imu_raw_uncalibrated_adc_values_t* huch_imu_raw_uncalibrated_adc_values)
{
	huch_imu_raw_uncalibrated_adc_values->xacc = mavlink_msg_huch_imu_raw_uncalibrated_adc_values_get_xacc(msg);
	huch_imu_raw_uncalibrated_adc_values->yacc = mavlink_msg_huch_imu_raw_uncalibrated_adc_values_get_yacc(msg);
	huch_imu_raw_uncalibrated_adc_values->zacc = mavlink_msg_huch_imu_raw_uncalibrated_adc_values_get_zacc(msg);
	huch_imu_raw_uncalibrated_adc_values->xgyro = mavlink_msg_huch_imu_raw_uncalibrated_adc_values_get_xgyro(msg);
	huch_imu_raw_uncalibrated_adc_values->ygyro = mavlink_msg_huch_imu_raw_uncalibrated_adc_values_get_ygyro(msg);
	huch_imu_raw_uncalibrated_adc_values->zgyro = mavlink_msg_huch_imu_raw_uncalibrated_adc_values_get_zgyro(msg);
}
