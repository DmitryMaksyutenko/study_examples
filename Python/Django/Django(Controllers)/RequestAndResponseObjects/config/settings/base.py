'''Base settings file that used by the other files for setup.'''

# ===================
# BASE INFORMATION:
# ===================
#
# Django settings file contains all the configuration of Django.
# It's just a Python module with module-level variables.
#
# -It can assign values dynamically.
# -It can import values from other modules (settings files).
#
# -----------------------------------------------------------
# Django uses the next algorithm for compiling settings:
#
# -Load settings from django/conf/global_settings.py
# -Load settings from the specified settings file,
# overidding the global settings as necessary.
#
# -----------------------------------------------------------
# The command "python manage.py diffsettings" displays difference berween the
# current settings file and Django's default settings.
#
# -----------------------------------------------------------
# The settings can be used in application via the object "settings" imported
# from "django.conf".
# Do not alter settings in application in runtime.
# The only place for settings assigning is the settings file.
#
# -----------------------------------------------------------
# -Settings name muset be all UPPERCASE.
# -Don't reinvent an alreay-existing settings.
#
# -----------------------------------------------------------

# Package for configuring Django Application with environment variables.
import environ

# Get root directory.
ROOT_DIR = (environ.Path(__file__) - 3)

# Get applications directory.
APPS_DIR = ROOT_DIR.path("request_response_objects")

# Provides scheme-dased lookups of environment variables so thar each caller
# doesn't have ro pass in cast and defaul parameters.
env = environ.Env()

# ===================
# GENERAL:
# ===================

# A boolean that turns on/off debug mode.
#
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# Never deploy a site into production with DEBUG = True.
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#
# Display detailed error pages. Django will display a detailed traceback,
# including a lot of metadata about environment.
#
DEBUG = False
# -----------------------------------------------------------

# A string represending the timezone for this instalation.
#
# When USE_TZ is False, this is time zone in which Django will store all
# datetimes. When USE_TZ is True, this is the default time zone that Django
# will use to display datetimes in templates and to interpret datetimes entered
# in forms.
#
# Default "America/Chicago".
#
TIME_ZONE = "Europe/Kiev"
# -----------------------------------------------------------

# A string reapresenting the language code for this instalation.
# Default "en-us"
#
# USE_I18N must be active for this settings to have any effect.
#
# - If the locale middleware isn't use, it indicate which translation is served
# to all users.
# - If the locale middleware is active, it provides a fallback language in case
# the user's preferd language can,t be determined or is not to be supported by
# the website. Also provide fallback translation.
#
LANGUAGE_CODE = "en-gb"
# -----------------------------------------------------------

# The ID, as an integer, of the current site in the "django_site" database
# table. This is used so that application data can hook into specific sites and
# a single databse can manage content for multiple sites.
#
# Default not specified.
#
SITE_ID = 1
# -----------------------------------------------------------

# A boolean that specifies whether Django's translation system should be
# enabled. This provides a way to turn it off, for performance. If this is set
# to False, Django will make some optimizations so as not to load the
# translation machinery.
#
# Default True.
#
USE_I18N = True
# -----------------------------------------------------------

# A boolean that specifies if localized formating of data will be enabled by
# default or not. If this is set to True, e.g. Django will display numbers and
# dates using the format of the current locale.
#
# Default False.
#
USE_L10N = True
# -----------------------------------------------------------

# A boolean that specifies if datetimes will be timezone-aware or not.
# If this is not set to True, Django will use timezone-aware datetimes
# internally. Otherwise, Django will use naive datetimes in local time.
#
# Default False.
#
USE_TZ = True
# -----------------------------------------------------------

# A list of directories where Django looks for translation files.
#
# Django will look within each of these paths fot the
# <locale_code>/LC_MESSSAGES directories containing the actual translation
# files.
#
# Default emply list ([]).
#
LOCALE_PATHS = []
# -----------------------------------------------------------


