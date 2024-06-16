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
from .utils import http_2_frame
from .utils import parser
from collections import deque
import time

def hmac_sha256(data, key):
    key = key.encode('utf-8')
    message = data.encode('utf-8')
    sign = base64.b64encode(hmac.new(key, message, digestmod=sha256).digest())
    sign = str(sign, 'utf-8')
    return sign

class RequestHandler():
    def __init__(self, client, request) -> None:
        self.client = client
        self.request = request
        self.complete = False
        # TODO: Create a thead to handle the request.
        # Call self.thread = threading.Thread(target=self.__handle_request)
        # Call self.thread.start()
        self.thread = threading.Thread(target=self.__handle_request)
        self.thread.start()

    def __bad_request_response(self):
        response = {
            'version': "HTTP/2.0", # e.g. "HTTP/1.0"
            'status': "400 Bad Request", # e.g. "200 OK"
            'headers': {'Content-Type': 'text/html'}, # e.g. {content-type: application/json}
            'body': b"<html><body><h1>400 Bad Request</h1></body></html>"  
        }
        return response
        
    def __not_found_response(self):
        response = {
            'version': "HTTP/2.0", # e.g. "HTTP/1.0"
            'status': "404 Not Found", # e.g. "200 OK"
            'headers': {'Content-Type': 'text/html'}, # e.g. {content-type: application/json}
            'body': b"<html><body><h1>404 Not Found</h1></body></html>" 
        }
        return response

    def __do_get(self):
        path = self.request.path
        query = self.request.query
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
            self.__send_response(response)
        elif path[:8] == "/static/":
            if path[8:].find("..") != -1:
                self.__send_response(response)
            file_path = Path(f"{self.client.args['static']}/{path[8:]}")
            self.__send_file(file_path)
        else:
            self.__send_response(response)

    def __do_post(self):
        path = self.request.path
        headers = self.request.headers
        response = self.__not_found_response()
        # TODO: Complete the response handling for requests with the path '/hello'.
        # Hint: You can refer to __do_get().
        # TODO: Check paht is '/hello'
        if path == "/hello":
            if 'content-type' in headers and headers['content-type'] == 'application/json':
                try:
                    body = self.request.get_full_body()
                    post_data = json.loads(body.decode())
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
                    response["headers"] = {'Content-Type': 'text/plain'}
                    response['body'] = f"Hello {post_data['id']}!".encode()
                    response['headers']['Content-Length'] = len(response['body'])
                else:
                    response['status'] = "200 OK"
                    response["headers"] = {'Content-Type': 'text/plain'}
                    response['body'] = "no id".encode()
                    response['headers']['Content-Length'] = len(response['body'])
            else:
                response = self.__bad_request_response()
            self.__send_response(response)
        else:
            self.__send_response(response)

    def __send_response(self, response):
        response['headers'][':status'] = response['status']
        stream_id = self.request.stream_id
        self.__send_headers(stream_id, response['headers'])
        self.__send_body(stream_id, response['body'])

        # Log
        if self.request:
            print(f"{self.client.address[0]} - - {datetime.now().strftime('%d/%m/%y %H:%M:%S')} \"{self.request.method} {self.request.resource} {self.request.version}\" {response['status']} -")
        else:
            print(f"{self.client.address[0]} - - {datetime.now().strftime('%d/%m/%y %H:%M:%S')} {response['status']} -")

    def __send_file(self, file_path):
        if not file_path.exists():
            self.__send_response(self.__not_found_response())
            return
        
        response = {
            'version': "HTTP/2.0", 
            'status': "200 OK", 
            'headers': {},
            'body': b""
        }
        if file_path.suffix == ".txt":
            response['headers']= {'Content-Type': 'text/plain'}
        response['headers'][':status'] = response['status']
        stream_id = self.request.stream_id
        self.__send_headers(stream_id, response['headers'])

        chunk_size = http_2_frame.Frame.max_payload_size
        with open(file_path, "rb") as f:
            data = b""
            while self.client.alive:
                read_bytes = f.read(chunk_size)
                if not read_bytes:
                    break
                if data != b"":
                    frame = http_2_frame.create_data_frame(stream_id, data)
                    try:
                        self.client.client_socket.sendall(frame.to_bytes())
                        time.sleep(0.001)
                    except:
                        self.client.close()
                        break
                data = read_bytes
            if self.client.alive:
                try:
                    frame = http_2_frame.create_data_frame(stream_id, data, flags=True)
                    self.client.client_socket.sendall(frame.to_bytes())
                except:
                    self.client.close()
                
        # Log
        if self.request:
            print(f"{self.client.address[0]} - - {datetime.now().strftime('%d/%m/%y %H:%M:%S')} \"{self.request.method} {self.request.resource} {self.request.version}\" {response['status']} -")
        else:
            print(f"{self.client.address[0]} - - {datetime.now().strftime('%d/%m/%y %H:%M:%S')} {response['status']} -")

    def __send_headers(self, stream_id, headers, flags=False):
        hdr = ""
        for key in headers:
            hdr += f"{key.lower()}: {headers[key]}\r\n"
        if flags:
            flags = 1
        else:
            flags = 0
        frame = http_2_frame.create_headers_frame(stream_id, hdr.encode(), flags=flags)
        try:
            self.client.client_socket.sendall(frame.to_bytes())
        except:
            self.client.close()

    def __send_body(self, stream_id, body):
        chunk_size = http_2_frame.Frame.max_payload_size
        while len(body) > chunk_size:
            frame = http_2_frame.create_data_frame(stream_id, body[:chunk_size])
            body = body[chunk_size:]
            self.client.client_socket.sendall(frame.to_bytes())
        frame = http_2_frame.create_data_frame(stream_id, body, flags=True)
        try:
            self.client.client_socket.sendall(frame.to_bytes())
        except:
            self.client.close()

    def __handle_request(self):
        if self.request:
            method = self.request.method
        else:
            method = ""
        # Check the method and path
        if method == "GET":
            self.__do_get()
        elif method == "POST":
            self.__do_post()
        else:
            self.__send_response(self.__bad_request_response())
        self.complete = True
        
