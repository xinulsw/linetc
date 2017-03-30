#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class ulamek {
private:
  int licznik;
  int mianownik;
  void skracaj();
public:
  ulamek() {// definicja pierwszego konstruktora
    licznik = 1;
    mianownik = 1;
  }

  ulamek(int l, int m); // deklaracja drugiego konstruktora

  void wypisz() {
    cout << licznik << "/" << mianownik;
    skracaj();
    cout << " (skracanie) " << licznik << "/" << mianownik << endl;
  }

  friend ulamek pomnoz(ulamek, ulamek); // deklaracja przyjazni
}; // koniec definicji klasy

void ulamek::skracaj() {
  int a = licznik;
  int b = mianownik;
  while (a>0) {
    a = a % b;
    b = b - a;
  }
  licznik = licznik/b;
  mianownik = mianownik/b;
}

ulamek::ulamek(int l, int m) {
  licznik = l;
  if (m!=0) mianownik = m;
  else {
    cout << "Mianownik nie może mieć wartości zero ";
  }
  cout << "Utworzono obiekt: " << licznik << "/" << mianownik << endl;
}

ulamek pomnoz(ulamek u1, ulamek u2) {// funkcja mnożąca ułamki
  cout << u1.licznik << "/" << u1.mianownik << " * " << u2.licznik << "/" << u2.mianownik << " = ";
  ulamek wynik;
  wynik.licznik = u1.licznik*u2.licznik;
  wynik.mianownik = u1.mianownik*u2.mianownik;
  return wynik;					// wynikiem funkcji jest obiekt klasy ułamek
}

int main() {
  int l, m;
  cout << "Podaj licznik i mianownik pierwszego ułamka" << endl;
  cin >> l >> m;
  ulamek a(l,m);
  cout << "Podaj licznik i mianownik drugiego ułamka" << endl;
  cin >> l >> m;
  ulamek b(l,m);
  cout << "Pierwszy ułamek: ";
  a.wypisz();
  cout << endl << "Drugi ułamek: ";
  b.wypisz();
  cout << endl << "Iloczyn ";
  pomnoz(a,b).wypisz();
  cin.ignore();

  return 0;
}
