#include <stdio.h>
int main()
{
    float prum=0;
    int a,p=0,x;
    printf("Zadej pocet zadavanych cisel: ");
    scanf("%d",&x);
    
    if(x==0)printf("musis zadat vice cisel");
    else{    
        for(int i=1;i<=x;i++){
            printf("Zadej znamku: ");
            scanf("%d",&a);
        
            if(a>0 && a<6){prum=prum+a;p++;}
            else printf("nezadal jsi znamku\n");
        }
        prum=prum/(float)p;
        if(prum>0 && prum<6){
            printf("prumer: %.2f",prum);
        }
    }
    
    getchar();getchar();
}
