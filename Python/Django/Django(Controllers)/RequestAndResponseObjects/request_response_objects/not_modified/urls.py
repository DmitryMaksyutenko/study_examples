from django.urls import path

from . views import get_not_modified

app_name = "not_modified"

urlpatterns = [
    path("not-modified", get_not_modified, name="not_modified_page")
]
