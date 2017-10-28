#include <stdio.h>
#include <windows.h>

int main()
{
    int x[4] = {65, 66, 67, 68}, i;
    
    for(i = 0; i < 4; i++)
    {
        printf("%c\n", x[i]);
    }
    
    system("pause");
}
