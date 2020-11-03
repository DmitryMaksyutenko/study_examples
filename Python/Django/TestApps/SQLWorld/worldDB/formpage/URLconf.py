from django.urls import path
from . views import index_page, db_table

urlpatterns = [
    path('index', index_page),
    path('table', db_table),
]