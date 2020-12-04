#
#   client.py
#
#	Author		   : Group 56
#	Date		   : November 11, 2020
#	Description    :
#
from socket import *
from time import sleep
# sense_emu is the sensehat emulator package that comes with the raspberry pi for prototyping and
# and development without the actual sensehat hardware. However we do have a sense hat on the way, and once
# received, we will continue the next steps, which include, sensing orientation in the users pocket,
# and converting acceleromneter data into steps. The reason we can not do this yet, is becasue the sensehat emulator
# has limited functionality compared to the physical sensehat
from sense_emu import SenseHat
import sys

# Declare network constants for connecting to c++ SensorReceiver
BUFFER_SIZE = 1024
HEADER = 64
PORT = 5050
FORMAT = 'utf-8'
SERVER = "127.0.0.1"
ADDR = (SERVER, PORT)


def main():

    # Initialize sense hat
    sense = SenseHat()

    try:
        # Connect to c++ SensorReceiver through sockets
        client_socket = socket(AF_INET, SOCK_STREAM)
        client_socket.connect(ADDR)
        try:
            while True:
                # Send accelerometer data until receive halt message from SensorReceiver
                data = sense.get_accelerometer_raw()
                client_socket.send((str(round(data['x'],3)) + ' ' + str(round(data['y'],3)) + ' ' + str(round(data['z'],3)) + '/').encode())
                sleep(0.08)
        except KeyboardInterrupt:
            # f.close()
            pass
    # Check for broken Connection
    except ConnectionRefusedError:
        print('Error:  That host or port is not accepting connections.')
        sys.exit(1)

# Main function
if __name__ == '__main__':
    main()
