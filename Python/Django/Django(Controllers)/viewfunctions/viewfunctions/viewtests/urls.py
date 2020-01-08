from django.urls import path
from . views import get_index, get_not_found, get_404


urlpatterns = [
    path('', get_index, name="index-page"),
    path('not-found', get_not_found, name="not-found-page"),
    path('404', get_404, name="404-page")
]
