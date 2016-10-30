#include <stdio.h>
int main()
{int cislo,a,b,c,d,e,f,g,i,n;
    printf("Zadej cislo od 0 do 15: ");
    scanf("%d",&n);
    b=n/2;
    c=n%2;
    d=b/2;
    e=b%2;
    f=d/2;
    g=d%2;
    i=f%2;
    printf("%d%d%d%d",i,g,e,c);
    getchar();getchar();
}
