#include <stdio.h>
#include <windows.h>

#define ABS(a) if(a < 0) a *= -1;

int main()
{
    int x = -5;
    
    ABS(x);
    printf("%d\n", x);
    system("pause");
}
