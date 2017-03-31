#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct el_listy {
   int liczba;
   el_listy *nast;
};

char czy() {
   char odp;
   cout << "Następny? (t/n)";
   cin >> odp;
   return odp;
}

int getDane() {
   int d;
   cout << "Podaj liczbę: ";
   cin >> d;
   return d;
}

void drukuj(el_listy *glowa) {
   el_listy *tmp;
   tmp = glowa;
   while (tmp != NULL) {
      cout << tmp->liczba << " ";
      tmp = tmp->nast;
   }
   cout << endl;
}

int addToB() {
   el_listy *glowa = NULL;
   el_listy *ogon = NULL;
   el_listy *nowy;
   
   while(czy() != 'n') {
      try {
         nowy = new el_listy; //tworzenie nowego el. listy
      } catch(bad_alloc) {
         cout << "Za mało!";
         return 1;
      }
      nowy->liczba = getDane();
      nowy->nast=NULL;
      if (glowa == NULL) {//lista nie ma elementów
         glowa = nowy; //wykona się tylko raz;
         ogon = glowa;
      } else {
         ogon->nast = nowy;
         ogon = nowy;
      }
   }
   
   drukuj(glowa);
   
   return 0;
}

int main(int argc, char *argv[]) {
   int wynik=0;
   wynik=addToB();
   return wynik;
}
