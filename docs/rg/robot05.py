#! /usr/bin/env python
# -*- coding: utf-8 -*-

import rg

class Robot:

    def act(self, game):

        # wyznaczamy zbiory różnych pól na planszy
        wszystkie = {(x, y) for x in xrange(19) for y in xrange(19)}
        wejscia = {loc for loc in wszystkie if 'spawn' in rg.loc_types(loc)}
        zablokowane = {loc for loc in wszystkie if 'obstacle' in rg.loc_types(loc)}
        druzyna = {loc for loc in game.robots if game.robots[loc].player_id == self.player_id}
        wrogowie = set(game.robots) - druzyna
        sasiednie = set(rg.locs_around(self.location)) - zablokowane
        sasiednie_wrogowie = sasiednie & wrogowie

        ruch = ['move', rg.toward(self.location, rg.CENTER_POINT)]

        if self.location in wejscia:
            ruch = ['move',  rg.toward(self.location, rg.CENTER_POINT)]

        if self.location == rg.CENTER_POINT:
            ruch = ['guard']

        if sasiednie_wrogowie:
            ruch = ['attack', sasiednie_wrogowie.pop()]

        return ruch
