import socket
import time
import random
import os
import re
import struct

def generate_normal_traffic(server_ip, server_port, duration=60, rate=10):
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    end_time = time.time() + duration
    print('------------------------------------')
    print(f'[TIME] {time.time()}')
    print(f'Sending normal traffic for {duration} seconds at {rate} packets per second')

    while time.time() < end_time:
        num1 = random.randint(0, 100)
        num2 = random.randint(0, 100)
        message = f'{num1} {num2}'
        sock.sendto(message.encode(), (server_ip, server_port))
        time.sleep(1 / rate)

    print('Done sending normal traffic')

def checksum(data):
    s = 0
    for i in range(0, len(data), 2):
        w = (data[i] << 8) + (data[i + 1])
        s = s + w
    s = (s >> 16) + (s & 0xffff)
    s = ~s & 0xffff
    return s

def generate_malicious_traffic(server_ip, server_port, duration=60, rate=1000):
    if os.geteuid() != 0:
        raise PermissionError("Root privileges are required to create raw sockets")

    sock = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_RAW)
    end_time = time.time() + duration

    print('------------------------------------')
    print(f'[TIME] {time.time()}')
    print(f'Sending malicious traffic for {duration} seconds at {rate} packets per second')

    while time.time() < end_time:
        # Generate random source IP
        src_ip = f"192.168.0.{random.randint(0, 255)}"
        dst_ip = server_ip

        # Generate random message
        num1 = random.randint(0, 100)
        num2 = random.randint(0, 100)
        message = f'{num1} {num2}'.encode()

        # IP header fields
        ip_ihl = 5  # Internet Header Length
        ip_ver = 4  # Version
        ip_tos = 0  # Type of Service
        ip_tot_len = 20 + len(message)  # Total length
        ip_id = random.randint(0, 65535)  # ID of this packet
        ip_frag_off = 0  # Fragment offset
        ip_ttl = 255  # Time to live
        ip_proto = socket.IPPROTO_UDP  # Protocol
        ip_check = 0  # Initial checksum
        ip_saddr = socket.inet_aton(src_ip)  # Source IP
        ip_daddr = socket.inet_aton(dst_ip)  # Destination IP

        ip_ihl_ver = (ip_ver << 4) + ip_ihl

        # The ! in the pack format string means network order (big-endian)
        ip_header = struct.pack('!BBHHHBBH4s4s', ip_ihl_ver, ip_tos, ip_tot_len, ip_id, ip_frag_off, ip_ttl, ip_proto, ip_check, ip_saddr, ip_daddr)

        # Calculate the checksum and replace the initial value
        ip_check = checksum(ip_header)
        ip_header = struct.pack('!BBHHHBBH4s4s', ip_ihl_ver, ip_tos, ip_tot_len, ip_id, ip_frag_off, ip_ttl, ip_proto, ip_check, ip_saddr, ip_daddr)

        # UDP header fields
        udp_source = random.randint(1024, 65535)  # Random source port
        udp_dest = server_port  # Destination port
        udp_length = 8 + len(message)  # Length of UDP header + payload
        udp_check = 0  # Initial checksum

        # Construct UDP header
        udp_header = struct.pack('!HHHH', udp_source, udp_dest, udp_length, udp_check)

        # Full packet
        packet = ip_header + udp_header + message

        # Send the packet
        sock.sendto(packet, (dst_ip, 0))

        time.sleep(1 / rate)

    print('Done sending malicious traffic')

def get_ip():
    try:
        command_output = os.popen('ip addr show eth0').read()
        ip_regex = r'inet (\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})'
        match = re.search(ip_regex, command_output)
        if match:
            return match.group(1)
        else:
            return None
    except:
        return None

def main():
    server_ip = '10.0.0.10'
    server_port = 12345

    normal_ip = {'10.0.0.1', '10.0.0.2'}
    malicious_ip = {'10.0.0.3', '10.0.0.4'}

    if get_ip() in normal_ip:
        generate_normal_traffic(server_ip, server_port, duration=40)
    elif get_ip() in malicious_ip:
        generate_normal_traffic(server_ip, server_port, duration=10)
        generate_malicious_traffic(server_ip, server_port, duration=20)
        generate_normal_traffic(server_ip, server_port, duration=10)

if __name__ == '__main__':
    main()