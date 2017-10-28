#include <stdio.h>
int main()
{
    float vysledek=0,cislo1=0,cislo2=0,ok=0;
    char operace=0;
    printf("Zadej prvni cislo: ");
    scanf("%f",&cislo1);getchar();
    printf("Zadej operaci: ");
    scanf("%c",&operace);
    printf("Zadej druhe cislo: ");
    scanf("%f",&cislo2);
    if(operace=='+')vysledek=cislo1+cislo2;
    if(operace=='-')vysledek=cislo1-cislo2;
    if(operace=='*')vysledek=cislo1*cislo2;
    if(cislo2==0){if(operace=='/'){printf("Nulou nelze delit!");ok=1;}}
    else if(operace=='/')vysledek=cislo1/cislo2;
    if(ok!=1)printf("%.2f%c%.2f=%.2f",cislo1,operace,cislo2,vysledek);
    getchar();getchar();
}
