from os import environ
from pathlib import Path

# Build paths inside the project like this: BASE_DIR / 'subdir'.
BASE_DIR = Path(__file__).resolve(strict=True).parent.parent
# https://docs.djangoproject.com/en/3.0/ref/settings/#secret-key
SECRET_KEY = 'Asdfj0900asdlkjlhooe67AdskhFklkLJLojas09jlahkljh'
# https://docs.djangoproject.com/en/3.0/ref/settings/#debug
DEBUG = True
# https://docs.djangoproject.com/en/3.0/ref/settings/#allowed-hosts
ALLOWED_HOSTS = ["127.0.0.1", "localhost", "0.0.0.0", "192.168.0.102"]
# https://docs.djangoproject.com/en/3.0/ref/settings/#root-urlconf
ROOT_URLCONF = 'configs.urls'

STATIC_URL = '/static/'
STATIC_ROOT = BASE_DIR / "static/"

MEDIA_URL = "/media/"
MEDIA_ROOT = BASE_DIR / "media/"

LOGIN_REDIRECT_URL = '/messages'
LOGOUT_REDIRECT_URL = '/'

SESSION_COOKIE_AGE = 86400

INSTALLED_APPS = [
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.messages',
    'django.contrib.sessions',
    'django.contrib.staticfiles',

    'corsheaders',

    'Messages.apps.MessagesConfig',
]

TEMPLATES = [
    {
        'BACKEND': 'django.template.backends.django.DjangoTemplates',
        'APP_DIRS': True,
        'OPTIONS': {
            'context_processors': [
                'django.contrib.auth.context_processors.auth',
                'django.contrib.messages.context_processors.messages'
            ]
        }
    },
]

DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.postgresql',
        'NAME': environ['DATABASE_NAME'],
        'USER': environ['DATABASE_USER'],
        'PASSWORD': environ['DATABASE_PASS'],
        'HOST': environ['DATABASE_HOST'],
        'PORT': environ['DATABASE_PORT'],
        'ATOMIC_REQUESTS': True
    }
}

MIDDLEWARE = [
    'corsheaders.middleware.CorsMiddleware',
    'django.contrib.sessions.middleware.SessionMiddleware',
    'django.contrib.messages.middleware.MessageMiddleware',
    'django.contrib.auth.middleware.AuthenticationMiddleware',
]

CORS_ORIGIN_ALLOW_ALL = False

CORS_ORIGIN_WHITELIST = (
    'http://localhost:8000',
    'http://127.0.0.1:8000'
)
