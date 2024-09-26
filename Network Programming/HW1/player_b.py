import socket
import time

class UDP_server:
    def __init__(self, my_ip, my_port):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.bind((my_ip, my_port))
        
        self.my_ip = my_ip
        self.my_port = my_port

        self.buffer = ''

    def __del__(self):
        self.sock.close()

    def receive(self):
        if '\n' not in self.buffer:
            data, addr = self.sock.recvfrom(1024)
            self.buffer += data.decode()

        msg, self.buffer = self.buffer.split('\n', 1)
        return msg, addr
    
    def send(self, msg, ip, port):
        if msg[-1] != '\n':
            msg += '\n'
        self.sock.sendto(msg.encode(), (ip, port))

class TCP_client:
    def __init__(self, my_ip, my_port, ip, port):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        if type(my_port) == str:
            my_port = int(my_port)
        while True:
            try:
                self.sock.bind((my_ip, my_port))
                break
            except:
                print("Port already in use. Retrying...")
                time.sleep(1)
        while True:
            try:
                self.sock.connect((ip, port))
                break
            except:
                print("Connection failed. Retrying...")
                time.sleep(1)

        self.buffer = ''

    def __del__(self):
        self.sock.close()

    def send(self, msg):
        if msg[-1] != '\n':
            msg += '\n'
        self.sock.send(msg.encode())

    def receive(self):
        if '\n' not in self.buffer:
            self.buffer += self.sock.recv(4096).decode()
        
        msg, self.buffer = self.buffer.split('\n', 1)
        return msg
        

if __name__ == "__main__":
    my_port = input("Please enter the " + "\033[0;36m" + "port" + "\033[0m" + " for \033[0;35mplayer-b\033[0m: ")
    udp_server = UDP_server('0.0.0.0', int(my_port))
    tcp_client = None

    print("Waiting for \033[0;35mplayer-a\033[0m to connect...")

    while True:
        msg, addr = udp_server.receive()
        msg = msg.split(' ')
        if msg[0] != 'c109611066':
            continue

        if msg[1] == 'SEARCH':
            udp_server.send('c109611066 HELLO', addr[0], addr[1])
        elif msg[1] == 'INVITE':
            ip = addr[0]
            port = addr[1]
            option = input("\033[0;35m" + "Player-a" + "\033[0m" + " wants to play with you. Do you accept? " + "\033[0;32m" + "(Y/n)" + "\033[0m" + ": ")
            if option.upper() == 'Y' or option == '':
                udp_server.send('c109611066 ACCEPT', ip, port)
        elif msg[1] == 'PORT':
            ip = addr[0]
            port = int(msg[2])
            tcp_client = TCP_client('0.0.0.0', my_port, ip, port)
            del udp_server
            break

    while True:
        end = False

        while True:
            msg = tcp_client.receive()
            if msg == 'INPUT':
                break
            if msg == 'END':
                end = True
                break

            if msg.split(' ')[-1] == 'NO_ENDL':
                print(msg[:-8], end='')
            else:
                print(msg)

        if end:
            break

        option = input()
        tcp_client.send(option)
