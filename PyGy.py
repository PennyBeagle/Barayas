# Gyroscope and Accelerometer :D

import smbus            #imports I2C stuff
from time import sleep  #gives us our delay

# All of these are pulled from the MPU6050 document. The name is the value in decimal, and the other is the value in hexidecimal
OneOneSeven = 0x6B
TwoFive     = 0x19
TwoSix      = 0x1A
TwoSeven    = 0x1B
FiveSix     = 0x38
FiveNine    = 0x3B
SixOne      = 0x3D
SixThree    = 0x3F
SixSeven    = 0x43
SixNine     = 0x45
SevenOne    = 0x47

def MPU6050():
    bus.write_byte_data(MPU, TwoFive, 7) #      Writes to address 25 (SMPLRT_DIV, sample rate register)
    bus.write_byte_data(MPU, OneOneSeven, 1) #  Writes to address 117 (PWR_MGMT_1, power management register)
    bus.write_byte_data(MPU, TwoSix, 0) #       Writes to address 26 (CONFIG, configuration register)
    bus.write_byte_data(MPU, TwoSeven, 24) #    Writes to addres 27 (GYRO_CONFIG, gyro configuration register)
    bus.write_byte_data(MPU, FiveSix, 1) #      Writes to address 56 (INT_ENABLE, interrupt enable register)

def read(addr):
    high = bus.read_byte_data(MPU, addr)
    low = bus.read_byte_data(MPU, addr + 1)

    value = ((high << 8) | low)

    if(value > 32768):
        value = value - 65536
    
    return value

bus = smbus.SMBus(1)
MPU = 0x68    # MPU6050 Device Address

MPU6050()
print(" Reading Data of Gyro & Acc")

while True:
    # The next howeversomany lines of code read the raw value of the Accelerometer (first) and Gyroscope (second)
    Acc_X = read(FiveNine)
    Acc_Y = read(SixOne)
    Acc_Z = read(SixThree)

    Gy_X = read(SixSeven)
    Gy_Y = read(SixNine)
    Gy_Z = read(SevenOne)

    # We do some math here (dividing the raw values by the sensitivity scale factor, found on page 29 & 31)
    Ax = Acc_X / 16384.0
    Ay = Acc_Y / 16384.0
    Az = Acc_Z / 16384.0

    Gx = Gy_X / 131.0
    Gy = Gy_Y / 131.0
    Gz = Gy_Z / 131.0

    # Okay onto the actual stuff that isn't just torturing myself with the MPU6050 Document
    # Let's print everything out

    print ("Gx = %.2f" %Gx, u'\u00b0'+ "/s", "\tGy = %.2f" %Gy, u'\u00b0'+ "/s", "\tGz = %.2f" %Gz, u'\u00b0'+ "/s", "\tAx = %.2f g" %Ax, "\tAy = %.2f g" %Ay, "\tAz = %.2f g" %Az) 	
	sleep(1)