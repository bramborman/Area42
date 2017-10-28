 #include <stdio.h>
#include <windows.h>

int main() {
    int a = 0, n = 0, x = 0, max = 0;
    system("color 0A");
    
    do {
        do {
            printf("Zadej pocet lidi hlasujicich pro: ");
            scanf("%d", &a);
            system("cls");
        } while(a < 0 || a > 30);
        
        do {
            printf("Zadej pocet lidi hlasujicich proti: ");
            scanf("%d", &n);
            system("cls");
        } while(n < 0 || n > 30);
        
        do {
            printf("Zadej pocet lidi zdrzujicich se hlasovani: ");
            scanf("%d", &x);
            system("cls");
        } while(x < 0 || x > 30);
    } while(a == 0 && n == 0 && x == 0);
    
    max = a;
    if(max < n) max = n;
    if(max < x) max = x;
    
    printf("\n");
    for(; max >= 0; max--) {
        if(max < 10 && (a >= 10 || n >= 10 || x >= 10)) printf(" ");
        printf(" %d %c\t", max, 195);
        
        if(a >= max) printf("%c\t", 219);
        else printf(" \t");
        
        if(n >= max) printf("%c\t", 219);
        else printf(" \t");
        
        if(x >= max) printf("%c", 219);
        printf("\n");
    }
    
    printf("     ");
    if((a/((float)(a+n+x)/100)) != 100) printf(" ");
    if((a/((float)(a+n+x)/100)) < 10) printf(" ");
    printf("%.1f%%  ", a/((float)(a+n+x)/100));
    
    if((n/((float)(a+n+x)/100)) != 100) printf(" ");
    if((n/((float)(a+n+x)/100)) < 10) printf(" ");
    printf("%.1f%%  ", n/((float)(a+n+x)/100));
    
    if((x/((float)(a+n+x)/100)) != 100) printf(" ");
    if((x/((float)(a+n+x)/100)) < 10) printf(" ");
    printf("%.1f%%\n\n", x/((float)(a+n+x)/100));
    
    system("pause");
}
