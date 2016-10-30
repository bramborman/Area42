#include <stdio.h>
int main()
{
    int c=0,max=-99999;
    for(int p=1;p<=5;p++){
        printf("Zadej %d cislo: ",p);
        scanf("%d",&c);
        if(max<c)max=c;
    }
    
    printf("max:%d",max);
    getchar();getchar();
}
