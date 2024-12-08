import socket
import threading
import textwrap
import json
import time
import traceback
import os

LOBBY_PORT = 11066

ANONYMOUS = 0
IDLE = 1
WAITING = 2
IN_GAME = 3

CLEAN_DATA_RUN = False

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

class LobbyGamesFolder:
    def __init__(self, folder_name = "lobby_games") -> None:
        self.folder_name = folder_name
        # self.games: a dictionary that maps the game name to the game filename
        self.games = {}
        # self.game_publisher: a dictionary that maps the game name to the game publisher
        self.game_publisher = {}
        # self.game_description: a dictionary that maps the game name to the game description
        self.game_description = {}
        # self.game_version: a dictionary that maps the game name to the game version
        self.game_version = {}
        
        if not CLEAN_DATA_RUN:
            if not os.path.exists(self.folder_name):
                os.makedirs(self.folder_name)
            try:
                with open(f"{self.folder_name}/info.json", "r") as f:
                    info = json.load(f)
                    self.games = info["games"]
                    self.game_publisher = info["publisher"]
                    self.game_description = info["description"]
                    self.game_version = info["version"]
            except FileNotFoundError:
                with open(f"{self.folder_name}/info.json", "w") as f:
                    info = {
                        "games": {},
                        "publisher": {},
                        "description": {},
                        "version": {}
                    }
                    json.dump(info, f, indent=4)
                self.games = {}
                self.game_publisher = {}
                self.game_description = {}
                self.game_version = {}
    
    def write_info(self):
        info = {
            "games": self.games,
            "publisher": self.game_publisher,
            "description": self.game_description,
            "version": self.game_version
        }
        with open(f"{self.folder_name}/info.json", "w") as f:
            json.dump(info, f, indent=4)
    
    def get_game_list(self):
        game_list_str = "\033[1;36mGame List\033[0m\n"
        if len(self.games) == 0:
            game_list_str += "    No games are available.\n"
        for game, publisher in self.game_publisher.items():
            game_list_str += f"    \033[0;35m{game}\033[0m by {publisher}, version {self.game_version[game]}\n"
            game_list_str += f"        {self.game_description[game]}\n"
        return game_list_str
    
    def get_publisher_game_list(self, publisher):
        game_list_str = f"\033[1;36mGame List by {publisher}\033[0m\n"
        publisher_games = [game for game, pub in self.game_publisher.items() if pub == publisher]
        if len(publisher_games) == 0:
            game_list_str += "    No games are available.\n"
        for game in publisher_games:
            game_list_str += f"    \033[0;35m{game}\033[0m, version {self.game_version[game]}\n"
            game_list_str += f"        {self.game_description[game]}\n"
        return game_list_str
    
    def get_game_filename(self, game_name):
        return self.games.get(game_name)
    
    def get_game_publisher(self, game_name):
        return self.game_publisher.get(game_name)
    
    def get_game_description(self, game_name):
        return self.game_description.get(game_name)
    
    def get_game_version(self, game_name):
        return self.game_version.get(game_name)
    
    def add_game(self, game_name, game_filename, game_publisher, game_description, game_code):
        self.games[game_name] = game_filename
        self.game_publisher[game_name] = game_publisher
        self.game_description[game_name] = game_description
        self.game_version[game_name] = 1
        with open(f"{self.folder_name}/{game_filename}", "w") as f:
            f.write(game_code)
        self.write_info()

    def remove_game(self, game_name):
        if game_name not in self.games:
            return
        game_filename = self.games.pop(game_name)
        self.game_publisher.pop(game_name)
        self.game_description.pop(game_name)
        self.game_version.pop(game_name)
        os.remove(f"{self.folder_name}/{game_filename}")
        self.write_info()

    def update_game(self, game_name, game_filename, game_publisher, game_description, game_code):
        if game_name not in self.games:
            return
        self.games[game_name] = game_filename
        self.game_publisher[game_name] = game_publisher
        self.game_description[game_name] = game_description
        self.game_version[game_name] += 1
        with open(f"{self.folder_name}/{game_filename}", "w") as f:
            f.write(game_code)
        self.write_info()

    def get_raw_game_list(self):
        games = []
        for game in self.games.keys():
            games.append(game)
        return games

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
        # each value is a list of players in the room.
        self.rooms = {}
        # rooms_game is a dictionary that stores
        # the name of the game that is being played 
        # in the room.
        self.rooms_game = {}
        # rooms_type is a dictionary that stores
        # the type of the room. It is either "Public" or "Private".
        self.rooms_type = {}
        # rooms_start is a dictionary that stores
        # whether the game has started in the room.
        # The key is the room number.
        # The value is a boolean value.
        self.rooms_start = {}

        # set of connections
        self.conns = {}

        # pending invitations
        # key: username of the invited player
        # value: a list of usernames of the inviting players
        self.invitations = {}

        # games folder
        self.games_folder = LobbyGamesFolder()

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
                line = self.get_line_no_strip()
                return line.strip()
            
            def get_line_no_strip(self):
                if '\n' not in self.buffer:
                    self.buffer += self.conn.recv(4096).decode(encoding="utf-16")
                if len(self.buffer.split('\n')) > 1:
                    line, self.buffer = self.buffer.split('\n', 1)
                else:
                    line = ""
                    time.sleep(1)
                line = line.strip('\ufeff')
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
                    msg = msg.encode(encoding="utf-16", errors="surrogatepass")
                    self.conn.send(msg)

        def get_player_list():
            player_list = "\033[1;36mPlayer List\033[0m\n"
            if len(self.player_status) == 0:
                player_list += "    Currently, no players are online.\n"
            for player, status in self.player_status.items():
                if status == ANONYMOUS:
                    continue
                elif status == IDLE:
                    player_list += f"    \033[0;36m\uf444 \033[0m{player} [idle]\n"
                elif status == WAITING:
                    player_list += f"    \033[0;32m\uf444 \033[0m{player} [waiting]\n"
                elif status == IN_GAME:
                    player_list += f"    \033[0;30m\uf444 \033[0m{player} [in game]\n"
            return player_list
        
        def get_room_list():
            room_list_str = "\033[1;36mRoom List\033[0m\n"
            try:
                all_private = True
                for room, players in self.rooms.items():
                    if self.rooms_type[room] == "Public":
                        all_private = False
                        break
                if len(self.rooms) == 0 or all_private:
                    room_list_str += "    No public rooms waiting for players.\n"
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

        def broadcast_notification(msg, exclude_player=None):
            msg = f"\033[0;30m[NOTIFY] {msg}\033[0m"
            for player, conn in self.conns.items():
                if player == exclude_player:
                    continue
                ihandler = InputHandler(conn)
                ihandler.send(msg)
        
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
            if option == '':
                return False
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
                # Get the room number
                room = None
                for r, players in self.rooms.items():
                    if inviter in players:
                        room = r
                        break
                if room is None:
                    ihandler.send("The inviter has closed the room.")
                    self.invitations[username].remove(inviter)
                    if len(self.invitations[username]) == 0:
                        self.invitations.pop(username)
                    return False
                elif len(self.rooms[room]) == 2:
                    ihandler.send("The room is full.")
                    self.invitations[username].remove(inviter)
                    if len(self.invitations[username]) == 0:
                        self.invitations.pop(username)
                    return False
                self.rooms[room].append(username)
                self.player_status[username] = WAITING
                
                # Check client for game version
                ihandler.send(f"DOWNLOAD {self.rooms_game[room]} VERSION {self.games_folder.get_game_version(self.rooms_game[room])}")
                request = ihandler.get_line()
                if request.startswith("DOWNLOAD"):
                    download_game(ihandler, self.rooms_game[room])

                broadcast_player_list(username)
                self.invitations.pop(username)
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
        
        def open_invitation_window(username, ihandler):
            if username not in self.invitations:
                ihandler.send("You have no invitations.")
                return
            inviters = self.invitations[username]
            invitation_message = get_invitation_message(inviters)
            ihandler.send(invitation_message)
            accept = process_invitation(ihandler.get_line(), username, ihandler)
            return accept
        
        def exit_room(username, room):
            self.rooms[room].remove(username)
            self.player_status[username] = IDLE
            broadcast_player_list(username)
            if len(self.rooms[room]) == 0:
                self.rooms.pop(room)
                self.rooms_game.pop(room)
                self.rooms_type.pop(room)
            broadcast_room_list()
            if room in self.rooms.keys(): # Check if the room still exists
                for player in self.rooms[room]:
                    ihandler = InputHandler(self.conns[player])
                    ihandler.send(f"\033[0;30m[ROOM] {username} left the room.\033[0m")

        def be_game_host(username):
            choice = None
            room = get_room_from_player(username)
            start_game = False
            has_input = True
            while start_game == False:
                if has_input:
                    ihandler.send(ROOM_WAITING_PROMPT)
                    has_input = False

                choice = ihandler.get_line_non_blocking()
                if choice == "1":
                    ihandler.send(INVITATION_PROMPT)
                    invited_player = ihandler.get_line()
                    if invited_player not in self.player_status:
                        ihandler.send("\033[0;31mPlayer not found.\033[0m")
                        has_input = True
                        continue
                    if self.player_status[invited_player] != IDLE:
                        ihandler.send("Player is not available.")
                        has_input = True
                        continue

                    # send invitation
                    ihandler_invited = InputHandler(self.conns[invited_player])
                    if invited_player not in self.invitations:
                        self.invitations[invited_player] = [username]
                    else:
                        self.invitations[invited_player].append(username)
                    ihandler_invited.send(f"\033[0;30m[INVITATION] {username} invited you to join the room. Press (a) to open intitation window.\033[0m")
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
                    has_input = True
                elif choice == "2": # Leave room
                    exit_room(username, room)
                    break
                elif choice == "3": # List room players
                    room_players = "\033[1;36mRoom Players\033[0m\n"
                    for player in self.rooms[room]:
                        room_players += f"    {player}\n"
                    ihandler.send(room_players)
                    has_input = True
                elif choice == "4": # Start game
                    if len(self.rooms[room]) != 2:
                        ihandler.send("The room is not full.")
                        has_input = True
                        continue
                    start_game = True
                    has_input = True
                elif choice is None:
                    time.sleep(1)
                    ihandler.send("PING")
                elif choice == "":
                    has_input = True
                    ihandler.send(INVALID_INPUT)
                else:
                    ihandler.send(INVALID_INPUT)
                    has_input = True
            return start_game
        
        def upload_game_from_client(ihandler: InputHandler, publisher):
            game_name = ''
            while game_name == '':
                ihandler.send("Please enter the game name: ")
                game_name = ihandler.get_line()
            game_filename = ''
            while game_filename == '':
                ihandler.send("Please enter the game filename: ")
                game_filename = ihandler.get_line()
            game_description = ''
            while game_description == '':
                ihandler.send("Please enter the game description: ")
                game_description = ihandler.get_line()
            game_code = ''
            print(f"Uploading game {game_name}...")
            ihandler.send(f"UPLOAD {game_filename}")
            while True:
                line = ihandler.get_line_no_strip()
                if line.strip() == "END":
                    break
                game_code += line + '\n'

            if game_name in self.games_folder.games:
                self.games_folder.update_game(game_name, game_filename, publisher, game_description, game_code)
            else:
                self.games_folder.add_game(game_name, game_filename, publisher, game_description, game_code)
            ihandler.send(f"GAME {game_name} VERSION {self.games_folder.get_game_version(game_name)} FILENAME {game_filename} UPLOADED")
            ihandler.send("Game uploaded successfully.")

        def open_game_management_window(ihandler):
            leave = False
            while not leave:
                GAME_MANAGEMENT_PROMPT = textwrap.dedent("""\
                    \033[1;36mGame Management\033[0m
                    (1) View game list
                    (2) View your own game list
                    (3) Upload a game
                    (4) Remove a game
                    (5) Exit
                    Enter your choice:""")
                ihandler.send(GAME_MANAGEMENT_PROMPT)
                choice = ihandler.get_line()
                if choice == "1":
                    game_list = self.games_folder.get_game_list()
                    ihandler.send(game_list)
                elif choice == "2":
                    game_list = self.games_folder.get_publisher_game_list(username)
                    ihandler.send(game_list)
                elif choice == "3":
                    upload_game_from_client(ihandler, username)
                elif choice == "4":
                    REMOVE_GAME_PROMPT = "Enter the game name to remove: "
                    ihandler.send(REMOVE_GAME_PROMPT)
                    game_name = ihandler.get_line()
                    if game_name not in self.games_folder.games:
                        ihandler.send("Game not found.")
                        continue
                    self.games_folder.remove_game(game_name)
                    ihandler.send(f"Game {game_name} removed.")
                elif choice == "5":
                    leave = True
                else:
                    ihandler.send(INVALID_INPUT)
        def download_game(ihandler, game_name):
            game_filename = self.games_folder.get_game_filename(game_name)
            if game_filename is None:
                print(f"Game {game_name} not found.")
                return
            with open(f"{self.games_folder.folder_name}/{game_filename}", "r") as f:
                game_code_lines = f.readlines()
                for line in game_code_lines:
                    ihandler.send(line)
            ihandler.send("END")

        def get_game_type_prompt(games_folder):
            prompt = "\033[1;36mSelect the game type:\033[0m\n"
            games = games_folder.get_raw_game_list()
            num_of_games = len(games)

            index = 0
            for game in games:
                prompt += f"({index + 1}) {game}\n"
                index += 1
            prompt += f"({num_of_games + 1}) Logout\n"
            prompt += "(a) Open invitation window\n"
            prompt += "(b) Open game management window\n"
            prompt += "Enter your choice:"
            return prompt

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
        LOGIN_FAILED = "\033[0;31mYour password is incorrect. Please try again.\033[0m"

        username = f"{addr[0]}:{addr[1]}"

        try:
            while True:
                logout = False
                print(f"username: \033[0;35m{username}\033[0m, enter the lobby")
                while True:
                    if self.player_status[username] == ANONYMOUS:
                        print(f"username: \033[0;35m{username}\033[0m, enter login/register step")
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
                                    broadcast_notification(f"{username} logged in.", username)
                                    broadcast_player_list(username)
                                    ihandler.send(get_player_list())
                                    ihandler.send(get_room_list())
                                    ihandler.send(f"LOGIN {username}")
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
                    (3) Logout
                    (a) Open invitation window
                    (b) Open game management window
                    Enter your choice:""")
                SELECT_ROOM_PROMPT = "Enter the room number: (or 'a' to open invitation window)"
                ROOM_TYPE_PROMPT = textwrap.dedent("""\
                    \033[1;36mSelect the room type:\033[0m
                    (1) Public
                    (2) Private
                    (3) Logout
                    (a) Open invitation window
                    (b) Open game management window
                    Enter your choice:""")
                ROOM_WAITING_PROMPT = textwrap.dedent("""\
                    \033[1;36mWaiting for other players...\033[0m
                    \033[1;36mMeanwhile, you can:\033[0m
                    (1) Invite a player
                    (2) Leave room
                    (3) List room players
                    (4) Start game
                    Enter your choice:""")
                INVITATION_PROMPT = "Enter the username of the player you want to invite:"

                # Select room or create room
                print(f"username: \033[0;35m{username}\033[0m, enter select/create room step")
                while True:
                    ihandler.send(SELECT_OR_CREATE_ROOM)
                    choice = ihandler.get_line()
                    join_failed = False
                    if choice == "1": # Join a room
                        while True:
                            ihandler.send(SELECT_ROOM_PROMPT)
                            room = ihandler.get_line()

                            if room == 'a':
                                accept_invitation = open_invitation_window(username, ihandler)
                                if accept_invitation:
                                    break
                                else:
                                    continue

                            if room == "":
                                ihandler.send(INVALID_INPUT)
                                continue

                            room = int(room)
                            if room not in self.rooms.keys():
                                ihandler.send("Room does not exist.")
                                print("self.rooms:", self.rooms)
                                join_failed = True
                                break
                            elif self.rooms_type[room] == "Private":
                                ihandler.send("Room is private.")
                                join_failed = True
                                break
                            elif len(self.rooms[room]) == 2:
                                ihandler.send("Room is full.")
                                ihandler.send(get_room_list())
                                join_failed = True
                                break
                            else:
                                self.rooms[room].append(username)
                                self.player_status[username] = WAITING

                                ihandler.send(f"DOWNLOAD {self.rooms_game[room]} VERSION {self.games_folder.get_game_version(self.rooms_game[room])}")
                                request = ihandler.get_line()
                                if request.startswith("DOWNLOAD"):
                                    download_game(ihandler, self.rooms_game[room])

                                broadcast_player_list(username)
                                broadcast_room_list(username)

                                room_host_username = self.rooms[room][0]
                                room_host_conn = self.conns[room_host_username]
                                room_host_ihandler = InputHandler(room_host_conn)
                                room_host_ihandler.send(f"\033[0;30m{username} joined the room.\033[0m")
                                
                                break
                    elif choice == "2": # Create a room
                        while True:
                            games = self.games_folder.get_raw_game_list()
                            num_of_games = len(games)
                            ihandler.send(get_game_type_prompt(self.games_folder))
                            game_type = ihandler.get_line()
                            if int(game_type) >= 1 and int(game_type) <= num_of_games:
                                game_type = games[int(game_type) - 1]

                                # check client game version
                                ihandler.send(f"DOWNLOAD {game_type} VERSION {self.games_folder.get_game_version(game_type)}")
                                request = ihandler.get_line()
                                if request.startswith("DOWNLOAD"):
                                    download_game(ihandler, game_type)
                                break
                            elif int(game_type) == num_of_games + 1:
                                logout = True
                                break
                            # accept invitation
                            elif game_type == 'a':
                                accept_invitation = open_invitation_window(username, ihandler)
                                if accept_invitation:
                                    break
                                else:
                                    continue
                            elif game_type == 'b':
                                open_game_management_window(ihandler)
                                continue
                            else:
                                ihandler.send(INVALID_INPUT)
                                continue
                        if self.player_status[username] == WAITING:
                            break
                        if logout:
                            break
                        while True:
                            ihandler.send(ROOM_TYPE_PROMPT)
                            room_type = ihandler.get_line()

                            if room_type == "1": # Public room
                                room = max(self.rooms.keys(), default=0) + 1
                                self.rooms[room] = [username]
                                self.player_status[username] = WAITING
                                broadcast_notification(f"{username} created a public room.", username)
                                broadcast_player_list(username)
                                self.rooms_type[room] = "Public"
                                self.rooms_game[room] = game_type
                                self.rooms_start[room] = False
                                broadcast_room_list()
                                break
                            elif room_type == "2": # Private room
                                room = max(self.rooms.keys(), default=0) + 1
                                self.rooms[room] = [username]
                                self.player_status[username] = WAITING
                                broadcast_player_list(username)
                                self.rooms_type[room] = "Private"
                                self.rooms_game[room] = game_type
                                self.rooms_start[room] = False
                                break
                            elif room_type == "3": # Logout
                                logout = True
                                break
                            elif room_type == 'a':
                                accept_invitation = open_invitation_window(username, ihandler)
                                if accept_invitation:
                                    break
                                else:
                                    continue
                            elif room_type == 'b':
                                open_game_management_window(ihandler)
                                continue
                            else:
                                ihandler.send(INVALID_INPUT)
                                continue
                    elif choice == "3": # Logout
                        logout = True
                        break
                    elif choice == 'a':
                        accept_invitation = open_invitation_window(username, ihandler)
                        if accept_invitation:
                            break
                        else:
                            continue
                    elif choice == 'b':
                        open_game_management_window(ihandler)
                        continue
                    else:
                        ihandler.send(INVALID_INPUT)
                        continue
                    
                    if join_failed:
                        continue
                    
                    break


                if logout:
                    # remove the player from the player_status
                    ihandler.send("LOGOUT")
                    self.player_status.pop(username)
                    broadcast_notification(f"{username} logged out.", username)
                    broadcast_player_list(username)
                    if username in self.invitations.keys():
                        self.invitations.pop(username)
                    self.conns.pop(username)
                    username = f"{addr[0]}:{addr[1]}"
                    self.player_status[username] = ANONYMOUS
                    self.conns[username] = conn
                    continue

                # Waiting for other players
                print(f"username: \033[0;35m{username}\033[0m, enter waiting for other players step")

                WAITING_FOR_OTHER_PLAYERS = textwrap.dedent("""\
                    \033[1;36mWaiting for the host to start the game...\033[0m
                    \033[1;36mMeanwhile, you can:\033[0m
                    (1) Leave room
                    (2) Show room players
                    Enter your choice:""")
                room = get_room_from_player(username)
                if self.rooms[room][0] != username:
                    ihandler.send(WAITING_FOR_OTHER_PLAYERS)
                hasInput = False
                while True:
                    if self.rooms[room][0] == username:
                        ihandler.send("\033[0;30m[ROOM] You are now the host.\033[0m")
                        self.rooms_start[room] = be_game_host(username)
                        break
                    if self.rooms_start[room]:
                        break
                    choice = ihandler.get_line_non_blocking()
                    if choice == "1":
                        exit_room(username, room)
                        break
                    elif choice == "2":
                        room_players = "\033[1;36mRoom Players\033[0m\n"
                        for player in self.rooms[room]:
                            room_players += f"    {player}\n"
                        ihandler.send(room_players)
                        hasInput = True
                    elif choice == None:
                        time.sleep(1)
                        ihandler.send("PING")
                    else:
                        ihandler.send(INVALID_INPUT)
                        hasInput = True

                    if hasInput:
                        hasInput = False
                        ihandler.send(WAITING_FOR_OTHER_PLAYERS)

                    time.sleep(1)

                if room not in self.rooms.keys():
                    continue
                if not self.rooms_start[room]:
                    continue

                # Game start
                print(f"username: \033[0;35m{username}\033[0m, enter game start step")
                # sorted_players = sorted(self.rooms[room])
                sorted_players = self.rooms[room]
                if sorted_players[0] == username:
                    ihandler.send(f"START {self.rooms_game[room]} SERVER VERSION {self.games_folder.get_game_version(self.rooms_game[room])}")

                    # possible request to download the game
                    msg = ihandler.get_line()
                    msg_ip_port = ""
                    if msg.startswith("DOWNLOAD"):
                        split_msg = msg.split(' ')
                        game_name = split_msg[1]
                        print(f"username: \033[0;35m{username}\033[0m requested to download the game {game_name}")
                        download_game(ihandler, game_name)
                        print(f"Game {game_name} downloaded to \033[0;35m{username}\033[0m")
                        msg_ip_port = ihandler.get_line()
                    else:
                        msg_ip_port = msg

                    # read the server's ip and port
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
                    print(f"Server's IP: {server_ip}, port: {server_port} sent to \033[0;35m{sorted_players[1]}\033[0m")
                    
                elif sorted_players[1] == username:
                    ihandler.send(f"START {self.rooms_game[room]} CLIENT VERSION {self.games_folder.get_game_version(self.rooms_game[room])}")
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
                    elif msg.startswith("DOWNLOAD"):
                        split_msg = msg.split(' ')
                        game_name = split_msg[1]
                        download_game(ihandler, game_name)
        
        except BrokenPipeError or ConnectionResetError:
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