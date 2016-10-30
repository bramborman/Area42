#include <stdio.h>
#include <windows.h>

int main()
{
    int x, y;
    for(x = 4;x>=1;x--) {
        for(y = 1;y<=x;y++)printf("*");
        printf("\n");
    }
    system("pause");
}
