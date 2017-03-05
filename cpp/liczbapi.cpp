#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
  double a, b; // zmienne pomocnicze - wspó³rzedne losowanego punktu
  long T = 0; // dziêki typowi long mo¿emy losowac wiele punktów
  long R;
  long n;
  srand(time(NULL)); // inicjacja funkcji rand()
  cout << "Na podstawie ilu punktow znalezc wartosc liczby pi? ";
  cin >> n;
  for(R=0; R<n; R++)
  {
    a = (double)rand()/(RAND_MAX); // losujemy liczby rzeczywiste
    b = (double)rand()/(RAND_MAX); // z zakresu <0,1>
    if (a*a+b*b<=1) T++; // jeœli punkt nale¿y do ko³a to zwiêkszamy licznik
  }
  cout << "liczba pi ma wartosc : " << (double)(4*T)/R << endl;
 
 T = 0; 
 for(R=0; R<n; R++)
  {
    a = (double)rand()/(RAND_MAX); // losujemy liczby rzeczywiste
    b = (double)rand()/(RAND_MAX); // z zakresu <0,1>
    if (a*a+b*b<=1) T++; // jeœli punkt nale¿y do ko³a to zwiêkszamy licznik
  }
  cout << "liczba pi ma wartosc : " << (double)(4*T)/R << endl;
  
  cout << "Liczba Pi: " << M_PI << endl;
  
    system("PAUSE");
    return EXIT_SUCCESS;
}
