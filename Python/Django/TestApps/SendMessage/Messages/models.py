# -*- coding: utf-8 -*-
import json

from django.contrib.auth.models import User
from django.contrib.sessions.models import Session
from django.db import models
from django.utils import timezone


class JesonMessages(models.Manager):

    def as_json(self):
        json_string = str()
        all_data = self.all()
        for obj in all_data:
            json_string += json.dumps({"user_name": obj.user_id.username,
                                       "message": obj.message})
        return json_string


class PrivateMessageManager(models.Manager):

    def messages(self, send, rec):
        json_string = str()
        li = [send, rec]
        res = self.filter(sender__in=li, receiver__in=li)
        for obj in res:
            json_string += json.dumps({"from_user": obj.sender.username,
                                       "for_user": obj.receiver.username,
                                       "message": obj.message})
        return json_string

    def from_users_messages(self, user):
        json_string = str()
        query = self.filter(receiver=user)
        users = query.filter(sender__in=query.values("sender"))
        users_id = User.objects.filter(id__in=users.values("sender"))
        for data in users_id:
            json_string += json.dumps({"user_name": data.username,
                                       "user_id": data.id})
        return json_string


class AuthenticatedUsersManager(models.Manager):

    def authenticated_users(self, active_sessions):
        users_list = list()
        for session in active_sessions:
            data = session.get_decoded()
            users_list.append(data.get("_auth_user_id", None))
        users = User.objects.filter(id__in=users_list)
        return users


class AuthenticatedSessionManager(models.Manager):

    def active_sessions(self):
            current_time = timezone.now()
            active_sessions = Session.objects.filter(
                        expire_date__gte=current_time
                    )
            return active_sessions


class UserMethods(User):

    auth_manager = AuthenticatedUsersManager()

    class Meta:
        proxy = True


class SessionMethods(Session):

    auth_manager = AuthenticatedSessionManager()

    class Meta:
        proxy = True


class Messages(models.Model):

    objects = models.Manager()
    json = JesonMessages()

    user_id = models.ForeignKey(User, on_delete=models.PROTECT)
    message = models.TextField()
    time = models.DateTimeField(auto_now=True)


class PrivateMessage(models.Model):

    objects = models.Manager()
    message_manager = PrivateMessageManager()

    message = models.TextField()
    time = models.DateTimeField(auto_now=True)
    sender = models.ForeignKey(User,
                               on_delete=models.PROTECT,
                               related_name='sender',
                               unique=False)
    receiver = models.ForeignKey(User,
                                 on_delete=models.PROTECT,
                                 related_name='receiver',
                                 unique=False)
