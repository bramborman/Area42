#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <locale.h>

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "");
    
    bool youwin = false;
    int i, count, remove, pc, pca;
    
    do
    {
        printf("Vyber poèet zápalek pro hru (5 - 100): ");
        scanf("%d", &count);
    } while(count < 5 || count > 100);
    system("cls");
    
    for(; ; )
    {
        system("cls");
        printf("Aktuální poèet zápalek: %d", count);
        
        do
        {
            printf("\nOdeber 1 - 3 zápalky: ");
            scanf("%d", &remove);
        } while(remove < 1 || remove > 3);
        count -= remove;
        
        if(count == 1)
        {
            printf("Poèítaèi zbývá %d zápalka.", count);
            youwin = true;
            break;
        }
        
        for(pc = 1; pc <= 3; pc++)
        {
            if(count-pc == 1)
            {
                count -= pc;
                break;
            }
            else if(pc == 3 && count-pc >= 1)
            {
                for(pca = 1; pca <= 3; pca++)
                {
                    if(count-pc-pca == 1)
                    {
                        count -= pca;
                        pc = pca;
                        break;
                    }
                    else
                    {
                        pc = rand()%3 + 1;
                        count -= pc;
                        break;
                    }
                }
                break;
            }
            else if(pc == 3)
            {
                printf("FATAL ERROR\n!!!");
                system("pause");
                return 0;    
            }    
        }
        
        printf("Poèítaè odebral zápalek: %d\n", pc);
        getchar();getchar();
        
        if(count == 1)
        {
            printf("Zbývá ti %d zápalka.", count);
            youwin = false;
            break;
        }
    }
    
    if(youwin == true) printf("\n\nVyhrál jsi!!!\n\n");
    else printf("\n\nVyhrál poèítaè!!!\n\n");
    
    system("pause");
}
