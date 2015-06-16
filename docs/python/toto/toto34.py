#! /usr/bin/env python
# -*- coding: utf-8 -*-

from totomodul32 import ustawienia, losujliczby, pobierztypy, czytaj, zapisz_str, wyniki
import time

# program główny

# ustalamy trudność gry
ileliczb, maksliczba, ilerazy, nick = ustawienia()

nazwapliku = nick + ".txt"
losowania = [] # czytaj(nazwapliku)

# losujemy liczby
liczby = losujliczby(ileliczb, maksliczba)

# pobieramy typy użytkownika i sprawdzamy, ile liczb trafił
for i in range(ilerazy):
    typy = pobierztypy(ileliczb, maksliczba)
    trafione = wyniki(set(liczby), typy)

losowania.append({
    "czas": time.time(),
    "dane": (ileliczb, maksliczba),
    "wylosowane": liczby,
    "ile": trafione
})

print "Wylosowane liczby:",liczby

zapisz_str(nazwapliku, losowania)
