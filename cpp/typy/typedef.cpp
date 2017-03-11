#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <string.h>

using namespace std;

enum REZULTAT {
    ISTNIEJE = 1,
    NIEISTNIEJE = -1
};

inline REZULTAT czyjest (const char *npliku) {
    ifstream f(npliku);
    if (f.good()) {
        f.close();
        return ISTNIEJE;
    } else {
        f.close();
        return NIEISTNIEJE;
    }
}

int powieksz(int a) {
// deklaracja
    const int x = 10;
    return a + x;
}

// deklarowanie stałych
#define ROZMIAR 20

void nowytyp() {
// typedef pozwala używać alternatywnych nazw (aliasów) dla
// długich i skomplikowanych deklaracji typów.
    typedef string str;
    str x;
    cout << "Wprowadź tekst: ";
    cin >> ws >> x;
    cout << x << endl;
    // Opróżnianie bufora wejścia
    //cin.clear(); cin.sync();
    //cin.ignore(INT_MAX,'\n');
    cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
}

void pLiczba() {
// sprawdzanie danych: funkcja strtol
    char liczby[ROZMIAR];
    char* pEnd;
    long int li1;
    float li2;
    cout << "Podaj liczbę całkowitą: ";
    cin.getline(liczby,ROZMIAR);
    li1 = strtol(liczby, NULL, 10);
    cout << li1 << endl;
    cout << "Podaj liczby rzeczywiste oddzielone spacjami: ";
    cin.getline(liczby,ROZMIAR);
    li2 = strtod(liczby, &pEnd);
    cout << li2 << endl;
    while (pEnd != NULL) {
        li2 = strtod(pEnd, &pEnd);
        cout << li2 << endl;
    }
    if (pEnd == NULL) cout << "Koniec";
    cout << pEnd;
}

void typwylicz() {
// Użycie typu stałej ROZMIAR i typu wyliczeniowego.
    char plik[ROZMIAR];
    cout << "Podaj nazwę pliku: ";
    cin.getline(plik,ROZMIAR);
    cout << "Nazwa: " << plik << endl;

    REZULTAT jestplik;
    jestplik = czyjest(plik);
    if (jestplik == ISTNIEJE)
        cout << "Plik jest na dysku.\n";
    else if (jestplik == NIEISTNIEJE)
        cout << "Pliku nie ma!\n";
}

int main() {
    nowytyp();
    return 0;
}
