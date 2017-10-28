#include <stdio.h>
#include <windows.h>

int main()
{
    int x = 0, y, z;
    
    printf("Zadej cislo: ");
    scanf("%d",&x);
    
    for(y = 1; y <= x; y++) {
        for(z = 1; z < y; z++) {
            printf(" ");
        }
        for(z = x; z >= y; z--) {
            printf("*");
        }
    printf("\n");
    }
    
    printf("\n\n");
    system("pause");
    return 0;
}
