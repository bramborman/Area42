#include <stdio.h>
#include <windows.h>

int add(const int X, const int Y)
{
    return X + Y;
}

int main()
{
    printf("%d\n", add(1, 2));
    
    system("pause");
    return 0;
}
