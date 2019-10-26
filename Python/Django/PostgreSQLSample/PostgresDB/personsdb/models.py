# This is an auto-generated Django model module.
# You'll have to do the following manually to clean this up:
#   * Rearrange models' order
#   * Make sure each model has one field with primary_key=True
#   * Make sure each ForeignKey has `on_delete` set to the desired behavior.
#   * Remove `managed = False` lines if you wish to allow Django to create, modify, and delete the table
# Feel free to rename the models, but don't rename db_table values or field names.
from django.db import models


class Persons(models.Model):
    name = models.CharField(max_length=20, blank=True, null=True)
    surname = models.CharField(max_length=30, blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'persons'


class PLanguages(models.Model):
    LANGUAGES = (
        ('JS', 'JavaScript'),
        ('CPP', 'C++'),
        ('Py', 'Python'),
    )
    person = models.ForeignKey(Persons, on_delete=models.PROTECT)
    name = models.CharField(max_length=20, null=True, choices=LANGUAGES)
    typeofl = models.CharField(max_length=7, null=True)

    class Meta:
        db_table = "planguages"
