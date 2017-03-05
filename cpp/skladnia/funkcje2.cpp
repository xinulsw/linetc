#include <iostream>

using namespace std;

void srednia(float &a,float &b) {
	a = a+1;
	b = b+10;
	cout << "Srednia: liczba a = " << a << " liczba b = " << b << endl;
}

int main() {
	float a,b;
	cout << "Podaj dwie liczby: ";
	cin >> a >> b;
	cout << "Main: liczba a = " << a << " liczba b = " << b << endl;
	srednia(a,b);
	cout << "Main: liczba a = " << a << " liczba b = " << b << endl;
	
	return 0;
}
