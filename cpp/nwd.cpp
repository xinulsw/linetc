#include <cstdlib>
#include <iostream>

using namespace std;

int NWDv3(int a, int b) {
	int i=1, tmp;
	while (b!=0) {
		tmp=a%b;
		a=b;
		b=tmp;
		i++;
	}
	cout << "Powtorzen: " << i << endl;
	return a;
}

int NWDv2(int a, int b) {
	int i=1;
	while (a>0) {
		a = a%b;
		b = b-a;
		i++;
	}
	cout << "Powtorzen: " << i << endl;
	return b;
}

int NWDv1 (int a, int b) {	// funkcja licz¹ca NWD(a,b)
	int i=1;
	while (a!=b) {		// dopóki a jest ró¿ne od b
		if(a>b)				// jeœli a jest wiêksze od b to 
			a = a-b;		// w miejsce a podstaw ró¿nicê a-b		
		else							// w przeciwnym wypadku	
			b = b-a;
		i++;		// w miejsce b podstaw ró¿nicê b-a				
	}
	cout << "Powtorzen: " << i << endl;
	return a;
}

int NWW (int a, int b) {//najwiêksza wspólna wielokrotnoœæ
	return (a*b)/NWDv1(a,b);
}

int main(int argc, char *argv[]) {
	int a, b;
	cout << "podaj pierwsza liczbe a: ";
	cin >> a;
	cout << "podaj druga liczbe b: ";
	cin >> b;
	cout << "NWD(" << a << "," << b << ") ma wartosc: " << NWDv1(a,b) << endl<<endl;
	cout << "NWD2(" << a << "," << b << ") ma wartosc: " << NWDv2(a,b) << endl<<endl;
	cout << "NWD3(" << a << "," << b << ") ma wartosc: " << NWDv3(a,b) << endl << endl;
	cout << "NWW(" << a << "," << b << ") ma wartosc: " << NWW(a,b) << endl << endl;
	cout << endl;
	return 0;
}
