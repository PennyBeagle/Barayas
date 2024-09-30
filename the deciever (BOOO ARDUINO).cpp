//Gyroscope and Accelerometer :D

#include <Wire.h>

//Next 4 lines initializes the I2C address of the MPU-6050 + the XYZ variables of the ACC, GYRO, and TEMP data

const int MPU6050 = 0x68; //I2C address
int16_t Ax, Ay, Az;
int16_t Gx, Gy, Gz; 
int16_t Temp;

//Might need to make something to convert the ints to strings here so I can print them out later? I'm not so sure.

void setup(){
    Serial.begin(9600); //Opens serial port & sets data rate to 9600 bps
    Wire.begin();
    Wire.beginTransmission(MPU6050); //Starts a transmission to the Gyro board
    Wire.write(0x6B); //Grabs register PWR_MGMT_1 (107) (part of the MPU6050... tldr, this configures power)
    Wire.write(0); //Sets the prev value to 0 (wakes up MPU)
    Wire.endTransmission(true);
}

//Setup is played through once, while loop goes through over and over and over. Yay!

void loop(){
    Wire.beginTransmission(MPU6050);
    Wire.write(0x3B); //Begins with register 0*3B (59), which stores the most recent Acc. measurements
    Wire.endTransmission(false);
    Wire.requestFrom(MPU6050, 7*2, true); //Requests 7*2 (14) registers, or enough for double our number of variables (important)

    //Okay onto the actual stuff that isn't just torturing myself with the MPU6050 Document
    //The "Wire.read() << 8 | Wire.read()" part in this next bit just means that two registers are stored in one variable

    Ax = Wire.read() << 8 | Wire.read(); //Registers 0x3B and 0x3C (59 & 60)
    Ay = Wire.read() << 8 | Wire.read(); //Registers 0x3D and 0x3E (61 & 62)
    Az = Wire.read() << 8 | Wire.read(); //Registers 0x3F and 0x40 (63 & 64)
    Temp = Wire.read() << 8 | Wire.read(); //Registers 0x41 and 0x42 (65 & 66)
    Gx = Wire.read() << 8 | Wire.read(); //Registers 0x43 and 0x44 (67 & 68)
    Gy = Wire.read() << 8 | Wire.read(); //Registers 0x45 and 0x46 (69 & 70)
    Gz = Wire.read() << 8 | Wire.read(); //Registers 0x47 and 0x48 (71 & 72)

    //That whole list of registers was just addresses 59-72 on the MPU6050 Register map. It's page 7. I'm in pain.
    //Anyway let's start printing everything out

    Serial.print("Accelerometer X-value = "); Serial.print(Ax);
    Serial.print("Accelerometer Y-value = "); Serial.print(Ay);
    Serial.print("Accelerometer Z-value = "); Serial.print(Az);
    Serial.print("Temperature value = "); Serial.print(Temp/340.00+36.53); //Equation for temperature taken from MPU6050 Temp Measurement (page 30)
    Serial.print("Gyroscope X-value = "); Serial.print(Gx);
    Serial.print("Gyroscope Y-value = "); Serial.print(Gy);
    Serial.print("Gyroscope Z-value = "); Serial.print(Gz);

    //A cute little delay as a treat
    delay(1000);
}