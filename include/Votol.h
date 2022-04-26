/********************************************************************************/
/*   Author  : Ahmed Farag                                                      */
/*   Date    : 22/04/2022                                                       */
/*   Version : V01                                                              */
/********************************************************************************/

#ifndef _Votol_H
#define _Votol_H

// Transistors Pin number 

#define POTENTIOMETER_PIN_NUMBER 14
#define REVERSE_PIN_SWITCH       41
#define HIGH_BREAK_PIN           13
#define HIGH_BREAK_OFF_STATE     0
#define HIGH_BREAK_ON_STATE      1


// Forward motor driver parameters

#define THROTTLE_FORWARD_PIN   2
#define THROTTLE_MIN_PWM       60
#define THROTTLE_MAX_PWM       200
#define THROTTLE_MIN_READINGS  0
#define THROTTLE_MAX_READINGS  600


// REVERSE motor driver parameters

#define THROTTLE_REVERSE_PIN             2
#define THROTTLE_MIN_PWM_REVERSE        -200
#define THROTTLE_MAX_PWM_REVERSE        -60
#define THROTTLE_MIN_READINGS_REVERSE   -600
#define THROTTLE_MAX_READINGS_REVERSE    0





// Functions Prototype

void Votol_Init();
int  Get_Potentiometer_Readings (int Potentiometer_Pin_Num) ;
void Votol_Forward (int Throttle_Pin , int Potentiometer_Readings , int Throttle_Min_Readings, int Throttle_Max_Readings, int Throttle_Min_PWM ,int Throttle_Max_PWM );
void Votol_Reverse(int Throttle_Pin , int Potentiometer_Readings , int Throttle_Min_Readings, int Throttle_Max_Readings, int Throttle_Min_PWM ,int Throttle_Max_PWM, int Reverse_Switch_Pin);
void Votol_Break(int Break_Pin , int State);
int  Votol_Speedometer();




#endif