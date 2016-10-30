#include <stdio.h>
#include <windows.h>

#define POW(a) a = a * a

int main()
{
    int x = 3;
    
    POW(x);
    printf("%d\n", x);
    
    system("pause");
}
