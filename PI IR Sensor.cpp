//IR Sensor :D

//Variable definitions
const int IR = 4; //IR Sensor is on pin 4

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Opens serial port & sets data rate to 9600 bps
  pinMode(IR, INPUT); //Sets IR Sensor as the input
}

void loop() {
  // put your main code here, to run repeatedly:
  int thing = digitalRead(IR); //Thing is equal to the current state of the IR Sensor

    if (thing == LOW) {
        Serial.println(thing); //Gives an indicator that this works
    }

    else {
        Serial.println(thing); //Gives an indicator that this works
    }

    delay(1000); //Delay to prevent inputs stacking up. Yippee!
}