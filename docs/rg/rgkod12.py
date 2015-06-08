# zapamiętaj wybrane pola w zbiorze wykonane_ruchy
# dzięki któremu możemy unikać kolizji z własnymi botami

# poniższe definicje umieszczamy przed klasą Robot jako globalne

runda_numer = 0
wybrane_pola = set()

# poniższy kod umieszczamy wewnątrz metody Robot.act, na początku:

# wyzeruj zbiór wybrane_pola przy pierwszym robocie w rundzie
global runda_numer, wybrane_pola
if game.turn != runda_numer:
    runda_numer = game.turn
    wybrane_pola = set()

# jeżeli się ruszamy, zapisujemy docelowe pole
def ruszaj(loc):
    wybrane_pola.add(loc)
    return ['move', loc]

# jeżeli stoimy, zapisujemy zajmowane miejsce
def stoj(act, loc=None):
    wybrane_pola.add(self.location)
    return [act, loc]

# Uwaga: ze zbioru bezpieczne wyłączamy wybrane_pola

        bezpieczne = sasiednie - sasiednie_wrogowie - sasiednie_wrogowie2 - wejscia - druzyna - wybrane_pola

# stosujemy nowy kod w regułach atakowania wrogów

elif sasiednie_wrogowie2 and self.location not in wybrane_pola:
    #ruch = ['attack', sasiednie_wrogowie2.pop()]
    if sasiednie_wrogowie:
        ruch = stoj('attack',sasiednie_wrogowie.pop())
elif bezpieczne:
    #ruch = ['move', mindist(bezpieczne, najblizszy_wrog)]
    ruch = ruszaj(mindist(bezpieczne, najblizszy_wrog))
