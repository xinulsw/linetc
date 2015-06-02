# wyznaczamy zbiory różnych pól na planszy

# wszystkie pola
wszystkie = {(x, y) for x in xrange(19) for y in xrange(19)}

# punkty wejścia (spawn)
wejscia = {loc for loc in wszystkie if 'spawn' in rg.loc_types(loc)}

# pola zablokowane (obstacle)
zablokowane = {loc for loc in wszystkie if 'obstacle' in rg.loc_types(loc)}

# pola zajęte przez nasze roboty
druzyna = {loc for loc in game.robots if game.robots[loc].player_id == self.player_id}

# pola zajęte przez wrogów
wrogowie = set(game.robots) - druzyna
