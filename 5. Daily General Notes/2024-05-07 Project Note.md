# 1. Target

Current version has a timestamp option in the TCP packet:

![[Pasted image 20240507161931.png]]

Today's target is to disable the timestamp in the TCP options field.

# 2. Modifications Made

## 2.1. Use libc with setsockopt

According to chatgpt (<u>1</u>), we can use `libc.setsockopt` to disable the option:

```python
import socket
import ctypes

# Define the TCP constants
TCP_OPT_TIMESTAMP = 8

# Create a TCP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Access low-level system functions using ctypes
libc = ctypes.CDLL('libc.so.6')

# Attempt to disable TCP timestamps on the socket
result = libc.setsockopt(sock.fileno(), socket.IPPROTO_TCP, TCP_OPT_TIMESTAMP, ctypes.byref(ctypes.c_int(0)))

if result == -1:
    # If setsockopt fails, print the error code
    print("Error:", ctypes.get_errno())
```

However, in the 3 hosts, it seems that only one host has no issues. Other hosts that have issues print their error:

![[Pasted image 20240507162417.png]]

## 2.2. Use socket.setsockopt

Since `libc.setsockopt` is used, maybe a more higher level `socket.setsockopt` can be used.

It does not return any error, but no sign of disabling timestamp either.

## 2.3. Use SO_TIMESTAMP

According to the manual (<u>2, 3</u>), there is an option `SO_TIMESTAMP` that can be used to disable cmsg (not sure what this is) timestamp. Therefore I wrote:

```python
self.socket.setsockopt(socket.SOL_SOCKET, socket.SO_TIMESTAMP, 0)
```

for both sender and receiver.

The result is that module `socket` does not have a option `SO_TIMESTAMP`.

![[Pasted image 20240507164931.png]]

With previous experience, we can use `ctypes` to access `SO_TIMESTAMP`:

```python
import socket
import ctypes

# Define the socket constants
SOL_SOCKET = 1
SO_TIMESTAMP = 29

# Create a TCP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Access low-level system functions using ctypes
libc = ctypes.CDLL('libc.so.6')

# Attempt to disable SO_TIMESTAMP option on the socket
result = libc.setsockopt(sock.fileno(), SOL_SOCKET, SO_TIMESTAMP, ctypes.byref(ctypes.c_int(0)))

if result == -1:
    # If setsockopt fails, print the error code
    print("Error:", ctypes.get_errno())
```

It does not work, so I think the cmsgs timestamp is different than TCP timestamp.

## 2.4. sysctl

According to a document from VMWare (<u>4</u>), we can use `sysctl` to disable TCP timestamp response.

```sh
sysctl -w net.ipv4.tcp_timestamps=0
```

It works.

# 3. Reference

1. ChatGPT. “Disable TCP Options Python.” Accessed May 7, 2024. https://chat.openai.com.
2. “Setsockopt(2): Get/Set Options on Sockets - Linux Man Page.” Accessed May 7, 2024. https://linux.die.net/man/2/setsockopt.
3. “Socket(7): Socket Interface - Linux Man Page.” Accessed May 7, 2024. https://linux.die.net/man/7/socket.
4. “Deactivate the TCP Timestamp Response on Linux.” Accessed May 7, 2024. https://docs.vmware.com/en/vRealize-Operations/8.10/com.vmware.vcom.scg.doc/GUID-DAC867BC-8C5F-4A5E-BB55-36FC25555696.html.