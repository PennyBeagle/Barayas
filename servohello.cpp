#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver srituhobby = Adafruit_PWMServoDriver();

#define servoMIN 125  //Start value of motor
#define servoMAX 625  //End value of motor

int worm = 0;  //on & off button

void setup() {  //Sets up the driver library
  Serial.begin(9600);
  srituhobby.begin();
  srituhobby.setPWMFreq(60);

  pinMode(43, INPUT);  //on & off button
}

void loop() {
  worm = digitalRead(43);  //on & off button
  delay(4000);             //4 second delay

  while (worm == 1) {
    //SERVO STUFF
    for (int servo = 2; servo >= 0; servo--) {  //Begins at servo 2, goes until servo 0
      for (int i = servoMIN; i < servoMAX; i += 3) {
        srituhobby.setPWM(servo, 0, i);  //Writes servo # to value servoMAX
        delay(5);                       //0.2 second delay
      }
    }

    for (int servo = 0; servo < 3; servo++) {  //Begins at servo 0, goes until servo 2
      for (int i = servoMAX; i > servoMIN; i -= 3) {
        srituhobby.setPWM(servo, 0, i);  //Writes servo # to value servoMIN
        delay(5);                       //0.2 second delay
      }
    }

    worm = digitalRead(43);  //on & off button
  }
}