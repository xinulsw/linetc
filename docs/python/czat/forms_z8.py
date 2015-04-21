# -*- coding: utf-8 -*-

from django.forms import ModelForm, TextInput
from czat.models import Wiadomosc

class AktualizujWiadomoscForm(ModelForm):
    class Meta:
        model = Wiadomosc
        fields = ['tekst', 'data_pub']
        exclude = ['autor']
        widgets = {'tekst': TextInput(attrs={'size': 80})}
