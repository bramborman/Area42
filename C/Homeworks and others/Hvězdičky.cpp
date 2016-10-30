#include <stdio.h>
#include <windows.h>
#include <time.h>

int main() {
    int x, r = 0, m = 0, i, p;
    
    system("color 0F");
    do {
        printf("Vyber si:\n\t1. Malo hvezdicek\n\t2. Vic hvezdicek\n\t3. Hodne hvezdicek\n\t4. KONEC\n\n\t");
        scanf("%d", &x);
        system("cls");
    } while(x < 1 || x > 4);
    
    if(x == 2) x = 5;
    else if(x == 3) x = 10;
    else if(x == 4) return 0;
    
    system("color 0E");
    srand (time(0));
    
    for(;;) {
        for(p = 1; p <= x; p++) {
            if(x == 1) m = rand()%80+1;
            else if(x == 5) m = rand()%16+1;
            else if(x == 10) m = rand()%8+1;
            
            for(i = 1; i <= m; i++) printf(" ");
            printf("%c", 250);
            Sleep(200);
            printf("\b*");
            Sleep(50);
        }
        printf("\n");
    }
}
