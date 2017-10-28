#include <stdio.h>
#include <windows.h>

int main()
{
	char filePath[100] = "";
	char fileName[8];
	FILE *file;
	
	printf("Zadej nazev souboru (max 8 znaku): ");
	scanf("%8s", fileName);
	
	strcat(filePath, "R:\\IT3\\Prg\\");
	strcat(filePath, fileName);
	strcat(filePath, ".txt");
	
	file = fopen(filePath, "w");
	fprintf(file, "ahoj");
	
	fclose(file);
	
	putchar('\n');
	system("pause");
}
