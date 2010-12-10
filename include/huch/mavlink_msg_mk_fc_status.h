// MESSAGE MK_FC_STATUS PACKING

#define MAVLINK_MSG_ID_MK_FC_STATUS 109

typedef struct __mavlink_mk_fc_status_t 
{
	int16_t rssi; ///< RC Control RSSI on FlightCtrl
	int16_t batt; ///< Battery Voltage Level
	int16_t gas; ///< Internally computed gas value

} mavlink_mk_fc_status_t;



/**
 * @brief Send a mk_fc_status message
 *
 * @param rssi RC Control RSSI on FlightCtrl
 * @param batt Battery Voltage Level
 * @param gas Internally computed gas value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mk_fc_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, int16_t rssi, int16_t batt, int16_t gas)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_MK_FC_STATUS;

	i += put_int16_t_by_index(rssi, i, msg->payload); //RC Control RSSI on FlightCtrl
	i += put_int16_t_by_index(batt, i, msg->payload); //Battery Voltage Level
	i += put_int16_t_by_index(gas, i, msg->payload); //Internally computed gas value

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_mk_fc_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, int16_t rssi, int16_t batt, int16_t gas)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_MK_FC_STATUS;

	i += put_int16_t_by_index(rssi, i, msg->payload); //RC Control RSSI on FlightCtrl
	i += put_int16_t_by_index(batt, i, msg->payload); //Battery Voltage Level
	i += put_int16_t_by_index(gas, i, msg->payload); //Internally computed gas value

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, i);
}

static inline uint16_t mavlink_msg_mk_fc_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mk_fc_status_t* mk_fc_status)
{
	return mavlink_msg_mk_fc_status_pack(system_id, component_id, msg, mk_fc_status->rssi, mk_fc_status->batt, mk_fc_status->gas);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mk_fc_status_send(mavlink_channel_t chan, int16_t rssi, int16_t batt, int16_t gas)
{
	mavlink_message_t msg;
	mavlink_msg_mk_fc_status_pack_chan(mavlink_system.sysid, mavlink_system.compid, chan, &msg, rssi, batt, gas);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE MK_FC_STATUS UNPACKING

/**
 * @brief Get field rssi from mk_fc_status message
 *
 * @return RC Control RSSI on FlightCtrl
 */
static inline int16_t mavlink_msg_mk_fc_status_get_rssi(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload)[0];
	r.b[0] = (msg->payload)[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field batt from mk_fc_status message
 *
 * @return Battery Voltage Level
 */
static inline int16_t mavlink_msg_mk_fc_status_get_batt(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

/**
 * @brief Get field gas from mk_fc_status message
 *
 * @return Internally computed gas value
 */
static inline int16_t mavlink_msg_mk_fc_status_get_gas(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(int16_t)+sizeof(int16_t))[0];
	r.b[0] = (msg->payload+sizeof(int16_t)+sizeof(int16_t))[1];
	return (int16_t)r.s;
}

static inline void mavlink_msg_mk_fc_status_decode(const mavlink_message_t* msg, mavlink_mk_fc_status_t* mk_fc_status)
{
	mk_fc_status->rssi = mavlink_msg_mk_fc_status_get_rssi(msg);
	mk_fc_status->batt = mavlink_msg_mk_fc_status_get_batt(msg);
	mk_fc_status->gas = mavlink_msg_mk_fc_status_get_gas(msg);
}
