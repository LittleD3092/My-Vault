import socket
import argparse
import threading
import time

shutdown_event = threading.Event()

def current_hms():
    return time.strftime('%H:%M:%S', time.localtime())

class RoutingTable:
    def __init__(self, my_router_id: int):
        self.table = {}
        self.lock = threading.Lock()
        self.my_router_id = my_router_id

    def add_route(self, router_id: int, next_hop: int, cost: int):
        with self.lock:
            self.table[router_id] = {
                'next_hop': next_hop,
                'cost': cost
            }
        print(f'{current_hms()} - add route {router_id} {next_hop} {cost}')

    def update_route(self, router_id: int, next_hop: int, cost: int):
        with self.lock:
            self.table[router_id] = {
                'next_hop': next_hop,
                'cost': cost
            }
        print(f'{current_hms()} - update route {router_id} {next_hop} {cost}')

    def remove_route(self, router_id: int):
        with self.lock:
            self.table.pop(router_id)
        print(f'{current_hms()} - remove route {router_id}')

    def get_cost(self, router_id: int):
        with self.lock:
            if router_id in self.table:
                return self.table[router_id]['cost']
            else:
                return float('inf')
    
    def get_next_hop(self, router_id: int):
        with self.lock:
            if router_id in self.table:
                return self.table[router_id]['next_hop']
            else:
                return None

    def exists(self, router_id: int):
        with self.lock:
            return router_id in self.table

    def compare_and_update(self, new_table):
        for router_id, data in new_table.items():
            if self.exists(router_id) == False:
                self.add_route(
                    router_id,
                    data['next_hop'],
                    data['cost']
                )
            elif (
                data['next_hop'] != self.get_next_hop(router_id) or
                data['cost'] != self.get_cost(router_id)
            ):
                self.update_route(
                    router_id,
                    data['next_hop'],
                    data['cost']
                )

        all_routers = set(self.table.keys())
        for router_id in all_routers:
            if router_id not in new_table:
                self.remove_route(router_id)

    def perform_spf(self, lsdb):
        N = {self.my_router_id}
        D = {}
        P = {self.my_router_id: None}

        for v in lsdb.routers():
            if v != self.my_router_id:
                P[v] = self.my_router_id

        for v in lsdb.routers():
            if (
                v != self.my_router_id and
                lsdb.get_cost(self.my_router_id, v) != float('inf')
            ):
                D[v] = lsdb.get_cost(self.my_router_id, v)
            elif v == self.my_router_id:
                D[v] = 0
            else:
                D[v] = float('inf')

        while N != lsdb.routers():
            min_v = None
            min_d = float('inf')
            for v in lsdb.routers():
                if v not in N and D[v] <= min_d:
                    min_v = v
                    min_d = D[v]
            N.add(min_v)
            for w in lsdb.get_neighbors(min_v):
                if w not in N:
                    D[w] = min(
                        D[w], 
                        D[min_v] + lsdb.get_cost(min_v, w)
                    )
                    if D[w] == D[min_v] + lsdb.get_cost(min_v, w):
                        P[w] = min_v

        new_routing_table = {}
        for v in N:
            if v != self.my_router_id:
                new_routing_table[v] = {
                    'next_hop': None,
                    'cost': D[v]
                }
                next_hop = v
                while P[next_hop] != self.my_router_id:
                    next_hop = P[next_hop]
                new_routing_table[v]['next_hop'] = next_hop

        # Delete unreachable routers
        indexes = list(new_routing_table.keys())
        for v in indexes:
            if new_routing_table[v]['cost'] == float('inf'):
                new_routing_table.pop(v)

        self.compare_and_update(new_routing_table)
        
    def print(self):
        with self.lock:
            for router_id, data in self.table.items():
                print(f'R{router_id}:')
                print(f'    Next Hop: {data["next_hop"]}')
                print(f'    Cost: {data["cost"]}')
