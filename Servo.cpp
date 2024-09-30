//Servo Motors :D

#include <wiringPi.h> //Library for C++ on Raspberry Pi (deals with GPIO's)
#include <softPwm.h> //Library for PWM pins (to control the Servo easier)

//Variable definitions
const int Servo = 0; //Servo is on pin 0

void setup(){
    Serial.begin(9600);

    wiringPiSetup(); //Initializes wiringPi
    pinMode(Servo, OUTPUT); //Sets Servo as the output
    softPwmCreate(Servo, 0, 180); //Creates the softPwm pin, sets the initial value to 0 with a range of 180
}

void loop(){
    //Since the range of softPwm is from 180, then 1 = 0 degrees, 90 = 90 degrees, and 180 = 180 degrees. Theorhetically.

    softPwmWrite(Servo, 90); //90 degrees
    delay(1000); //I really love my delays don't I
    softPwmWrite(Servo, 0); //0 degrees
    delay(1000);
    softPwmWrite(Servo, 180); //180 degrees
    delay(1000);
}