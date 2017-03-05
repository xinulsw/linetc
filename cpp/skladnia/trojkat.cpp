#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char **argv) {
	//deklaracja zmiennych
	float a, b, c; //boki trójkąta
	float h; //wysokość trójkąta
	
	cout << "Podaj długości boków przyprostokątnych: " << endl;
	cin >> a >> b; //pobierz dane od użytkownika
	
	if (a <= 0 || b <= 0) { //alternatywa logiczna
		cout << "Boki muszą być dodatnie. " << endl;
	} else {
		c = sqrt(a*a + b*b); // liczymy przeciwprostokątną
		h = a*b / c; //liczymy wysokość

		cout << "Obwód wynosi: " << a+b+c << endl;
		cout << "Pole wynosi: " << 0.5 * c * h << endl;
	
	}
	
	return 0;
}
