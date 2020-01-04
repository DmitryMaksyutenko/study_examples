from django.shortcuts import render
from . models import City, Countrylanguage, Country


def get_index(request):
    return render(request, 'URLnamespaces/index.html')


def get_cities(request):
    context = City.objects.all()
    return render(request, 'URLnamespaces/cities.html', {'context': context})


def get_languages(request):
    context = Countrylanguage.objects.all()
    return render(request, 'URLnamespaces/languages.html',
                  {'context': context})


def get_countries(request):
    context = Country.objects.all()
    return render(request, 'URLnamespaces/countries.html',
                  {'context': context})
