#include <stdio.h>
#include <windows.h>

int main()
{
    int x, y = 78;
    char s1, s2, s3, s4;
    
    system("color 0A");
    printf("Zadej 4-znakove slovo: ");
    scanf("%c%c%c%c", &s1, &s2, &s3, &s4);
    system("cls");
    
    for(;;) {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n");
        for(x = y; x >=0 ; x--) {
            printf(" ");
        }
        
        if(y == 78) printf("%c", s1);
        else if(y == 77) printf("%c%c", s1, s2);
        else if(y == 76) printf("%c%c%c", s1, s2, s3);
        else if(y == 75) printf("%c%c%c%c", s1, s2, s3, s4);
        else if(y < 75 && y > 0) printf("%c%c%c%c", s1, s2, s3, s4);
        else if(y == 0) printf("%c%c%c%c", s1, s2, s3, s4);
        else if(y == -1) printf("%c%c%c", s2, s3, s4);
        else if(y == -2) printf("%c%c", s3, s4);
        else if(y == -3) {
            printf("%c", s4);
            y = 78;
        }
        
        Sleep(10);
        y--;
    }
    
    printf("\n\n");
    system("pause");
    return 0;
}
