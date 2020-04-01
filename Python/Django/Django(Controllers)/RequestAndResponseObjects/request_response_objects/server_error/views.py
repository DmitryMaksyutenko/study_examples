from django.http import HttpResponseServerError


def get_server_error(request):
    """Return 500."""
    return HttpResponseServerError("<p>500</p>")
