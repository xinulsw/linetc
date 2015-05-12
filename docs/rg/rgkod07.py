# jeżeli w odległości 2 kroków jest przeciwnik, atakuj
# wersja wykorzystująca zbiory pól i operacje na zbiorach

# poniżej wstaw definicje potrzebnych zbiorów

sasiednie = set(rg.locs_around(self.location)) - zablokowane
sasiednie_wrogowie2 = {loc for loc in sasiednie if (set(rg.locs_around(loc)) & wrogowie)} - druzyna

if sasiednie_wrogowie2:
    return ['attack', sasiednie_wrogowie2.pop()]
