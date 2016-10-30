#include <stdio.h>
#include <windows.h>

int faktorial(int x)
{
    int f = 1;
    
    printf("1 * ");
    
    for(int i = 2; i <= x; i++)
    {
        f *= i;
        
        printf("%d * ", i);
    }
    
    printf("\b\b= ");
    return f;
}

int main()
{
    int x;
    
    do
    {
        printf("Zadej cislo: ");
        scanf("%d", &x);
    } while(x < 0 || x > 10);
    
    printf("%d! = ", x);
    
    x = faktorial(x);
    printf("%d\n\n", x);
    
    system("pause");
}
