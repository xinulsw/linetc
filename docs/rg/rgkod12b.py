# zapamiętaj wybrane pola w zbiorze wykonane_ruchy
# dzięki któremu możemy unikać kolizji z własnymi botami
# wewnątrz metody Robot.act, po inicjacji zmiennych:

# jeżeli się ruszamy, zapisujemy docelowe pole
def ruszaj(loc):
    wybrane_pola.add(loc)
    return ['move', loc]

# jeżeli stoimy, zapisujemy zajmowane miejsce
def stoj(act, loc=None):
    wybrane_pola.add(self.location)
    return [act, loc]
