from http_request import (
    parse_cmd,
    split_address,
    create_http_query
)


def test_get_addres_from_cmd(monkeypatch):
    host = "tst.com"
    method = "GET"
    monkeypatch.setattr("sys.argv", ["file", host, method])
    data_host, data_method = parse_cmd()

    assert isinstance(parse_cmd(), tuple)
    assert data_host == host
    assert data_method == method


def test_split_addres():
    domain = "some.com"
    resource_path = "/test/path/page.html"
    res = split_address(domain + resource_path)
    dom, path = res

    assert isinstance(res, tuple)
    assert dom == domain
    assert path == resource_path


def test_create_http_query():
    method = "GET"
    path = "/tst/path/index.html"
    test_query = bytes(method + " " + path + " HTTP/1.1\n\n", "ascii")
    http_query = create_http_query(method, path)

    assert isinstance(http_query, bytes)
    assert http_query == test_query
