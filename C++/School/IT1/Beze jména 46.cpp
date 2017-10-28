#include <stdio.h>
#include <windows.h>

int main()

{
   int a,b,c,d,x;
   
   printf("Zadej 4 cisla: ");
   scanf("%d%d%d%d",&a,&b,&c,&d);
   
   if(a > b) {x=a;a=b;b=x;}
   if(a > c) {x=a;a=c;c=x;}
   if(a > d) {x=a;a=d;d=x;}
   if(b > c) {x=b;b=c;c=x;}
   if(b > d) {x=b;b=d;d=x;}
   if(c > d) {x=c;c=d;d=x;}
   
   if(a%2 == 0) printf("%d %d %d",b,c,d);
   else if(b%2 == 0) printf("%d %d %d",a,c,d);
   else if(c%2 == 0) printf("%d %d %d",a,b,d);
   else if(d%2 == 0) printf("%d %d %d",a,b,c);
   else printf("%d %d %d %d",a,b,c,d);
   
   printf("\n\n");
   system("PAUSE");
}
