from django.urls import path

from . views import get_gone

app_name = "gone"

urlpatterns = [
    path("gone", get_gone, name="gone_page")
]
