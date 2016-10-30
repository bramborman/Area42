#include <stdio.h>
#include <windows.h>

void printnumber(const int NUMBER)
{
    printf("%d", NUMBER);
    return;
}

int main()
{
    int x;
    
    printnumber(10);
    printf("\n");
    
    scanf("%d", &x);
    printnumber(x);
    
    printf("\n");
    system("pause");
    
    return 0;
}
