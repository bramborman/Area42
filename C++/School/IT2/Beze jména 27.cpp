#include <stdio.h>
#include <windows.h>

#define HEIGHT 25
#define WIDTH 80

int main()
{
    char array[HEIGHT][WIDTH];
    int size, row, col;
    
    do
    {
        printf("Zadej velikost: ");
        scanf("%d", &size);
    } while(size < 5 || size > 23);
    
    system("cls");
    
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            array[i][j] = ' ';
        }
    }
    
    row = (HEIGHT / 2) - (size / 2);
    
    for(int i = 0; i <= (size / 2) - (size % 2 == 0 ? 1 : 0); i++)
    {
    	col = (WIDTH / 2) - (size / 2);
    	
    	for(int j = i; j < size / 2; j++)
    	{
    		col++;
		}
		
		for(int j = 0; j <= (2 * i) + (size % 2 == 0 ? 1 : 0); j++)
		{
			array[row][col] = 'X';
			col++;
		}
		
		row++;
	}
    
    for(int i = (size / 2) - 1; i >= 0; i--)
    {
    	col = (WIDTH / 2) - (size / 2);
    	
    	for(int j = i; j < size / 2; j++)
    	{
    		col++;
		}
		
		for(int j = 0; j <= (2 * i) + (size % 2 == 0 ? 1 : 0); j++)
		{
			array[row][col] = 'X';
			col++;
		}
		
		row++;
	}
    
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            printf("%c", array[i][j]);
        }
    }
    
    getchar();getchar();
}
