#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

using namespace std;

void wprowadz(float *tab, int ile) {
   for (int i=0; i<ile; i++) {
      cout << "Podaj liczbę: ";
      cin >> *(tab+i);
      //cin >> tab[i];
   }
}

void wyswietl(float *tab, int ile) {
   for (int i=0; i<ile; i++) {
      cout << *(tab+i) << " ";
   }
   cout << endl;
}

int tab1W() {
   float *tab = NULL;
   int ile;
   
   cout << "Ile podasz liczb? ";
   cin >> ile;
   
   try {
      tab = new float[ile];
   } catch(bad_alloc) {
      cout << "Za mało pamięci!";
      return 1;
   }

   wprowadz(tab,ile);
   wyswietl(tab,ile);
   return 0;
}

int tab2W() {
   int w, k, i, j;
   cout << "Podaj liczbę wierszy i kolumn: ";
   cin >> w >> k;
   int **tab; //deklaracja wskaźnika do wskaxnika typu int;
   try {
      tab = new int *[w];
   } catch(bad_alloc) {
      cout << "Za mało pamięci!";
      return 1;
   }
   
   for (i=0; i<w; i++) {
      try {
         tab[i] = new int[k];
      } catch(bad_alloc) {
         cout << "Za mało pamięci!";
         return 1;
      }
   }
   
   srand(time(NULL));
   
   for (i=0; i<w; i++) {
      for (j=0; j<k; j++) {
         tab[i][j]= rand() % 101;
         cout << setw(5) << tab[i][j];
      }
      cout << endl;
   }
   
   return 0;
}

int main(int argc, char *argv[]) {
   int wynik=0;
   //wynik=tab1W();
   wynik=tab2W();
   return wynik;
}
