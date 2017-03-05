#include <cstdlib>
#include <iostream>

// Jeżeli funkcja f(x) jest ciągła w przedziale domkniętym <a;b>,
// f(a)!=f(b) oraz liczba p zawiera się w (f(a);f(b)),
// to istnieje taka liczba c zawarta w (a;b),
// że f(c) = p. W szczególności, jeżeli f(a)*f(b) < 0,
// tj. f(a) i f(b) są różnych znaków, to istnieje takie c, że f(c)=0.

double f(double x) {
  return 2*x*x-4*x;
}

double m_zerowe(double a, double b, double dokladnosc) {
  double d = (a+b)/2;
  while (b-a > dokladnosc && f(a) != 0 && f(b) != 0) {
    d = (a+b)/2;
    if (f(a)*f(d)<0)
      b = d;
    else
      a = d;
  }
  if (f(a)==0) return a;
  if (f(b)==0) return b;
  return d;
}

using namespace std;

int main(int argc, char *argv[]) {
  double lewy, prawy, dokl;
  double wynik;

  do {
    cout << "Podaj lewy kraniec przedzialu ";
    cin >> lewy;
    cout << "Podaj prawy kraniec przedzialu ";
    cin >> prawy;
  } while (f(lewy)*f(prawy)>0 || prawy<=lewy);

  cout << "Podaj dokladnosc ";
  cin >> dokl;
  wynik=m_zerowe(lewy,prawy,dokl);
  cout << "Przyblizona wartosc miejsca zerowego: ";
  cout << wynik << endl;
  cout << "f(" << wynik << ") = " << f(wynik) << endl << endl;

  //  system("PAUSE");
  //  return EXIT_SUCCESS;
  return 0;
}
