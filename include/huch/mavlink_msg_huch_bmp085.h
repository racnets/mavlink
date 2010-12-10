// MESSAGE HUCH_BMP085 PACKING

#define MAVLINK_MSG_ID_HUCH_BMP085 106

typedef struct __mavlink_huch_bmp085_t 
{
	int32_t pressure; ///< pressure in Pa
	int16_t temperature; ///< temperature in 0.1C
	uint32_t timestamp; ///< time in us
	float height; ///< height in meter

} mavlink_huch_bmp085_t;



/**
 * @brief Send a huch_bmp085 message
 *
 * @param pressure pressure in Pa
 * @param temperature temperature in 0.1C
 * @param timestamp time in us
 * @param height height in meter
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_bmp085_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, int32_t pressure, int16_t temperature, uint32_t timestamp, float height)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_BMP085;

	i += put_int32_t_by_index(pressure, i, msg->payload); //pressure in Pa
	i += put_int16_t_by_index(temperature, i, msg->payload); //temperature in 0.1C
	i += put_uint32_t_by_index(timestamp, i, msg->payload); //time in us
	i += put_float_by_index(height, i, msg->payload); //height in meter

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_huch_bmp085_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, int32_t pressure, int16_t temperature, uint32_t timestamp, float height)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_BMP085;

	i += put_int32_t_by_index(pressure, i, msg->payload); //pressure in Pa
	i += put_int16_t_by_index(temperature, i, msg->payload); //temperature in 0.1C
	i += put_uint32_t_by_index(timestamp, i, msg->payload); //time in us
	i += put_float_by_index(height, i, msg->payload); //height in meter

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, i);
}

static inline uint16_t mavlink_msg_huch_bmp085_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_bmp085_t* huch_bmp085)
{
	return mavlink_msg_huch_bmp085_pack(system_id, component_id, msg, huch_bmp085->pressure, huch_bmp085->temperature, huch_bmp085->timestamp, huch_bmp085->height);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_bmp085_send(mavlink_channel_t chan, int32_t pressure, int16_t temperature, uint32_t timestamp, float height)
{
	mavlink_message_t msg;
	mavlink_msg_huch_bmp085_pack_chan(mavlink_system.sysid, mavlink_system.compid, chan, &msg, pressure, temperature, timestamp, height);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE HUCH_BMP085 UNPACKING

/**
 * @brief Get field pressure from huch_bmp085 message
 *
 * @return pressure in Pa
 */
static inline int32_t mavlink_msg_huch_bmp085_get_pressure(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload)[0];
	r.b[2] = (msg->payload)[1];
	r.b[1] = (msg->payload)[2];
	r.b[0] = (msg->payload)[3];
	return (int32_t)r.i;
}

/**
 * @brief Get field temperature from huch_bmp085 message
 *
 * @return temperature in 0.1C
 */
static inline int16_t mavlink_msg_huch_bmp085_get_temperature(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(int32_t))[0];
	r.b[0] = (msg->payload+sizeof(int32_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field timestamp from huch_bmp085 message
 *
 * @return time in us
 */
static inline uint32_t mavlink_msg_huch_bmp085_get_timestamp(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(int32_t)+sizeof(int16_t))[0];
	r.b[2] = (msg->payload+sizeof(int32_t)+sizeof(int16_t))[1];
	r.b[1] = (msg->payload+sizeof(int32_t)+sizeof(int16_t))[2];
	r.b[0] = (msg->payload+sizeof(int32_t)+sizeof(int16_t))[3];
	return (uint32_t)r.i;
}

/**
 * @brief Get field height from huch_bmp085 message
 *
 * @return height in meter
 */
static inline float mavlink_msg_huch_bmp085_get_height(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(int32_t)+sizeof(int16_t)+sizeof(uint32_t))[0];
	r.b[2] = (msg->payload+sizeof(int32_t)+sizeof(int16_t)+sizeof(uint32_t))[1];
	r.b[1] = (msg->payload+sizeof(int32_t)+sizeof(int16_t)+sizeof(uint32_t))[2];
	r.b[0] = (msg->payload+sizeof(int32_t)+sizeof(int16_t)+sizeof(uint32_t))[3];
	return (float)r.f;
}

static inline void mavlink_msg_huch_bmp085_decode(const mavlink_message_t* msg, mavlink_huch_bmp085_t* huch_bmp085)
{
	huch_bmp085->pressure = mavlink_msg_huch_bmp085_get_pressure(msg);
	huch_bmp085->temperature = mavlink_msg_huch_bmp085_get_temperature(msg);
	huch_bmp085->timestamp = mavlink_msg_huch_bmp085_get_timestamp(msg);
	huch_bmp085->height = mavlink_msg_huch_bmp085_get_height(msg);
}
