#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

struct osoba {
  char imie[20];
  char nazwisko[20];
  int wiek;
};

struct punkt {
  float wx;
  float wy;
};

struct wektor {
  punkt start;
  punkt end;
};

void getOsoba() {
  osoba uczen;
  cout << "Podaj imię ucznia: ";
  cin >> uczen.imie;
  cout << "Podaj nazwisko ucznia: ";
  cin >> uczen.nazwisko;
  cout << "Podaj wiek ucznia: ";
  cin >> uczen.wiek;
  cout << "Informacje o uczniu: \n";
  cout << uczen.imie << " " << uczen.nazwisko << " " << uczen.wiek << " lat";
  cout << endl;
}

void srodekWektora() {
punkt p;
wektor w;
  cout << "Podaj odciętą początku wektora: "; cin >> w.start.wx;
  cout << "Podaj rzędną początku wektora: "; cin >> w.start.wy;
  cout << "Podaj odciętą końca wektora: "; cin >> w.end.wx;
  cout << "Podaj rzędną końca wektora: "; cin >> w.end.wy;
  p.wx = 0.5 * (w.start.wx + w.end.wx);
  p.wy = 0.5 * (w.start.wy + w.end.wy);
  cout << "Współrzędne środka wektora: " << p.wx << "," << p.wy;
  cout << endl;
}

void drukuj(osoba tb[],int ilu) {
  cout << "\nWprowadzone dane: " << endl;
  for (int i=0; i<ilu; i++) {
    cout << "Uczeń " << (i+1) << " : " << endl;
    cout << "Imię: " << tb[i].imie;
    cout << " Nazwisko: " << tb[i].nazwisko;
    cout << " Wiek: " << tb[i].wiek;
    cout << endl;
  }
  cout << endl;
}

void getOsoby(osoba tb[],int ilu) {
  for (int i=0; i<ilu; i++) {
    cout << "Wprowadź dane " << (i+1) << " ucznia: " << endl;
    cout << "Imię: "; cin >> tb[i].imie;
    cout << "Nazwisko: "; cin >> tb[i].nazwisko;
    cout << "Wiek: "; cin >> tb[i].wiek;
  }
  drukuj(tb,ilu);
}

void zapiszOsoby (osoba tb[],int ilu) {
  ofstream hp;
  hp.open("osoby.txt");
  for (int i; i<ilu; i++) {
    hp << tb[i].imie << " " << tb[i].nazwisko << " " << tb[i].wiek;
  }
  hp.close();
  cout << "Baza zapisana \n";
}

int main(int argc, char *argv[])
{
  //getOsoba();
  //srodekWektora();
  int ilu;
  cout << "Dane ilu uczniów chcesz wprowadzić? "; cin >> ilu;
  osoba tb[ilu];
  getOsoby(tb,ilu);
  zapiszOsoby(tb,ilu);
  return 0;
}
