#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	int a, b;
	a = b = 0;

	cout << "Podaj dwie liczby: " << endl;
	cin >> a >> b;
	
	cout << "Suma: " << a+b << endl;
	cout << "Różnica: " << a-b << endl;
	cout << "Iloczyn: " << a*b << endl;
	cout << "Iloraz: " << (float)a / (float)b << endl;

	return 0;
}
