# from django.http import HttpResponse
# from django.template import loader
from django.shortcuts import render


from .models import Db


#   def index(request):
#       """Start page function"""
#       template = loader.get_template('bboard/index.html')
#       bbs = Db.objects.order_by('-published')
#       context = {'bbs': bbs}
#       return HttpResponse(template.render(context, request))


def index(request):
    """Start page function"""
    bbs = Db.objects.order_by('-published')
    return render(request, 'bboard/index.html', {'bbs': bbs})
