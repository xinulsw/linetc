#include <iostream>

using namespace std;

void lower(char tekst[]) {
/*
* Funkcja zamienia duże litery na małe
*/
  int i = 0;
  while (tekst[i]!='\0') {
    if (tekst[i] == ' ') ;
    else if ((int)tekst[i] > 64 && (int)tekst[i] < 90)
      tekst[i] = (char)((int)tekst[i] + 32);
    i++;
  }
}


// A-Z = ASCII 65-90; a-z = ASCII 97-122; a-A = 32;
void szyfruj(char tekst[], int klucz) {
  int i = 0;
  klucz = klucz % 26;	// przesuniecie znaku o calkowita wielokrotnosc 26 nie zmienia kodowanego znaku!
  while (tekst[i]!='\0') {
    if (tekst[i] == ' ') ;
    else if ((int)tekst[i] + klucz > 122) // ograniczenie, aby nie przekroczyc zakresu 122 w ASCII
      tekst[i] = (char)((int)tekst[i] + klucz - 26);
    else
      tekst[i] = (char)((int)tekst[i] + klucz);
    i++;
  }
}

void deszyfruj(char tekst[], int klucz) {
  int i = 0;
  klucz = klucz%26;
  while (tekst[i]!='\0') {
    if (tekst[i] == ' ') ;
    else if ((int)tekst[i] - klucz < 97)
      tekst[i] = (char)((int)tekst[i] - klucz + 26);
    else
      tekst[i] = (char)((int)tekst[i] - klucz);
    i++;
  }
}

int main(int argc, char *argv[]) {
  #define MAKS 100
  char tekst[MAKS];
  int klucz;
  cout << "Podaj tekst: " << endl;
  cin.getline(tekst, MAKS);
  lower(tekst);
  cout << "Podaj klucz: ";
  cin >> klucz;
  szyfruj(tekst, klucz);
  cout << "Szyfrogram:" << endl << tekst << endl;
  deszyfruj(tekst, klucz);
  cout << "Deszyfr:" << endl << tekst << endl;
  // getchar();
  return 0;
}
