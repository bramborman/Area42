#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27

int main()
{
    int i, j, row = 12, column = 40;
    unsigned char key;
    char array[24][80];
    
    do
    {
        system("cls");
        
        for(i = 0; i < 24; i++)
        {
            for(j = 0; j < 80; j++)
            {
                array[i][j] = (i == row && j == column ? '*' : ' ');
                printf("%c", array[i][j]);
            }
        }
        
        key = getch();
        
        if(key == 0 || key == 224)
        {
            key = getch();
        }
        
        if(key == UP && row != 0)
        {
            row--;
        }
        else if(key == DOWN && row != 23)
        {
            row++;
        }
        else if(key == LEFT && column != 0)
        {
            column--;
        }
        else if(key == RIGHT && column != 79)
        {
            column++;
        }
        
        
    } while(key != ESC);
}
