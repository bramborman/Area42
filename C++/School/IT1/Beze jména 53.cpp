#include <stdio.h>
#include <windows.h>

int main()

{
    char x = 0, y = 1;
    
    for(x = 1; x <= 4 ; x++)
    {
        for(y = 1; y <= x; y++) printf("*");
        printf("\n");
    }
    
    system("pause");
    return 0;
}
