import socket
from . import request_1, response_1
from . import request_2, response_2
    
def parse_url(url):
    scheme = "http"
    port = 80
    if url[:8] == "https://":
        scheme = "https"
        port = 443
        url = url[8:]
    elif url[:7] == "http://":
        url = url[7:]
    
    index = url.find("/")
    if index != -1:
        host = url[:index]
        resource = url[index:]
    elif len(url) > 0:
        host = url
        resource = "/"
    else:
        return None
    
    host_port = host.split(":")
    if len(host_port) == 2:
        host = host_port[0]
        try:
            port = int(host_port[1])
        except:
            return None
    elif len(host_port) == 1:
        host = host_port[0]
    else:
        return None
    try:
        host = socket.gethostbyname(host)
    except:
        return None
    return scheme, (host, port), resource

# use to parse path, params from resource(str)
# return (path, params)
def parse_resource(resource):
    # Split resource into path and parameters
    resource = resource.split('?')
    if len(resource) == 2:
        path, query = resource
    else:
        return resource[0], {}
    
    # Split the parameters into list
    query = query.split('&')

    # Initialize an empty dictionary to store the params
    params = {}
    
    # Iterate through the parameters
    for para in query:
        # Split the para into a key-value pair
        para = para.split('=')
        if (len(para) == 2):
            key, value = para
            params[key] = value
    return path, params

def parse_response_2(stream_id, raw_bytes):
    # Parse raw_bytes to get headers
    """
    Hint: raw_bytes foramt: b"<headers>"
            <headers>::= <header>*
                <header>::= <key>": "<value>"\r\n"
        E.g., Request raw_bytes may be b":status: 200\r\nContent-Type: text/plain\r\nContent-Length: 4096\r\n"

    """
    # TODO: Split the raw_bytes into a list of bytes
    # E.g., lines = [b":status: 200 OK", b"Content-Type: text/plain", b"Content-Length: 4096"]
    

    # Initialize an empty dictionary to store the headers
    headers = {}
    # TODO: Extract headers from the list obtained by splitting
    # Hint: Header keys should be converted to lowercase.
    # Hint: Bytes should be decoded using decode() to obtain a string.
    # E.g., headers = {":status": "200 OK", "content-type": "text/plain", "content-length": "4096"}
    
            
    # Check valid or not
    if ':status' not in headers:
        return None

    request = response_2.Response_2(stream_id, headers, headers[":status"])
    return request

# raw_bytes: bytes in frame payload
def parse_request_2(stream_id, raw_bytes):
    # Parse raw_bytes to get headers
    """
    Hint: raw_bytes foramt: b"<headers>"
            <headers>::= <header>*
                <header>::= <key>": "<value>"\r\n"
        E.g., Request raw_bytes may be b":method: GET\r\n:path: /\r\n:scheme: http\r\n:authority: 127.0.0.1:8080\r\n"

    """
    # TODO: Split the raw_bytes into a list of bytes
    # E.g., lines = [b":method: GET", b"path: /", b":scheme: http", b":authority: 127.0.0.1:8080"]
    

    # Initialize an empty dictionary to store the headers
    headers = {}
    # TODO: Extract headers from the list obtained by splitting
    # Hint: Header keys should be converted to lowercase.
    # Hint: Bytes should be decoded using decode() to obtain a string.
    # E.g., headers = {":method": "GET", ":path": "/", ":scheme": "http", ":authority": "127.0.0.1:8080"}
    
    
    # Check valid or not
    if ':method' not in headers or ":path" not in headers or ":scheme" not in headers or ":authority" not in headers:
        return None
    path, query = parse_resource(headers[":path"])

    request = request_2.Request_2(stream_id, headers, headers[":method"], headers[":path"], path, query, headers[":scheme"], headers[":authority"])
    return request

