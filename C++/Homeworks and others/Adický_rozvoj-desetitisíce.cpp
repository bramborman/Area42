#include <stdio.h>
int main()
{int cislo,cislo2,cislo3,cislo4,destisice,tisice,stovky,desitky,jednotky;
    printf("Zadej 5cif. cislo: ");
    scanf("%d",&cislo);
    destisice=cislo/10000;
    cislo2=cislo%10000;
    tisice=cislo2/1000;
    cislo3=cislo2%1000;
    stovky=cislo3/100;
    cislo4=cislo3%100;
    desitky=cislo4/10;
    jednotky=cislo4%10;
    printf("\nV cisle je\n   %d desetitisicu\n   %d tisicu\n   %d stovek\n   %d desitek\n   %d jednotek.",destisice,tisice,stovky,desitky,jednotky);
    getchar();getchar();
}
