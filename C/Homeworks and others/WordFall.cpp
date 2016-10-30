///
///
///      MARIAN DOLINSKÝ
///
///
#include <stdio.h>
#include <windows.h>

int main()

{
    char a, b, c, d, x = 1, y, z = 0;
    
    printf("Zadej 4-znaky: ");
    scanf("%c%c%c%c", &a, &b, &c, &d);
    system("cls");
    
    for(x = 1;x <= 25;x++) {
        if(z == 0) {
            printf("%c%c%c%c", a, b, c, d);
            z++;
        }
        else {
            printf(" %c%c%c", b, c, d);
            for(y = 2;y <= x;y++) printf("\n");
            printf("%c", a);
        }
        
        Sleep(20);
        system("cls");
    }
    
    z = 0;
    for(x = 1;x <= 25;x++) {
        if(z == 0) {
            printf(" %c%c%c", b, c, d);
            z++;
        }
        else {
            printf("  %c%c", c, d);
            for(y = 2;y <= x;y++) printf("\n");
            printf(" %c", b);
        }
        
        Sleep(20);
        system("cls");
    }
    
    z = 0;
    for(x = 1;x <= 25;x++) {
        if(z == 0) {
            printf("  %c%c", c, d);
            z++;
        }
        else {
            printf("   %c", d);
            for(y = 2;y <= x;y++) printf("\n");
            printf("  %c", c);
        }
        
        Sleep(20);
        system("cls");
    }
    
    z = 0;
    for(x = 1;x <= 25;x++) {
        if(z == 0) {
            printf("   %c", d);
            z++;
        }
        else {
            printf("\n");
            for(y = 2;y <= x;y++) printf("\n");
            printf("   %c", d);
        }
        
        Sleep(20);
        system("cls");
    }
    
    Sleep(100);
    system("PAUSE");
}
