#include <stdio.h>
#include <windows.h>
#include <time.h>

int main()
{
    srand(time(0));
    
    int count, i, j, temp;
    
    do
    {
        printf("Zadej velikost pole: ");
        scanf("%d", &count);
    } while(count < 1);
    
    int array[count], kladne[count], zaporne[count], k = 0, z = 0;
    
    for(i = 0; i < count; i++)
    {
        array[i] = rand() % 41 - 20;
    }
    
    for(i = 0; i < count; i++)
    {
        for(j = i + 1; j < count; j++)
        {
            if(array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        
        if(array[i] >= 0)
        {
            kladne[k] = array[i];
            k++;
        }
        else
        {
            zaporne[z] = array[i];
            z++;
        }
    }
    
    printf("kladne:");
    
    for(i = 0; i < k; i++)
    {
        printf(" %d", kladne[i]);
    }
    
    printf("\nzaporne:");
    
    for(i = 0; i < z; i++)
    {
        printf(" %d", zaporne[i]);
    }
    
    printf("\n");
    system("pause");
}
