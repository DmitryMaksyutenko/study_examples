from django.conf import settings
from django.urls import path

from . views import (get_image, get_text)

app_name = "staticserve"

if settings.DEBUG:
    urlpatterns = [
        path("image", get_image, name="get_image_page"),
        path("text", get_text, name="get_text_page"),
    ]
