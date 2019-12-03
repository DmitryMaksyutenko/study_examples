from .forms import GetInfoForm
from django.shortcuts import render, Http404
from django.views.generic.edit import FormView
from django.views.generic import DetailView
# from django.shortcuts import get_object_or_404
from .models import Persons


def index(request):
    """Returns index page."""
    return render(request, 'personsdb/index.html')


def addInfo(request):
    """Returns the page of insertion of data."""
    return render(request, 'personsdb/addInfo.html')


def getInfo(request):
    """Returns the page of adding the information."""
    return render(request, 'personsdb/getInfo.html')


class GetInfo(FormView):
    """Show form"""
    template_name = 'personsdb/getInfo.html'
    form_class = GetInfoForm
    model = Persons


class ShowInfo(DetailView):
    """Return the result"""
    model = Persons

    def get_object(self, queryset=None):
        if queryset is None:
            queryset = self.get_queryset()

        pk = self.kwargs.get(self.pk_url_kwarg)
        slug = self.kwargs.get(self.slug_url_kwarg)

        if pk is not None:
            queryset = queryset.filter(pk=pk)
        if slug is not None and (pk is None or self.query_pk_and_slug):
            slug_field = self.get_slug_field()
            queryset = queryset.filter(**{slug_field: slug})

        if pk is None and slug is None:
            raise AttributeError("Error from get_object() method")

        try:
            obj = queryset.get()
        except queryset.model.DoesNotExist:
            raise Http404()

        return obj
