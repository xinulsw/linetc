#! /usr/bin/env python
# -*- coding: utf-8 -*-

import random

ileliczb = raw_input("Podaj ilość typowanych liczb: ")
maksliczba = raw_input("Podaj maksymalną losowaną liczbę: ")
#print "Wytypuj",ileliczb,"z",makliczba," liczb: "

liczby = []
i = 0
while i < int(ileliczb):
    liczba = random.randint(1, int(maksliczba))
    if liczby.count(liczba) == 0:
        liczby.append(liczba)
        i = i + 1

print "Wylosowane liczby:",liczby
