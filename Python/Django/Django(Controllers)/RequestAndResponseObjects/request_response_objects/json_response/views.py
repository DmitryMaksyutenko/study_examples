# -*- coding utf-8 -*-
from django.http import JsonResponse


def get_json(request):
    """Return JsonResponse object"""
    return JsonResponse({
        "name": "class JsonResponse",
        "place": "django.http module",
        })
