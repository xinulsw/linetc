# przed klasą Robot:

runda_numer = 0 # numer rundy
wybrane_pola = set() # zbiór wybranych w rundzie pól

# na początku metody Robot.act:
# wyzeruj zbiór wybrane_pola przy pierwszym robocie w rundzie
global runda_numer, wybrane_pola
if game.turn != runda_numer:
    runda_numer = game.turn
    wybrane_pola = set()
