#include <stdio.h>
int main()
{
    int c1,c2,c3,c4,c5,v=0;
    printf("Zadej cislo: ");
    scanf("%d",&c1);
    if(c1!=0){v=c1;
        printf("Zadej cislo: ");
        scanf("%d",&c2);
        if(c2!=0){v=v+c2;
            printf("Zadej cislo: ");
            scanf("%d",&c3);
            if(c3!=0){v=v+c3;
                printf("Zadej cislo: ");
                scanf("%d",&c4);
                if(c4!=0){v=v+c4;
                    printf("Zadej cislo: ");
                    scanf("%d",&c5);
                    v=v+c5;
                }
            }
        }
    }
    printf("soucet cisel je: %d",v);
    getchar();getchar();
}
