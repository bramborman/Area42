#include <stdio.h>
int main()
{
    int a,b;
    printf("Zadej dve cisla: ");
    scanf("%d%d",&a,&b);
    if(a==b){
        printf("Cisla jsou shodna\n");
        if(a>0)printf("kladne");
        if(a<0)printf("zaporne");
        if(a==0)printf("nula");
    }
    if(a>b){
        if(b>0)printf("kladne");
        if(b<0)printf("zaporne");
        if(b==0)printf("nula");
    }
    if(a<b){
        if(a>0)printf("kladne");
        if(a<0)printf("zaporne");
        if(a==0)printf("nula");
    }
    getchar();getchar();
}
