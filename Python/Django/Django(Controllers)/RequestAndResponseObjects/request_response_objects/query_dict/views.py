from django.shortcuts import render


def get_query_dict(request):
    """Return the QueryDict information."""

    context = dict()
    get_copy = request.GET.copy()

    # Methods:
    m_dict = dict()
    m_dict["__setitem__(key, value)"] = get_copy.__setitem__("a", "a value")
    m_dict["__getitem__(key)"] = get_copy.__getitem__("a")
    m_dict["__contains__(key)"] = get_copy.__contains__("a")
    m_dict["get(key, default=None)"] = get_copy.get("b", default="No key")
    m_dict["setdefault(key, default=None)"] = get_copy.setdefault("b",
                                              "b value") # noqa
    m_dict["update(other_dict)"] = get_copy.update({"a": "new a value"})
    m_dict["items()"] = list(get_copy.items())
    m_dict["values()"] = list(get_copy.values())
    m_dict["copy()"] = get_copy.copy()
    m_dict["getlist(key, default=None)"] = get_copy.getlist("a")
    m_dict["setlist(key, list_)"] = get_copy.setlist("b", [
        "first",
        "second",
        "third"
        ])
    m_dict["new b"] = get_copy.getlist("b")
    m_dict["appendlist(key, item)"] = get_copy.appendlist("a", "third value")
    m_dict["a list after appending"] = get_copy.getlist("a")
    m_dict["setlistdefault(key, default_list=None)"] = \
        get_copy.setlistdefault("c", default_list=["c value"])
    m_dict["lists()"] = list(get_copy.lists())
    m_dict["pop(key)"] = get_copy.pop("a")
    m_dict["after pop(key)"] = list(get_copy.lists())
    m_dict["popitem()"] = get_copy.popitem()
    m_dict["dict()"] = get_copy.dict()
    m_dict["urlencode()"] = get_copy.urlencode()

    context["m_dict"] = m_dict

    return render(request, "query_dict/qdict.html", context)
