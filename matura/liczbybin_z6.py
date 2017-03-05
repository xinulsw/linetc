#! /usr/bin/env python
# -*- coding: utf-8 -*-

zrodlo = "liczby.txt"
lmax = 0
lmaxb =""

def bin2dec(liczba2, lbdl):
    liczba10 = 0;
    for i, lb in enumerate(liczba2):
        #print lb, 2**(dl-1-i) * ord()
        liczba10 = liczba10 + (2**(lbdl-1-i) * int(lb));

    return liczba10

lp = 0  # liczb parzystych
l9 = 0  # liczb 9-cyfrowych
suma9 = 0  # suma liczb 9-cyfrowych

with open(zrodlo) as f:
    for lb in f:
        lb = lb.replace("\n", "")
        lb = lb.replace("\r", "")
        lbdl = len(lb)  # długość liczby binarnej
        # l = int(lb, 2)  # wartość dziesiętna
        l = bin2dec(lb, lbdl)
        if (l > lmax):  # znajdź największą liczbę
            lmax = l
            lmaxb = lb
        if l % 2 == 0:  # zlicz liczby parzyste
            lp += 1
        if lbdl == 9:
            l9 += 1
            suma9 += l

print "Liczb parzystych:",lp
print "Największa:", lmaxb, lmax
print "9-cyfrowych:", l9
