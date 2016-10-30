#include <stdio.h>
#include <windows.h>

int main()
{
	FILE *file = fopen("text.txt", "r");
	
	int count = 0, temp;
	
	while (fscanf(file, "%d", &temp) != EOF)
	{
		count++;
	}
	
	fclose(file);
	file = fopen("text.txt", "r");
	
	int index = 0;
	int numbers[count];
	
	while (fscanf(file, "%d", &numbers[index++]) != EOF);
	fclose(file);
	
	for (int i = 0; i < count; i++)
	{
		printf("%d ", numbers[i]);
	}
	
	putchar('\n');
	
	int minIndex;
	
	for (int i = 0; i < count; i++)
	{
		minIndex = i;
		
		for (int j = i + 1; j < count; j++)
		{
			if (numbers[minIndex] > numbers[j])
			{
				minIndex = j;
			}
		}
		
		temp = numbers[i];
		numbers[i] = numbers[minIndex];
		numbers[minIndex] = temp;
		
		printf("%d ", numbers[i]);
	}
	
	printf("\n\n");
	system("pause");
}
