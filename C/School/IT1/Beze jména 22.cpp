#include <stdio.h>
#include <math.h>
int main()
{
    int c1,c2,ok=0;
    float vys;
    char op;
    printf("(jako operaci lze zadat cislo od 0 do 9 a vypocitat tak mocninu prvniho cisla\n nebo zadej s pro druhou odmocninu)\n\n");
    printf("Zadej 1. hodnotu: ");
    scanf("%d",&c1);
    printf("Zadej operaci: ");getchar();
    scanf("%c",&op);
    if(op=='+'||op=='-'||op=='*'||op=='/'||op=='x'||op==':'){
    printf("Zadej 2. hodnotu: ");
    scanf("%d",&c2);}
    
    if(op=='+')vys=c1+(float)c2;
    if(op=='-')vys=c1-(float)c2;
    if(op=='*'||op=='x')vys=c1*(float)c2;
    if(op=='/'||op==':' && c2!=0)vys=c1/(float)c2;
    if(op=='/'||op==':' && c2==0)ok=1;
    
    if(op=='s')vys=sqrt(c1);
    
    if(op=='0')vys=1;
    if(op=='1')vys=c1;
    if(op=='2')vys=c1*c1;
    if(op=='3')vys=c1*c1*c1;
    if(op=='4')vys=c1*c1*c1*c1;
    if(op=='5')vys=c1*c1*c1*c1*c1;
    if(op=='6')vys=c1*c1*c1*c1*c1*c1;
    if(op=='7')vys=c1*c1*c1*c1*c1*c1*c1;
    if(op=='8')vys=c1*c1*c1*c1*c1*c1*c1*c1;
    if(op=='9')vys=c1*c1*c1*c1*c1*c1*c1*c1*c1;
    
    if(op=='+'||op=='-'||op=='*'||op=='/'||op=='x'||op==':'){
        if(ok!=1)printf("%d%c%d=%.2f",c1,op,c2,vys);
        if(ok==1)printf("Nulou nelze delit!");
    }
    
    if(op=='s')printf("/%d=%.2f",c1,vys);
    
    if(op=='0'||op=='1'||op=='2'||op=='3'||op=='4'||op=='5'||op=='6'||op=='7'||op=='8'||op=='9')printf("%d^%c=%.0f",c1,op,vys);
    getchar();getchar();
}
