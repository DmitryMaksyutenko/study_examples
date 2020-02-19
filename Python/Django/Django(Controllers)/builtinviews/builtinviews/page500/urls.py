from django.conf import settings
from django.urls import path

from . views import get_500_page

app_name = "page500"

if settings.DEBUG:
    urlpatterns = [
        path("page500", get_500_page, name="get_500_page"),
    ]
