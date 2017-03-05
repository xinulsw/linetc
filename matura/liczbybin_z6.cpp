#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

string liner (int a){
	string l;
	ifstream plik;
	plik.open("liczby.txt");
	for (int i = 1; i<=a; i++) {
		plik >> l;
	}
	return l;
}

inline int digit(char a) {
    if ((int)a == 48) return 0;
    return 1;
}

int ptg (int l, int w) {
	if (w == 0)
		return 1;
	else
		return ptg(l, w-1) * l;
}

long int bindouble(string a, int lng){
  //int lng = a.length();
  long int collector = 0;
	int i = 0;
	while (lng > 0) {
		collector = collector + ptg(2,lng-1) * digit(a[i]);
		lng--;
		i++;
	}
	return collector;
}

int main(){
	int ilep = 0; //ile liczb parzystych
	long int lmax = 0; //liczba największa (10)
	string lmaxb=""; //liczba największa (2)
	long int l = 0; //liczba bieżąca (10)
	string lb=""; //liczba bieżąca (2)
	int lbdl=0; //długość liczby bieżącej (2)
	int ile9 = 0; //ile liczb 9-cyfrowych (2)
	long int suma9 = 0; //suma liczba 9 cyfrowych(10)
	for(int i = 0; i<1000; i++) {
		lb=liner(i+1);
		lbdl = lb.length();
		l = bindouble(lb,lbdl);
		if (l > lmax) {
			lmax = l;
			lmaxb = lb;
		}
		if (l % 2 == 0) ilep++;
		if (lbdl == 9) {
			ile9++;
			suma9 = suma9 + l;
		}
	}
	cout << "W pliku jest: " << ilep << " liczb parzystych" << endl;
	cout << "Największa liczba to: " << lmaxb << "(2), " << lmax << "(10)" << endl;
	cout << "Liczb 9-cyfrowych: " << ile9 << " Suma: " << suma9 << "(10)" << endl;
	return 0;
}
