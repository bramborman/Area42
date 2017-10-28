#include <stdio.h>

int main()
{
    int c1, c2, c3, c4;
    
    printf("Zadej 4-cif cislo: ");
    scanf("%i%i%i%i", &c1, &c2, &c3, &c4);
    
    if((c1==0 || c1==1) && (c2==0 || c2==1) && (c3==0 || c3==1) && (c4==0 || c4==1)) printf("Cislo je binarni.");
    else printf("Cislo je desitkove4.");
    getchar();getchar();
}
