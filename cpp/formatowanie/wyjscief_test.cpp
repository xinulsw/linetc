#include <iostream> // std::cout, std::ios, std::endl
#include <iomanip> // std::setiosflags
#include <cstdio> // printf
#include <math.h> //stała M_PI

using namespace std;

int main(int argc, char **argv){

    int tab[4];
    for (int i = 0; i < 4; i++)
        tab[i] = i;

    printf("\e[1;40H%i", tab[1]);
    printf("\e[4;20H%i", tab[2]);
    
    return 0;
}
