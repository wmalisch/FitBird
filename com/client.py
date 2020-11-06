from socket import *
import sys

PORT = 5050
FORMAT = 'utf-8'
SERVER = "127.0.1.1"
ADDR = (SERVER, PORT)

client = socket(AF_INET, SOCK_STREAM)
client.connect(ADDR)


