# unikaj nierównych starć

# wersja 1
elif sasiednie_wrogowie:
    if 9*len(sasiednie_wrogowie) < self.hp and len(sasiednie_wrogowie) == 1:
        ruch = stoj('attack',minhp(sasiednie_wrogowie.pop()))
    elif bezpieczne:
        ruch = ruszaj(mindist(bezpieczne, rg.CENTER_POINT))
    else:
        ruch = stoj('suicide')

# wersja 2
elif sasiednie_wrogowie:
    if 9*len(sasiednie_wrogowie) >= self.hp:
        if bezpieczne:
            ruch = ruszaj(mindist(bezpieczne, rg.CENTER_POINT))
        else:
            ruch = stoj('suicide')
    elif len(sasiednie_wrogowie) > 1:
        if bezpieczne:
            ruch = ruszaj(mindist(bezpieczne, rg.CENTER_POINT))
    else:
        ruch = stoj('attack', minhp(sasiednie_wrogowie))
