# include <stdio.h>
int main()
{
 int x,y;
 printf("Zadej 1. znak: ");
 x=getchar();
 getchar();
 printf("Zadej 2. znak: ");
 y=getchar();
 printf("%c", x+y);
 getchar();getchar();
}
