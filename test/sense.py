from sense_emu import SenseHat

print("Hello Will")
sense = SenseHat()
a = sense.get_accelerometer_raw()
f = open("data.txt","w")
f.write("working")
