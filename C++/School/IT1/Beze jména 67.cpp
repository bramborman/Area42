#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <locale.h>

int main()
{
    int x, n = 0;
    
    system("color 0A");
    srand(time(0));
    setlocale(LC_ALL, "");
    
    do
    {
        do
        {
            system("cls");
            x = rand()%7+1;
            
            printf("\n\n\n\n\n\n\n\n\n\t\t\t\t*********\n\t\t\t\t");
            if(x == 1) printf("*       *\n\t\t\t\t*   *   *\n\t\t\t\t*       *");
            else if(x == 2) printf("* *     *\n\t\t\t\t*       *\n\t\t\t\t*     * *");
            else if(x == 3) printf("* *     *\n\t\t\t\t*   *   *\n\t\t\t\t*     * *");
            else if(x == 4) printf("* *   * *\n\t\t\t\t*       *\n\t\t\t\t* *   * *");
            else if(x == 5) printf("* *   * *\n\t\t\t\t*   *   *\n\t\t\t\t* *   * *");
            else if(x == 6) printf("* *   * *\n\t\t\t\t* *   * *\n\t\t\t\t* *   * *");
            else if(x == 7) printf("* *   * *\n\t\t\t\t* * * * *\n\t\t\t\t* *   * *");
            printf("\n\t\t\t\t*********\n\n");
            
            Sleep(200);
        } while(kbhit() == false);
        
        if(x == 1) printf("\t\t\t\t  Pond�l�");
        else if(x == 2) printf("\t\t\t\t  �ter�");
        else if(x == 3) printf("\t\t\t\t  St�eda");
        else if(x == 4) printf("\t\t\t\t  �tvrtek");
        else if(x == 5) printf("\t\t\t\t  P�tek");
        else if(x == 6) printf("\t\t\t\t  Sobota");
        else if(x == 7)
        {
            printf("\t\t\t\t  Ned�le");
            n++;
        }
        printf("\n\t\t\t   Po�et ned�l� do konce: %d\n\t\t\t", 3-n);
        system("pause");
    } while(n < 3);
}
