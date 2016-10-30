#include <stdio.h>
int main()
{
    int x=1;
    
    for(x;x<=5;x++)printf("%d\n",x);
    
    do{
        printf("%d\n",x);
        x++;
    }
    while(x<=10);
    
    getchar();
}
