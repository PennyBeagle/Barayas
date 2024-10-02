//Gyroscope and Accelerometer :D

#include <wiringPi.h> //Library for C++ on Raspberry Pi (deals with GPIO's)
#include <wiringPiI2C.h> //Library for I2C connections on Raspberry Pi
#include <stdio.h> //C Library my beloved. The beloved

#define Address 0x68 //MPU6050 Device Address

//All of these are pulled from the MPU6050 document. The name is the value in decimal, and the other is the value in hexidecimal
#define OneOneSeven 0x6B
#define TwoFive     0x19
#define TwoSix      0x1A
#define TwoSeven    0x1B
#define FiveSix     0x38
#define FiveNine    0x3B
#define SixOne      0x3D
#define SixThree    0x3F
#define SixSeven    0x43
#define SixNine     0x45
#define SevenOne    0x47

int16_t P; //P stands for placeholder. I have fun here.

void MPU6050(){
    wiringPiI2CWriteReg8(P, TwoFive, 0x07); //Writes to address 25 (SMPLRT_DIV, sample rate register)
    wiringPiI2CWriteReg8(P, OneOneSeven, 0x01); //Writes to address 117 (PWR_MGMT_1, power management register)
    wiringPiI2CWriteReg8(P, TwoSix, 0); //Writes to address 26 (CONFIG, configuration register)
    wiringPiI2CWriteReg8(P, TwoSeven, 24); //Writes to addres 27 (GYRO_CONFIG, gyro configuration register)
    wiringPiI2CWriteReg8(P, FiveSix, 0x01); //Writes to address 56 (INT_ENABLE, interrupt enable register)
}

short DataRead(int A){
    short High, Low, V;
    High = wiringPiI2CWriteReg8(P, A);
    Low = wiringPiI2CWriteReg8(P, A+1);
    V = (High << 8) | Low;
    return V;
}

//Next 3 lines initializes the XYZ variables of the ACC and GYRO
int16_t AccX, AccY, AccZ, GyX, GyY, GyZ;
int16_t Ax, Ay, Az;
int16_t Gx, Gy, Gz; 

void setup(){
    Serial.begin(9600); //Opens serial port & sets data rate to 9600 bps
    P = wiringPiI2CSetup(Address); //Initializes I2C with the address
    MPU6050(); //Initializes MPU6050
}

//Setup is played through once, while loop goes through over and over and over. Yay!

void loop(){
    //The next howeversomany lines of code read the raw value of the Accelerometer (first) and Gyroscope (second)
    
    AccX = DataRead(FiveNine);
    AccY = DataRead(SixOne);
    AccZ = DataRead(SixThree);

    GyX = DataRead(SixSeven);
    GyY = DataRead(SixNine);
    GyZ = DataRead(SevenOne);

    //We do some math here (dividing the raw values by the sensitivity scale factor, found on page 29 & 31)

    Ax = AccX / 16384.0;
    Ay = AccY / 16384.0;
    Az = AccZ / 16384.0;

    Gx = GyX / 131;
    Gy = GyY / 131;
    Gz = GyZ / 131;
    
    //Okay onto the actual stuff that isn't just torturing myself with the MPU6050 Document
    //Let's start printing everything out

    Serial.println("Accelerometer X-value = "); Serial.println(Ax);
    Serial.println("Accelerometer Y-value = "); Serial.println(Ay);
    Serial.println("Accelerometer Z-value = "); Serial.println(Az);
    Serial.println("Gyroscope X-value = "); Serial.println(Gx);
    Serial.println("Gyroscope Y-value = "); Serial.println(Gy);
    Serial.println("Gyroscope Z-value = "); Serial.println(Gz);

    //A cute little delay as a treat
    delay(1000);
}