class ClientHandler():
    def __init__(self, client_socket, address, args) -> None:
        self.client_socket = client_socket
        self.client_socket.settimeout(10)
        self.address = address
        self.args = args
        self.alive = True
        self.recv_buffer = b""
        self.recv_streams = {}
        self.request_handler_deque = deque()

        self.key = hmac_sha256(f'key{random.random()*100}', 'http11')
        # TODO: Create a thead to handle the client.
        # Call self.recv_thread = threading.Thread(target=self.__recv_loop)
        # Call self.recv_thread.start()
        self.recv_thread = threading.Thread(target=self.__recv_loop)
        self.recv_thread.start()

    def close(self):
        self.alive = False
        self.client_socket.close()

    def __recv_loop(self):
        while self.alive:
            while len(self.request_handler_deque) > 0:
                if self.request_handler_deque[0].complete:
                    self.request_handler_deque.popleft()
                else:
                    break
            try:
                # Recv request
                recv_bytes = self.client_socket.recv(4096)

                # check connection
                if recv_bytes == b"":
                    self.alive = False
                    self.client_socket.close()
                    break
            except:
                if len(self.request_handler_deque) > 0:
                    continue
                self.alive = False
                self.client_socket.close()
                break

            # TODO: Merge the bytes with recv_buffer and recv_bytes.
            # Call recv_bytes = self.recv_buffer + recv_bytes
            recv_bytes = self.recv_buffer + recv_bytes

            # parse request
            frames, remian_bytes = http_2_frame.bytes_to_frames(recv_bytes)
            self.recv_buffer = remian_bytes
            for frame in frames:
                # TODO: Complete the frame handling.
                if frame.type == 0: # data
                    if frame.stream_id in self.recv_streams:
                        self.recv_streams[frame.stream_id].append_body(frame.payload)
                # TODO: Check frame.type is 1(headers frame)
                if frame.type == 1:
                    request = parser.parse_request_2(frame.stream_id, frame.payload)
                    already_exsit = False
                    if frame.stream_id in self.recv_streams:
                        already_exsit = True
                    if request and not already_exsit:
                        # TODO: Add the request to self.recv_streams using the key frame.stream_id.
                        self.recv_streams[frame.stream_id] = request

                        # TODO: Create a RequestHandler with the request and append it to self.request_handler_deque.
                        request_handler = RequestHandler(self, request)
                    else:
                        request_handler = RequestHandler(self, None)

                if frame.flags == 1:
                    if frame.stream_id in self.recv_streams:
                        self.recv_streams[frame.stream_id].complete = True
                        del self.recv_streams[frame.stream_id]

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

    def __accept_loop(self):
        while self.alive:
            try:
                # Establish a connection with the client
                client, address = self.socket.accept()

                # TODO: Generate a ClientHander to hande request
                # Call client_handler = ClientHandler(client, address, self.args)
                client_handler = ClientHandler(client, address, self.args)

                for handler in reversed(self.handler_list):
                    if not handler.alive:
                        self.handler_list.remove(handler)
                self.handler_list.append(client_handler)

            except:
                # catch socket closed
                self.alive = False
                pass


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
            for handler in reversed(self.handler_list):
                if handler.alive:
                    handler.close()

if __name__ == '__main__':
    server = HTTPServer()
    server.run()

    while True:
        cmd = input()
        if cmd == 'close' or cmd == 'exit':
            server.close()
            break