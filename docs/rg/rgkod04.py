# opuść punkt wejścia jak najszybciej
# wersja wykorzystująca zbiory pól i operacje na zbiorach

# poniżej wstaw definicje potrzebnych zbiorów

wejscia = {loc for loc in wszystkie if 'spawn' in rg.loc_types(loc)}

if self.location in wejscia:
    move = ['move',  rg.toward(self.location, rg.CENTER_POINT)]
