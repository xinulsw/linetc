#! /usr/bin/env python
# -*- coding: utf-8 -*-

import random

ileliczb = raw_input("Podaj ilość typowanych liczb: ")
zakres = raw_input("Podaj zakres losowanych liczb: ")
#print "Wytypuj",ileliczb,"z",zakres," liczb: "

liczby = []
i = 0
while i < int(ileliczb):
    liczba = random.randint(1, int(zakres))
    if liczby.count(liczba) == 0:
        liczby.append(liczba)
        i = i + 1

print "Wylosowane liczby:",liczby
