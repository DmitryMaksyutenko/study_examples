from django.shortcuts import render

# Create your views here.

def index(request):
    """Return index page."""
    return render(request, 'personsdb/index.html', {})