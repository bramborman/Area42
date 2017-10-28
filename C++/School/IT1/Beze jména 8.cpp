#include <stdio.h>
int main()
{
    int cislo,a,b;
    printf("Zadej 4-mistne cislo: ");
    scanf("%d",&cislo);
    a=(cislo/10)%10;
    b=(cislo/100)%10;
    printf("soucet 2. a 3. cislice je: %d",a+b);
    getchar();getchar();
}
