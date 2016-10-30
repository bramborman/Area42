//
//
//      (c) MARIAN DOLINSKÝ
//
//
#include <stdio.h>
#include <windows.h>

int main() {
    char z1 = 0, z2 = 0, z3 = 0, z4 = 0;
    int x, y, p = 0;
    
    do {
        system("color 0F");
        
        for(x = 1; x <= 5;x++) {
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t      ENTER PASSWORD: ");
            
            for(y = 0; y < x-1; y++) printf("*");
            
            if(x == 1) scanf("%c", &z1);
            else if(x == 2) scanf("%c", &z2);
            else if(x == 3) scanf("%c", &z3);
            else if(x == 4) scanf("%c", &z4);
            else if(x != 5) x = 0;
            
            if(x != 5) getchar();
            system("cls");
        }
        
        for(x = 1; x < 160; x++) {
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t      VALIDATING PASSWORD\n\n\t\t\t\t     ****");
            
            for(y = x/40; y < 4; y++) printf("\b");
            
            if(x%4 == 0) printf("|");
            else if(x%4 == 1) printf("\\");
            else if(x%4 == 2) printf("-");
            else if(x%4 == 3) printf("/");
            
            Sleep(20);
            system("cls");
        }
        
        if(z1 == 'f' && z2 == 'i' && z3 == 's' && z4 == 'a') p = 5;
        else {
            p++;
            system("color 0C");
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tWRONG PASSWORD\n\n\t\t\t");
            system("pause");
            system("cls");
        }
        
    } while(p < 3);
    
    system("cls");
    
    if(p == 5) {
        system("color 0A");
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tACCESS GRANTED\n\n\t\t\t      Fisa je tulipan xD\n\n\t\t\t");
    }
    else {
        system("color 0C");
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t  ACCESS DENIED\n\n\t\t\t");
    }
    
    system("pause");
}
