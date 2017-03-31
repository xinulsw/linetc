#include <cstdlib>
#include <cstdio>
#include <ioshtream>
#include <iomanip>

using namespace std;

void wypelnij(float *tab, int ile) {
   srand(time(NULL));
   for(int i=0; i<ile; i++) {
      tab[i] = rand() % 101;
   }
}

void drukuj(float *tab, int ile) {
   cout << "Zawartość tablicy:\n";
    for(int i=0; i<ile; i++) {
      cout << setw(4) << tab[i] << " ";
   }
   cout << endl;
}

int tabd_1W() {
   float *tab = NULL;
   int ile;
   
   cout << "Ile podasz liczb? "; cin >>ile;
   
   try {
      tab = new float[ile]; //utworzenie tab. dynamicznej
   } catch(bad_alloc) {
      cout << "Za mało pamięci!"; return 1;
   }
   
   wypelnij(tab,ile);
   drukuj(tab,ile);
   delete [] tab;
   return 0;
}

int tabd_2W() {
   int w, k, i, j;
   srand(time(NULL));
   cout << "Podaj liczbę wierszy i kolumn: "; cin >> w >> k;
   float **tab; //deklaracja wskaźnika do wskaźnika typu float
   try {
      tab = new float *[w];
   } catch(bad_alloc) {
      cout << "Za mało pamięci!"; return 1;
   }
   for (i=0; i<w; i++) {
      try {
         tab[i] = new float[k]; //tworzenie tablic w wierszach
      }  catch(bad_alloc) {
         cout << "Za mało pamięci!"; return 1;
      }
   }
   for (i=0; i<w; i++) {
      for(j=0; j<k; j++) {
         tab[i][j] = rand() % 101;
         cout << setw(4) << tab[i][j];
      }
   }
   cout << endl;
   
   return 0;
}

int main(int argc, char *argv[]) {
   tabd_2W();
   return 0;
}
