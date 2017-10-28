#include <stdio.h>
int main()

{
   int a,b,c,d,e,f,x;
   
   do {
      printf("Zadej 3 cisla: ");
      scanf("%d%d%d",&a,&b,&c);
   } while(a >= 0 || b >=0 || c >= 0);
   
   do {
      printf("Zadej 3 cisla: ");
      scanf("%d%d%d",&d,&e,&f);
   } while(d >= 0 || e >=0 || f >= 0);
   
   if(a > b) {x=a;a=b;b=x;}
   if(a > c) {x=a;a=c;c=x;}
   if(b > c) {x=b;b=c;c=x;}
   
   if(d > e) {x=d;d=e;e=x;}
   if(d > f) {x=d;d=f;f=x;}
   if(e > f) {x=e;e=f;f=x;}
   
   printf("Prostredni: %d a %d\n",b,e);
   
   if(b > e) {x=b;b=e;e=x;}
   x = b;
   
   do{
      printf("%d ",x);
      x++;
   } while(x != e);
   
   getchar();getchar();
}
