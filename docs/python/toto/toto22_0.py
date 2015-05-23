#! /usr/bin/env python
# -*- coding: utf-8 -*-

import random

ileliczb = raw_input("Podaj ilość typowanych liczb: ")
maksliczba = raw_input("Podaj maksymalną losowaną liczbę: ")
#print "Wytypuj",ileliczb,"z",makliczba," liczb: "

liczby = []
for i in range(int(ileliczb)):
    liczba = random.randint(1, int(maksliczba))
    liczby.append(liczba)

print "Wylosowane liczby:",liczby
