# The django.shortcuts collects helper functions and classes
# for controled coupling.
from django.shortcuts import render, redirect, get_object_or_404
from django.shortcuts import get_list_or_404
from . models import City


###############################################################################
# The render() function combines a given template with
# a given context dictionary and returns an HttpResponse.
#
# render(request, template_name, context=None, content_type=None
#        status=None, using=None)
#
# request - The request object used to generate response.
# template_name - The full name of a template to use.
# context - A dictionary of values to add to the template context.
# content_type - The MIME type of the request document.
# status - The statys type of the response. Deafaul 200.
# using - The NAME of the template engine to use for loading the template.
#
def get_index(request):
    context = "This page returned by 'render' function from 'django.shortcuts'"
    return render(request, "shortcuts/index.html", {"context": context})
###############################################################################


###############################################################################
# The redirect() function returns an HttpResponseRedirect to the appropriate
# URL for the arguments passed.
#
# redirect(to, *args, permanenent=False, **kwargs)
#
# The argument could be:
# A model: the model's get_absolute_url() function will be called.
# A view name, possibly with arguments: reverse() will be used to
# reverse-resolve the name.
# An absolute or relative URL, witch will be used as-is for the redirect
# location
#
def get_redirect(request):
    return redirect("http://google.com")
###############################################################################


###############################################################################
# get_obgect_or_404() function call get() on a given model manager, bu it
# raises Http404 insted of the model's DoesNotExists exception.
#
# get_object_or_404(class, *args, **kwargs)
#
# class - a model or QuerySet from which to get the object.
# **kwargs - lookup parameters, which should be in the format accepted by get()
# and filter()
#
def get_city(request, value):
    city = get_object_or_404(City, id=value)
    return render(request, "shortcuts/city.html", {"context": city})
###############################################################################


###############################################################################
# get_list_or_404() function returns the result of filter() on a given manager
# cast to a list, raisisng Http404 if the resulting list is empty.
#
# get_list_or_404(class, *args, **kwargs)
#
# class - a model or QuerySet from which to get the list.
# **kwargs - lookup parameters, which should be in the format accepted by get()
# and filter()
#
def get_cities(request):
    cities = get_list_or_404(City)
    return render(request, "shortcuts/cities.html", {"context": cities})
###############################################################################
