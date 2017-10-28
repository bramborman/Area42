#include <stdio.h>
int main()
{int cislo;
    printf("Zadej cislo: ");
    scanf("%d",&cislo);
    if(cislo>0)printf("Cislo je kladne.");
    if(cislo<0)printf("Cislo je zaporne.");
    getchar();getchar();
}
