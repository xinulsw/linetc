# -*- coding: utf-8 -*-
from django.contrib import admin

# Register your models here.
from .models import Pizza, Skladnik
from django.forms import Textarea
from django.db import models


class SkladnikInline(admin.TabularInline):
    model = Skladnik
    max_num = 6
    extra = 3
    fields = ['nazwa', 'jarski']


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
        models.TextField: {'widget': Textarea(attrs={'rows': 2, 'cols': 100})},
    }

    def save_model(self, request, obj, form, change):
        if not change:
            obj.autor = request.user
        obj.save()


# rejestrujemy model Pizza w panelu administracyjnym
admin.site.register(Pizza, PizzaAdmin)
