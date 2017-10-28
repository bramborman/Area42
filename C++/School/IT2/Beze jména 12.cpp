#include <stdio.h>
#include <windows.h>

int main()
{
    int num, count = 0, array[16] = {0};
    
    do
    {
        printf("Zadej cislo: ");
        scanf("%d", &num);
    } while(num < 0 || num > 65535);
    
    do
    {
        array[count] = num % 2;
        num /= 2;
        count++;
    } while(num != 0);
    
    for(count--; count >= 0; count--) printf("%d", array[count]);
    
    printf("\n");
    system("pause");
}
