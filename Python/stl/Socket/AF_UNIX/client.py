import pathlib
import sys
import socket


def get_data_from_cmd():
    if len(sys.argv) == 3:
        path = bytes(sys.argv[1], "utf-8")
        peer = bytes(sys.argv[2], "utf-8")
    else:
        raise ValueError
    return (path, peer)


def sending(sock):
    data_list = []
    while True:
        data = input()
        data_list.append(bytes(data, "utf-8"))
        if not data:
            break
    sock.send(b"\n".join(data_list))


if __name__ == "__main__":
    try:
        path, peer = get_data_from_cmd()
        client = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
        client.bind(path)
        client.connect(peer)
        sending(client)
        client.close()
        pathlib.Path(str(path, "utf-8")).unlink()
    except ValueError:
        print("Enter name for client socket and peer addres.")
    except OSError:
        print("File exists.")
