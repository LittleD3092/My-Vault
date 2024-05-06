import socket
import threading
import time
from .utils import http_2_frame
from .utils import parser, response_2
from collections import deque
import time
        
class Connection:
    def __init__(self, client_socket) -> None:
        self.client_socket = client_socket
        self.connecting = True
        self.recv_buffer = b""
        self.recv_streams = {}
        self.send_streams = {}
        self.next_stream_id = 1
        # TODO: Create a thread to handle the bytes received from the server.
        # self.recv_thread = threading.Thread(target=self.__recv_loop)
        # self.recv_thread.start()
        
        # TODO: Create a thread to handle the frames to be sent to the server.
        # self.send_thread = threading.Thread(target=self.__send_loop)
        # self.send_thread.start()
        

    def send_request(self, request):
        if not self.connecting:
            return
        stream_id = self.__get_next_stream_id()
        headers = request['headers']
        if 'body' in request:
            # TODO: Send headers and body
            # Call self.__send_headers(stream_id, headers)
            # self.__send_body(stream_id, body)
            self.__send_headers(stream_id, headers)
            body = request['body']
            self.__send_body(stream_id, body)
        else:
            # TODO: Send headers
            # Call self.__send_headers(stream_id, headers, end_stream=True)
            
        response = response_2.Response_2(stream_id)
        self.recv_streams[stream_id] = response
        return response
     
    def close(self):
        self.connecting=False
        self.client_socket.close()

    def __get_next_stream_id(self):
        stream_id = self.next_stream_id
        self.next_stream_id += 2
        return stream_id
    
    def __send_headers(self, stream_id, headers, end_stream=False):
        # TODO: Generate the string of the headers frame payload in HTTP/2 format based on the dictionary "headers".
        # headers_str = ?
        # E.g., headers_str = "header1: 1\r\nheader2: 2\r\n"
        
        
        if end_stream:
            flags = 1
        else:
            flags = 0
        frame = http_2_frame.create_headers_frame(stream_id, headers_str.encode(), flags=flags)
        self.send_streams[stream_id] = deque([frame])

    def __send_body(self, stream_id, body):
        # Generate the data frames in HTTP/2 format
        chunk_size = http_2_frame.Frame.max_payload_size
        while len(body) > chunk_size:
            # TODO: Generate a data frame in HTTP/2 format, the payload should be limited to chunk_size.
            # Hint: payload=body[:chunk_size]
            # Hint: After creating a data frame, set the body to body[chunk_size:].
            
            self.send_streams[stream_id].append(frame) 
        frame = http_2_frame.create_data_frame(stream_id, body, flags=1)
        self.send_streams[stream_id].append(frame) 
       
    def __send_loop(self):
        while self.connecting:
            try:
                end_streams = []
                keys = list(self.send_streams.keys())
                # Round Robin
                for key in keys:
                    if len(self.send_streams[key]) > 0:
                        # TODO: Pop the leftmost frame from self.send_streams[key] and send it.
                        # Hint: Use popleft()
                        # Call self.client_socket.sendall(frame.to_bytes())
                        
                        
                        if frame.flags == 1:
                            end_streams.append(key)
                        time.sleep(0.002)
                for key in end_streams:
                    del self.send_streams[key]
            except:
                self.connecting = False
                self.client_socket.close()
                break

    def __recv_loop(self):
        while self.connecting:
            try:
                recv_bytes = self.client_socket.recv(4096)
                if not recv_bytes:
                    self.connecting = False
                    self.client_socket.close()
                    break
            except:
                self.connecting=False
                self.client_socket.close()
                break

            # TODO: Merge the bytes with recv_buffer and recv_bytes.
            # Call recv_bytes = self.recv_buffer + recv_bytes
            
            # parse request
            frames, remain_bytes = http_2_frame.bytes_to_frames(recv_bytes)
            self.recv_buffer = remain_bytes
            for frame in frames:
                # TODO: Complete the frame handling.
                if frame.type == 0: # data
                    if frame.stream_id in self.recv_streams:
                        self.recv_streams[frame.stream_id].append_body(frame.payload)
                # TODO: Check frame.type is 1(headers frame)
                
                    response = parser.parse_response_2(frame.stream_id, frame.payload)
                    if response:
                        if frame.stream_id in self.recv_streams:
                            if self.recv_streams[frame.stream_id].status == "Not yet":
                                self.recv_streams[frame.stream_id].headers = response.headers
                                self.recv_streams[frame.stream_id].status = response.status
                        else:
                            # TODO: Add the response to self.recv_streams using the key frame.stream_id.
                            
                if frame.flags == 1:
                    if frame.stream_id in self.recv_streams:
                        self.recv_streams[frame.stream_id].complete = True
                        del self.recv_streams[frame.stream_id]
class HTTPClient:
    def __init__(self) -> None:
        self.connection_pool = {}

    def get(self, url, headers=None):
        result = parser.parse_url(url)
        if result is None:
            return None
        scheme = result[0]
        address = result[1]
        resource = result[2]

        if headers is None:
            headers = {}

        # TODO: Set headers with ":method", ":path", ":scheme", and ":authority".
        # Hint: These four headers correspond to "GET", resource, scheme, and f"{address[0]}:{address[1]}".
        

        request = {
            'headers': headers
        }
        return self.__send_request(address, request)
    
    def post(self, url, headers=None, body=None):
        result = parser.parse_url(url)
        if result is None:
            return None
        scheme = result[0]
        address = result[1]
        resource = result[2]

        if headers is None:
            headers = {}

        headers[":method"] = "POST"
        headers[":path"] = resource
        headers[":scheme"] = scheme
        headers[":authority"] = f"{address[0]}:{address[1]}"

        request = {
            'headers': headers
        }
        if body:
            request['body'] = body
        return self.__send_request(address, request)
    
    def __send_request(self, address, request):
        # Get connection in pool
        if f"{address[0]}:{address[1]}" in self.connection_pool:
            connection = self.connection_pool[f"{address[0]}:{address[1]}"]
        else:
            client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            client_socket.settimeout(5)
            try:
                client_socket.connect(address)
            except:
                return None
            connection = Connection(client_socket)
            self.connection_pool[f"{address[0]}:{address[1]}"] = connection
        
        # Check connection
        if not connection.connecting:
            client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            client_socket.settimeout(5)
            try:
                client_socket.connect(address)
            except:
                return None
            connection = Connection(client_socket)
        return connection.send_request(request)
        


