#include <stdio.h>
#include <windows.h>

int nas(const int X, const int Y)
{
    int i = 0;
    
    for(; i / Y != X; i += Y);
    
    return i;
}

int main()
{
    int x, y;
    
    printf("Zadej 1. cislo: ");
    scanf("%d", &x);
    
    printf("Zadej 2. cislo: ");
    scanf("%d", &y);
    
    printf("%d x %d = %d\n\n", x, y, nas(x, y));
    
    system("pause");
}
