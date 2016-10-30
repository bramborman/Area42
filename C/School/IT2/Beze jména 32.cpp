#include <stdio.h>
#include <windows.h>

void calc(const float X, const float Y, const char OPERATION)
{
    float result;
    
    if(OPERATION == '+')
    {
        result = X + Y;
    }
    else if(OPERATION == '-')
    {
        result = X - Y;
    }
    else if(OPERATION == '*' || OPERATION == 'x')
    {
        result = X * Y;
    }
    else if(OPERATION == '/' || OPERATION == ':')
    {
        if(Y != 0)
        {
            result = X / Y;
        }
        else
        {
            printf("ERROR: dividing by zero");
            return;
        }
    }
    else
    {
        printf("SYNTAX ERROR");
        return;
    }
    
    printf("%.2f %c %.2f = %.2f", X, OPERATION, Y, result);
    
    return;
}

int main()
{
    char operation, repeat;
    float x, y;
    
    do
    {
        system("cls");
        
        printf("Number 1: ");
        scanf("%f", &x);
        getchar();
        
        printf("Operation: ");
        scanf("%c", &operation);
        getchar();
        
        printf("Number 2: ");
        scanf("%f", &y);
        getchar();
        
        calc(x, y, operation);
        
        do
        {
            printf("\n\nRepeat? (Y/n): ");
            scanf("%c", &repeat);
            
            if(repeat >= 97 && repeat <= 122)
            {
                repeat -= 32;
            }
        } while(repeat != 'Y' && repeat != 'N');
    } while(repeat == 'Y');
    
    return 0;
}
