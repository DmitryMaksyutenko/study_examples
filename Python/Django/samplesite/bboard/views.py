from django.http import HttpResponse

def index(request):
    """Start page function"""
    return HttpResponse("Здесь будет выведен список объявлений.")
