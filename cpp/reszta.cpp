#include <iostream>

using namespace std;

int nominaly[100];
int liczbaNominalow;

void wczytajNominaly()
{
	cout << "Podaj liczbe nominalow: ";
	cin >> liczbaNominalow;

	cout << "Podaj nominaly (w kolejnosci malejacej!): " << endl;
	for(int i = 0; i < liczbaNominalow; ++i)
	{
		int nominal;
		cin >> nominal;

		nominaly[i] = nominal;
	}
    for(int i = 0; i < liczbaNominalow; ++i)
        cout << nominaly[i] << " ";
    cout << endl;
}

void znajdzReszte(int reszta)
{
	cout << "Wyplacone nominaly: " << endl;
	int aktualnyNominal = 0;
	while( reszta > 0 && aktualnyNominal < liczbaNominalow )
	{
        cout << "reszta=" << reszta << endl;
		while( aktualnyNominal < liczbaNominalow && reszta < nominaly[aktualnyNominal] )
			++aktualnyNominal;
        cout << "aktN=" << aktualnyNominal << endl;
		if( aktualnyNominal < liczbaNominalow && reszta >= nominaly[aktualnyNominal] )
		{
			int liczbaBanknotow = reszta/nominaly[aktualnyNominal];
			cout << liczbaBanknotow << "x" << nominaly[aktualnyNominal] << "zl" << endl;
			reszta -= liczbaBanknotow*nominaly[aktualnyNominal];
		}
	}

	if( reszta > 0 )
		cout << "Brak nominalow do wydania pozostalej kwoty: " << reszta << "zl" << endl;
}

int main()
{
	wczytajNominaly();

	int cena;
	int wplata;
	cout << "Podaj cene: ";
	cin >> cena;

	do
	{
		cout << "Podaj wplate: ";
		cin >> wplata;
	}while( wplata < cena );

	znajdzReszte(wplata - cena);

	return 0;
}
