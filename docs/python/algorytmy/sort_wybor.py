#! /usr/bin/env python
# -*- coding: utf-8 -*-

from random import randint


def zamien(lista, i, k):
    tmp = lista[i]
    lista[i] = lista[k]
    lista[k] = tmp
    return lista


def sort_wybor(lista):
    n = len(lista)
    for i in range(n):
        k = i
        for j in range(i + 1, n):
            if lista[j] < lista[k]:
                k = j
        # print k, "=>", i
        tmp = lista[i]
        lista[i] = lista[k]
        lista[k] = tmp
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
