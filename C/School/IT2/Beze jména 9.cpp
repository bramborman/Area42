#include <stdio.h>
#include <windows.h>

int main()
{
    int i;
    float x[3] = {0};
    
    for(i = 0; i < 3; i++)
    {
        printf("%.1f\n", x[i]);
    }
    
    system("pause");
}
