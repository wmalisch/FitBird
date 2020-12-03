from sense_emu import SenseHat
from time import sleep

sense = SenseHat()

i = 0

# To simulate steps, move roll between 0 and -90 degrees
while(True):
    d = sense.get_accelerometer_raw()
    sleep(0.1)
    x = d['x']
    y = d['y']
    z = d['z']
    if(y <= -0.6):
        i = i + 1
        print(i)
