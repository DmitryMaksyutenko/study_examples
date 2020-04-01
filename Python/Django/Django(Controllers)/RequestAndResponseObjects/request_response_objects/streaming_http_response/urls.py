# -*- coding: utf-8 -*-
from django.urls import path

from . views import get_streaming_response

app_name = "streaming_http_response"

urlpatterns = [
    path("streaming-response", get_streaming_response,
         name="streaming_response_page")
]
