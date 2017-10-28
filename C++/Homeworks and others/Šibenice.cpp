#include <stdio.h>
#include <windows.h>

int main() {
    int p = 0;
    char c1 = '?', c2 = '?', c3 = '?', c4 = '?', x = 0;
    system("color 0A");
    
    do {
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t     %c%c%c%c", c1, c2, c3, c4);
        printf("\n\n\t\t\t\tHadej pismeno: "); scanf("%c", &x); getchar();
        
        if(x == 'f' || x == 'F') c1 = x;
        else if(x == 'i' || x == 'I') c2 = x;
        else if(x == 's' || x == 'S') c3 = x;
        else if(x == 'a' || x == 'A') c4 = x;
        
        p++;
        system("cls");
    } while(!((c1 == 'f' || c1 == 'F') && (c2 == 'i' || c2 == 'I') && (c3 == 's' || c3 == 'S') && (c4 == 'a' || c4 == 'A')));
    
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t Vyhral jsi!!!\n\n\t\t\t\t   pokusy: %d\n\n\t\t\t   ", p);
    system("pause");
}
