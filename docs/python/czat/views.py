# -*- coding: utf-8 -*-
# czat/czat/views.py

# from django.http import HttpResponse
from django.shortcuts import render
from django.views.generic.edit import CreateView
from czat.models import Wiadomosc
from django.utils import timezone
from django.views.generic.edit import UpdateView


def index(request):
    """Strona główna aplikacji."""
    # return HttpResponse("Witaj w aplikacji Czat!")
    return render(request, 'czat/index.html')


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
