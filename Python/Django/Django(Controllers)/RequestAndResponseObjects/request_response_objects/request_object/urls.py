from django.urls import path

from . views import request_object

app_name = "request_object"

urlpatterns = [
    path("request", request_object, name="request_object")
]
