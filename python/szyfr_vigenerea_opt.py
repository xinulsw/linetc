#!/usr/bin/env python
# -*- coding: utf-8 -*-


def szyfruj_vigenere(tekst, klucz):
    szyfrogram = ''
    i = 0
    for litera in tekst:
        if i > len(klucz) - 1:
            i = 0
        wartosc3 = ord(litera.upper()) + ord(klucz[i].upper()) - 64
        if wartosc3 > 90:
            wartosc3 -= 26
        szyfrogram += chr(wartosc3)
        i += 1
    return szyfrogram


def main(args):
    tekst = raw_input("Podaj tekst: ")
    klucz = raw_input("Podaj klucz: ")
    print(szyfruj_vigenere(tekst, klucz))
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
