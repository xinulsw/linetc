#! /usr/bin/env python
# -*- coding: utf-8 -*-

import random

try:
    ileliczb = int(raw_input("Podaj ilość typowanych liczb: "))
    maksliczba = int(raw_input("Podaj maksymalną losowaną liczbę: "))
except ValueError:
    print "Błędne dane!"
    exit()

liczby = []
i = 0
while i < int(ileliczb):
    liczba = random.randint(1, int(maksliczba))
    if liczby.count(liczba) == 0:
        liczby.append(liczba)
        i = i + 1

for i in range(3):
    print "Wytypuj",ileliczb,"z",maksliczba," liczb: "
    typy = set()
    i = 0
    while i < int(ileliczb):
        try:
            typ = int(raw_input("Podaj liczbę "+str(i+1)+": "))
        except ValueError:
            print "Błędne dane!"
            exit()

        if typ not in typy:
            typy.add(typ)
            i = i + 1

    trafione = set(liczby) & typy
    if trafione:
        print "Ilość trafień: ",len(trafione)
        print "Trafione liczby: ",trafione
    else:
        print "Brak trafień. Spróbuj jeszcze raz!"

    print
    print "x"*40 # wydrukuj 40 znaków x
    print

print "Wylosowane liczby:",liczby
