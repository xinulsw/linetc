# jeżeli w odległości 2 kroków jest przeciwnik, atakuj
# wersja oparta na zbiorach

sasiednie_wrogowie2 = {poz for poz in sasiednie if (set(rg.locs_around(poz)) & wrogowie)} - druzyna

if sasiednie_wrogowie2:
    ruch = ['attack', sasiednie_wrogowie2.pop()]
