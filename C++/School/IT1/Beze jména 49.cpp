#include <stdio.h>
#include <windows.h>

int main()

{
   int x = 1;
   
   while(x <= 5) {
      printf("%d\n",x);
      x++;
   }
   
   do {
      printf("%d\n",x);
      x++;
   } while(x <= 10);
   
   for(x;x<=15;x++) printf("%d\n",x);
   
   printf("\n\n");
   system("PAUSE");
}
