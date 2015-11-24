# -*- coding: utf-8 -*-
# czat/czat/views.py

from django.http import HttpResponse


def index(request):
    """Widok dla strony głównej aplikacji."""
    return HttpResponse("Witaj w aplikacji Czat!")
