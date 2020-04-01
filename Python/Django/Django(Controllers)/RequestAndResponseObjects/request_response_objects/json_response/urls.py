# -*- coding: utf-8 -*-
from django.urls import path

from . views import get_json

app_name = "json_response"

urlpatterns = [
    path("json", get_json, name="json_page")
]
