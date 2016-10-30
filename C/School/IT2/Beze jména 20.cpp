#include <stdio.h>
#include <windows.h>
#include <time.h>

int main()
{
    srand(time(0));
    
    int i, j, k, temp;
    int array[8][8], numbers[8] = {0}, ascii[256];
    
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            array[i][j] = rand() % 2;
            temp = 1;
            
            for(k = 7; k > j; k--)
            {
                temp *= 2;
            }
            
            numbers[i] += array[i][j] * temp;
            printf("%d", array[i][j]);
        }
        
        printf(" = %d - %c\n", numbers[i], numbers[i]);
    }
    
    /*for(i = 0; i < 16; i++)
    {
        for(j = 0; j < 16; j++)
        {
            ascii[i][j] = i * j;
        }
    }*/
    
    printf("\n");
    system("pause");
}
