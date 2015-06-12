#! /usr/bin/env python
# -*- coding: utf-8 -*-

import rg

class Robot:

    def act(self, game):

        # wyznaczamy zbiory różnych pól na planszy
        wszystkie = {(x, y) for x in xrange(19) for y in xrange(19)}
        wejscia = {loc for loc in wszystkie if 'spawn' in rg.loc_types(loc)}

        ruch = ['move', rg.toward(self.location, rg.CENTER_POINT)]

        if self.location in wejscia:
            ruch = ['move',  rg.toward(self.location, rg.CENTER_POINT)]

        if self.location == rg.CENTER_POINT:
            ruch = ['guard']

        for loc, bot in game.robots.iteritems():
            if bot.player_id != self.player_id:
                if rg.dist(loc, self.location) <= 1:
                    ruch = ['attack', loc]

        return ruch
