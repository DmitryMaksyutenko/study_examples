from .forms import GetInfoForm
from django.shortcuts import render, get_object_or_404
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
    context_object_name = 'object'

    def get_object(self, queryset=None):
        obj = self.request.GET['name']
        return get_object_or_404(Persons, name=obj)
