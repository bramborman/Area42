#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

void colors();
void house();

int main()
{
    srand(time(NULL));
    
    do
    {
        colors();
        house();
        
        Sleep(rand() % 10 + 1500);
        system("cls");
    } while(!(kbhit() && getch() == 27));
    
    system("color 07");
    system("pause");
}

void colors()
{
    char color[] = "color xx";
    int backgroundColor, fontColor;
    
    do
    {
        backgroundColor = rand() % 16;
        fontColor = rand() % 16;
    } while(backgroundColor == fontColor);
    
    if(backgroundColor >= 10)
    {
        backgroundColor += 55;
    }
    else
    {
        backgroundColor += 48;
    }
    
    if(fontColor >= 10)
    {
        fontColor += 55;
    }
    else
    {
        fontColor += 48;
    }
    
    color[6] = backgroundColor;
    color[7] = fontColor;
    
    system(color);
}

void house()
{
    for(int i = 0; i < 7; i++)
    {
        printf("\n");
    }
    
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 34; j++)
        {
            printf(" ");
        }
        
        if(i < 5)
        {
            for(int j = 5; j > i; j--)
            {
                printf(" ");
            }
            
            for(int j = 0; j <= i * 2; j++)
            {
                printf("*");
            }
        }
        else
        {
            printf("***********");
        }
        
        printf("\n");
    }
}
