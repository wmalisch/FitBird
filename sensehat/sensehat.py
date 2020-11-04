from sense_emu import SenseHat
sense = SenseHat()

while True:
    a = sense.get_accelerometer_raw()
    x=a['x']
    y=a['y']
    z=a['z']
    x=round(x,1)
    y=round(y,1)
    z=round(z,1)
    print("x={0}, y={1}, z={2}".format(x,y,z))