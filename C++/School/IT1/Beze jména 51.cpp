#include <stdio.h>
#include <windows.h>

int main()

{
    char x = 0, y = 1, v = 0;
    
    do {
        v = 0;
        printf("Zadej cislo: ");
        scanf("%d",&x);
        
        for(y = 1;y <= x; y++) {
            if(y%3 != 0) printf("%d, ", y);
            else v += y;
        }
        printf("%d\n\n", v);
    } while(v%2 == 0);
    
    system("pause");
    return 0;
}
