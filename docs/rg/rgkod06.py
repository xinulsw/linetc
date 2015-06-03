# jeżeli wokół są przeciwnicy, atakuj, jeżeli nie grozi ci śmierć
# wersja oparta na zbiorach

# 9 to średni poziom uszkodzeń
if sasiednie_wrogowie:
    if 9*len(sasiednie_wrogowie) < self.hp:
        ruch = ['attack', sasiednie_wrogowie.pop()]
