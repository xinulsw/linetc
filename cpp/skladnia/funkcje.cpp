#include <iostream>
#include <cmath>

using namespace std;

void _switch(int b) {
	switch (b) {
		case 1: cout << "Masz informatykę"; break;
		case 2: cout << "Masz niemiecki"; break;
		case 3: cout << "Masz polski"; break;
		case 4: cout << "Masz angilelski"; break;
		case 5: cout << "Masz religię"; break;
		default: cout << "Jesteś po lekcjach!";
	}
}

void drukuj(char znak, int ile) {
	for (int i=0; i<ile; i++) {
		if (i%10 == 0) cout << endl;
		cout << znak;
		if (i>1000) break;
	}
	cout << endl;
}

int main() {
//	int lekcja=0;
//	cout << "Którą masz lekcję? "; cin >> lekcja;
//	_switch(lekcja);
	
	char znaczek;
	int ile;
	cout << "Podaj znaczek: "; cin >> znaczek;
	cout << "Ile razy? "; cin >> ile;
	drukuj(znaczek,ile);
	
	return 0;
}
