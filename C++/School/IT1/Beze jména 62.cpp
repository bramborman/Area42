#include <stdio.h>
#include <windows.h>
#include <time.h>

int main() {
    int x, y, i;
    
    for(;;) {
        srand(time(0));
        x = rand() % 79 + 1;
        y = rand() % 24 + 1;
        for(i = 1; i <= y; i++) printf("\n");
        for(i = 1; i <= x; i++) printf(" ");
        printf("%c", 250);
        Sleep(200);
        system("cls");
        for(i = 1; i <= y; i++) printf("\n");
        for(i = 1; i <= x; i++) printf(" ");
        printf("*");
        Sleep(200);
        system("cls");
    }
}
