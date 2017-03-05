#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>

using namespace std;
/*
	Program demonstruje użycie strumieni wejścia i wyjścia.
 */
int main(int argc, char *argv[]) {
	char nazwa[100]; //deklaracja tablicy znakowej na nazwę pliku
	cout << "Podaj nazwę pliku tekstowego: ";
	cin >> nazwa; //pobranie nazwy pliku
	/* wywołanie funkcji operujących
	 * na pliku
	*/
	liczZnaki(nazwa);
	czytajSlowa(nazwa);
	cout << "Podaj nazwę pliku z danymi: ";
	cin >> nazwa;
	/* sumowanie extra */
	sumuj(nazwa);
	return 0;
}
