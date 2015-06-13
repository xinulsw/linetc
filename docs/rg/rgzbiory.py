# wyznaczamy zbiory różnych pól na planszy

# wszystkie pola na planszy jako współrzędne (x, y)
wszystkie = {(x, y) for x in xrange(19) for y in xrange(19)}

# punkty wejścia (spawn)
wejscia = {poz for poz in wszystkie if 'spawn' in rg.loc_types(poz)}

# pola zablokowane (obstacle)
zablokowane = {poz for poz in wszystkie if 'obstacle' in rg.loc_types(poz)}

# pola zajęte przez nasze roboty
druzyna = {poz for poz in game.robots if game.robots[poz].player_id == self.player_id}

# pola zajęte przez wrogów
wrogowie = set(game.robots) - druzyna
