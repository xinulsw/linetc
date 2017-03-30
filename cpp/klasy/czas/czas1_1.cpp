// Przykład użycia klasy Czas
#include <iostream>
#include <cstdio>

using namespace std;

class Czas {
public:
	Czas(); //konstruktor
	void ustawCzas( int, int, int);	//ustawia godz., min, i sek.
	void drukujWojskowy();				//wyświetla czas w formacie wojskowym
	void drukujStandard();				//wyświetla czas w formacie standardowym
private:
	int godz;	//0-23
	int min;		//0-59
	int sek;		//0-59
};

//Konstruktor inicjuje składowe wartością 0
Czas::Czas () { godz = min = sek = 0; }

//Ustawia wartości składowych
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

int main(int argc, char *argv[]) {
	Czas t;
	cout << "Czas początkowy w f. wojskowym: " << endl;
	t.drukujWojskowy();
	cout << "\nCzas początkowy w f. standardowym: " << endl;
	t.drukujStandard();
	return 0;
}
