#! /usr/bin/env python
# -*- coding: utf-8 -*-

import rg

class Robot:

    def act(self, game):
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
