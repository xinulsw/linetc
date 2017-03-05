#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int x=11;
	cout << x << endl;
	cout << "Wartość x: " << x << endl;
	cout << "Adres x: " << &x << endl;
	cout << "Wartość pod adresem: " << * &x << endl;
	cout << "Rozmiar x: " << sizeof(x) << endl;

	int *px;
	px = &x;
	cout << "Wartość wskaźnika: " << px << endl;
	cout << "Wartość pamięci wskazywanej przez wskaźnik: " << *px << endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}
