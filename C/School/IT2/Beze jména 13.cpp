#include <stdio.h>
#include <windows.h>

int main()
{
    int num, count = 0, array[16] = {0}, chars[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 65, 66, 67, 68, 69, 70};
    
    do
    {
        printf("Zadej cislo: ");
        scanf("%d", &num);
    } while(num < 0 || num > 255);
    
    do
    {
        array[count] = num % 16;
        num /= 16;
        count++;
    } while(num != 0);
    
    for(count--; count >= 0; count--) printf((chars[array[count]] < 10 ? "%d" : "%c"), chars[array[count]]);
    
    printf("\n");
    system("pause");
}
