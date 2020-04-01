from django.urls import path

from . views import get_response

app_name = "response_object"

urlpatterns = [
    path("response", get_response, name="response_page")
]
