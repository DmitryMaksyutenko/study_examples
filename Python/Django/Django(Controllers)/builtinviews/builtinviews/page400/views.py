from django.views.defaults import bad_request
from django.core.exceptions import SuspiciousOperation


# When a SuspiciousOperation is raised Django calls the django.core.exceptions.bad_request
#
# By default, nothing related to the exception that triggered the view is passed to the template context
#
def get_400_page(request):
    return bad_request(request, SuspiciousOperation("error 400"),
                       "../templates/page400/400.html")
