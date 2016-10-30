#include <stdio.h>
int main()
{
    int a,b,x;
    printf("Zadej dve hodnoty: ");
    scanf("%d%d",&a,&b);
    x=(a>b ? a:b);
    printf("%d",x);
    getchar();getchar();
}
