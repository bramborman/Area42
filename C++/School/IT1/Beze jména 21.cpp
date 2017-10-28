#include <stdio.h>
int main()
{
    int c1=0,c2=0,c3=0;
    printf("Zadej tri cisla: ");
    scanf("%d%d%d",&c1,&c2,&c3);
    
    if(c1+c2<=c3 || c1+c3<=c2 || c2+c3<=c1)printf("Trojuhelnik nelze sestrojit.");
    else{
        printf("Trojuhelnik lze sestrojit.");
        if(c1==c2 && c2==c3)printf("\nrovnostranny");
        else {
            if(c1==c2 || c1==c3 || c2==c3)printf("\nrovnoramenny");
            else printf("\nobecny");
        }
    }
    getchar();getchar();
}
