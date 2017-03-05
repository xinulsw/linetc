#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char **argv) {
	//deklaracja zmiennych
	float P = 0; //pole kwadratu
	cout << "Podaj wartość pola kwadratu: " << endl;
	cin >> P; //pobierz pole od użytkownika
	
	if (P <= 0) {
		cout << "Pole musi być wartością dodatnią.";
	} else {
		cout << "Bok kwadratu wynosi: " << sqrt(P) << endl;
	}
	
	return 0;
}
