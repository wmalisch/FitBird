from socket import *
from sense_emu import SenseHat
import sys

BUFFER_SIZE = 1024
HEADER = 64
PORT = 5050
FORMAT = 'utf-8'
SERVER = "127.0.0.1"
ADDR = (SERVER, PORT)


client = socket(AF_INET, SOCK_STREAM)
client.connect(ADDR)

def main():

    # Initialize SenseHat object
    sense = SenseHat()

    try:
        client_socket = socket(AF_INET, SOCK_STREAM)
        client_socket.connect(ADDR)
        accel = sense.get_accelerometer_raw()
        x = accel['x']
        y = accel['y']
        z = accel['z']
        
        client_socket.send(str(x).encode())
    except ConnectionRefusedError:
        print('Error:  That host or port is not accepting connections.')
        sys.exit(1)

if __name__ == '__main__':
    main()