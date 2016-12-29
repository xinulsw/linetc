# -*- coding: utf-8 -*-
from django.conf.urls import url
from django.contrib.auth.decorators import login_required
from django.views.generic.list import ListView
from . import views
from . import models

urlpatterns = [
    url(r'^$', views.index, name='index'),
    url(r'^dodaj/$', login_required(views.PizzaCreate.as_view(),
        login_url='/konta/login'),
        name='dodaj'),
    url(r'^lista/', login_required(ListView.as_view(
        model=models.Pizza,
        context_object_name='pizze',
        paginate_by=10),
        login_url='/konta/login'),
        name='lista'),
    url(r'^aktualizuj/(?P<pk>\d+)/', login_required(
        views.PizzaUpdate.as_view(),
        login_url='/konta/login'),
        name='aktualizuj'),
    url(r'^usun/(?P<pk>\d+)/', login_required(
        views.PizzaDelete.as_view(),
        login_url='/konta/login'),
        name='usun'),
]
