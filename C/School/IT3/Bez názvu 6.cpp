#include <stdio.h>
#include <windows.h>

int main()
{
	char text[10];
	FILE *file;
	
	file = fopen("R:\\IT3\\Prg\\pokus.txt", "w");
	
	printf("Enter any text: ");
	scanf("%10s", text);
	
	fprintf(file, text);
	fclose(file);
	
	memset(text, 0, 10 * sizeof(char));
	
	file = fopen("R:\\IT3\\Prg\\pokus.txt", "r");
	fscanf(file, "%s", text);
	
	printf("%s\n\n", text);
	system("pause");
}
