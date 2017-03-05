#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
	ofstream wyj("brown.xls");
	//const float PI = 3.14159;
	float x,y,s,fi;
	long i,n;
	cout << "Ile ruchów? ";
	cin >> n;
	x=y=0;
	wyj << x << "\t" << y << endl;
	srand(time(NULL));
	for (i=0; i<n; i++) {
		fi = (float)rand()/(RAND_MAX+1)*(2*M_PI);
		cout << fi << "\t";
		x = x + cos(fi);
		y = y + sin(fi);
		cout << "\t" << x << "," << y << endl;
		wyj << x << "\t" << y << endl;
	}
	s = sqrt(x*x + y*y);
	cout << endl << "Przemieszczenie: " << s;
	wyj.close();
	
	return 0;
}
