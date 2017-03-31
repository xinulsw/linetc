#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

class Figura {
public:
   Figura(char figura); //konstruktor
   void getNazwa(); //wyświetl nazwę figury
   char getTyp(); //zwraca typ figury
   void getPole(); //wyświetl pole figury
   void getObwod(); //wyświetl obwód figury
private:
   char typ; //litera oznaczająca figurę
   char nazwa[15]; //nazwa figury
   float pole; //pole figury
   float obwod; //obwód figury
   void setTyp(char figura);
};

Figura::Figura(char figura) {
   setTyp(figura);
   cout << "Utworzono: ";
   getNazwa();
   cout << endl;
   pole = obwod = 0;
}

void Figura::setTyp(char figura) {
   switch (figura) {
      case 'k': strcpy(nazwa,"kwadrat"); typ = figura; break;
      case 'p': strcpy(nazwa,"prostokąt"); typ = figura; break;
      case 't': strcpy(nazwa,"trójkąt"); typ = figura; break;
      case 'o': strcpy(nazwa,"koło"); typ = figura; break;
      default:
         cout << "Nieznany typ figury!";
         strcpy(nazwa,"kwadrat"); typ = 'k';
   }
}

char Figura::getTyp() { return typ; }
void Figura::getNazwa() { cout << nazwa; }
void Figura::getPole() { cout << pole; }
void Figura::getObwod() { cout << obwod; }

int main(int argc, char *argv[]) {
   char odp;
   cout << "Wybierz figurę: " << endl;
   cout << " k - kwadrat\n p - prostokąt \n t - trójkąt \n o - koło\n";
   cin >> odp;
   Figura f1(odp);
   Figura f2('t');
   Figura f3('x');
}
