from django.shortcuts import render
from django.views.decorators.http import require_http_methods, require_GET,\
                                         require_safe, require_POST, condition
from django.views.decorators.gzip import gzip_page
from django.views.decorators.vary import vary_on_headers
from django.views.decorators.cache import never_cache, cache_control

from . forms import PostForm, GetForm
from . models import Person


###############################################################################
# The decorators in django.views.decorators.http can be used to restrict access
# to views based on the request method. These decorators will return
# a django.http.HttpResponseNotAllowed if the conditions are not met.
#
# Decorator to require that a view only accepts particular request methods.
@require_http_methods(["POST", "GET"])
def get_index(request):
    """Main page view."""
    return render(request, "decorators/index.html", {})


# Decorator to require that a view only accepts the GET method.
@require_GET
def get_get_page(request):
    """View with @require_GET decorator."""
    data = request.headers
    return render(request, "decorators/get.html", {"context": data})


###############################################################################
# Decorator to require that a view only accepts the GET and HEAD methods.
# These methods are commonly considered “safe” because they should not
# have the significance of taking an action other than retrieving the
# requested resource.
@require_safe
def get_safe(request):
    """View with @require_safe decorator."""
    return render(request, "decorators/safe.html", {"context": request.META})


###############################################################################
# Decorator to require that a view only accepts the POST method.
@require_POST
def get_post(request):
    """View with @require_POST decorator."""
    form = PostForm(request.POST)
    if form.is_valid:
        form.save()

    return render(request, "decorators/post.html", {"context": form})


def get_form(request):
    """The function for form rendering."""
    form = PostForm()
    return render(request, "decorators/postForm.html", {"form": form})


###############################################################################
# The decorators in django.views.decorators.gzip control content compression on
# a per-view basis.
#
# This decorator compresses content if the browser allows gzip compression.
@gzip_page
def get_gzip(request):
    """Function makes compression."""
    return render(request, "decorators/gzip.html",
                  {"context": request.headers})


###############################################################################
# For each page (response) that Django sends back from a view, it might provide
# two HTTP headers: the ETag header and the Last-Modified header.
# These headers are optional on HTTP responses. They can be set by your view
# function, or you can rely on the ConditionalGetMiddleware middleware to set
# the ETag header.
#
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# As a general rule, if you can provide functions to compute both the ETag and
# the last modified time, you should do so. You don’t know which headers any
# given HTTP client will send you, so be prepared to handle both.
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#
def set_etag(request):
    return "testETag"


# The decorator sets the ETag and Last-Modified headers on the response if
# they are not already set by the view and if the request’s method is
# safe (GET or HEAD)
#
@condition(etag_func=set_etag)
def get_name_form(request):
    """The conditional processing function."""
    form = GetForm()
    response = render(request, "decorators/getNameForm.html", {"form": form})
    return response


###############################################################################
# The decorators in django.views.decorators.vary can be used to control caching
# based on specific request headers.
#
# The Vary header defines which request headers a cache mechanism should take
# into account when building its cache key.
#
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# Don't use it if every time sent same result or used adapted design.
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
@vary_on_headers("User-Agent")
def conditional_processing(request):
    form = GetForm(request.POST)
    result = None

    if form.is_valid():
        result = Person.objects.get(name=form.data["name"])

    return render(request, "decorators/showDataPage.html", {"context": result})


###############################################################################
# The decorators in django.views.decorators.cache control server and
# client-side caching.
#
# The never_cache() decorator adds a Cache-Control: max-age=0, no-cache,
# no-store, must-revalidate, private header to a response to indicate that
# a page should never be cached.
#
@never_cache
def get_not_cacheable_page(request):
    """This view function returns the never cacheable page."""
    response = request.headers
    return render(request, "decorators/notCahablePage.html",
                  {"context": response})


# The "Cache-Control" header field is used to specify directives for
# caches along the request/response chain.
# A cache MUST obey the requirements of the Cache-Control directives.
#
# The cache_control() decorator patches the response’s Cache-Control
# header by adding all of the keyword arguments to it.
#
@cache_control(private=True, no_cache=True, max_age=3600)
def get_cache_control(request):
    response = request.headers
    return render(request, "decorators/cacheControl.html",
                  {"context": response})
