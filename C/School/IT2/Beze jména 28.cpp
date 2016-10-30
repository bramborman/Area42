#include <stdio.h>
#include <windows.h>

#define ROWS 20
#define COLS 80

int main()
{
    char array[ROWS][COLS];
    int number, row, col, count, result = 0;
    
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            array[i][j] = '.';
        }
    }
    
    do
    {
        printf("Zadej pocet zadavani: ");
        scanf("%d", &count);
    } while(count < 1);
    
    system("cls");
    
    do
    {
        do
        {
            printf("Zadej radek: ");
            scanf("%d", &row);
        } while(row < 0 || row > ROWS);
        
        do
        {
            printf("Zadej sloupec: ");
            scanf("%d", &col);
        } while(col < 0 || col > COLS);
        
        printf("Zadej cislo: ");
        scanf("%d", &number);
        
        array[row][col] = number;
        
        count--;
        system("cls");
    } while(count > 0);
    
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(array[i][j] != '.')
            {
                result += array[i][j];
                printf("%d", array[i][j]);
            }
            else
            {
                printf(".");
            }
        }
    }
    
    printf("\nSoucet zadanych cisel (%d) je %s\n", result, (result % 2 == 0 ? "sudy" : "lichy"));
    system("pause");
}
