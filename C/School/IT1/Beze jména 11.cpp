#include <stdio.h>
int main()
{
    int cislo;
    printf("Zadej cislo: ");
    scanf("%d",&cislo);
    if(cislo==1)printf("zelena");
    if(cislo==2)printf("oranzova");
    if(cislo==3)printf("cervena");
    if(cislo<1)printf("chyba");
    if(cislo>3)printf("chyba");
    getchar();getchar();
}
