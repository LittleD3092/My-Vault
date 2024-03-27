# -*- coding: utf-8 -*-

from setting import get_hosts, get_switches, get_links, get_ip, get_mac

DEBUG = True

# custom packet class
ETHERTYPE_ARP = 0x0806
ETHERTYPE_IP = 0x0800
class EthernetFrame:
    def __init__(self, src_mac, dst_mac, ethertype, payload):
        self.src_mac = src_mac
        self.dst_mac = dst_mac
        self.ethertype = ethertype
        self.payload = payload

ARP_HARDWARE_TYPE_ETHERNET = 1
ARP_PROTOCOL_TYPE_IP = 0x0800
ARP_OPCODE_REQUEST = 1
ARP_OPCODE_REPLY = 2
class ARPPacket:
    def __init__(self, hardware_type, protocol_type, opcode, sender_mac, sender_ip, target_mac, target_ip):
        self.hardware_type = hardware_type
        self.protocol_type = protocol_type
        self.opcode = opcode
        self.sender_mac = sender_mac
        self.sender_ip = sender_ip
        self.target_mac = target_mac
        self.target_ip = target_ip

IP_PROTOCOL_ICMP = 1
class IPPacket:
    def __init__(self, src_ip, dst_ip, protocol, payload):
        self.src_ip = src_ip
        self.dst_ip = dst_ip
        self.protocol = protocol
        self.payload = payload

ICMP_TYPE_ECHO_REQUEST = 8
ICMP_TYPE_ECHO_REPLY = 0
class ICMPPacket:
    def __init__(self, type, payload):
        self.type = type
        self.payload = payload

