#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#include <conio.h>

int main() {
    char ch;
    setlocale(LC_ALL, "");
    
    ch = getch();
    Sleep(2000);
    printf("\nzadaný znak: %c\n", ch);
    
    system("pause");
}
