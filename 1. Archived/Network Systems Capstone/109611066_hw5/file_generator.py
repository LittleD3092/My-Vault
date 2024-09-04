import os
import random
import math
from pathlib import Path
if __name__ == "__main__":
    for i in range(10):
        with open(f"./static/file_{str(i).zfill(2)}.txt", "wb") as f:
            num = math.floor(random.random()*1000000000)
            bytes_to_write = (str(num).zfill(9)+"\r\n").encode()
            for j in range(100000):
                f.write(bytes_to_write)
