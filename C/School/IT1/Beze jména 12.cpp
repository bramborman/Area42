#include <stdio.h>
int main()
{
    int cislo,ok1,ok2,ok;
    printf("Zadej cislo: ");
    scanf("%d",&cislo);
    if(cislo%3<1){
        ok1=1;
        }
    if(cislo%5<1){
        ok2=1;
        }
    ok=ok1+ok2;
    if(ok==2)printf("Cislo je delitelne 3mi a 5ti.");
    getchar();getchar();
}
