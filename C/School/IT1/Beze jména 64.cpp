#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#include <conio.h>

int main() {
    setlocale(LC_ALL, "");
    
    do printf("Fiša je tulipán!!!\n");
    while(kbhit() != true);
    
    system("pause");
}
