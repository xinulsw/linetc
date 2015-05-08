# jeżeli wokół są przeciwnicy, atakuj
for loc, bot in game.robots.iteritems():
    if bot.player_id != self.player_id:
        if rg.dist(loc, self.location) <= 1:
            return ['attack', loc]
