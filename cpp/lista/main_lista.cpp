#include <iostream>
#include "lista.h"

int main(){
  Lista lista;
  for(int i = 1; i <= 5; i++){
    lista.Dodaj(i);
  }
  lista.Wyswietl();
  lista.Wstaw(0, 2);
  lista.Wyswietl();
  lista.Usun(2);
  lista.Wyswietl();
  return 0;
}
