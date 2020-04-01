# -*- coding: utf-8 -*-
import csv

from django.http import StreamingHttpResponse


class Iter:

    def write(self, value):
        return value


def get_streaming_response(request):
    """Return streaming response."""

    rows = ([f"row: {num}", str(num)] for num in range(65000))
    pseudo_iter = Iter()
    writer = csv.writer(pseudo_iter)
    response = StreamingHttpResponse((writer.writerow(row) for row in rows),
                                     content_type="text/csv")

    response["Content-Disposition"] = 'attachment; filename="file.cvs"'

    return response
