#include <stdio.h>
#include <windows.h>

#define ANSWER printf("Zadej cislo: ")
#define ANSOP printf("Zadej operaci: ")
#define END printf("\n");system("pause")

int main()
{
    float x, y, result;
    char op;
    
    ANSWER;
    scanf("%f", &x);
    
    do
    {
        ANSOP;
        
        getchar();
        scanf("%c", &op);
    } while(op != '+' && op != '-' && op != '*' && op != '/');
    
    ANSWER;
    scanf("%f", &y);
    
    if(op == '+')
    {
        result = x + y;
    }
    else if(op == '-')
    {
        result = x - y;
    }
    else if(op == '*')
    {
        result = x * y;
    }
    else if(op == '/' && y != 0)
    {
        result = x / y;
    }
    
    if(op != '/' || y != 0)
    {
        printf("%.2f", result);
    }
    else
    {
        printf("Nulou nelze delit!");
    }
    
    END;
}
