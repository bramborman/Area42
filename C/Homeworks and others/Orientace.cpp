#include <stdio.h>
#include <string.h>
#include <windows.h>

int blb(bool female, int pocet);

int main()
{
	
    int year = 2015;
    float version = 0.9;
    char channel[] = "beta";
    
    bool female = false;
    
    int otc = 0, pocet = 0, x = 0, procenta = 0, delka=0, v0 = -1, v1 = -1, v2 = -1, v3 = -1, v4 = -1, v5 = -1, v6 = -1, v7 = -1, v8 = -1, v9 = -1, v10 = -1;
    char ot[100], homo[5], pritel[100], zmena[100];
    
        
    system ("color 0d");
    
    Sleep(300);
    /*printf("\n\n\n\n\n\n        #####  ######  ### ####### #     # #######  #####   #####  #######"); Sleep(50);
    printf("\n       #     # #     #  #  #       ##    #    #    #     # #     # #"); Sleep(50);
    printf("\n       #     # #     #  #  #       # #   #    #    #     # #       #"); Sleep(50);
    printf("\n       #     # ######   #  #####   #  #  #    #    #     # #       #####"); Sleep(50);
    printf("\n       #     # #   #    #  #       #   # #    #    ####### #       #"); Sleep(50);
    printf("\n       #     # #    #   #  #       #    ##    #    #     # #     # #"); Sleep(50);
    printf("\n        #####  #     # ### ####### #     #    #    #     #  #####  #######"); Sleep(50);
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t(c) Marian Dolinsky %d (v%.1f %s)", year, version, channel);
    
    Sleep(3000);
    system("cls");
    
    system("color 0F");
    
    //VAROVANI
    
    printf("\n\n\t\t\t\t!!!Varovani!!!");
    printf("\n\nToto je testovaci verze (%.1f %s), pouziti na vlastni nebezpeci!\nMuze obsahovat vir Trojan:Win32/Fisa.AgentQUZY\n\n",version,channel);
    system("pause");
    Sleep(300);*/ 
    
    
    start:
        system("cls");
        printf("\n\n\n\tJsi muz nebo zena? (M/Z): ");
        gets(ot);
        
        for(x = 0; x <= strlen(ot); x++) if(ot[x] >= 65 && ot[x] <= 90) ot[x] = ot[x] + 32;
        
        if((strcmp(ot, "z") == 0) || (strcmp(ot, "zena") == 0)) female = true;
        
        else if((strcmp(ot, "m") != 0) && (strcmp(ot, "muz") != 0)){
            printf("\n\tMel/a jsi na vyber z M/Z, ale napsal/a jsi: %s", ot);
            
            pocet = blb(female,pocet);
            if(pocet == -5) return 0;
            
            printf("\n\tAle nevadi, stane se, zkus to znovu!!!\n\n\t");
            Sleep(500);
            system("pause");
            goto start;
        }
    
    ot:
        system("cls");
        printf("\n\n\n\t");
        
        if(otc == 0) {
            printf("Jsi" female == false ? "gay":"lesba" "?");
        }
        else if(otc == 1) {
            if(female == false) printf("Vedel jsi uz driv ze jsi gay?");
            else if(female == true) printf("Vedela jsi uz driv ze jsi lesba?");
        }
        else if(otc == 2) {
            if(female == false)printf("Jsi se svou orientaci spokojeny?");
            else if(female == true)printf("Jsi se svou orientaci spokojena?");
        }
        else if(otc == 3) {
            if(female == false) printf("Mel jsi nekdy vztah s nejakym klukem?");
            else if(female == true) printf("Mela jsi nekdy vztah s nejakou divkou?");
        }
        else if(otc == 4) {
            if(female == false) printf("Jsi zaregistrovany na nejake gay seznamce?");
            else if(female == true) printf("Jsi zaregistrovana na nejake seznamce pro lesbicky?");
        }
        else if(otc == 5) {
            if(female == false) printf("Mas pritele?");
            else if(female == true) printf("Mas pritelkyni?");
        }
        else if(otc == 6) {
            printf("Jiz brzy");
                
                    otc++;
                    goto  ot;
        }
        else if(otc == 7) {
            printf("Jiz brzy");
                
                    otc++;
                    goto  ot;
        }
        else if(otc == 8) {
            printf("Jiz brzy");
                
                    otc++;
                    goto  ot;
        }
        else if(otc == 9) {
            printf("Jiz brzy");
                
                    otc++;
                    goto  ot;
        }
        else if(otc == 10) {
            printf("Jiz brzy");
                
                    otc++;
                    goto  ot;
        }
        else {
            system("cls");
            system("color 0C");
            printf("\n\tError 69\n\n\t");
            Sleep(300);
            system("pause");
            return 0;
        }
        
        printf("\n\tANO/NE: ");
        gets(ot);
        
        for(x=0;x <= strlen(ot);x++) {
            if(ot[x] >= 65 && ot[x] <= 90) ot[x] = ot[x]+32;
        }
        
        printf("\n\t");
        
        if((strcmp(ot, "ano") == 0) || (strcmp(ot, "a") == 0)) {
            if(otc == 0) {
                printf("Mas uplnou pravdu!!!\n\n\t");
                v0 = 1;
                Sleep(300);
                system("pause");
                system("cls");
                printf("\n\n\n\tNa zaklade tve odpovedi jsme dospeli k zaveru, ze jsi %s.", homo);
                printf("\n\tProsim, venuj jeste par minut tomuto dotazniku:");
                Sleep(200);
            }
            else if(otc == 1) {
                printf("V tom pripade tento program ani nepotrebujes,\n\tale i tak jej posli vsem svym pratelum,\n\tkteri si se svou orientaci jeste nejsou jisti.");
                v1 = 1;
            }
            else if(otc == 2) {
                printf("K tomu neni co dodat...");
                printf("\n\tSnad jen poprat hodne stesti v milostnem zivote. ;)");
                v2 = 1;
            }
            else if(otc == 3) {
                if(female == false) printf ("Takze uz jsi zkuseny, tak hura na lov. :P\n\n\t");
                else if(female == true) printf("Takze uz jsi zkusena, tak hura na lov. :P\n\n\t");
                v3 = 1;
            }
            else if(otc == 4) {
                printf("Brzy si tam nekoho urcite najdes. ;)");
                v4 = 1;
            }
            else if(otc == 5) {
                printf("Tak to preju hodne stesti. ;)");
                v5 = 1;
            }
            else if(otc == 6) {
                printf("Jiz brzy");
                
                v6 = 1;
            }
            else if(otc == 7) {
                printf("Jiz brzy");
                
                v7 = 1;
            }
            else if(otc == 8) {
                printf("Jiz brzy");
                
                v8 = 1;
            }
            else if(otc == 9) {
                printf("Jiz brzy");
                
                v9 = 1;
            }
            else if(otc == 10) {
                printf("Jiz brzy");
                
                v10 = 1;
            }
            else {
                system("cls");
                system("color 0C");
                printf("\n\tError 69\n\n\t");
                Sleep(300);
                system("pause");
                return 0;
            }
            
            otc++;
            Sleep(300);
            printf("\n\n\t");
            system("pause");
            goto ot;
        }
    
        else if((strcmp(ot, "ne") == 0) || (strcmp(ot, "n") == 0)) {
            if(otc == 0) {
                if(female == false)printf ("Sam vis, ze to neni pravda!!!\n\n\t");
                else if(female == true) printf("Sama vis, ze to neni pravda!!!\n\n\t");
                v0 = 0;
                Sleep(300);
                system("pause");
                goto ot;
            }
            else if(otc == 1) {
                printf("Tak prosim zaplat alespon 50 000 Kc na tento ucet: 69-3546533153/6996"); 
                printf("Pomuzes tak vyvoji tohoto programu a tim i spouste ");
                if(female == false) printf("muzu,\n\tkteri ");
                else if(female == true) printf("zen,\n\tktere ");
                printf("o sve orientaci jeste nevi.");
                v1 = 0;
            }
            else if(otc == 2) {
                if(female == false) printf("A udelal jsi nekdy neco pro to abys to zmenil?!");
                else if(female == true) printf("A udelala jsi nekdy neco pro to aby jsi to zmenila?!");
                printf("\n\tZamysli se nad tim, jeste se na to zeptam...");
                v2 = 0;
            }
            else if(otc == 3) {
                if(female == false) printf("Mel by sis nejakeho najit!");
                else if(female == true) printf("Mela by sis nejakou najit!");
                v3 = 0;
            }
            else if(otc == 4) {
                if(female == false) printf("Mel bys to udelat, treba tady: http://www.nakluky.cz");
                else if(female == true) printf("Mela bys to udelat, treba tady: http://www.lesbickaseznamka.cz");
                v4 = 0;
            }
            else if(otc == 5) {
                if(female == false) printf("Tak si nejakeho najdi ;)");
                else if(female == true) printf("Tak si nejakou najdi ;)");
                v5 = 0;
            }
            else if(otc == 6) {
                printf("Jiz brzy");
                
                v6 = 0;
            }
            else if(otc == 7) {
                printf("Jiz brzy");
                
                v7 = 0;
            }
            else if(otc == 8) {
                printf("Jiz brzy");
                
                v8 = 0;
            }
            else if(otc == 9) {
                printf("Jiz brzy");
                
                v9 = 0;
            }
            else if(otc == 10) {
                printf("Jiz brzy");
                
                v10 = 0;
            }
            else {
                system("cls");
                system("color 0C");
                printf("\n\tError 69\n\n\t");
                Sleep(300);
                system("pause");
                return 0;
            }
            
            otc++;
            Sleep(300);
            printf("\n\n\t");
            system("pause");
            goto ot;
        }
        
        else{
            if(otc == 0) {
                printf("Urcite jsi, tak se nestyd a rekni to celemu svetu!");
                Sleep(500);
                printf("\n\n\n\tNa zaklade tve odpovedi jsme dospeli k zaveru, ze jsi %s.", homo);
                printf("\n\tProsim, venuj jeste par minut tomuto dotazniku:\n\n\t");
                Sleep(500);
                system("pause");
                otc++;
                goto ot;
            }
            else {
                if(female == false) printf("Mel jsi na vyber z ANO/NE, ale napsal jsi: %s", ot);
                else if(female == true) printf("Mela jsi na vyber z ANO/NE, ale napsala jsi: %s", ot);
                pocet = blb(female,pocet);
                if(pocet == -5) return 0;
                printf("\n\tAle nevadi, stane se, zkus to znovu!!!\n\n\t");
                Sleep(500);
                system("pause");
                goto ot;
            }
        }
        
    vysledek:
        
        if(v2 == 0){
            if(female == false) printf("\n\n\tTak co? Zamyslel ses?");
            else if(female == true) printf("\n\n\tTak co? Zamyslela jsi se?");
            printf("\n\tNejspis ne, ale zkus to i tak:");
            if(female == false) printf("\n\tCo jsi kdy udelal/udelas abys zmenil svou orientaci?\n\t");
            else if(female == true) printf("\n\tCo jsi kdy udelala/udelas aby jsi zmenila svou orientaci?\n\t");
            gets(zmena);
            delka = strlen(zmena);
            
            for(x=0;x <= delka;x++) {
                if(zmena[x] >= 65 && zmena[x] <= 90) zmena[x] = zmena[x]+32;
            }
            
            if(strcmp(zmena, "nic") == 0) {
                if(female == false) printf("\n\tTakze jsi spokojeny, a jenom se stydis...");
                else if(female == true) printf("\n\tTakze jsi spokojena, a jenom se stydis...");
                Sleep(2000);
                if(v3 != 1 && female == false)printf("\n\tAle to je v poradku,\n\tnajdi si pritele a ten uz ti pomuze se s tim vyrovnat ;)");
                else if(v3 != 1 && female == true)printf("\n\tAle to je v poradku,\n\tnajdi si pritelkyni a ona uz ti pomuze se s tim vyrovnat ;)\n\n\t");
                Sleep(300);
                system("pause");
            }
            else if(delka < 7){
                printf("\n\tTakova malickost ti moc nepomuze...");
                Sleep(3000);
                if(v3 != 1 && female == false)printf("\n\tAle muzu ti poradit,\n\tnajdi si pritele a ten uz ti pomuze se s tim vyrovnat ;)");
                else if(v3 != 1 && female == true)printf("\n\tAle muzu ti poradit,\n\tnajdi si pritelkyni a ona uz ti pomuze se s tim vyrovnat ;)\n\n\t");
                Sleep(3000);
                system("pause");
            }
            else {
                printf("\n\tTo zni jako plan, drzim palce ;)\n\n\t");
                Sleep(3000);
                system("pause");
            }
        }
        
        /*procenta=(v1+v2+v3+v4+v5+v6+v7+v8+v9+v10)*10;
        printf("\n\n\tAnalyzovali jsme tve odpovedi a zjistili jsme, ze jsi %d%% %s", procenta, homo);*/
        Sleep(3000);
        system("pause");
}

