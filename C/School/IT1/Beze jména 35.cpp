#include <stdio.h>
int main()
{
    float prum=0;
    int a,b,c,d,e,p=0;
    printf("Zadej 5 cisel: ");
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    
    if(a>0 && a<6){prum=prum+a;p++;}
    if(b>0 && b<6){prum=prum+b;p++;}
    if(c>0 && c<6){prum=prum+c;p++;}
    if(d>0 && d<6){prum=prum+d;p++;}
    if(e>0 && e<6){prum=prum+e;p++;}
    prum=prum/(float)p;
    
    printf("prumer: %.2f",prum);
    
    
    getchar();getchar();
}
