#include <stdio.h>
#include <windows.h>
#include <locale.h>

int main()
{
    int o, y, z, d=1, v=0;
    system("color 0A");
    setlocale(LC_ALL, "");
    
    do
    {
        printf("Zadej èíslo 3-7: ");
        scanf("%d", &o);
    } while(o!=3 && o!=5 && o!=7);
    
    for(;o>=1;o--)
    {
        do
        {
            printf("Zadej èíslici: ");
            scanf("%d", &y);
        } while(y<0 || y>9);
        
        d=1;
        for(z=o; z>1; z--) d*=10;
        v+=y*d;
    }
    
    if(v%2==0) printf("%d - sudé\n", v);
    else printf("%d - liché\n", v);
    system("pause");
}
