#include <stdio.h>
int main()
{
    label:    
    int d,m,r;
    printf("Zadej cislo dne: ");
    scanf("%d",&d);
    printf("Zadej cislo mesice: ");
    scanf("%d",&m);
    printf("Zadej cislo roku: ");
    scanf("%d",&r);
    
    if(d>=1&&d<=31&&m>=1&&m<=12){
            if(2015-r>=18 && m-1>=0 && d-6>=0)printf("Jsi plnolety");
            else printf("Nejsi plnolety");
    }
    else {
            printf("Zadal jsi spatne datum!\n\n");
        goto label;    
    }   
    getchar();getchar();
}
