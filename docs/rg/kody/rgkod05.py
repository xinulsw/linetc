# jeżeli obok są przeciwnicy, atakuj
# wersja oparta na zbiorach

sasiednie = set(rg.locs_around(self.location)) - zablokowane
sasiednie_wrogowie = sasiednie & wrogowie

# 9 to średni poziom uszkodzeń
if sasiednie_wrogowie:
    if 9*len(sasiednie_wrogowie) >= self.hp:
        pass
    else:
        ruch = ['attack', sasiednie_wrogowie.pop()]