def parse_response(client_socket, stream):
    response = response_1.Response(client_socket, stream)
    raw_bytes = b""
    # Received bytes until the header is completely received
    while True:
        try:
            recv_bytes = client_socket.recv(4096)
            if recv_bytes == b"":
                client_socket.close()
                return None
            raw_bytes += recv_bytes
            if raw_bytes.find(b"\r\n\r\n") != -1: # Check the end of header
                break
        except:
            client_socket.close()
            return None
    
    # Parse raw_bytes and set request.version, request.status, request.headers
    """
    Hint: Response raw_bytes foramt: b"<HTTP-version> <status>\r\n<headers>\r\n<body>"
            <headers>::= <header>*
                <header>::= <key>": "<value>"\r\n"
        E.g., Response raw_bytes may be b"HTTP/1.0 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 4096\r\n\r\nabcabcabcabc"

    """
    # TODO: Split the raw_bytes into a list of bytes
    # E.g., lines = [b"HTTP/1.0 200 OK", b"Content-Type: text/plain", b"Content-Length: 4096", b"", b"abcabcabcabc"]
    lines = raw_bytes.split(b"\r\n")

    if len(lines) < 2:
        return None

    # TODO: Extract the version and status from the list obtained by splitting
    # Hint: Bytes should be decoded using decode() to obtain a string.
    # E.g., response.version = "HTTP/1.0"
    # E.g., response.status = "200 OK"
    response.version, response.status = lines[0].decode().split(" ", 1)    

    # Initialize an empty dictionary to store the headers
    headers = {}

    # TODO: Extract headers from the list obtained by splitting
    # Hint: Header keys should be converted to lowercase.
    # Hint: Bytes should be decoded using decode() to obtain a string.
    # E.g., headers = {"content-type": "text/plain", "content-length": "4096"}
    for line in lines[1:]:
        if line == b"":
            break
        key, value = line.decode().split(": ")
        headers[key.lower()] = value

    response.headers = headers

    response.complete = True
    # Extract the body from raw_bytes
    # Hint: End of headers is b"\r\n\r\n".
    body = b""
    index = raw_bytes.find(b"\r\n\r\n")
    if index != -1:
        body = raw_bytes[index+4:]
    if 'transfer-encoding' in headers and headers['transfer-encoding'] == 'chunked':
        response.complete = False
        decode_body = b""
        while len(body) > 0:
            index = body.find(b'\r\n')
            if index == -1:
                break
            hex_str = body[:index].decode()
            size = int(f"0x{hex_str}",16)
            if size == 0 and body == b"0\r\n\r\n":
                response.complete = True
                break
            if len(body) < index + 2 + size + 2: # 2 for "\r\n" after index, 2 for "\r\n" at end of body data  
                break
            decode_body += body[index+2:index+2+size]
            body = body[index+4+size:]
        response.__reamin_bytes = body
        body = decode_body
    
    response.body = body
    response.body_length = len(body)
    
    if 'content-length' in headers:
        response.complete = False
        # TODO: If the full content is received, set response.complete to True.
        # Hint: use int(headers['content-length']) and response.body_length
        if int(headers['content-length']) == response.body_length:
            response.complete = True
            
    if not stream:
        while not response.complete:
            remain_body = response.get_remain_body()
            if remain_body:
                response.body += response.get_remain_body()
 
    return response

def parse_request(client_socket):
    request = request_1.Request(client_socket)
    raw_bytes = b""
    # Received bytes until the header is completely received
    while True: 
        try:
            recv_bytes = client_socket.recv(4096)
            if recv_bytes == b"":
                client_socket.close()
                return None
            raw_bytes += recv_bytes
            if raw_bytes.find(b"\r\n\r\n") != -1: # Check the end of header
                break
        except:
            client_socket.close()
            return None
    
    # Parse raw_bytes and set request.method, request.version, request.resource, request.path, request.query, and request.headers
    """
    Hint: Request raw_bytes foramt: b"<method> <resource> <HTTP-version>\r\n<headers>\r\n<body>"
            <resource>::= <path>[<query>]
            <headers>::= <header>*
                <header>::= <key>": "<value>"\r\n"
        E.g., Request raw_bytes may be b"GET /?sid=123 HTTP/1.0\r\n\r\n"

    """
    # TODO: Split the raw_bytes into a list of bytes
    # E.g., lines = [b"GET / HTTP/1.0", b""]
    lines = raw_bytes.split(b"\r\n")
    
    if len(lines) < 2:
        return None

    # TODO: Extract the method, resource and version from the list obtained by splitting
    # Hint: Bytes should be decoded using decode() to obtain a string.
    # E.g., request.method = "HTTP/1.0"
    # E.g., resource = "/?sid=123"
    # E.g., request.version = "HTTP/1.0"
    request.method, resource, request.version = lines[0].decode().split(" ")

    # Extract the path and query from the resource
    # E.g., request.path = "/"
    # E.g., request.query = {"sid": "123"}
    request.resource = resource
    request.path, request.query = parse_resource(resource)

    # Initialize an empty dictionary to store the headers
    headers = {}
    # TODO: Extract headers from the list obtained by splitting
    # Hint: Header keys should be converted to lowercase.
    # Hint: Bytes should be decoded using decode() to obtain a string.
    # E.g., headers = {"header1": "1", "header2": "2"}
    for line in lines[1:]:
        if line == b"":
            break
        key, value = line.decode().split(": ")
        headers[key.lower()] = value
    
    request.headers = headers

    request.complete = True
    # Extract the body from raw_bytes
    # Hint: End of headers is b"\r\n\r\n".
    body = b""
    index = raw_bytes.find(b"\r\n\r\n")
    if index != -1:
        body = raw_bytes[index+4:]

    if 'transfer-encoding' in headers and headers['transfer-encoding'] == 'chunked':
        request.complete = False
        decode_body = b""
        while len(body) > 0:
            index = body.find(b'\r\n')
            if index == -1:
                break
            hex_str = body[:index].decode()
            size = int(f"0x{hex_str}",16)
            if size == 0 and body == b"0\r\n\r\n":
                request.complete = True
                break
            if len(body) < index + 2 + size + 2: # 2 for "\r\n" after index, 2 for "\r\n" at end of body data  
                break
            decode_body += body[index+2:index+2+size]
            body = body[index+4+size:]
        request.__reamin_bytes = body
        body = decode_body
    
    request.body = body
    request.body_length = len(body)
    
    if 'content-length' in headers:
        request.complete = False
        # TODO: If the full content is received, set request.complete to True.
        # Hint: use int(headers['content-length']) and request.body_length
        if int(headers['content-length']) == request.body_length:
            request.complete = True
        
 
    return request