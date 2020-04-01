#!/usr/bin/env python
"""Django's command-line utility for administrative tasks."""
import os
import sys


def main():
    # DJANGO_SETTINGS_MODULE is an environment variable that tells Django which
    # settings file to use. It should be in Python path syntax e.g.
    # "mysite.settings". The settings module should be on the Python import
    # search path. (sys.path)
    #
    # os.environ - a "mapping"" object representing the string environment.
    #
    # "mapping" - a container object that supports arbitrary key lookups and
    # implements the methods specified in the Mapping or MutableMapping
    # abstract base classes:
    # (dict, collections.defaultdict, collections.OrderedDict,
    # collections.Counter)
    #
    # os.environ.setdefault(self, key, value) - insert key with a value of
    # default and retunr default.
    #
    # In live server environment, need to tell WSGI application what settings
    # file to use.
    #
    os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'config.settings.local')
    try:
        from django.core.management import execute_from_command_line
    except ImportError as exc:
        raise ImportError(
            "Couldn't import Django. Are you sure it's installed and "
            "available on your PYTHONPATH environment variable? Did you "
            "forget to activate a virtual environment?"
        ) from exc
    # A function that runs a ManagementUtility.
    # ManagementUtility class encapsulate the logic of the django-admin and
    # manage.py utilities by passed "sys.argv". ManagementUtility.execute()
    execute_from_command_line(sys.argv)


if __name__ == '__main__':
    main()
