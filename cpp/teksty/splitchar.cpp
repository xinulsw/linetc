#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;


int main(int argc, char **argv){
	char linia[255];
    char *wskch;
	cout << "Wprowadź linię: ";
	cin.getline(linia,255); // Cała linia razem z znakami "bialymi" (spacja tab);
    wskch = strtok(linia, " ");
	while(wskch != NULL) {
		printf ("%s\n",wskch);
        wskch = strtok(NULL, " ");
	}
	return 0;
}
