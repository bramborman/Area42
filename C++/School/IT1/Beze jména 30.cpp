#include <stdio.h>
int main()
{
    int i=0;
    for(int i=1;i<10;i++){
        if(i==5)continue;
        printf("%d. ahoj\n",i);
    }
    getchar();getchar();
}
