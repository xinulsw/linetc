# -*- coding: utf-8 -*-
# czat/czat/urls.py

from django.conf.urls import patterns, include, url
from django.contrib import admin
from czat import views # importujemy zdefiniowane w pliku views.py widoki

admin.autodiscover() # potrzebne tylko w Django 1.6

from django.views.generic.edit import CreateView
from django.contrib.auth.forms import UserCreationForm, AuthenticationForm
from django.core.urlresolvers import reverse_lazy

urlpatterns = patterns('',
    url(r'^$', views.index, name='index'),
    #url(r'^rejestruj/', views.rejestruj, name='rejestruj'),
    #url(r'^loguj/', views.loguj, name='loguj'),
    #url(r'^wyloguj/', views.wyloguj, name='wyloguj'),
    url(r'^rejestruj/', CreateView.as_view(
                    template_name='czat/rejestruj.html',
                    form_class=UserCreationForm,
                    success_url='/'), name='rejestruj'),
    url(r'^loguj/', 'django.contrib.auth.views.login',
                    {'template_name': 'czat/loguj.html'},
                    name='loguj'),
    url(r'^wyloguj/', 'django.contrib.auth.views.logout',
                    {'next_page': reverse_lazy('index')},
                    name='wyloguj'),
    url(r'^wiadomosci/', views.wiadomosci, name='wiadomosci'),

    url(r'^admin/', include(admin.site.urls)),
)
