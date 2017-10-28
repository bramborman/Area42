#include <stdio.h>
int main()
{
    float prum=0;
    int a,p=0,x;
    printf("Zadej pocet zadavanych cisel: ");
    scanf("%d",&x);
    
    if(x==0)printf("Musis zadat vice cisel!");
    else{    
        do{
            printf("Zadej znamku: ");
            scanf("%d",&a);
            x--;
        
            if(a>0 && a<6){prum=prum+a;p++;}
            else printf("Nezadal jsi znamku!\n");
        }
        while(x>=1);
        
        prum=prum/(float)p;
        if(prum>0 && prum<6){
            printf("prumer: %.2f",prum);
        }
    }
    
    getchar();getchar();
}
