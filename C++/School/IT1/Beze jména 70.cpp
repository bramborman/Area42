#include <stdio.h>
#include <windows.h>

int main()
{
    int p, x, y, z;
    
    system("color 0A");
    
    do
    {
        printf("Zadej velikost plachty: ");
        scanf("%i", &p);
    } while(p<3 || p>14);
    system("cls");
    
    for(x=1; x<=p; x++)
    {
        for(z=p; z>=1; z--) printf(" ");
        for(y=1; y<=x; y++) printf("*");
        printf("\n");
    }
    for(z=p; z>=1; z--) printf(" ");
    printf("*\n");
    for(z=p; z>=1; z--) printf(" ");
    printf("*\n");
    
    for(x=p/2; x>=1; x--)
    {
        for(z=1; z<=p/2-x; z++) printf(" ");
        for(y=p*2; y>=1; y-=2) printf("*");
        printf("\n");
    }
    
    system("pause");
}
