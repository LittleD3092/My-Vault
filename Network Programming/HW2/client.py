import socket
import time

class TCP_client:
    def __init__(self, my_ip, my_port, ip, port):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        if type(my_port) == str:
            my_port = int(my_port)
        if my_port == None:
            my_port = 0
        while True:
            try:
                self.sock.bind((my_ip, my_port))
                break
            except:
                print("Port already in use. Retrying...")
                time.sleep(1)
        while True:
            try:
                print(f"Connecting to {ip}:{port}")
                self.sock.connect((ip, port))
                break
            except:
                print("Connection failed. Retrying...")
                time.sleep(1)

        self.buffer = ''

    def __del__(self):
        self.sock.close()

    def send(self, msg: str):
        if msg[-1] != '\n':
            msg += '\n'
        self.sock.send(msg.encode(encoding="utf-16"))

    def receive(self):
        if '\n' not in self.buffer:
            self.buffer += self.sock.recv(4096).decode(encoding="utf-16")

        if len(self.buffer.split('\n')) == 1:
            msg = self.buffer
            self.buffer = ''
        else:
            msg, self.buffer = self.buffer.split('\n', 1)

        return msg
    
def connect_io_server(ip, port):
    tcp_client = TCP_client('0.0.0.0', 0, ip, port)

    while True:
        end = False

        while True:
            msg = tcp_client.receive()
            if msg == '':
                continue
            if 'INPUT' in msg:
                input_flag = True
                # find the string 'INPUT' and remove it
                msg = msg.split('INPUT')[0] + msg.split('INPUT')[1]
            else:
                input_flag = False
                
            if msg == 'END':
                end = True
                print('Closing connection...')
                break

            if msg.split(' ')[-1] == 'NO_ENDL':
                print(msg[:-8], end='')
            else:
                print(msg)

            if input_flag:
                break

        if end:
            break

        option = input()
        tcp_client.send(option)

if __name__ == "__main__":
    connect_io_server('127.0.0.1', 11066)