#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Implementacja klasycznego szyfru Cezara
# <eCG>

"""
    ZADANIE
    Pobierz od użytkownika ciąg znaków, zaszyfruj go przy wykorzystaniu
    szyfru Cezara o kluczu podanym przez użytkownika,
    wyświetl zaszyfrowany ciąg. Następnie zdeszyfruj go
    i ponownie wyświetl wynik operacji.
"""


def szyfruj(tekst, klucz):
    szyfrogram = ""
    for znak in tekst:
        znak = znak.lower()
        if znak == ' ':
            pass
        elif ord(znak) + klucz > 122:
            znak = chr(ord(znak) + klucz - 26)
        else:
            znak = chr(ord(znak) + klucz)
        szyfrogram += znak
    return szyfrogram


def deszyfruj(szyfrogram, klucz):
    tekst = ""
    for znak in szyfrogram:
        if znak == ' ':
            pass
        elif ord(znak) - klucz < 97:
            znak = chr(ord(znak) - klucz + 26)
        else:
            znak = chr(ord(znak) - klucz)
        tekst += znak
    return tekst


def main(args):
    tekst = raw_input("Podaj tekst do zaszyfrowania:\n")
    try:
        klucz = int(raw_input("Podaj klucz:\n"))
        klucz = klucz % 26
        szyfrogram = szyfruj(tekst, klucz)
        deszyfr = deszyfruj(szyfrogram, klucz)
        assert deszyfr == tekst.lower()
        print "Szyfrogram:\n", szyfrogram
        print "Deszyfracja:\n", deszyfr
    except ValueError:
        print "Błędny klucz!"
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))


"""
    JAK TO DZIAŁA
    try ... except to konstrukcja która przechwytuje błędy: w bloku try
    użytkownik może wprowadzić niewłaściwy klucz, np. literę, wtedy wykona się
    kod w bloku except.
    def nazwa_funkcji(argumenty): – tak definiujemy funkcje
    return zmienna – instrukcja zwraca wartość przypisaną zmiennej
    nazwa_funkcji(argumenty) – tak wywołujemy funkcje.
    Napisy mogą być indeksowane (od 0), co daje dostęp do pojedynczych znaków.
    Funkcja len(str) zwraca długość napisu, wykorzystana jako argument funkcji
    range() pozwala iterować po znakach napisu.
    Operator += oznacza dodanie argumentu z prawej strony do wartości z lewej.
"""
