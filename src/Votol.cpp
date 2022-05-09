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
    // Set the PWM pin for the throttle to output
      pinMode(THROTTLE_FORWARD_PIN, OUTPUT);
    // Set the reverse pin switch to output 
      pinMode(REVERSE_DIRECTION_SWITCH, OUTPUT);
    // Set the High break pin switch to output 
      pinMode(HIGH_BREAK_PIN, OUTPUT);
    // Set the potentiometer pin to input
      pinMode(POTENTIOMETER_PIN_NUMBER, INPUT);
    // Set the spedometer pin to input
    //pinMode(SPEDOMETER_PIN, INPUT);
    
      
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

// Function to move the motor backward with PWM maped from Potentiometer values
void Votol_Reverse(int Throttle_Pin , int Potentiometer_Readings , int Throttle_Min_Readings, int Throttle_Max_Readings, int Throttle_Min_PWM ,int Throttle_Max_PWM,int Reverse_Switch_Pin)
{
    // Set reverse switch on 
    digitalWrite(Reverse_Switch_Pin,HIGH);

    int Throttle_PWM_Value_Rev = map(Potentiometer_Readings,Throttle_Max_Readings,Throttle_Min_Readings,Throttle_Max_PWM,Throttle_Min_PWM);
    analogWrite(Throttle_Pin, Throttle_PWM_Value_Rev);
}

// Function to activate the high break 
void Votol_Break(int Break_Pin , int State)
{
    digitalWrite(Break_Pin,State);
}

// Function for speedo meter for feedback
// int  Votol_Speedometer(int Sedometer_Pin , int Mode)
// {
  
//   unsigned long Duration_In_Micro = pulseIn(Sedometer_Pin , Mode);

  
//   if(Duration_In_Micro > 1)
//   {
//   Serial.println(Duration_In_Micro); 
//   delay(1000);
//   }
   
// }