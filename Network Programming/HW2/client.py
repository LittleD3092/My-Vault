import socket
import time
import threading
import random
import ipaddress
from queue import Queue
import os
import traceback

LOBBY_IP = 'linux1.cs.nycu.edu.tw'
LOBBY_PORT = 11066

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

class BattleShip:
    def __init__(self):
        self.BOARD_ROW = 7
        self.BOARD_COL = 9

        self.board_a = [[' ' for _ in range(self.BOARD_COL)] for _ in range(self.BOARD_ROW)]
        self.board_b = [[' ' for _ in range(self.BOARD_COL)] for _ in range(self.BOARD_ROW)]
        
        self.letters_to_numbers = {
            chr(ord('A')+i): i for i in range(self.BOARD_COL)
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

        self.input_buffer = ""
        self.order = random.choice([['a', 'b'], ['b', 'a']])
        self.turn = 0

    def deploy_ships(self):
        self.deploy_player_ships(self.board_a)
        self.deploy_player_ships(self.board_b)

    def deploy_player_ships(self, board):
        for ship, size in self.ships.items():
            placed = False
            while not placed:
                orientation = random.choice(['H', 'V'])
                if orientation == 'H':
                    row = random.randint(0, self.BOARD_ROW - 1)
                    col = random.randint(0, self.BOARD_COL - size)
                    if all(
                        board[row][col+i] == ' ' 
                        for i in range(size)
                    ):
                        for i in range(size):
                            board[row][col+i] = ship
                        placed = True
                else:
                    row = random.randint(0, self.BOARD_ROW - size)
                    col = random.randint(0, self.BOARD_COL - 1)
                    if all(
                        board[row+i][col] == ' '
                        for i in range(size)
                    ):
                        for i in range(size):
                            board[row+i][col] = ship
                        placed = True

    def print_board(self, board, opponent_board, player = 'a', tcp_server = None):
        if player == 'a':
            print("\033[0;35m" + "Opponent's" + "\033[0m" + " board:")
            print("\033[1m" + "  " + " ".join([chr(ord('A')+i) for i in range(self.BOARD_COL)]) + "\033[0m")
            for row_num, row in enumerate(opponent_board):
                censored_row = [
                    cell if cell in 'OX' else ' ' for cell in row
                ]
                print("\033[1m" + f"{row_num} " + "\033[0;31m" + " ".join(censored_row) + "\033[0m")
            print()

            print("\033[0;35m" + "Your" + "\033[0m" + " board:")
            print("\033[1m" + "  " + " ".join([chr(ord('A')+i) for i in range(self.BOARD_COL)]) + "\033[0m")
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
            tcp_server.send("\033[1m" + "  " + " ".join([chr(ord('A')+i) for i in range(self.BOARD_COL)]) + "\033[0m")
            for row_num, row in enumerate(opponent_board):
                censored_row = [
                    cell if cell in 'OX' else ' ' for cell in row
                ]
                tcp_server.send(
                    "\033[1m" + f"{row_num} " + "\033[0;31m" + " ".join(censored_row) + "\033[0m"
                )
            tcp_server.send('')

            tcp_server.send("\033[0;35m" + "Your" + "\033[0m" + " board:")
            tcp_server.send("\033[1m" + "  " + " ".join([chr(ord('A')+i) for i in range(self.BOARD_COL)]) + "\033[0m")
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
                    print("\033[0;35m" + "Player-a" + "\033[0m" + ", enter your move " + "\033[0;32m" + "(e.g. A5, or CONCEDE)" + "\033[0m" + ": ")
                    move = self.get_input_buffer().upper()
                    if move == "CONCEDE":
                        tcp_server.send("Player-a has conceded.")
                        print("Player-a has conceded.")
                        for row in range(self.BOARD_ROW):
                            for col in range(self.BOARD_COL):
                                if self.board_a[row][col] in 'ABCSP':
                                    self.board_a[row][col] = 'X'
                        return None, None
                    else:
                        row, col = int(move[1]), self.letters_to_numbers[move[0]]
                        if self.board_b[row][col] == 'O' or self.board_b[row][col] == 'X':
                            print("\033[0;31mInvalid move, please try again.\033[0m")
                            continue
                        if 0 <= row < self.BOARD_ROW and 0 <= col < self.BOARD_COL:
                            return row, col
                except (IndexError, KeyError, ValueError):
                    print("\033[0;31mInvalid move, please try again.\033[0m")
        else:
            tcp_server.send("\033[0;35m" + "Player-b" + "\033[0m" + ", enter your move " + "\033[0;32m" + "(e.g. A5, or CONCEDE)" + "\033[0m" + ":")
            while True:
                move = tcp_server.recv().upper()
                try:
                    if move == "CONCEDE":
                        tcp_server.send("Player-b has conceded.")
                        print("Player-b has conceded.")
                        for row in range(self.BOARD_ROW):
                            for col in range(self.BOARD_COL):
                                if self.board_b[row][col] in 'ABCSP':
                                    self.board_b[row][col] = 'X'
                        return None, None
                    else:
                        row, col = int(move[1]), self.letters_to_numbers[move[0]]
                        if self.board_a[row][col] == 'O' or self.board_a[row][col] == 'X':
                            tcp_server.send("\033[0;31mInvalid move, please try again:\033[0m")
                            continue
                        if 0 <= row < self.BOARD_ROW and 0 <= col < self.BOARD_COL:
                            return row, col
                except (IndexError, KeyError, ValueError):
                    tcp_server.send("\033[0;31mInvalid move, please try again:\033[0m")

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
            self.print_board(self.board_a, self.board_b, 'a', tcp_server)
        else:
            self.print_board(self.board_b, self.board_a, 'b', tcp_server)

        while True:
            current_player = self.order[self.turn % 2]
            board = self.board_a if current_player == 'a' else self.board_b
            opponent_board = self.board_a if current_player == 'b' else self.board_b
            print("\n" + "\033[0;35m" + f"Player-{current_player}'s" + "\033[0m" + " turn.")
            tcp_server.send("\033[0;35m" + f"Player-{current_player}'s" + "\033[0m" + " turn.")
            self.print_board(board, opponent_board, current_player, tcp_server)

            row, col = self.get_move(current_player, tcp_server)
            if row != None and col != None:
                hit = self.make_move(opponent_board, row, col)
                if hit:
                    print("\033[0:35m" + f"Player-{current_player}" + "\033[0;31m" + " hit" + "\033[0m" + " a ship at " + "\033[0;33m" + f"{chr(col+ord('A'))}{row}" + "\033[0m" + ".")
                    tcp_server.send("\033[0:35m" + f"Player-{current_player}" + "\033[0;31m" + " hit" + "\033[0m" + " a ship at " + "\033[0;33m" + f"{chr(col+ord('A'))}{row}" + "\033[0m" + ".")
                else:
                    print("\033[0:35m" + f"Player-{current_player}" + "\033[0;31m" + " missed" + "\033[0m" + " at " + "\033[0;33m" + f"{chr(col+ord('A'))}{row}" + "\033[0m" + ".")
                    tcp_server.send("\033[0:35m" + f"Player-{current_player}" + "\033[0;31m" + " missed" + "\033[0m" + " at " + "\033[0;33m" + f"{chr(col+ord('A'))}{row}" + "\033[0m" + ".")
            time.sleep(1)
            self.print_board(board, opponent_board, current_player, tcp_server)

            if row != None and col != None and hit:
                self.print_board(opponent_board, board, self.order[(self.turn + 1) % 2], tcp_server)

            if self.is_winner(opponent_board):
                print("\033[0;35m" + f"Player-{current_player}" + "\033[0m" + " wins!")
                tcp_server.send("\033[0;35m" + f"Player-{current_player}" + "\033[0m" + " wins!")
                tcp_server.send("GAME_END")
                break
            elif self.is_winner(board):
                opponent_player = self.order[(self.turn + 1) % 2]
                print("\033[0;35m" + f"Player-{opponent_player}" + "\033[0m" + " wins!")
                tcp_server.send("\033[0;35m" + f"Player-{opponent_player}" + "\033[0m" + " wins!")
                tcp_server.send("GAME_END")
                break

            if not hit:
                self.turn += 1

    def local_input(self, input_str):
        self.input_buffer += input_str
        if '\n' not in self.input_buffer:
            self.input_buffer += '\n'

    def get_input_buffer(self):
        while '\n' not in self.input_buffer:
            time.sleep(1)
            
        msg, self.input_buffer = self.input_buffer.split('\n', 1)
        return msg

    def main(self, tcp_server):
        self.deploy_ships()
        self.play_game(tcp_server)

class Checkers:
    def __init__(self) -> None:
        self.BOARD_SIZE = 8

        self.board = [[' ' for _ in range(self.BOARD_SIZE)] for _ in range(self.BOARD_SIZE)]

        self.input_buffer = ""
        self.order = random.choice([['a', 'b'], ['b', 'a']])
        self.turn = 0

        self.letters_to_numbers = {
            chr(ord('A')+i): i for i in range(self.BOARD_SIZE)
        }

    def init_board(self):
        for row in range(self.BOARD_SIZE):
            for col in range(self.BOARD_SIZE):
                if abs(row - col) % 2 == 1:
                    if row < 3:
                        self.board[row][col] = 'a'
                    elif row > 4:
                        self.board[row][col] = 'b'

    def print_board(self, board, player = 'a', tcp_server = None):
        if player == 'a':
            print("   H  G  F  E  D  C  B  A")
            for row_num in range(self.BOARD_SIZE - 1, -1, -1):
                print(f"{row_num + 1} ", end="")
                for col_num in range(self.BOARD_SIZE - 1, -1, -1):
                    if board[row_num][col_num] == 'a':
                        print(f" \033[0;31;40m\uf444\033[0m ", end="")
                    elif board[row_num][col_num] == 'b':
                        print(f" \033[0;40m\uf444\033[0m ", end="")
                    elif board[row_num][col_num] == 'A':
                        print(f" \033[0;31;40m\udb85\udfdc\033[0m ".encode("utf-16", "surrogatepass").decode("utf-16"), end="")
                    elif board[row_num][col_num] == 'B':
                        print(f" \033[0;40m\udb85\udfdc\033[0m ".encode("utf-16", "surrogatepass").decode("utf-16"), end="")
                    elif (row_num + col_num) % 2 == 0:
                        print("\033[0;47m   \033[0m", end="")
                    else:
                        print("\033[0;40m   \033[0m", end="")
                print()
        else: # player == 'b'
            tcp_server.send("   A  B  C  D  E  F  G  H")
            for row_num in range(self.BOARD_SIZE):
                row = f"{row_num + 1} "
                for col_num in range(self.BOARD_SIZE):
                    if board[row_num][col_num] == 'a':
                        row += f" \033[0;31;40m\uf444\033[0m "
                    elif board[row_num][col_num] == 'b':
                        row += f" \033[0;40m\uf444\033[0m "
                    elif board[row_num][col_num] == 'A':
                        row += f" \033[0;31;40m\udb85\udfdc\033[0m ".encode("utf-16", "surrogatepass").decode("utf-16")
                    elif board[row_num][col_num] == 'B':
                        row += f" \033[0;40m\udb85\udfdc\033[0m ".encode("utf-16", "surrogatepass").decode("utf-16")
                    elif (row_num + col_num) % 2 == 0:
                        row += "\033[0;47m   \033[0m"
                    else:
                        row += "\033[0;40m   \033[0m"
                tcp_server.send(row)

    def local_input(self, input_str):
        self.input_buffer += input_str
        if '\n' not in self.input_buffer:
            self.input_buffer += '\n'

    def get_input_buffer(self):
        while '\n' not in self.input_buffer:
            time.sleep(1)
            
        msg, self.input_buffer = self.input_buffer.split('\n', 1)
        return msg
    
    def can_capture(self, board, player):
        for row in range(self.BOARD_SIZE):
            for col in range(self.BOARD_SIZE):
                if board[row][col] == 'a' and player == 'a':
                    if row < self.BOARD_SIZE - 2 and col < self.BOARD_SIZE - 2:
                        if board[row+1][col+1] in 'bB' and board[row+2][col+2] == ' ':
                            return True
                    if row < self.BOARD_SIZE - 2 and col > 1:
                        if board[row+1][col-1] in 'bB' and board[row+2][col-2] == ' ':
                            return True
                elif board[row][col] == 'b' and player == 'b':
                    if row > 1 and col < self.BOARD_SIZE - 2:
                        if board[row-1][col+1] in 'aA' and board[row-2][col+2] == ' ':
                            return True
                    if row > 1 and col > 1:
                        if board[row-1][col-1] in 'aA' and board[row-2][col-2] == ' ':
                            return True
                elif board[row][col] == 'A' and player == 'a':
                    if row < self.BOARD_SIZE - 2 and col < self.BOARD_SIZE - 2:
                        if board[row+1][col+1] in 'bB' and board[row+2][col+2] == ' ':
                            return True
                    if row < self.BOARD_SIZE - 2 and col > 1:
                        if board[row+1][col-1] in 'bB' and board[row+2][col-2] == ' ':
                            return True
                    if row > 1 and col < self.BOARD_SIZE - 2:
                        if board[row-1][col+1] in 'bB' and board[row-2][col+2] == ' ':
                            return True
                    if row > 1 and col > 1:
                        if board[row-1][col-1] in 'bB' and board[row-2][col-2] == ' ':
                            return True
                elif board[row][col] == 'B' and player == 'b':
                    if row < self.BOARD_SIZE - 2 and col < self.BOARD_SIZE - 2:
                        if board[row+1][col+1] in 'aA' and board[row+2][col+2] == ' ':
                            return True
                    if row < self.BOARD_SIZE - 2 and col > 1:
                        if board[row+1][col-1] in 'aA' and board[row+2][col-2] == ' ':
                            return True
                    if row > 1 and col < self.BOARD_SIZE - 2:
                        if board[row-1][col+1] in 'aA' and board[row-2][col+2] == ' ':
                            return True
                    if row > 1 and col > 1:
                        if board[row-1][col-1] in 'aA' and board[row-2][col-2] == ' ':
                            return True
        return False
    
    def can_capture_from(self, player, col, row):
        if player == 'a':
            if row < self.BOARD_SIZE - 2 and col < self.BOARD_SIZE - 2:
                if self.board[row+1][col+1] in 'bB' and self.board[row+2][col+2] == ' ':
                    return True
            if row < self.BOARD_SIZE - 2 and col > 1:
                if self.board[row+1][col-1] in 'bB' and self.board[row+2][col-2] == ' ':
                    return True
            
            # King pieces
            if self.board[row][col] == 'A':
                if row > 1 and col < self.BOARD_SIZE - 2:
                    if self.board[row-1][col+1] in 'bB' and self.board[row-2][col+2] == ' ':
                        return True
                if row > 1 and col > 1:
                    if self.board[row-1][col-1] in 'bB' and self.board[row-2][col-2] == ' ':
                        return True
        elif player == 'b':
            if row > 1 and col < self.BOARD_SIZE - 2:
                if self.board[row-1][col+1] in 'aA' and self.board[row-2][col+2] == ' ':
                    return True
            if row > 1 and col > 1:
                if self.board[row-1][col-1] in 'aA' and self.board[row-2][col-2] == ' ':
                    return True
                
            # King pieces
            if self.board[row][col] == 'B':
                if row < self.BOARD_SIZE - 2 and col < self.BOARD_SIZE - 2:
                    if self.board[row+1][col+1] in 'aA' and self.board[row+2][col+2] == ' ':
                        return True
                if row < self.BOARD_SIZE - 2 and col > 1:
                    if self.board[row+1][col-1] in 'aA' and self.board[row+2][col-2] == ' ':
                        return True
        return False

    def move_valid(self, board, player, src_col, src_row, dest_col, dest_row, constraint_src_col = None, constraint_src_row = None):
            # Check within bounds
            if not (0 <= src_row < self.BOARD_SIZE and 0 <= src_col < self.BOARD_SIZE):
                print("Source out of bounds")
                return False
            if not (0 <= dest_row < self.BOARD_SIZE and 0 <= dest_col < self.BOARD_SIZE):
                print("Destination out of bounds")
                return False
            
            # Check if source is the player's piece
            if (
                constraint_src_col != None and constraint_src_row != None and
                (constraint_src_col != src_col or constraint_src_row != src_row)
            ):
                print("Player must capture if possible")
                
                return False
            
            # Check if source has the player's piece
            piece = board[src_row][src_col]
            if piece not in player and piece not in player.upper():
                print("Source does not have the player's piece")
                return False
            
            # Check if destination is empty
            if board[dest_row][dest_col] != ' ':
                print("Destination is not empty")
                return False
            
            # Calculate row and column differences
            row_diff = dest_row - src_row
            col_diff = dest_col - src_col

            # Can capture but not capturing
            if self.can_capture(board, player) and abs(row_diff) == 1 and abs(col_diff) == 1:
                print("Player must capture if possible")
                return False

            # Movement rules for regular pieces
            if piece == 'a' or piece == 'b':
                # Regular moves (one step diagonally forward)
                if player == 'a' and row_diff == 1 and abs(col_diff) == 1:
                    return True
                elif player == 'b' and row_diff == -1 and abs(col_diff) == 1:
                    return True

                # Capture move (two steps diagonally with an opponent's piece in between)
                if abs(row_diff) == 2 and abs(col_diff) == 2:
                    mid_row = (src_row + dest_row) // 2
                    mid_col = (src_col + dest_col) // 2
                    mid_piece = board[mid_row][mid_col]
                    if player == 'a' and mid_piece in 'bB':
                        return True
                    elif player == 'b' and mid_piece in 'aA':
                        return True
                print("Invalid move for regular piece")
                return False
            # Movement rules for king pieces
            elif piece == 'A' or piece == 'B':
                # King moves (one step diagonally in any direction)
                if abs(row_diff) == 1 and abs(col_diff) == 1:
                    return True

                # King capture moves (two steps diagonally in any direction with an opponent's piece in between)
                if abs(row_diff) == 2 and abs(col_diff) == 2:
                    mid_row = (src_row + dest_row) // 2
                    mid_col = (src_col + dest_col) // 2
                    mid_piece = board[mid_row][mid_col]
                    if player == 'a' and mid_piece in 'bB':
                        return True
                    elif player == 'b' and mid_piece in 'aA':
                        return True
                print("Invalid move for king piece")
                return False
            print("Invalid piece")
            return False

    def get_move(self, player, tcp_server, constraint_src_col = None, constraint_src_row = None):
        if player == 'a':
            while True:
                try:
                    print("\033[0;35m" + "Player-a" + "\033[0m" + ", enter your move " + "\033[0;32m" + "(e.g. B3 A4, or CONCEDE)" + "\033[0m" + ": ")
                    move = self.get_input_buffer().upper()
                    if move == "CONCEDE":
                        tcp_server.send("Player-a has conceded.")
                        print("Player-a has conceded.")
                        for row in range(self.BOARD_SIZE):
                            for col in range(self.BOARD_SIZE):
                                if self.board[row][col] in 'aA':
                                    self.board[row][col] = ' '
                        return None, None, None, None
                    else:
                        src_col, src_row, dest_col, dest_row = self.letters_to_numbers[move[0]], int(move[1]) - 1, self.letters_to_numbers[move[3]], int(move[4]) - 1
                        if self.move_valid(self.board, player, src_col, src_row, dest_col, dest_row, constraint_src_col, constraint_src_row):
                            return src_col, src_row, dest_col, dest_row
                        else:
                            print("\033[0;31mInvalid move, please try again.\033[0m")
                except (IndexError, KeyError, ValueError):
                    print("\033[0;31mInvalid move, please try again.\033[0m")
        else:
            tcp_server.send("\033[0;35m" + "Player-b" + "\033[0m" + ", enter your move " + "\033[0;32m" + "(e.g. G6 H5, or CONCEDE)" + "\033[0m" + ":")
            while True:
                move = tcp_server.recv().upper()
                try:
                    if move == "CONCEDE":
                        tcp_server.send("Player-b has conceded.")
                        print("Player-b has conceded.")
                        for row in range(self.BOARD_SIZE):
                            for col in range(self.BOARD_SIZE):
                                if self.board[row][col] in 'bB':
                                    self.board[row][col] = ' '
                        return None, None, None, None
                    else:
                        src_col, src_row, dest_col, dest_row = self.letters_to_numbers[move[0]], int(move[1]) - 1, self.letters_to_numbers[move[3]], int(move[4]) - 1
                        if self.move_valid(self.board, player, src_col, src_row, dest_col, dest_row, constraint_src_col, constraint_src_row):
                            return src_col, src_row, dest_col, dest_row
                        else:
                            tcp_server.send("\033[0;31mInvalid move, please try again:\033[0m")
                except (IndexError, KeyError, ValueError):
                    tcp_server.send("\033[0;31mInvalid move, please try again:\033[0m")

    def make_move(self, player, src_col, src_row, dest_col, dest_row):
        self.board[dest_row][dest_col] = self.board[src_row][src_col]
        self.board[src_row][src_col] = ' '
        if player == 'a' and dest_row == self.BOARD_SIZE - 1:
            self.board[dest_row][dest_col] = 'A'
        elif player == 'b' and dest_row == 0:
            self.board[dest_row][dest_col] = 'B'
        if abs(src_row - dest_row) == 2:
            mid_row = (src_row + dest_row) // 2
            mid_col = (src_col + dest_col) // 2
            self.board[mid_row][mid_col] = ' '

    def is_winner(self, player):
        for row in range(self.BOARD_SIZE):
            for col in range(self.BOARD_SIZE):
                if self.board[row][col] in 'aA' and player == 'a':
                    return False
                if self.board[row][col] in 'bB' and player == 'b':
                    return False
        return True
    
    def play_game(self, tcp_server):
        time.sleep(1)
        print("\033[0;35m" + f"Player-{self.order[self.turn]}" + "\033[0m" + " goes first.")
        tcp_server.send("\033[0;35m" + f"Player-{self.order[self.turn]}" + "\033[0m" + " goes first.")

        constraint_src_col = None
        constraint_src_row = None

        current_player = self.order[self.turn % 2]
        opponent_player = self.order[(self.turn + 1) % 2]
        self.print_board(self.board, current_player, tcp_server)
        self.print_board(self.board, opponent_player, tcp_server)
        while True:
            current_player = self.order[self.turn % 2]
            opponent_player = self.order[(self.turn + 1) % 2]
            print("\n" + "\033[0;35m" + f"Player-{current_player}'s" + "\033[0m" + " turn.")
            tcp_server.send("\033[0;35m" + f"Player-{current_player}'s" + "\033[0m" + " turn.")

            src_col, src_row, dest_col, dest_row = self.get_move(
                current_player, tcp_server, constraint_src_col, constraint_src_row
            )
            if src_col != None and src_row != None and dest_col != None and dest_row != None:
                self.make_move(current_player, src_col, src_row, dest_col, dest_row)
            self.print_board(self.board, current_player, tcp_server)
            self.print_board(self.board, opponent_player, tcp_server)

            if self.is_winner(current_player):
                print("\033[0;35m" + f"Player-{current_player}" + "\033[0m" + " wins!")
                tcp_server.send("\033[0;35m" + f"Player-{current_player}" + "\033[0m" + " wins!")
                tcp_server.send("GAME_END")
                break

            if self.is_winner(self.order[(self.turn + 1) % 2]):
                opponent_player = self.order[(self.turn + 1) % 2]
                print("\033[0;35m" + f"Player-{opponent_player}" + "\033[0m" + " wins!")
                tcp_server.send("\033[0;35m" + f"Player-{opponent_player}" + "\033[0m" + " wins!")
                tcp_server.send("GAME_END")
                break

            # If the player can capture again, don't change the turn
            if (
                abs(src_row - dest_row) == 2 and
                abs(src_col - dest_col) == 2 and
                self.can_capture_from(current_player, dest_col, dest_row)
            ):
                constraint_src_col = dest_col
                constraint_src_row = dest_row
                continue

            constraint_src_col = None
            constraint_src_row = None
            self.turn += 1

    def main(self, tcp_server):
        self.init_board()
        self.play_game(tcp_server)

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
        if msg == '':
            msg = '\n'
        elif msg[-1] != '\n':
            msg += '\n'
        self.sock.send(msg.encode(encoding="utf-16", errors="surrogatepass"))

    def receive(self):
        try:
            if '\n' not in self.buffer:
                self.buffer += self.sock.recv(4096).decode(encoding="utf-16")

            if '\n' in self.buffer:
                msg, self.buffer = self.buffer.split('\n', 1)
                msg.strip('\ufeff')
            else:
                msg = ''

            return msg
        except Exception as e:
            print(f"Error in TCP_client.receive: {e}")
            traceback.print_exc()

class TCP_server:
    def __init__(self, my_ip, my_port):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.bind((my_ip, my_port))
        self.sock.listen(1)

        # Get the ip and port of the server
        self.ip = Network_tools().get_local_ip()
        self.port = self.sock.getsockname()[1]

        self.buffer = ''

    def __del__(self):
        if 'conn' in self.__dict__:
            self.conn.close()
        self.sock.close()

    def waiting_client(self):
        print("Waiting for \033[0;35mplayer-b\033[0m to connect...")
        self.conn, self.addr = self.sock.accept()
        print("Connected to " + "\033[0;35m" + "player-b" + "\033[0m" + ".")

    def send(self, msg):
        msg += '\n'
        self.conn.sendall(msg.encode(encoding="utf-16", errors="surrogatepass"))

    def recv(self):
        try:
            if '\n' not in self.buffer:
                self.buffer += self.conn.recv(4096).decode(encoding="utf-16")

            if '\n' in self.buffer:
                msg, self.buffer = self.buffer.split('\n', 1)
                msg.strip('\ufeff')
            else:
                msg = ''
            return msg.strip()
        except Exception as e:
            print(f"Error in TCP_server.recv: {e}")

def connect_io_server(ip, port):
    tcp_client = TCP_client('0.0.0.0', 0, ip, port)
    game_client = None
    game_server = None
    game_obj = None
    end = False

    def lobby_receive_thread():
        try:
            nonlocal game_client, game_server, end, game_obj
            while not end:
                msg = tcp_client.receive()
                msg = msg.lstrip('\ufeff')
                if msg == '':
                    time.sleep(1)
                    continue
                    
                if msg == 'END':
                    end = True
                    print('Closing lobby connection...')
                    print('Press ENTER to exit.')
                    break

                # Check for game start triggers
                splitted_msg = msg.split(' ')

                if splitted_msg[0] == "START":
                    game = splitted_msg[1]
                    if splitted_msg[2] == "CLIENT":
                        print(f"Starting game {game} as client...")
                        # Wait for game server ip and port
                        msg_ip_port = ""
                        while not msg_ip_port.startswith("IP"):
                            msg_ip_port = tcp_client.receive()
                        game_ip = msg_ip_port.split(' ')[1]
                        game_port = int(msg_ip_port.split(' ')[3])
                        game_client = TCP_client('0.0.0.0', 0, game_ip, game_port)
                        print(f"Connected to game server at {game_ip}:{game_port}")
                        game_thread = threading.Thread(target=game_receive_thread, args=(game_client,))
                        game_thread.start()
                        print(f"Game {game} started as client.")
                    elif splitted_msg[2] == "SERVER":
                        print(f"Starting game {game} as server...")
                        game_server = TCP_server('0.0.0.0', 0)
                        time.sleep(1)
                        # Send ip and port to lobby
                        tcp_client.send(f"IP {game_server.ip} PORT {game_server.port}")
                        print(f"Sent IP {game_server.ip} PORT {game_server.port} to lobby")
                        game_server.waiting_client()
                        if game == "Battleship":
                            game_obj = BattleShip()
                        elif game == "Checkers":
                            game_obj = Checkers()
                        else:
                            raise Exception("In lobby_receive_thread: Invalid game type")
                        game_thread = threading.Thread(target=game_receive_thread, args=(game_server, game_obj, ))
                        game_thread.start()
                        print(f"Game {game} started as server.")
                    else:
                        raise Exception(f"In lobby_receive_thread: Invalid game type {splitted_msg[2]}")
                elif splitted_msg[0] == "PING":
                    pass
                else:
                    if game_server == None and game_client == None:
                        print(msg)
        except KeyboardInterrupt:
            end = True
            print('Closing lobby connection...')
        except Exception as e:
            print(f"Error in lobby_receive_thread: {e}")
            traceback.print_exc()

    def game_receive_thread(game_agent, game_obj = None):
        try:
            nonlocal game_client, game_server, end
            if type(game_agent) == TCP_client:
                while True:
                    msg = game_agent.receive()
                    if msg == '':
                        time.sleep(1)
                        continue

                    if 'GAME_END' in msg:
                        print("Game session ended. Returning to lobby.")
                        game_client = None
                        game_server = None
                        tcp_client.send("GAME_END")
                        break
                    
                    print(msg)
            elif type(game_agent) == TCP_server:
                game_obj.main(game_agent)
                game_client = None
                game_server = None
                print("Game session ended. Returning to lobby.")
                tcp_client.send("GAME_END")
            else:
                raise Exception("In game_receive_thread: Invalid game agent type")
        except KeyboardInterrupt:
            end = True
            print('Closing game connection...')
        except Exception as e:
            print(f"Error in game_receive_thread: {e}")
            traceback.print_exc()

    thread = threading.Thread(target=lobby_receive_thread)
    thread.start()

    try:
        while True:
            option = input()

            if end:
                break

            if game_client != None:
                game_client.send(option)
            elif game_server != None:
                game_obj.local_input(option)
            else:
                tcp_client.send(option)
    except KeyboardInterrupt:
        end = True
        print('Closing lobby connection...')
        del tcp_client

if __name__ == "__main__":
    connect_io_server(LOBBY_IP, LOBBY_PORT)