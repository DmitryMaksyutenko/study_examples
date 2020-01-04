from django.shortcuts import render, get_object_or_404, get_list_or_404
from . models import City, Country, Countrylanguage


def index(request):
    return render(request, 'simpleURLs/index.html')


def get_cities(request):
    data = City.objects.all()
    return render(request, 'simpleURLs/cities.html', {'data': data})


def get_countty(request):
    data = Country.objects.all()
    return render(request, 'simpleURLs/countries.html', {'data': data})


def get_languages(request):
    data = Countrylanguage.objects.all()
    return render(request, 'simpleURLs/languages.html', {'data': data})


def get_city(request, num):
    return render(request, 'simpleURLs/city.html',
                  {'data': get_object_or_404(City, pk=num)})


def get_country(request, val):
    return render(request, 'simpleURLs/country.html',
                  {'data': get_object_or_404(Country, code=val)})


def get_language(request, val):
    if Countrylanguage.objects.filter(countrycode=val).count() > 1:
        return render(request, 'simpleURLs/language.html',
                      {'data':
                       get_list_or_404(Countrylanguage, countrycode=val)})
    else:
        return render(request, 'simpleURLs/language.html',
                      {'data':
                       get_object_or_404(Countrylanguage, countrycode=val)})
