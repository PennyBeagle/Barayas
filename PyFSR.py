# Force Sensing Resistor :D

import RPi.GPIO as GPIO #   Imports GPIO file
from time import sleep  #   Gives us our delay

GPIO.setmode(GPIO.BCM) #    Tells the PI to be in BCM mode

GPIO.setup(5, GPIO.IN) # Sets GPIO 5 as an input

base = 0 # Base variable to determine if pressure is being applied

while 1: # Loops forever
    current = GPIO.input(5)

    if((not base) and current): # If last reading (base) was low and the current reading (current) is high, pressure is being applied
        print("Pressure detected!")
        base = current
        sleep(0.2)        

    else: # No pressure is being applied to be detected
        print("There's nothing there...")