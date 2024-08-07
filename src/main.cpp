#include <Arduino.h>
#include <stdint.h>

#include <DRV8835MotorShield.h>
#include "Sensors/accelerometer.h"
#include "Sensors/ultrasonicSensor.h"

#define MOTOR_SHIELD_MODE   13U
#define MOTOR_SHIELD_M1_DIR 12U
#define MOTOR_SHIELD_M1_PWM 11U
#define MOTOR_SHIELD_M2_DIR 10U
#define MOTOR_SHIELD_M2_PWM 9U

#define MOTOR_DEFAULT_SPEED 200U

DRV8835MotorShield motors( MOTOR_SHIELD_M1_DIR, 
                           MOTOR_SHIELD_M1_PWM, 
                           MOTOR_SHIELD_M2_DIR, 
                           MOTOR_SHIELD_M2_PWM );

void driveForward( void );

void setup() 
{
  Serial.begin(9600);

  accelerometerInit();
  ultrasonicSensorInit();

  /* motor shield */
  pinMode( MOTOR_SHIELD_MODE, OUTPUT );
  digitalWrite( MOTOR_SHIELD_MODE, HIGH );
}

void loop() 
{
  accelerometerCycle();
  ultrasonicSensorCycle();

  // Serial.print( "Left: " );
  // Serial.print( ultrasonicSensorData.left_f32 );
  // Serial.print( " cm | Front: ");
  // Serial.print( ultrasonicSensorData.front_f32 );
  // Serial.print( " cm | Right: " );
  // Serial.print( ultrasonicSensorData.right_f32 );
  // Serial.print( " cm | " );
  Serial.print( accelerometerData.x_axis.value_f32 );
  Serial.print( " | " );
  Serial.print( accelerometerData.y_axis.value_f32 );
  Serial.print( " | " );
  Serial.print( accelerometerData.z_axis.value_f32 );
  Serial.print( " | " );
  Serial.print( accelerometerData.x_axis.offset_f32 );
  Serial.print( " | " );
  Serial.print( accelerometerData.y_axis.offset_f32 );
  Serial.print( " | " );
  Serial.print( accelerometerData.z_axis.offset_f32 );
  Serial.print( " | " );



  driveForward();
}

void driveForward( void )
{
  int16_t leftMotorSpeed_s16 = MOTOR_DEFAULT_SPEED;
  int16_t rightMotorSpeed_s16 = MOTOR_DEFAULT_SPEED;


  if ( accelerometerData.y_axis.value_f32 > 0.06F )
  {
    leftMotorSpeed_s16 += 15;
  }
  else if ( accelerometerData.y_axis.value_f32 < -0.06F )
  {
    rightMotorSpeed_s16 += 15;
  }

  Serial.print( " | Speed: " );
  Serial.print( leftMotorSpeed_s16 );
  Serial.print( " | " );
  Serial.println( rightMotorSpeed_s16 );

  motors.setM1Speed( rightMotorSpeed_s16 ); // prawy
  motors.setM2Speed( leftMotorSpeed_s16 ); // lewy
}