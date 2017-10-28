#include <stdio.h>
#include <windows.h>
#include <time.h>

int main()
{
    srand(time(0));
    int count, i, j, temp;
    
    printf("Zadej velikost pole: ");
    scanf("%d", &count);
    
    int array[count];
    
    for(i = 0; i < count; i++)
    {
        array[i] = rand() % 101 - 50;
    }
    
    for(i = 0; i < count; i++)printf("%d ", array[i]);
    printf("\n");
    
    for(i = 0; i < count; i++)
    {
        for(j = i; j < count; j++)
        {
            if(array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    
    for(i = 0; i < count; i++)printf("%d ", array[i]);
    printf("\n");
    system("pause");
}
