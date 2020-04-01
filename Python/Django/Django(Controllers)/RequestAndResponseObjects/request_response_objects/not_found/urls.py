from django.urls import path

from . views import get_not_found

app_name = "not_found"

urlpatterns = [
    path("not-found", get_not_found, name="not_found_page")
]
