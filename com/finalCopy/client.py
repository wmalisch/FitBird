from socket import *

# sense_emu is the sensehat emulator package that comes with the raspberry pi for prototyping and
# and development without the actual sensehat hardware. However we do have a sense hat on the way, and once
# received, we will continue the next steps, which include, sensing orientation in the users pocket,
# and converting acceleromneter data into steps. The reason we can not do this yet, is becasue the sensehat emulator 
# has limited functionality compared to the physical sensehat
from sense_emu import SenseHat
import sys

BUFFER_SIZE = 1024
HEADER = 64
PORT = 5050
FORMAT = 'utf-8'
SERVER = "127.0.0.1"
ADDR = (SERVER, PORT)


def main():

    sense = SenseHat()
    
    try:
        client_socket = socket(AF_INET, SOCK_STREAM)
        client_socket.connect(ADDR)
        # while True:
        #     x = sense.get_accelerometer_raw()
        #     client_socket.send(str(x['x']).encode())
        #     client_socket.send(str(x['y']).encode())
        #     client_socket.send(str(x['z']).encode())
    except ConnectionRefusedError:
        print('Error:  That host or port is not accepting connections.')
        sys.exit(1)
    

    # except ConnectionRefusedError:
    #     print('Error:  That host or port is not accepting connections.')
    #     sys.exit(1)

if __name__ == '__main__':
    main()