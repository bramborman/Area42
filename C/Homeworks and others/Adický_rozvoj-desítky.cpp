#include <stdio.h>
int main()
{int cislo,desitky,jednotky;
    printf("Zadej 2cif. cislo: ");
    scanf("%d",&cislo);
    desitky=cislo/10;
    jednotky=cislo%10;
    if(cislo/100>=1){
        printf("Cislo musi byt dvojciferne!");
    }
    else{
        printf("V cisle jsou %d desitky a %d jednotek.",(desitky),(jednotky));
    }
    printf("\n\n\n(C) 2014 Marian Dolinsky");
    getchar();getchar();
}
