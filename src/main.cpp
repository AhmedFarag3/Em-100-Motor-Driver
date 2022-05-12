/********************************************************************************/
/*   Author  : Ahmed Farag                                                      */
/*   Date    : 22/04/2022                                                       */
/*   Version : V01                                                              */
/********************************************************************************/

// Includes
#include <Arduino.h>
#include <Votol.h>

int Potentiometer_Readings = 0;

void setup()
{

  Votol_Init();

  Serial.begin(9600);
}

char c;
void loop()
{

  if (Serial.available())
  {
    c = Serial.read();
    Serial.println(c);
  }
  if (c == 'F')
  {

    Potentiometer_Readings = Get_Potentiometer_Readings(POTENTIOMETER_PIN_NUMBER);
    Serial.print("Forward: ");
    

    Votol_Break(HIGH_BREAK_PIN,HIGH_BREAK_OFF_STATE);
    Votol_Forward(Potentiometer_Readings, THROTTLE_FORWARD_PIN, THROTTLE_MIN_READINGS, THROTTLE_MAX_READINGS, THROTTLE_MIN_PWM, THROTTLE_MAX_PWM);
  }
  if (c == 'R')
  {
    Potentiometer_Readings = Get_Potentiometer_Readings(POTENTIOMETER_PIN_NUMBER);
    Serial.print("Reverse: ");
    

    Votol_Break(HIGH_BREAK_PIN, HIGH_BREAK_OFF_STATE);
    // In this function call we will pass the arguments of the function as same as the forward since we are not using slider throttle with negative values
    Votol_Reverse(Potentiometer_Readings, THROTTLE_FORWARD_PIN, THROTTLE_MIN_READINGS, THROTTLE_MAX_READINGS, THROTTLE_MIN_PWM, THROTTLE_MAX_PWM, REVERSE_DIRECTION_SWITCH);
  }
  if (c == 'B')
  {
    Serial.println("Break");

    Votol_Break(HIGH_BREAK_PIN, HIGH_BREAK_ON_STATE);
  }
}

