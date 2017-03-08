#!/usr/bin/env python
# -*- coding: utf-8 -*-


def szyfruj(tekst, klucz):
    i = 0
    for l1 in tekst:
        print ord(l1) - 96
        if i > len(klucz) - 1:
            i = 0
        print ord(klucz[i]) - 96
        znak = (ord(l1) - 96 + ord(klucz[i]) - 96)
        if znak > 26:
            znak -= 26
        print znak
        i += 1


def main(args):
    tekst = raw_input("Podaj tekst: ")
    klucz = raw_input("Podaj klucz: ")
    szyfruj(tekst, klucz)
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
