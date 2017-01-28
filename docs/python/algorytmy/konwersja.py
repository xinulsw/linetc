#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Konwersja liczby dziesiętnej na system o podanej podstawie
# <eCG>


def konwertuj(liczba, podst):
    """
    Funkcja konwertuje podaną liczbę dziesiętną na system o podanej podstawie
    wykorzystując dzielenie z resztą, zwraca listę reszt.
    """

    # słownik ze znakami cyfr większych od 9
    cyfry = {10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}
    reszty = []  # pusta lista
    while liczba > 0:
        reszty.append(liczba % podst)
        liczba = liczba / podst

    reszty.reverse()  # odwrócenie elemnetów listy
    if podst > 10:  # zamiana cyfr większych od 9
        reszty = [cyfry[x] if x > 9 else x for x in reszty]
    return reszty
    print "".join(str(x) for x in reszty)


def main(args):
    liczba10 = int(raw_input("Podaj liczbę: "))
    podst = int(raw_input("Podaj podstawę (2-16): "))

    liczbaP = "".join(str(x) for x in konwertuj(liczba10, podst))
    print "Liczba(10):", liczba10
    print "Liczba(%s): %s" % (podst, liczbaP)

    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
