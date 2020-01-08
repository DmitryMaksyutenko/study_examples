from django.http import HttpResponse, HttpResponseNotFound, Http404
from django.template import loader
from django.shortcuts import render

# Each view function takes an HttpRequest object as its first parameter,
# which is typically named request.
# The view returns an HttpResponse object that contains the generated response.
# Each view function is responsible for returning an HttpResponse object.


def get_index(request):
    # Loads templates from a given source,
    # such as the filesystem or a database.
    page = loader.get_template("viewtests/index.html")
    return HttpResponse(page.render())
    # return render(request, "viewtests/index.html", {})


def get_not_found(request):
    return HttpResponseNotFound("<p>HttpResponseNotFound</p>")


def get_404(request):
    raise Http404("ERROR")


def get_custom_404(request, exception):
    # response = loader.get_template("viewtests/404.html")
    # return HttpResponseNotFound(response.render())
    return render(request, "viewtests/404.html", {})
