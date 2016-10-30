#include <stdio.h>
#include <windows.h>

int main()
{
    int i, j, columns, rows;
    
    do
    {
        printf("Zadej sirku pole: ");
        scanf("%i", &columns);
    } while(columns < 1);
    
    rows = (columns / 2) + 1;
    
    char array[rows][columns];
    
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            array[i][j] = (j >= columns / 2 && j < (columns / 2) + i ? '*' : '0');
            printf("%c", array[i][j]);
        }
        
        printf("\n");
    }
    
    system("pause");
}
