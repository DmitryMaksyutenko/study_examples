# -*- coding: utf-8 -*-
from django.urls import path

from . views import get_file_response

app_name = "file_response"

urlpatterns = [
    path("file-response", get_file_response, name="get_file_page")
]
