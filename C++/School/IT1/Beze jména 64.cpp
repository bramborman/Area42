#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#include <conio.h>

int main() {
    setlocale(LC_ALL, "");
    
    do printf("Fi�a je tulip�n!!!\n");
    while(kbhit() != true);
    
    system("pause");
}
