from django.http import HttpResponseGone


def get_gone(request):
    """Return 410"""
    return HttpResponseGone("<p>410</p>")
