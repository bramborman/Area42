#include <stdio.h>
#include <windows.h>

int main()
{
	int numbers[3];
	FILE *file;
	
	file = fopen("R:\\IT3\\Prg\\pokus3.txt", "r");
	
	int i = 0;
	while (fscanf(file, "%d", &numbers[i++]) != EOF);
	
	fclose(file);
	
	int temp;
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			if (numbers[i] > numbers[j])
			{
				temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
	
	file = fopen("R:\\IT3\\Prg\\sorted.txt", "w");
	
	for (int i = 0; i < 3; i++)
	{
		fprintf(file, "%d\n", numbers[i]);
	}
	
	fclose(file);
	putchar('\n');
	system("pause");
}
