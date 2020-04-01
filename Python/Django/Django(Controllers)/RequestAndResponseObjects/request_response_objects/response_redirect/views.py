from django.http import HttpResponseRedirect


def get_redirect(request):
    """Redirect to google page."""
    return HttpResponseRedirect("https://google.com")