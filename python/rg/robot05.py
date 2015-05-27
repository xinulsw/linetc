import rg

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

        # domyślne działanie robota: ruch do środka
        ruch = ['move', rg.toward(self.location, rg.CENTER_POINT)]

        # jeżeli jesteś w punkcie wejscia, idź do środka
        if self.location in wejscia:
            ruch = ['move',  rg.toward(self.location, rg.CENTER_POINT)]

        # jeżeli jesteś w środku, broń się w miejscu
        if self.location == rg.CENTER_POINT:
            ruch = ['guard']

        # jeżeli wokół są przeciwnicy i nie zginiesz, atakuj
        sasiednie = set(rg.locs_around(self.location)) - zablokowane
        sasiednie_wrogowie = sasiednie & wrogowie

        if sasiednie_wrogowie:
            if 9*len(sasiednie_wrogowie) < self.hp:
                return ['attack', sasiednie_wrogowie.pop()]

        return ruch
