#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver srituhobby = Adafruit_PWMServoDriver();

#define servoMIN 125 //Start value of motor
#define servoMAX 625 //End value of motor

const int one = 24; //Defining one as pin 24 (LA)
const int two = 25; //Defining two as pin 25 (LA)

int worm = 0; //on & off button

void setup() { //Sets up the driver library 
  Serial.begin(9600);
  srituhobby.begin();
  srituhobby.setPWMFreq(60);

  pinMode(one, OUTPUT); //One is now an output (LA)
  pinMode(two, OUTPUT); //Two is now an output (LA)

  pinMode(22, INPUT); //on & off button
}

void loop() {
    worm = digitalRead(22); //on & off button
    delay (4000); //4 second delay

    while (worm == 1){
  //SERVO STUFF
  for (int servo = 0; servo < 3; servo++ ) { //Begins at servo 0, goes until servo 2
    for (int i = 0; i < servoMIN; i+= 50){
        srituhobby.setPWM(servo, 0, i); //Writes servo # to value servoMIN
        delay(200); //0.2 second delay
    }
  }

  for (int servo = 2; servo >= 0; servo-- ) { //Begins at servo 2, goes until servo 0
    for (int i = 0; i < servoMAX; i+= 50){
        srituhobby.setPWM(servo, 0, i); //Writes servo # to value servoMAX
        delay(200); //0.2 second delay
    }
  }

    //THIS IS ALL LA STUFF
      //Extension - This is just an initial setup. If one = Low and two = High, the LA extends
      digitalWrite(one, LOW);
      digitalWrite(two, HIGH);
  
      delay(5000); //We are indeed chilling
  
      //Stop - If both one and two = High, the LA stops moving
      digitalWrite(one, HIGH);
      digitalWrite(two, HIGH);
  
      delay(2000); //Again. Chillin'
  
      //Retraction - If one = High and two = Low, the LA retracts
      digitalWrite(one, HIGH);
      digitalWrite(two, LOW);
  
      delay(5000); //Wow we do use these delays a lot don't we
  
      //Stop - You get the gist
      digitalWrite(one, HIGH);
      digitalWrite(two, HIGH);
  
      delay(2000);
}
}