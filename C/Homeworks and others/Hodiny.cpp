#include <stdio.h>
#include <windows.h>

int main() {
    int h = 0, m = 0, s = 0, x, y;
    
    system("color 0F");
    do {
        printf("Zadej hodiny: ");
        scanf("%d", &h);
        system("cls");
    } while(h < 0 || h > 23);
    
    do {
        printf("Zadej minuty: ");
        scanf("%d", &m);
        system("cls");
    } while(m < 0 || m > 59);
    
    do {
        printf("Zadej sekundy: ");
        scanf("%d", &s);
        system("cls");
    } while(s < 0 || s > 59);
    
    for(;;) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ");
        for(x = 1; x <= 12; x++) printf("*");
        printf("\n\t\t\t\t   * ");
        if(h < 10) printf("0");
        printf("%d:", h);
        if(m < 10) printf("0");
        printf("%d:", m);
        if(s < 10) printf("0");
        printf("%d *\n\t\t\t\t   ", s);
        for(x = 1; x <= 12; x++) printf("*");
        s++;
        if(s == 60) {
            s = 0;
            m++;
        }
        if(m == 60) {
            m = 0;
            h++;
        }
        if(h == 24) h = 0;
        Sleep(1000);
        system("cls");
    }
    
    system("pause");
}
