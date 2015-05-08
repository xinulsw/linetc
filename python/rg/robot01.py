import rg

class Robot:

    def act(self, game):
        # move toward the center
        return ['move', rg.toward(self.location, rg.CENTER_POINT)]
