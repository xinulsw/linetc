#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class Data {
public:
	Data(int=1, int=1, int=1990); //konstruktor
	void drukuj() const; //data w formacie d/m/r
	~Data();
private:
	int dzien;
	int miesiac;
	int rok;
	int sprawdzDzien(int); //fun. narzędziowa
};

Data::Data(int d, int m, int r) {
	if (m>0 && m<=12) miesiac = m;
	else {
		miesiac = 1;
		cout << "Niepoprawny miesiąc: " << m << ". Przyjęto wartość 1.\n";
	}
	rok = r;//powinno być sprawdzone
	dzien = sprawdzDzien(d);
	cout << "Konstruktor obiektu klasy Data dla daty: ";
	drukuj();
	cout << endl;
}

void Data::drukuj() const {
	cout << dzien << "/" << miesiac << "/" << rok;
}

Data::~Data() {
	cout << "Destruktor obiektu klasy Data dla daty: ";
	drukuj();
	cout << endl;
}

int Data::sprawdzDzien(int testDzien) {
	static const int dniMiesiecy[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if (testDzien > 0 && testDzien <= dniMiesiecy[miesiac])
		return testDzien;
	if (miesiac == 2 && //sprawdzanie roku przestępnego
		testDzien == 29 && (rok % 400 == 00 || (rok % 4 == 0 && rok % 100 != 0 ))) //rok 2000?
		return testDzien;
	cout << "Niepoprawny dzien: " << testDzien << ". Przyjęto wartość 1.\n";
	return 1;
}

class Pracownik {
public:
	Pracownik(char const *, char const *, int, int, int, int, int, int); //konstruktor
	void drukuj() const; //stała funkcja składowa
	~Pracownik(); //destruktor
private:
	char imie[25];
	char nazwisko[25];
	const Data dataUrodzenia; //stały obiekt składowy
	const Data dataZatrudnienia; //stały obiekt składowy
};

Pracownik::Pracownik(char const *pImie, char const *pNazwisko, int uDzien, int uMiesiac, int uRok, int zDzien, int zMiesiac, int zRok)
	: dataUrodzenia(uDzien,uMiesiac,uRok), dataZatrudnienia(zDzien,zMiesiac,zRok) //inicjatory składowych
{
	int dlugosc = strlen(pImie);
	dlugosc = (dlugosc < 25 ? dlugosc : 24);
	strncpy(imie,pImie,dlugosc);
	imie[dlugosc]='\0';

	dlugosc = strlen(pNazwisko);
	dlugosc = (dlugosc < 25 ? dlugosc : 24);
	strncpy(nazwisko,pNazwisko,dlugosc);
	nazwisko[dlugosc]='\0';

	cout << "Konstruktor obiektu klasy Pracownik: " << imie << ' ' << nazwisko << endl;
}

void Pracownik::drukuj() const {
	cout << nazwisko << ", " << imie << "\nZatrudniony: ";
	dataZatrudnienia.drukuj();
	cout << "   Data urodzenia: ";
	dataUrodzenia.drukuj();
	cout << endl << endl;
}

Pracownik::~Pracownik() {
	cout << "Destruktor klasy Pracownik: " << nazwisko << " " << imie << endl;
}

int main(int argc, char *argv[]) {
	Pracownik p("Jan","Kowalski",24,7,1970,3,12,1997);
	cout << "\n";
	p.drukuj();

	return 0;
}