class NeighborTable:
    def __init__(self):
        self.table = {}
        self.lock = threading.Lock()

    def add_neighbor(self, router_id: int, cost: int):
        with self.lock:
            self.table[router_id] = {
                'cost': cost,
                'state': 'DOWN',
                'dbd': None
            }
        print(f'{current_hms()} - add neighbor {router_id} {cost}')

    def remove_neighbor(self, router_id: int):
        with self.lock:
            self.table.pop(router_id)
        print(f'{current_hms()} - remove neighbor {router_id}')

    def update_neighbor(self, router_id: int, cost: int):
        with self.lock:
            self.table[router_id]['cost'] = cost
        print(f'{current_hms()} - update neighbor {router_id} {cost}')

    def get_state(self, router_id: int):
        with self.lock:
            if router_id not in self.table:
                return None
            return self.table[router_id]['state']
        
    def set_state(self, router_id: int, state: str):
        with self.lock:
            self.table[router_id]['state'] = state
        print(f'{current_hms()} - set neighbor state {router_id} {state}')

    def get_dbd(self, router_id: int):
        with self.lock:
            return self.table[router_id]['dbd'].copy()
        
    def set_dbd(self, router_id: int, dbd):
        with self.lock:
            self.table[router_id]['dbd'] = dbd

    def exists(self, router_id: int):
        with self.lock:
            return router_id in self.table
        
    def routers(self):
        with self.lock:
            return self.table.keys()
        
    def print(self):
        with self.lock:
            for router_id, data in self.table.items():
                print(f'R{router_id}:')
                print(f'    Cost: {data["cost"]}')
                print(f'    State: {data["state"]}')
                if data['dbd']:
                    print(f'    DBD: {data["dbd"].get_packet()}')
                else:
                    print('    DBD: None')
class LSDB:
    def __init__(self, my_router_id: int):
        self.table = {my_router_id: {'seq': 0, 'links': {}, 'timestamp': time.time()}}
        self.lock = threading.Lock()

    def add_lsa(self, router_id: int, seq: int, links: dict):
        with self.lock:
            self.table[router_id] = {
                'seq': seq,
                'links': links.copy(),
                'timestamp': time.time()
            }
        print(f'{current_hms()} - add LSA {router_id} {seq}')

    def update_lsa(self, router_id: int, seq: int, links: dict):
        modified = False
        with self.lock:
            if links != self.table[router_id]['links']:
                modified = True
            self.table[router_id] = {
                'seq': seq,
                'links': links.copy(),
                'timestamp': time.time()
            }
        if modified:
            print(f'{current_hms()} - update LSA {router_id} {seq}')

    def remove_lsa(self, router_id: int):
        with self.lock:
            self.table.pop(router_id)
        print(f'{current_hms()} - remove LSA {router_id}')

    def lsa_routers(self):
        with self.lock:
            return self.table.keys()
        
    def routers(self):
        with self.lock:
            result = set()
            for router_id in self.table:
                result.add(router_id)
                for link_id in self.table[router_id]['links']:
                    result.add(link_id)
        return result

    def get_cost(self, router1_id, router2_id):
        with self.lock:
            if (
                router1_id in self.table and 
                router2_id in self.table[router1_id]['links']):
                return (
                    self.table[router1_id]
                        ['links'][router2_id]['cost']
                )
            else:
                return float('inf')

    def get_neighbors(self, router_id):
        with self.lock:
            if router_id in self.table:
                return list(self.table[router_id]['links'].keys())
            else:
                return []
            
    def dbd_diff(self, dbd):
        diff = set()
        isFull = True
        with self.lock:
            for router_id, data in dbd.table.items():
                if router_id not in self.table:
                    diff.add(router_id)
                elif data['seq'] > self.table[router_id]['seq']:
                    diff.add(router_id)
                elif data['seq'] < self.table[router_id]['seq']:
                    isFull = False
            for router_id in self.table:
                if router_id not in dbd.table:
                    isFull = False
        return diff, isFull
    
    def get_lsu_from_lsr(self, lsr):
        lsu = LSU()
        with self.lock:
            for router_id in lsr.get_routers():
                if router_id in self.table:
                    lsu.add_lsa(
                        router_id, 
                        self.table[router_id]['seq'], 
                        self.table[router_id]['links']
                    )
                else:
                    lsu.add_lsa(
                        router_id, 
                        0, 
                        {}
                    )
        return lsu
                    
    def update_from_lsu_and_get_flood_lsu(self, lsu):
        lsu_to_flood = LSU()
        for router_id in lsu.routers():
            if router_id not in self.table:
                self.add_lsa(
                    router_id,
                    lsu.get_seq(router_id),
                    lsu.get_links(router_id)
                )
                lsu_to_flood.add_lsa(
                    router_id,
                    lsu.get_seq(router_id),
                    lsu.get_links(router_id)
                )
            elif (
                lsu.get_seq(router_id) > self.table[router_id]['seq']
            ):
                self.update_lsa(
                    router_id,
                    lsu.get_seq(router_id),
                    lsu.get_links(router_id)
                )
                lsu_to_flood.add_lsa(
                    router_id,
                    lsu.get_seq(router_id),
                    lsu.get_links(router_id)
                )

        return lsu_to_flood
    
    def set_cost(self, router1_id, router2_id, cost):
        with self.lock:
            self.table[router1_id]['links'][router2_id]['cost'] = cost
            self.table[router1_id]['seq'] += 1
            self.table[router1_id]['timestamp'] = time.time()
        print(f'{current_hms()} - update LSA {router1_id} {self.table[router1_id]["seq"]}')

    def remove_link(self, router1_id, router2_id):
        with self.lock:
            self.table[router1_id]['links'].pop(router2_id)
            self.table[router1_id]['seq'] += 1
            self.table[router1_id]['timestamp'] = time.time()
        print(f'{current_hms()} - update LSA {router1_id} {self.table[router1_id]["seq"]}')

    def exists(self, router_id):
        with self.lock:
            return router_id in self.table
        
    def get_seq(self, router_id):
        with self.lock:
            return self.table[router_id]['seq']
        
    def get_links(self, router_id):
        with self.lock:
            return self.table[router_id]['links'].copy()
        
    def empty(self):
        with self.lock:
            return len(self.table) == 0
        
    def print(self):
        with self.lock:
            for router_id, data in self.table.items():
                print(f'R{router_id}:')
                print(f'    Seq: {data["seq"]}')
                print('    Links:')
                for link_id, link_data in data['links'].items():
                    print(f'        R{link_id}:')
                    print(f'            Cost: {link_data["cost"]}')

    def increment_seq(self):
        with self.lock:
            for router_id in self.table:
                self.table[router_id]['seq'] += 1

    def get_lsa(self, router_id):
        with self.lock:
            return self.table[router_id].copy()
        
    def get_timestamp(self, router_id):
        with self.lock:
            return self.table[router_id]['timestamp']
        
    def add_link(self, router1_id, router2_id, cost):
        if router1_id not in self.table:
            self.add_lsa(router1_id, 1, {router2_id: {'cost': cost}})
        else:
            links = self.get_links(router1_id)
            links[router2_id] = {'cost': cost}
            self.update_lsa(router1_id, self.get_seq(router1_id) + 1, links)

