# -*- coding: utf-8 -*-
from django.http import FileResponse
from django.conf import settings


def get_file_response(requset):
    """Return file."""

    img_file = open(settings.APPS_DIR + "static/images/Linux.png", "rb")

    return FileResponse(img_file)
