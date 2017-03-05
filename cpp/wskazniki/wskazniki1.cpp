#include <iostream>
#include <cstdio>

using namespace std;

void zmien(int *wsk) {
  *wsk = *wsk+10;
}

int main(int argc, char *argv[]) {
  int i = 13;
  int *wsk1;
  wsk1 = &i;
  cout << "Wskaźnik typu integer wskazuje na 'i' o wartości: " << *wsk1 << endl;
  cout << "Wartość wskaźnika: " << wsk1 << endl;
  cout << "Adres zmiennej 'i': " << &i << endl;

  int j = 10;
  int *wsk2;
  wsk2 = &j;
  int a = 0;
  cout << "Wartość 'a': " << a << endl;
  a = *wsk1 + *wsk2;
  cout << "Wartość 'a': " << a << endl;
  cout << "Wartość 'i': " << i << endl;
  *wsk1 = *wsk1 +3;
  cout << "Wartość 'i': " << i << endl;
  cout << "Wartość 'j': " << j << endl;
  *wsk2 = *wsk1;
  zmien(wsk1);
  cout << "Wartość 'j': " << j << endl;
  cout << "Wskaźnik wsk1 wskazuje na: " << *wsk1 << endl;
  cout << "Wskaźnik wsk2 wskazuje na: " << *wsk2 << endl;
  wsk1=wsk2;
  cout << "Wskaźnik wsk1 wskazuje na: " << *wsk1 << endl;
  cout << "Wskaźnik wsk2 wskazuje na: " << *wsk2 << endl;
  return 0;
}
