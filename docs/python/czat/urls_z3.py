# -*- coding: utf-8 -*-
# czat/czat/urls.py

from django.conf.urls import patterns, include, url
from django.contrib import admin
from czat import views  # importujemy zdefiniowane w pliku views.py widoki

urlpatterns = patterns(
    '',
    url(r'^$', views.index, name='index'),
    url(r'^rejestruj/', views.rejestruj, name='rejestruj'),

    url(r'^admin/', include(admin.site.urls)),
)
