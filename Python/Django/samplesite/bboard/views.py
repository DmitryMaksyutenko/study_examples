# from django.http import HttpResponse
# from django.template import loader
from django.shortcuts import render
from django.views.generic.edit import CreateView
from django.urls import reverse_lazy


from . models import Db
from . models import Rubric
from . forms import DbForm


#   def index(request):
#       """Start page function"""
#       template = loader.get_template('bboard/index.html')
#       bbs = Db.objects.order_by('-published')
#       context = {'bbs': bbs}
#       return HttpResponse(template.render(context, request))


def index(request):
    """Start page function"""
    bbs = Db.objects.all()
    rubrics = Rubric.objects.all()
    context = {'bbs': bbs, 'rubrics': rubrics}
    return render(request, 'bboard/index.html', context)

def by_rubric(request, rubric_id):
    """Function for rubrics."""
    bbs = Db.objects.filter(rubric=rubric_id)
    rubrics = Rubric.objects.all()
    current_rubric = Rubric.objects.get(pk=rubric_id)
    context = {'bbs': bbs, 'rubrics': rubrics,
                'current_rubric': current_rubric}
    return render(request, 'bboard/by_rubric.html', context)

class DbCreateView(CreateView):
    template_name = 'bboard/create.html'
    form_class = DbForm
    success_url = reverse_lazy('index')

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context['rubrics'] = Rubric.objects.all()
        return context