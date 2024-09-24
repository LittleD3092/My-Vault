import socket
import time
import random
import sys

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
        ip_addresses = ['140.113.235.151', '140.113.235.152', '140.113.235.153', '140.113.235.154'],
        ports = range(11066, 11087)
    ):
        game_list = []
        for ip in ip_addresses:
            for port in ports:
                self.sock.sendto("c109611066 SEARCH".encode(), (ip, port))

        start_time = time.time()
        while time.time() - start_time < 5:
            data, addr = self.sock.recvfrom(4096)
            msg = data.decode()
            msg_list = msg.split()
            if msg_list[0] != "c109611066":
                continue
            if msg_list[1] == "HELLO":
                game_list.append((addr[0], addr[1]))
        return game_list
    
    def invite(self, ip, port):
        self.sock.sendto("c109611066 INVITE".encode(), (ip, port))
        print("Inviting player-b to play the game...")
        start_time = time.time()
        while time.time() - start_time < 60:
            data, addr = self.sock.recvfrom(4096)
            msg = data.decode()
            msg_list = msg.split()
            if msg_list[0] != "c109611066":
                continue
            if msg_list[1] == "ACCEPT":
                print("Player-b has accepted the invitation.")
                return True
        print("Player-b has not accepted the invitation.")
        return False
    
    def send_port(self, ip, port):
        self.sock.sendto(f"c109611066 PORT {self.my_port}".encode(), (ip, port))

class BattleShip:
    def __init__(self):
        self.board_a = [[' ' for _ in range(10)] for _ in range(10)]
        self.board_b = [[' ' for _ in range(10)] for _ in range(10)]
        
        self.letters_to_numbers = {chr(ord('A')+i): i for i in range(10)}

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
                    row = random.randint(0, 9)
                    col = random.randint(0, 9 - size + 1)
                    if all(board[row][col+i] == ' ' for i in range(size)):
                        for i in range(size):
                            board[row][col+i] = ship
                        placed = True
                else:
                    row = random.randint(0, 9 - size + 1)
                    col = random.randint(0, 9)
                    if all(board[row+i][col] == ' ' for i in range(size)):
                        for i in range(size):
                            board[row+i][col] = ship
                        placed = True

    def print_board(self, board, opponent_board, player = 'a'):
        if player == 'a':
            print("Opponent's board:")
            print("  A B C D E F G H I J")
            for row_num, row in enumerate(opponent_board):
                censored_row = [cell if cell in 'OX' else ' ' for cell in row]
                print(f"{row_num} " + " ".join(censored_row))
            print()

            print("Your board:")
            print("  A B C D E F G H I J")
            for row_num, row in enumerate(board):
                print(f"{row_num} " + " ".join(row))

        else: # player == 'b'
            tcp_server.send("Opponent's board:")
            tcp_server.send("  A B C D E F G H I J")
            for row_num, row in enumerate(opponent_board):
                censored_row = [cell if cell in 'OX' else ' ' for cell in row]
                tcp_server.send(f"{row_num} " + " ".join(censored_row))
            tcp_server.send()

            tcp_server.send("Your board:")
            tcp_server.send("  A B C D E F G H I J")
            for row_num, row in enumerate(board):
                tcp_server.send(f"{row_num} " + " ".join(row))

    def get_move(self, player, tcp_server):
        if player == 'a':
            while True:
                try:
                    move = input("Player-a, enter your move (e.g. A5): ").upper()
                    row, col = int(move[1]), self.letters_to_numbers[move[0]]
                    if 0 <= row < 10 and 0 <= col < 10:
                        return row, col
                except (IndexError, KeyError, ValueError):
                    print("Invalid move, please try again.")
        else:
            tcp_server.send("Player-b, enter your move (e.g. A5): ")
            while True:
                move = tcp_server.recv().upper()
                try:
                    row, col = int(move[1]), self.letters_to_numbers[move[0]]
                    if 0 <= row < 10 and 0 <= col < 10:
                        return row, col
                except (IndexError, KeyError, ValueError):
                    tcp_server.send("Invalid move, please try again: ")

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
        print(f"Player-{self.order[self.turn]} goes first.")
        tcp_server.send(f"Player-{self.order[self.turn]} goes first.")
        while True:
            current_player = self.order[self.turn % 2]
            board = self.board_a if current_player == 'a' else self.board_b
            opponent_board = self.board_a if current_player == 'b' else self.board_b
            print(f"\nPlayer-{current_player}'s turn:")
            tcp_server.send(f"\nPlayer-{current_player}'s turn:")
            self.print_board(board, opponent_board, current_player)

            row, col = self.get_move(current_player, tcp_server)
            hit = self.make_move(opponent_board, row, col)
            if hit:
                print(f"Player-{current_player} hit a ship at {chr(col+ord('A'))}{row}.")
                tcp_server.send(f"Player-{current_player} hit a ship at {chr(col+ord('A'))}{row}.")
            else:
                print(f"Player-{current_player} missed at {chr(col+ord('A'))}{row}.")
                tcp_server.send(f"Player-{current_player} missed at {chr(col+ord('A'))}{row}.")

            if self.is_winner(opponent_board):
                print(f"Player-{current_player} wins!")
                tcp_server.send(f"Player-{current_player} wins!")
                break

            self.turn += 1

    def main(self, tcp_server):
        self.deploy_ships(tcp_server)
        self.play_game(tcp_server)

class TCP_server:
    def __init__(self, my_ip, my_port):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.bind((my_ip, my_port))
        self.conn, self.addr = self.sock.accept()
        print("Connected to player-b.")

        self.buffer = ''

    def __del__(self):
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
        my_port = input("Please enter the port for player-a: ")
        udp_client = UDP_client('0.0.0.0', int(my_port))
    except Exception as e:
        print("Error: ", e)
        exit()

    # search for player-b
    if '--local' in args or '-l' in args:
        game_list = udp_client.search(ip_addresses=['localhost'])
    else:
        game_list = udp_client.search()

    # prompt the user to select a game
    print("Game list:")
    for i, game in enumerate(game_list):
        print(i, 'address:', game[0], 'port:', game[1])
    game_index = input("Please select a game by index: ")
    game = game_list[int(game_index)]

    # invite player-b to play the game
    invite_success = udp_client.invite(game[0], game[1])
    if not invite_success:
        exit()

    # send port info
    udp_client.send_port(game[0], game[1])

    # close UDP client
    del udp_client

    # start TCP server
    try:
        tcp_server = TCP_server('0.0.0.0', int(my_port))
    except Exception as e:
        print("Error: ", e)
        exit()

    # start the game
    battle_ship = BattleShip()
    battle_ship.main(tcp_server)