class host:
    def __init__(self, name, ip, mac):
        self.name = name
        self.ip = ip
        self.mac = mac 
        self.port_to = None 
        self.arp_table = dict() # maps IP addresses to MAC addresses
    def add(self, node):
        self.port_to = node
    def show_table(self):
        for i in self.arp_table:
            print(f'{i} : {self.arp_table[i]}')
    def clear(self):
        # clear ARP table entries for this host
        # Preconditions: None
        # Postconditions: ARP table (a dictionary that maps IP 
        #                 addresses to MAC addresses) is empty
        self.arp_table.clear()
    def update_arp(self, entry):
        # update ARP table with a new entry
        # Preconditions: entry is a list of two strings,
        #                where the first string is an IP
        #                address and the second string is
        #                a MAC address.
        # Postconditions: ARP table is updated with the
        #                 given new entry.
        self.arp_table[entry[0]] = entry[1]
    def handle_packet(self, packet, income_name):
        # handle incoming packets
        # Preconditions: packet is an object of class 
        #                EthernetFrame.
        # Postconditions: packet is processed and appropriate
        #                 action is taken.
        if packet.ethertype == ETHERTYPE_ARP:
            arp_packet = packet.payload
            if arp_packet.opcode == ARP_OPCODE_REQUEST:
                if arp_packet.target_ip == self.ip:
                    self.update_arp(
                        [arp_packet.sender_ip, 
                         arp_packet.sender_mac]
                    )
                    reply = ARPPacket(
                        hardware_type = 
                            ARP_HARDWARE_TYPE_ETHERNET,
                        protocol_type = ARP_PROTOCOL_TYPE_IP,
                        opcode = ARP_OPCODE_REPLY,
                        sender_mac = self.mac,
                        sender_ip = self.ip,
                        target_mac = arp_packet.sender_mac,
                        target_ip = arp_packet.sender_ip
                    )
                    eth_frame = EthernetFrame(
                        src_mac = self.mac,
                        dst_mac = arp_packet.sender_mac,
                        ethertype = ETHERTYPE_ARP,
                        payload = reply
                    )
                    self.send(eth_frame)
            elif arp_packet.opcode == ARP_OPCODE_REPLY:
                self.update_arp(
                    [arp_packet.sender_ip, 
                     arp_packet.sender_mac]
                )
        elif packet.ethertype == ETHERTYPE_IP:
            ip_packet = packet.payload
            if ip_packet.dst_ip == self.ip:
                if ip_packet.protocol == IP_PROTOCOL_ICMP:
                    icmp_packet = ip_packet.payload
                    if icmp_packet.type == ICMP_TYPE_ECHO_REQUEST:
                        reply = ICMPPacket(
                            type = ICMP_TYPE_ECHO_REPLY,
                            payload = icmp_packet.payload
                        )
                        ip_reply = IPPacket(
                            src_ip = self.ip,
                            dst_ip = ip_packet.src_ip,
                            protocol = IP_PROTOCOL_ICMP,
                            payload = reply
                        )
                        eth_reply = EthernetFrame(
                            src_mac = self.mac,
                            dst_mac = packet.src_mac,
                            ethertype = ETHERTYPE_IP,
                            payload = ip_reply
                        )
                        self.send(eth_reply)
    def ping(self, dst_ip):
        # handle a ping request
        # Preconditions: dst_ip is a string that represents
        #                the IP address of the destination.
        # Postconditions: A ping request is sent to the
        #                 destination.
        if self.arp_table.get(dst_ip) is not None:
            icmp = ICMPPacket(
                type = ICMP_TYPE_ECHO_REQUEST,
                payload = None
            )
            ip = IPPacket(
                src_ip = self.ip,
                dst_ip = dst_ip,
                protocol = IP_PROTOCOL_ICMP,
                payload = icmp
            )
            eth = EthernetFrame(
                src_mac = self.mac,
                dst_mac = self.arp_table[dst_ip],
                ethertype = ETHERTYPE_IP,
                payload = ip
            )
            self.send(eth)
        elif self.ip == dst_ip:
            self.update_arp([self.ip, self.mac])
        else: # send an ARP request
            arp = ARPPacket(
                hardware_type = ARP_HARDWARE_TYPE_ETHERNET,
                protocol_type = ARP_PROTOCOL_TYPE_IP,
                opcode = ARP_OPCODE_REQUEST,
                sender_mac = self.mac,
                sender_ip = self.ip,
                target_mac = 'ffff',
                target_ip = dst_ip
            )
            eth = EthernetFrame(
                src_mac = self.mac,
                dst_mac = 'ffff',
                ethertype = ETHERTYPE_ARP,
                payload = arp
            )
            self.send(eth)
            # send ping request
            if self.arp_table.get(dst_ip) is not None:
                self.ping(dst_ip)
    def send(self, packet):
        # determine the destination MAC here
        '''
            Hint :
                if the packet is the type of arp request, destination MAC would be 'ffff'.
                else, check up the arp table.
        '''
        node = self.port_to # get node connected to this host
        node.handle_packet(packet, self.name) # send packet to the connected node

class switch:
    def __init__(self, name, port_n):
        self.name = name
        self.mac_table = dict() # maps MAC addresses to port numbers
        self.port_n = port_n # number of ports on this switch
        self.port_to = list() 
    def add(self, node): # link with other hosts or switches
        self.port_to.append(node)
    def show_table(self):
        for m in self.mac_table:
            print(f'{m} : {self.mac_table[m]}')
    def clear(self):
        # clear MAC table entries for this switch
        # Preconditions: None
        # Postconditions: MAC table (a dictionary that maps MAC
        #                 addresses to port numbers) is empty
        self.mac_table.clear()
    def update_mac(self, entry):
        # update MAC table with a new entry
        # Preconditions: entry is a list of two strings,
        #                where the first string is a MAC
        #                address and the second string is
        #                a port number.
        # Postconditions: MAC table is updated with the
        #                 given new entry.
        self.mac_table[entry[0]] = entry[1]
    def send(self, idx, packet): # send to the specified port
        node = self.port_to[idx] 
        node.handle_packet(packet, self.name) 
    def handle_packet(self, packet, income_name):
        # handle incoming packets
        # Preconditions: packet is an object of class
        #                EthernetFrame.
        # Postconditions: packet is processed and appropriate
        #                 action is taken.

        # determine the incoming port number from 
        # the name of the incoming node
        income_port = None
        for i in range(self.port_n):
            if self.port_to[i].name == income_name:
                income_port = i
                break

        # update MAC table
        self.update_mac([packet.src_mac, income_port])

        # forward the packet or broadcast
        if packet.dst_mac == 'ffff':
            for i in range(self.port_n):
                if i != income_port:
                    self.send(i, packet)
        elif packet.dst_mac in self.mac_table:
            if income_port != self.mac_table[packet.dst_mac]:
                self.send(self.mac_table[packet.dst_mac], packet)
        else:
            for i in range(self.port_n):
                if i != income_port:
                    self.send(i, packet)

