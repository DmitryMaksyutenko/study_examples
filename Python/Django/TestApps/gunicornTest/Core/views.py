from django.http import HttpResponse


def root_path(request):
    return HttpResponse("<h1>Hello Gunicorn World!</h1>")
