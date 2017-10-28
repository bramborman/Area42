#include <stdio.h>
int main()
{
    int km, cena;
    printf("Zadej pocet kilometru: ");
    scanf("%d",&km);
    
    if(km>=0&&km<=10)cena=km*50;
    if(km>10&&km<=50)cena=km*45;
    if(km>50&&km<=100)cena=km*40;
    if(km>100)cena=km*35;
    
    printf("Cena za taxi bude: %d.",cena);
    getchar();getchar();
}
