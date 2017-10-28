#include <stdio.h>
int main()
{int km,eur,kc;
    printf("Zadej pocet km: ");
    scanf("%d",&km);
    printf("Zadej pocet EUR za km: ");
    scanf("%d",&eur);
    printf("Zadej kurz EUR na CZK: ");
    scanf("%d",&kc);
    printf("Zaplatis za %d km %d EUR tj %d Kc.",(km),(km*eur),(km*eur*kc));
    getchar();getchar();
}
