#include <stdio.h>
#include <windows.h>

#define HEIGHT 25
#define WIDTH 80

int main()
{
    char array[HEIGHT][WIDTH];
    int size;
    
    do
    {
        printf("Zadej velikost: ");
        scanf("%d", &size);
    } while(size < 1 || size > 10);
    
    system("cls");
    
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            if  (
                    (
                        (i < size || i > HEIGHT - size - 1) && 
                        (j < size || j > WIDTH - size - 1)
                    ) ||
                    (
                        (i > (HEIGHT / 2) - (size / 2) && i < (HEIGHT / 2) + (size / 2)) && 
                        (j > (WIDTH / 2) - (size / 2) && j < (WIDTH / 2) + (size / 2))
                    )
                )
            {
                array[i][j] = '*';
            }
            else
            {
                array[i][j] = ' ';
            }
            
            printf("%c", array[i][j]);
        }
    }
    
    getchar();getchar();
}
