//Servo Motors :D

//THIS ISN'T THE FINAL PROGRAM IT'S LITERALLY JUST TO TEST THAT THEY ALL MOVE

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

//Leg One
Servo SRVO1; //Creates the SRVO1 servo
Servo SRVO2; //Creates the SRVO2 servo
Servo SRVO3; //Creates the SRVO3 servo
//Leg Two
Servo SRVO4; //Creates the SRVO4 servo
Servo SRVO5; //Creates the SRVO5 servo
Servo SRVO6; //Creates the SRVO6 servo
//Leg Three
Servo SRVO7; //Creates the SRVO7 servo
Servo SRVO8; //Creates the SRVO8 servo
Servo SRVO9; //Creates the SRVO9 servo
//Leg Four
Servo SRVO10; //Creates the SRVO10 servo
Servo SRVO11; //Creates the SRVO11 servo
Servo SRVO12; //Creates the SRVO12 servo
//Leg Five
Servo SRVO13; //Creates the SRVO13 servo
Servo SRVO14; //Creates the SRVO14 servo
Servo SRVO15; //Creates the SRVO15 servo
//Leg Six
Servo SRVO16; //Creates the SRVO16 servo
Servo SRVO17; //Creates the SRVO17 servo
Servo SRVO18; //Creates the SRVO18 servo
//Leg Seven
Servo SRVO19; //Creates the SRVO19 servo
Servo SRVO20; //Creates the SRVO20 servo
Servo SRVO21; //Creates the SRVO21 servo
//Leg Eight
Servo SRVO22; //Creates the SRVO22 servo
Servo SRVO23; //Creates the SRVO23 servo
Servo SRVO24; //Creates the SRVO24 servo

int pos = 0; //Variable used to store the servo position

void setup(){
    //Leg One
    SRVO1.attach(7);    //Attaches SRVO1 to pin 7
    SRVO2.attach(8);    //Attaches SRVO2 to pin 8
    SRVO3.attach(9);    //Attaches SRVO3 to pin 9
    //Leg Two
    SRVO4.attach(10);   //Attaches SRVO4 to pin 10
    SRVO5.attach(11);   //Attaches SRVO5 to pin 11
    SRVO6.attach(12);   //Attaches SRVO6 to pin 12
    //Leg Three
    SRVO7.attach(13);   //Attaches SRVO7 to pin 13
    SRVO8.attach(14);   //Attaches SRVO8 to pin 14
    SRVO9.attach(15);   //Attaches SRVO9 to pin 15
    //Leg Four
    SRVO10.attach(16);  //Attaches SRVO10 to pin 16
    SRVO11.attach(17);  //Attaches SRVO11 to pin 17
    SRVO12.attach(18);  //Attaches SRVO12 to pin 18
    //Leg Five
    SRVO13.attach(19);  //Attaches SRVO13 to pin 19
    SRVO14.attach(20);  //Attaches SRVO14 to pin 20
    SRVO15.attach(21);  //Attaches SRVO15 to pin 21
    //Leg Six
    SRVO16.attach(22);  //Attaches SRVO16 to pin 22
    SRVO17.attach(23);  //Attaches SRVO17 to pin 23
    SRVO18.attach(24);  //Attaches SRVO18 to pin 24
    //Leg Seven
    SRVO19.attach(25);  //Attaches SRVO19 to pin 25
    SRVO20.attach(26);  //Attaches SRV20 to pin 26
    SRVO21.attach(27);  //Attaches SRVO21 to pin 27
    //Leg Eight
    SRVO22.attach(28);  //Attaches SRVO22 to pin 28
    SRVO23.attach(29);  //Attaches SRVO23 to pin 29
    SRVO24.attach(30);  //Attaches SRVO24 to pin 30

    Serial.begin(9600);
}

void loop(){
    //Chat they wiggle

    //Leg One
    RotateRight (SRVO1, pos); //Makes SRVO1 rotate
    RotateLeft (SRVO1, pos); //Makes SRVO1 rotate

    RotateRight (SRVO2, pos); //Makes SRVO2 rotate
    RotateLeft (SRVO2, pos); //Makes SRVO2 rotate

    RotateRight (SRVO3, pos); //Makes SRVO3 rotate
    RotateLeft (SRVO3, pos); //Makes SRVO3 rotate


    //Leg Two
    RotateRight (SRVO4, pos); //Makes SRVO4 rotate
    RotateLeft (SRVO4, pos); //Makes SRVO4 rotate

    RotateRight (SRVO5, pos); //Makes SRVO5 rotate
    RotateLeft (SRVO5, pos); //Makes SRVO5 rotate

    RotateRight (SRVO6, pos); //Makes SRVO6 rotate
    RotateLeft (SRVO6, pos); //Makes SRVO6 rotate


    //Leg Three
    RotateRight (SRVO7, pos); //Makes SRVO7 rotate
    RotateLeft (SRVO7, pos); //Makes SRVO7 rotate

    RotateRight (SRVO8, pos); //Makes SRVO8 rotate
    RotateLeft (SRVO8, pos); //Makes SRVO8 rotate

    RotateRight (SRVO9, pos); //Makes SRVO9 rotate
    RotateLeft (SRVO9, pos); //Makes SRVO9 rotate


    //Leg Four
    RotateRight (SRVO10, pos); //Makes SRVO10 rotate
    RotateLeft (SRVO10, pos); //Makes SRVO10 rotate

    RotateRight (SRVO11, pos); //Makes SRVO11 rotate
    RotateLeft (SRVO11, pos); //Makes SRVO11 rotate

    RotateRight (SRVO12, pos); //Makes SRVO12 rotate
    RotateLeft (SRVO12, pos); //Makes SRVO12 rotate


    //Leg Five
    RotateRight (SRVO13, pos); //Makes SRVO13 rotate
    RotateLeft (SRVO13, pos); //Makes SRVO13 rotate

    RotateRight (SRVO14, pos); //Makes SRVO14 rotate
    RotateLeft (SRVO14, pos); //Makes SRVO14 rotate

    RotateRight (SRVO15, pos); //Makes SRVO15 rotate
    RotateLeft (SRVO15, pos); //Makes SRVO15 rotate


    //Leg Six
    RotateRight (SRVO16, pos); //Makes SRV16 rotate
    RotateLeft (SRVO16, pos); //Makes SRV16 rotate

    RotateRight (SRVO17, pos); //Makes SRVO17 rotate
    RotateLeft (SRVO17, pos); //Makes SRVO17 rotate

    RotateRight (SRVO18, pos); //Makes SRVO18 rotate
    RotateLeft (SRVO18, pos); //Makes SRVO18 rotate


    //Leg Seven
    RotateRight (SRVO19, pos); //Makes SRVO19 rotate
    RotateLeft (SRVO19, pos); //Makes SRVO19 rotate

    RotateRight (SRVO20, pos); //Makes SRVO20 rotate
    RotateLeft (SRVO20, pos); //Makes SRVO20 rotate

    RotateRight (SRVO21, pos); //Makes SRVO21 rotate
    RotateLeft (SRVO21, pos); //Makes SRVO21 rotate


    //Leg Eight
    RotateRight (SRVO22, pos); //Makes SRVO22 rotate
    RotateLeft (SRVO22, pos); //Makes SRVO22 rotate

    RotateRight (SRVO23, pos); //Makes SRVO23 rotate
    RotateLeft (SRVO23, pos); //Makes SRVO23 rotate

    RotateRight (SRVO24, pos); //Makes SRVO24 rotate
    RotateLeft (SRVO24, pos); //Makes SRVO24 rotate

    //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
}