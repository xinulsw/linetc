#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Obliczanie silni metodą iteracyjną i rekurencyjną
# <eCG>


def sil_rek(n):
    if n == 0:
        return 1
    return sil_rek(n - 1) * n


def sil_iter(n):
    wynik = 1
    for i in range(1, n + 1):
        wynik = wynik * i
    return wynik


def main(args):
    n = int(raw_input("Podaj liczbę: "))
    print "sil_iter(%s) = %s" % (n, sil_iter(n))
    print "sil_rek(%s) = %s" % (n, sil_rek(n))
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
