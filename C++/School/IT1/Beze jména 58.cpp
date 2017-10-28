#include <stdio.h>
#include <windows.h>

int main()
{
    int c, x, y;
    char z;
    
    system("color 0A");
    printf("Zadej cislo: ");
    scanf("%d", &c);getchar();
    printf("Zadej znak: ");
    scanf("%c", &z);
    printf("\n");
    
    for(x = c; x > 0; x--) {
        for(y = x; y > 0; y--) printf("%c", z);
        printf("\n");
    }
    
    for(x = 1; x <= c; x++) {
        for(y = 1; y <= x; y++) printf("%c", z);
        printf("\n");
    }
    
    printf("\n");
    system("pause");
    return 0;
}
