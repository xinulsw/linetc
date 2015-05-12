# zwróć z podanego zbioru pól (bots) pole najbliższe podanego celu (loc)

def mindist(bots, loc):
    return min(bots, key=lambda x: rg.dist(x, loc))
