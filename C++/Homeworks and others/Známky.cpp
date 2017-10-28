#include <stdio.h>
int main()
{
    float prum=0;
    int a,b,c,d,e,f,g,h,i,j,max=0,min=0,p=0,je=0,dv=0,tr=0,ct=0,pe=0;
    printf("Zadej 10 znamek: ");
    scanf("%d%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j);
    if(a>0)if(a<6){prum=prum+a;p++;}
    if(b>0)if(b<6){prum=prum+b;p++;}
    if(c>0)if(c<6){prum=prum+c;p++;}
    if(d>0)if(d<6){prum=prum+d;p++;}
    if(e>0)if(e<6){prum=prum+e;p++;}
    if(f>0)if(f<6){prum=prum+f;p++;}
    if(g>0)if(g<6){prum=prum+g;p++;}
    if(h>0)if(h<6){prum=prum+h;p++;}
    if(i>0)if(i<6){prum=prum+i;p++;}
    if(j>0)if(j<6){prum=prum+j;p++;}
    prum=prum/p;
    
    max=a;
    if(b>max)max=b;
    if(c>max)max=c;
    if(d>max)max=d;
    if(e>max)max=e;
    if(f>max)max=f;
    if(g>max)max=g;
    if(h>max)max=h;
    if(i>max)max=i;
    if(j>max)max=j;
    
    
    min=a;
    if(b<min)min=b;
    if(c<min)min=c;
    if(d<min)min=d;
    if(e<min)min=e;
    if(f<min)min=f;
    if(g<min)min=g;
    if(h<min)min=h;
    if(i<min)min=i;
    if(j<min)min=j;
    
    if(a==1)je++;if(a==2)dv++;if(a==3)tr++;if(a==4)ct++;if(a==5)pe++;
    if(b==1)je++;if(b==2)dv++;if(b==3)tr++;if(b==4)ct++;if(b==5)pe++;
    if(c==1)je++;if(c==2)dv++;if(c==3)tr++;if(c==4)ct++;if(c==5)pe++;
    if(d==1)je++;if(d==2)dv++;if(d==3)tr++;if(d==4)ct++;if(d==5)pe++;
    if(e==1)je++;if(e==2)dv++;if(e==3)tr++;if(e==4)ct++;if(e==5)pe++;
    if(f==1)je++;if(f==2)dv++;if(f==3)tr++;if(f==4)ct++;if(f==5)pe++;
    if(g==1)je++;if(g==2)dv++;if(g==3)tr++;if(g==4)ct++;if(g==5)pe++;
    if(h==1)je++;if(h==2)dv++;if(h==3)tr++;if(h==4)ct++;if(h==5)pe++;
    if(i==1)je++;if(i==2)dv++;if(i==3)tr++;if(i==4)ct++;if(i==5)pe++;
    if(j==1)je++;if(j==2)dv++;if(j==3)tr++;if(j==4)ct++;if(j==5)pe++;
    
    printf("Prumer znamek je: %.2f",prum);
    printf("\nNejvetsi znamka je: %d",max);
    printf("\nNejmensi znamka je: %d",min);
    printf("\nPocet 1: %d",je);
    printf("\nPocet 2: %d",dv);
    printf("\nPocet 3: %d",tr);
    printf("\nPocet 4: %d",ct);
    printf("\nPocet 5: %d",pe);
    getchar();getchar();
}
