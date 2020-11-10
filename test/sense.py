from sense_emu import SenseHat

print("Hello Will")
sense = SenseHat()
a = sense.get_accelerometer_raw()
x=a['x']
y=a['y']
z=a['z']
print(x + " " + y + " " + z)
