//Force Sensing Resistor :D

//Variable definitions
const int FSR = 5; //FSR is on pin 5
int val = 0; //Variable to store the read values

void setup(){
    setmode(BCM); //Sets the GPIO pins to BCM mode
    pinMode(FSR, INPUT); //Sets FSR as the input (detects the force being applied)
    
    digitalWrite(FSR, HIGH); //Initializes FSR as Low
}

void loop(){
    int Base = 0; //Base variable to determine if pressure is being applied
    val = digitalRead(FSR); //Reads the FSR (input)
    
    if((Base == LOW) && (FSR == HIGH)){
        //Prints message if last reading was low and current reading is high (pressure is being applied)
        Serial.println("Pressure is being applied.");
    }
    Base = FSR;

    delay(1000); //One second delay :3
}