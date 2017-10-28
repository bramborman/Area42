#include <stdio.h>
#include <windows.h>

int main()
{
    int x[3], i;
    
    for(i = 0; i < 3; i++)
    {
        printf("%d\n", x[i] = i+1);
    }
    
    system("pause");
}
