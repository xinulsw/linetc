#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

void ascii() {
	for (int i=32;i<127;i++)
		cout << i << "=" << (char)i << " ";
}

void pobierz1 (char tab[]) {
	cin >> tab;
}

void pobierz2 (char tab[]) {
	cin.getline(tab,20);
}
// http://pl.wikipedia.org/wiki/ASCII
// A-Z = ASCII 65-90; a-z = ASCII 97-122; a-A = 32;
void zamiana (char tab[]) {
	int i=0;
	while (tab[i]!='\0') {
		cout << (char)((int)tab[i]-32);
		i++;
	}
}

int main(int argc, char *argv[]) {
	cout << (char)7;
	cout << "i" << (char)8;
	cout << (char)10 << (char)13;
	ascii();
	cout << endl;
	char osoba[20];
	cout << "Przedstaw sie: ";
	pobierz1(osoba);
	cout << "Juz wiem, jestes: " << osoba << endl;
	cin.ignore();
	cout << "Przedstaw sie jeszcze raz: ";
	pobierz2(osoba);
	cout << "Juz wiem, jestes: " << osoba << endl;
	cin.ignore();
	cout << "\nWprowadz tekst malymi literami" << endl;
	pobierz2(osoba);
	cout << "Duzymi literami: ";
	zamiana(osoba);
	cout << endl;
	cin.ignore();
	return 0;
}
