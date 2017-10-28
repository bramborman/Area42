#include <stdio.h>
#include <windows.h>

int main()
{
    int x, y, v = 0;
    
    printf("Zadej 2 cisla: ");
    scanf("%i%i", &x, &y);
    
    for(; x > 0; x--) v += y;
    
    printf("\n%i\n", v);
    
    system("pause");
}
