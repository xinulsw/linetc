import rg

rg.settings.max_turns = 2

class Robot:

    def act(self, game):

        # zbiory pól na planszy

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

        sasiednie = set(rg.locs_around(self.location)) - zablokowane
        sasiednie_wrogowie = sasiednie & wrogowie
        sasiednie_wrogowie2 = {loc for loc in sasiednie if (set(rg.locs_around(loc)) & wrogowie)} - druzyna

        bezpieczne = sasiednie - sasiednie_wrogowie - sasiednie_wrogowie2 - wejscia - druzyna

        print wejscia
        # domyślne działanie robota: ruch do środka
        ruch = ['move', rg.toward(self.location, rg.CENTER_POINT)]

        return ruch
