#include <stdio.h>
#include <windows.h>

int main()

{
    char op = 0, e = 0;
    float c1 = 0, c2 = 0, v = 0;
    
    while(e != 'n' && e != 'N') {
        e = 0;
        op = 0;
        printf("Zadej 1. cislo: ");
        scanf("%f",&c1);
        
        while(op != '+' && op != '-' && op != '*' && op != 'x' && op != '/' && op != ':') {
            printf("Zadej operator: ");getchar();
            scanf("%c",&op);
        }
        
        printf("Zadej 2. cislo: ");
        scanf("%f",&c2);
        
        while((op == '/' || op == ':') && c2 == 0) {
            printf("Zadej 2. cislo: ");
            scanf("%f",&c2);
        }
        
        if(op == '+') v = c1+c2;
        if(op == '-') v = c1-c2;
        if(op == '*' || op == 'x') v = c1*c2;
        if(op == '/' || op == ':') v = c1/c2;
        
        printf("%.2f%c%.2f=%.2f",c1,op,c2,v);
        
        while(e != 'a' && e != 'A' && e != 'n' && e != 'N') {
            printf("\n\nZadavat znovu? (a/n): ");getchar();
            scanf("%c",&e);
        }
    }
    
    system("pause");
    return 0;
}
