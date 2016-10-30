#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 23

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define ESC 27

#define BALL 'o'

#define PLATFORM_WIDTH 3

#define SLEEP 250

int main()
{
    const int Y = HEIGHT - 1;
    
    char key = 0;
    char board[HEIGHT][WIDTH] = {0};
    int x = (WIDTH / 2) - 1;
    int points = 0;
    int ball_x, ball_y = HEIGHT - 1;
    
    srand(time(NULL));
    
    for(int i = 0; i < PLATFORM_WIDTH; i++)
    {
        board[Y][x + i] = '*';
    }
    
    while(key != ESC)
    {
        if(ball_y == HEIGHT - 1)
        {
            ball_x = rand() % WIDTH;
            ball_y = 0;
        }
        
        board[ball_y - 1][ball_x] = 0;
        board[ball_y][ball_x] = BALL;
        
        for(int row = 0; row < HEIGHT; row++)
        {
            for(int col = 0; col < WIDTH; col++)
            {
                putchar(board[row][col]);
            }
        }
        
        printf("points: %d", points);
        
        if(kbhit())
        {
            key = getch();
            
            if(key == -32 || key == 224)
            {
                key = getch();
                
                if(key == LEFT && x != 0)
                {
                    x--;
                }
                else if(key == RIGHT && x + PLATFORM_WIDTH != WIDTH)
                {
                    x++;
                }
                
                if(x - 1 >= 0)
                {
                    board[Y][x - 1] = 0;
                }
                
                if(x + PLATFORM_WIDTH <= WIDTH)
                {
                    board[Y][x + PLATFORM_WIDTH] = 0;
                }
                
                for(int i = 0; i < PLATFORM_WIDTH; i++)
                {
                    board[Y][x + i] = '*';
                }
            }
        }
        
        if(ball_y++ == HEIGHT - 2)
        {
            board[ball_y - 1][ball_x] = 0;
            
            if(ball_x >= x && ball_x <= x + PLATFORM_WIDTH)
            {
                points++;
            }
            else
            {
                points--;
            }
        }
        
        Sleep(SLEEP);
        system("cls");
    }
    
    
    getchar();
}
