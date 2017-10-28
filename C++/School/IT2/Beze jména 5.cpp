#include <stdio.h>
#include <windows.h>

int main()
{
    int x, y;
    
    printf("Zadej cislo: ");
    scanf("%d", &x);
    
    do
    {
        y = x%10;
        x /= 10;
        printf("%d\n", y);
    } while(x > 0);
    
    system("pause");
}
