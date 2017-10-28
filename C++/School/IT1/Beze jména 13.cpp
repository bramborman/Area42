#include <stdio.h>
int main()
{
    int cislo;
    printf("Zadej cislo: ");
    scanf("%d",&cislo);
    if(cislo%2==0)printf("Cislo je sude.");
    if(cislo%2==1)printf("Cislo je liche.");
    getchar();getchar();
}
