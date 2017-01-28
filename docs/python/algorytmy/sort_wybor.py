#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Sortowanie przez wybór
# <eCG>


from random import randint


def sort_wybor(lista):
    n = len(lista)
    for i in range(n):
        k = i
        for j in range(i + 1, n):
            if lista[j] < lista[k]:
                k = j
        # pythonowy składnia dla zamiany wartości
        lista[i], lista[k] = lista[k], lista[i]

    return lista


def main(args):
    lista = []
    for i in range(10):
        lista.append(randint(0, 100))
    print lista
    print sort_wybor(lista)


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
