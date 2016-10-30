#include <stdio.h>
int main()
{
    int cislo1=0,cislo2=0,cislo3=0;
    int vysledek=0,pocet=0,mez1=0,mez2=0;
    char operace1=0,operace2=0;
    
    printf("\n\tNapiste priklad: ");
    scanf("%d",&pocet);
    
    switch(pocet){
        
        default:
            printf("\n\tMusite zadat cislo dva nebo tri!");
        break;
        
        case 2:
            printf("\n\tZadejte priklad s max dvemi cisly a stisknete Enter pro vypocet:\n\t");
            scanf("%d %c %d",&cislo1,&operace1,&cislo2);
            
            if(operace1==120)operace1=42;
            if(operace1==58)operace1=47;
            
            if(operace1==43)vysledek=cislo1+cislo2;
            if(operace1==45)vysledek=cislo1-cislo2;
            if(operace1==42)vysledek=cislo1*cislo2;
            if(operace1==47)vysledek=cislo1/cislo2;
            
            printf("\n\t%d%c%d=%d",cislo1,operace1,cislo2,vysledek);
            
        break;
        
        case 3:
            printf("\n\tZadejte priklad s max tremi cisly a stisknete Enter pro vypocet:\n\t");
            scanf("%d %c %d %c %d",&cislo1,&operace1,&cislo2,&operace2,&cislo3);
            
            if(operace1==120)operace1=42;
            if(operace1==58)operace1=47;
            if(operace2==120)operace2=42;
            if(operace2==58)operace2=47;
            
            if(operace2!=42&&operace2!=47){
                if(operace1==43)mez1=cislo1+cislo2;
                if(operace1==45)mez1=cislo1-cislo2;
                if(operace1==42)mez1=cislo1*cislo2;
                if(operace1==47)mez1=cislo1/cislo2;
                
                if(operace2==43)vysledek=mez1+cislo3;
                if(operace2==45)vysledek=mez1-cislo3;
            }
            
            if(operace2==42||operace2==47&&operace1!=42&&operace1!=47){
                if(operace2==42)mez2=cislo2*cislo3;
                if(operace2==47)mez2=cislo2/cislo3;
                
                if(operace1==43)vysledek=cislo1+mez2;
                if(operace1==45)vysledek=cislo1-mez2;
            }
        
            if(operace1==42||operace1==47){
                if(operace2==42||operace2==47){
                    if(operace1==42)mez1=cislo1*cislo2;
                    if(operace1==47)mez1=cislo1/cislo2;
                    
                    if(operace2==42)vysledek=mez1*cislo3;
                    if(operace2==47)vysledek=mez1/cislo3;
                }
            }
            
            printf("\n\t%d%c%d%c%d=%d",cislo1,operace1,cislo2,operace2,cislo3,vysledek);
            
        break;
    }
    printf("\n\n\t\t\t(C) 2014 Marian Dolinsky");
    getchar();getchar();
}
