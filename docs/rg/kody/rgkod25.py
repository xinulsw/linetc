# unikaj nierównych starć

# wersja 1
elif wrogowie_obok:
    if 9*len(wrogowie_obok) < self.hp and len(wrogowie_obok) == 1:
        ruch = stoj('attack',minhp(wrogowie_obok.pop()))
    elif bezpieczne:
        ruch = ruszaj(mindist(bezpieczne, rg.CENTER_POINT))
    else:
        ruch = stoj('suicide')

# wersja 2
elif wrogowie_obok:
    if 9*len(wrogowie_obok) >= self.hp:
        if bezpieczne:
            ruch = ruszaj(mindist(bezpieczne, rg.CENTER_POINT))
        else:
            ruch = stoj('suicide')
    elif len(wrogowie_obok) > 1:
        if bezpieczne:
            ruch = ruszaj(mindist(bezpieczne, rg.CENTER_POINT))
    else:
        ruch = stoj('attack', minhp(wrogowie_obok))
