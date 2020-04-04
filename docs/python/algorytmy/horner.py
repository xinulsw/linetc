#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Program oblicza wartość wielomianu n-stopnia przy użyciu schematu Hornera.
# <eCG>


def horner_it(tabwsp, x, stopien):
    wartosc = tabwsp[0]
    for i in range(1, stopien + 1):
        print(wartosc, tabwsp[i])
        wartosc = wartosc * x + tabwsp[i]
        print(wartosc)
    return wartosc


def horner_re(tabwsp, x, stopien):
    if (stopien == 0):
        return tabwsp[0]
    else:
        return horner_re(tabwsp, x, stopien - 1) * x + tabwsp[stopien]


def main(args):
    stopien = int(input("Podaj stopień: "))
    tabwsp = []  # pusta lista
    print("Podaj współczynniki: ")
    for i in range(stopien + 1):
        liczba = input(
            "Podaj współczynnik przy potędze {}: ".format(stopien - i))
        tabwsp.append(float(liczba))
    x = float(input("Podj argument: "))

    for i in range(stopien + 1):
        print(str(int(tabwsp[i])) + 'x^' + str(stopien-i) + '+', end='')
    print (tabwsp, x)
    print ("Wartość:", horner_it(tabwsp, x, stopien))
    print ("Wartość:", horner_re(tabwsp, x, stopien))

    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
