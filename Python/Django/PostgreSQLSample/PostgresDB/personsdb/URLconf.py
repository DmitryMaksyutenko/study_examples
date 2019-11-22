from django.urls import path

from . views import index, addInfo, GetInfo

urlpatterns = [
    path('index', index),
    path('addinfo', addInfo),
    path('getinfo', GetInfo.as_view(), name='data-from-db')
]