# jeżeli wokół są przeciwnicy, atakuj, jeżeli nie grozi ci śmierć
# wersja wykorzystująca zbiory pól i operacje na zbiorach

# poniżej wstaw definicje potrzebnych zbiorów

# 9 to średni poziom uszkodzeń
if sasiednie_wrogowie:
    if 9*len(sasiednie_wrogowie) < self.hp:
        return ['attack', sasiednie_wrogowie.pop()]
