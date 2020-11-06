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
        thread = threading.Thread(target=handle_client)

print("[STARTING] Server is starting...")
start()