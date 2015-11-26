# -*- coding: utf-8 -*-
# czat/czat/views.py

# from django.http import HttpResponse
from django.shortcuts import render
from django.shortcuts import redirect
from django.core.urlresolvers import reverse
from django.contrib.auth import authenticate, login, logout
from django.contrib import messages
from django.views.generic.edit import CreateView
from czat.models import Wiadomosc
from django.utils import timezone
from django.views.generic.edit import UpdateView


def index(request):
    """Strona główna aplikacji."""
    # return HttpResponse("Witaj w aplikacji Czat!")
    kontekst = {'user': request.user}
    return render(request, 'czat/index.html', kontekst)


def rejestruj(request):
    """Rejestracja nowego użytkownika."""
    from django.contrib.auth.forms import UserCreationForm

    if request.method == 'POST':
        form = UserCreationForm(request.POST)
        if form.is_valid():
            form.save()
            messages.success(request, "Zostałeś zarejestrowany.")
            user = authenticate(
                    username=form.data['username'],
                    password=form.data['password1'])
            login(request, user)
            messages.success(request, "Zostałeś zalogowany.")
            return redirect(reverse('index'))

    kontekst = {'form': UserCreationForm()}
    return render(request, 'czat/rejestruj.html', kontekst)


def loguj(request):
    """Logowanie użytkownika"""
    from django.contrib.auth.forms import AuthenticationForm

    if request.method == 'POST':
        form = AuthenticationForm(request, request.POST)
        if form.is_valid():
            login(request, form.get_user())
            messages.success(request, "Zostałeś zalogowany!")
            return redirect(reverse('index'))

    kontekst = {'form': AuthenticationForm()}
    return render(request, 'czat/loguj.html', kontekst)


def wyloguj(request):
    """Wylogowanie użytkownika"""
    logout(request)
    messages.info(request, "Zostałeś wylogowany!")
    return redirect(reverse('index'))


class UtworzWiadomosc(CreateView):
    model = Wiadomosc
    fields = ['tekst', 'data_pub']
    context_object_name = 'wiadomosci'
    success_url = '/wiadomosc'

    def get_initial(self):
        initial = super(UtworzWiadomosc, self).get_initial()
        initial['data_pub'] = timezone.now()
        return initial

    def get_context_data(self, **kwargs):
        kwargs['wiadomosci'] = Wiadomosc.objects.filter(
                                autor=self.request.user)
        return super(UtworzWiadomosc, self).get_context_data(**kwargs)

    def form_valid(self, form):
        wiadomosc = form.save(commit=False)
        wiadomosc.autor = self.request.user
        wiadomosc.save()
        return super(UtworzWiadomosc, self).form_valid(form)


class AktualizujWiadomosc(UpdateView):
    model = Wiadomosc
    from czat.forms import AktualizujWiadomoscForm
    form_class = AktualizujWiadomoscForm
    context_object_name = 'wiadomosci'
    template_name = 'czat/wiadomosc_form.html'
    success_url = '/wiadomosci'

    def get_context_data(self, **kwargs):
        kwargs['wiadomosci'] = Wiadomosc.objects.filter(
                                autor=self.request.user)
        return super(AktualizujWiadomosc, self).get_context_data(**kwargs)

    def get_object(self, queryset=None):
        wiadomosc = Wiadomosc.objects.get(id=self.kwargs['pk'])
        return wiadomosc
