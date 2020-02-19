from django.views.defaults import permission_denied
from django.core.exceptions import PermissionDenied


# Django has a view to handle 403 Forbidden errors. If a view results in a 403 exception
# then Django will, by default, call the view django.views.defaults.permission_denied.
#
# django.views.defaults.permission_denied is triggered by a PermissionDenied exception.
#
# The template context contains exception, which is the string representation
# of the exception that triggered the view.
#
def get_403_page(request):
    '''Controller returns the 403 error.'''
    return permission_denied(request, PermissionDenied("error 403"),
                             "../templates/page403/403.html", )
