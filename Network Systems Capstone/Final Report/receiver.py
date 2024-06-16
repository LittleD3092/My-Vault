import socket

def udp_server(server_ip = '10.0.0.10', port = 12345):
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind((server_ip, port))

    while True:
        data, addr = sock.recvfrom(1024)
        msg = data.decode()

        try:
            num1, num2 = map(int, msg.split())
            response = f"{num1 + num2}"
            sock.sendto(response.encode(), addr)
        except ValueError:
            print(f"Invalid input: {msg}")
            response = "Invalid input"
            sock.sendto(response.encode(), addr)

def main():
    udp_server()

if __name__ == '__main__':
    main()