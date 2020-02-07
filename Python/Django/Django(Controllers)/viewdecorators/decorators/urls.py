from django.urls import path, re_path
from . import views


urlpatterns = [
    path('', views.get_index, name="index_page"),
    re_path(r'^get-page$', views.get_get_page, name="get_decorator_page"),
    re_path(r'^safe-page$', views.get_safe, name="safe_decorator_page"),
    re_path(r'^post-response$', views.get_post, name="post_decorator"),
    re_path(r'^post-request$', views.get_form, name="post_form_page"),
    re_path(r'^gzip-page$', views.get_gzip, name="gzip_decorator_page"),
    re_path(r'^get-name$', views.get_name_form, name="get_name_form_page"),
    re_path(r'^get-data-page$',
            views.conditional_processing,
            name="show_data_page"),
    re_path(r'^get-never-cache-page$', views.get_not_cacheable_page,
            name="get_not_cacheable_page"),
    re_path(r'^get-cache-control-page$', views.get_cache_control,
            name="get_cache_control_page")
]
