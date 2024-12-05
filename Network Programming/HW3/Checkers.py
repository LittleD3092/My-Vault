import random
import time

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