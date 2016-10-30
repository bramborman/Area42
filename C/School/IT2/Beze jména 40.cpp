#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

int main()
{
    int width, height;
    
    do
    {
        printf("Zadej vysku: ");
        scanf("%d", &height);
    } while(height < 1 || height > HEIGHT);
    
    do
    {
        printf("Zadej sirku: ");
        scanf("%d", &width);
    } while(width < 1 || width > WIDTH);
    
    char board[height][width];
    
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            board[y][x] = 0;
        }
    }
    
    for(int i = 0; i < height; i++)
    {
        board[i][width / 2] = '#';
    }
    
    for(int i = 0; i < width; i++)
    {
        board[height / 2][i] = '#';
    }
    
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            putchar(board[y][x]);
        }
        
        putchar('\n');
    }
    
    getchar();
    getchar();
    getchar();
}
