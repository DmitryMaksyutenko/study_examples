"""Client module."""
import socket


def data_receive(socket, msg_len):
    """A better way to receive data from the socket."""
    msg = "" # buffer
    while len(msg) < msg_len:
        chunk = socket.recv(msg_len - len(msg))
        print(chunk)
        if chunk == b"":
            raise RuntimeError("broken")
        msg = msg + str(chunk)

    return msg

def client():
    """Client socket."""
    req_str = b"Hello tcp!"
    soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    soc.connect(('127.0.0.1', 1234))
    soc.send(req_str)
    response = data_receive(soc, 100)
    soc.close()

    print(response)

def main():
    """Entry point."""
    client()


if __name__ == "__main__":
    main()
