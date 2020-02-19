from django.conf import settings
from django.urls import path

from . views import get_403_page

app_name = "page403"

if settings.DEBUG:
    urlpatterns = [
        path("page403", get_403_page, name="get_403_page"),
    ]
