#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <locale.h>

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "");
    
    int human, pc, ph = 0, pp = 0;
    
    do
    {
        printf("Vyber:\n\t1 - k�men\n\t2 - n��ky\n\t3 - pap�r");
        scanf("%d", human);
        pc = rand()%3 + 1;
        
        if(human == 1)
        {
            
        }
        else if(human == 2)
        {
            
        }
        else if(human == 3)
        {
            
        }
    } while(ph < 10 && pp < 10 && ph != pp);
    
    if(ph > pp) printf("Vyhr�l jsi!!!");
    else if(pp > ph) printf("Vyhr�l PC!!!");
    
    system("pause");
}
