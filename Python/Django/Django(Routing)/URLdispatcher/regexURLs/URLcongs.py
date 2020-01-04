from django.urls import path, re_path
from .views import index_page, get_city, get_country, get_language
from .views import get_all_info

urlpatterns = [
    path('', index_page, name='index-page'),
    re_path(r'[a-z]+$', get_all_info, name='get-all-info'),
    re_path(r'^city/(?P<val>[0-9]+)$', get_city, name='get-city'),
    re_path(r'^country/(?P<val>[a-zA-Z]+)$', get_country, name='get-country'),
    re_path(r'^language/(?P<val>[a-zA-Z]+)$', get_language,
            name='get-language'),
]

# Each regular expression in a urlpatterns is compiled the first time it’s
# accessed. This makes the system blazingly fast.

# re_path(route, view, kwargs=None, name=None) - Returns an element for
# inclusion in urlpatterns.
# route - is a string or gettext_lazy() that contains regular expression.
# view, kwargs, name - the same as for path().

# In Python regular expressions, the syntax for named regular expression groups
# is (?P<name>pattern), where name is the name of the group and pattern is some
# pattern to match.
