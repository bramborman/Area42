#include <stdio.h>
#include <windows.h>
#include <time.h>

int main()
{
    int x, y, z=0;
    
    system("color 0A");
    srand(time(0));
    x = rand()%10+1;
    
    for(;;){
        printf("Hadej cislo 1-10: ");
        scanf("%d", &y);
        z++;
        
        if(y == x) {
            printf("Vyhral jsi\npokusy: %d\n", z);
            break;
        }
        else if(y < x) printf("Zadej vyssi cislo\n\n");
        else if(y > x) printf("Zadej nizsi cislo\n\n");
    }
    system("pause");
}
