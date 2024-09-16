import socket

def udp_send(message, server_ip, server_port) -> None:
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    
    try:
        sock.sendto(message.encode(), (server_ip, server_port))
    except Exception as e:
        print(e)

    sock.close()

if __name__ == "__main__":
    # send an invitation to player-b through UDP
    address = input("Enter the IP address of the player-b: ")
    port = int(input("Enter the port number of the player-b: "))
    udp_send(
        "c109611066 INVITATION",
        address,
        port
    )