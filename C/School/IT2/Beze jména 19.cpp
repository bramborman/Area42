#include <stdio.h>
#include <windows.h>

int main()
{
    int i, j, x, y;
    
    do
    {
        printf("Zadej vysku: ");
        scanf("%d", &y);
    } while(y < 1 || y > 24);
    
    do
    {
        printf("Zadej sirku: ");
        scanf("%d", &x);
    } while(x < 1 || x > 26);
    
    system("cls");
    int array[y][x];
    
    for(i = 0; i < (25 - y) / 2; i++)
    {
        printf("\n");
    }
    
    for(i = 0; i < (80 - x) / 2 + (y < 10 ? 1 : 2); i++)
    {
        printf(" ");
    }
    
    for(i = 0; i < x; i++)
    {
        printf("%c", i + 65);
    }
    
    printf("\n");
    
    for(i = 0; i < y; i++)
    {
        for(j = 0; j < (80 - x) / 2; j++)
        {
            printf(" ");
        }
        
        printf(y < 10 ? "%d" : i + 1 < 10 ? "0%d" : "%d", i + 1);
        
        for(j = 0; j < x; j++)
        {
            array[i][j] = (i % 2 == j % 2 ? 219 : 0);
            printf("%c", array[i][j]);
        }
        
        if(i != y -1)
        {
            printf("\n");
        }
    }
    
    getchar(); getchar();
}

