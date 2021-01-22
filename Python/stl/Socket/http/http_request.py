import socket
import pprint
import sys


def parse_cmd():
    if len(sys.argv) == 3:
        return (sys.argv[1], sys.argv[2])
    else:
        print("python http_request.py 'host' 'method'")


def split_address(addr):
    if "/" in addr:
        index = addr.find("/")
        return (addr[:index], addr[index:])
    else:
        return (addr, "")


def create_http_query(*args):
    method, path = args
    if path == "":
        path = "/"
    return bytes(method + " " + path + " HTTP/1.1\n\n", "ascii")


def recv_all(conn):
    data = bytearray()
    while not data.endswith(b"\r\n"):
        try:
            data += conn.recv(4096)
        except InterruptedError:
            pass
    return str(data)


if __name__ == "__main__":
    addr, method = parse_cmd()
    domain, path = split_address(addr)
    connection = socket.create_connection((domain, 80), 2)
    http_query = create_http_query(method, path)
    connection.send(http_query)
    response = recv_all(connection)
    connection.close()
    pprint.pprint(response)