# ===================
# DATABASES:
# ===================

# A dictionary containing the settings for all databases to bu used with
# Django. It is a nested dictionary whose contents map a database alias to a
# dictionary containing the options for an ingividual database.
#
# the DATABASES  settings must configure a default database; any number af
# additional databases may also be specified.
#
# Default {} (Empty dictionary).
#
# Read os.environ['DATABASE_URL']
DATABASES = {"default": env.db()}

# If True wrap each view in transaction on this database.
# Default False.
DATABASES["default"]["ATOMIC_REQUESTS"] = True
# -----------------------------------------------------------

# ===================
# URLS:
# ===================

# A string representing the full path to root URLcong.
#
# Default not spacified.
#
ROOT_URLCONF = "config.urls"
# -----------------------------------------------------------

# The full Python path of the WSGI application object that Django's built-in
# servers will use.
#
# If not set, then the retunr value fo django.core.wsgi.get_wsgi_application()
# will be used.
#
# Default None.
#
WSGI_APPLICATION = None
# -----------------------------------------------------------

# ===================
# APPS:
# ===================

# Django built applications list
DJANGO_APPS = [
    "django.contrib.admin",
    "django.contrib.auth",
    "django.contrib.contenttypes",
    "django.contrib.messages",
    "django.contrib.sessions",
    "django.contrib.staticfiles"
]
# -----------------------------------------------------------

# Custom applications.
LOCAL_APPS = []
# -----------------------------------------------------------

# Applications installed via pip.
THIRD_PARTY_APPS = []
# -----------------------------------------------------------

# A list of stringts designating all applications that are enabled in this
# Django instalation. Each string should be dotted Python path to:
# - an application configuration class, or
# - a package containing an application.
#
# Default [] (Empty list).
#
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# Never accesse the INSTALLED_APPS directly use "django.apps.apps"
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#
INSTALLED_APPS = DJANGO_APPS + THIRD_PARTY_APPS + LOCAL_APPS
# -----------------------------------------------------------

# ===================
# MIGRATIONS:
# ===================

# A dictionary specifying the package where migration modules can be found on a
# per-app bases. Default name for package is "migrations".
#
# Default {} (Empty dictionary).
#
MIGRATION_MODULES = {}
# -----------------------------------------------------------

# ===================
# AUTHENTICATION:
# ===================

# Alist of authentication classes (as strings) to use when attemptiong to
# authenticate a user.
#
# Default ['django.contrib.auth.backends.ModelBackend']
#
AUTHENTICATION_BACKENDS = [
        'django.contrib.auth.backends.ModelBacked'
]
# -----------------------------------------------------------

# The model to use to represent a User.
#
# Default "auth.user".
#
AUTH_USER_MODEL = "auth.user"
# -----------------------------------------------------------

# The URL or named URL pattern where requests are redirected after login when
# the "LoginView" doesn't get a new GET parameter.
#
# Default "/account/profile/"
#
LOGIN_REDIRECT_URL = "/account/profile/"
# -----------------------------------------------------------

# The URL or named URL pattern where requests are redirected for login when
# using the "login_requiered()" decoreator, "LoginRequieredMixin" or
# "AccessMixin".
#
# Default "/account/login/"
#
LOGN_URL = "/account/login/"
# -----------------------------------------------------------

# ===================
# PASSWORDS:
# ===================

PASSWORD_HASHERS = [
    'django.contrib.auth.hashers.PBKDF2PasswordHasher',
    'django.contrib.auth.hashers.PBKDF2SHA1PasswordHasher',
    'django.contrib.auth.hashers.Argon2PasswordHasher',
    'django.contrib.auth.hashers.BCryptSHA256PasswordHasher',
]
# -----------------------------------------------------------

# The list of validators that are used to check the strength of user's
# passwords.
#
# Default [] (Empty list).
#
AUTH_PASSWORD_VALIDATORS = []
# -----------------------------------------------------------

