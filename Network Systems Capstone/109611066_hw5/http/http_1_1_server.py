import socket
import threading
from datetime import datetime
import json
from hashlib import sha256
import hmac
import base64
import random
import os
from pathlib import Path
from .utils import parser

def hmac_sha256(data, key):
    key = key.encode('utf-8')
    message = data.encode('utf-8')
    sign = base64.b64encode(hmac.new(key, message, digestmod=sha256).digest())
    sign = str(sign, 'utf-8')
    return sign

class ClientHandler():
    def __init__(self, client_socket, address, args) -> None:
        self.client_socket = client_socket
        self.client_socket.settimeout(5)
        self.address = address
        self.args = args
        self.alive = True
        self.key = hmac_sha256(f'key{random.random()*100}', 'http11')
        # TODO: Create a thead to handle the client.
        # Call self.recv_thread = threading.Thread(target=self.__recv_loop)
        # Call self.recv_thread.start()
        self.recv_thread = threading.Thread(target=self.__recv_loop)
        self.recv_thread.start()

    def close(self):
        self.alive = False
        self.client_socket.close()

    def __bad_request_response(self):
        response = {
            'version': "HTTP/1.1", 
            'status': "400 Bad Request",
            'headers': {'Content-Type': 'text/html'},
            'body': b"<html><body><h1>400 Bad Request</h1></body></html>"  
        }
        return response
        
    def __not_found_response(self):
        response = {
            'version': "HTTP/1.1", 
            'status': "404 Not Found",
            'headers': {'Content-Type': 'text/html'},
            'body': b"<html><body><h1>404 Not Found</h1></body></html>" 
        }
        return response

    def __do_get(self, request):
        path = request.path
        query = request.query
        response = self.__not_found_response()
        if path == "/":
            response['status'] = "200 OK"
            response["headers"] = {'Content-Type': 'text/html'}
            file_names = []
            for i in random.sample(range(10), 3):
                file_names.append(f"file_{str(i).zfill(2)}.txt")
            response['body'] = f'''<html>
    <header>
    </header>
    <body>
        <a href="/static/{file_names[0]}">{file_names[0]}</a>
        <br/>
        <a href="/static/{file_names[1]}">{file_names[1]}</a>
        <br/>
        <a href="/static/{file_names[2]}">{file_names[2]}</a>
    </body>
</html>'''
            response['body'] = response['body'].encode()
            response['headers']['Content-Length'] = len(response['body'])
            self.__send_response(request, response)
        elif path[:8] == "/static/":
            if path[8:].find("..") != -1:
                self.__send_response(request, response)
            file_path = Path(f"{self.args['static']}/{path[8:]}")
            self.__send_file(request, file_path)
        else:
            self.__send_response(request, response)

    def __do_post(self, request):
        path = request.path
        headers = request.headers
        response = self.__not_found_response()
        # TODO: Complete the response handling for requests with the path '/hello'.
        # Hint: You can refer to __do_get().
        # TODO: Check paht is '/hello'
        if path == "/hello":
            if 'content-type' in headers and headers['content-type'] == 'application/json':
                try:
                    post_data = json.loads(request.body.decode())
                except:
                    post_data = None
            else:
                post_data = None
            if post_data:
                if 'id' in post_data and type(post_data['id']) == str:
                    # TODO: Set up the status, headers, and body of the response.
                    # stauts: "200 OK"
                    # body: f"Hello {post_data['id']}!"
                    # headers: 'Content-Type': 'text/plain', 'Content-Length': len(body)
                    response['status'] = "200 OK"
                    response["body"] = f"Hello {post_data['id']}!".encode()
                    response["headers"] = {'Content-Type': 'text/plain', 'Content-Length': len(response["body"])}

                else:
                    response['status'] = "200 OK"
                    response["headers"] = {'Content-Type': 'text/plain'}
                    response['body'] = "no id".encode()
                    response['headers']['Content-Length'] = len(response['body'])
            else:
                response = self.__bad_request_response()
            self.__send_response(request, response)
        else:
            self.__send_response(request, response)

    def __send_file(self, request, file_path):
        if not file_path.exists():
            self.__send_response(request, self.__not_found_response())
            return
        
        response = {
            'version': "HTTP/1.1", 
            'status': "200 OK", 
            'headers': {},
            'body': b""
        }
        if file_path.suffix == ".txt":
            response['headers']= {'Content-Type': 'text/plain',
                                  'Content-Length': str(os.path.getsize(file_path))}

        # TODO: Generate the string in HTTP/1.1 format, excluding the body, based on the dictionary "response".
        # response_str = ?
        # E.g.,response_str = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 100\r\n\r\n"
        response_str = f"{response['version']} {response['status']}\r\n"
        for key, value in response['headers'].items():
            response_str += f"{key}: {value}\r\n"
        response_str += "\r\n"

        with open(file_path, "rb") as f:
            self.client_socket.sendall(response_str.encode()) # send response header
            while True:
                try:
                    read_bytes = f.read(4096) # read file
                    if not read_bytes:
                        break
                    self.client_socket.sendall(read_bytes) # send response body
                except:
                    response['status'] = "send file failed"
                    break
                
        # Log
        if request:
            print(f"{self.address[0]} - - {datetime.now().strftime('%d/%m/%y %H:%M:%S')} \"{request.method} {request.resource} {request.version}\" {response['status']} -")
        else:
            print(f"{self.address[0]} - - {datetime.now().strftime('%d/%m/%y %H:%M:%S')} {response['status']} -")

    def __send_response(self, request, response):
        
        # TODO: Generate the string in HTTP/1.1 format, excluding the body, based on the dictionary "response".
        # response_str = ?
        # E.g.,response_str = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 100\r\n\r\n"
        response_str = f"{response['version']} {response['status']}\r\n"
        for key, value in response['headers'].items():
            response_str += f"{key}: {value}\r\n"
        response_str += "\r\n"

        try:
            self.client_socket.sendall(response_str.encode()+response['body']) # send response
        except:
            response['status'] = "send failed"

        # Log
        if request:
            print(f"{self.address[0]} - - {datetime.now().strftime('%d/%m/%y %H:%M:%S')} \"{request.method} {request.resource} {request.version}\" {response['status']} -")
        else:
            print(f"{self.address[0]} - - {datetime.now().strftime('%d/%m/%y %H:%M:%S')} {response['status']} -")
            
    def __recv_loop(self):
        while self.alive:
            request = parser.parse_request(self.client_socket)
            
            # parse request
            if request is None:
                self.close()
                break
            method = request.method
            # TODO: Call different functions based on the method.
            # If method is "GET", call self.__do_get(request)
            # If method is "POST", call self.__do_post(request)
            # If method is other, call self.__send_response(request, self.__bad_request_response())
            if method == "GET":
                self.__do_get(request)
            elif method == "POST":
                self.__do_post(request)
            else:
                self.__send_response(request, self.__bad_request_response())

