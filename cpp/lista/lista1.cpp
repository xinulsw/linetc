#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct elem_listy {
  int liczba;        //dane przechowywane w el. listy
  elem_listy *nast;  //wskaźnik do następnego elementu listy
};

int main(int argc, char *argv[]) {
   elem_listy *glowa = NULL; //tworzymy listę pustą
   elem_listy *nowy;

   char odp;
   int d;
   
   cout << "Czy dodasz element do listy? (t/n) ";
   cin >> odp;
   while (odp != 'n') {
         cout << "Podaj liczbę: ";
         cin >> d;
         
         try {
            nowy = new elem_listy;
         } catch (bad_alloc) {
            cout << "Brak pamięci!";
            break;
         }
         
         nowy->nast = glowa;
         nowy->liczba = d;
         
         glowa = nowy;
         
         cout << "Czy dodasz kolejny element? (t/n) ";
         cin >> odp;
   }
   
   elem_listy *tmp = glowa;
   cout << "Oto lista: " << endl;
   while (tmp != NULL) {
      cout << tmp->liczba << " ";
      tmp = tmp->nast;
   }
   
   return 0;
}
