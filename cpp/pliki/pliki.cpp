#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>

using namespace std;

int sumuj(char nazwa[]) {
	ifstream we(nazwa); //deklaracja strumienia wejścia jako pliku
	if (!we) {
		cout << "Błąd otwarcia pliku!";
		return 1;
	}
	float l;
	float suma=0;
	while(!we.eof()) {
		we >> l; //odczytujemy wszystko poza białymi znakami
		cout << "Odczytano: " << l << endl;
		suma = suma + l;
	}
	cout << "Suma pobranych liczb to: " << suma << endl;
	return 0;
}
int czytajSlowa(char nazwa[]) {
	ifstream we(nazwa); //deklaracja strumienia wejścia jako pliku
	if (!we) {
		cout << "Błąd otwarcia pliku!";
		return 1;
	}
	char slowo[100];
	while(!we.eof()) {
		//we >> slowo; //czytamy poszczególne słowa
		we.getline(slowo,sizeof(slowo)); //czytamy czałe wiersze
		cout << "Odczytano słowo(wiersz): " << slowo << endl;
	}
	we.close();
	return 0;
}
int liczZnaki(char nazwa[]) {
	ifstream we(nazwa); //deklaracja strumienia wejścia jako pliku
	if (!we) {
		cout << "Błąd otwarcia pliku!";
		return 1;
	}
	char nazwa2[100];
	strcpy(nazwa2,nazwa);
	char *pch;
	pch = strstr(nazwa2,".txt");
	strncpy(pch,".bak",4);
	ofstream wy(nazwa2);
	if (!wy) {
		cout << "Błąd zapisu pliku: " << nazwa2 << endl;
		return 1;
	}
	char c; //zmienna przechowująca odczytywane znaki;
	int ile=0; //suma wszystkich znaków
	int ileal=0; //suma liter
	int ilealnum=0; //suma znaków alfanumerycznych
	int ilenum=0; //suma znaków cyfr
	while (!we.eof()) {
		we.get(c);
		if (we) {
			ile++; //jeżeli strumień nie jest pusty zwiększ licznik
		}
		if (we && isalnum(c)) {
			//wy << c << endl; //zapisujemy tylko alfanum w noeych wierszach
			wy.put(c); //zapisujemy alfanum w jednym wierszu
			ilealnum++;
		}
		if (we && isalpha(c)) ileal++;
		if (we && isdigit(c)) ilenum++;
	}
	we.close();
	wy.close();
	cout << "Znaków: " << ile << endl;
	cout << "Liter: " << ileal << endl;
	cout << "Cyfr: " << ilenum << endl;
	cout << "Alfanum.: " << ilealnum << endl;
	return 0;
}

int czytajznaki(char* plik) {
    ifstream f;
    char c;
    int i = 0;
    f.open(plik, ios::binary);
    while (!f.eof()) {
        f >> c; //czytanie z pliku znaku
        cout << c; //wyprowadzenie znaku na ekran
        i++;
    }
    f.close();
    cout << endl;
    return i;
}

void zapiszznaki(char* plik) {
    ofstream f;
    char c;
/*
 * Tryby otwierania plików:
 * ios::in - do odczytu
 * ios::out - do zapisu
 * ios::binary - tryb binarny
 * ios::ate - wskaźnik na końcu pliku
 * ios::app - tryb dopisywania
 * ios::trunc - zerowanie pliku
*/
    f.open(plik);
    do {
        c = cin.get();
        if (c != 27) {
            //cout << c; //wyświetlenie na ekranie
            f << c; //zapis do pliku
        }
    } while(c != 27);
    f.close();
    cout << endl;
}

/*
 * Sprawdzanie stanu strumienia:
 * f.bad(), f.fail(), f.eof(), f.good()
 *
 * tellg(), tellp() - podają pozycję znacznika odczytu i zapisu (streampos)
 * seekg(streampos), seekp(streampos) - ustawiają pozycję znacnzika odczytu i zapisu
 * seekg(offset, direction), seekp(offset, direction)
 * direction: ios::beg, ios::cur, ios::end
 *
*/

void czytajlinie(char *plik) {
    string linia;
    ifstream f(plik);
    if (f.is_open()) {
        while(getline(f,linia)) {
            cout << f.tellg() << endl;
            cout << linia << '\n';
        }
        f.close();
    } else cout << "Nie mogę otworzyć pliku.";
}

void rozmiarpliku(char *plik) {
    streampos begin, end;
    ifstream f(plik,ios::binary);
    begin = f.tellg();
    f.seekg(0, ios::end);
    end = f.tellg();
    f.close();
    cout << "Rozmiar pliku: " << (end-begin) << " bajtów. \n";
}

/*
	Program demonstruje użycie strumieni wejścia i wyjścia.
 */
#define MAX_NAZWA 100
int main(int argc, char *argv[]) {
	char nazwa[MAX_NAZWA]; //deklaracja tablicy znakowej na nazwę pliku
	cout << "Podaj nazwę pliku tekstowego z rozszerzeniem: ";
	cin.getline(nazwa,MAX_NAZWA); //pobranie nazwy pliku
    zapiszznaki(nazwa);
    czytajznaki(nazwa);
    czytajlinie(nazwa);
    rozmiarpliku(nazwa);
	/* wywołanie funkcji operujących
	 * na pliku
	*/
//	liczZnaki(nazwa);
//	czytajSlowa(nazwa);
//	cout << "Podaj nazwę pliku z danymi: ";
//	cin >> nazwa;
	/* sumowanie extra */
//	sumuj(nazwa);
	return 0;
}
