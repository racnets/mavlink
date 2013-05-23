// MESSAGE HUCH_QUAD_PIX_RAW PACKING

#define MAVLINK_MSG_ID_HUCH_QUAD_PIX_RAW 225

typedef struct __mavlink_huch_quad_pix_raw_t
{
 uint32_t msec; ///< timestamp in milliseconds
 uint32_t data[10]; ///< data
} mavlink_huch_quad_pix_raw_t;

#define MAVLINK_MSG_ID_HUCH_QUAD_PIX_RAW_LEN 44
#define MAVLINK_MSG_ID_225_LEN 44

#define MAVLINK_MSG_HUCH_QUAD_PIX_RAW_FIELD_DATA_LEN 10

#define MAVLINK_MESSAGE_INFO_HUCH_QUAD_PIX_RAW { \
	"HUCH_QUAD_PIX_RAW", \
	2, \
	{  { "msec", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_huch_quad_pix_raw_t, msec) }, \
         { "data", NULL, MAVLINK_TYPE_UINT32_T, 10, 4, offsetof(mavlink_huch_quad_pix_raw_t, data) }, \
         } \
}


/**
 * @brief Pack a huch_quad_pix_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param msec timestamp in milliseconds
 * @param data data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_quad_pix_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t msec, const uint32_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[44];
	_mav_put_uint32_t(buf, 0, msec);
	_mav_put_uint32_t_array(buf, 4, data, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 44);
#else
	mavlink_huch_quad_pix_raw_t packet;
	packet.msec = msec;
	mav_array_memcpy(packet.data, data, sizeof(uint32_t)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 44);
#endif

	msg->msgid = MAVLINK_MSG_ID_HUCH_QUAD_PIX_RAW;
	return mavlink_finalize_message(msg, system_id, component_id, 44, 27);
}

/**
 * @brief Pack a huch_quad_pix_raw message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param msec timestamp in milliseconds
 * @param data data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_quad_pix_raw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t msec,const uint32_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[44];
	_mav_put_uint32_t(buf, 0, msec);
	_mav_put_uint32_t_array(buf, 4, data, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 44);
#else
	mavlink_huch_quad_pix_raw_t packet;
	packet.msec = msec;
	mav_array_memcpy(packet.data, data, sizeof(uint32_t)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 44);
#endif

	msg->msgid = MAVLINK_MSG_ID_HUCH_QUAD_PIX_RAW;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 44, 27);
}

/**
 * @brief Encode a huch_quad_pix_raw struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param huch_quad_pix_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_huch_quad_pix_raw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_quad_pix_raw_t* huch_quad_pix_raw)
{
	return mavlink_msg_huch_quad_pix_raw_pack(system_id, component_id, msg, huch_quad_pix_raw->msec, huch_quad_pix_raw->data);
}

/**
 * @brief Send a huch_quad_pix_raw message
 * @param chan MAVLink channel to send the message
 *
 * @param msec timestamp in milliseconds
 * @param data data
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_quad_pix_raw_send(mavlink_channel_t chan, uint32_t msec, const uint32_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[44];
	_mav_put_uint32_t(buf, 0, msec);
	_mav_put_uint32_t_array(buf, 4, data, 10);
	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HUCH_QUAD_PIX_RAW, buf, 44, 27);
#else
	mavlink_huch_quad_pix_raw_t packet;
	packet.msec = msec;
	mav_array_memcpy(packet.data, data, sizeof(uint32_t)*10);
	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HUCH_QUAD_PIX_RAW, (const char *)&packet, 44, 27);
#endif
}

#endif

// MESSAGE HUCH_QUAD_PIX_RAW UNPACKING


/**
 * @brief Get field msec from huch_quad_pix_raw message
 *
 * @return timestamp in milliseconds
 */
static inline uint32_t mavlink_msg_huch_quad_pix_raw_get_msec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field data from huch_quad_pix_raw message
 *
 * @return data
 */
static inline uint16_t mavlink_msg_huch_quad_pix_raw_get_data(const mavlink_message_t* msg, uint32_t *data)
{
	return _MAV_RETURN_uint32_t_array(msg, data, 10,  4);
}

/**
 * @brief Decode a huch_quad_pix_raw message into a struct
 *
 * @param msg The message to decode
 * @param huch_quad_pix_raw C-struct to decode the message contents into
 */
static inline void mavlink_msg_huch_quad_pix_raw_decode(const mavlink_message_t* msg, mavlink_huch_quad_pix_raw_t* huch_quad_pix_raw)
{
#if MAVLINK_NEED_BYTE_SWAP
	huch_quad_pix_raw->msec = mavlink_msg_huch_quad_pix_raw_get_msec(msg);
	mavlink_msg_huch_quad_pix_raw_get_data(msg, huch_quad_pix_raw->data);
#else
	memcpy(huch_quad_pix_raw, _MAV_PAYLOAD(msg), 44);
#endif
}
