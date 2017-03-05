#include <cstdlib>
#include <iostream>

using namespace std;

void drukuj(char znak, int ile) {
  for (int i=0; i<=ile; i++) 
    cout << znak;
  cout << endl;
}

int main(int argc, char *argv[])
{
char znak;
int ile;
cout << "Wprowadz znak..." << endl;
cin >> znak;
cout << "Wprowadz ilosc powtorzen..." << endl;
cin >> ile;
drukuj(znak,ile);
cout << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
