//Linear Actuator

void setup(){
    GPIO.pinMode(1, GPIO.OUTPUT); //Pin 1 is now an output
    GPIO.pinMode(2, GPIO.OUTPUT); //Pin 2 is now an output

    digitalWrite(1, GPIO.HIGH); //Sets pin 1 to Low
    digitalWrite(2, GPIO.HIGH); //Sets pin 2 to Low
}

void(loop){
    //Extension - This is just an initial setup. If 1 = Low and 2 = High, the LA extends
    digitalWrite(1, GPIO.LOW);
    digitalWrite(2, GPIO.HIGH);

    delay(1000); //We are indeed chilling

    //Stop - If both 1 and 2 = High, the LA stops moving
    digitalWrite(1, GPIO.HIGH);
    digitalWrite(2, GPIO.HIGH);

    delay(1000); //Again. Chillin'

    //Retraction - If 1 = High and 2 = Low, the LA retracts
    digitalWrite(1, GPIO.HIGH);
    digitalWrite(2, GPIO.LOW);

    delay(1000); //Wow we do use these delays a lot don't we

    //Stop - You get the gist
    digitalWrite(1, GPIO.HIGH);
    digitalWrite(2, GPIO.HIGH);

    delay(1000);
}