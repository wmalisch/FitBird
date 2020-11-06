from socket import *
import threading
import time

PORT = 5050
SERVER = gethostbyname(gethostname())

serverSocket = socket(AF_INET,SOCK_STREAM)
serverSocket.bind((SERVER,PORT))

def handle_client(conn, addr):
    pass

def start():
    serverSocket.listen(1)
    while True:
        conn, addr = serverSocket.accept()

print("[STARTING] Server is starting...")
start()