#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#include <conio.h>

int main() {
    char ch, pass[4], i, p = 0;
    
    system("color 0A");
    setlocale(LC_ALL, "");
    
    for(;;) {
        system("cls");
        printf("\n\tZadej heslo: ");
        
        for(i = 0; i < 4; i++) {
            ch = getch();
            pass[i] = ch;
            printf("*");
        }
        pass[4] = 0;
        system("cls");
        
        if(strcmp(pass, "fisa") == 0 || p == 2) break;
        else {
            printf("\n\t�PATN� HESLO\n\t");
            p++;
            system("pause");
        }
    }
    if(p == 2) printf("\n\tP��STUP ZAM�TNUT\n\t");
    else printf("\n\tP��STUP POVOLEN\n\t");
    
    system("pause");
}
