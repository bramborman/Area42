#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define ESC 27

#define MAX_X 77
#define MAX_Y 21

#define SLEEP 75

void guy(const bool RIGHT)
{
    COORD position = {RIGHT ? 0 : MAX_X, rand() % MAX_Y};
    
    for(int i = 0; i < MAX_X; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
            
            if(i % 2)
            {
                if(j % 2 == 0)
                {
                    fputs("*", stdout);
                }
                else if(j == 5)
                {
                    fputs("* *", stdout);
                }
                else
                {
                    fputs("***", stdout);
                }
            }
            else
            {
                if(j % 2 == 0)
                {
                    fputs(" *", stdout);
                }
                else if(j == 5)
                {
                    fputs("* *", stdout);
                }
                else
                {
                    fputs("***", stdout);
                }
            }
            
            position.Y++;
        }
        
        position.X += RIGHT ? 1 : -1;
        position.Y -= 6;
        
        Sleep(SLEEP);
        system("cls");
    }
}

int main()
{
    srand(time(NULL));
    
    bool right = true;
    
    while(!kbhit() || getch() != ESC)
    {
        guy(right);
        system("cls");
        
        right = !right;
    }
    
    system("pause");
}
