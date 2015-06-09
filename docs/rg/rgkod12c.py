# ze zbioru bezpieczne wyłączamy wybrane_pola
bezpieczne = sasiednie - sasiednie_wrogowie - sasiednie_wrogowie2 - \
             wejscia - druzyna - wybrane_pola

# stosujemy nowy kod w regułach atakowania wrogów
elif sasiednie_wrogowie2 and self.location not in wybrane_pola:

# zamiast: ruch = ['attack', sasiednie_wrogowie.pop()]
ruch = stoj('attack',sasiednie_wrogowie.pop())

# zamiast: ruch = ['move', mindist(bezpieczne, najblizszy_wrog)]
ruch = ruszaj(mindist(bezpieczne, najblizszy_wrog))
