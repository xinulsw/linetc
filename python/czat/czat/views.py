# -*- coding: utf-8 -*-
# czat/czat/views.py

from django.http import HttpResponse
from django.shortcuts import render
from django.contrib import messages

def index(request):
    """Strona główna aplikacji."""
    # aby zwrócić prostą wiadomość tekstową wystarczy instrukcja poniżej:
    #return HttpResponse("Witaj w aplikacji Czat!")

    # w słowniku kontekst pod nazwą 'user' przekażemy do szablonu obiekt
    # użytkownika
    kontekst = {'user': request.user}

    # aby zwrócić szablon używamy funkcji render()
    return render(request, 'czat/index.html', kontekst)

from django.shortcuts import redirect
from django.core.urlresolvers import reverse
from django.contrib.auth import authenticate, login, logout

def rejestruj(request):
    """Rejestracja nowego użytkownika."""
    from django.contrib.auth.forms import UserCreationForm

    # użytkownik próbuje się zarejestrować
    if request.method == 'POST':
        # tworzymy formularz wypełniony przesłanymi danymi użytkownika
        form = UserCreationForm(request.POST)

        # sprawdzamy poprawność nadesłanych danych
        if form.is_valid():
            # dane są poprawne, zapisujemy dane nowego użytkownika
            form.save()
            # komunikat dla użytkownika
            messages.success(request, "Zostałeś zarejestrowany.")
            # uwierzytelniamy użytkownika i logujemy go
            user = authenticate(
                    username=form.data['username'],
                    password=form.data['password1'])
            login(request, user)
            messages.success(request, "Zostałeś zalogowany.")
            # przekierowujemy zalogowanego użytkownika na stronę główną
            return redirect(reverse('index'))

    # w słowniku 'kontekst' pod nazwą 'form' przekażemy pusty formularz
    # rejestracji użytkownika do szablonu
    kontekst = {'form': UserCreationForm()}
    # renderujemy szablon rejestracji
    return render(request, 'czat/rejestruj.html', kontekst)

def loguj(request):
    """Logowanie użytkownika"""
    from django.contrib.auth.forms import AuthenticationForm

    # użytkownik próbuje się zalogować
    if request.method == 'POST':
        # tworzymy formularz wypełniony przesłanymi danymi
        form = AuthenticationForm(request, request.POST)
        # sprawdzamy poprawność nadesłanych danych
        if form.is_valid():
            # logujemy użytownika i przygotowujemy komunikat
            login(request, form.get_user())
            messages.success(request, "Zostałeś zalogowany!")
            # przekierowanie na stronę główną
            return redirect(reverse('index'))

    kontekst = {'form': AuthenticationForm()}
    return render(request, 'czat/loguj.html', kontekst)

def wyloguj(request):
    """Wylogowanie użytkownika"""
    # wylogowanie użytkownika, którego dane zapisane są w żądaniu
    logout(request)
    messages.info(request, "Zostałeś wylogowany!")
    return redirect(reverse('index'))


from django.views.generic.edit import CreateView
from czat.models import Wiadomosc
from django.utils import timezone

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


from django.views.generic.edit import UpdateView

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


from django.contrib.auth.decorators import login_required

@login_required(login_url='/loguj')
def wiadomosci(request):
    """Dodawanie i wyświetlanie wiadomości"""

    if request.method == 'POST':
        tekst = request.POST.get('tekst', '')
        if not 0 < len(tekst) <= 250:
            messages.error(request,
            "Wiadomość nie może być pusta, może mieć maks. 250 znaków!")
        else:
            wiadomosc = Wiadomosc(tekst=tekst,
                        data_pub=timezone.now(),
                        autor=request.user)
            wiadomosc.save()
            return redirect(reverse('wiadomosci'))

    wiadomosci = Wiadomosc.objects.all()
    kontekst = {'user': request.user, 'wiadomosci': wiadomosci}
    return render(request, 'czat/wiadomosci.html', kontekst)
