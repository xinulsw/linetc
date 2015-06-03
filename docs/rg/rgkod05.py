# jeżeli obok są przeciwnicy, atakuj
# wersja oparta na zbiorach
sasiednie = set(rg.locs_around(self.location)) - zablokowane
sasiednie_wrogowie = sasiednie & wrogowie

if sasiednie_wrogowie:
    ruch = ['attack', sasiednie_wrogowie.pop()]
