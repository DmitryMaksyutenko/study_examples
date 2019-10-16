# This is an auto-generated Django model module.
# You'll have to do the following manually to clean this up:
#   * Rearrange models' order
#   * Make sure each model has one field with primary_key=True
#   * Make sure each ForeignKey has `on_delete` set to the desired behavior.
#   * Remove `managed = False` lines if you wish to allow Django to create, modify, and delete the table
# Feel free to rename the models, but don't rename db_table values or field names.
from django.db import models


class City(models.Model):
    id = models.AutoField(db_column='ID', primary_key=True)
    name = models.CharField(db_column='Name', max_length=35)
    countrycode = models.ForeignKey('Country', models.DO_NOTHING, db_column='CountryCode')
    district = models.CharField(db_column='District', max_length=20)
    population = models.IntegerField(db_column='Population')

    class Meta:
        managed = False
        db_table = 'city'


class Country(models.Model):
    code = models.CharField(db_column='Code', primary_key=True, max_length=3)
    name = models.CharField(db_column='Name', max_length=52)
    continent = models.CharField(db_column='Continent', max_length=13)
    region = models.CharField(db_column='Region', max_length=26)
    surfacearea = models.FloatField(db_column='SurfaceArea')
    indepyear = models.SmallIntegerField(db_column='IndepYear', blank=True, null=True)
    population = models.IntegerField(db_column='Population')
    lifeexpectancy = models.FloatField(db_column='LifeExpectancy', blank=True, null=True)
    gnp = models.FloatField(db_column='GNP', blank=True, null=True)
    gnpold = models.FloatField(db_column='GNPOld', blank=True, null=True)
    localname = models.CharField(db_column='LocalName', max_length=45)
    governmentform = models.CharField(db_column='GovernmentForm', max_length=45)
    headofstate = models.CharField(db_column='HeadOfState', max_length=60, blank=True, null=True)
    capital = models.IntegerField(db_column='Capital', blank=True, null=True)
    code2 = models.CharField(db_column='Code2', max_length=2)

    class Meta:
        managed = False
        db_table = 'country'


class Countrylanguage(models.Model):
    countrycode = models.OneToOneField(Country, on_delete=models.PROTECT, primary_key=True)
    language = models.CharField(db_column='Language', max_length=30)
    isofficial = models.CharField(db_column='IsOfficial', max_length=1)
    percentage = models.FloatField(db_column='Percentage')

    class Meta:
        managed = False
        db_table = 'countrylanguage'
        unique_together = (('countrycode', 'language'),)
