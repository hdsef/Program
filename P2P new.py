import socket
import threading
from tkinter import *

users = []

def connect_button(message):
    UDP_PORT = 5005
    MESSAGE = socket.gethostbyname(socket.getfqdn())+"|"+message
    print ("UDP target port:", UDP_PORT)
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
    sock.sendto(MESSAGE.encode(), ('<broadcast>', UDP_PORT))
    
def Test():
    UDP_PORT = 5005
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
    sock.bind(('', UDP_PORT))
    while True:
        data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
        users.append(data.decode())
        print ("received message:", data.decode())
        
#def main():
c = threading.Thread(target=Test)
c.daemon = True
c.start()
print("Please choose login")
message=input()
#t = threading.Thread(target=connect_button(message))
#t.daemon = True
#t.start()
connect_button(message)

for item in users:
    print(item)