import socket

client = socket.socket(
    socket.AF_INET,
    socket.SOCK_STREAM
)

client.connect(("localhost", 8080))

client.sendall(b"Hello World!")
data = client.recv(1024)

client.close()

print(f"Received: {data}")