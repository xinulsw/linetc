#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

char alfabet_o[] = "abcdefghijklmnopqrstuvwxyz\0";
char alfabet_w[] = ".,;'[]{}|<>?!@#$%^&*()-_+=\0";

void koduj (char* tekst) {
	int dl_tekstu = (int) strlen(tekst);
	int dl_alfabetu = (int) strlen(alfabet_o);
	
	for(int i=0; i<dl_tekstu; i++) {
		for(int j=0; j<dl_alfabetu; j++) {
			if (tekst[i] == alfabet_o[j]) {
				tekst[i] = alfabet_w[j];
				break;
			}
		}
	}
}

void dekoduj (char* tekst) {
	int dl_tekstu = (int) strlen(tekst);
	int dl_alfabetu = (int) strlen(alfabet_w);
	
	for(int i=0; i<dl_tekstu; i++) {
		for(int j=0; j<dl_alfabetu; j++) {
			if (tekst[i] == alfabet_w[j]) {
				tekst[i] = alfabet_o[j];
				break;
			}
		}
	}
}

void koduj_dekoduj(char* tekst, int tryb) {
	char *a_wynik, *a_zrodlo;
	int dl_tekstu = (int) strlen(tekst);
	int dl_alfabetu = (int) strlen(alfabet_o);
	
	if (tryb == 1) {//kodowanie
		a_zrodlo = alfabet_o;
		a_wynik = alfabet_w;
	} else {//dekodowanie
		a_zrodlo = alfabet_w;
		a_wynik = alfabet_o;
	}
	
	for(int i=0; i<dl_tekstu; i++) {
		for(int j=0; j<dl_alfabetu; j++) {
			if (tekst[i] == a_zrodlo[j]) {
				tekst[i] = a_wynik[j];
				break;
			}
		}
	}
}

char tab_kod[256];
char tab_dekod[256];

void przygotuj_tb_kod() {
	int dl_alfabetu = (int) strlen(alfabet_o);
	for (int i=0; i<256; i++) {
		tab_kod[i] = i;
		tab_dekod[i] = i;
	}
	
	for (int i=0; i<dl_alfabetu; i++) {
		tab_kod[(int)alfabet_o[i]] = alfabet_w[i];
		tab_dekod[(int)alfabet_w[i]] = alfabet_o[i];
	}
}

void szyfruj_szybko(char* tekst, int tryb) {
	char* tab_kodow;
	if (tryb == 1){//kodowanie
		tab_kodow = tab_kod;
	} else {//dekodowanie
		tab_kodow = tab_dekod;
	}
	
	int dl_tekstu = (int) strlen(tekst);
	for(int i=0; i<dl_tekstu; i++){
		tekst[i] = tab_kodow[(int)tekst[i]];
	}
}
int main () {
	char bufor[100];
	cout << "Wprowadź tekst: ";
	fgets(bufor,100,stdin);
	
	//koduj(bufor);
	//koduj_dekoduj(bufor,1);
	przygotuj_tb_kod();
	szyfruj_szybko(bufor,1);
	cout << "Po zakodowaniu: " << bufor;
	//dekoduj(bufor);
	//koduj_dekoduj(bufor,2);
	szyfruj_szybko(bufor,2);
	cout << "Po zdekodowaniu: " << bufor;
	exit (0);
}
