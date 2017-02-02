#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Obliczanie wartości pierwiastka kwadratowego z podanej liczby
# przy użyciu metody Herona: a(n) = (a(n-1) + x / a(n-1)) / 2
# <eCG>


def pierwiastek(x, d):
    a = x  # inicjalizacja szkuanej wartości
    while abs(a - (x / a)) > d:
        a = (a + (x / a)) / 2
    return a


def main(args):
    # liczba dla której szukamy pierwiastka
    x = float(raw_input("Podaj liczbę: "))
    # dokładność obliczeń
    d = float(raw_input("Podaj dokładność: "))
    # drukujemy wynik z dokładnością do 6 miejsc
    print "Pierwiastek kwadratowy: {:.6f}".format(pierwiastek(x, d))
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
