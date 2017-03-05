#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct uczen {
  char imie[10];
  char nazwisko[30];
  float srednia;
};

int main(int argc, char *argv[])
{
    uczen tab[3];
    uczen *wsk;
    wsk = tab;
    for (int i=0; i<3; i++) {
      cout << "Podaj imie: ";
      cin >> wsk->imie;
      cout << "Podaj nazwisko: ";
      cin >> wsk->nazwisko;
      cout << "Podaj średnią: ";
      cin >> wsk->srednia;
      wsk++;
    }
  wsk = tab;
  cout << "Best of the best: " << endl;
  for (int i=0; i<3; i++) {
    cout << wsk->imie << " ";
    cout << wsk->nazwisko << " ";
    cout << wsk->srednia << endl;
    wsk++;
  }
    return 0;
}
