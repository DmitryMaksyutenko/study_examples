from django import forms


class GetInfoForm(forms.Form):
    """Class of the form from getInfo.html"""
    name = forms.CharField(max_length=30)
