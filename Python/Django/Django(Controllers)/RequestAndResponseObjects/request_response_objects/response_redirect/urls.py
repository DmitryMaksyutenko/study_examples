from django.urls import path

from . views import get_redirect

app_name = "response_redirect"

urlpatterns = [
    path("redirect", get_redirect, name="redirect_page")
]