def add_link(tmp1, tmp2): # create a link between two nodes
    if tmp1 in host_dict:
        node1 = host_dict[tmp1]
    else:
        node1 =  switch_dict[tmp1]
    if tmp2 in host_dict:
        node2 = host_dict[tmp2]
    else:
        node2 = switch_dict[tmp2]
    node1.add(node2)

def set_topology():
    global host_dict, switch_dict
    hostlist = get_hosts().split(' ')
    switchlist = get_switches().split(' ')
    link_command = get_links()
    ip_dic = get_ip()
    mac_dic = get_mac()
    
    host_dict = dict() # maps host names to host objects
    switch_dict = dict() # maps switch names to switch objects
    
    for h in hostlist:
        host_dict[h] = host(h, ip_dic[h], mac_dic[h])
    for s in switchlist:
        switch_dict[s] = switch(s, len(link_command.split(s))-1)
    for l in link_command.split(' '):
        [n0, n1] = l.split(',')
        add_link(n0, n1)
        add_link(n1, n0)

def ping(tmp1, tmp2): # initiate a ping between two hosts
    global host_dict, switch_dict
    if tmp1 in host_dict and tmp2 in host_dict : 
        node1 = host_dict[tmp1]
        node2 = host_dict[tmp2]
        node1.ping(node2.ip)
    else : 
        return 1 # wrong 
    return 0 # success 


def show_table(tmp): # display the ARP or MAC table of a node
    if tmp == 'all_hosts':
        print(f'ip : mac')
        for h in host_dict:
            print(f'---------------{h}:')
            host_dict[h].show_table()
        print()
    elif tmp == 'all_switches':
        print(f'mac : port')
        for s in switch_dict:
            print(f'---------------{s}:')
            switch_dict[s].show_table()
        print()
    elif tmp in host_dict:
        print(f'ip : mac\n---------------{tmp}')
        host_dict[tmp].show_table()
    elif tmp in switch_dict:
        print(f'mac : port\n---------------{tmp}')
        switch_dict[tmp].show_table()
    else:
        return 1
    return 0


def clear(tmp):
    wrong = 0
    if tmp in host_dict:
        host_dict[tmp].clear()
    elif tmp in switch_dict:
        switch_dict[tmp].clear()
    else:
        wrong = 1
    return wrong


def run_net():
    while(1):
        wrong = 0 
        try:
            command_line = input(">> ")
        except EOFError:
            return 0
        command_list = command_line.strip().split(' ')
        
        if command_line.strip() =='exit':
            return 0
        if command_line.strip() == 'show_all':
            show_table('all_hosts')
            show_table('all_switches')
        elif len(command_list) == 2 : 
            if command_list[0] == 'show_table':
                wrong = show_table(command_list[1])
            elif command_list[0] == 'clear' :
                wrong = clear(command_list[1])
            else :
                wrong = 1 
        elif len(command_list) == 3 and command_list[1] == 'ping' :
            wrong = ping(command_list[0], command_list[2])
        else : 
            wrong = 1
        if wrong == 1:
            print('a wrong command')

    
def main():
    set_topology()
    run_net()


if __name__ == '__main__':
    main()