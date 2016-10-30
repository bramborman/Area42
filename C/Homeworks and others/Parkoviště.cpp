#include <stdio.h>
int main()
{int delkap,sirkap,delkav,sirkav,delkaok,sirkaok,vysledek;
    printf("Vitejte v programu pro vypocitavani poctu aut na parkovisti.");
    printf("\n\nZadej delku parkoviste: ");
    scanf("%d",&delkap);
    printf("Zadej sirku parkoviste: ");
    scanf("%d",&sirkap);
    printf("\nZadej delku auta: ");
    scanf("%d",&delkav);
    printf("Zadej sirku auta: ");
    scanf("%d",&sirkav);
    printf("___________________________");
    vysledek=(delkap*sirkap)/(delkav*sirkav);
    if(delkap<delkav){
        delkaok=0;
    }
    else{
        delkaok=1;
    }
    if(sirkap<sirkav){
        sirkaok=0;
    }
    else{
        sirkaok=1;
    }
    if(delkaok+sirkaok<2){
        printf("\nNa parkoviste se nevejde ani jedno auto.");
    }
    if(vysledek==1){
        printf("\nNa parkoviste se vejde %d auto.",(vysledek));
    }
    if((vysledek>1)&&(vysledek<5)){
        printf("\nNa parkoviste se vejdou %d auta.",(vysledek));
    }
    if(vysledek>4){
        printf("\nNa parkoviste se vejde %d aut.",(vysledek));
    }
    printf("\n\n\n(C)2014 Marian Dolinsky a David Knieradl");
    getchar();getchar();
}
