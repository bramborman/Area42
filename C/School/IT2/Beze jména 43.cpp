#include <stdio.h>
#include <windows.h>

int main()
{
    char str[10];
    
    printf("Napis slovo: ");
    scanf("%10s", str);
    
    for(int i = 0; i < 11; i++)
    {
        putchar('\n');
    }
    
    for(int i = 0; i < (80 - strlen(str)) / 2; i++)
    {
        putchar(' ');
    }
    
    for(int i = 0; i < strlen(str); i++)
    {
        putchar(str[i]);
    }
    
    system("pause");
}    
