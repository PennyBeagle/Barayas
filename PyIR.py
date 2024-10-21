# IR Sensor :D

import RPi.GPIO as GPIO #   Imports GPIO file
from time import sleep  #   Gives us our delay

GPIO.setwarnings(False) #   Tells the PI not to yell at us
GPIO.setmode(GPIO.BCM) #    Tells the PI to be in BCM mode

GPIO.setup(4, GPIO.IN) # Sets GPIO 4 as an input

while 1: # Loops forever
    if(GPIO.input(4) == False): # Object is nearby to be detected
        print("Object detected!")
        sleep(0.2)        

    else: # No object is nearby to be detected
        print("There's nothing there...")