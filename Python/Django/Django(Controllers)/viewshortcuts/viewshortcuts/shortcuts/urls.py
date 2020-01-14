from django.urls import path, re_path
from . views import get_index, get_redirect, get_city, get_cities

app_name = "shortcuts"

urlpatterns = [
    path('', get_index, name="index-page"),
    re_path(r'^redirect$', get_redirect, name="redirect-page"),
    re_path(r'^city/(?P<value>[0-9]+)$', get_city, name="city-page"),
    re_path(r'^cities$', get_cities, name="cities-page"),
]
