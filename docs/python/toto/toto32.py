#! /usr/bin/env python
# -*- coding: utf-8 -*-

from totomodul import ustawienia, losujliczby, pobierztypy, czytaj, zapisz

# program główny

# ustalamy trudność gry
ileliczb, maksliczba, ilerazy = ustawienia()

# losujemy liczby
liczby = losujliczby(ileliczb, maksliczba)

# pobieramy typy użytkownika i sprawdzamy, ile liczb trafił
for i in range(ilerazy):
    typy = pobierztypy(ileliczb, maksliczba)
    trafione = wyniki(set(liczby), typy)

print "Wylosowane liczby:",liczby

import time

nick = raw_input("\nPodaj swój nick: ")
nazwapliku = nick + ".json"

losowania = czytaj(nazwapliku)

losowania.append({
    "czas": time.time(),
    "dane": (ileliczb, maksliczba),
    "wylosowane": liczby,
    "ile": trafione
})

zapisz(nazwapliku, losowania)

print "\n",losowania
