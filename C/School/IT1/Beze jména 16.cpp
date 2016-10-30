#include <stdio.h>
int main()
{
    int a,b,c,p;
    printf("Zadej tri cisla: ");
    scanf("%d%d%d",&a,&b,&c);
    if(a>b){
        p=a;
        a=b;
        b=p;
        }
    if(a>c){
        p=a;
        a=c;
        c=p;
        }
    if(b>c){
        p=b;
        b=c;
        c=p;
        }
    printf("Setrideno: %d<%d<%d",a,b,c);
    getchar();getchar();
}
