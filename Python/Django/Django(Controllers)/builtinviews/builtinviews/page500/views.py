from django.views.defaults import server_error


# In case of runtime errors in view code. If a view results in an exception, Django will, by default,
# call the view django.views.defaults.server_error
#
# The default 500 view passes no variables to the 500.html template and is rendered with an empty Context
#
def get_500_page(request):
    '''Controller render the 500 error page.'''
    return server_error(request, "../templates/page500/500.html")
