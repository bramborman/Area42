#include <stdio.h>
#include <windows.h>

int main()
{
    int c1, c2, v = 0, x;
    
    system("color 0A");
    printf("Zadej 1. cislo: ");
    scanf("%d", &c1);
    printf("Zadej 2. cislo: ");
    scanf("%d", &c2);
    printf("\n");
    
    for(x = 1; x <= c2; x++) v += c1;
    
    printf("vysledek: %d", v);
    printf("\n");
    system("pause");
    return 0;
}
