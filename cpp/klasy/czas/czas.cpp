#include <iostream>
#include "czas.h"

using namespace std;

//Czas::Czas() { godz = min = sek = 0 }

Czas::Czas(int g, int m, int s) {
	ustawCzas(g,m,s);
}

void Czas::ustawCzas( int g, int m, int s) {
	godz = (g >= 0 && g < 24) ? g : 0;
	min = (m >= 0 && m < 59) ? m : 0;
	sek = (s >= 0 && s < 59) ? s : 0;
}

void Czas::drukujWojskowy() {
	cout << (godz < 10 ? "0" : "") << godz << ":"
			<< (min < 10 ? "0" : "") << min;
}

void Czas::drukujStandard() {
	cout << ((godz == 0 || godz == 12) ? 12 : godz%12 )
			<< ":" << (min < 10 ? "0" : "") << min
			<< ":" << (sek < 10 ? "0" : "") << sek
			<< (godz < 12 ? " AM" : " PM");
}
