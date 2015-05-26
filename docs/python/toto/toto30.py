#! /usr/bin/env python
# -*- coding: utf-8 -*-

import random

def losujliczby(ileliczb, maksliczba):
    """Funkcja losuje podaną ilość unikalnych liczb
    z zakresu od 1 do maksliczba"""
    liczby = []
    i = 0
    while i < ileliczb:
        liczba = random.randint(1, maksliczba)
        if liczby.count(liczba) == 0:
            liczby.append(liczba)
            i = i + 1
    return liczby


def pobierztypy(ileliczb, maksliczba):
    """Funkcja pobiera od użytkonika jego typy wylosowanych liczb"""
    print "Wytypuj",ileliczb,"z",maksliczba," liczb: "
    typy = set()
    i = 0
    while i < ileliczb:
        try:
            typ = int(raw_input("Podaj liczbę "+str(i+1)+": "))
        except ValueError:
            print "Błędne dane!"
            continue

        if typ not in typy:
            typy.add(typ)
            i = i + 1
    return typy

# pobieramy wstępne dane
try:
    ileliczb = int(raw_input("Podaj ilość typowanych liczb: "))
    maksliczba = int(raw_input("Podaj maksymalną losowaną liczbę: "))
    if ileliczb > maksliczba:
        print "Błędne dane!"
        exit()
except:
    print "Błędne dane!"
    exit()

# losujemy liczby
liczby = losujliczby(ileliczb, maksliczba)

# trzy razy pobieramy typy użytkownika i sprawdzamy, ile liczb trafił
for i in range(3):
    typy = pobierztypy(ileliczb, maksliczba)
    trafione = set(liczby) & typy
    if trafione:
        print "\nIlość trafień: ",len(trafione)
        print "Trafione liczby: ",trafione
    else:
        print "Brak trafień. Spróbuj jeszcze raz!"

    print "\n"+"x"*40+"\n" # wydrukuj 40 znaków x

print "Wylosowane liczby:",liczby
