#include <stdio.h>
int main()
{int cislo,cislo2,cislo3,tisice,stovky,desitky, jednotky;
    printf("Zadej 4cif. cislo: ");
    scanf("%d",&cislo);
    tisice=cislo/1000;
    cislo2=cislo%1000;
    stovky=cislo2/100;
    cislo3=cislo%100;
    desitky=cislo3/10;
    jednotky=cislo3%10;
    printf("V cisle je %d tisice\n%d stovky\n%d desitky\n%d jednotky.",(tisice),(stovky),(desitky),(jednotky));
    getchar();getchar();
}
