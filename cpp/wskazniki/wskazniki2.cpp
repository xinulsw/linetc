#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>

using namespace std;

void fill(int tab[],int roz,char t,int a,int b) {
  srand(time(NULL));
  switch (t) {
    case 'n':
      for (int i=0; i<roz; i++) tab[i] = rand()%(b+1);
    break;
    case 'c':
      for (int i=0; i<roz; i++) tab[i] = a + rand()%(b-a+1);
    break;
    case 'f':
      for (int i=0; i<roz; i++) tab[i] = a + ((float)rand()/(RAND_MAX))*(b-a);
    break;
    case 'm':
      for (int i=0; i<roz; i++) tab[i] = (double)rand()/(RAND_MAX); //liczba z zakresu <0,1>
    break;
  }
}

void drukuj(int tab[],int roz) {
  for (int i=0; i<roz; i++) cout << tab[i] << " ";
  cout << endl;
}

void drukuja(int tab[], int roz) {
  for (int i=0; i<roz; i++) cout << "[" << &tab[i] << "] " << tab[i] << " ";
  cout << endl;
}

void drukujw(int tab[], int roz) {
  int *wsk;
  wsk = tab;
  for (int i=0; i<roz; i++) {
     cout << "[" << wsk << "] " << *wsk << " ";
     wsk++;
   }
  cout << endl;
  wsk = NULL;
}

void drukujw2(int tab[], int roz) {
	int *wsk;
	wsk = tab; //dlatego, że nazwa tablicy jest (stałym!) wskaźnikiem jej pierwszego elementu
  //można też: wsk = &tab[0];
  // wsk + 3 == &tab[3], *(tab+3) - wskazuj 3 element tablicy tab
  cout << wsk + 3 << endl;
  cout << &tab[3] << endl;
  cout << tab+3 << endl;
  
  cout << *(wsk+3) << endl; //notacja wskaźnik/przesunięcie (pointer/offset)
  cout << wsk [3] << endl; //notacja wskaźnik/indeks (pointer/indeks)

	for (int i=0; i<roz; i++)
		cout << "E" << i << "=" << *(wsk + i) << endl;	
}

void fillw(int tab[],int roz,char t,int a,int b) {
int *wsk;
wsk = tab;
switch (t) {
  case 'n':
    for (int i=0; i<roz; i++) {
      *wsk = rand()%(b+1);
      wsk++;
    }
  break;
  case 'c':
    for (int i=0; i<roz; i++) {
      *wsk = a + rand()%(b-a+1);
      wsk++;
    }
  break;
}
wsk = NULL;
}

void tabWsk() {
	const char *kolory[4] = {"Trefl","Karo","Kier","Pik"}; //tablica wskaźników/tab. napisów
	for (int i=0;i<4;i++) {
		cout << setw(10) << setiosflags(ios::right) << i;
		cout << setiosflags(ios::left) << setw(8) << kolory[i];
		cout << endl;
	}
}

int main(int argc, char *argv[])
{
  int size=5;
  int tab[size];
  //fill(tab,size,'n',0,10);
  //drukuj(tab,size);
  //drukuja(tab,size);
  //fillw(tab,size,'n',0,10);
  //drukujw2(tab,size);
  tabWsk();
  return 0;
}
