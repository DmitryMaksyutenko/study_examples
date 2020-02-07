from django.db import models


class Person(models.Model):
    name = models.CharField(max_length=15)
    surname = models.CharField(max_length=25)
    age = models.PositiveIntegerField()
