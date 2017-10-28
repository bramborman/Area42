#include <stdio.h>
#include <windows.h>

int main()

{
   int a = 0, b = 0, c = 0;
   
   while(a < 1 || a > 5) {
      printf("Zadej cislo: ");
      scanf("%d",&a);
   }
   
   do {
      printf("Zadej cislo: ");
      scanf("%d",&b);
   } while(b < 1 || b > 5);
   
   // for(;c < 1 || c > 5;) {
   for(;;) {
      printf("Zadej cislo: ");
      scanf("%d",&c);
      //
      if(c < 1 || c > 5) break;
      //
   }
   
   printf("%d\n",a);
   printf("%d\n",b);
   printf("%d\n",c);
   
   printf("\n\n");
   system("PAUSE");
}
