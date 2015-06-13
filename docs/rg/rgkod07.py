# wersja oparta na zbiorach

# wyznacz bezpieczne sąsiednie pola
bezpieczne = sasiednie - sasiednie_wrogowie - sasiednie_wrogowie2 - wejscia - druzyna

# zwróć z podanego zbioru pól (bots) pole najbliższe podanego celu (loc)
# wstaw pod definicjami zbiorów
def mindist(bots, poz):
    return min(bots, key=lambda x: rg.dist(x, poz))

# idź do środka bezpiecznie i szybko
if self.location in wejscia:
    if bezpieczne:
        ruch = ['move',  mindist(bezpieczne, rg.CENTER_POINT)]
