from django.urls import path

from . views import get_server_error

app_name = "server_error"

urlpatterns = [
    path("servet-error", get_server_error, name="server_error_page")
]