int blb(bool female, int pocet) {
    if(pocet == 1) printf("\n\tUz zase???");
    else if(pocet == 2) printf("\n\tA zase? To nebude nahoda...");
    else if(pocet == 3) printf("\n\tTohle je proste divny...");
    else if(pocet == 4) printf("\n\tDalsi chyba??? o_O");
    else if(pocet == 5) {
        if(female == false) printf("\n\tTy musis byt fakt debil!!! -.-");
        else if(female == true) printf("\n\tTy musis byt fakt blba!!! -.-");
        else printf("\n\tA zase spatne!!! -.- ");
    }
    else if(pocet == 6) printf("\n\tCopak je to takovej problem odpovedet spravne na par otazek?!");
    else if(pocet != 0) {
        if(female == false) {
            printf("\n\tSes divnej...");
            Sleep(2000);
            printf("\n\ta jeste k tomu gay :D");
        }
        else if(female == true) {
            printf("\n\tSes divna...");
            Sleep(2000);
            printf("\n\t...a jeste k tomu lesba :D");
        }
        else {
            printf("\n\tDalsi chyba?!");
            Sleep(2000);
            printf("\n\tJa to vzdavam!!!");
            Sleep(5000);
        }
        return -5;
    }
    pocet++;
    return pocet;
}
