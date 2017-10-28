#include <stdio.h>
int main()

{
    int c1, c2, r=0;
    printf("Zadej 1. cislo: ");
    scanf("%d",&c1);
    
    do {
       printf("Zadej 2. cislo: ");
       scanf("%d",&c2);
    }
    while(c1 >= c2);
    
    r=(c2-c1)/2;
    printf("Pocet sudych cisel: %d",r);
    
    getchar();getchar();
}
