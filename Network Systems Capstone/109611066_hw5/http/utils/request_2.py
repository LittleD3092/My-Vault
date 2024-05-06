import threading
import time
from collections import deque

class Request_2:
    def __init__(self, stream_id, headers, method, resource, path, query, scheme, authority) -> None:
        self.stream_id = stream_id
        self.headers = headers
        self.version = "HTTP/2.0"

        self.resource = resource
        self.method = method
        self.path = path
        self.query = query
        self.scheme = scheme
        self.authority = authority
        self.body = b"" # only after getting full body will have

        self.contents = deque()
        self.lock = threading.Lock()
        self.complete = False
    
    def append_headers(self, headers):
        for header in headers:
            self.headers[header] = headers[header]

    def append_body(self, body):
        if self.complete:
            raise "Stream is closed"
        self.contents.append(body)

    def get_full_body(self):
        begin_time = time.time()
        while not self.complete:
            if time.time() - begin_time > 5:
                return None
        if len(self.body) > 0:
            return self.body
        while len(self.contents) > 0:
            self.body += self.contents.popleft()

        return self.body

    def get_stream_content(self, size):
        begin_time = time.time()
        while len(self.contents) == 0:
            if self.complete:
                return None
            if time.time() - begin_time > 5:
                return None

        return self.contents.popleft()