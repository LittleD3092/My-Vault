import socket
import time
import random
import sys
import ipaddress
import os
from queue import Queue
import threading

BOARD_ROW = 7
BOARD_COL = 9

class Network_tools:
    def get_local_ip(self):
        # Get the local IP address of the current machine
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        try:
            # doesn't have to be reachable, just needs to be a valid IP
            s.connect(('8.8.8.8', 1))  
            local_ip = s.getsockname()[0]
        except Exception:
            local_ip = '127.0.0.1'
        finally:
            s.close()
        return local_ip

    def is_private_ip(self, ip):
        return ipaddress.ip_address(ip).is_private

    def get_network_ips(self, local_ip):
        # Derive the network range based on the local IP and default subnet
        # This example assumes a /24 subnet
        network = ipaddress.IPv4Network(local_ip + '/24', strict=False)
        return [str(ip) for ip in network]

    def ping_ip(self, ip, active_ips):
        # Ping the IP to check if it is active
        response = os.system(f"ping -c 1 -W 1 {ip} > /dev/null 2>&1")  # '-W 1' sets a 1-second timeout
        if response == 0:
            active_ips.append(ip)

    def scan_network(self):
        local_ip = self.get_local_ip()

        if not self.is_private_ip(local_ip):
            return []
        
        network_ips = self.get_network_ips(local_ip)
        active_ips = []
        
        ip_queue = Queue()

        def worker():
            while not ip_queue.empty():
                ip = ip_queue.get()
                self.ping_ip(ip, active_ips)
                ip_queue.task_done()

        for ip in network_ips:
            ip_queue.put(ip)

        num_threads = 300
        for _ in range(num_threads):
            thread = threading.Thread(target=worker)
            thread.start()

        ip_queue.join()

        return active_ips

class UDP_client:
    def __init__(self, my_ip, my_port):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.settimeout(1)
        self.sock.bind((my_ip, my_port))

        self.my_ip = my_ip
        self.my_port = my_port

    def __del__(self):
        self.sock.close()

    def search(
        self, 
        ip_addresses,
        ports = range(11066, 11087)
    ):
        game_list = []
        for ip in ip_addresses:
            for port in ports:
                self.sock.sendto("c109611066 SEARCH\n".encode(), (ip, port))

        start_time = time.time()
        while time.time() - start_time < 3:
            try:
                data, addr = self.sock.recvfrom(4096)
            except socket.timeout:
                continue
            msg = data.decode()
            msg_list = msg.split()
            if msg_list[0] != "c109611066":
                continue
            if msg_list[1] == "HELLO":
                game_list.append((addr[0], addr[1]))
        return game_list
    
    def invite(self, ip, port):
        self.sock.sendto("c109611066 INVITE\n".encode(), (ip, port))
        print("Inviting " + "\033[0;35m" + "player-b" + "\033[0m" + " to play the game...")
        start_time = time.time()
        while time.time() - start_time < 60:
            try:
                data, addr = self.sock.recvfrom(4096)
            except socket.timeout:
                continue
            msg = data.decode()
            msg_list = msg.split()
            if msg_list[0] != "c109611066":
                continue
            if msg_list[1] == "ACCEPT":
                print("\033[0;35m" + "Player-b" + "\033[0m" + " has accepted the invitation.")
                return True
        print("\033[0;35m" + "Player-b" + "\033[0m" + " has not accepted the invitation.")
        return False
    
    def send_port(self, ip, port):
        self.sock.sendto(f"c109611066 PORT {self.my_port}\n".encode(), (ip, port))

