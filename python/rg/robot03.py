#! /usr/bin/env python
# -*- coding: utf-8 -*-

import rg

class Robot:

    def act(self, game):

        if self.location == rg.CENTER_POINT:
            return ['guard']

        for loc, bot in game.robots.iteritems():
            if bot.player_id != self.player_id:
                if rg.dist(loc, self.location) <= 1:
                    return ['attack', loc]

        return ['move', rg.toward(self.location, rg.CENTER_POINT)]
