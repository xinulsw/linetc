#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

typedef list<string> ListaZdan;

enum stan 
{
    TEKST,
    KROPKA,
    KROPKA_ODSTEP,
};

ListaZdan podzielNaZdania(istream)
{
    ListaZdan lista;
    stan biezacyStan = TEKST;
    string zdanie;
    char znak;
    
    while (file.get(znak))
    {
        if (znak == '.')
        {
             biezacyStan = KROPKA;    
        }
        else if (isspace(znak))
        {
            if (biezacyStan == KROPKA || biezacyStan == KROPKA_ODSTEP)
            {
                biezacyStan = KROPKA_ODSTEP;
                continue;
            }    
        }
        else if (isupper(znak))
        {
            if (biezacyStan == KROPKA_ODSTEP)
            {
                lista.push_back(zdanie);
                zdanie = string();
            }
            biezacyStan = TEKST;
        }
        zdanie += znak;               
    }
    if (biezacyStan == KROPKA || biezacyStan == KROPKA_ODSTEP)
    {
        lista.push_back(zdanie);
    }
    return lista;       
}

int main ()
{    
    stringstream strumien;
    string tekst;
    string plikWynikowy = "wynik.txt";
    
    cout << "Podaj tekst: ";
    getline(cin, tekst);
    strumien << tekst;

    ListaZdan lista = podzielNaZdania(strumien);
    
    ofstream file(plikWynikowy.c_str());
    
    if (!file.is_open())
    {
        cout << "Blad otwarcia pliku!";
        return 1;    
    }    
    
    for (ListaZdan::iterator it = lista.begin(); it != lista.end(); it++ )
    {
        file << *it << endl;
    }
        
    cout << "Zapisano do pliku " << plikWynikowy << endl;
    file.close();
    
    cin.get();
    return 0;   
}
