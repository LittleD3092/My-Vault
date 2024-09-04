import time
class Response():
    def __init__(self, socket, stream) -> None:
        self.socket = socket
        self.stream = stream

        # fieleds
        self.version = "" # e.g., "HTTP/1.0"
        self.status = ""  # e.g., "200 OK"
        self.headers = {} # e.g., {content-type: application/json}
        self.body = b""  # e.g. "{'id': '123', 'key':'456'}"
        self.body_length = 0
        self.complete = False
        self.__reamin_bytes = b""

    def get_remain_body(self):
        try:
            recv_bytes = self.socket.recv(4096)
            if recv_bytes == b"":
                self.complete = True
                self.socket.close()
                return None
        except:
            self.socket.close()
            return None
        if 'transfer-encoding' in self.headers and self.headers['transfer-encoding'] == 'chunked':
            raw_bytes = self.__reamin_bytes + recv_bytes # combine bytes
            decode_body = b""
            while len(raw_bytes) > 0: # parse body
                index = raw_bytes.find(b'\r\n')
                if index == -1:
                    break
                hex_str = raw_bytes[:index].decode()
                size = int(f"0x{hex_str}",16)
                if size == 0 and raw_bytes == b"0\r\n\r\n":
                    self.complete = True
                    break
                if len(raw_bytes) < index + 2 + size + 2: # 2 for "\r\n" after index, 2 for "\r\n" at end of body data  
                    break
                decode_body += raw_bytes[index+2:index+2+size]
                raw_bytes = raw_bytes[index+4+size:]
            self.__reamin_bytes = raw_bytes # save remain bytes
            return decode_body
        if 'content-length' in self.headers:
            self.body_length += len(recv_bytes)
            if int(self.headers['content-length']) <= self.body_length:
                self.complete = True
            return recv_bytes
        return None

    def get_full_body(self):
        if self.stream or not self.complete:
            return None
        return self.body

    def get_stream_content(self):
        if not self.stream or self.complete: # use stream receiving or response is complete
            return None
        if self.body != b"":
            content = self.body
            self.body = b""
            return content
        content = self.get_remain_body()
        return content # part of the HTTP response body
    
