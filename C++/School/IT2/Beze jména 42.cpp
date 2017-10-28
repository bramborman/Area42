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
    
    for(int j = 0; j < (80 - strlen(str)) / 2; j++)
    {
        putchar(' ');
    }
    
    printf("%s\n\n", str);
    
    system("pause");
}    
