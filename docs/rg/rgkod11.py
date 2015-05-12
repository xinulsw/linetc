# idź bezpiecznie w kierunku najbliższego wroga
# wersja wykorzystująca zbiory pól i operacje na zbiorach

# poniżej wstaw definicje potrzebnych zbiorów

def mindist(bots, loc):
    return min(bots, key=lambda x: rg.dist(x, loc))

if wrogowie:
    najblizszy_wrog = mindist(wrogowie,self.location)
else:
    najblizszy_wrog = rg.CENTER_POINT

if bezpieczne:
    move = ['move', mindist(bezpieczne, najblizszy_wrog)]