class LSU:
    def __init__(self, obj = None):
        if obj == None:
            self.table = {}
        elif type(obj) == dict:
            self.table = obj
        elif type(obj) == str:
            self.table = self.parse_from_packet(obj)
        else:
            raise ValueError('Invalid argument type')
        self.lock = threading.Lock()

    def parse_from_packet(self, packet):
        lsdb = {}
        packet = packet.split(sep=' ')
        i = 1
        while i < len(packet):
            if packet[i] == 'END':
                break
            router_id = int(packet[i])
            seq = int(packet[i + 2])
            links = {}
            i += 4
            while packet[i] != 'END':
                link_id = int(packet[i])
                cost = int(packet[i + 2])
                links[link_id] = {
                    'cost': cost,
                }
                i += 3
            lsdb[router_id] = {
                'seq': seq,
                'links': links
            }
            i += 1
        return lsdb

    def get_packet(self):
        with self.lock:
            result = 'LSU '
            for router_id, data in self.table.items():
                result += f'{router_id} SEQ {data["seq"]} LINKS '
                for link_id, link_data in data['links'].items():
                    result += f'{link_id} COST {link_data["cost"]} '
                result += 'END '
            result += 'END'
            return result
        
    def add_lsa(self, router_id: int, seq: int, links: dict):
        with self.lock:
            self.table[router_id] = {
                'seq': seq,
                'links': links
            }

    def routers(self):
        with self.lock:
            return self.table.keys()
        
    def get_seq(self, router_id):
        with self.lock:
            return self.table[router_id]['seq']
        
    def get_links(self, router_id):
        with self.lock:
            return self.table[router_id]['links'].copy()
        
    def empty(self):
        with self.lock:
            return len(self.table) == 0
        
    def print(self):
        with self.lock:
            print(self.table)
