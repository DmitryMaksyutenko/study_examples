import socket

server = socket.socket(
    socket.AF_INET,
    socket.SOCK_STREAM
)

server.bind(("localhost", 8080))
server.listen(1)
connection, peer_addr = server.accept()

with connection:
    print(f"connection from : {peer_addr}")
    size = 0
    while True:
        data = connection.recv(1024)
        size += len(data)
        if not data:
            break
        print(data)
        connection.send(b"Recieved " + bytes(str(size), "ascii"))

server.close()
