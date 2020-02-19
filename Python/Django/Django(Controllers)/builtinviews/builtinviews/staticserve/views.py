from django.views.static import serve
from django.conf import settings


# Used to serve any directory give to it.
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# NOT FOR PRODUCTION USE, USED ONLY FOR DEVELOPMENT.
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#
def get_image(request):
    '''Controller returns the image.'''
    return serve(request, "Linux.png", document_root=settings.MEDIA_ROOT)


def get_text(request):
    '''Controller returns the text.'''
    return serve(request, "test.txt", document_root=settings.MEDIA_ROOT)
