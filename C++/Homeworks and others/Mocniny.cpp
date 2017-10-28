#include <stdio.h>
#include <windows.h>

int main()
{
    int c1, c2, vys = 1;
    char x;
    
    do {
        printf("Zadej cislo a * a cislo: ");
        scanf("%d%c%d", &c1, &x, &c2);
    } while(x != '*');
    
    for(;c2 > 0;c2--) {
        vys = vys*c1;
    }
    
    printf("=%d\n\n", vys);
    system("pause");
    return 0;
    
}
