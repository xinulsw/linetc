# jeżeli wokół są przeciwnicy, atakuj, ale tylko wtedy kiedy nie grozi ci śmierć
# wersja wykorzystująca zbiory pól i operacje na zbiorach

# wszystkie pola
wszystkie = {(x, y) for x in xrange(19) for y in xrange(19)}

# pola zablokowane (obstacle)
zablokowane = {loc for loc in wszystkie if 'obstacle' in rg.loc_types(loc)}

# pola sąsiednie
sasiednie = set(rg.locs_around(self.location)) - zablokowane

# pola zajęte przez nasze roboty
druzyna = {loc for loc in game.robots if game.robots[loc].player_id == self.player_id}

# pola zajęte przez wrogów
wrogowie = set(game.robots) - druzyna

# pola sąsiednie zajęte przez wrogów
sasiednie_wrogowie = sasiednie & wrogowie

# 9 to średni poziom uszkodzeń
if sasiednie_wrogowie:
    if 9*len(sasiednie_wrogowie) < self.hp:
        return ['attack', sasiednie_wrogowie.pop()]
