from django import forms
from . models import Person


class PostForm(forms.ModelForm):
    class Meta:
        model = Person
        fields = ['name', 'surname', 'age']


class GetForm(forms.Form):
    name = forms.CharField(max_length=30, label='get name ')
