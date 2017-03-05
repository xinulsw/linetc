#include <cstdlib>
#include <iostream>

// n! = 1 dla n={0,1}
// n! = 1*...*n dla N+-{1}
double silnia_it(int n) {
	double silnia = 1;
	for (int i=2; i<n+1; i++)
		silnia = silnia*i;
	return silnia;
}

// n! = 1					dla n=0
// n! = (n-1)! * n dla n=N
double silnia_re(int n) {
	if (n==0)
		return 1;
	else
		return silnia_re(n-1)*n;
}

int main(int argc, char *argv[]) {
	int n;
// -------- SILNIA
	cout << "Obliczanie silni liczby naturalnej: podaj liczbę" << endl;
	cin >> n;
	cout << "Silnia wynosi (it): " << silnia_it(n) << endl;
	cout << "Silnia wynosi (re): " << silnia_re(n) << endl;
	cout << endl;
	return 0;
}
