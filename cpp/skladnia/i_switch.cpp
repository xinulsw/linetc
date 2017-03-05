#include <cstdlib>
#include <iostream>

using namespace std;

void _switch1(int lekcja) {
	switch (lekcja) {
		case 1: cout << "Masz matematyke"; break;
		case 2: cout << "Masz biologie"; break;
		case 3: cout << "Masz polski"; break;
		case 4: cout << "Masz historie"; break;
		case 5: cout << "Masz wf"; break;
		default: cout << "Jestes po lekcjach!!!"; break;
	}
	cout << endl;
}

void _switch2(int lekcja) {
	cout << "\nZostaly ci jeszce lekcje: " << endl;
	switch (lekcja) {
		case 1: cout << "matematyka\n";
		case 2: cout << "biologia\n";
		case 3: cout << "polski\n";
		case 4: cout << "historia\n";
		case 5: cout << "wf\n"; break;
		default: cout << "Jestes po lekcjach!!!\n";
	}
}

void najmniejsza (int a, int b, int c) {
	cout << "Najmniejsza liczba: ";
	if (a<b)
		if (a<c) cout << a;
		else cout << c;
	else
		if (c<b) cout << c;
		else cout << b;
	cout << endl;
}

void _for1 (int a, int b) {
	int i=0;
	for (i=a; i<b; i++) {
		cout << i;
		if (i%3!=0) cout << " - nie jest podzielna przez 3";
		cout << endl;
	}
}

void _while1(int a, int b) {
int k=0; // zmienna pomocnicza
	if (b==0) {
		cout << "Nie dzielimy przez 0!" << endl;
		return;
	} else {
		while (a>=b) {
			a=a-b;
			k++;
		}
		cout << "a/b wynosi " << k << endl;
	}
}

void _dowhile1() {
	float bok;
	do {
		cout << "Podaj dodatnia dlugosc boku\n";
		cin >> bok;
		if (bok<=0) cout << "Dlugosc niepoprawna - sprobuj jeszcze raz!\n\n";
	} while (bok<=0);
	cout << "Pole kwadratu wynosi: " << bok*bok << endl;
}

int main(int argc, char *argv[]) {
	int a,b,c;
	cout << "[Instrukcja if - else (if)]\n[Najmniejsza wprowadzona liczba calkowita]\n\n";
	cout << "Wprowadz trzy liczby:\n";
	cin >> a >> b >> c;
	najmniejsza(a,b,c);

	int lekcja;
	cout << "\n\n[Instrukcji wyboru switch - case - (break)]\n";		
	cout << "Ktora godzina lekcyjna sie zaczela?\n";
	cin >> lekcja;
	_switch1(lekcja);
	_switch2(lekcja);

	cout << "\n\n[Instrukcja petli for]\n[Liczby podzielne przez 3]\n\n";
	cout << "Podaj dwie liczby calkowite wieksze od zera:\n";
	cin >> a >> b;
	_for1(a, b);

	cout << "\n\n[Instrukcja petli while]\n[Dzielenie dwoch liczb calkowitych]\n\n";
	cout << "Podaj dzielna i dzielnik\n";
	cin >> a >> b;
	_while1(a,b);
	
	cout << "\n\n[Instrukcja do...while]\n[Oblicznie pola kwadratu]\n\n";
	_dowhile1();
	
	cout << endl;

	return 0;
}
