from django.shortcuts import render, get_object_or_404, get_list_or_404
from . models import City, Country, Countrylanguage


def index_page(request):
    return render(request, 'regexURLs/index.html', {})


def get_all_info(request):

    content = None
    name = None
    data = None

    if(request.path == '/cities'):
        content = City.objects.all()
        name = "Cities"
        data = {'content': content,
                'name': name}
    if(request.path == '/countries'):
        content = Country.objects.all()
        name = "Countries"
        data = {'content': content,
                'name': name}
    if(request.path == '/languages'):
        content = Countrylanguage.objects.all()
        name = "Languages"
        data = {'content': content,
                'name': name}

    return render(request, 'regexURLs/info.html', data)


def get_city(request, val):

    content = get_object_or_404(City, id=val)
    name = "City"
    data = {'content': content,
            'name': name}

    return render(request, 'regexURLs/city.html', data)


def get_country(request, val):

    content = get_object_or_404(Country, code=val)
    name = "Country"
    data = {'content': content,
            'name': name}

    return render(request, 'regexURLs/country.html', data)


def get_language(request, val):

    name = "Language"

    if Countrylanguage.objects.filter(countrycode=val).count() > 1:
        data = {'content': get_list_or_404(Countrylanguage, countrycode=val),
                'name': name}
        return render(request, 'regexURLs/language.html', data)
    else:
        data = {'content': get_object_or_404(Countrylanguage, countrycode=val),
                'name': name}
        return render(request, 'regexURLs/language.html', data)
