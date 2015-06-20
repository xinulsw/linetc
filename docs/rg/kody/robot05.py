#! /usr/bin/env python
# -*- coding: utf-8 -*-

import rg

class Robot:

    def act(self, game):

        wszystkie = {(x, y) for x in xrange(19) for y in xrange(19)}
        wejscia = {poz for poz in wszystkie if 'spawn' in rg.loc_types(poz)}
        zablokowane = {poz for poz in wszystkie if 'obstacle' in rg.loc_types(poz)}
        przyjaciele = {poz for poz in game.robots if game.robots[poz].player_id == self.player_id}
        wrogowie = set(game.robots) - przyjaciele
        sasiednie = set(rg.locs_around(self.location)) - zablokowane
        wrogowie_obok = sasiednie & wrogowie
        wrogowie_obok2 = {poz for poz in sasiednie if (set(rg.locs_around(poz)) & wrogowie)} - przyjaciele
        bezpieczne = sasiednie - wrogowie_obok - wrogowie_obok2 - wejscia - przyjaciele

        def mindist(bots, poz):
            return min(bots, key=lambda x: rg.dist(x, poz))

        # działanie domyślne:
        ruch = ['move', rg.toward(self.location, rg.CENTER_POINT)]

        if self.location in wejscia:
            if bezpieczne:
                ruch = ['move',  mindist(bezpieczne, rg.CENTER_POINT)]

        if self.location == rg.CENTER_POINT:
            ruch = ['guard']

        if wrogowie_obok:
            if 9*len(wrogowie_obok) >= self.hp:
                pass
            else:
                ruch = ['attack', wrogowie_obok.pop()]

        if wrogowie_obok2:
            ruch = ['attack', wrogowie_obok2.pop()]

        return ruch
