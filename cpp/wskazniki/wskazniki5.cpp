#include <iostream>
#include <cstdio>

using namespace std;

void zmien1(int x) {//operuje na kopii
      x = x + 10;
}

void zmien2(int *x) {//operuje bezpośrednio na zmiennej
      *x = *x + 10;
}

void zmien3(int &x) {
   x = x + 10;
}
int main(int argc, char *argv[]) {
   //int i = 13;
   //int *wsk1; //deklaracja wskaźnika
/*
   zmien1(i);
   cout << i << endl;
   zmien2(&i);
   cout << i << endl;
   zmien3(i);
   cout << i << endl;
*/   
//   int tab[3] = {3,5,2};
//   
//   cout << tab << endl;
//   cout << *(tab+1) << tab[1] << endl;

//char *kolory[4] = {"trefl","karo","kier","pik"};
//cout << kolory[1] << endl;

char napis1[6]="abcde";
char napis2[5]="";

/*
   cout << "Adres zmiennej i to: " << &i << endl;
   wsk1 = &i; //inicjacja wskaźnika adresem zmiennej
   cout << "Wartość wskaźnika to: " << wsk1 << endl;
   cout << "Wskaźnik wskauzje wartość int: " << *wsk1 << endl;
   cout << "Wartość zmiennej i to: " << i << endl;

   *wsk1 = i + 5;
   cout << endl << i;
   return 0;

   int j = 10;
   wsk1 = &j;
   cout << endl << *wsk1;
*/
//   int *wsk2;
//  wsk2 = &j;
//   int a = 0;
//   cout << "Wartość a: " << a << endl;
//   a = *wsk1 + *wsk2;
//   cout << "Wartość a: " << a << endl;
//   *wsk1 = *wsk1 + 3;
//   cout << i << endl;
   
//   *wsk2 = *wsk1;
//   cout << j << endl;
   
//   wsk2 = wsk1;
//   cout << *wsk1 << "==" << *wsk2 << endl;

//   i = 10;
//   zmien1(i); //przekazanie kopii
//   cout << i << endl;
//  zmien2(&i);//przekazanie referencji
//   cout << i << endl;
   
   //return 0;
}
