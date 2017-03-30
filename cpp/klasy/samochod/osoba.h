#include <iostream>
#include <cstdlib>

#ifndef __OSOBA_H_
#define __OSOBA_H_

using namespace std;

class Osoba {
private:
    string imie;
    string nazwisko;
    int wiek;
    string plec;
public:
    Osoba();
    Osoba(string, string, int, string);
    void dane();
};
#endif