# ===================
# MIDDLEWARE:
# ===================

# A list of middleware to use.
#
# Default None.
#
# Middleware is a framework of hooks into Django's request/response processing.
# It's a light, low-level "plugin" system for globally altering Django's input
# or output.
#
MIDDLEWARE = [
    "django.contrib.sessions.middleware.SessionMiddleware",
    "django.middleware.common.CommonMiddleware",
    "django.contrib.auth.middleware.AuthenticationMiddleware",
    "django.contrib.messages.middleware.MessageMiddleware",
]
# -----------------------------------------------------------

# ===================
# STATIC:
# ===================

# The absolute path to the directory where"collectstatic" command will collect
# static files for deployment into specified root.
#
# Default None.
#
STATIC_ROOT = None
# -----------------------------------------------------------

# URL to use when refering to static files located in STATIC_ROOT.
#
# It must end in a slash if set to a non-empty value.
#
# It must be specified in production.
#
# Default None.
#
STATIC_URL = "/static/"
# -----------------------------------------------------------

# Additional locations the staticfiles app will traverse if the
# FileSystemFinder finder is enabled.
#
# It should consists the strings of full paths.
#
# Default [] (Empty list).
#
STATICFILES_DIRS = [str(APPS_DIR.path("static"))]
# -----------------------------------------------------------

# The list of finder backends that know how to find static files in various
# locations.
#
# Default [
#   'django.contrib.staticfiles.finders.FileSystemFinder',
#   'django.contrib.staticfiles.finders.AppDirectoriesFinder',
# ]
#
STATICFILES_FINDERS = [
    'django.contrib.staticfiles.finders.FileSystemFinder',
    'django.contrib.staticfiles.finders.AppDirectoriesFinder',
]
# -----------------------------------------------------------

# ===================
# MEDIA:
# ===================

# Absolute filesystem path to the directory where user will hold the
# user-uploaded files.
#
# Default "" (Empty string)
#
MEDIA_ROOT = ""
# -----------------------------------------------------------

# URL that handles the media served from MEDIA_ROOT, used for managing stored
# files. It muset end in a slash if setted as non-empty stering.
#
# Default "" (Empty string)
#
MEDIA_URL = ""
# -----------------------------------------------------------

# ===================
# TEMPLATES:
# ===================

# A list containing the settings for all template engine to be used with
# Django. Each item in a list is a dictionary containing the options for an
# indevidual engine.
#
# Default [] (Empty list)
#
# Options:
# BACKEND - the backeng template to use.
# NAME - the alias for this particular engine.
# DIRS - a list in wihich engine must to look for template source files.
# APP_DIRS - whether the engine should look for template source files inside
# installed application.
# OPTIONS - extra paremeters to pass to the template backend. A dictionary
# depends on the particular engine.
#
TEMPLATES = [{
    "BACKEND": "django.template.backends.django.DjangoTemplates",
    "DIRS": ["request_response_objects/templates"],
    "OPTIONS": {
        "context_processors": [
            "django.contrib.auth.context_processors.auth",
            "django.contrib.messages.context_processors.messages",
        ],
    }
}]
# -----------------------------------------------------------

# The class that renders the form widgets.
#
# Default: 'django.forms.renderers.DjangoTemplates'.
#
FORM_RENDERER = "django.forms.renderers.DjangoTemplates"
# -----------------------------------------------------------

# django-crispy-forms has built-in support for different CSS frameworks.
# Crispy filter lets render a form or formset using django-crispy-forms
# elegantly div based fields.
#
CRISPY_TEMPLATE_PACK = ""
# -----------------------------------------------------------

# ===================
# FIXTURES:
# ===================

# List of directories looked for fixtures files.
#
# Default [] (Empty list).
#
FIXTURE_DIRS = []
# -----------------------------------------------------------

# ===================
# security:
# ===================

