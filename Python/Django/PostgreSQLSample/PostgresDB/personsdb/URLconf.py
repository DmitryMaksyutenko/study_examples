from django.urls import path

from . views import index, addInfo, GetInfo, ShowInfo

urlpatterns = [
    path('index', index),
    path('addinfo', addInfo),
    path('getinfo', GetInfo.as_view()),
    path('from-db', ShowInfo.as_view())
]
