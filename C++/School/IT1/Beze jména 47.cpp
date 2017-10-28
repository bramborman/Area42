#include <stdio.h>
#include <windows.h>

int main()

{
   int a = 1;
   
   while(a != 0) {
      printf("Zadej cislo: ");
      scanf("%d",&a);
   }
   
   printf("%d",a);
   
   printf("\n\n");
   system("PAUSE");
}