class DBD:
    def __init__(self, obj = None):
        if obj == None:
            self.table = {}
        elif type(obj) == LSDB:
            self.table = self.parse_from_lsdb(obj)
        elif type(obj) == str:
            self.table = self.parse_from_packet(obj)
        else:
            raise ValueError('Invalid argument type')
        self.lock = threading.Lock()

    def parse_from_lsdb(self, lsdb):
        dbd = {}
        for router_id, data in lsdb.table.items():
            dbd[router_id] = {
                'seq': data['seq']
            }
        return dbd
    
    def parse_from_packet(self, packet):
        dbd = {}
        packet = packet.split(sep=' ')
        i = 1
        while i < len(packet):
            if packet[i] == 'END':
                break
            router_id = int(packet[i])
            seq = int(packet[i + 2])
            dbd[router_id] = {
                'seq': seq
            }
            i += 3
        return dbd
    
    def get_packet(self):
        with self.lock:
            result = 'DBD '
            for router_id, data in self.table.items():
                result += f'{router_id} SEQ {data["seq"]} '
            result += 'END'
            return result
class HELLO:
    def __init__(self, data):
        if type(data) == bool:
            self._is_received = data
        elif type(data) == str:
            self._is_received = self.parse_from_packet(data)

    def parse_from_packet(self, packet):
        return packet.split(sep=' ')[1] == 'RECEIVED'
    
    def is_received(self):
        return self._is_received
    
    def get_packet(self):
        if self._is_received:
            return 'HELLO RECEIVED'
        else:
            return 'HELLO NOT RECEIVED'
class LSR:
    def __init__(self, obj = None):
        if obj == None:
            self.table = {}
        elif type(obj) == set:
            self.table = {'routers': obj}
        elif type(obj) == str:
            self.table = self.parse_from_packet(obj)
        elif type(obj) == dict:
            self.table = obj
        else:
            raise ValueError('Invalid argument type')
        self.lock = threading.Lock()

    def parse_from_packet(self, packet):
        routers = set()
        packet = packet.split(sep=' ')
        i = 1
        while i < len(packet):
            if packet[i] == 'END':
                break
            routers.add(int(packet[i]))
            i += 1
        return {'routers': routers}
    
    def get_packet(self):
        with self.lock:
            result = 'LSR '
            for router_id in self.table['routers']:
                result += f'{router_id} '
            result += 'END'
            return result

    def get_routers(self):
        with self.lock:
            return self.table['routers'].copy()
class DATA:
    def __init__(self, data):
        if type(data) == str and data.startswith('DATA'):
            self.src_id = int(data.split(sep=' ')[1])
            self.dest_id = int(data.split(sep=' ')[2])
            self.message = ' '.join(data.split(sep=' ')[3:])
        elif type(data) == str:
            self.src_id = None
            self.dest_id = None
            self.message = data
        elif type(data) == dict:
            self.src_id = data['src_id']
            self.dest_id = data['dest_id']
            self.message = data['message']
        else:
            raise ValueError('Invalid argument type')
        
    def get_packet(self):
        return f'DATA {self.src_id} {self.dest_id} {self.message}'

    def get_src_id(self):
        return self.src_id
    
    def get_dest_id(self):
        return self.dest_id
    
    def get_message(self):
        return self.message

class Packet:
    def __init__(self, packet: str):
        self.packet = packet
        self.lock = threading.Lock()

    def get_packet(self):
        with self.lock:
            return self.packet
        
    def get_object(self):
        if self.packet.startswith('HELLO'):
            return HELLO(self.packet)
        elif self.packet.startswith('DBD'):
            return DBD(self.packet)
        elif self.packet.startswith('LSR'):
            return LSR(self.packet)
        elif self.packet.startswith('LSU'):
            return LSU(self.packet)
        elif self.packet.startswith('DATA'):
            return DATA(self.packet)
        else:
            raise ValueError('Invalid packet type')

routing_table = None
neighbor_table = None
lsdb = None

