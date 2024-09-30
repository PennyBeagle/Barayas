//Linear Actuator (with GPIO commands to help Raspberry Pi?) :D

#include <wiringPi.h> //Library for C++ on Raspberry Pi (deals with GPIO's)

//Variable definitions
const int 1 = 1; //Defining pin 1
const int 2 = 2; //Defining pin 2

void setup(){
    GPIO.pinMode(1, GPIO.OUTPUT); //Pin 1 is now an output
    GPIO.pinMode(2, GPIO.OUTPUT); //Pin 2 is now an output

    digitalWrite(1, GPIO.HIGH); //Initializes pin 1 as Low
    digitalWrite(2, GPIO.HIGH); //Initializes pin 2 as Low
}

void(loop){
    //Extension - This is just an initial setup. If 1 = Low and 2 = High, the LA extends
    digitalWrite(1, GPIO.LOW);
    digitalWrite(2, GPIO.HIGH);

    delay(1000); //We are indeed chilling

    //Stop - If both 1 and 2 = High, the LA stops moving
    digitalWrite(1, GPIO.HIGH);
    digitalWrite(2, GPIO.HIGH);

    delay(1000); //Again. Chillin'

    //Retraction - If 1 = High and 2 = Low, the LA retracts
    digitalWrite(1, GPIO.HIGH);
    digitalWrite(2, GPIO.LOW);

    delay(1000); //Wow we do use these delays a lot don't we

    //Stop - You get the gist
    digitalWrite(1, GPIO.HIGH);
    digitalWrite(2, GPIO.HIGH);

    delay(1000);
}