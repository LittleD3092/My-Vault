import socket
import threading
import textwrap
import json
import time

ANONYMOUS = 0
IDLE = 1
IN_ROOM = 2
IN_GAME = 3

class PlayerDB:
    def __init__(self) -> None:
        self.filename = "players.json"

        try:
            with open(self.filename, "r") as f:
                self.players = json.load(f)
        except FileNotFoundError:
            with open(self.filename, "w") as f:
                self.players = {}
                json.dump(self.players, f)
            self.players = {}

    def __del__(self):
        self.save()
    
    def save(self):
        with open(self.filename, "w") as f:
            json.dump(self.players, f)

    def register(self, username, password):
        if username in self.players:
            return False
        self.players[username] = password
        self.save()
        return True
    
    def login(self, username, password):
        if username not in self.players:
            return False
        return self.players.get(username) == password
    
class LobbyServer:
    def __init__(self, my_ip, my_port) -> None:
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        while True:
            try:
                self.sock.bind((my_ip, my_port))
                print("Bound to", my_ip, my_port)
                break
            except:
                print("Port already in use. Retrying...")
                time.sleep(1)
        self.sock.listen(10)

        self.ac_thread = threading.Thread(target=self.accept_thread)
        self.ac_thread.start()

        # player statuses are listed on the top of this file,
        # and the key is the username
        self.player_status = {}
        self.player_db = PlayerDB()
        # rooms are stored in a set,
        # each element is a set of players in the room
        self.rooms = set()

        # set of connections
        self.conns = set()

    def __del__(self):
        if self.__dict__.get("conns") is not None:
            for conn in self.conns:
                conn.close()
        self.sock.close()

    def accept_thread(self):
        while True:
            conn, addr = self.sock.accept()
            self.conns.add(conn)

            anonymous_name = f"{addr[0]}:{addr[1]}"
            self.player_status[f"{addr[0]}:{addr[1]}"] = ANONYMOUS

            print(f"Connection from \033[0;35m{addr}\033[0m")

            th = threading.Thread(
                target=self.handle_client, args=(conn, addr)
            )
            th.start()

    def handle_client(self, conn, addr):
        class InputHandler:
            def __init__(self, conn) -> None:
                self.conn = conn
                self.buffer = ""

            def get_line(self):
                if '\n' not in self.buffer:
                    self.buffer += self.conn.recv(4096).decode(encoding="utf-16")
                if len(self.buffer.split('\n')) == 1:
                    line = self.buffer
                    self.buffer = ''
                else:
                    line, self.buffer = self.buffer.split('\n', 1)
                line = line.strip()
                return line
            
            def send(self, msg):
                if not msg.endswith('\n'):
                    msg += '\n'
                if isinstance(msg, str):
                    msg = msg.encode(encoding="utf-16")
                    self.conn.send(msg)

        def get_player_list():
            player_list = "\033[1;36mPlayer List\033[0m\n"
            for player, status in self.player_status.items():
                if status == ANONYMOUS:
                    continue
                elif status == IDLE:
                    player_list += f"    \033[0;36m\uf444\033[0m{player} [idle]\n"
                elif status == IN_ROOM:
                    player_list += f"    \033[0;32m\uf444\033[0m{player} [in room]\n"
                elif status == IN_GAME:
                    player_list += f"    \033[0;30m\uf444\033{player} [in game]\n"
            return player_list
        
        def get_room_list():
            room_list = "\033[1;36mRoom List\033[0m\n"
            i = 1
            for room in self.rooms:
                room_list += f"    Room {i}\n"
                for player in room:
                    room_list += f"        {player}\n"
            return room_list

        ihandler = InputHandler(conn)

        # Info
        WELCOME_MSG = textwrap.dedent("""\
            \033[1;36mWelcome to the lobby server!\033[0m
            (1) Register
            (2) Login
            (3) Show players
            (4) Exit
            Enter your choice: INPUT NO_ENDL""")
        PROMPT_USERNAME = "Enter your username: INPUT NO_ENDL"
        PROMPT_PASSWORD = "Enter your password: INPUT NO_ENDL"
        CREATE_ACCOUNT_SUCCESS = "\033[0;32mAccount created successfully.\033[0m"
        LOGIN_SUCCESS = "\033[0;32mLogin successful.\033[0m"
        # Error
        INVALID_INPUT = "\033[0;31mInvalid input. Please try again.\033[0m"
        USER_EXISTS = "\033[0;31mUsername already exists. Please try again.\033[0m"
        LOGIN_FAILED = "\033[0;31mYour username or password is incorrect. Please try again.\033[0m"

        username = f"{addr[0]}:{addr[1]}"

        try:
            # Welcome step
            while True:
                ihandler.send(WELCOME_MSG)
                choice = ihandler.get_line()
                if choice == "1":
                    ihandler.send(PROMPT_USERNAME)
                    username = ihandler.get_line()
                    ihandler.send(PROMPT_PASSWORD)
                    password = ihandler.get_line()
                    if not self.player_db.register(username, password):
                        ihandler.send(USER_EXISTS)
                        continue
                    ihandler.send(CREATE_ACCOUNT_SUCCESS)
                elif choice == "2":
                    ihandler.send(PROMPT_USERNAME)
                    username = ihandler.get_line()
                    ihandler.send(PROMPT_PASSWORD)
                    password = ihandler.get_line()
                    if not self.player_db.login(username, password):
                        ihandler.send(LOGIN_FAILED)
                        continue
                    else:
                        ihandler.send(LOGIN_SUCCESS)
                        ihandler.send(f"Welcome, {username}!")
                        self.player_status.pop(f"{addr[0]}:{addr[1]}")
                        self.player_status[username] = IDLE
                        ihandler.send(get_player_list())
                        ihandler.send(get_room_list())
                        break
                elif choice == "3":
                    ihandler.send(get_player_list())
                    continue
                elif choice == "4":
                    ihandler.send("END")
                    conn.close()
                    self.conns.remove(conn)
                    return
                else:
                    ihandler.send(INVALID_INPUT)
                    continue

            # Select room or create room
        except:
            conn.close()
            self.conns.remove(conn)
            return


if __name__ == "__main__":
    lobby = LobbyServer("0.0.0.0", 11066)