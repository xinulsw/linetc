# jeżeli wokół są przeciwnicy, atakuj
# wersja wykorzystująca zbiory pól i operacje na zbiorach

# poniżej wstaw definicje potrzebnych zbiorów

sasiednie = set(rg.locs_around(self.location)) - zablokowane
sasiednie_wrogowie = sasiednie & wrogowie

if sasiednie_wrogowie:
    return ['attack', sasiednie_wrogowie.pop()]