class BattleShip:
    def __init__(self):
        self.board_a = [[' ' for _ in range(BOARD_COL)] for _ in range(BOARD_ROW)]
        self.board_b = [[' ' for _ in range(BOARD_COL)] for _ in range(BOARD_ROW)]
        
        self.letters_to_numbers = {
            chr(ord('A')+i): i for i in range(BOARD_COL)
        }

        self.SHIP_A = 5 # aircraft carrier
        self.SHIP_B = 4 # battleship
        self.SHIP_C = 3 # cruiser
        self.SHIP_S = 2 # submarine
        self.SHIP_P = 2 # patrol boat
        self.ships = {
            'A': self.SHIP_A,
            'B': self.SHIP_B,
            'C': self.SHIP_C,
            'S': self.SHIP_S,
            'P': self.SHIP_P
        }

        self.order = random.choice([['a', 'b'], ['b', 'a']])
        self.turn = 0

    def deploy_ships(self, tcp_server):
        self.deploy_player_ships(self.board_a)
        self.deploy_player_ships(self.board_b)

    def deploy_player_ships(self, board):
        for ship, size in self.ships.items():
            placed = False
            while not placed:
                orientation = random.choice(['H', 'V'])
                if orientation == 'H':
                    row = random.randint(0, BOARD_ROW - 1)
                    col = random.randint(0, BOARD_COL - size)
                    if all(
                        board[row][col+i] == ' ' 
                        for i in range(size)
                    ):
                        for i in range(size):
                            board[row][col+i] = ship
                        placed = True
                else:
                    row = random.randint(0, BOARD_ROW - size)
                    col = random.randint(0, BOARD_COL - 1)
                    if all(
                        board[row+i][col] == ' '
                        for i in range(size)
                    ):
                        for i in range(size):
                            board[row+i][col] = ship
                        placed = True

    def print_board(self, board, opponent_board, player = 'a'):
        if player == 'a':
            print("\033[0;35m" + "Opponent's" + "\033[0m" + " board:")
            print("\033[1m" + "  " + " ".join([chr(ord('A')+i) for i in range(BOARD_COL)]) + "\033[0m")
            for row_num, row in enumerate(opponent_board):
                censored_row = [
                    cell if cell in 'OX' else ' ' for cell in row
                ]
                print("\033[1m" + f"{row_num} " + "\033[0;31m" + " ".join(censored_row) + "\033[0m")
            print()

            print("\033[0;35m" + "Your" + "\033[0m" + " board:")
            print("\033[1m" + "  " + " ".join([chr(ord('A')+i) for i in range(BOARD_COL)]) + "\033[0m")
            for row_num, row in enumerate(board):
                colored_row = []
                for cell in row:
                    if cell == 'O' or cell == 'X':
                        colored_row.append("\033[0;31m" + str(cell) + "\033[0m")
                    elif cell in 'ABCSP':
                        colored_row.append("\033[0;32m" + str(cell) + "\033[0m")
                    else:
                        colored_row.append(str(cell))
                print("\033[1m" + f"{row_num} " + "\033[0m" + " ".join(colored_row))

        else: # player == 'b'
            tcp_server.send("\033[0;35m" + "Opponent's" + "\033[0m" + " board:")
            tcp_server.send("\033[1m" + "  " + " ".join([chr(ord('A')+i) for i in range(BOARD_COL)]) + "\033[0m")
            for row_num, row in enumerate(opponent_board):
                censored_row = [
                    cell if cell in 'OX' else ' ' for cell in row
                ]
                tcp_server.send(
                    "\033[1m" + f"{row_num} " + "\033[0;31m" + " ".join(censored_row) + "\033[0m"
                )
            tcp_server.send('')

            tcp_server.send("\033[0;35m" + "Your" + "\033[0m" + " board:")
            tcp_server.send("\033[1m" + "  " + " ".join([chr(ord('A')+i) for i in range(BOARD_COL)]) + "\033[0m")
            for row_num, row in enumerate(board):
                colored_row = []
                for cell in row:
                    if cell == 'O' or cell == 'X':
                        colored_row.append("\033[0;31m" + str(cell) + "\033[0m")
                    elif cell in 'ABCSP':
                        colored_row.append("\033[0;32m" + str(cell) + "\033[0m")
                    else:
                        colored_row.append(str(cell))
                tcp_server.send("\033[1m" + f"{row_num} " + "\033[0m" + " ".join(colored_row))

    def get_move(self, player, tcp_server):
        if player == 'a':
            while True:
                try:
                    move = input("\033[0;35m" + "Player-a" + "\033[0m" + ", enter your move " + "\033[0;32m" + "(e.g. A5)" + "\033[0m" + ": ").upper()
                    row, col = int(move[1]), self.letters_to_numbers[move[0]]
                    if self.board_b[row][col] == 'O' or self.board_b[row][col] == 'X':
                        print("Invalid move, please try again.")
                        continue
                    if 0 <= row < BOARD_ROW and 0 <= col < BOARD_COL:
                        return row, col
                except (IndexError, KeyError, ValueError):
                    print("Invalid move, please try again.")
        else:
            tcp_server.send("\033[0;35m" + "Player-b" + "\033[0m" + ", enter your move " + "\033[0;32m" + "(e.g. A5)" + "\033[0m" + ": NO_ENDL")
            tcp_server.send("INPUT")
            while True:
                move = tcp_server.recv().upper()
                try:
                    row, col = int(move[1]), self.letters_to_numbers[move[0]]
                    if self.board_a[row][col] == 'O' or self.board_a[row][col] == 'X':
                        tcp_server.send("Invalid move, please try again:  NO_ENDL")
                        tcp_server.send("INPUT")
                        continue
                    if 0 <= row < BOARD_ROW and 0 <= col < BOARD_COL:
                        return row, col
                except (IndexError, KeyError, ValueError):
                    tcp_server.send("Invalid move, please try again:  NO_ENDL")
                    tcp_server.send("INPUT")

    def make_move(self, board, row, col):
        if board[row][col] == ' ':
            board[row][col] = 'O'
            return False
        elif board[row][col] != 'O' and board[row][col] != 'X':
            board[row][col] = 'X'
            return True
        return False
    
    def is_winner(self, board):
        for row in board:
            if any([cell in 'ABCSP' for cell in row]):
                return False
        return True
    
    def play_game(self, tcp_server):
        print("\033[0;35m" + f"Player-{self.order[self.turn]}" + "\033[0m" + " goes first.")
        tcp_server.send("\033[0;35m" + f"Player-{self.order[self.turn]}" + "\033[0m" + " goes first.")

        # print board for 2nd player
        if self.order[self.turn] == 'b':
            self.print_board(self.board_a, self.board_b, 'a')
        else:
            self.print_board(self.board_b, self.board_a, 'b')

        while True:
            current_player = self.order[self.turn % 2]
            board = self.board_a if current_player == 'a' else self.board_b
            opponent_board = self.board_a if current_player == 'b' else self.board_b
            print("\n" + "\033[0;35m" + f"Player-{current_player}'s" + "\033[0m" + " turn:")
            tcp_server.send("\033[0;35m" + f"Player-{current_player}'s" + "\033[0m" + " turn:")
            self.print_board(board, opponent_board, current_player)

            row, col = self.get_move(current_player, tcp_server)
            hit = self.make_move(opponent_board, row, col)
            if hit:
                print("\033[0:35m" + f"Player-{current_player}" + "\033[0;31m" + " hit" + "\033[0m" + " a ship at " + "\033[0;33m" + f"{chr(col+ord('A'))}{row}" + "\033[0m" + ".")
                tcp_server.send("\033[0:35m" + f"Player-{current_player}" + "\033[0;31m" + " hit" + "\033[0m" + " a ship at " + "\033[0;33m" + f"{chr(col+ord('A'))}{row}" + "\033[0m" + ".")
            else:
                print("\033[0:35m" + f"Player-{current_player}" + "\033[0;31m" + " missed" + "\033[0m" + " at " + "\033[0;33m" + f"{chr(col+ord('A'))}{row}" + "\033[0m" + ".")
                tcp_server.send("\033[0:35m" + f"Player-{current_player}" + "\033[0;31m" + " missed" + "\033[0m" + " at " + "\033[0;33m" + f"{chr(col+ord('A'))}{row}" + "\033[0m" + ".")
            time.sleep(1)
            self.print_board(board, opponent_board, current_player)

            if hit:
                self.print_board(opponent_board, board, self.order[(self.turn + 1) % 2])

            if self.is_winner(opponent_board):
                print("\033[0;35m" + f"Player-{current_player}" + "\033[0m" + " wins!")
                # tcp_server.send(f"Player-{current_player} wins!")
                tcp_server.send("\033[0;35m" + f"Player-{current_player}" + "\033[0m" + " wins!")
                tcp_server.send("END")
                break

            if not hit:
                self.turn += 1

    def main(self, tcp_server):
        self.deploy_ships(tcp_server)
        self.play_game(tcp_server)

