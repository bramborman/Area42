#include <stdio.h>
#include <windows.h>

int main()
{
    char ascii[256], block[20];
    int x;
    
    for(int i = 0; i < 256; i++)
    {
        ascii[i] = i;
    }
    
    do
    {
        printf("Zadej cislo: ");
        scanf("%d", &x);
    } while(x < 0 || x > 235);
    
    for(int i = x; i < x + 20; i++)
    {
        block[i - x] = i;
        putchar(block[i - x]);
    }
    
    putchar('\n');
    system("pause");
}
