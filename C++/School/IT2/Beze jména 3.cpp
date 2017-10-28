#include <stdio.h>
#include <windows.h>
#include <time.h>

int main()
{
    int c, x;
    srand(time(0));
    
    for(x = 1; x <= 30; x++)
    {
        c = rand()%50 + 50;
        printf("%d ", c);
        if(x%10 == 0) printf("\n");
    }
    
    system("pause");
}
