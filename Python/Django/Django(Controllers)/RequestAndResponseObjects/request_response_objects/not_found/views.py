from django.http import HttpResponseNotFound


def get_not_found(request):
    """Return 404."""
    return HttpResponseNotFound("<p>404</p>")