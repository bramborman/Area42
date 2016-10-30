#include <stdio.h>
#include <windows.h>
#include <time.h>

int main() {
    
    int u, x, y, p = 0;
    srand(time(0));
    
    for(;;) {
        printf("Vyber si uroven:\n\t1. lehka 1-10\n\t2. stredni 1-50\n\t3. tezka 1-100\n\t4. konec\n\t");
        scanf("%d", &u);
        system("cls");
        p = 0;
        
        if(u == 1) {
            x = rand()%10+1;
            printf("Hadej cislo 1-10: ");
        }
        else if(u == 2) {
            x = rand()%50+1;
            printf("Hadej cislo 1-50: ");
        }
        else if(u == 3) {
            x = rand()%100+1;
            printf("Hadej cislo 1-100: ");
        }
        else if(u == 4) return 0;
        else continue;
        
        for(;;) {
            scanf("%d", &y);
            p++;
            
            if(y == x) {
                printf("Vyhral jsi!!!\nPokusy: %d", p);
                break;
            }
            else if(y < x) printf("Zadej vyssi cislo: ");
            else if(y > x) printf("Zadej nizsi cislo: ");
        }
        Sleep(10000);
        system("cls");
    }
    
    system("pause");
}
