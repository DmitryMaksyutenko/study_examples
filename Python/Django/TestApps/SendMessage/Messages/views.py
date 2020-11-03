import json

from django.http import JsonResponse
from django.shortcuts import render, redirect
from django.contrib.auth import authenticate, login
from django.contrib.auth.models import User
from django.contrib.auth.views import (LoginView,
                                       AuthenticationForm)
from django.views.generic.base import TemplateView
from django.views.generic.edit import FormView
from django.utils import timezone

from . models import (Messages,
                      SessionMethods,
                      UserMethods,
                      PrivateMessage)
from . forms import (CreateUser,
                     LogInUser,
                     MessageForm)


class HomePage(TemplateView):
    template_name = 'index.html'


class PrivateMessageView(TemplateView):
    template_name = 'private_message.html'

    def get(self, request, *args, **kwargs):
        form = MessageForm()
        all_messages = PrivateMessage.message_manager.messages(
                request.user.id,
                kwargs['user_id']
                )
        content = {
                    "form": form,
                    "all": all_messages
                  }

        return render(request, self.template_name, content)

    def post(self, request, *args, **kwargs):
        if request.is_ajax():
            json_data = json.loads(request.body)

        form = MessageForm(request.POST)
        messages = PrivateMessage()
        if form.is_valid():
            messages.receiver = User.objects.get(pk=kwargs["user_id"])
            messages.sender = User.objects.get(pk=request.user.id)
            messages.message = json_data['message']
            messages.time = timezone.now()
            messages.save()

        all_messages = PrivateMessage.message_manager.messages(
                request.user.id,
                kwargs['user_id'])
        data = {"all": all_messages}

        return JsonResponse(data, status=200, safe=False)


class MessagesPage(TemplateView):
    template_name = 'messages.html'

    def get(self, request, *args, **kwargs):
        if request.user.is_authenticated:
            all_messages = Messages.json.as_json()
            private_users = \
                PrivateMessage.message_manager.from_users_messages(
                        request.user)
            active_sessions = SessionMethods.auth_manager.active_sessions()
            users = UserMethods.auth_manager.authenticated_users(
                                                active_sessions)
            users = users.exclude(username=request.user)
            form = MessageForm()
            content = {
                        "form": form,
                        "all": all_messages,
                        "users": users,
                        "private": private_users
                      }
            return render(request, self.template_name, content)
        else:
            return redirect("messages:home")

    def post(self, request, *args, **kwarg):

        json_data = {"message": ""}
        if request.is_ajax():
            json_data = json.loads(request.body)

        form = MessageForm(request.POST)
        messages = Messages()

        if form.is_valid():
            messages.user_id = request.user
            messages.time = timezone.now()
            messages.message = json_data['message']
            messages.save()

        all_messages = Messages.json.as_json()
        private_messages = \
            PrivateMessage.message_manager.from_users_messages(request.user)
        data = {"all": all_messages, "private": private_messages}
        return JsonResponse(data, status=200, safe=False)


class CreateUserFormView(FormView):
    template_name = 'signup.html'
    form_class = CreateUser
    success_url = 'messages'

    def form_valid(self, form):
        form.save()
        return super().form_valid(form)


class LogInUserView(LoginView):
    template_name = 'login.html'
    form_class = LogInUser

    def post(self, request, *args, **kwargs):
        content = dict()
        user_form = AuthenticationForm(data=request.POST)
        if not request.user.is_authenticated:
            if user_form.is_valid():
                user_name = request.POST['username']
                password = request.POST['password']
                user = authenticate(request,
                                    username=user_name,
                                    password=password)
                if user is not None:
                    login(request, user)
            return redirect("messages:messages")

        content['form'] = user_form
        return render(request, self.template_name, content)