def receive_thread(sock, my_router_id):
    while not shutdown_event.is_set():
        try:
            data, addr = sock.recvfrom(1024)
            packet = Packet(data.decode())
            packet_obj = packet.get_object()
            neighbor_id = addr[1] - 10000
            if type(packet_obj) == HELLO:
                if packet_obj.is_received() == False:
                    if neighbor_table.get_state(neighbor_id) == 'DOWN':
                        neighbor_table.set_state(neighbor_id, 'INIT')
                elif packet_obj.is_received() == True:
                    if neighbor_table.get_state(neighbor_id) == 'DOWN':
                        neighbor_table.set_state(neighbor_id, 'EXCHANGE')
                    elif neighbor_table.get_state(neighbor_id) == 'INIT':
                        neighbor_table.set_state(neighbor_id, 'EXCHANGE')
            elif type(packet_obj) == DBD:
                neighbor_table.set_dbd(neighbor_id, packet_obj)
                if neighbor_table.get_state(neighbor_id) == 'EXCHANGE':
                    difference, isFull = lsdb.dbd_diff(packet_obj)
                    if difference:
                        packet = LSR(difference).get_packet()
                        sock.sendto(packet.encode(), ('localhost', 10000 + neighbor_id))
                    elif isFull:
                        neighbor_table.set_state(neighbor_id, 'FULL')
                elif neighbor_table.get_state(neighbor_id) == 'FULL':
                    dbd = DBD(lsdb)
                    packet = dbd.get_packet()
                    sock.sendto(packet.encode(), ('localhost', 10000 + neighbor_id))
            elif type(packet_obj) == LSR:
                if neighbor_table.exists(neighbor_id):
                    lsu = lsdb.get_lsu_from_lsr(packet_obj)
                    packet = lsu.get_packet()
                    sock.sendto(packet.encode(), ('localhost', 10000 + neighbor_id))
            elif type(packet_obj) == LSU:
                lsu_to_flood = lsdb.update_from_lsu_and_get_flood_lsu(packet_obj)
                if lsu_to_flood.empty() == False:
                    packet = lsu_to_flood.get_packet()
                    for neighbor_id in neighbor_table.routers():
                        sock.sendto(packet.encode(), ('localhost', 10000 + neighbor_id))
                    routing_table.perform_spf(lsdb)
            elif type(packet_obj) == DATA:
                if packet_obj.dest_id == my_router_id:
                    print(f'Recv message from {packet_obj.src_id}: {packet_obj.message}')
                else:
                    next_hop = routing_table.get_next_hop(
                        packet_obj.dest_id
                    )
                    if next_hop:
                        sock.sendto(
                            packet_obj.get_packet().encode(), 
                            ('localhost', 10000 + next_hop)
                        )
                        print(f'Forward message from {packet_obj.src_id} to {packet_obj.dest_id}: {packet_obj.message}')
                    else:
                        print('Destination unreachable')
        except socket.timeout:
            pass
        except OSError:
            break
    # print('Receive thread terminated.')

def manage_thread(sock, my_router_id):
    last_t_send_hello = time.time()
    last_t_send_dbd = time.time()
    last_t_lsa = time.time()
    while not shutdown_event.is_set():
        try:
            if time.time() - last_t_send_hello >= 1:
                for neighbor_id in neighbor_table.routers():
                    if neighbor_table.get_state(neighbor_id) == 'DOWN':
                        packet_obj = HELLO(False)
                        packet = packet_obj.get_packet()
                        sock.sendto(packet.encode(), ('localhost', 10000 + neighbor_id))
                    elif neighbor_table.get_state(neighbor_id) == 'INIT':
                        packet_obj = HELLO(True)
                        packet = packet_obj.get_packet()
                        sock.sendto(packet.encode(), ('localhost', 10000 + neighbor_id))
                    elif neighbor_table.get_state(neighbor_id) == 'EXCHANGE':
                        packet_obj = HELLO(True)
                        packet = packet_obj.get_packet()
                        sock.sendto(packet.encode(), ('localhost', 10000 + neighbor_id))
                last_t_send_hello = time.time()
            if time.time() - last_t_send_dbd >= 1:
                for neighbor_id in neighbor_table.routers():
                    if neighbor_table.get_state(neighbor_id) == 'EXCHANGE':
                        dbd = DBD(lsdb)
                        packet = dbd.get_packet()
                        sock.sendto(packet.encode(), ('localhost', 10000 + neighbor_id))
                last_t_send_dbd = time.time()
            if time.time() - last_t_lsa >= 15:
                lsu = LSU()
                lsdb.increment_seq()
                for router_id in lsdb.lsa_routers():
                    lsa_dict = lsdb.get_lsa(router_id)
                    lsu.add_lsa(router_id, lsa_dict['seq'], lsa_dict['links'])
                for neighbor_id in neighbor_table.routers():
                    packet = lsu.get_packet()
                    sock.sendto(packet.encode(), ('localhost', 10000 + neighbor_id))

                last_t_lsa = time.time()

            # Check LSA timeout
            for router_id in list(lsdb.lsa_routers()):
                if time.time() - lsdb.get_timestamp(router_id) >= 30 and router_id != my_router_id:
                    lsdb.remove_lsa(router_id)
                    routing_table.perform_spf(lsdb)
            time.sleep(1)
        except OSError:
            break
    # print('Manage thread terminated.')
