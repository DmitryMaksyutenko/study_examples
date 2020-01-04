from django.urls import path
from . import views


urlpatterns = [
    path('', views.index, name="index-page"),
    path('cities', views.get_cities, name="cities-page"),
    path('countries', views.get_countty, name="countries-page"),
    path('languages', views.get_languages, name="languages-page"),
    path('city/<int:num>', views.get_city, name="city-page"),
    path('country/<val>', views.get_country, name="country-page"),
    path('language/<val>', views.get_language, name="language-page")
]
