# -*- coding: utf-8 -*-
# czat/czat/views.py

#from django.http import HttpResponse
from django.shortcuts import render
from django.shortcuts import redirect
from django.core.urlresolvers import reverse
from django.contrib.auth import authenticate, login, logout
from django.contrib import messages


def index(request):
    """Strona główna aplikacji."""
    # return HttpResponse("Witaj w aplikacji Czat!")
    return render(request, 'czat/index.html')


def rejestruj(request):
    """Rejestracja nowego użytkownika."""

    from django.contrib.auth.forms import UserCreationForm

    kontekst = {'form': UserCreationForm()}
    return render(request, 'czat/rejestruj.html', kontekst)
