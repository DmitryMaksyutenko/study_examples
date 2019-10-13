from django.shortcuts import render

from . models import City

# Create your views here.
def index_page(request):
    '''This function returns main page.'''
    title = "Cities"
    cities = City.objects.all()
    context = {'title': title, 'cities': cities}
    return render(request, 'index.html', context)
