//IR Sensor (with GPIO commands to help Raspberry Pi?)

#include <wiringPi.h> //Library for C++ on Raspberry Pi (deals with GPIO's)

//Variable definitions
const int LED = 3; //LED is on pin 3
const int IR = 4; //IR Sensor is on pin 4

//If this thing doesn't work change the "pinMode" to "setup" and the "GPIO.INPUT"/"GPIO.OUTPUT" to "GPIO.IN"/"GPIO.OUT"
void setup(){

    Serial.begin(9600); //Opens serial port & sets data rate to 9600 bps

    GPIO.pinMode(LED, GPIO.OUTPUT); //Sets LED as the output
    GPIO.pinMode(IR, GPIO.INPUT); //Sets IR Sensor as the input
}

void loop(){
    int thing = digitalRead(IR); //Thing is equal to the current state of the IR Sensor

    if (thing == GPIO.LOW) {
        digitalWrite(LED, GPIO.HIGH); //Turns the LED on
    }

    else {
        digitalWrite(LED, GPIO.LOW); //Turns the LED off
    }

    delay(1000); //Delay to prevent inputs stacking up. Yippee!
}