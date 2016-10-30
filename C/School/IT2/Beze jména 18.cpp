#include <stdio.h>
#include <windows.h>
#include <time.h>

int main()
{
    srand(time(0));
    
    int i, j;
    int array[5][5];
    
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            array[i][j] = rand() % 10;
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    
    system("pause");
}
