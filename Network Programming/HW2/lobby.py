import socket
import threading
import textwrap
import json
import time

ANONYMOUS = 0
IDLE = 1
WAITING = 2
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
        self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
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
        # rooms are stored in a dictionary,
        # and the key is the room number.
        # each value is a set of players in the room.
        self.rooms = {}
        # rooms_game is a dictionary that stores
        # the name of the game that is being played 
        # in the room.
        self.rooms_game = {}
        # rooms_type is a dictionary that stores
        # the type of the room.
        self.rooms_type = {}

        # set of connections
        self.conns = {}

    def __del__(self):
        if self.__dict__.get("conns") is not None:
            for conn in self.conns.values():
                conn.close()
        self.sock.close()

    def accept_thread(self):
        while True:
            conn, addr = self.sock.accept()
            anonymous_name = f"{addr[0]}:{addr[1]}"
            self.conns[anonymous_name] = conn

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

            def get_line(self, timeout=0):
                if '\n' not in self.buffer:
                    self.buffer += self.conn.recv(4096).decode(encoding="utf-16")
                if len(self.buffer.split('\n')) == 1:
                    line = self.buffer
                    self.buffer = ''
                else:
                    line, self.buffer = self.buffer.split('\n', 1)
                line = line.strip()
                return line
            
            def get_line_non_blocking(self):
                self.conn.setblocking(False)
                try:
                    if '\n' not in self.buffer:
                        self.buffer += self.conn.recv(4096).decode(encoding="utf-16")
                    if '\n' not in self.buffer:
                        return None
                    if len(self.buffer.split('\n')) == 1:
                        return None
                    line, self.buffer = self.buffer.split('\n', 1)
                    line = line.strip()
                    return line
                except BlockingIOError:
                    return None
                except Exception as e:
                    print(f"Error occurred in get_line_non_blocking: {e} (type: {type(e).__name__})")
                    return None
                finally:
                    self.conn.setblocking(True)
            
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
                    player_list += f"    \033[0;36m\uf444 \033[0m{player} [idle]\n"
                elif status == WAITING:
                    player_list += f"    \033[0;32m\uf444 \033[0m{player} [in room]\n"
                elif status == IN_GAME:
                    player_list += f"    \033[0;30m\uf444 \033{player} [in game]\n"
            return player_list
        
        def get_room_list():
            room_list_str = "\033[1;36mRoom List\033[0m\n"
            try:
                for room, players in self.rooms.items():
                    room_list_str += f"    Room {room} is willing to play {self.rooms_game[room]}\n"
                    for player in players:
                        room_list_str += f"        {player}\n"
            except Exception as e:
                print(f"Error occurred while getting room list: {e} (type: {type(e).__name__})")
                print("self.rooms:", self.rooms)
                print("self.rooms_game:", self.rooms_game)
            return room_list_str
        
        def broadcast_room_list():
            room_list_str = get_room_list()
            for conn in self.conns.values():
                ihandler = InputHandler(conn)
                ihandler.send(room_list_str)

        ihandler = InputHandler(conn)

        # Welcome step
        WELCOME_MSG = textwrap.dedent("""\
            \033[1;36mWelcome to the lobby server!\033[0m
            (1) Register
            (2) Login
            (3) Show players
            (4) Exit
            Enter your choice:""")
        PROMPT_USERNAME = "Enter your username:"
        PROMPT_PASSWORD = "Enter your password:"
        CREATE_ACCOUNT_SUCCESS = "\033[0;32mAccount created successfully.\033[0m"
        LOGIN_SUCCESS = "\033[0;32mLogin successful.\033[0m"
        # Error
        INVALID_INPUT = "\033[0;31mInvalid input. Please try again.\033[0m"
        USER_EXISTS = "\033[0;31mUsername already exists. Please try again.\033[0m"
        LOGIN_FAILED = "\033[0;31mYour username or password is incorrect. Please try again.\033[0m"

        username = f"{addr[0]}:{addr[1]}"

        try:
            while True:
                if self.player_status[username] == ANONYMOUS:
                    # Welcome step
                    ihandler.send(WELCOME_MSG)
                    choice = ihandler.get_line()
                    if choice == "1":
                        ihandler.send(PROMPT_USERNAME)
                        username = ihandler.get_line()
                        ihandler.send(PROMPT_PASSWORD)
                        password = ihandler.get_line()
                        if not self.player_db.register(username, password) or username in self.player_status:
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
                            tmp_conn = self.conns.pop(f"{addr[0]}:{addr[1]}")
                            self.conns[username] = tmp_conn
                            ihandler.send(get_player_list())
                            ihandler.send(get_room_list())
                            break
                    elif choice == "3":
                        ihandler.send(get_player_list())
                        continue
                    elif choice == "4":
                        ihandler.send("END")
                        conn.close()
                        self.conns.pop(f"{addr[0]}:{addr[1]}")
                        return
                    else:
                        ihandler.send(INVALID_INPUT)
                        continue
            
            SELECT_OR_CREATE_ROOM = textwrap.dedent("""\
                \033[1;36mDo you want to join a room or create a room?\033[0m
                (1) Join a room
                (2) Create a room
                Enter your choice:""")
            SELECT_ROOM_PROMPT = "Enter the room number:"
            GAME_TYPE_PROMPT = textwrap.dedent("""\
                \033[1;36mSelect the game type:\033[0m
                (1) Battleship
                (2) Checkers
                Enter your choice:""")
            ROOM_TYPE_PROMPT = textwrap.dedent("""\
                \033[1;36mSelect the room type:\033[0m
                (1) Public
                (2) Private
                Enter your choice:""")
            ROOM_WAITING_PROMPT = textwrap.dedent("""\
                \033[1;36mWaiting for other players...\033[0m
                \033[1;36mMeanwhile, you can:\033[0m
                (1) Invite a player
                Enter your choice:""")
            INVITATION_PROMPT = "Enter the username of the player you want to invite:"

            # Select room or create room
            while True:
                ihandler.send(SELECT_OR_CREATE_ROOM)
                choice = ihandler.get_line()
                if choice == "1":
                    while True:
                        ihandler.send(SELECT_ROOM_PROMPT)
                        room = int(ihandler.get_line())
                        if room not in self.rooms.keys():
                            ihandler.send("Room does not exist. Please try again.")
                            print("self.rooms:", self.rooms)
                            continue
                        else:
                            self.rooms[room].add(username)
                            self.player_status[username] = WAITING
                            break
                elif choice == "2":
                    self.player_status[username] = WAITING
                    while True:
                        ihandler.send(GAME_TYPE_PROMPT)
                        game_type = ihandler.get_line()
                        room = max(self.rooms.keys(), default=0) + 1
                        self.rooms[room] = {username}
                        if game_type == "1":
                            self.rooms_game[room] = "Battleship"
                            break
                        elif game_type == "2":
                            self.rooms_game[room] = "Checkers"
                            break
                        else:
                            ihandler.send(INVALID_INPUT)
                            continue
                    while True:
                        ihandler.send(ROOM_TYPE_PROMPT)
                        room_type = ihandler.get_line()
                        if room_type == "1":
                            self.player_status[username] = WAITING
                            self.rooms_type[room] = "Public"
                            break
                        elif room_type == "2":
                            self.player_status[username] = WAITING
                            self.rooms_type[room] = "Private"
                            break
                        else:
                            ihandler.send(INVALID_INPUT)
                            continue
                    broadcast_room_list()
                else:
                    ihandler.send(INVALID_INPUT)
                    continue
                break

            # Waiting for other players
            if len(self.rooms[room]) == 1:
                ihandler.send(ROOM_WAITING_PROMPT)
            while len(self.rooms[room]) < 2:
                choice = ihandler.get_line_non_blocking()
                if choice == "1":
                    ihandler.send(INVITATION_PROMPT)
                    invited_player = ihandler.get_line()
                    if invited_player not in self.player_status:
                        ihandler.send("Player does not exist. Please try again.")
                        continue
                    if self.player_status[invited_player] != IDLE:
                        ihandler.send("Player is not available. Please try again.")
                        continue
                    self.rooms[room].add(invited_player)
                    self.player_status[invited_player] = WAITING
                elif choice is None:
                    time.sleep(1)
                    continue
                else:
                    ihandler.send(INVALID_INPUT)
                    continue

            # Game start
            sorted_players = sorted(self.rooms[room])
            if self.rooms_game[room] == "Battleship":
                if sorted_players[0] == username:
                    ihandler.send("START Battleship SERVER")
                    
                    # read the server's ip and port
                    msg_ip_port = ihandler.get_line()
                    msg_ip_port = msg_ip_port.strip().split(' ')
                    if msg_ip_port[0] == 'IP':
                        server_ip = msg_ip_port[1]
                    else:
                        raise Exception(f"Invalid message received when reading game server's IP: {msg_ip_port}")
                    if msg_ip_port[2] == 'PORT':
                        server_port = int(msg_ip_port[3])
                    else:
                        raise Exception("Invalid message received when reading game server's port")
                    
                    # send server's ip and port to the client
                    client_conn = self.conns[sorted_players[1]]
                    ihandler_client = InputHandler(client_conn)
                    ihandler_client.send(f"IP {server_ip} PORT {server_port}")
                    
                elif sorted_players[1] == username:
                    ihandler.send("START Battleship CLIENT")

            # Wait for the game to end
            while True:
                msg = ihandler.get_line()
                if msg == "GAME_END":
                    self.player_status[username] = IDLE
                    self.rooms.pop(room)
                    self.rooms_game.pop(room)
                    self.rooms_type.pop(room)
                    ihandler.send("Thank you for playing!")
                    ihandler.send(get_player_list())
                    broadcast_room_list()
                    break
            
        except Exception as e:
            print(f"Error occurred in handle_client: {e} (type: {type(e).__name__})")
            conn.close()
            if username in self.conns.keys():
                self.conns.pop(username)
            if f"{addr[0]}:{addr[1]}" in self.conns.keys():
                self.player_status.pop(f"{addr[0]}:{addr[1]}")
            if username in self.player_status:
                self.player_status.pop(username)
            return


if __name__ == "__main__":
    lobby = LobbyServer("0.0.0.0", 11066)