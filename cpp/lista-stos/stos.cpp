#include "stos.h"

void Stos::Push(int value){
  lista.Dodaj(value);
}

int Stos::Pop(){
  return lista.Usun();
}

bool Stos::Pusty(){
  return lista.Pusta();
}
