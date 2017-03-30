#include <iostream>
#include <cstdlib>
#include "osoba.h"
#include "car.h"

using namespace std;

Car::Car() {
	marka=model="";
	rocznik=przebieg=0;
	ileosob=0;
}

Car::Car(string mr, string ml, int r, int p)
    : ileosob(0)
{
    marka=mr;
    model=ml;
    rocznik=r;
    przebieg=p;
	laduj(2);
}

void Car::dodaj() {
	cout<<"Dodawanie samochodu:"<<endl;
	cout<<"Marka: "; cin>>marka;
	cout<<"Model: "; cin>>model;
	cout<<"Rocznik: "; cin>>rocznik;
	cout<<"Przebieg: "; cin>>przebieg;
}

void Car::dane() {
	cout<<"\nTwoje piękne auto:"<<endl;
    cout<<marka<<" "<<model<<endl;
    cout<<"rocznik: "<<rocznik<<endl;
    cout<<"przebieg: "<<przebieg<<endl;
    cout<<"przewozi: "<<ileosob<<" osób"<<endl;
}

void Car::laduj(int ile) {
    string im, n, p;
    im=n=p="";
	int w=0;
    cout << "Podaj dane " << ile << " osób:" << endl;
    for (int i=0; i<ile;i++) {
        cout << "Imię: "; cin >> im;
        cout << "Nazwisko: "; cin >> n;
        cout << "Wiek: "; cin >> w;
        cout << "Płeć: "; cin >> p;
        osoby[i]=Osoba(im,n,w,p);
        ileosob++;
    }
}

void Car::pasazerowie() {
	cout << "Pasażerowie:" << endl;
    for(int i = 0; i<ileosob;i++) {
        cout << i+1 << ") ";
        osoby[i].dane();
    }
}
