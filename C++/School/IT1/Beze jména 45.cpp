#include <stdio.h>
#include <windows.h>

int main()

{
   float bmi,vyska2,vaha,vyska,x;
   
   printf("\n\n\t\t\t");
   for(x = 0; x <=31;x++) {
       printf("*");
       Sleep(30);
   }
   printf("\n\t\t\t*   ******    **   **\t **    *");
   printf("\n\t\t\t*   **   **   *** ***\t **    *");
   printf("\n\t\t\t*   ******    *******\t **    *");
   printf("\n\t\t\t*   **   **   ** * **\t **    *");
   printf("\n\t\t\t*   **   **   **   **\t **    *");
   printf("\n\t\t\t*   ******    **   **\t **    *");
   
   printf("\n\t\t\t");
   for(x = 0; x <=31;x++) {
       printf("*");
       Sleep(30);
   }
   Sleep(300);
   system("cls");
   
   printf("\n\t\tZadej vysku: ");
   scanf("%f",&vyska);
   
   printf("\n\t\tZadej vahu: ");
   scanf("%f",&vaha);
   
   vyska2 = vyska/100;
   bmi = vaha/(vyska2*vyska2);
   printf("\n\t\t");
   printf("BMI: %.2f => ",bmi);
   if(bmi < 18.5) printf("%.2f => podvaha",bmi);
   else if(bmi >= 18.5 && bmi <= 24.9) printf("norma");
   else if(bmi >= 25.0 && bmi <= 29.9) printf("nadvaha");
   else if(bmi >= 30.0 && bmi <= 34.9) printf("obezita 1. stupne");
   else if(bmi >= 35.0 && bmi <= 39.9) printf("obezita 2. stupne (zavazna)");
   else if(bmi >= 40.0) printf("obezita 3. stupne (tezka)");
   
   printf("\n\n");
   system("PAUSE");
}
