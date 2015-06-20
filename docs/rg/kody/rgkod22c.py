# ze zbioru bezpieczne wyłączamy wybrane_pola
bezpieczne = sasiednie - sasiednie_wrogowie - sasiednie_wrogowie2 - \
             wejscia - druzyna - wybrane_pola

# stosujemy nowy kod w regułach atakowania wrogów
elif sasiednie_wrogowie2 and self.location not in wybrane_pola:

# zdecyduj, czy zapamiętujesz wszystkie czy tylko niektóre wybrane ruchy

# ruch = ['move', mindist(bezpieczne, rg.CENTER_POINT)]
ruch = ruszaj(mindist(bezpieczne, rg.CENTER_POINT))

# zamiast: ruch = ['attack', sasiednie_wrogowie.pop()]
ruch = stoj('attack',sasiednie_wrogowie.pop())

# zamiast: ruch = ['move', mindist(bezpieczne, najblizszy_wrog)]
ruch = ruszaj(mindist(bezpieczne, najblizszy_wrog))
