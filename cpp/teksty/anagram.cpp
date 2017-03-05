#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

void drukujwstecz(char tab[], int rozmiar) {
	for (int i=rozmiar-1; i>-1; i--)
		cout << tab[i];
	cout << endl;
}

void drukujwstecz2(char tab[], int rozmiar) {
	bool ok = false;
	for (int i=rozmiar-1; i>-1; i--) {
		if (tab[i] != '\0' && ok == false) continue;//pomiń pozostałe instrukcjje i kontynuuj działanie pętli od początku
		else {
			cout << tab[i];
			ok = true;
		}
	}
	cout << endl;
}

/*
 * Funkcja drukuje tablicę znakową w odwrotnej kolejności
 * za pomocą znanej długości wprowadzonego tekstu (strlen)
*/
void drukujz(char tab[], int rozmiar) {
	for (int i=rozmiar; i>-1; i--) {
		cout << tab[i];
	}
	cout << endl;
}

/*
 * Funkcja drukuje tablicę znakową w odwrotnej kolejności
 * za pomocą znaku specjalnego \0
*/
void drukujz2(char tab[], int rozmiar) {
	bool ok = false;
	for (int i=rozmiar; i>-1; i--) {
		if (tab[i] != '\0' && ok == false) continue;
		else {
			ok = true;
			cout << tab[i];
		}
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	int roz = 11;//rozmiar tab o 1 większy
	char tab[roz];
	cout << "Jak się nazywasz? ";
	cin.getline(tab,roz);
	//cin >> tab;
	int ileznakow=0;
	ileznakow = strlen(tab);
	cout << "Wprowadzono " << ileznakow << " znaków." << endl;
	drukujz(tab,ileznakow);
	drukujz2(tab,roz);
	//drukujwstecz(tab,ileznakow);
	//drukujwstecz2(tab,roz);
	return 0;
}
/*
 * 		if (tab[i] != '\0') cout << tab[i];
		else break;//przerwanie działania pętli
*/
