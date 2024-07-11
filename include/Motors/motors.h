#ifndef MOTORS_H
#define MOTORS_H

/*===============================*/
/* Includes                      */
/*===============================*/

#include "Utils/calmanFilter.h"

/*===============================*/
/* Pins connfiguration           */
/*===============================*/

#define MOTOR_SHIELD_MODE   13U
#define MOTOR_SHIELD_M1_DIR 12U
#define MOTOR_SHIELD_M1_PWM 11U
#define MOTOR_SHIELD_M2_DIR 10U
#define MOTOR_SHIELD_M2_PWM 9U

/*===============================*/
/* Constant values               */
/*===============================*/

#define MOTOR_SPEED_DEFAULT 100
#define MOTOR_SPEED_STOPPED 0

#define DIST_SIDE_MIN 7.0F
#define DIST_SIDE_MAX 20.0F
#define DIST_SIDE_OFFSET 0.5F

#define SPEED_EQUATION_A 66.667F
#define SPEED_EQUATION_B 33.334F

/*===============================*/
/* Types definitions             */
/*===============================*/

typedef enum motorsJob_tag
{
    AWAIT = 0U,
    FOLLOW_LEFT_WALL,
    FOLLOW_RIGHT_WALL,
    TURN_LEFT,
    TUNR_RIGHT
}motorsJob_t;

/*===============================*/
/* Global data                   */
/*===============================*/

/*===============================*/
/* Global functions declarations */
/*===============================*/

void motorsInit( void );

void motorsCycle( void );

#endif