#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

/*
 * Pliki binarne nie są obsługiwane przez operatory <<, >> i funkcje typu getline()
 * nie występuje tu formatowanie danych jako znaków i linii.
 * Używamy:
 * read(memory_block, size), write(memory_block, size)
 * char* memory_block - wskaźnik do tablicy znaków
 * 
 * 
*/

void czytajbin(char* plik) {
    streampos rozmiar;
    char* blokpam;
    ifstream f(plik,ios::in|ios::binary|ios::ate);
    if (f.is_open()) {
        rozmiar = f.tellg();
        blokpam = new char [rozmiar];
        f.seekg(0,ios::beg); //ustaw znacznik pozycji na początku pliku
        f.read(blokpam,rozmiar);//wczytanie pliku do pamięci
        f.close();
        
        cout << "Zawartość pliku wczytana." << endl;
        delete[] blokpam;
    } else cout << "Nie mogę otworzyć pliku.";
}

int main(int argc, char *argv[]) {
    char plik1[] = "test1.dat";
    char plik2[] = "test2.dat";
    int i;
    //ios::in, ios::out, ios::binary, ios::ate, ios::app, ios::trunc
    //ofstream f;
    ofstream f(plik1,ios::binary|ios::app);
    //f.open(plik1,ios::binary);
    if (f.is_open()) cout << "Plik otwarto." << endl;
    for (i=0; i<100; i++) {
        f.write((const char *)&i, sizeof(i));
    }
    f.close();
    
    czytajbin(plik1);
    
    f.open(plik2,ios::app);
    if (f.is_open()) cout << "Plik otwarto." << endl;
    for (i=0; i<100; i++) {
        f << i;
    }
    f.close();

	return 0;
}
