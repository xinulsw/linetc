#include <iostream>
#include "stos.h"

using namespace std;

int main(int argc, char *argv[]) {
  Stos stos;
  stos.Push(1);
  stos.Push(2);
  stos.Push(3);
  stos.Push(4);
  cout << "Na stos wrzucono elementy 1, 2, 3, 4" << endl;
  int wartosc = stos.Pop();
  cout << "Operacja Pop zwróciła element: " << wartosc << endl;

  cout << "Pozostałe elementy stosu: " << endl;
  while(!stos.Pusty()){
    int wartosc = stos.Pop();
    cout << wartosc << endl;
  }

  cout << endl;
  Lista lista;
  lista.Dodaj(1);
  lista.Dodaj(2);
  lista.Dodaj(3);
  lista.Dodaj(4);
  lista.Wyswietl();
  return 0;
}
