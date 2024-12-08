import socket
import time
import threading
import random
import ipaddress
from queue import Queue
import os
import traceback
import json
import importlib

# LOBBY_IP = 'linux1.cs.nycu.edu.tw'
LOBBY_IP = 'localhost'
LOBBY_PORT = 11066
CLEAN_DATA_RUN = False

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
                msg = msg.strip('\ufeff')
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

class ClientGamesFolder:
    def __init__(self, username = None):
        if username == None:
            self.valid = False
            return

        self.folder_name = f"client_games/{username}"
        if not os.path.exists(self.folder_name):
            os.makedirs(self.folder_name)
        self.games = {}
        self.game_version = {}
        self.valid = True
        self.username = username

        if not CLEAN_DATA_RUN:
            if not os.path.exists(f"{self.folder_name}"):
                os.makedirs(f"{self.folder_name}")
            try:
                with open(f"{self.folder_name}/info.json", 'r') as f:
                    data = json.load(f)
                    self.games = data['games']
                    self.game_version = data['version']
            except FileNotFoundError:
                with open(f"{self.folder_name}/info.json", 'w') as f:
                    info = {
                        'games': {},
                        'version': {}
                    }
                    json.dump(info, f, indent=4)
                self.games = {}
                self.game_version = {}

    def write_info(self):
        if not self.valid:
            return
        info = {
            "games": self.games,
            "version": self.game_version
        }
        with open(f"{self.folder_name}/info.json", 'w') as f:
            json.dump(info, f, indent=4)

    def get_game_code(self, filename):
        if not self.valid:
            return None
        with open(f"{self.folder_name}/{filename}", 'r') as f:
            return f.readlines()
        
    def update_game_info(self, game_name, filename, version):
        if not self.valid:
            return
        self.games[game_name] = filename
        self.game_version[game_name] = version
        self.write_info()
        
    def exists(self, game_name):
        if not self.valid:
            return False
        return game_name in self.games
    
    def load_game(self, game_name):
        filename = self.games[game_name]
        class_name = filename.split('.')[0]
        module_name = f"client_games.{self.username}.{filename[:-3]}"
        script = importlib.import_module(module_name)
        game_obj = getattr(script, class_name)()
        return game_obj
    
    def write_game(self, game_name, version, game_code):
        if not self.valid:
            return
        filename = f"{game_name}.py"
        with open(f"{self.folder_name}/{filename}", 'w') as f:
            f.writelines(game_code)
        self.update_game_info(game_name, filename, version)

class GameBugException(Exception):
    def __init__(self, message):
        self.message = message

def connect_io_server(ip, port):
    tcp_client = TCP_client('0.0.0.0', 0, ip, port)
    game_client = None
    game_server = None
    game_obj = None
    end = False
    game_folder = ClientGamesFolder()

    def download_game(game_name, version):
        try:
            if not game_folder.valid:
                raise Exception(f"In download_game: Invalid game folder = {game_folder.__dict__}")
            game_code = ""
            while True:
                line = tcp_client.receive()
                if line == "END":
                    break
                game_code += line + '\n'
            game_folder.write_game(game_name, version, game_code)
        except Exception as e:
            print(f"Error in download_game: {e}")
            traceback.print_exc()

    def lobby_receive_thread():
        try:
            nonlocal game_client, game_server, end, game_obj, game_folder
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

                # Check for game uploading triggers
                if msg.startswith("UPLOAD"):
                    splitted_msg = msg.split(' ')
                    game_filename = splitted_msg[1]
                    game_code = game_folder.get_game_code(game_filename)
                    for line in game_code:
                        tcp_client.send(line)
                    tcp_client.send("END")
                    continue
                if msg.startswith("GAME"):
                    splitted_msg = msg.split(' ')
                    game_name = splitted_msg[splitted_msg.index("GAME") + 1]
                    game_version = splitted_msg[splitted_msg.index("VERSION") + 1]
                    game_filename = splitted_msg[splitted_msg.index("FILENAME") + 1]
                    game_folder.update_game_info(game_name, game_filename, game_version)
                    continue

                # Check for game downloading triggers
                if msg.startswith("DOWNLOAD"):
                    game_name = msg.split(' ')[1]
                    version = msg.split(' ')[3]
                    if not game_folder.exists(game_name) or game_folder.game_version[game_name] != version:
                        print("Local game not found. Downloading game...")
                        tcp_client.send("DOWNLOAD " + game_name)
                        download_game(game_name, version)
                        print(f"Game {game_name} downloaded.")
                    else:
                        tcp_client.send("PING")
                    continue

                # Check login/logout triggers
                if msg.startswith("LOGIN"):
                    splitted_msg = msg.split(' ')
                    username = splitted_msg[1]
                    game_folder = ClientGamesFolder(username)
                    continue
                if msg.startswith("LOGOUT"):
                    game_folder = ClientGamesFolder()
                    continue

                # Check for early ip and port triggers
                if msg.startswith("IP"):
                    game_ip = msg.split(' ')[1]
                    game_port = int(msg.split(' ')[3])
                    game_client = TCP_client('0.0.0.0', 0, game_ip, game_port)

                # Check for game start triggers
                splitted_msg = msg.split(' ')

                if splitted_msg[0] == "START":
                    game = splitted_msg[1]
                    version = splitted_msg[splitted_msg.index("VERSION") + 1]
                    if not game_folder.exists(game) or game_folder.game_version[game] != version:
                        print("Local game not found. Downloading game...")
                        tcp_client.send("DOWNLOAD " + game)
                        download_game(game, version)
                        print(f"Game {game} downloaded.")

                    if splitted_msg[2] == "CLIENT":
                        print(f"Starting game {game} as client...")
                        if game_client == None:
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
                        # if game == "Battleship":
                        #     game_obj = BattleShip()
                        # elif game == "Checkers":
                        #     game_obj = Checkers()
                        if game_folder.exists(game):
                            game_obj = game_folder.load_game(game)
                        else:
                            raise Exception("In lobby_receive_thread: Game not found")
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
                try:
                    game_obj.main(game_agent)
                except Exception as e:
                    print(f"\033[0;31mError when running game: {e}\033[0m")
                    game_agent.send(f"\033[0;31mError when running game: {e}\033[0m")
                    game_agent.send("GAME_END")
                    raise GameBugException(f"Error when running game: {e}")
                game_client = None
                game_server = None
                print("Game session ended. Returning to lobby.")
                tcp_client.send("GAME_END")
            else:
                raise Exception("In game_receive_thread: Invalid game agent type")
        except KeyboardInterrupt:
            end = True
            print('Closing game connection...')
        except GameBugException as e:
            game_client = None
            game_server = None
            tcp_client.send("GAME_END")
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