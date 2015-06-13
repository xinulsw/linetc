#! /usr/bin/env python
# -*- coding: utf-8 -*-

import rg

class Robot:

    def act(self, game):

        wszystkie = {(x, y) for x in xrange(19) for y in xrange(19)}
        wejscia = {poz for poz in wszystkie if 'spawn' in rg.loc_types(poz)}
        zablokowane = {poz for poz in wszystkie if 'obstacle' in rg.loc_types(poz)}
        druzyna = {poz for poz in game.robots if game.robots[poz].player_id == self.player_id}
        wrogowie = set(game.robots) - druzyna
        sasiednie = set(rg.locs_around(self.location)) - zablokowane
        sasiednie_wrogowie = sasiednie & wrogowie

        # działanie domyślne:
        ruch = ['move', rg.toward(self.location, rg.CENTER_POINT)]

        if self.location in wejscia:
            ruch = ['move',  rg.toward(self.location, rg.CENTER_POINT)]

        if self.location == rg.CENTER_POINT:
            ruch = ['guard']

        if sasiednie_wrogowie:
            if 9*len(sasiednie_wrogowie) >= self.hp:
                pass
            else:
                ruch = ['attack', sasiednie_wrogowie.pop()]

        return ruch
