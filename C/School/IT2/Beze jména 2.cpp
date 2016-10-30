#include <stdio.h>
#include <windows.h>

int main()
{
    int i, p, c, min, max;
    
    do
    {
        printf("Zadej pocet zadavani: ");
        scanf("%d", &p);
    } while(p < 1);
    
    for(i = 1; i <= p; i++)
    {
        printf("Zadej %d. cislo: ", i);
        scanf("%d", &c);
        
        if(i == 1)
        {
            min = c;
            max = c;
        }
        if(min > c) min = c;
        if(max < c) max = c;
    }
    printf("minimalni: %d\nmaximalni: %d\n", min, max);
    system("pause");
}
