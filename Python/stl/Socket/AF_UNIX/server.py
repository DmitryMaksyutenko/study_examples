import pathlib
import sys
import socket


def get_data_from_cmd():
    if len(sys.argv) == 2:
        path = bytes(sys.argv[1], "utf-8")
    else:
        path = b"/Sockets/default_socket"

    return path


def show_server_info(server):
    print(server.getsockname())
    print(server.family)


def connection_loop(con):
    res = bytearray()
    while True:
        data = con.recv(1024)
        res += data
        if not data:
            break
    return bytes(res)


if __name__ == "__main__":
    path = get_data_from_cmd()
    try:
        server = socket.create_server(path, family=socket.AF_UNIX)
        show_server_info(server)
        server.listen(1)
        con, peer = server.accept()
        print(f"{peer} connected.")
        data = connection_loop(con)
        print(f"received from {peer}: ", data)
        server.close()
        pathlib.Path(str(path, "utf-8")).unlink()
    except OSError:
        print("File exists.")
