from django.forms import forms


class GetInfoForm(forms.Form):
    """Class of the form from getInfo.html"""
    persons = forms.Field()