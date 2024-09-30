//Force Sensing Resistor (with GPIO commands to help Raspberry Pi?) :D

#include <wiringPi.h> //Library for C++ on Raspberry Pi (deals with GPIO's)

//Variable definitions
const int FSR = 5; //FSR is on pin 5
int val = 0; //Variable to store the read values

void setup(){
    GPIO.setmode(GPIO.BCM); //Sets the GPIO pins to BCM mode
    GPIO.pinMode(FSR, GPIO.INPUT); //Sets FSR as the input (detects the force being applied)
    
    digitalWrite(FSR, GPIO.HIGH); //Initializes FSR as Low
}

void loop(){
    int Base = 0; //Base variable to determine if pressure is being applied
    val = digitalRead(FSR); //Reads the FSR (input)
    
    if((Base == LOW) && (FSR == HIGH)){
        //Prints message if last reading was low and current reading is high (pressure is being applied)
        Serial.print("Pressure is being applied.");
    }
    Base = Read;

    delay(1000); //One second delay :3
}