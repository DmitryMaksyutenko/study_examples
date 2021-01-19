from socket import socket

from http_request import (
    get_address_from_cmd,
    connect
)


def test_get_addres_from_cmd(monkeypatch):
    host = "tst.com"
    method = "GET"
    monkeypatch.setattr("sys.argv", ["file", host, method])
    data_host, data_method = get_address_from_cmd()

    assert isinstance(get_address_from_cmd(), tuple)
    assert data_host == host
    assert data_method == method


def test_connection():
    host = "google.com"
    con = connect(host)

    assert isinstance(con, socket)
