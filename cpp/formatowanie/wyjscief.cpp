#include <iostream> // std::cout, std::ios, std::endl
#include <iomanip> // std::setiosflags
#include <cstdio> // printf
#include <math.h> //stała M_PI

using namespace std;

/*
* FLAGI fmtflags (typ bitmask):
* Ustawiane selektywne za pomocą cout.setf(fmtflags fmtfl, fmtflags mask):
* [left], right, internal - wyrównanie w polu wyprowadzania (dla liczb - [right]) (adjustfield)
* [dec], oct, hex - system liczbowy, w jakim wypisuje się liczbę (dot. całkowitych) (basefield)
* scientific, fixed - notacja naukowa lub zwykła - dla float/double [bez ustawienia określa się to na podstawie wielkości rzędu liczby] (floatfield)
*
* Ustawiane/anulowane za pomocą cout.setf(fmtflags fmtfl)/cout.unsetf(fmtflags fmtfl); flagi niezależne:
* boolalpha - wartości bool jako true,false
* skipws - powoduje pominięcie (w istreamach) wiodących spacji
* uppercase - litery w liczbach szesnastkowych (i E w notacji naukowej) są duże
* showbase - dodaje odpowiednie nagłówki dla hex i oct
* showpoint - nakazuje zawsze wypisać kropkę w liczbach float
* showpos - dodaje `+' przed liczbą dodatnią
* unitbuf - wyłącza buforowanie dla strumienia
*
* MANIPULATORY:
* Wejścia:
* ws - ignorowanie wiodących białych znaków w operacjach wejścia
* setw (size_t) - ograniczenie bufora dla wprowadzanych znaków
* Wyjścia:
* flush, ends, endl - opróżnienie bufora, wysłanie znaku zerowego, wysłanie znaku '\n'
* setbase(8 lub 16) - ustawia podstawę liczby
* setfill(znak), jak cout.fill(znak) - ustawia znak wypełnienia
* setprecision(), jak cout.precision() - ustawia ilość cyfr rozwinięcia
* setw() , jak width() - ustawia min. szerokość pola
* setiosflags, resetiosflags() - ustawia, kasuje flagi formatowania
*
*/

int main(int argc, char **argv){
    int li = 100;
    float lf = 12.789;

    //FUNKCJA fmtflags flags (fmtflags fmtfl);
    //cout.flags (ios::right | ios::hex | ios::showbase); //ustawianie flag fmtflags jako typu
    ios_base::fmtflags fx; //deklaracja zmiennej typu fmtflags
    //fx &= ~cout.basefield;   // unset basefield bits
    fx |= cout.hex;
    fx |= cout.showbase;

    cout.flags(fx);
    cout << li << endl;

    //FUNKCJA fmtflags setf (fmtflags fmtfl, fmtflags mask);
    cout.setf (ios::right, ios::adjustfield);// selektywne modyfikowanie flag
    //cout.setf (ios_base::oct, ios_base::basefield); //użycie fmtflags jako stałych klasy
    //FUNKCJA fmtflags setf (fmtflags fmtfl);
    //cout.setf (ios_base::showbase);
    //cout.setf (ios::oct, ios::basefield); //użycie fmtflags jako dziedziczonych stałych klasy
    //cout.setf (ios::showbase);
    //cout.setf (cout.oct, cout.basefield); //użycie fmtflags jako stałych obiektu
    //cout.setf (cout.showbase);
    //cout.setf( 0, ios::floatfield ); //przywrócenie stanu domyślnego floatfield

    cout.precision(5);
    cout.fill('*'); //ustawia znak wypełnienia pola
    cout.width (20); //ustawienie minimalnej szerokości pola
    cout << li << endl;
    cout << lf << endl;
    cout << M_PI << endl;

    //MANIPULATORY
    //setiosflags (ios_base::fmtflags mask);
    //cout << hex;
    //cout << setiosflags (ios::showbase | ios::uppercase);
    //cout << dec << showbase << uppercase;

    //cout << hex;
    //cout << showpoint << f << endl;

    string s;
    cin >> ws >> s;
    cout << s << endl;

//http://www.cplusplus.com/reference/cstdio/printf/
//%[flags][width][.precision][length]specifier
    printf("%e\n", 10*M_PI);     // 3.141593e+001
    printf("%12f\n", 10*M_PI);   // 31.415927
    printf("%12.4f\n", 10*M_PI); // 31.4159
    printf("%12.4d\n", 3);       // 0003
    printf("Hex: %#x\nOct: %#o\n", 10, 10);
    printf("Napis: %20s", "Ahoj");

    return 0;
}
