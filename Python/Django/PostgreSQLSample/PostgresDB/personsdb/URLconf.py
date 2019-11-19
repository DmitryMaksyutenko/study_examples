from django.urls import path

from . views import index, addInfo, getInfo

urlpatterns = [
    path('index', index),
    path('addinfo', addInfo),
    path('getinfo', getInfo)
]