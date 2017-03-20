/*
 * stos.cpp
 *
 * Copyright 2017 smaster <smaster@atsbox>
 *
 */


#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

void push(int stack[], int sr, int &sp, int dane) {
    sp++;
    if (sp > -1 && sp < sr + 1) {
        stack[sp] = dane;
        cout << dane << " ";
    } else {
        cout << sp << " - stack overflow!\n";
        sp = - 1;
    }
}

int pop(int stack[], int sr, int &sp) {
    int dane = 0;
    if (sp > -1 && sp < sr + 1) {
        dane = stack[sp];
        sp--;
    } else {
        cout << sp << " - stack overflow!\n";
        sp = - 1;
    }
    return dane;
}

int main(int argc, char **argv) {
    int sr = 0; // rozmiar stosu
    int *stack = NULL; // wskaźnik do stosu
    int sp = 0; // wskaźnik stosu

    cout << "Podaj rozmiar stosu: ";
    cin >> sr;
    if (!cin)
    {
        cout << "Błędne dane!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

	stack = new int[sr];

    srand(time(NULL));
    for (int i=0; i < sr; i++)
        push(stack, sr, sp, rand()%100 + 1);

    cout << endl;
    for (int i=0; i < sr; i++)
        cout << pop(stack, sr, sp) << " ";

    cout << endl;
	return 0;
}

