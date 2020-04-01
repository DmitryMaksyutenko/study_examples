from django.http import HttpResponseBadRequest


def get_bad_request(request):
    """Return bad request."""
    return HttpResponseBadRequest("<p>400</p>")