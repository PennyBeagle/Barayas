//Servo Motors :D

#include <Servo.h> //Library for Servos on Arduino
#include "ARD SRV.hpp"

void setup(){
    Serial.begin(9600);
    SRVO1.attach(7);    //Attaches SRVO1 to pin 7
    SRVO2.attach(8);    //Attaches SRVO2 to pin 8
    SRVO3.attach(9);    //Attaches SRVO3 to pin 9
    SRVO4.attach(10);   //Attaches SRVO4 to pin 10
}

void loop(){
    //The first for loop makes the servo turn from 0 degrees to 180 degrees

    //SRVO 1
    for (pos1 = 0; pos1 <= 180; pos1 += 1){ //Moves 1 degree every time the loop cycles
      SRVO1.write(pos1); //Pos1 changes within the for loop, and this command tells the servo to move to that position
      delay(10); //A 10 ms delay
    }

    //SRVO 2
    for (pos2 = 0; pos2 <= 180; pos2 += 1){ //Moves 1 degree every time the loop cycles
      SRVO2.write(pos2); //Pos2 changes within the for loop, and this command tells the servo to move to that position
      delay(10); //A 10 ms delay
    }

    //SRVO 3
    for (pos3 = 0; pos3 <= 180; pos3 += 1){ //Moves 1 degree every time the loop cycles
      SRVO3.write(pos3); //Pos3 changes within the for loop, and this command tells the servo to move to that position
      delay(10); //A 10 ms delay
    }

    //SRVO 4
    for (pos4 = 0; pos4 <= 180; pos4 += 1){ //Moves 1 degree every time the loop cycles
      SRVO4.write(pos4); //Pos4 changes within the for loop, and this command tells the servo to move to that position
      delay(10); //A 10 ms delay
    }



    //The second moves it from 180 degrees to 0 degrees.

    //SRVO 1
    for (pos1 = 180; pos1 >= 0; pos1 -= 1){
      SRVO1.write(pos1);
      delay(10);
    }

    //SRVO 2
    for (pos2 = 180; pos2 >= 0; pos2 -= 1){
      SRVO2.write(pos2);
      delay(10);
    }

    //SRVO 3
    for (pos3 = 180; pos3 >= 0; pos3 -= 1){
      SRVO3.write(pos2);
      delay(10);
    }

    //SRVO 4
    for (pos4 = 180; pos4 >= 0; pos4 -= 1){
      SRVO4.write(pos4);
      delay(10);
    }

    delay (1000);

    //I'll adjust this to be more precise as we need, but this should get the servo to move around a lil
}