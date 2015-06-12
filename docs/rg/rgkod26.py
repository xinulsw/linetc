# goń najsłabszych wrogów
elif sasiednie_wrogowie:
    ...
    else:
        cel = minhp(sasiednie_wrogowie)
        if game.robots[cel].hp <= 5:
            ruch = ruszaj(cel)
        else:
            ruch = stoj('attack', minhp(sasiednie_wrogowie))
