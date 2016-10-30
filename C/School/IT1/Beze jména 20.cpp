#include <stdio.h>
int main()
{
    int cislo;
    printf("Zadej cislo od 0 do 24: ");
    scanf("%d",&cislo);
    
    if((cislo>=0 && cislo<=5) || (cislo>22 && cislo<=24))printf("noc");
    if(cislo>=6 && cislo<=9)printf("rano");
    if(cislo>=10 && cislo<12)printf("dopoledne");
    if(cislo==12)printf("poledne");
    if(cislo>12 && cislo<=16)printf("odpoledne");
    if(cislo>=17 && cislo<=20)printf("podvecer");
    if(cislo>20 && cislo<=22)printf("vecer");
    if(cislo<0 || cislo>24)printf("neni cast dne");
   
    getchar();getchar();
}
