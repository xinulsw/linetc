import rg

class Robot:

    def act(self, game):
        # jeżeli jesteś w środku, broń się w miejscu
        if self.location == rg.CENTER_POINT:
            return ['guard']

        # idź do środka planszy
        return ['move', rg.toward(self.location, rg.CENTER_POINT)]
