#include <iostream>
#include <cstdlib>
#include "osoba.h"
#include "car.h"

using namespace std;

int main(int argc, char **argv) {
	string marka, model;
	int rocznik, przebieg;
	cout<<"Dodawanie samochodu:"<<endl;
	cout<<"Marka: "; cin>>marka;
	cout<<"Model: "; cin>>model;
	cout<<"Rocznik: "; cin>>rocznik;
	cout<<"Przebieg: "; cin>>przebieg;
    Car sam(marka,model,rocznik,przebieg);
//	Car sam;
//	sam.dodaj();
//  sam.laduj(2);
    sam.dane();
    sam.pasazerowie();

    return 0;
}
