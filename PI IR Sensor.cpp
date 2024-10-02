//IR Sensor (with GPIO commands to help Raspberry Pi?) :D

#include <wiringPi.h> //Library for C++ on Raspberry Pi (deals with GPIO's)

//Variable definitions
const int IR = 4; //IR Sensor is on pin 4

//If this thing doesn't work change the "pinMode" to "setup" and the "GPIO.INPUT"/"GPIO.OUTPUT" to "GPIO.IN"/"GPIO.OUT"
void setup(){
    Serial.begin(9600); //Opens serial port & sets data rate to 9600 bps
    GPIO.pinMode(IR, GPIO.INPUT); //Sets IR Sensor as the input
}

void loop(){
    int thing = digitalRead(IR); //Thing is equal to the current state of the IR Sensor

    if (thing == GPIO.LOW) {
        Serial.println(thing); //Prints the value. Gives an indicator that this works
    }

    else {
        Serial.println(thing); //Prints the value. Gives an indicator that this doesn't work
    }

    delay(1000); //Delay to prevent inputs stacking up. Yippee!
}