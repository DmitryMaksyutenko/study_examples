from django.shortcuts import render
from . models import City, Countrylanguage, Country

from . form import ShowTable

# Create your views here.
def index_page(request):
    """Functin return main page"""
    form = ShowTable()
    context = { 'form': form }
    return render(request, 'index.html', context)

def db_table(request):
    """Function return city tabele."""
    from_form = request.POST.copy()
    field = from_form.get("field", "")

    if field == City._meta.db_table:
        title = field
        city = City.objects.all()
        columns = [i.get_attname() for i in City._meta.fields]
        context = {'title': title, 'tables': city, 'columns': columns}
        return render(request, 'city.html', context)

    if field == Country._meta.db_table:
        title = field
        country = Country.objects.all()
        columns = [i.get_attname() for i in Country._meta.fields]
        context = {'title': title, 'tables': country, 'columns': columns}
        return render(request, 'country.html', context)

    if field == Countrylanguage._meta.db_table:
        title = field
        countrylang = Countrylanguage.objects.all()
        columns = [i.get_attname() for i in Countrylanguage._meta.fields]
        context = {'title': title, 'tables': countrylang, 'columns': columns}
        return render(request, 'language.html', context)