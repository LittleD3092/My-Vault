import threading
import time
from collections import deque

class Response_2:
    def __init__(self, stream_id, headers = {}, status = "Not yet") -> None:
        self.stream_id = stream_id
        self.headers = headers
        
        self.status = status
        self.body = b""

        self.contents = deque()
        self.complete = False
    
    def get_headers(self):
        begin_time = time.time()
        while self.status == "Not yet":
            if time.time() - begin_time > 5:
                return None
        return self.headers

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
    
    def get_stream_content(self):
        begin_time = time.time()
        while len(self.contents) == 0:
            if self.complete:
                return None
            if time.time() - begin_time > 20:
                return None
            time.sleep(0.01)
        
        return self.contents.popleft()