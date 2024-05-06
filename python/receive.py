import socket
import threading
import queue

messages = queue.Queue()
clients = []

UDP_IP = "192.168.0.28"  # Listen on all network interfaces
UDP_PORT = 4210  # Replace with the port your ESP8266 is sending to

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  # UDP
server.bind("localhost", UDP_PORT)



def receive():
    while True:
        try:
            message, addr = server.recvfrom(1024)
            messages.put((message, addr))
        except:
            pass

def broadcast():
    while True:
        while not messages.empty():
            message, addr = message.get()
            print(message.decode())
            if addr not in clients:
                clients.append(addr)
