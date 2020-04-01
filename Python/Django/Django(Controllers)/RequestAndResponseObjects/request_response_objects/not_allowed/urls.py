from django.urls import path

from . views import get_not_allowed

app_name = "not_allowed"

urlpatterns = [
    path("not-allowed", get_not_allowed, name="not_allowed_page")
]
