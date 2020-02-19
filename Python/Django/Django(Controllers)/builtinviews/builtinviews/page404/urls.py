from django.conf import settings
from django.urls import path

from . views import get_404_page

app_name = "page404"

if settings.DEBUG:
    urlpatterns = [
        path("404page", get_404_page, name="get_404_page"),
    ]
