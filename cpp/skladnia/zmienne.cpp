#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int a=1;
	short int a1=2;
	char b='a';
	float c=1.23;
	double d=2.34567;
	bool e=true;
	cout << "Rozmiar pamieci w bajtach dla kolejnych typow zmiennych: " << endl;
	cout << "int:\t\t" << sizeof(a) << endl;
	cout << "short int:\t" << sizeof(a1) << endl;
	cout << "char:\t\t" << sizeof(b) << endl;
	cout << "float:\t\t" << sizeof(c) << endl;
	cout << "double:\t\t" << sizeof(d) << endl;
	cout << "boole:\t\t" << sizeof(e) << endl;
	return 0;
}
