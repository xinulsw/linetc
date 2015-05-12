# zbiór sąsiednich pól, na które można wejść bez ryzyka
# wersja wykorzystująca zbiory pól i operacje na zbiorach

# poniżej wstaw definicje potrzebnych zbiorów

sasiednie = set(rg.locs_around(self.location)) - zablokowane
sasiednie_wrogowie = sasiednie & wrogowie
sasiednie_wrogowie2 = {loc for loc in sasiednie if (set(rg.locs_around(loc)) & wrogowie)} - druzyna
bezpieczne = sasiednie - sasiednie_wrogowie - sasiednie_wrogowie2 - wejscia - druzyna
