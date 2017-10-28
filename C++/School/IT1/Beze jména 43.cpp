#include <stdio.h>
int main()

{
   int c,x=0,s=0;
   
   do {
      printf("Zadej cislo: ");
      scanf("%d",&c);
      
      s=0;
      for(x=1;x<=c;x++) {
         s=s+x;
      }
      
      
   }while(s>100);
   
   printf("soucet: %d",s);
   
   getchar();getchar();
}
