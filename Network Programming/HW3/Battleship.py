import random
import time

class Battleship:
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