# zwróć z podanego zbioru pól (bots) pole najbliższe podanego celu (loc)
# wersja wykorzystująca zbiory pól i operacje na zbiorach

# poniżej wstaw definicje potrzebnych zbiorów

def mindist(bots, loc):
    return min(bots, key=lambda x: rg.dist(x, loc))

if self.location in wejscia:
    if bezpieczne:
        move = ['move', mindist(bezpieczne, rg.CENTER_POINT)]
