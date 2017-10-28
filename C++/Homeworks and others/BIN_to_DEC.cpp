#include <stdio.h>
int main()
{int bin,c1,c2,c3,c4,m2,m3,vys;
    printf("Zadej 4-mistne binarni cislo: ");
    scanf("%d",&bin);
    c1=bin/1000;
    m2=bin%1000;
    c2=m2/100;
    m3=m2%100;
    c3=m3/10;
    c4=m3%10;
    vys=(c1*2*2*2)+(c2*2*2)+(c3*2)+c4;
    printf("\n%d = %d",bin,vys);
    getchar();getchar();
}
