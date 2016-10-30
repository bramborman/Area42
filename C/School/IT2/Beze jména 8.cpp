#include <stdio.h>
#include <windows.h>

int main()
{
    int x[3], i;
    
    for(i = 0; i < 3; i++)
    {
        printf("Zadej %d. cislo: ", i + 1);
        scanf("%d", &x[i]);
    }
    
    for(i = 0; i < 3; i++)
    {
        printf("%d. cislo: %d\n", i + 1, x[i]);
    }
    
    system("pause");
}
