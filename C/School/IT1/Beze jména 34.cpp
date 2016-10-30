#include <stdio.h>
int main()
{
    int p=1;
    for(p;p<=5;p++)printf("%d\n",p);
    do{
        printf("%d\n",p);
        p++;
    }
    while(p<=10);
    getchar();
}
