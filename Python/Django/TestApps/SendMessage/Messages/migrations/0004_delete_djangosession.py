# Generated by Django 3.0.6 on 2020-06-29 07:20

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('Messages', '0003_djangosession_sessionmethods_usermethods'),
    ]

    operations = [
        migrations.DeleteModel(
            name='DjangoSession',
        ),
    ]