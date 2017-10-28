//
//
//      (c) MARIAN DOLINSKÝ
//
//
#include <stdio.h>
#include <windows.h>

int main()
{   
    char x = 0, k1 = '1', k2 = '2', k3 = '3', k4 = '4', k5 = '5', k6 = '6', k7 = '7', k8 = '8', k9 = '9', k10a = '1', k10b = '0', k11a = '1', k11b = '1', k12a = '1', k12b = '2';
    int c1 = 0, c2 = 0;
    
    system("color 0A");
    
    printf(" \n\n\n\n\n\n\n\t     _______   _______   __   __   _______   _______   _______"); Sleep(50);
    printf("\n\t    |       | |       | |  |_|  | |       | |       | |       |"); Sleep(50);
    printf("\n\t    |    _  | |    ___| |       | |    ___| |  _____| |   _   |"); Sleep(50);
    printf("\n\t    |   |_| | |   |___  |       | |   |___  | |_____  |  | |  |"); Sleep(50);
    printf("\n\t    |    ___| |    ___|  |     |  |    ___| |_____  | |  |_|  |"); Sleep(50);
    printf("\n\t    |   |     |   |___  |   _   | |   |___   _____| | |       |"); Sleep(50);
    printf("\n\t    |___|     |_______| |__| |__| |_______| |_______| |_______|"); Sleep(50);
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t      (c) Marian Dolinsky 2015");
    Sleep(3000);
    
    do {
        system("cls");
        system("color 0A");
        printf("\n\t\t****\t****\t****\t****\t****\t****");Sleep(50);
        printf("\n\t\t* %c*\t* %c*\t* %c*\t* %c*\t* %c*\t* %c*", k1, k2, k3, k4, k5, k6);Sleep(50);
        printf("\n\t\t****\t****\t****\t****\t****\t****");Sleep(100);
        printf("\n\n\t\t****\t****\t****\t****\t****\t****");Sleep(50);
        printf("\n\t\t* %c*\t* %c*\t* %c*\t*%c%c*\t*%c%c*\t*%c%c*",k7, k8, k9, k10a, k10b, k11a, k11b, k12a, k12b);Sleep(50);
        printf("\n\t\t****\t****\t****\t****\t****\t****");Sleep(50);
        printf("\n________________________________________________________________________________");Sleep(100);
        
        do {
            printf("\n\tZadej cislo 1. karty: ");
            scanf("%d", &c1);
        } while(c1 < 1 || c1 > 6);
        
        switch(c1) {
            case 1: printf("\t\tB"); break;
            case 2: printf("\t\tF"); break;
            case 3: printf("\t\tA"); break;
            case 4: printf("\t\tD"); break;
            case 5: printf("\t\tE"); break;
            case 6: printf("\t\tC"); break;
        }
        
        do {
            printf("\n\n\tZadej cislo 2. karty: ");
            scanf("%d", &c2);
        } while(c2 < 7 || c2 > 12);
        
        switch(c2) {
            case 7: printf("\t\tD"); break;
            case 8: printf("\t\tE"); break;
            case 9: printf("\t\tB"); break;
            case 10: printf("\t\tC"); break;
            case 11: printf("\t\tA"); break;
            case 12: printf("\t\tF"); break;
        }
        
        if(c1 == 1 && c2 == 9) {
            k1 = ' ';
            k9 = ' ';
        }
        else if(c1 == 2 && c2 == 12) {
            k2 = ' ';
            k12a = ' ';
            k12b = ' ';
        }
        else if(c1 == 3 && c2 == 11) {
            k3 = ' ';
            k11a = ' ';
            k11b = ' ';
        }
        else if(c1 == 4 && c2 == 7) {
            k4 = ' ';
            k7 = ' ';
        }
        else if(c1 == 5 && c2 == 8) {
            k5 = ' ';
            k8 = ' ';
        }
        else if(c1 == 6 && c2 == 10) {
            k6 = ' ';
            k10a = ' ';
            k10b = ' ';
        }
        
        x++;
        Sleep(500);
        printf("\n\n\t");
        system("pause");
        
    } while(k1 != ' ' || k2 != ' ' || k3 != ' ' || k4 != ' ' || k5 != ' ' || k6 != ' ' || k7 != ' ' || k8 != ' ' || k9 != ' ' || k10a != ' ' || k10b != ' ' || k11a != ' ' || k11b != ' ' || k12a != ' ' || k12b != ' ');
    
    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t     **********************"); Sleep(50);
    printf("\n\t\t\t    *                      *"); Sleep(50);
    printf("\n\t\t\t    *      VYHRAL JSI      *"); Sleep(50);
    printf("\n\t\t\t    *                      *"); Sleep(50);
    printf("\n\t\t\t    *      pokusy: %d       *", x); Sleep(50);
    printf("\n\t\t\t    *                      *"); Sleep(50);
    printf("\n\t\t\t     **********************"); Sleep(50);
    
    printf("\n\n\n\n\n\n\n\n\n\t");
    system("pause");
    return 0;
}

