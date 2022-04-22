/********************************************************************************/
/*   Author  : Ahmed Farag                                                      */
/*   Date    : 22/04/2022                                                       */
/*   Version : V01                                                              */
/********************************************************************************/

//Includes
#include <Arduino.h>
#include <Votol.h>

int Potentiometer_Readings = 0 ;
 
void setup() {

  Votol_Init();
  pinMode(POTENTIOMETER_PIN_NUMBER, INPUT);




}

void loop() {

Potentiometer_Readings = Get_Potentiometer_Readings(POTENTIOMETER_PIN_NUMBER);
Votol_Forward(Potentiometer_Readings , THROTTLE_FORWARD_PIN ,THROTTLE_MIN_READINGS , THROTTLE_MAX_READINGS ,THROTTLE_MIN_PWM ,THROTTLE_MAX_PWM );

}

   