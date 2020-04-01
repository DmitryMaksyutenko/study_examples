from django.urls import path

from . views import get_permanent_redirect

app_name = "permanent_redirec"

urlpatterns = [
    path("permanent-redirect", get_permanent_redirect, name="permanent_redirect_page")
]
