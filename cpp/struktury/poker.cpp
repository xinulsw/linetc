#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <fstream>

using namespace std;

const int TALIA_SIZE=25;
const int ZESTAW_SIZE=5;

struct karta {
   int figura; //{1,6}
   int kolor; //{1,4}
};

/*
1    {9,1}, {9,2}, {9,3}, {9,4}
5    {10,1}, {10,2}, {10,3}, {10,4}
9    {11,1}, {11,2}, {11,3}, {11,4}
13    {12,1}, {12,2}, {12,3}, {12,4}
17    {13,1}, {13,2}, {13,3}, {13,4}
21    {14,1}, {14,2}, {14,3}, {14,4}

*/

struct talia {
   karta tb[TALIA_SIZE];
   int zestaw1[ZESTAW_SIZE];
   int zestaw2[ZESTAW_SIZE];
};

talia x;
string tb_kolor[5] = {"nic","trefl","karo","kier","pik"};
string tb_figura[7] = {"nic","9","10","W","D","K","A"};

bool inArray(int a) {
	for (int i=0; i<ZESTAW_SIZE; i++)
		if (x.zestaw1[i] == a || x.zestaw2[i] == a) return true;
	return false;
}

int losujKarte() {
	int a;
	do {
		a = 1 + rand() % (TALIA_SIZE - 2);
	} while (inArray(a));
	return a;
}

void losujKarty() {
/*
   wylosuj kartę z talii,
   sprawdź czy nie została wylosowana wcześniej,
   zapisz wylosowany indeks do zestawu y 
*/
	srand(time(NULL));
	for (int i=0; i<ZESTAW_SIZE; i++)
		x.zestaw1[i] = losujKarte();
	for (int i=0; i<ZESTAW_SIZE; i++)
		x.zestaw2[i] = losujKarte();
/*	i = 0;
	do {
		a = 1 + rand() % (TALIA_SIZE - 2);
		if (inArray(a) != true) {
			x.zestaw2[i] = a;
			i++;
		}
	} while (i<ZESTAW_SIZE);
*/
}

void pokazKarte(const talia &x,int i) {
//wydrukuj kartę o indeksie i z talii
   cout << "K" << i << ": ";
   cout << "\t" << tb_figura[x.tb[i].figura] << " " << tb_kolor[x.tb[i].kolor];
   cout << endl;
}

void wypelnijTalie(talia &x) {
//iniciacja tabeli talii kart
   int j=0;
   for (int k=0; k<TALIA_SIZE-1; k+=4) {
		j++;
         for (int i=1; i<5; i++) {
            x.tb[k+i].figura = j;
            x.tb[k+i].kolor = i;
         }
   }
}

void drukujTalie(const talia &x) {
   for (int k=1; k<TALIA_SIZE; k++)
      pokazKarte(x,k);
}

void drukujZestaw(const talia &x, int zestaw) {
	cout << "\nKarty gracza " << zestaw << ": \n";
	for (int i=0; i<ZESTAW_SIZE; i++)
		if (zestaw == 1) pokazKarte(x,x.zestaw1[i]);
		else pokazKarte(x,x.zestaw2[i]);
}

int main(int argc, char *argv[]) {
   wypelnijTalie(x);
   drukujTalie(x);
   losujKarty();
   drukujZestaw(x,1);
   drukujZestaw(x,2);
   return 0;
}
