/********************************************************************************/
/*   Author  : Ahmed Farag                                                      */
/*   Date    : 22/04/2022                                                       */
/*   Version : V01                                                              */
/********************************************************************************/

#ifndef _Votol_H
#define _Votol_H

// Potentiometer Parameters definition 

#define POTENTIOMETER_PIN_NUMBER 14

// Forward motor driver parameters

#define THROTTLE_FORWARD_PIN   2
#define THROTTLE_MIN_PWM       60
#define THROTTLE_MAX_PWM       200
#define THROTTLE_MIN_READINGS  0
#define THROTTLE_MAX_READINGS  600























// Functions Prototype

void Votol_Init();
int  Get_Potentiometer_Readings (int Potentiometer_Pin_Num) ;
void Votol_Forward (int Throttle_Pin , int Potentiometer_Readings , int Throttle_Min_Readings, int Throttle_Max_Readings, int Throttle_Min_PWM ,int Throttle_Max_PWM );
void Votol_Backward();
void Votol_Regenerative_Break();
int  Votol_Speedometer();













#endif