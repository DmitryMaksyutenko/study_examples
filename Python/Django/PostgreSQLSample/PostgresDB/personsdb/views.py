from .forms import GetInfoForm
from django.shortcuts import render
from django.views.generic.edit import FormView
from django.views.generic import ListView
#   from django.shortcuts import get_object_or_404
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
    """Returns the page of adding the information."""
    template_name = 'personsdb/getInfo.html'
    form_class = GetInfoForm
    success_url = 'getinfo'

    def form_valid(self, form):
        return super().form_valid(form)


class ShowInfo(ListView):
    """Return the result"""
#    queryset = Persons.objects.all()
    template_name = 'personsdb/getInfo.html'
    context_object_name = 'person'
