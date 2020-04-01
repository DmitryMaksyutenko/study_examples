from django.shortcuts import render
from django.http import HttpResponse


def get_response(request):
    """Return information about HttpResponse object."""

    a_dict = {}
    m_dict = {}
    context = {}
    response = HttpResponse()

    # Attributes:
    response.content = "some content"
    a_dict["content"] = response.content
    a_dict["charset"] = response.charset
    a_dict["status_code"] = response.status_code
    a_dict["reason_phrese"] = response.reason_phrase
    a_dict["streaming"] = response.streaming
    a_dict["closed"] = response.closed

    # Methods:
    m_dict["__setitem__(header, value)"] = response.__setitem__("test", "Test")
    m_dict["__getitem__(header)"] = response.__getitem__("test")
    m_dict["__delitem__(header)"] = response.__delitem__("test")
    m_dict["has_header(header)"] = response.has_header("test")
    m_dict["setdefault(headre, value)"] = response.setdefault("t", "test")
    m_dict["set_cookie(key, value='', max_age=None,\
            expres=None, path='/', domain=None,\
            secure=False, httponly=False,\
            samesite=None)"] = response.set_cookie("some", "foo")
    m_dict["set_signed_cookie(key, value='', max_age=None,\
            expres=None, path='/', domain=None,\
            secure=False, httponly=False,\
            samesite=None)"] = response.set_signed_cookie("foo", "foo")
    m_dict["delete_cookie(key, path='/', domain=None)"] =\
        response.delete_cookie("foo")
    m_dict["close()"] = response.close()
    m_dict["write(content)"] = response.write("<p>CONTENT</p>")
    m_dict["flush()"] = response.flush()
    m_dict["tell()"] = response.tell()
    m_dict["getvalue()"] = response.getvalue()
    m_dict["readable()"] = response.readable()
    m_dict["seekable()"] = response.seekable()
    m_dict["writable()"] = response.writable()
    m_dict["writelines(lines)"] = response.writelines([" one",
                                                       " two", " three"])
    m_dict["lines"] = response.getvalue()

    context["a_dict"] = a_dict
    context["m_dict"] = m_dict

    return render(request, "response_object/response.html", context)
