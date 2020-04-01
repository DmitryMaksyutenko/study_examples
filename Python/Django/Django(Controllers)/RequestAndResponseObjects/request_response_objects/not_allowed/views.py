from django.http import HttpResponseNotAllowed

def get_not_allowed(request):
    """Return 405."""
    return HttpResponseNotAllowed("<p>405</p>")