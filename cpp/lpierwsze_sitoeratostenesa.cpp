#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;
// SITO ERATOSTENESA
int main(int argc, char *argv[]) {
	int i, j, zakres, b;
	bool tablica[100];
	cout << "Podaj górny zakres, max 99" << endl;
	cin >> zakres;
	b = sqrt((float)zakres);
	for (i=2; i<zakres+1; i++)
		tablica[i] = true; 		// 1
	for (i=2; i<=b; i++)
	if (tablica[i]!=false)
		for (j=i+i; j<zakres+1; j=j+i)
			tablica[j] = false;			// 2
	cout << "Liczby pierwsze z zakresu od 1 do " << zakres << " to:" << endl;
	for (i=2; i<zakres+1; i++)
		if (tablica[i]!=false)				// 3
			cout << i << "	";
	cout << endl << endl;

	return 0;
}
