# ze zbioru bezpieczne wyłączamy wybrane_pola
bezpieczne = sasiednie - wrogowie_obok - wrogowie_obok2 - \
             wejscia - przyjaciele - wybrane_pola

# stosujemy nowy kod w regułach atakowania wrogów
elif wrogowie_obok2 and self.location not in wybrane_pola:

# zdecyduj, czy zapamiętujesz wszystkie czy tylko niektóre wybrane ruchy

# ruch = ['move', mindist(bezpieczne, rg.CENTER_POINT)]
ruch = ruszaj(mindist(bezpieczne, rg.CENTER_POINT))

# zamiast: ruch = ['attack', wrogowie_obok.pop()]
ruch = stoj('attack',wrogowie_obok.pop())

# zamiast: ruch = ['move', mindist(bezpieczne, najblizszy_wrog)]
ruch = ruszaj(mindist(bezpieczne, najblizszy_wrog))
