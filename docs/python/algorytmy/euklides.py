#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Algorytm Euklidesa – znajdowanie najwększego wspólnego dzielnika
# <eCG>


def nwd_klasyczny(a, b):
    while a != b:
        if a > b:
            a -= b
        else:
            b -= a

    return a


def nwd_optymalny(a, b):
    while a > 0:
        a = a % b
        b = b - a

    return b


def main(args):
    a = int(raw_input("Podaj liczbę a: "))
    b = int(raw_input("Podaj liczbę b: "))

    print "Nwd(%, %) klasyczny =", nwd_klasyczny(a, b)
    print "Nwd(%, %) optymalny =", nwd_optymalny(a, b)

    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
