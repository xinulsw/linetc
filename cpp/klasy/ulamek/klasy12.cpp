#include <iostream>
#include <cstdio>
using namespace std;

class Ulamek
{
  int licznik;
  int mianownik;
public:
  void zapisz(int l, int m);
  void wypisz()
  {cout << licznik << "/" << mianownik;}
};					// koniec definicji klasy

void Ulamek::zapisz(int l, int m) // definicja metody klasy
{
  licznik = l;
  if (m!=0)
    mianownik = m;
  else
  {
    cout << "Mianownik nie moze miec wartosci 0 ";
    getchar();
    exit(1);
  }
}
int main()
{
  Ulamek ul1, ul2;
  ul1.zapisz(4,5);
  ul2.zapisz(1,7);
  cout << "Pierwszy ulamek: ";
  ul1.wypisz();
  cout << endl << "Drugi ulamek: ";
  ul2.wypisz();
  getchar();
  return 0;
}