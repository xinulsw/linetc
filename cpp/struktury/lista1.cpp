#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

struct el_listy {
	int liczba;
	el_listy *nast;
};

void delLista(el_listy *glowa) {
	el_listy *tmp;
	while (glowa != NULL) {
		tmp = glowa;
		glowa = glowa->nast;
		delete tmp;
	}
}

char czy() {
	char odp;
	cout << "Następny element? (t/n) ";
	cin >> odp;
	return odp;
}

int getD() {
	int d;
	cout << "Podaj liczbę: ";
	cin >> d;
	return d;
}

void drukuj(el_listy *glowa) {
	el_listy *tmp;
	tmp = glowa;
	while(tmp != NULL) {
		cout << tmp->liczba << " ";
		tmp = tmp->nast;
	}
	cout << endl;
}

int addToB() {
	el_listy *glowa = NULL;
	el_listy *nowy;

	while(czy() != 'n') {
		try {
			nowy = new el_listy; //tworzenie nowej struktury
		} catch(bad_alloc) {
			cout << "Brak pamięci!";
			return -1;
		}
		nowy->nast=glowa;
		nowy->liczba=getD();
		glowa = nowy;
	}

	cout << "Oto lista: " << endl;
	drukuj(glowa);
	delLista(glowa);
	return 0;
}

int addToE() {
	el_listy *glowa = NULL;
	el_listy *ogon = NULL;
	el_listy *nowy;

	while (czy() != 'n') {
		try {
			nowy = new el_listy;
		} catch(bad_alloc) {
			cout << "Brak pamięci";
			return -1;
		}
		nowy->nast = NULL;
		nowy->liczba = getD();
		if (glowa == NULL) {
			glowa = nowy;
			ogon = glowa;
		} else {
			ogon->nast = nowy;
			ogon = nowy;
		}
	}
	drukuj(glowa);
	return 0;
}

int main(int argc, char *argv[]) {
	addToB();
	addToE();
   return 0;
}
