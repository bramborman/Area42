#include <stdio.h>
#include <windows.h>

int main()
{
	char t[10];
	FILE *file;
	
	file = fopen("R:\\IT3\\Prg\\pokus2.txt", "w");
	
	fprintf(file, "ahoj\n");
	fclose(file);
	
	file = fopen("R:\\IT3\\Prg\\pokus2.txt", "a");
	
	fprintf(file, "zdar");
	fclose(file);
	
	file = fopen("R:\\IT3\\Prg\\pokus2.txt", "r");
	
	while (fscanf(file, "%s", t) != EOF)
	{
		printf("%s ", t);
	}
	
	fclose(file);
	
	putchar('\n');
	system("pause");
}
