from django.urls import path

from . views import get_forbiddedn

app_name = "forbidden"

urlpatterns = [
    path("forbidden", get_forbiddedn, name="forbidden_page")
]
