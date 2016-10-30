#include <stdio.h>
int main()
{
    int cislo1,cislo2,x;
    printf("Zadej 1. cislo: ");
    scanf("%d",&cislo1);
    printf("Zadej 2. cislo: ");
    scanf("%d",&cislo2);
    if(cislo1<cislo2)x=cislo1;
    if(cislo1>cislo2)x=cislo2;
    if(x>0)printf("Cislo je kladne.");
    if(x<0)printf("Cislo je zaporne.");
    getchar();getchar();
}
