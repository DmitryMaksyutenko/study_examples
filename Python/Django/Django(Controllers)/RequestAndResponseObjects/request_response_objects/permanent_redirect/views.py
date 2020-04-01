from django.http import HttpResponsePermanentRedirect


def get_permanent_redirect(request):
    """Make permanent redirect to the django page."""
    return HttpResponsePermanentRedirect("https://www.djangoproject.com")