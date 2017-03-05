#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

inline void stop() {
		char b;
		cin>>b;
		return;
}
// f(n) = 1						 dla n {0,1}
// f(n) = f(n-1)+f(n-2) dla n>1
int fibonacci(int n) {
	if (n<2)
		return 1;
	else
		return fibonacci(n-1)+fibonacci(n-2);
}

int fibonacciit(int n) {
	int a = 1;
	int b = 1;
	int wynik=0;
	if (n<2) return 1;
	for (int i=2; i<n+1; i++){
		wynik=a+b;
		b = a;
		a = wynik;
	}
	return wynik;
}

int main(int argc, char *argv[])
{
	int n;
		// -------- CIAG FIBONACCIEGO
	cout << "Obliczanie wartosci n-tego wyrazu ciagu Fibonacciego: ktory wyraz..." << endl;
	cin >> n;
	cout << "Wartosc " << n << " wyrazu ciagu: " << fibonacci(n) << endl;
	cout << "Ciag Fibonacciego do " << n << " wyrazu: " << endl;
//	for (int i=0; i<n+1; i++) {
//		cout << "f(" << i << ") = " << setw(4) << fibonacci(i) << "			 ";
//		cout << "iloraz f(" << i << ")/f(" << i-1 << "): " << setw(10) << (float)fibonacci(i)/fibonacci(i-1) << endl;
//	}

	 for (int i=0; i<n+1; i++) {
		cout << "f(" << i << ") = " << setw(4) << fibonacciit(i) << "			 ";
			cout << "iloraz f(" << i << ")/f(" << i-1 << "): " << setw(10) << (float)fibonacciit(i)/fibonacciit(i-1) << endl;
		}
	cout << endl;
	return 0;
}
