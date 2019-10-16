from django.shortcuts import render
from . models import City, Countrylanguage, Country

# Create your views here.
def index_page(request):
    """Functin return main page"""
    title = 'Form'
    city = City.objects.all()
    country = Country.objects.all()
    country_language = Countrylanguage.objects.all()
    context = {'title': title,
                'city': city,
                'country': country,
                'country_language': country_language,
            }
    return render(request, 'index.html', context)