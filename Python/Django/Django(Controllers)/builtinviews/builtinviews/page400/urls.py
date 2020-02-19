from django.urls import path
from django.conf import settings

from . views import get_400_page

app_name = "page400"

if settings.DEBUG:
    urlpatterns = [
        path("page400", get_400_page, name="get_400_page")
    ]