class HTTPServer():
    def __init__(self, host="127.0.0.1", port=8080) -> None:
        self.host=host
        self.port=port
        self.args = {
            "root": os.getcwd(),
            "static": os.getcwd()+"/static"
        }
        self.alive = False

    def set_root(self, path):
        self.args['root'] = path

    def set_static(self, path):
        self.args['static'] = path

    def run(self):
        if not self.alive:
            # Create a socket object
            self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

            # Bind the socket to a specific address and port
            self.socket.bind((self.host, self.port))
            
            # Listen for incoming connections
            self.socket.listen(5)
            
            # Create a thread to accept clients
            self.thread = threading.Thread(target=self.__accept_loop)

            self.alive = True
            self.handler_list_mutex = threading.Lock()
            self.handler_list = []
            self.thread.start()

    def close(self):
        if self.alive:
            self.alive = False
            try:
                self.socket.shutdown(0)
            except:
                pass
            self.socket.close()
            self.thread.join()
            self.handler_list_mutex.acquire()
            for handler in self.handler_list:
                if handler.alive:
                    handler.close()
            self.handler_list_mutex.release()

    def __accept_loop(self):
        while self.alive:
            try:
                # Establish a connection with the client
                client, address = self.socket.accept()
                
                # TODO: Generate a ClientHander to hande request
                # Call client_handler = ClientHandler(client, address, self.args)
                client_handler = ClientHandler(client, address, self.args)

                self.handler_list_mutex.acquire()
                for handler in reversed(self.handler_list):
                    if not handler.alive:
                        self.handler_list.remove(handler)
                self.handler_list.append(client_handler)
                self.handler_list_mutex.release()

            except:
                # catch socket closed
                self.alive = False

if __name__ == '__main__':
    server = HTTPServer()
    server.run()

    while True:
        cmd = input()
        if cmd == 'close' or cmd == 'exit':
            server.close()
            break