#include "ARDpinnum.hpp"

void extend (int a, int b); //Extend Function Prototype
void retract (int c, int d); //Retract Function Prototype
void stop (int e, int f); //Stop Function Prototype

void setup(){
    pinMode(one, OUTPUT); //One is now an output
    pinMode(two, OUTPUT); //Two is now an output

    pinMode(three, OUTPUT); //Three is now an output
    pinMode(four, OUTPUT); //Four is now an output

    pinMode(five, OUTPUT); //Five is now an output
    pinMode(six, OUTPUT); //Six is now an output

    pinMode(seven, OUTPUT); //Seven is now an output
    pinMode(eight, OUTPUT); //Eight is now an output
    
    pinMode(nine, OUTPUT); //Nine is now an output
    pinMode(ten, OUTPUT); //Ten is now an output

    pinMode(eleven, OUTPUT); //Eleven is now an output
    pinMode(twelve, OUTPUT); //Twelve is now an output

    pinMode(thirteen, OUTPUT); //Thirteen is now an output
    pinMode(fourteen, OUTPUT); //Fourteen is now an output

    pinMode(fifteen, OUTPUT); //Fifteen is now an output
    pinMode(sixteen, OUTPUT); //Sixteen is now an output    

    Serial.begin (9600);
}

void loop (){
if (Serial.available() > 0){
    conn = Serial.read(); //Read connection variable
    }

    switch(conn){
        case(1): { //Walk
            //GROUP ONE: 1 (one, two), 3 (five, six), 5 (nine, ten), 7 (thirteen, fourteen)

            //Extension - (1, 3, 5, 7)
            extend(one, two);
            extend(five, six);
            extend(nine, ten);
            extend(thirteen, fourteen);
            delay(1000);
            
            //Stopping - (1, 3, 5, 7)
            stop(one, two);
            stop(five, six);
            stop(nine, ten);
            stop(thirteen, fourteen);
            delay(1000);

            //Retracting - (1, 3, 5, 7)
            retract(one, two);
            retract(five, six);
            retract(nine, ten);
            retract(thirteen, fourteen);
            delay(1000);

            //GROUP TWO: 2 (three, four), 4 (seven, eight), 6 (eleven, twelve), 8 (thirteen, fourteen)

            //Extension - (2, 4, 6, 8)
            extend(three, four);
            extend(seven, eight);
            extend(eleven, twelve);
            extend(fifteen, sixteen);
            delay(1000);
            
            //Stopping - (2, 4, 6, 8)
            stop(three, four);
            stop(seven, eight);
            stop(eleven, twelve);
            stop(fifteen, sixteen);
            delay(1000);

            //Retracting - (2, 4, 6, 8)
            retract(three, four);
            retract(seven, eight);
            retract(eleven, twelve);
            retract(fifteen, sixteen);
            delay(1000);

            break;
            } //Ends case 1

        case (0): { //Stand
            //Stopping - (1, 3, 5, 7)
            stop(one, two);
            stop(five, six);
            stop(nine, ten);
            stop(thirteen, fourteen);
            delay(1000);

            //Stopping - (2, 4, 6, 8)
            stop(three, four);
            stop(seven, eight);
            stop(eleven, twelve);
            stop(fifteen, sixteen);
            delay(1000);
            break;
            }

        default:
            break;
    }

}

void extend (int a, int b){
    //Extension - If A = 0 and B = 1, the LA extends
    digitalWrite(a, 0);
    digitalWrite(b, 1);
}

void retract (int c, int d){
    //Extension - If C = 1 and D = 0, the LA retracts
    digitalWrite(c, 1);
    digitalWrite(d, 0);
}

void stop (int e, int f){
    //Stopping - If E = 0 and F = 0, the LA stops
    digitalWrite(e, 0);
    digitalWrite(f, 0);

}