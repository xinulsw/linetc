class Ulamek
{
  int licznik;
  int mianownik;
public:
  Ulamek (int l, int m); // deklaracja konstruktora
  void wypisz()
  {
    cout << licznik << "/" << mianownik;
  }
};					// koniec definicji klasy

Ulamek::Ulamek(int l, int m) // definicja konstruktora
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