#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <locale.h>

int main()
{
    int o=0, b, x, y, z;
    
    srand(time(0));
    system("color 0A");
    setlocale(LC_ALL, "");
    
    do
    {
        system("cls");
        b = 0;
        do
        {
            printf("\n\n\t1: lehká\n\t2: støední\n\t3: tìžká\n\n\tVyber obtížnost: ");
            scanf("%d", &o);
            system("cls");
        } while(o<1 || o>3);
        
        while(b>-5 && b<3)
        {
            do
            {
                x = rand()%10;
                y = rand()%10;
                z = rand()%10;
                
                printf("\n\n\t\t\t\t    Body: %d\n\n\n\n\n\t\t\t\t *************\n\t\t\t\t * %d * %d * %d *\n\t\t\t\t *************\n\n\t\t\t\tStiskni klávesu!", b, x, y, z);
                
                if(o==1) Sleep(800);
                else if(o==2) Sleep(500);
                else if(o==3) Sleep(300);
                
                system("cls");
            } while(kbhit()==false);
            
            printf("\n\n\n\n\n\n\n\t\t\t\t *************\n\t\t\t\t * %d * %d * %d *\n\t\t\t\t *************\n\n\t\t\t  ", x, y, z);
            
            if(x==y && y==z) b+=2;
            else if(x==y || x==z || y==z) b++;
            else b--;
            
            system("pause");
            system("cls");
        }
        if(b>=3) printf("\n\n\t\t\t\t    Body: %d\n\n\n\n\n\t\t\t\t***************\n\t\t\t\t* Vyhrál jsi! *\n\t\t\t\t***************\n", b);
        else if(b==-5) printf("\n\n\t\t\t\t    Body: %d\n\n\n\n\n\t\t\t\t****************\n\t\t\t\t* Prohrál jsi! *\n\t\t\t\t****************\n", b);
        
        do
        {
            printf("\nChceš hrát znovu? (A/n): ");getchar();
            scanf("%c", &z);
        } while(z!='a' && z!='A' && z!='n' && z!='N');
    } while(z=='a' || z=='A');
}
