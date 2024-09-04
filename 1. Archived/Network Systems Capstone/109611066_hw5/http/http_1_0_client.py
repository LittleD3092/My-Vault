import socket
from .utils import parser

class HTTPClient:
    def __init__(self) -> None:
        pass
    
    def get(self, url, headers=None, stream=False):
        result = parser.parse_url(url)
        if result is None:
            return None
        scheme = result[0]
        address = result[1]
        resource = result[2]

        # TODO: Generate the string in HTTP/1.0 format, excluding the body, based on the dictionary "headers".
        # headers_str = ?
        # E.g., headers_str = "header1: 1\r\nheader2: 2\r\n"
        headers_str = ""
        if headers:
            for key, value in headers.items():
                headers_str += f"{key}: {value}\r\n"
        
        # TODO: Format the string in HTTP/1.0 format, excluding the body and encode the string to bytes.
        # request = ?
        # E.g., request = b"GET / HTTP/1.0\r\nheader1: 1\r\nheader2: 2\r\n\r\n"
        request = f"GET {resource} HTTP/1.0\r\n{headers_str}\r\n".encode()

        return self.__send_request(address, request, stream)
    
    def post(self, url, headers=None, body=None, stream=False):
        result = parser.parse_url(url)
        if result is None:
            return None
        scheme = result[0]
        address = result[1]
        resource = result[2]

        # TODO: Generate the string in HTTP/1.0 format, excluding the body, based on the dictionary "headers".
        # headers_str = ?
        # E.g., headers_str = "header1: 1\r\nheader2: 2\r\n"
        headers_str = ""
        if headers:
            for key, value in headers.items():
                headers_str += f"{key}: {value}\r\n"
        
        # TODO: Format the string in HTTP/1.0 format, excluding the body and encode the string to bytes.
        # request = ?
        # E.g., request = b"GET / HTTP/1.0\r\nheader1: 1\r\nheader2: 2\r\n\r\n"
        request = f"POST {resource} HTTP/1.0\r\n{headers_str}\r\n".encode()

        if body:
            # TODO: Append the bytes with body.
            # request = ?
            # E.g., request = b"GET / HTTP/1.0\r\nheader1: 1\r\nheader2: 2\r\n\r\nthis is body"
            request += body
            
        return self.__send_request(address, request, stream)
    
    def __send_request(self, address, request, stream):
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client_socket.settimeout(5)
        # TODO: Attempting to connect client_socket to the address; if unsuccessful, return None.
        # Hint: Use try...except... and client_socket.connect()
        try:
            client_socket.connect(address)
        except:
            return None
        
        # TODO: Attempting to send a request using client_socket; if unsuccessful, return None.
        # Hint: Use try...except... and client_socket.sendall()
        try:
            client_socket.sendall(request)
        except:
            return None

        # Receive the server's response
        response = parser.parse_response(client_socket, stream)
        if response and response.complete:
            client_socket.close()
        
        return response
    