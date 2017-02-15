#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Konwersja liczby dziesiętnej na system o podanej podstawie
# <eCG>

cyfry = {10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}
cyfry2 = {v: k for k, v in cyfry.items()}


def do10(liczba, podst):
    """
    Funkcja konwertuje liczbę o podanej podstawie na system dziesiętny
    Liczba konertowana jest na napis
    """
    p = len(str(liczba)) - 1
    liczba10 = 0
    for l in str(liczba):
        if l.isdigit():
            liczba10 += int(l) * podst**p
        else:
            liczba10 += cyfry2[l] * podst**p
        p -= 1
    print liczba10


def konwertuj(liczba, podst):
    """
    Funkcja konwertuje podaną liczbę dziesiętną na system o podanej podstawie
    wykorzystując dzielenie z resztą, zwraca listę reszt.
    """

    global cyfry

    # słownik ze znakami cyfr większych od 9
    reszty = []  # pusta lista
    while liczba > 0:
        reszty.append(liczba % podst)
        liczba = liczba / podst

    reszty.reverse()  # odwrócenie elemnetów listy
    if podst > 10:  # zamiana cyfr większych od 9
        reszty = [cyfry[x] if x > 9 else x for x in reszty]
    return reszty


def main(args):
    liczba = raw_input("Podaj liczbę: ")
    podst = int(raw_input("Podaj podstawę (2-16): "))
    # cel = raw_input("Podaj podstawę systemu docelowego: ")
    do10(liczba, podst)
    # liczbaP = "".join(str(x) for x in konwertuj(int(liczba), podst))
    # print "Liczba(10):", liczba10
    # print "Liczba(%s): %s" % (podst, liczbaP)

    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
