#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

double funkcja(double x)	//funkcja dla której liczymy calkê, tu x^2
{
  return x*x;
}

double pole_obszaru(int n, double a, double b)
{
  double P = 0;			//zmienna która sumuje pola prostok¹tów
  double d = (b-a)/n;		//dlugoœæ przedzia³ów na jakie dzielimy <a;b>
  double x;			//punkty poœrednie przedzialów
  for (int k=0; k<n; k++)
  {
    x = a+(d*k)+(d/2);
    P = P+d*fabs(funkcja(x));	//suma pól prostok¹tów
  }
  return P;			//suma pól wszystkich prostok¹tów
}

int main(int argc, char *argv[])
{
  int ilosc;
  double a, b;
  cout << "Program oblicza pole obszaru ograniczonego";
  cout << "wykresem funkcji w przedziale <a; b>" << endl;
  cout << "podaj wartosc lewego kranca przedzialu:  a ";
  cin >> a;
  cout << "podaj wartosc prawego kranca przedzialu:  b ";
  cin >> b;
  cout << "Na ile przedzialow podzielic wyjsciowy przedzial?: ";
  cin >> ilosc;
  cout << "wartosc pola : " << pole_obszaru(ilosc,a,b) << endl;
  cin.ignore();
    system("PAUSE");
    return EXIT_SUCCESS;
}
