#include <stdio.h>
int main()
{
    int a=0,b=0,c=0,d=0;
    printf("Zadej 1. cislo: ");
    scanf("%d",&a);
    printf("Zadej 2. cislo: ");
    scanf("%d",&b);
    for(;;){d=d+a;c++;if(c==b)break;}
    printf("%d*%d=%d",a,b,d);
    getchar();getchar();
}
