import socket
import threading
import textwrap
import json
import time
import traceback

LOBBY_PORT = 11066

ANONYMOUS = 0
IDLE = 1
WAITING = 2
IN_GAME = 3

CLEAN_DATA_RUN = True

class PlayerDB:
    def __init__(self) -> None:
        self.filename = "players.json"

        if CLEAN_DATA_RUN:
            self.players = {}
        else:
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
        if CLEAN_DATA_RUN == False:
            with open(self.filename, "w") as f:
                json.dump(self.players, f, indent=4)

    def register(self, username, password):
        if username in self.players:
            return False
        self.players[username] = password
        self.save()
        return True
    
    def login(self, username, password):
        if username not in self.players:
            return False
        elif username == '':
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

        # pending invitations
        # key: username of the invited player
        # value: a list of usernames of the inviting players
        self.invitations = {}

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

            def get_line(self):
                if '\n' not in self.buffer:
                    self.buffer += self.conn.recv(4096).decode(encoding="utf-16")
                if len(self.buffer.split('\n')) > 1:
                    line, self.buffer = self.buffer.split('\n', 1)
                else:
                    line = ""
                    time.sleep(1)
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
                    player_list += f"    \033[0;30m\uf444 \033[0m{player} [in game]\n"
            return player_list
        
        def get_room_list():
            room_list_str = "\033[1;36mRoom List\033[0m\n"
            try:
                for room, players in self.rooms.items():
                    if self.rooms_type[room] == "Public":
                        if len(players) == 1:
                            room_list_str += f"    Room \033[0;35m{room}\033[0m is willing to play \033[0;35m{self.rooms_game[room]}\033[0m\n"
                        else:
                            room_list_str += f"    Room \033[0;35m{room}\033[0m is now playing \033[0;35m{self.rooms_game[room]}\033[0m\n"
                        for player in players:
                            room_list_str += f"        {player}\n"
            except Exception as e:
                print(f"Error occurred while getting room list: {e} (type: {type(e).__name__})")
                print("self.rooms:", self.rooms)
                print("self.rooms_game:", self.rooms_game)
                traceback.print_exc()
            return room_list_str
        
        def broadcast_room_list(exclude_player=None):
            room_list_str = get_room_list()
            for player, conn in self.conns.items():
                if player == exclude_player:
                    continue
                ihandler = InputHandler(conn)
                ihandler.send(room_list_str)

        def broadcast_player_list(exclude_player=None):
            player_list_str = get_player_list()
            for player, conn in self.conns.items():
                if player == exclude_player:
                    continue
                ihandler = InputHandler(conn)
                ihandler.send(player_list_str)
        
        def get_invitation_message(inviters):
            invitation_message = f"There are invitations from the following players:\n"
            index = 'a'
            for inviter in inviters:
                invitation_message += f"    ({index}) {inviter}\n"
                index = chr(ord(index) + 1)

                # 'r' is reserved for rejecting all invitations
                if index == 'r':
                    index = chr(ord(index) + 1)
            invitation_message += "    (r) Reject all invitations\n"
            invitation_message += "Do you want to accept the invitation? (Enter the letter)"
            return invitation_message
        
        # return True if the player accepted the invitation
        # return False if the player rejected the invitation
        def process_invitation(option, username, ihandler):
            try:
                index = ord(option) - ord('a')
                if option == 'r':
                    self.invitations.pop(username)
                    ihandler.send("All invitations are rejected.")
                    return False
                elif index >= len(self.invitations[username]):
                    ihandler.send(INVALID_INPUT)
                    return False
                inviter = self.invitations[username][index]
                self.invitations.pop(username)
                # Get the room number
                room = None
                for r, players in self.rooms.items():
                    if inviter in players:
                        room = r
                        break
                if room is None:
                    raise Exception(f"Room not found for the inviter {inviter}")
                self.rooms[room].add(username)
                self.player_status[username] = WAITING
                broadcast_player_list(username)
                return True
            except Exception as e:
                print(f"Error occurred while processing invitation: {e} (type: {type(e).__name__})")
                print(f"self.invitations: {self.invitations}")
                traceback.print_exc()
                return False

        def get_room_from_player(player):
            for room, players in self.rooms.items():
                if player in players:
                    return room
            return None

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
        USER_NOT_FOUND = "\033[0;31mUsername not found. Please try again.\033[0m"
        USER_ALREADY_LOGGED_IN = "\033[0;31mUser is already logged in. Please try again.\033[0m"
        LOGIN_FAILED = "\033[0;31mYour username or password is incorrect. Please try again.\033[0m"

        username = f"{addr[0]}:{addr[1]}"

        try:
            while True:
                print(f"username: {username}, enter the lobby")
                while True:
                    if self.player_status[username] == ANONYMOUS:
                        print(f"username: {username}, enter login/register step")
                        # Welcome step
                        ihandler.send(WELCOME_MSG)
                        choice = ihandler.get_line()
                        if choice == "1":
                            while True:
                                ihandler.send(PROMPT_USERNAME)
                                tmp_username = ihandler.get_line()
                                ihandler.send(PROMPT_PASSWORD)
                                password = ihandler.get_line()
                                if tmp_username == '' or password == '':
                                    ihandler.send(INVALID_INPUT)
                                    continue
                                elif not self.player_db.register(tmp_username, password) or tmp_username in self.player_status:
                                    ihandler.send(USER_EXISTS)
                                    continue
                                else:
                                    ihandler.send(CREATE_ACCOUNT_SUCCESS)
                                    break
                        elif choice == "2":
                            while True:
                                ihandler.send(PROMPT_USERNAME)
                                tmp_username = ihandler.get_line()
                                if tmp_username not in self.player_db.players:
                                    ihandler.send(USER_NOT_FOUND)
                                    continue
                                if tmp_username in self.player_status:
                                    ihandler.send(USER_ALREADY_LOGGED_IN)
                                    continue
                                ihandler.send(PROMPT_PASSWORD)
                                password = ihandler.get_line()
                                if not self.player_db.login(tmp_username, password):
                                    ihandler.send(LOGIN_FAILED)
                                    continue
                                else:
                                    ihandler.send(LOGIN_SUCCESS)
                                    username = tmp_username
                                    ihandler.send(f"Welcome, {username}!")
                                    self.player_status.pop(f"{addr[0]}:{addr[1]}")
                                    self.player_status[username] = IDLE
                                    tmp_conn = self.conns.pop(f"{addr[0]}:{addr[1]}")
                                    self.conns[username] = tmp_conn
                                    broadcast_player_list(username)
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
                            self.player_status.pop(f"{addr[0]}:{addr[1]}")
                            print(f"Connection from \033[0;35m{addr}\033[0m closed.")
                            return
                        else:
                            ihandler.send(INVALID_INPUT)
                            continue
                    else:
                        break
                
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
                print(f"username: \033[0;35m{username}\033[0m, enter select/create room step")
                while True:
                    ihandler.send(SELECT_OR_CREATE_ROOM)
                    choice = ihandler.get_line()
                    if choice == "1":
                        while True:
                            ihandler.send(SELECT_ROOM_PROMPT)
                            room = ihandler.get_line()

                            # handle invitation
                            if room >= 'a' and room <= 'z':
                                accept_invitation = process_invitation(room, username, ihandler)
                                if accept_invitation:
                                    break
                                else:
                                    continue

                            if room == "":
                                ihandler.send(INVALID_INPUT)
                                continue

                            room = int(room)
                            if room not in self.rooms.keys():
                                ihandler.send("Room does not exist. Please try again.")
                                print("self.rooms:", self.rooms)
                                continue
                            elif self.rooms_type[room] == "Private":
                                ihandler.send("Room is private. Please try again.")
                                continue
                            elif len(self.rooms[room]) == 2:
                                ihandler.send("Room is full. Please try again.")
                                continue
                            else:
                                self.rooms[room].add(username)
                                self.player_status[username] = WAITING
                                broadcast_player_list(username)
                                # opponents = [player for player in self.rooms[room] if player != username]
                                # for opponent in opponents:
                                #     ihandler_opponent = InputHandler(self.conns[opponent])
                                #     ihandler_opponent.send(f"\033[0;35m{username}\033[0m joined the room. \033[1;36mPRESS ENTER TO START THE GAME\033[0m")
                                
                                break
                    elif choice == "2":
                        while True:
                            ihandler.send(GAME_TYPE_PROMPT)
                            game_type = ihandler.get_line()
                            if game_type == "1":
                                game_type = "Battleship"
                                break
                            elif game_type == "2":
                                game_type = "Checkers"
                                break
                            # accept invitation
                            elif game_type >= 'a' and game_type <= 'z':
                                accept_invitation = process_invitation(game_type, username, ihandler)
                                if accept_invitation:
                                    break
                                else:
                                    continue
                            else:
                                ihandler.send(INVALID_INPUT)
                                continue
                        if self.player_status[username] == WAITING:
                            break
                        while True:
                            ihandler.send(ROOM_TYPE_PROMPT)
                            room_type = ihandler.get_line()

                            if room_type == "1":
                                room = max(self.rooms.keys(), default=0) + 1
                                self.rooms[room] = {username}
                                self.player_status[username] = WAITING
                                broadcast_player_list(username)
                                self.rooms_type[room] = "Public"
                                self.rooms_game[room] = game_type
                                broadcast_room_list()
                                break
                            elif room_type == "2":
                                room = max(self.rooms.keys(), default=0) + 1
                                self.rooms[room] = {username}
                                self.player_status[username] = WAITING
                                broadcast_player_list(username)
                                self.rooms_type[room] = "Private"
                                self.rooms_game[room] = game_type
                                break
                            elif room_type >= 'a' and room_type <= 'z':
                                accept_invitation = process_invitation(room_type, username, ihandler)
                                if accept_invitation:
                                    break
                                else:
                                    continue
                            else:
                                ihandler.send(INVALID_INPUT)
                                continue
                    elif choice >= 'a' and choice <= 'z': # Accept invitation
                        accept_invitation = process_invitation(choice, username, ihandler)
                        if accept_invitation:
                            break
                        else:
                            continue
                    else:
                        ihandler.send(INVALID_INPUT)
                        continue
                    break

                # Waiting for other players
                choice = None
                print(f"username: \033[0;35m{username}\033[0m, enter waiting for other players step")
                room = get_room_from_player(username)
                if len(self.rooms[room]) == 1:
                    ihandler.send(ROOM_WAITING_PROMPT)
                while len(self.rooms[room]) < 2:
                    choice = ihandler.get_line_non_blocking()
                    if choice == "1":
                        ihandler.send(INVITATION_PROMPT)
                        invited_player = ihandler.get_line()
                        if invited_player not in self.player_status:
                            ihandler.send("Player does not exist. Please try again.")
                            ihandler.send(ROOM_WAITING_PROMPT)
                            continue
                        if self.player_status[invited_player] != IDLE:
                            ihandler.send("\033[0;31mPlayer is not available. Please try again.\033[0m")
                            ihandler.send(ROOM_WAITING_PROMPT)
                            continue

                        # Send invitation to the invited player
                        ihandler_invited = InputHandler(self.conns[invited_player])
                        if invited_player not in self.invitations:
                            self.invitations[invited_player] = [username]
                        ihandler_invited.send(get_invitation_message(self.invitations[invited_player]))
                        ihandler.send(f"Invitation sent to {invited_player}.")
                        while True:
                            # Check if the invited player joined the room
                            if self.rooms[room] == {username, invited_player}:
                                ihandler.send(f"{invited_player} joined the room.")
                                break
                            # Check if the invited player rejected the invitation
                            if invited_player not in self.invitations:
                                ihandler.send(f"{invited_player} rejected the invitation.")
                                ihandler.send(ROOM_WAITING_PROMPT)
                                break
                            if invited_player in self.invitations and username not in self.invitations[invited_player]:
                                ihandler.send(f"{invited_player} rejected the invitation.")
                                ihandler.send(ROOM_WAITING_PROMPT)
                                break
                            time.sleep(1)

                    elif choice is None:
                        time.sleep(1)
                        ihandler.send("PING")
                        continue
                    elif choice == '':
                        pass
                    else:
                        ihandler.send(INVALID_INPUT)
                        continue

                # Game start
                print(f"username: \033[0;35m{username}\033[0m, enter game start step")
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
                # change the status to IN_GAME
                self.player_status[username] = IN_GAME
                broadcast_player_list(username)

                # Wait for the game to end
                print(f"username: \033[0;35m{username}\033[0m is in game")
                while True:
                    msg = ihandler.get_line()
                    if msg == "GAME_END":
                        self.player_status[username] = IDLE
                        broadcast_player_list(username)
                        if room in self.rooms.keys():
                            self.rooms.pop(room)
                            self.rooms_game.pop(room)
                            self.rooms_type.pop(room)
                        ihandler.send("Thank you for playing!")
                        time.sleep(1)
                        ihandler.send(get_player_list())
                        broadcast_room_list(username)
                        break
        
        except BrokenPipeError:
            print(f"Connection from \033[0;35m{addr}\033[0m closed.")
            # traceback.print_exc()
            conn.close()
            if username in self.conns.keys():
                self.conns.pop(username)
            if f"{addr[0]}:{addr[1]}" in self.conns.keys():
                self.player_status.pop(f"{addr[0]}:{addr[1]}")
            if username in self.player_status:
                self.player_status.pop(username)
                print(f"\033[0;35m{username}\033[0m is removed from the player_status.")
            if username in self.invitations:
                self.invitations.pop(username)
            for inviter, invited_players in self.invitations.items():
                if username in invited_players:
                    invited_players.remove(username)
                if len(invited_players) == 0:
                    self.invitations.pop(inviter)

            rooms_to_remove = []
            for room, players in self.rooms.items():
                if username in players:
                    players.remove(username)
                    if len(players) == 0:
                        rooms_to_remove.append(room)
            for room in rooms_to_remove:
                self.rooms.pop(room)
                self.rooms_game.pop(room)
                self.rooms_type.pop(room)
            
            return

        except Exception as e:
            print(f"Error occurred in handle_client: {e} (type: {type(e).__name__})")
            traceback.print_exc()
            conn.close()
            if username in self.conns.keys():
                self.conns.pop(username)
            if f"{addr[0]}:{addr[1]}" in self.conns.keys():
                self.player_status.pop(f"{addr[0]}:{addr[1]}")
            if username in self.player_status:
                self.player_status.pop(username)
                broadcast_player_list(username)
            if username in self.invitations:
                self.invitations.pop(username)
            for inviter, invited_players in self.invitations.items():
                if username in invited_players:
                    invited_players.remove(username)
                if len(invited_players) == 0:
                    self.invitations.pop(inviter)
            for room, players in self.rooms.items():
                if username in players:
                    players.remove(username)
                    if len(players) == 0:
                        self.rooms.pop(room)
                        self.rooms_game.pop(room)
                        self.rooms_type.pop(room)
            return


if __name__ == "__main__":
    lobby = LobbyServer("0.0.0.0", LOBBY_PORT)