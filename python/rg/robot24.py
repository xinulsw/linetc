#! /usr/bin/env python
# -*- coding: utf-8 -*-

import rg

runda_numer = 0 # numer rundy
wybrane_pola = set() # zbiór wybranych w rundzie pól

class Robot:

    def act(self, game):

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

        # wyznaczamy zbiory różnych pól na planszy
        wszystkie = {(x, y) for x in xrange(19) for y in xrange(19)}
        wejscia = {loc for loc in wszystkie if 'spawn' in rg.loc_types(loc)}
        zablokowane = {loc for loc in wszystkie if 'obstacle' in rg.loc_types(loc)}
        druzyna = {loc for loc in game.robots if game.robots[loc].player_id == self.player_id}
        wrogowie = set(game.robots) - druzyna
        sasiednie = set(rg.locs_around(self.location)) - zablokowane
        sasiednie_wrogowie = sasiednie & wrogowie
        sasiednie_wrogowie2 = {loc for loc in sasiednie if (set(rg.locs_around(loc)) & wrogowie)} - druzyna
        # bezpieczne = sasiednie - sasiednie_wrogowie - sasiednie_wrogowie2 - wejscia - druzyna
        bezpieczne = sasiednie - sasiednie_wrogowie - sasiednie_wrogowie2 - \
                     wejscia - druzyna - wybrane_pola

        def mindist(bots, loc):
            return min(bots, key=lambda x: rg.dist(x, loc))

        def minhp(bots):
            return min(bots, key=lambda x: game.robots[x].hp)

        if wrogowie:
            najblizszy_wrog = mindist(wrogowie,self.location)
        else:
            najblizszy_wrog = rg.CENTER_POINT

        ruch = ['guard']

        if self.location in wejscia:
            if bezpieczne:
                ruch = ['move',  mindist(bezpieczne, rg.CENTER_POINT)]
        elif sasiednie_wrogowie:
            if 9*len(sasiednie_wrogowie) < self.hp:
                ruch = stoj('attack',minhp(sasiednie_wrogowie.pop()))
            elif bezpieczne:
                ruch = ruszaj(mindist(bezpieczne, rg.CENTER_POINT))
            else:
                ruch = stoj('suicide')
        elif sasiednie_wrogowie2 and self.location not in wybrane_pola:
            ruch = ['attack', sasiednie_wrogowie2.pop()]
        elif bezpieczne:
            ruch = ruszaj(mindist(bezpieczne, najblizszy_wrog))


        return ruch
