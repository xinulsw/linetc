#! /usr/bin/env python
# -*- coding: utf-8 -*-

from totomodul import trudnosc, losujliczby, pobierztypy

# program główny

# ustalamy trudność gry
ileliczb, maksliczba = trudnosc()

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

import os
nazwapliku = "lotek.json"
nick = raw_input("Podaj swój nick: ")
if os.path.isfile(nazwapliku):
    plik = open(nazwapliku, "r")

#losowanie = time.time(), liczby, maksliczba
#zapisz(losowanie)
