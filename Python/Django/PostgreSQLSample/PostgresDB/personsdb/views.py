from django.shortcuts import render

# Create your views here.

def index(request):
    """Returns index page."""
    return render(request, 'personsdb/index.html')

def addInfo(request):
    """Returns the page of insertion of data."""
    return render(request, 'personsdb/addInfo.html')

def getInfo(request):
    """Returns the page of adding the information."""
    return render(request, 'personsdb/getInfo.html')