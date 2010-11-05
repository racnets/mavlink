// MESSAGE HUCH_ATTITUDE PACKING

#define MAVLINK_MSG_ID_HUCH_ATTITUDE 103

typedef struct __mavlink_huch_attitude_t 
{
	int16_t xacc; ///< 
	int16_t yacc; ///< 
	int16_t zacc; ///< 
	int16_t zaccraw; ///< 
	int16_t xaccmean; ///< 
	int16_t yaccmean; ///< 
	int16_t zaccmean; ///< 
	int16_t xgyro; ///< 
	int16_t ygyro; ///< 
	int16_t zgyro; ///< 
	int16_t xmag; ///< 
	int16_t ymag; ///< 
	int16_t zmag; ///< 

} mavlink_huch_attitude_t;



/**
 * @brief Send a huch_attitude message
 *
 * @param xacc 
 * @param yacc 
 * @param zacc 
 * @param zaccraw 
 * @param xaccmean 
 * @param yaccmean 
 * @param zaccmean 
 * @param xgyro 
 * @param ygyro 
 * @param zgyro 
 * @param xmag 
 * @param ymag 
 * @param zmag 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_attitude_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, int16_t xacc, int16_t yacc, int16_t zacc, int16_t zaccraw, int16_t xaccmean, int16_t yaccmean, int16_t zaccmean, int16_t xgyro, int16_t ygyro, int16_t zgyro, int16_t xmag, int16_t ymag, int16_t zmag)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_ATTITUDE;

	i += put_int16_t_by_index(xacc, i, msg->payload); //
	i += put_int16_t_by_index(yacc, i, msg->payload); //
	i += put_int16_t_by_index(zacc, i, msg->payload); //
	i += put_int16_t_by_index(zaccraw, i, msg->payload); //
	i += put_int16_t_by_index(xaccmean, i, msg->payload); //
	i += put_int16_t_by_index(yaccmean, i, msg->payload); //
	i += put_int16_t_by_index(zaccmean, i, msg->payload); //
	i += put_int16_t_by_index(xgyro, i, msg->payload); //
	i += put_int16_t_by_index(ygyro, i, msg->payload); //
	i += put_int16_t_by_index(zgyro, i, msg->payload); //
	i += put_int16_t_by_index(xmag, i, msg->payload); //
	i += put_int16_t_by_index(ymag, i, msg->payload); //
	i += put_int16_t_by_index(zmag, i, msg->payload); //

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_huch_attitude_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_attitude_t* huch_attitude)
{
	return mavlink_msg_huch_attitude_pack(system_id, component_id, msg, huch_attitude->xacc, huch_attitude->yacc, huch_attitude->zacc, huch_attitude->zaccraw, huch_attitude->xaccmean, huch_attitude->yaccmean, huch_attitude->zaccmean, huch_attitude->xgyro, huch_attitude->ygyro, huch_attitude->zgyro, huch_attitude->xmag, huch_attitude->ymag, huch_attitude->zmag);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_attitude_send(mavlink_channel_t chan, int16_t xacc, int16_t yacc, int16_t zacc, int16_t zaccraw, int16_t xaccmean, int16_t yaccmean, int16_t zaccmean, int16_t xgyro, int16_t ygyro, int16_t zgyro, int16_t xmag, int16_t ymag, int16_t zmag)
{
	mavlink_message_t msg;
	mavlink_msg_huch_attitude_pack(mavlink_system.sysid, mavlink_system.compid, &msg, xacc, yacc, zacc, zaccraw, xaccmean, yaccmean, zaccmean, xgyro, ygyro, zgyro, xmag, ymag, zmag);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE HUCH_ATTITUDE UNPACKING

/**
 * @brief Get field xacc from huch_attitude message
 *
 * @return 
 */
static inline int16_t mavlink_msg_huch_attitude_get_xacc(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload)[0];
	r.b[0] = (msg->payload)[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field yacc from huch_attitude message
 *
 * @return 
 */
static inline int16_t mavlink_msg_huch_attitude_get_yacc(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field zacc from huch_attitude message
 *
 * @return 
 */
static inline int16_t mavlink_msg_huch_attitude_get_zacc(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(int16_t)+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field zaccraw from huch_attitude message
 *
 * @return 
 */
static inline int16_t mavlink_msg_huch_attitude_get_zaccraw(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field xaccmean from huch_attitude message
 *
 * @return 
 */
static inline int16_t mavlink_msg_huch_attitude_get_xaccmean(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field yaccmean from huch_attitude message
 *
 * @return 
 */
static inline int16_t mavlink_msg_huch_attitude_get_yaccmean(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field zaccmean from huch_attitude message
 *
 * @return 
 */
static inline int16_t mavlink_msg_huch_attitude_get_zaccmean(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field xgyro from huch_attitude message
 *
 * @return 
 */
static inline int16_t mavlink_msg_huch_attitude_get_xgyro(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field ygyro from huch_attitude message
 *
 * @return 
 */
static inline int16_t mavlink_msg_huch_attitude_get_ygyro(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field zgyro from huch_attitude message
 *
 * @return 
 */
static inline int16_t mavlink_msg_huch_attitude_get_zgyro(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field xmag from huch_attitude message
 *
 * @return 
 */
static inline int16_t mavlink_msg_huch_attitude_get_xmag(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field ymag from huch_attitude message
 *
 * @return 
 */
static inline int16_t mavlink_msg_huch_attitude_get_ymag(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field zmag from huch_attitude message
 *
 * @return 
 */
static inline int16_t mavlink_msg_huch_attitude_get_zmag(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t)+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

static inline void mavlink_msg_huch_attitude_decode(const mavlink_message_t* msg, mavlink_huch_attitude_t* huch_attitude)
{
	huch_attitude->xacc = mavlink_msg_huch_attitude_get_xacc(msg);
	huch_attitude->yacc = mavlink_msg_huch_attitude_get_yacc(msg);
	huch_attitude->zacc = mavlink_msg_huch_attitude_get_zacc(msg);
	huch_attitude->zaccraw = mavlink_msg_huch_attitude_get_zaccraw(msg);
	huch_attitude->xaccmean = mavlink_msg_huch_attitude_get_xaccmean(msg);
	huch_attitude->yaccmean = mavlink_msg_huch_attitude_get_yaccmean(msg);
	huch_attitude->zaccmean = mavlink_msg_huch_attitude_get_zaccmean(msg);
	huch_attitude->xgyro = mavlink_msg_huch_attitude_get_xgyro(msg);
	huch_attitude->ygyro = mavlink_msg_huch_attitude_get_ygyro(msg);
	huch_attitude->zgyro = mavlink_msg_huch_attitude_get_zgyro(msg);
	huch_attitude->xmag = mavlink_msg_huch_attitude_get_xmag(msg);
	huch_attitude->ymag = mavlink_msg_huch_attitude_get_ymag(msg);
	huch_attitude->zmag = mavlink_msg_huch_attitude_get_zmag(msg);
}
