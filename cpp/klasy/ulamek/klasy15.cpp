#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

class Ulamek{
private:
  int licznik;
  int mianownik;
  void skracaj();

public:
  Ulamek(){ // definicja pierwszego konstruktora
    licznik = 1;
    mianownik = 1;
  }
  Ulamek(int l, int m); // deklaracja drugiego konstruktora
  void wypisz(){
    skracaj(); 
    cout << licznik << "/" << mianownik;
  }
  friend Ulamek pomnoz(Ulamek, Ulamek); // deklaracja przyjazni
}; // koniec definicji klasy

void Ulamek::skracaj(){
  int a = abs(licznik);
  int b = abs(mianownik);
  while (a!=b)
    if (a>0)
      a = a-b;
    else
     b = b-a;
  licznik = licznik/a;
  mianownik = mianownik/a;
}

Ulamek::Ulamek(int l, int m){
  licznik = l;
  if (m!=0)
    mianownik = m;
  else{
    cout << "Mianownik nie moze miec wartosci zero ";
    getchar();
    exit(1);
  }
}

Ulamek pomnoz(Ulamek u1, Ulamek u2){ // funkcja mnożąca ułamki
  Ulamek wynik;
  wynik.licznik = u1.licznik*u2.licznik;
  wynik.mianownik = u1.mianownik*u2.mianownik;
  return wynik; // wynikiem funkcji jest obiekt klasy Ulamek
}

int main() {
  int l, m;
  cout << "Podaj licznik i mianownik pierwszego ulamka" << endl;
  cin >> l >> m;
  Ulamek a(l,m);
  cout << "Podaj licznik i mianownik drugiego ulamka" << endl;
  cin >> l >> m;
  Ulamek b(l,m);
  cout << "Pierwszy ulamek: ";
  a.wypisz();
  cout << endl << "Drugi ulamek: ";
  b.wypisz();
  cout << endl << "Iloczyn ";
  a.wypisz();
  cout << " i ";
  b.wypisz();
  cout << " wynosi ";
  pomnoz(a,b).wypisz();
  cin.ignore();
  getchar();
  return 0;
}
