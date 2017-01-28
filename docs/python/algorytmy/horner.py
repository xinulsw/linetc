#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Program oblicza wartość wielomianu 3 stopnia przy użyciu schematu Hornera.
# <eCG>


def horner(tabwsp, x, stopien):
    wartosc = tabwsp[0]
    for i in range(1, 4, 1):
        wartosc = wartosc * x + tabwsp[i]
    return wartosc


def main(args):
    stopien = 3
    tabwsp = []  # pusta lista
    print "Podaj 4 współczynniki: "
    for i in range(stopien + 1):
        liczba = raw_input("Podaj współczynnik: ")
        tabwsp.append(float(liczba))
    x = float(raw_input("Podj argument: "))

    print tabwsp, x
    print "Wartość:", horner(tabwsp, x, stopien)

    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
