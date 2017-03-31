#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
  double a, b; // zmienne pomocnicze - wsp��rzedne losowanego punktu
  long T = 0; // dzi�ki typowi long mo�emy losowac wiele punkt�w
  long R;
  long ilosc;
  srand(time(NULL)); // inicjacja funkcji rand()
  cout << "Na podstawie ilu punktow znalezc wartosc liczby pi? ";
  cin >> ilosc;
  for(R=0; R<ilosc; R++)
  {
    a = (double)rand()/(RAND_MAX); // losujemy liczby rzeczywiste
    b = (double)rand()/(RAND_MAX); // z zakresu <0,1>
    if (a*a+b*b<=1) T++; // je�li punkt nale�y do ko�a to zwi�kszamy licznik
  }
  cout << "liczba pi ma wartosc : " << (double)(4*T)/R << endl;
  cout << "Liczba Pi: " << M_PI << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
