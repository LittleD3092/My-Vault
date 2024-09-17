import socket

def udp_receiver(bind_ip, bind_port) -> str:
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind((bind_ip, bind_port))
    
    data, addr = sock.recvfrom(1024)
    return data.decode()