from django.shortcuts import render


def request_object(request):
    """Return main page of the request_object application."""
    context_dict = {}

    a_dict = {}  # attributes dictionary.
    m_dict = {}  # methods dictionary.

    # Attributes.
    a_dict["object_name"] = "HttpRequest"
    a_dict["scheme"] = request.scheme
    a_dict["body"] = request.body
    a_dict["path"] = request.path
    a_dict["path_info"] = request.path_info
    a_dict["method"] = request.method
    a_dict["encoding"] = request.encoding
    a_dict["content_type"] = request.content_type
    a_dict["content_params"] = request.content_params
    a_dict["GET"] = request.GET
    a_dict["POST"] = request.POST
    a_dict["COOKIES"] = request.COOKIES
    a_dict["FILES"] = request.FILES
    a_dict["META"] = request.META
    a_dict["resolver_match"] = request.resolver_match

    # Attributes set by application.
    request.current_app = "request_object"
    a_dict["current_app"] = request.current_app

    # Attributes set by Middleware.
    a_dict["session"] = request.session
    a_dict["user"] = request.user

    # Methods.
    m_dict["get_host()"] = request.get_host()
    m_dict["get_port()"] = request.get_port()
    m_dict["get_full_paht()"] = request.get_full_path()
    m_dict["get_full_path_info()"] = request.get_full_path_info()
    m_dict["build_absolute_uri()"] = request.build_absolute_uri()
    m_dict["get_signed_cookie()"] = request.get_signed_cookie("csrftoken",
                                                              False)
    m_dict["is_secure()"] = request.is_secure()
    m_dict["is_ajax()"] = request.is_ajax()
    m_dict["read()"] = request.read()
    m_dict["readline()"] = request.readline()
    m_dict["readlines()"] = request.readlines()
    m_dict["__iter__()"] = request.__iter__()

    context_dict["context_a"] = a_dict
    context_dict["context_m"] = m_dict

    return render(request, "request_object/request.html", context_dict)
