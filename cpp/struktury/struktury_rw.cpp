#include <iostream> // std::cout, std::ios, std::endl
#include <iomanip>
#include <cstdio> // printf
#include <cstdlib> //strtol
#include <fstream>
#include <cstring>

using namespace std;

struct osoba {
    char imie[20];
    char nazwisko[20];
    int wiek;
};

void getOsoby(osoba tb[], int ile) {
    for (int i = 0; i<ile; i++) {
        cout << "Podaj dane ucznia " << i+1 << ": " << endl;
        cout << setw(10) << left << "Imię: ";
        cin >> tb[i].imie;
        cout << setw(10) << left << "Nazwisko: ";
        cin >> tb[i].nazwisko;
        cout << setw(10) << left << "Wiek: ";
        cin >> tb[i].wiek;
    }
}

void drukuj(osoba tb[], int ile) {
    cout << "Dane uczniów: " << endl;
    for (int i = 0; i<ile; i++) {
        cout << tb[i].imie << " " << tb[i].nazwisko << " " << tb[i].wiek << endl;
    }
}

void zapisz(osoba tb[], int ile) {
    ofstream f("osoby.txt", ios::app);
    if (!f.is_open()) {
        cout << "Błąd otwarcia pliku!" << endl;
    } else {
        for (int i = 0; i<ile; i++) {
            f << tb[i].imie << " " << tb[i].nazwisko << " " << tb[i].wiek << endl;
        }
    }
}

void ltos(osoba tb[], const char *liniach, int i) {
    char linia[255] = (liniach);
    char *wskch; //deklaracja wskaźnika
    wskch = strtok(linia, " ");
    tb[i].imie = wskch;
    wskch = strtok(NULL, " ");
    tb[i].nazwisko = wskch;
    wskch = strtok(NULL, " ");
    tb[i].wiek = atoi(wskch);
}

void czytaj(osoba tb[]) {
    string linia;
    ifstream f("osoby.txt");
    int i = 0;
    if (f.is_open()) {
        while(getline(f,linia)) {
            cout << linia << '\n';
            ltos(tb, linia.c_str(), i);
            i++;
        }
        f.close();
    } else cout << "Nie mogę otworzyć pliku.";
}

#define MAX_OSOB 255

int main(int argc, char **argv) {
    osoba tb[MAX_OSOB];
    czytaj(tb);
    drukuj(tb, MAX_OSOB);
    //getOsoby(tb, MAX_OSOB);
    //drukuj(tb, MAX_OSOB);
    //zapisz(tb, MAX_OSOB);

	return 0;
}
