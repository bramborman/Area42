#include <stdio.h>
#include <windows.h>
#include <time.h>

int main() {
    int x, y, i, p, n;
    system("color 0E");
    srand(time(0));
    
    start:
    printf("\n\tVyber pocet hvezd:\n\t\t1. Malo\n\t\t2. Vic\n\t\t3. Jeste vic\n\t\t4. Nejvic\n\t\t4. Nejvic\n\t\t");
    scanf("%d", &n);
    system("cls");
    
    if(n == 1) n  = 5;
    else if(n == 2) n  = 20;
    else if(n == 3) n  = 50;
    else if(n == 4) n  = 100;
    else if(n == 5) return 0;
    else goto start;
    
    for(;n > 0;n--) {    
        x = rand()%79+1;
        y = rand()%24+1;
        
        for(i = 1; i <= y; i++) printf("\n");
        for(i = 1; i <= x; i++) printf(" ");
        
        printf("%c", 250);
        Sleep(100);
        printf("\b*");
        Sleep(500);
        printf("\n");
    }
    system("pause");
}
