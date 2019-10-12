from django.shortcuts import render

# Create your views here.
def index_page(request):
    '''This function returns main page.'''
    return render(request, 'index.html')