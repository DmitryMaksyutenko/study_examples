"""This file override some base settings and add new, for local needments."""
from . base import * # noqa
from . base import env


DEBUG = True
# ------------------------------------------------------------------------

SECRET_KEY = env("DJANGO_SECRET_KEY",
                 default="sdklfgjLKklj1lkjJLLhilhHOIho098HhhoihggpPghpgh")
# ------------------------------------------------------------------------

# A list of strings represnting the host/domain names that this Django site can
# serve. This is security measure to prevent HTTP header attacks, which are
# possible even many seemingly-save web server configuration.
#
# Default [] (Empty list).
#
ALLOWED_HOSTS = ["localhost", "127.0.0.1", "0.0.0.0"]
# ------------------------------------------------------------------------

# A dictionary containing the settings for all caches to be used with Django.
# It is a nested dictionary whose contents maps cache aliases to a dictionary
# containing the options for an individual cache.
#
# Default {
#   "default": {
#       "BACKEND": "django.core.cache.backends.locmem.LocMemCache",
#   }
#
CACHES = {
    "default": {
        "BACKEND": "django.core.cache.backends.locmem.LocMemCache",
        "LOCATION": "",
    }
}
# ------------------------------------------------------------------------

# =================
# django-debug-toolbar
# =================

# The Django Debug Toolbar is a configurable set of panels that display various
# debug information about the cuttent request/response.
#
# INSTALLED_APPS += ["debug_toolbar"] # noqa
# ------------------------------------------------------------------------

# MIDDLEWARE += ["debug_toolbar.middleware.DebugToolbarMiddleware"] # noqa
# ------------------------------------------------------------------------

# DEBUG_TOOLBAR_CONFIG = {
#     "DISABLE_PANELS": ["debug_toolbar.panels.redirect.RedirectPanel"],
#     "SHOW_TEMPLATE_CONTEXT": True,
# }
# ------------------------------------------------------------------------

# INTERNAL_IPS = ["127.0.0.1", "10.0.2.2"]
# ------------------------------------------------------------------------

# =================
# django-extensions
# =================

# Is a collection of custom extensions for Django Framework.
# Include management commends, additional database fields, admin extensions...
#
INSTALLED_APPS += ["django_extensions"] # noqa
