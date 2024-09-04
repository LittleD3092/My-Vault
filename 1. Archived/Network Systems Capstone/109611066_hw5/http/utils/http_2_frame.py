import struct
    
class Frame:
    max_payload_size = 4096 # 2^14
    def __init__(self, length=0, type=0, flags=0, r=0, stream_id=0, payload=b"") -> None:
        self.length = length #(24)
        self.type = type #(8)
        self.flags  = flags #(8)
        self.r = r #(1)
        self.stream_id = stream_id #(31)
        self.payload = payload
    
    def to_bytes(self):
        # TODO return the bytes formated by length, type, flags, r, stream_id, payload
        # Hint: Use struct.pack()
        # Hint: "!" indicates network byte order (big-endian)
        # Hint: "L" indicates an unsigned long integer of 4 bytes (32 bits)
        # Hint: "B" indicates an unsigned char of 1 byte (8 bits)
        # Hint: "{self.length}s" indicates a byte string of length self.length
        # Hint: Some fields can be combined into a 32-bit value using << and | operators.
        # bytes = ?
        bytes = (
            struct.pack("!L", (self.length << 8) | self.type) +
            struct.pack("!B", self.flags) +
            struct.pack("!L", (self.r << 31) | self.stream_id) +
            self.payload
        )
        
        return bytes

def create_data_frame(stream_id, payload, flags=0):
    if len(payload) > Frame.max_payload_size: # 2^24-1
        raise "payload can't larger than 2^24-1"
    return Frame(length=len(payload), type=0, flags=flags, stream_id=stream_id, payload=payload)

def create_headers_frame(stream_id, payload, flags=False):
    if len(payload) > Frame.max_payload_size: # 2^24-1
        raise "payload can't larger than 2^24-1"
    return Frame(length=len(payload), type=1, flags=flags, stream_id=stream_id, payload=payload)

def bytes_to_frame(data):
    length_type, = struct.unpack(f"!L", data[:4])
    length = length_type >> 8
    type, flags, r_stream_id, payload = struct.unpack(f"!BBL{length}s", data[3:])
    return Frame(length=length, type=type, flags=flags, r=r_stream_id>>31, stream_id=r_stream_id&((1<<31)-1), payload=payload)

def bytes_to_frames(data):
    # Parse bytes and return frames and remain bytes that can't be parsed as a frame
    frames = []
    remain_bytes = b""
    while len(data) > 0:
        # TODO: Try to unpack a 32-bit value from data that includes both the length and type.
        length_type = struct.unpack("!L", data[:4])[0]

        # TODO: Use the right shift operator >> to extract the length from the 32-bit value.
        length = length_type >> 8
        
        # TODO: Check data has enough length to be parsed.
        # Hint: The frame header has 9 bytes, and the payload has 'length' bytes
        if len(data) >= 9+length:
        
            # TODO: Parse type, flags, r_stream_id, payload from data
            type = length_type & 0xFF
            flags, r_stream_id, payload = struct.unpack(f"!BL{length}s", data[4:9+length])

            frame = Frame(length=length, type=type, flags=flags, r=r_stream_id>>31, stream_id=r_stream_id&((1<<31)-1), payload=payload)
            frames.append(frame)
            data = data[9+length:]
        else:
            break
    remain_bytes = data
    return frames, remain_bytes

if __name__ == "__main__":
    f1 = create_headers_frame(1, "aaa".encode())
    f2 = create_headers_frame(1, "bbb".encode())
    fs, bytes = bytes_to_frames(f1.to_bytes()+f2.to_bytes())
    for f in fs:
        print(f.payload)