# Whether to use HttpOnly flag on the session cookie. If this is set to True,
# client-side JavaScript will not be able to access the session cookie.
#
# Default True
#
SESSION_COOKIE_HTTPONLY = True
# -----------------------------------------------------------

# Whether to use HttpOnly flag on the CSRF cookie. If this is set to True,
# client-side JavaScript will not be able to access the CSRF cookie.
#
# Default True.
#
CSRF_COOKIE_HTTPONLY = True
# -----------------------------------------------------------

# If True, the SecurityMiddleware sets the X-XSS-Protection: 1; mode=block
# header on all responses that do not already have it.
# Modern browsers don’t honor X-XSS-Protection HTTP header anymore.
# Although the setting offers little practical benefit, you may still
# want to set the header if you support older browsers.
#
# Default True.
#
SECURE_BROWSER_XSS_FILTER = True
# -----------------------------------------------------------


# The default value for the X-Frame-Options header used by
# XFrameOptionsMiddleware.
#
# Default: 'DENY'.
#
X_FRAME_OPTIONS = "DENY"
# -----------------------------------------------------------

# ===================
# EMAIL:
# ===================

# The backend to use for sending emails.
#
# Default "django.core.mail.backends.smpt.EmailBackend".
#
EMAIL_BACKEND = "django.core.mail.backends.smpt.EmailBackend"
# -----------------------------------------------------------

# Spacifies a timeout in seconds for blocking operations like the connection
# attempt.
#
# Default None.
#
EMAIL_TIMEOUT = None
# -----------------------------------------------------------

# ===================
# ADMIN:
# ===================

# Django admin URL.
#
ADMIN_URL = "admin/"
# -----------------------------------------------------------

# A list of all the people who get code error notifications. When DEBUG=False
# and AdminEmailHandler is configured in LOGGING, Django emails these peoples
# the derails of exeption raised in the request/response cycle.
#
# Default [] (Empty list).
#
ADMINS = []
# -----------------------------------------------------------

# A list in the same format as ADMINS that specifies who should get broken link
# norigications when BrokenLinksEmailsMiddleware is enabled.
#
# Default [] (Empty list).
#
MANAGERS = ADMINS
# -----------------------------------------------------------

# ===================
# LOGGING:
# ===================

# A data structure containing configuration information. The content of this
# data structure will be passed as the argument to the configuration method
# discribed in LOGGING_CONFIG.
#
# Amoung other things, the default logging configuration passes HTTP 500 server
# errors to an email log hendler when DEBUG=False.
#
# Default a logging configuration information.
#
LOGGING = {
    'version': 1,
    'disable_existing_loggers': False,
    'handlers': {
        'file': {
            'level': 'DEBUG',
            'class': 'logging.FileHandler',
            'filename': ROOT_DIR + 'debug.log',
        },
    },
    'loggers': {
        'django': {
            'handlers': ['file'],
            'level': 'DEBUG',
            'propagate': True,
        },
    },
}
# -----------------------------------------------------------


# django-allauth is a reusable Django app that allows for both local and social
# authentication with flows that just work.
#

# Spacifies the login method to use.
#
ACCOUNT_AUTHENTICATION_METHOD = "username"
# -----------------------------------------------------------

# The user is required to hand over an e-mail addres when signing up.
#
ACCOUNT_EMAIL_REQUIERED = True
# -----------------------------------------------------------

# Determines the e-mail verification method during singup.
#
ACCOUNT_EMAIL_VERIFICATION = "mandatory"
# -----------------------------------------------------------

# Specifies the adapter class to use, allowing the alert certain default
# behaviour.
#
ACCOUNT_ADAPTER = "builtinviews.users.adapter.AccountAdapter"
# -----------------------------------------------------------

# Specifies the adapter class to use, allowing to alert certain default
# behaviour.
#
SOCIALACCAUNT_ADAPTER = "builtinviews.users.adapters.SocialAccauntAdapter"
# -----------------------------------------------------------