def main():
    # Parse command line arguments
    parser = argparse.ArgumentParser(description='Network System Capstone Homework 4')
    parser.add_argument('id', type=int, help='Router ID')
    args = parser.parse_args()
    my_router_id = args.id

    # Initialize global variables
    global routing_table
    global neighbor_table
    global lsdb
    routing_table = RoutingTable(my_router_id)
    neighbor_table = NeighborTable()
    lsdb = LSDB(my_router_id)

    # Create a UDP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind(('', 10000 + my_router_id))
    sock.settimeout(1)

    # Start all threads
    recv_t = threading.Thread(target=receive_thread, args=(sock, my_router_id))
    recv_t.start()
    manage_t = threading.Thread(target=manage_thread, args=(sock, my_router_id))
    manage_t.start()

    # User input loop
    try:
        while True:
            command = input().split(sep=' ')
            if command[0] == 'exit':
                break
            elif command[0] == 'send':
                dest_id = int(command[1])
                message = ' '.join(command[2:])
                next_hop = routing_table.get_next_hop(dest_id)
                if next_hop:
                    packet = DATA({
                        'src_id': my_router_id,
                        'dest_id': dest_id,
                        'message': message
                    }).get_packet()
                    sock.sendto(packet.encode(), ('localhost', 10000 + next_hop))
                else:
                    print('Destination unreachable')
            elif command[0] == 'addlink':
                try:
                    router_id = int(command[1])
                    cost = int(command[2])
                except ValueError:
                    print('Invalid argument type')
                    continue

                # Add neighbor to neighbor table
                neighbor_table.add_neighbor(router_id, cost)

                # Add link to lsdb
                lsdb.add_link(my_router_id, router_id, cost)
                lsu = LSU()
                lsu.add_lsa(my_router_id, lsdb.get_seq(my_router_id), lsdb.get_links(my_router_id))

                # # Flood LSU packet
                # packet = lsu.get_packet()
                # for neighbor_id in neighbor_table.routers():
                #     sock.sendto(packet.encode(), ('localhost', 10000 + neighbor_id))

                # Perform SPF
                routing_table.perform_spf(lsdb)

            elif command[0] == 'rmlink':
                router_id = int(command[1])

                # Remove neighbor from neighbor table
                neighbor_table.remove_neighbor(router_id)

                # Remove link from lsdb
                lsdb.remove_link(my_router_id, router_id)
                lsu = LSU()
                lsu.add_lsa(my_router_id, lsdb.get_seq(my_router_id), lsdb.get_links(my_router_id))

                # Flood LSU packet
                packet = lsu.get_packet()
                for neighbor_id in neighbor_table.routers():
                    sock.sendto(packet.encode(), ('localhost', 10000 + neighbor_id))

                # Perform SPF
                routing_table.perform_spf(lsdb)

            elif command[0] == 'setlink':
                router_id = int(command[1])
                cost = int(command[2])

                # Update neighbor table
                neighbor_table.update_neighbor(router_id, cost)

                # Update lsdb
                lsdb.set_cost(my_router_id, router_id, cost)
                lsu = LSU()
                lsu.add_lsa(my_router_id, lsdb.get_seq(my_router_id), lsdb.get_links(my_router_id))

                # Flood LSU packet
                packet = lsu.get_packet()
                for neighbor_id in neighbor_table.routers():
                    sock.sendto(packet.encode(), ('localhost', 10000 + neighbor_id))

                # Perform SPF
                routing_table.perform_spf(lsdb)

            elif command[0] == 'show':
                if command[1] == 'neighbor':
                    print('Neighbor Table:')
                    neighbor_table.print()
                elif command[1] == 'lsdb':
                    print('LSDB:')
                    lsdb.print()           
                elif command[1] == 'routing':
                    print('Routing Table:')
                    routing_table.print()
                elif command[1] == 'all':
                    print('Neighbor Table:')
                    neighbor_table.print()
                    print('LSDB:')
                    lsdb.print()
                    print('Routing Table:')
                    routing_table.print()
            else:
                print('Invalid command')
        shutdown_event.set()
        sock.close()
        manage_t.join()
        recv_t.join()
    except KeyboardInterrupt:
        shutdown_event.set()
        sock.close()
        manage_t.join()
        recv_t.join()

if __name__ == '__main__':
    main()
