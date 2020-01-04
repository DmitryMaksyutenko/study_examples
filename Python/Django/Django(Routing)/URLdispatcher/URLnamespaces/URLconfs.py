from django.urls import path
from . views import get_index, get_cities, get_languages, get_countries

# Set the application namespace attribute.
app_name = 'urlnamespaces'

urlpatterns = [
    path('', get_index, name="index-page"),
    path('cities', get_cities, name="cities-page"),
    path('languages', get_languages, name="languages-page"),
    path('countries', get_countries, name="countries-page"),
]
