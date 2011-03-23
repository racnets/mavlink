/** @file
 *	@brief MAVLink comm protocol.
 *	@see http://pixhawk.ethz.ch/software/mavlink
 *	 Generated on Wednesday, March 23 2011, 12:39 UTC
 */
#ifndef HUCH_H
#define HUCH_H

#ifdef __cplusplus
extern "C" {
#endif


#include "../protocol.h"

#define MAVLINK_ENABLED_HUCH


#include "../common/common.h"
// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 0
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 0
#endif

// ENUM DEFINITIONS


// MESSAGE DEFINITIONS

#include "./mavlink_msg_mk_debugout.h"
#include "./mavlink_msg_mk_extern_control.h"
#include "./mavlink_msg_huch_exp_ctrl.h"
#include "./mavlink_msg_huch_attitude.h"
#include "./mavlink_msg_huch_fc_altitude.h"
#include "./mavlink_msg_huch_ranger.h"
#include "./mavlink_msg_huch_exp_ctrl_rx.h"
#include "./mavlink_msg_mk_fc_status.h"
#include "./mavlink_msg_huch_ctrl_hover_state.h"
#include "./mavlink_msg_huch_imu_raw_adc.h"
#include "./mavlink_msg_huch_mk_imu.h"
#include "./mavlink_msg_huch_raw_pressure.h"
#include "./mavlink_msg_huch_altitude.h"
#include "./mavlink_msg_huch_temperature.h"
#include "./mavlink_msg_huch_magnetic_kompass.h"
#include "./mavlink_msg_huch_distance.h"
#ifdef __cplusplus
}
#endif
#endif
