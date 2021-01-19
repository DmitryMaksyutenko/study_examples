import socket
import sys


def get_address_from_cmd():
    if len(sys.argv) == 3:
        return (sys.argv[1], sys.argv[2])
    else:
        print("python http_request.py 'host' 'method'")


def connect(host, port=80):
    return socket.create_connection((host, port), 2)


if __name__ == "__main__":
    addr, method = get_address_from_cmd()
    connection = connect(addr)

    http_query = bytes(method + " / HTTP/1.1\n\n", "ascii")

    connection.send(http_query)
    print(connection.recv(4098))
