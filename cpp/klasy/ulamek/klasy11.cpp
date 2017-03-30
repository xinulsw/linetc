class Ulamek
{
  int licznik;
  int mianownik;
public:
  void zapisz(int l, int m); // deklaracja metody klasy
  void wypisz()
  {
    cout << licznik << "/" << mianownik;
  }
};					// koniec definicji klasy

void Ulamek::zapisz(int l, int m) // definicja metody klasy
{
  licznik = l;
  if (m!=0)
  mianownik = m;
  else
  {
    cout << "Mianownik nie moze miec wartosci 0 ";
    getchar();
    exit(1);
  }
}