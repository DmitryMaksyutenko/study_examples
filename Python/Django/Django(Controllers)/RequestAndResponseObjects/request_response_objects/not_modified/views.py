from django.http import HttpResponseNotModified


def get_not_modified(request):
    """Page not modified."""
    return HttpResponseNotModified()