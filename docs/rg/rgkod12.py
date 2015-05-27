# zapamiętaj wybrane ruchy w zbiorze wykonane_ruchy
# dzięki któremu możemy unikać kolizji z własnymi botami

# poniższe definicje umieszczamy przed klasą Robot jako globalne

runda_numer = 0
wybrane_ruchy = set()

# poniższy kod umieszczamy wewnątrz metody Robot.act, na początku:

        global runda_numer, wybrane_ruchy
        if game.turn != runda_numer:
            runda_numer = game.turn
            wybrane_ruchy = set()

        def ruszaj(loc):
            wybrane_ruchy.add(loc)
            return ['move', loc]

        def stoj(act, loc=None):
            wybrane_ruchy.add(self.location)
            return [act, loc]

# poniżej wstaw definicje potrzebnych zbiorów
# Uwaga: ze zbioru bezpieczne wyłączamy wybrane_ruchy

        bezpieczne = sasiednie - sasiednie_wrogowie - sasiednie_wrogowie2 - wejscia - druzyna - wybrane_ruchy

# stosujemy nowy kod w regułach atakowania wrogów
        elif sasiednie_wrogowie2 and self.location not in wybrane_ruchy:
            #ruch = ['attack', sasiednie_wrogowie2.pop()]
            if sasiednie_wrogowie:
                ruch = stoj('attack',sasiednie_wrogowie.pop())
        elif bezpieczne:
            #ruch = ['move', mindist(bezpieczne, najblizszy_wrog)]
            ruch = ruszaj(mindist(bezpieczne, najblizszy_wrog))
