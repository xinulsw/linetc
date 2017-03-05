#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

typedef list<string> ListaZdan;

enum stan 
{
    TEKST,
    KROPKA,
    KROPKA_ODSTEP,
};

ListaZdan podzielNaZdania(istream & file)
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
    ifstream file("lorem.txt");
    
    if (!file.is_open())
    {
        cout << "Blad otwarcia pliku!";
        return 1;    
    }    
    
    ListaZdan lista = podzielNaZdania(file);
    
    for (ListaZdan::iterator it = lista.begin(); it != lista.end(); it++ )
    {
        cout << *it << endl;
    }
    
    cout << "Ilosc zdan: " << lista.size();
    
    file.close();
    cin.get();
    return 0;   
}
