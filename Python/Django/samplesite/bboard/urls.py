from django.urls import path
from . import views
from . views import DbCreateView

urlpatterns = [
    path('add/', DbCreateView.as_view(), name='add'),
    path('<int:rubric_id>/', views.by_rubric, name='by_rubric'),
    path('', views.index, name='index'),
]