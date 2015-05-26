#! /usr/bin/env python
# -*- coding: utf-8 -*-

import random

def losujliczby(ileliczb, maksliczba):
    liczby = []
    i = 0
    while i < ileliczb:
        liczba = random.randint(1, maksliczba)
        if liczby.count(liczba) == 0:
            liczby.append(liczba)
            i = i + 1
    return liczby


def pobierztypy(ileliczb, maksliczba):
    print "Wytypuj",ileliczb,"z",maksliczba," liczb: "
    typy = set()
    i = 0
    while i < ileliczb:
        try:
            typ = int(raw_input("Podaj liczbę "+str(i+1)+": "))
        except ValueError:
            print "Błędne dane!"
            continue

        if typ not in typy:
            typy.add(typ)
            i = i + 1
    return typy


try:
    ileliczb = int(raw_input("Podaj ilość typowanych liczb: "))
    maksliczba = int(raw_input("Podaj maksymalną losowaną liczbę: "))
    if ileliczb > maksliczba:
        print "Błędne dane!"
        exit()
except:
    print "Błędne dane!"
    exit()

liczby = losujliczby(ileliczb, maksliczba)

for i in range(3):
    typy = pobierztypy(ileliczb, maksliczba)
    trafione = set(liczby) & typy
    if trafione:
        print "Ilość trafień: ",len(trafione)
        print "Trafione liczby: ",trafione
    else:
        print "Brak trafień. Spróbuj jeszcze raz!"

    print
    print "x"*40 # wydrukuj 40 znaków x
    print

print "Wylosowane liczby:",liczby

import os, datetime, time, json

losowanie = time.time(), liczby, maksliczba

def zapisz(losowanie):
    nazwapliku = "lotek.json"
    if os.path.isfile(nazwapliku):
        plik = open(nazwapliku, "a")
    else:
        plik = open(nazwapliku, "w")
    print >>plik, json.dumps(losowanie)

zapisz(losowanie)
