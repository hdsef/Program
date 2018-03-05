import socket
import threading

users = []
MESSAGE = ""
event = threading.Event()
event.set()

def notification():
    UDP_PORT = 5005
    print("UDP target port:", UDP_PORT)
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  # UDP
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
    sock.sendto(MESSAGE.encode(), ('<broadcast>', UDP_PORT))


def Receiving():
    UDP_PORT = 5005
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  # UDP
    sock.bind(('', UDP_PORT))
    while True:
        event.wait()
        print("1")
        data, addr = sock.recvfrom(1024)
        if data.decode().find("@#") != -1:
            writeback = data.decode().split("@#")
            flag = 0
            for item in users:
                if item == data.decode():
                    flag = 1
            if flag != 1:
                users.append(data.decode())
                print(writeback[0], "gdohndoh")
                # sock.bind((writeback[0],UDP_PORT))
                if data.decode() != MESSAGE:
                    sock.sendto(MESSAGE.encode(), (writeback[0], UDP_PORT))
        elif data.decode().find("|") != -1:
            writeback = data.decode().split("|")
            print("received message:", data.decode())
            chat = open("chat"+writeback[0]+".txt", "a")
            chat.write(writeback[1])
            chat.close()


def Sending(Actual_chat):
    Node = input()
    UDP_PORT = 5005
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  # UDP
    i=0
    while i< len(users):
        IP = users[i].split("@#")
        if open_chat == IP[1]:
            event.clear()
            sock.sendto(message+"|"+Node.encode(), (IP[0], UDP_PORT))
            event.set()
        i += 1

# def main():
print("Please choose login")
message = input()
MESSAGE = socket.gethostbyname(socket.getfqdn())+"@#"+message
users.append(socket.gethostbyname(socket.getfqdn())+"@#"+message)
c = threading.Thread(target=Receiving)
c.start()
notification()

print("open chat with")
open_chat = input()
file = open("chat"+open_chat+".txt", "r")
for line in file:
    print(line, end="")
file.close()
Sending(open_chat)

for item in users:
    print(item)
