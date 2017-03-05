#include <cstdlib>
#include <iostream>

using namespace std;

float horner_it(int k, float tbwsp[], float x) {
	int i;
	float wartosc = tbwsp[0];
	for (i=1; i<=k; i++)
		wartosc = wartosc*x + tbwsp[i];
	return wartosc;
}

// W(x) = 2x^3 + 3x^2 + 5x + 4
// W(x) = x (2x^2 + 3x + 5) +4
// W(x) = x (x (2x + 3) + 5) + 4
float horner_re(int k, float tbwsp[], float x) {
	if (k==0)
		return tbwsp[0];
	else
		return horner_re(k-1,tbwsp,x)*x+tbwsp[k];
}

void drukujw(int st, float tbwsp[]) {
    int i;
    for (i=0; i<st-1; i++) {
        cout << tbwsp[i] << "x^" << st-i << " + ";
    }
    cout << tbwsp[i] << "x + " << tbwsp[i+1]; 
}

int main(int argc, char *argv[]) {
    float *tbwsp;
    float x = 0;
	int stopien = 0;
    cout << "Podaj stopień wielomianu: ";
    cin >> stopien;
    tbwsp = new float [stopien+1];

	cout << "Obliczanie wartości wielomianu dla " << stopien+1 << " współczynników i argumentu." << endl;
	for (int i=0; i<=stopien; i++) {
        cout << "Podaj współczynnik przy potędze " << stopien-i << ": ";
		cin >> tbwsp[i];
    }

	cout << "Podaj argument... ";
	cin >> x;

    cout << "Wartość wielomianu o postaci: ";
    drukujw(stopien, tbwsp);
    cout << "\ndla x = " << x << " wynosi: ";
    cout << horner_re(stopien,tbwsp,x) << endl;
	cout << horner_it(stopien,tbwsp,x) << endl;
	cout << endl;
	return 0;
}
