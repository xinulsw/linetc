#! /usr/bin/env python
# -*- coding: utf-8 -*-

import rg

class Robot:

    def act(self, game):

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

#        for loc, bot in game.robots.iteritems():
#            if bot.player_id != self.player_id:
#                if rg.dist(loc, self.location) <= 1:
#                    return ['attack', loc]

        wejscia = {loc for loc in wszystkie if 'spawn' in rg.loc_types(loc)}
        sasiednie = set(rg.locs_around(self.location)) - zablokowane
        sasiednie_wrogowie = sasiednie & wrogowie

        if sasiednie_wrogowie:
            if 9*len(sasiednie_wrogowie) < self.hp:
                return ['attack', sasiednie_wrogowie.pop()]

        if self.location in wejscia:
            move = ['move', rg.toward(self.location, rg.CENTER_POINT)]

        if self.location == rg.CENTER_POINT:
            return ['guard']

        return ['move', rg.toward(self.location, rg.CENTER_POINT)]
