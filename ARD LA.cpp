//Linear Actuator :D

//Variable definitions
const int one = 24; //Defining one as pin 24
const int two = 25; //Defining two as pin 25

void setup(){
    pinMode(one, OUTPUT); //One is now an output
    pinMode(two, OUTPUT); //Two is now an output

    Serial.begin (9600);
}

void loop (){
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