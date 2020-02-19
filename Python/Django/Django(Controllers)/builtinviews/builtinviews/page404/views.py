from django.views.defaults import page_not_found


# When rises Http404 from within a view, Django loads aspecial view
# by calling this function.
#
# The default view will pass two variables to the template:
#
# request_path = the URL whith error page.
# exception = a useful representstion of the exception Exception object.
#
# ----------------------------------------------------------------------------
# -The 404 will alse called if Django doesn't find a match agter checking
# every regular expression in the URLconf.
#
# -The 404 view is passed a RequestContext and will have access to variables
# supplied by context processor.
#
# -If Debug is set True, then 404 view will never be used.
# ----------------------------------------------------------------------------
#
def get_404_page(request):
    '''Controller returns the 404 page.'''
    return page_not_found(request, Exception("Exception!"),
                          template_name="../templates/page404/404.html")
