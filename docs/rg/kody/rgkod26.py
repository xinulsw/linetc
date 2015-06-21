# goń najsłabszych wrogów
elif wrogowie_obok:
    ...
    else:
        cel = minhp(wrogowie_obok)
        if game.robots[cel].hp <= 5:
            ruch = ruszaj(cel)
        else:
            ruch = stoj('attack', minhp(wrogowie_obok))
