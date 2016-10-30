#include <stdio.h>
#include <windows.h>

int main()
{
    int x = 0, y, z;
    
    printf("Zadej cislo: ");
    scanf("%d",&x);
    
    if(x <= 40 && x > 0) {
        for(y = 1; y <= x; y++) {
            for(z = x; z > y; z--) {
                printf(" ");
            }
            for(z = 2; z <= 2*y; z++) {
                printf("o");
            }
        printf("\n");
        }
    }
    else printf("ERROR");
    
    printf("\n\n");
    system("pause");
    return 0;
}
