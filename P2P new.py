import socket
import threading
from tkinter import *

users = []

def connect_button(MESSAGE):
    UDP_PORT = 5005
    print ("UDP target port:", UDP_PORT)
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
    sock.sendto(MESSAGE.encode(), ('<broadcast>', UDP_PORT))
    
def Receiving(MESSAGE):
    UDP_PORT = 5005
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
    sock.bind(('', UDP_PORT))
    while True:
        data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
        if data.decode().find("@#"):
            f=0
            for item in users:
                if item == data.decode():
                    f=1
            if f!=1:       
                users.append(data.decode())
                writeback=data.decode().split("@#")
                print(writeback[0])
                sock.sendto(MESSAGE.encode(),(writeback[0],UDP_PORT))
        else:
            print ("received message:", data.decode())
        
#def main():
message=input()
MESSAGE = socket.gethostbyname(socket.getfqdn())+"@#"+message
c = threading.Thread(target=Receiving(MESSAGE))
c.daemon = True
c.start()
print("Please choose login")

#t = threading.Thread(target=connect_button(message))
#t.daemon = True
#t.start()
connect_button(MESSAGE)

messagf = input()
for item in users:
    print(item)
