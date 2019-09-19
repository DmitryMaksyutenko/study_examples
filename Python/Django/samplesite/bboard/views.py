# from django.http import HttpResponse
# from django.template import loader
from django.shortcuts import render


from . models import Db
from . models import Rubric


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