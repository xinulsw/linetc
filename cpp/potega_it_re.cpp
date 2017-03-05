#include <cstdlib>
#include <iostream>

using namespace std;

// a0 = 1 dla a=/0
// a1 = 1
// an = a*...*a(n-czynników) dla n zaw N+ - {1}
float potega_it(float x, int n) {
	float wynik = 1;
	for (int i=0; i<n; i++)
		wynik = wynik*x;
	return wynik;
}

// a0 = 1				dla a roznego od 0
// an = a(n-1)*a dla n=N+						//rekurencyjna definicja potegowania
float potega_re(float x, int n) {
	if (n==0)
		return 1;
	else
		return potega_re(x,n-1)*x;
}
int main(int argc, char *argv[]) {
	int x=0;
	float n=0;
 // -------- POTEGA
	cout << "Obliczanie potęgi o wykładniku naturalnym: podaj liczbę i potęgę..." << endl;
	while (x<1 || n<1) {
		cin >> x;
		cin >> n;
		if (x<1) cout << "Błędna podstawa... Wprowadź większą od zera." << endl;
		if (n<1) cout << "Błędna potęga... Wprowadź większą od zera." << endl;
	}
	cout << "Potęga wynosi (it): " << potega_it(x,n) << endl;
	cout << "Potęga wynosi (re): " << potega_re(x,n) << endl;
	cout << endl;
	return 0;
}
