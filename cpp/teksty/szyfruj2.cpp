#include <cstdlib>
#include <iostream>

using namespace std;
// A-Z = ASCII 65-90; a-z = ASCII 97-122; a-A = 32;
void szyfruj(char tekst[], int klucz)
{
  int i = 0;
  klucz = klucz%26;	// przesuniêcie znaku o ca³kowit¹ wielokrotnoœæ 26 nie zmienia kodowanego znaku!
  while (tekst[i]!='\0')
  {
    if ((int)tekst[i]>122-klucz) // ograniczenie, aby nie przekroczyæ zakresu 122 w ASCII
      tekst[i] = (char)((int)tekst[i]+klucz-26); 
    else
      tekst[i] = (char)((int)tekst[i]+klucz);
    i++;
  }
}

void deszyfruj(char tekst[], int klucz)
{
  int i = 0;
  klucz = klucz%26;
  while (tekst[i]!='\0')
  {
    if ((int)tekst[i]-klucz<97)
      tekst[i] = (char)((int)tekst[i]-klucz+26);
    else
      tekst[i] = (char)((int)tekst[i]-klucz);
    i++;
  }
}

int main(int argc, char *argv[])
{
  char a[50];
  int klucz;
  cout << "Podaj klucz (dla szyfr CEZARA wpisz 3): ";
  cin >> klucz;
  cout << "TEKST DO ZASZYFROWANIA:   ";
  cin >> a;
  cout << "TEKST ZASZYFROWANY:       ";
  szyfruj(a,klucz);
  cout << a << endl;
  cout << "TEKST ODSZYFROWANY:       ";
//  cin >> a;
  deszyfruj(a,klucz);
  cout << a << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
