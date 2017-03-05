#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

using namespace std;

int tabd_1W() {
	float *tab = NULL; //deklaracja wskaźnika do typu float
	int ile;
	float liczba;

	cout << "Ile podasz liczb? ";
	cin >> ile;
	try {
		tab = new float[ile]; //próba utworzenia tablicy za pomocą operatora new
	} catch (bad_alloc) {
		cout << "Za mało pamięci!";
		return -1;
	}
	for (int i=0; i<ile; i++) {
		cout << "Podaj liczbę: ";
		cin >> liczba;
		*(tab+i) = liczba; //notacja wskaźnik/przesunięcie
	}
	cout << "Zawartość tablicy: ";
	for (int i=0; i<ile; i++) {
		cout << setw(6) << tab[i]; //notacja wskaźnik/indeks
	}
	delete [] tab; //zwolnienie pamięci	
	return 0;
}

int tabd_2W() {
	int w, k, i, j;
	srand(time(NULL));
	cout << "Podaj liczbę wierszy i kolumn tablicy: ";
	cin >> w >> k;
	int **tab; //deklaracja wskaźnika do wskaźnika typu int;
	try {
		tab = new int *[w]; //tworzenie tablicy wskaźników;
	} catch(bad_alloc) {
		cout << "Za mało pamięci!";
		return -1;
	}
	for (i=0; i<w; i++) {
		try {
			tab[i] = new int[k]; //tworzenie tablic w wierszach
		} catch(bad_alloc) {
			cout << "Za mało pamięci!";
			return -1;
		}
	}
	for (i=0; i<w; i++) {
		for (j=0; j<k; j++) {
			tab[i][j] = rand() % 101;
			cout << setw(4) << tab[i][j];
		}
		cout << endl;
	}
	for (i=0; i<w; i++)
		delete [] tab[i];
	delete [] tab;
	return 0;
}

int main(int argc, char *argv[]) {
	int w;
	w=tabd_2W();
    return w;
}
