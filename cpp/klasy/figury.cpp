#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>

using namespace std;

class Figura {
public:
	Figura(char figura); //konstruktor
	void getNazwa(); //wyświetl nazwę figury
   char getTyp(); //zwraca typ figury
	void getPole(); //wyświetl pole figury
	void getObwod(); //wyświetl obwod figury
private:
	char typ;
	char nazwa[15];
	float pole;
	float obwod;
	void setTyp(char figura);
};

Figura::Figura(char figura) {
	setTyp(figura);
	cout << "Utworzono: ";
	getNazwa();
	cout << endl;
}

void Figura::setTyp(char figura) {
	switch (figura) {
		case 'k': strcpy(nazwa,"kwadrat"); typ = figura; break;
		case 'p': strcpy(nazwa,"prostokąt"); typ = figura; break;
		case 't': strcpy(nazwa,"trójkąt"); typ = figura; break;
		case 'o': strcpy(nazwa,"koło"); typ = figura; break;
		default:
			cout << "Nieznany typ figury!";
			strcpy(nazwa,"kwadrat"); typ = 'k';
	}
}

char Figura::getTyp() {
	return typ;
}

void Figura::getNazwa() {
	cout << nazwa;
}

void Figura::getPole() {
   cout << pole;
}

void Figura::getObwod() {
   cout << obwod;
}

int main(int argc, char *argv[]) {
	char odp;
	cout << "Wybierz figurę: " << endl;
	cout << " k - kwadrat\n";
	cout << " p - prostokąt\n";
	cout << " t - trójkąt\n";
	cout << " o - koło\n";
	cout << " x - koniec\n";
	cin >> odp;
	Figura figura(odp);
	return 0;
}
