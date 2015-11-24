# -*- coding: utf-8 -*-
# czat/czat/urls.py

from django.conf.urls import patterns, include, url
from django.contrib import admin
from czat import views  # importujemy widoki z pliku views.py

urlpatterns = patterns(
    '',
    url(r'^$', views.index, name='index'),
    url(r'^admin/', include(admin.site.urls)),
)
