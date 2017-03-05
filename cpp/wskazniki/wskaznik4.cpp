#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char **argv) {
	int tab[10];				
	int *wsk_x;
	wsk_x = tab;

	srand(time(NULL));

	for (int i=0; i<10; i++) {
        *wsk_x=1+rand()%11;
        wsk_x++;	
    }

	cout << "Oto tabela od poczatku..." << endl;
	wsk_x=tab;
	for (int i=0;i<10;i++) {
        cout << *wsk_x << ",";
        wsk_x++;
    }

    cout << "\t... i od konca"<< endl; 

    wsk_x--;

	for( int i = 0 ; i <10 ; i++ ) {
        cout << *wsk_x << ","; 
        wsk_x--;
    }

	return 0;
}
