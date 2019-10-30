# This is an auto-generated Django model module.
# You'll have to do the following manually to clean this up:
#   * Rearrange models' order
#   * Make sure each model has one field with primary_key=True
#   * Make sure each ForeignKey has `on_delete` set to the desired behavior.
#   * Remove `managed = False` lines if you wish to allow Django to create, modify, and delete the table
# Feel free to rename the models, but don't rename db_table values or field names.
from django.db import models


class Personaddress(models.Model):
    address = models.CharField(max_length=50)
    person = models.OneToOneField('Persons', models.DO_NOTHING)

    class Meta:
        managed = False
        db_table = 'personaddress'


class Persons(models.Model):
    name = models.CharField(max_length=20, blank=True, null=True)
    surname = models.CharField(max_length=30, blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'persons'


class Planguages(models.Model):
    name = models.CharField(max_length=20, blank=True, null=True)
    typeofl = models.CharField(max_length=7, blank=True, null=True)
    person = models.ForeignKey(Persons, models.DO_NOTHING)

    class Meta:
        managed = False
        db_table = 'planguages'

class Shoes(models.Model):
    person = models.ManyToManyField(Persons)
    shoes = models.BooleanField(default=False)
    sneakers = models.BooleanField(default=False)
    winter_shoes = models.BooleanField(default=False)
    slippers = models.BooleanField(default=False)

    class Meta:
        db_table = "shoes"