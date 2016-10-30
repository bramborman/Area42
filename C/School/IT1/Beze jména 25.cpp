#include <stdio.h>
int main()
{
    int a,b,c,d,e,min=1000,max=-1000;
    printf("Zadej 5 cisel: ");
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    
    if(a>99 && a<1000){a=a/10%10; min=a; max=a;}
    if(b>99 && b<1000){b=b/10%10; if(b<min)min=b;if(b>max)max=b;}
    if(c>99 && c<1000){c=c/10%10; if(c<min)min=c;if(c>max)max=c;}
    if(d>99 && d<1000){d=d/10%10; if(d<min)min=d;if(d>max)max=d;}
    if(e>99 && e<1000){e=e/10%10; if(e<min)min=e;if(e>max)max=e;}
    
    printf("min: %d, max: %d",min,max);
    
    getchar();getchar();
}
