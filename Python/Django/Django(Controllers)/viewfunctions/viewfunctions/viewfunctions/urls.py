"""viewfunctions URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/3.0/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path, include

urlpatterns = [
    path('', include("viewtests.urls")),
    path('admin/', admin.site.urls),
]

# --insecure option to force serving of static files with the staticfiles app
# even if the DEBUG setting is False. By using this you acknowledge the fact
# that it’s grossly inefficient and probably insecure. This is only
# intended for local development, should never be used in production and is
# only available if the staticfiles app is in your project’s INSTALLED_APPS
# setting.

# The default error view.
handler404 = "viewtests.views.get_custom_404"
