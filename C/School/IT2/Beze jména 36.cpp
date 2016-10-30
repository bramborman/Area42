#include <stdio.h>
#include <windows.h>

void rozklad(int x)
{
    for(int i = x; i >= 0; i--)
    {
        printf("%d + %d = %d\n", i, x - i, x);
    }
    
    printf("\n");
    
    int j;
    
    for(int i = 1; i <= x; i++)
    {
        for(j = x; j > i; j--)
        {
            printf("1 + ");
        }
        
        printf("%d = %d\n", j, x);
    }
    
    return;
}

int main()
{
    int x;
    
    do
    {
        printf("Zadej cislo: ");
        scanf("%d", &x);
    } while(x < 0);
    
    rozklad(x);
    
    printf("\n\n");
    system("pause");
}
