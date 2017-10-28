#include <stdio.h>
int main()
{
    int cislo,a,b;
    printf("Zadej cislo v rozsahu 0-255: ");
    scanf("%d",&cislo);
    a=cislo%16;
    b=(cislo/16)%16;
    
    if(b==0)printf("0");
    if(b==1)printf("1");
    if(b==2)printf("2");
    if(b==3)printf("3");
    if(b==4)printf("4");
    if(b==5)printf("5");
    if(b==6)printf("6");
    if(b==7)printf("7");
    if(b==8)printf("8");
    if(b==9)printf("9");
    if(b==10)printf("A");
    if(b==11)printf("B");
    if(b==12)printf("C");
    if(b==13)printf("D");
    if(b==14)printf("E");
    if(b==15)printf("F");
    
    if(a==0)printf("0");
    if(a==1)printf("1");
    if(a==2)printf("2");
    if(a==3)printf("3");
    if(a==4)printf("4");
    if(a==5)printf("5");
    if(a==6)printf("6");
    if(a==7)printf("7");
    if(a==8)printf("8");
    if(a==9)printf("9");
    if(a==10)printf("A");
    if(a==11)printf("B");
    if(a==12)printf("C");
    if(a==13)printf("D");
    if(a==14)printf("E");
    if(a==15)printf("F");
    
    getchar();getchar();
}
