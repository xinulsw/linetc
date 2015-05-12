#! /usr/bin/env python
# -*- coding: utf-8 -*-

import rg

class Robot:
    def act(self, game):
        wszystkie = {(x, y) for x in xrange(19) for y in xrange(19)}
        wejscia = {loc for loc in wszystkie if 'spawn' in rg.loc_types(loc)}
        zablokowane = {loc for loc in wszystkie if 'obstacle' in rg.loc_types(loc)}
        druzyna = {loc for loc in game.robots if game.robots[loc].player_id == self.player_id}
        wrogowie = set(game.robots)-druzyna

        sasiednie = set(rg.locs_around(self.location)) - zablokowane
        sasiednie_wrogowie = sasiednie & wrogowie
        sasiednie_wrogowie2 = {loc for loc in sasiednie if (set(rg.locs_around(loc)) & wrogowie)} - druzyna
        bezpieczne = sasiednie - sasiednie_wrogowie - sasiednie_wrogowie2 - wejscia - druzyna

        def mindist(bots, loc):
            return min(bots, key=lambda x: rg.dist(x, loc))

        if wrogowie:
            najblizszy_wrog = mindist(wrogowie,self.location)
        else:
            najblizszy_wrog = rg.CENTER_POINT

        # akcja domyślna, którą nadpiszemy, jak znajdziemy coś lepszego
        move = ['guard']

        if self.location in wejscia:
            if bezpieczne:
                move = ['move', mindist(bezpieczne, rg.CENTER_POINT)]
        elif sasiednie_wrogowie:
            if 9*len(sasiednie_wrogowie) >= self.hp:
                if bezpieczne:
                    move = ['move', mindist(bezpieczne, rg.CENTER_POINT)]
            else:
                move = ['attack', sasiednie_wrogowie.pop()]
        elif sasiednie_wrogowie2:
            move = ['attack', sasiednie_wrogowie2.pop()]
        elif bezpieczne:
            move = ['move', mindist(bezpieczne, najblizszy_wrog)]

        return move
