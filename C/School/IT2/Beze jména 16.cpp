//------------------------------------------------------
//
//   Vygeneruj 5 èísel (0 - 50) a vypiš setøídìné
//   do dalších dvou polí na sudé a liché.
//
//------------------------------------------------------

#include <stdio.h>
#include <windows.h>
#include <time.h>

int main()
{
    srand(time(0));
    
    int i, j, temp, s = 0, l = 0;
    int array[5], sude[5], liche[5];
    
    for(i = 0; i < 5; i++)
    {
        array[i] = rand() % 51;
        printf("%d ", array[i]);
    }
    
    for(i = 0; i < 5; i++)
    {
        for(j = i + 1; j < 5; j++)
        {
            if(array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
            
        if(array[i] % 2 == 0)
        {
            sude[s] = array[i];
            s++;
        }
        else if(array[i] % 2 == 1)
        {
            liche[l] = array[i];
            l++;
        }
    }
    
    printf("\n\nsude: ");
    
    for(i = 0; i < s; i++)
    {
        printf("%d ", sude[i]);
    }
    
    printf("\nliche: ");
    
    for(i = 0; i < l; i++)
    {
        printf("%d ", liche[i]);
    }
    
    printf("\n\n");
    
    system("pause");
}
