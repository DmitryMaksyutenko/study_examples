from .forms import GetInfoForm
from django.shortcuts import render
from django.views.generic.edit import FormView

# Create your views here.

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

    def form_valid(self, form):
        return super().form_valid(form)