from django.http import HttpResponseForbidden

def get_forbiddedn(request):
    """Return 403."""
    return HttpResponseForbidden("<p>403</p>")