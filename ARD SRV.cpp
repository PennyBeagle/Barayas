//Servo Motors :D

#include <Servo.h> //Library for Servos on Arduino

void RotateRight (Servo prototype, int pos){
    //SRVO movement
    for (pos = 0; pos <= 180; pos += 1){ //Moves 1 degree every time the loop cycles
      prototype.write(pos); //Pos1 changes within the for loop, and this command tells the servo to move to that position
      delay(10); //A 10 ms delay
    }
}

void RotateLeft (Servo prototype, int pos){
    //SRVO movement
    for (pos = 180; pos >= 0; pos -= 1){ //Moves 1 degree every time the loop cycles
      prototype.write(pos); //Pos1 changes within the for loop, and this command tells the servo to move to that position
      delay(10); //A 10 ms delay
    }
}

//Variable definitions
Servo SRVO1; //Creates the SRVO1 servo
Servo SRVO2; //Creates the SRVO2 servo
Servo SRVO3; //Creates the SRVO3 servo
Servo SRVO4; //Creates the SRVO4 servo

int pos = 0; //Variable used to store the servo position

void setup(){
    Serial.begin(9600);
    SRVO1.attach(7);    //Attaches SRVO1 to pin 7
    SRVO2.attach(8);    //Attaches SRVO2 to pin 8
    SRVO3.attach(9);    //Attaches SRVO3 to pin 9
    SRVO4.attach(10);   //Attaches SRVO4 to pin 10
}

void loop(){
    //The first function call makes the servo turn from 0 degrees to 180 degrees

    RotateRight (SRVO1, pos); //Makes SRVO1 rotate
    RotateRight (SRVO2, pos); //Makes SRVO2 rotate
    RotateRight (SRVO3, pos); //Makes SRVO3 rotate
    RotateRight (SRVO4, pos); //Makes SRVO4 rotate

    //The second function call moves it from 180 degrees to 0 degrees

    RotateLeft (SRVO1, pos); //Makes SRVO1 rotate
    RotateLeft (SRVO2, pos); //Makes SRVO2 rotate
    RotateLeft (SRVO3, pos); //Makes SRVO3 rotate
    RotateLeft (SRVO4, pos); //Makes SRVO4 rotate

    delay (1000);

    //I'll adjust this to be more precise as we need, but this should get the servo to move around a lil
}