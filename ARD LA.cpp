//Linear Actuator :D

//Variable definitions
const int one = 1; //Defining one as pin 1
const int two = 2; //Defining two as pin 2

void setup(){
    pinMode(one, OUTPUT); //Pin 1 is now an output
    pinMode(two, OUTPUT); //Pin 2 is now an output

    Serial.println(one, HIGH); //Initializes pin 1 as Low
    Serial.println(two, HIGH); //Initializes pin 2 as Low
}

void loop (){
    //Extension - This is just an initial setup. If one = Low and two = High, the LA extends
    Serial.println(one, LOW);
    Serial.println(two, HIGH);

    delay(1000); //We are indeed chilling

    //Stop - If both one and two = High, the LA stops moving
    Serial.println(one, HIGH);
    Serial.println(two, HIGH);

    delay(1000); //Again. Chillin'

    //Retraction - If one = High and two = Low, the LA retracts
    Serial.println(one, HIGH);
    Serial.println(two, LOW);

    delay(1000); //Wow we do use these delays a lot don't we

    //Stop - You get the gist
    Serial.println(one, HIGH);
    Serial.println(two, HIGH);

    delay(1000);
}