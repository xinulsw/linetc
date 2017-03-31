#include <cstdlib>
#include <iostream>

using namespace std;

const int N = 19; 	//liczba element¢w w sortowanym zbiorze

void wypelnij(int tablica[], int n)
{
  for (int i=0; i<n; i++)
  tablica[i] = rand()%11;
}

void wyswietl(int tablica[], int n)
{
  for (int i=0; i<n; i++)
  cout << tablica[i] << "  ";
  cout << endl;
}

void wyswietl2(int tablica[], int x, int y)
{
  for (int i=x; i<=y; i++)
  cout << tablica[i] << "  ";
  cout << endl;
}

void Merge(int d[], int pocz, int kon)
{
  cout << "wej˜cie: Merge(" << pocz << "," << kon << "): ";
  wyswietl2(d,pocz,kon);
  int i, i1, i2, sr;
  int temp[N];   	//tablica pomocnicza, do niej przepiszemy elementy tablicy d

  for (i=0; i<N;i++)
    temp[i] = d[i];
  sr = (pocz+kon)/2;
  i = pocz;   		//indeks “wedrujacy” po tablicy d
  i1 = pocz;  		//indeks “wedrujacy” po pierwszej polowce tablicy temp
  i2 = sr+1;  		//indeks “wedrujacy” po drugiej polowce tablicy temp
  while (i1<=sr && i2<=kon) {
    if (temp[i1]<temp[i2]) {
      d[i] = temp[i1];
      i1++;
    } else {
      d[i]=temp[i2];
      i2++;
    }
    i++;
  }
  if (i1>sr)
    while (i2<=kon) {
      d[i] = temp[i2];
      i2++; i++;
    }
  else
    while (i1<=sr) {
      d[i]=temp[i1];
      i1++; i++;
    }
  cout << "wyj˜cie: ";
  wyswietl2(d,pocz,kon);
}

void MergeSort(int d[], int pocz, int kon)
{
  cout << "MergeSort(" << pocz << "," << kon << "): ";
  wyswietl2(d,pocz,kon);
  int sr;
  sr = (pocz+kon)/2;
  if (pocz<sr)
    MergeSort(d,pocz,sr);
  if (sr+1<kon) 
    MergeSort(d,sr+1,kon);
  Merge(d,pocz,kon);
}

int main(int argc, char *argv[])
{
  int tab[20];
  int tabt[] = {3,2,3,8,4,1};
  int n = 6;
  srand(time(NULL));
  wypelnij(tab,n);
  cout << "Tablica przed sortowaniem: " << endl;
  wyswietl(tabt,n);
  MergeSort(tabt,0,n-1);
  cout << "\n\nTablica po posortowaniu: " << endl;
  wyswietl(tabt,n);
  cout << endl;
  system("PAUSE");
  return EXIT_SUCCESS;
}
