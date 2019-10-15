"""Server module."""
import socket


def send_data(socket, msg):
    """A better way to send data."""
    total_sent = 0
    while total_sent < len(msg):

        sent = socket.send(msg[total_sent:])
        if sent == 0:
            raise RuntimeError("broken")
        total_sent = total_sent + sent

def server():
    """Server socket."""
    soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    soc.bind(('127.0.0.1', 1234))
    soc.listen(10)

    while True:
        conn, addr = soc.accept()

        while True:
            data = conn.recv(10)
            if not data: break
            data += b" from server"
            send_data(conn, data)
        conn.close()

def main():
    """Entry point."""
    server()
    client()


if __name__ == "__main__":
    main()

