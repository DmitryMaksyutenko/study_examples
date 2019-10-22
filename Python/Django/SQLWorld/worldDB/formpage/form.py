from django import forms

from . models import City, Country, Countrylanguage

class ShowTable(forms.Form):
    """Form for request table from the database."""
    options = ((City._meta.db_table, City._meta.db_table),
                (Country._meta.db_table, Country._meta.db_table),
                (Countrylanguage._meta.db_table, Countrylanguage._meta.db_table))
    field = forms.ChoiceField(choices=options)