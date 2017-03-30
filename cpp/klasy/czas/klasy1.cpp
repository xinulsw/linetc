#include <iostream>
#include <cstdio>
#include "czas.h"

using namespace std;

int main(int argc, char *argv[]) {
	Czas t1;
//	Czas t2(23,59);
	cout << "Czas początkowy w f. wojskowym: " << endl;
	t1.drukujWojskowy();
//	cout << " ";
//	t2.drukujWojskowy();
	cout << "\nCzas początkowy w f. standardowym: " << endl;
	t1.drukujStandard();
//	cout << " ";
//	t2.drukujStandard();
	return 0;
}
