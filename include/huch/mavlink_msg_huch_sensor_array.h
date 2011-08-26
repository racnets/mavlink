// MESSAGE HUCH_SENSOR_ARRAY PACKING

#define MAVLINK_MSG_ID_HUCH_SENSOR_ARRAY 121

typedef struct __mavlink_huch_sensor_array_t 
{
	double data[64]; ///< 64-vector of generic double

} mavlink_huch_sensor_array_t;

#define MAVLINK_MSG_HUCH_SENSOR_ARRAY_FIELD_DATA_LEN 64


/**
 * @brief Pack a huch_sensor_array message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param data 64-vector of generic double
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_sensor_array_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const double* data)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_SENSOR_ARRAY;

	i += put_array_by_index((const int8_t*)data, sizeof(double)*64, i, msg->payload); // 64-vector of generic double

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

/**
 * @brief Pack a huch_sensor_array message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param data 64-vector of generic double
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_sensor_array_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const double* data)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_SENSOR_ARRAY;

	i += put_array_by_index((const int8_t*)data, sizeof(double)*64, i, msg->payload); // 64-vector of generic double

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, i);
}

/**
 * @brief Encode a huch_sensor_array struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param huch_sensor_array C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_huch_sensor_array_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_sensor_array_t* huch_sensor_array)
{
	return mavlink_msg_huch_sensor_array_pack(system_id, component_id, msg, huch_sensor_array->data);
}

/**
 * @brief Send a huch_sensor_array message
 * @param chan MAVLink channel to send the message
 *
 * @param data 64-vector of generic double
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_sensor_array_send(mavlink_channel_t chan, const double* data)
{
	mavlink_message_t msg;
	mavlink_msg_huch_sensor_array_pack_chan(mavlink_system.sysid, mavlink_system.compid, chan, &msg, data);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE HUCH_SENSOR_ARRAY UNPACKING

/**
 * @brief Get field data from huch_sensor_array message
 *
 * @return 64-vector of generic double
 */
static inline uint16_t mavlink_msg_huch_sensor_array_get_data(const mavlink_message_t* msg, double* r_data)
{

	memcpy(r_data, msg->payload, sizeof(double)*64);
	return sizeof(double)*64;
}

/**
 * @brief Decode a huch_sensor_array message into a struct
 *
 * @param msg The message to decode
 * @param huch_sensor_array C-struct to decode the message contents into
 */
static inline void mavlink_msg_huch_sensor_array_decode(const mavlink_message_t* msg, mavlink_huch_sensor_array_t* huch_sensor_array)
{
	mavlink_msg_huch_sensor_array_get_data(msg, huch_sensor_array->data);
}
