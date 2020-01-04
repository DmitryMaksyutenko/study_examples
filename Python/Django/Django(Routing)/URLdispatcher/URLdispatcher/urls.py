"""URLdispatcher URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/2.2/topics/http/urls/
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

# from simpleURLs import URLconfs

# This value is a list of path patterns. Django searches it,
# for runs through all elements.
# If Django finds any match, imports and calls the given view.
urlpatterns = [
    path('admin/', admin.site.urls),

    # path('', URLconfs.views.index, name="index-page"),
    # path('cities', URLconfs.views.get_cities, name="cities-page"),
    # path('countries', URLconfs.views.get_countty, name="countries-page"),
    # path('languages', URLconfs.views.get_languages, name="languages-page"),
    # path('city/<int:num>', URLconfs.views.get_city, name="city-page"),
    # path('country/<val>', URLconfs.views.get_country, name="country-page"),
    # path('language/<val>', URLconfs.views.get_language, name="language-page")
    # path('', include('simpleURLs.URLconfs'))

    # path('', include('regexURLs.URLcongs'))

    path('', include('URLnamespaces.URLconfs', namespace='urlnamespaces'))
]

# path(route, view, kwargs=None, name=None)
# Returns an element for inclusion in urlpatterns.
# route - a string that contains a URL
# view - a view function or a class-based as_view() method.
# kwargs - additional arguments passed into view.
# name - named URL pattern, used for refer to the view by that name.

# include(module, namespace=None)
# include(pattern_list)
# include((pattern_list, app_namespace), namespace=None)
# A function that takes a full Python import path
# to another URLconf module that should bee included in this space.
