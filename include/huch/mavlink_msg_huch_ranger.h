// MESSAGE HUCH_RANGER PACKING

#define MAVLINK_MSG_ID_HUCH_RANGER 105

typedef struct __mavlink_huch_ranger_t 
{
	uint16_t ranger1; ///< 
	uint16_t ranger2; ///< 
	uint16_t ranger3; ///< 

} mavlink_huch_ranger_t;



/**
 * @brief Pack a huch_ranger message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ranger1 
 * @param ranger2 
 * @param ranger3 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_ranger_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint16_t ranger1, uint16_t ranger2, uint16_t ranger3)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_RANGER;

	i += put_uint16_t_by_index(ranger1, i, msg->payload); // 
	i += put_uint16_t_by_index(ranger2, i, msg->payload); // 
	i += put_uint16_t_by_index(ranger3, i, msg->payload); // 

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

/**
 * @brief Pack a huch_ranger message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param ranger1 
 * @param ranger2 
 * @param ranger3 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_ranger_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, uint16_t ranger1, uint16_t ranger2, uint16_t ranger3)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_RANGER;

	i += put_uint16_t_by_index(ranger1, i, msg->payload); // 
	i += put_uint16_t_by_index(ranger2, i, msg->payload); // 
	i += put_uint16_t_by_index(ranger3, i, msg->payload); // 

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, i);
}

/**
 * @brief Encode a huch_ranger struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param huch_ranger C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_huch_ranger_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_ranger_t* huch_ranger)
{
	return mavlink_msg_huch_ranger_pack(system_id, component_id, msg, huch_ranger->ranger1, huch_ranger->ranger2, huch_ranger->ranger3);
}

/**
 * @brief Send a huch_ranger message
 * @param chan MAVLink channel to send the message
 *
 * @param ranger1 
 * @param ranger2 
 * @param ranger3 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_ranger_send(mavlink_channel_t chan, uint16_t ranger1, uint16_t ranger2, uint16_t ranger3)
{
	mavlink_message_t msg;
	mavlink_msg_huch_ranger_pack_chan(mavlink_system.sysid, mavlink_system.compid, chan, &msg, ranger1, ranger2, ranger3);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE HUCH_RANGER UNPACKING

/**
 * @brief Get field ranger1 from huch_ranger message
 *
 * @return 
 */
static inline uint16_t mavlink_msg_huch_ranger_get_ranger1(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload)[0];
	r.b[0] = (msg->payload)[1];
	return (uint16_t)r.s;
}

/**
 * @brief Get field ranger2 from huch_ranger message
 *
 * @return 
 */
static inline uint16_t mavlink_msg_huch_ranger_get_ranger2(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint16_t))[0];
	r.b[0] = (msg->payload+sizeof(uint16_t))[1];
	return (uint16_t)r.s;
}

/**
 * @brief Get field ranger3 from huch_ranger message
 *
 * @return 
 */
static inline uint16_t mavlink_msg_huch_ranger_get_ranger3(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint16_t)+sizeof(uint16_t))[0];
	r.b[0] = (msg->payload+sizeof(uint16_t)+sizeof(uint16_t))[1];
	return (uint16_t)r.s;
}

/**
 * @brief Decode a huch_ranger message into a struct
 *
 * @param msg The message to decode
 * @param huch_ranger C-struct to decode the message contents into
 */
static inline void mavlink_msg_huch_ranger_decode(const mavlink_message_t* msg, mavlink_huch_ranger_t* huch_ranger)
{
	huch_ranger->ranger1 = mavlink_msg_huch_ranger_get_ranger1(msg);
	huch_ranger->ranger2 = mavlink_msg_huch_ranger_get_ranger2(msg);
	huch_ranger->ranger3 = mavlink_msg_huch_ranger_get_ranger3(msg);
}
