from django.urls import path

from . views import root_path

app_name = "Core"

urlpatterns = [path("", root_path)]
