#include <iostream>

using namespace std;

class Zespolona
{
    private:
        double rzeczywista_;
        double urojona_;
        
    public:
        Zespolona(double rzeczywista = 0, double urojona = 0)
        {
            rzeczywista_ = rzeczywista;
            urojona_ = urojona;
        }
        
        Zespolona operator+(const Zespolona & z) const
        {
            double nowaRzeczywista = rzeczywista_ + z.rzeczywista_;
            double nowaUrojona = urojona_ + z.urojona_;
            Zespolona nowaZespolona = Zespolona(nowaRzeczywista, nowaUrojona);
            return nowaZespolona;
        }    
        
        Zespolona operator-(const Zespolona & z) const
        {
            double nowaRzeczywista = rzeczywista_ - z.rzeczywista_;
            double nowaUrojona = urojona_ - z.urojona_;
            Zespolona nowaZespolona = Zespolona(nowaRzeczywista, nowaUrojona);
            return nowaZespolona;
        }
        
        friend ostream & operator<< (ostream & os, const Zespolona & z)
        {
            os << "(" << z.rzeczywista_ << ", " << z.urojona_ << ")";
            return os;
        }
};          

int main ()
{    
    double pierwszaRzeczywista, pierwszaUrojona, drugaRzeczywista, drugaUrojona;
    
    cout << "Podaj czesc rzeczywista i urojona pierwszej liczby: ";
    cin >> pierwszaRzeczywista >> pierwszaUrojona;
    cout << "Podaj czesc rzeczywista i urojona drugiej liczby: ";
    cin >> drugaRzeczywista >> drugaUrojona;
    
    Zespolona pierwszaZespolona = Zespolona(pierwszaRzeczywista, pierwszaUrojona);
    Zespolona drugaZespolona = Zespolona(drugaRzeczywista, drugaUrojona);
    
    Zespolona suma = pierwszaZespolona + drugaZespolona;
    Zespolona roznica = pierwszaZespolona - drugaZespolona;
    
    cout << "a = " << pierwszaZespolona << endl;
    cout << "b = " << drugaZespolona << endl;
    cout << "a + b = " << suma << endl;
    cout << "a - b = " << roznica << endl;
    
    cin.ignore();
    cin.get();
    return 0;   
}
