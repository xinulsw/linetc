# funkcja znajdująca najsłabszego wroga obok
def minhp(bots):
    return min(bots, key=lambda x: game.robots[x].hp)

elif sasiednie_wrogowie:
    if 9*len(sasiednie_wrogowie) < self.hp:
        ruch = stoj('attack',minhp(sasiednie_wrogowie.pop()))
