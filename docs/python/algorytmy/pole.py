#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Obliczanie pola obszaru ograniczoneg wykresem funkcji:
# y = x^2, prostymi x = a, x = b i osią OX
# (oznaczona całka Riemanna)
# <eCG>


def funkcja(x):
    return x * x


def pole(a, b, n):
    p = 0  # wyliczane pole
    d = (b - a) / n  # długość przedziałów w zakresie <a;b>
    for i in range(n):
        x = a + (d * i) + (d / 2)  # punkty pośrednie przedziałów
        p += abs(funkcja(x))  # suma pól prostokątów
    return p


def main(args):
    a = int(raw_input("Podaj lewy kraniec: "))
    b = int(raw_input("Podaj prawy kraniec: "))
    n = int(raw_input("Podaj liczbę przedziałów: "))
    print "Pole: {:.3f}".format(pole(a, b, n))
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
