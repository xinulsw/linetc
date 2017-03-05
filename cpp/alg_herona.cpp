/*
 *  Algorytm Herona lub metoda Newtona-Raphsona:
 *  – wyszukiwanie pierwiastka metoda przybliżeń
 */
#include <iostream>
#include <cmath>

using namespace std;

double pierwiastek(double x, double d) {
	double a = x;
	while (a-(x/a) > d) {
		a = (a + (x/a)) / 2;
	}
	return a;
}

int main() {
	cout << "Program oblicza pierwiastek kwadratowy z liczby rzeczywistej x ";
	cout << "z zadaną dokładnością:" << endl;
	double x;
	double d;
	
	cout << "Podaj liczbę i dokładność: " << endl;
	cin >> x >> d;
	cout << "Pierwiastek z x=" << x << " wynosi: " << pierwiastek(x,d) << endl;
	cout << "Pierwiastek z x=" << x << " wynosi: " << sqrt(x) << endl;
	return 0;
}
