#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

void konwersja1(int x, int podstawa) {
	int tab[8],i=0;
	do {
		tab[i] = x%podstawa;
		x = x/podstawa;
		i++;
	} while (x!=0);

	while (i>0) {
		i--;
		cout << tab[i];
	}
}

void zamiana1() {
	int liczba,podstawa = 0;
	cout << "Podaj liczbe dziesietna: ";
	cin >> liczba;
	do {
		cout << "Podaj podstawe: ";
		cin >> podstawa;
	} while (podstawa < 2 || podstawa > 9);
	cout << "Wynik konwersji: " << liczba << "[10] = ";
	konwersja1(liczba,podstawa);
	cout << "[" << podstawa << "]" << endl;
}

int konwersja2(int tab[], int ile, int podstawa) {
	int i,j,k;
	int liczba10=0;
	for (j=0; j<ile; j++){
		i=1;
		for (k=j+1; k<ile; k++) i=i*podstawa;
		liczba10 += tab[j]*i;
	}
	return liczba10;
}

void zamiana2() {
	int tab[20],i,ilecyfr,podstawa;
	cout << "Podaj podstawe ";
	cin >> podstawa;
	cout << "Ile podasz cyfr? ";
	cin >> ilecyfr;
	cout << "Podaj kolejne cyfry liczby ";
	for (i=0;i<ilecyfr;i++) 
		do {
			cin >> tab[i];
			if (tab[i]>podstawa-1) cout << "Niedopuszczalna cyfra. Podaj jeszcze raz... \n";
		} while (tab[i]>podstawa-1);

	cout << "Wynik konwersji: " << konwersja2(tab,ilecyfr,podstawa) << "[10]" << endl;
}

void konwersja3(int liczba, int podstawa) {//wersja rekurencyjna
	if (liczba > podstawa)
		konwersja3(liczba/podstawa,podstawa);
	cout << liczba%podstawa;
}

void zamiana3() {
		int liczba, podstawa;
		cout << "Podaj liczbę: ";
		cin >> liczba;
		cout << "Podaj podstawę: ";
		cin >> podstawa;
		konwersja3(liczba,podstawa);
}

int main() {
	cout << "Program pozwala na zamianę liczby dziesietnej na liczbe o podstawie <3;16> lub odwrotnie." << endl;
	zamiana1();
	zamiana2();
	//zamiana3();
	//getchar(); return EXIT_SUCCESS;
	return 0;
}
