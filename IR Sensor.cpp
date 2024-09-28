//IR Sensor

//Variable definitions
const int LED = 3; //LED is on pin 3
const int IR = 4; //IR Sensor is on pin 4

void setup(){

    Serial.begin(9600); //Opens serial port & sets data rate to 9600 bps

    pinMode(LED, OUTPUT); //Sets LED as the output
    pinMode(IR, INPUT); //Sets IR Sensor as the input
}

void loop(){
    int thing = digitalRead(IR); //Thing is equal to the current state of the IR Sensor

    if (thing == LOW) {
        digitalWrite(LED, HIGH); //Turns the LED on
    }

    else {
        digitalWrite(LED, LOW); //Turns the LED off
    }

    delay(1000); //Delay to prevent inputs stacking up. Yippee!
}