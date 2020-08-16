from django import forms
from django.contrib.auth.forms import (UserCreationForm,
                                       AuthenticationForm)
from django.contrib.auth.models import User


class CreateUser(UserCreationForm):

    def __init__(self, *args, **kwargs):
        super(UserCreationForm, self).__init__(*args, **kwargs)

        for field_name in ['username', 'password1', 'password2']:
            self.fields[field_name].help_text = None

    class Meta:
        model = User
        fields = ['username', 'email', 'password1', 'password2']


class LogInUser(AuthenticationForm):

    def confirm_login_allowed(self, user):
        if not user.is_active:
            raise forms.ValidationError(("This account is inactive."),
                                        code='inactive',
                                        )

    class Meta:
        fields = ['email', 'password']


class MessageForm(forms.Form):
    message = forms.CharField(empty_value="Message.",
                              label="",
                              widget=forms.TextInput(attrs={
                                  "class": "form-control",
                                  "size": "50"})
                              )
