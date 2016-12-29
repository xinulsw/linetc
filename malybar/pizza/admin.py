# -*- coding: utf-8 -*-

from django.contrib import admin
from django.forms import Textarea
from django.db.models.fields import TextField

from . import models


class SkladnikInline(admin.TabularInline):
    model = models.Skladnik
    max_num = 6
    extra = 3
    fields = ['nazwa', 'jarski']


@admin.register(models.Pizza)
class PizzaAdmin(admin.ModelAdmin):
    # fields = ['przedmiot', 'kategoria', 'typ', 'polecenie']
    exclude = ('autor',)
    # obiekty zależne do wyświetlenia
    inlines = [SkladnikInline]
    # nagłówki do wyświetlenia
    # list_display = ('question_text', 'pub_date', 'was_published_recently')
    # wyszukiwanie
    search_fields = ['nazwa']
    list_per_page = 10

    formfield_overrides = {
        TextField: {'widget': Textarea(attrs={'rows': 2, 'cols': 100})},
    }

    def save_model(self, request, obj, form, change):
        if not change:
            obj.autor = request.user
        obj.save()
