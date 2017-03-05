#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int a,b,c;
	cout << "Program wybiera najmniejszą podaną liczbę";
	cout << "\nPodaj 3 liczby";
	cin >> a >> b >> c;
	cout << "Najmniejsza liczba to: ";
	if (a<b)
		if (a<c) cout << a;
		else cout << c;
	else
		if (c<b) cout << c;
		else cout << b;
	cout << endl;
	return 0;
}
