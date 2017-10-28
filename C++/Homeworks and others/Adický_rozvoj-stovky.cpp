#include <stdio.h>
int main()
{int cislo,cislo2,stovky,desitky, jednotky;
    printf("Zadej 3cif. cislo: ");
    scanf("%d",&cislo);
    stovky=cislo/100;
    cislo2=cislo%100;
    desitky=cislo2/10;
    jednotky=cislo2%10;
    printf("V cisle je %d stovek, %d desitek a %d jednotek.",(stovky),(desitky),(jednotky));
    getchar();getchar();
}
