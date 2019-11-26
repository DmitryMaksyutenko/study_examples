from django import forms


class GetInfoForm(forms.Form):
    """Class of the form from getInfo.html"""
    person = forms.CharField(max_length=30)
    language = forms.CharField(max_length=30)
    shoes = forms.CharField(max_length=30)
    address = forms.CharField(max_length=30)
