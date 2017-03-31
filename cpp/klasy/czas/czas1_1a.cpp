#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Czas {
public:
   //Czas(); //konstruktor
   Czas(int=0, int=0, int=0);
   void ustawCzas(int,int,int); //ustawia godz.,min. i sek.
   void drukujWojskowy(); //wyświetla czas w formacie wojskowym
   void drukujStandardowy(); //wyświetla czas w formacie wojskowym
   void drukujLicznik();
   void impuls(int);
   ~Czas(); //dekonstruktor
   static int licznik;
private:
   int godz;
   int min;
   int sek;
};
/*
Czas::Czas() {
   godz = min = sek = 0;
   cout << "\nKonstruktor obiektu typu Czas" << endl;
}
*/

int Czas::licznik = 0;

Czas::Czas(int g, int m, int d) {
   ustawCzas(g,m,d);
   licznik++;
   cout << "\nKonstruktor parametryczny obiektu typu Czas" << endl;
}

Czas::~Czas() {
   cout << "Dekonstruktor obiektu typu Czas" << endl;
}

void Czas::ustawCzas(int g, int m, int s) {//fun. typu ustaw
   godz = (g >= 0 && g < 24) ? g : 0;
   min = (m >= 0 && m < 60) ? m : 0;
   sek = (s >= 0 && s < 60) ? s : 0;
}

void Czas::drukujWojskowy() {
   cout << (godz < 10 ? "0" : "") << godz << ":"
         << (min < 10 ? "0" : "") << min;
}

void Czas::drukujStandardowy() {
   cout << ((godz == 0 || godz == 12) ? 12 : godz % 12)
         << ":" << (min < 10 ? "0" : "") << min
         << ":" << (sek < 10 ? "0" : "") << sek
         << (godz < 12 ? " AM" : " PM");
}

void Czas::drukujLicznik() {
   cout << "\nIlość obiektów: " << licznik << "\n";
}

void Czas::impuls(int sek) {
   ;
}

int main(int argc, char *argv[]) {
   Czas t; //tworzymy instancję klasy, czyli OBIEKT
   Czas t2(24,12,12);
   cout << "Czas (początkowy) wojskowy: " << endl;
   t.drukujWojskowy();
   cout << "\nCzas (początkowy) standardowy: " << endl;
   t.drukujStandardowy();
   t.ustawCzas(11,2,59);
   cout << "\n";
   t.drukujStandardowy();
   cout << "\n";
   t2.drukujStandardowy();
   cout << "\n";
   cout << "Ilość obiektów: " << Czas::licznik << endl;
   t.drukujLicznik();
   return 0;
}
