#include <iostream>

using namespace std; // użyj przestrzeni nazw std

int main(int argc, char **argv) {
	int wiek;
	char imie[15];

	cout << "Jak masz na imię? " << endl;
	cin.getline(imie, 15);
	cout << "Hello in the World of C++, " << imie << "!";

	cout << "\nIle masz lat?\n";
	cin >> wiek;
	cout << "Już wiem, masz " << wiek << " lat!" << endl;
	
	if (wiek < 19)
		cout << "Jeszcze się uczysz...";
	else
		cout << "Studiujesz?";

	
	return 0;
}

/*
int - integer, liczby całkowite
char - character, znak
main - nazwa głównej funkcji programu
() - lista argumentów funkcji (danych wejściowych)
{} - blok kodu
std - biblioteka standardowa
*/