class TCP_server:
    def __init__(self, my_ip, my_port):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.bind((my_ip, my_port))
        self.sock.listen(1)
        self.conn, self.addr = self.sock.accept()
        print("Connected to " + "\033[0;35m" + "player-b" + "\033[0m" + ".")

        self.buffer = ''

    def __del__(self):
        if 'conn' in self.__dict__:
            self.conn.close()
        self.sock.close()

    def send(self, msg):
        msg += '\n'
        self.conn.sendall(msg.encode())

    def recv(self):
        if '\n' not in self.buffer:
            self.buffer += self.conn.recv(4096).decode()

        msg, self.buffer = self.buffer.split('\n', 1)
        return msg

if __name__ == "__main__":
    args = sys.argv

    # enter the port for player-a
    try:
        my_port = input("Please enter the " + "\033[0;36m" + "port\033[0m for \033[0;35mplayer-a\033[0m: ")
        udp_client = UDP_client('0.0.0.0', int(my_port))
    except Exception as e:
        print("Error: ", e)
        exit()

    # search for player-b
    ip_addresses = ['140.113.235.151', '140.113.235.152', '140.113.235.153', '140.113.235.154']
    active_ips = Network_tools().scan_network()
    ip_addresses.extend(active_ips)
    game_list = udp_client.search(ip_addresses)

    # prompt the user to select a game
    print("\033[1;33m" + "Game list:" + "\033[0m")
    for i, game in enumerate(game_list):
        print(
            '\033[0;32m', i, ')', '\033[0m', 
            ' address:', game[0], ' port:', game[1], sep=''
        )
    game_index = input("Please select a game by " + "\033[0;36m" + "index" + "\033[0m" + ": ")
    game = game_list[int(game_index)]

    # invite player-b to play the game
    invite_success = udp_client.invite(game[0], game[1])
    if not invite_success:
        print("Failed to invite player-b to play the game.")
        exit()

    # send port info
    udp_client.send_port(game[0], game[1])

    # close UDP client
    del udp_client

    # start TCP server
    while True:
        try:
            tcp_server = TCP_server('0.0.0.0', int(my_port))
            break
        except:
            print("Failed to start TCP server. Retrying...")
            time.sleep(1)

    # start the game
    battle_ship = BattleShip()
    battle_ship.main(tcp_server)