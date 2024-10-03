//Servo Motors :D

#include <Servo.h> //Library for Servos on Arduino

//Variable definitions
Servo SRVO; //Creates the SRVO servo

int position = 0; //Variable used to store the servo position

void setup(){
    Serial.begin(9600);
    SRVO.attach(7); //Attaches servo to pin 7 of the SRVO servo
}

void loop(){
    //The first for loop makes the servo turn from 0 degrees to 180 degrees
    //The second moves it from 180 degrees to 0 degrees.

    for (position = 0; position <= 180; position += 1){ //Moves 1 degree every time the loop cycles
      SRVO.write(position); //Position changes within the for loop, and this command tells the servo to move to that position
      delay(10); //A 10 ms delay
    }

    for (position = 180; position >= 0; position -= 1){
      SRVO.write(position);
      delay(10);
    }

    delay (1000);

    //I'll adjust this to be more precise as we need, but this should get the servo to move around a lil
}