from django.urls import path

from . views import get_bad_request

app_name = "bad_request"

urlpatterns = [
    path("bad-request", get_bad_request, name="bad_request_page")
]
