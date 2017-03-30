#include <iostream>
#include <cstdlib>
#include "osoba.h"

#ifndef __CAR_H_
#define __CAR_H_

using namespace std;

class Car {
private:
	string marka;
	string model;
	int rocznik;
	int przebieg;
	Osoba osoby[3];
	int ileosob;

public:
	Car();
    Car(string, string, int, int);
    void dodaj();
    void dane();
    void laduj(int);
    void pasazerowie();
};
#endif
