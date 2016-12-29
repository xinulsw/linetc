from django.conf.urls import url
from django.contrib.auth.decorators import login_required
from django.views.generic.list import ListView
from . import views
from . import models

urlpatterns = [
    url(r'^$', views.index, name='index'),
    url(r'^dodaj/$', views.PizzaCreate.as_view(), name='dodaj'),
    url(r'^lista/', login_required(
        ListView.as_view(
            model=models.Pizza,
            context_object_name='pizze',
            paginate_by=10),
        ),
        name='lista'),
    url(r'^aktualizuj/(?P<pk>\d+)/', views.PizzaUpdate.as_view(), name='aktualizuj'),
    url(r'^usun/(?P<pk>\d+)/', views.PizzaDelete.as_view(), name='usun'),
]
