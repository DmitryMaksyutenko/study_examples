from django.urls import path
from django.contrib.auth.views import LogoutView

from . views import (HomePage,
                     CreateUserFormView,
                     LogInUserView,
                     MessagesPage,
                     PrivateMessageView)

app_name = "messages"

urlpatterns = [
    path('', HomePage.as_view(), name='home'),
    path('sign-up', CreateUserFormView.as_view(), name='sign_up'),
    path('log-in', LogInUserView.as_view(), name='log_in'),
    path('log-out', LogoutView.as_view(), name='log_out'),
    path('messages', MessagesPage.as_view(), name='messages'),
    path('private-message/<int:user_id>',
         PrivateMessageView.as_view(),
         name="private_message")
]
