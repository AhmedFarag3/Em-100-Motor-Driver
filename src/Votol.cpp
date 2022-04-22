/********************************************************************************/
/*   Author  : Ahmed Farag                                                      */
/*   Date    : 22/04/2022                                                       */
/*   Version : V01                                                              */
/********************************************************************************/
#include <Arduino.h>
#include <Votol.h>

//Intitialization function 
void Votol_Init()
{
      pinMode(THROTTLE_FORWARD_PIN, OUTPUT);
}

// Function to get the Potentiomete readings
int  Get_Potentiometer_Readings (int Potentiometer_Pin_Num)
{
    int Potentiometer_Readings = analogRead(Potentiometer_Pin_Num);
    return Potentiometer_Readings ;
}

// Function to move the motor forward with PWM maped from Potentiometer values
void Votol_Forward (int Potentiometer_Readings  , int Throttle_Pin  , int Throttle_Min_Readings, int Throttle_Max_Readings, int Throttle_Min_PWM ,int Throttle_Max_PWM )
{
    int Throttle_PWM_Value = map(Potentiometer_Readings,Throttle_Min_Readings,Throttle_Max_Readings,Throttle_Min_PWM,Throttle_Max_PWM);
    analogWrite(Throttle_Pin, Throttle_PWM_Value);

}

