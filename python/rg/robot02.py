#! /usr/bin/env python
# -*- coding: utf-8 -*-

import rg

class Robot:

    def act(self, game):
        # zbiory pól na planszy
        wszystkie = {(x, y) for x in xrange(19) for y in xrange(19)}
        wejscia = {loc for loc in wszystkie if 'spawn' in rg.loc_types(loc)}
        zablokowane = {loc for loc in wszystkie if 'obstacle' in rg.loc_types(loc)}
        druzyna = {loc for loc in game.robots if game.robots[loc].player_id == self.player_id}
        wrogowie = set(game.robots)-druzyna

        # jeżeli jesteśmy w środku, bronimy się w miejscu
        if self.location == rg.CENTER_POINT:
            return ['guard']

        # jeżeli wokół są przeciwnicy, atakuj
        for loc, bot in game.robots.iteritems():
            if bot.player_id != self.player_id:
                if rg.dist(loc, self.location) <= 1:
                    return ['attack', loc]

        # idź do środka planszy
        return ['move', rg.toward(self.location, rg.CENTER_POINT)]
