from django.urls import path

from . views import get_query_dict

app_name = "query_dict"

urlpatterns = [
    path("qdict", get_query_dict, name="qdict_page")
]
