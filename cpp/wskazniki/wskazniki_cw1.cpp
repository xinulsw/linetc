#include <iostream>

using namespace std;

void wypelnienie(int tab[])
{
    for (int i = 0; i < 20 ; i++)
    {
        tab[i] = rand () % 6;
    }  
}

void wyswietl (int * ptr)
{
    cout << "Zawartosc tablicy: " << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << *(ptr + i) << " ";   
    }         
    cout << endl;
} 

int ile_par (int * ptr1, int * ptr2)
{
    int wynik = 0;
    
    for (int i = 0; i < 20; i++)
    {
        if (*(ptr1 + i) == *(ptr2 + i)) 
            wynik++;   
    }
    return wynik;    
}

int main ()
{    
    int tablica1[20];
    int tablica2[20];
    int * ptr1 = tablica1;
    int * ptr2 = tablica2; 
    srand (time(NULL));
    
    wypelnienie(tablica1);
    wypelnienie(tablica2);
    wyswietl(ptr1);
    wyswietl(ptr2);
    cout << "\nIlosc par elementow, ktore znajduja sie na tej samej pozycji w tablicach i maja te sama wartosc: " << ile_par(ptr1, ptr2);
    cin.get();
    return 0;   
}
