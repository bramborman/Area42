#include <stdio.h>
#include <windows.h>
#include <time.h>

void sort(int *array)
{
	int temp, max = array[0];
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (max < array[j])
			{
				max = j;
			}
		}
		
		temp = array[i];
		array[i] = array[max];
		array[max] = temp;
	}
}

int main()
{
	srand(time(NULL));
	
	int array[5];
	
	for (int i = 0; i < 5; i++)
	{
		array[i] = rand() % 10;
		printf("%d", array[i]);
	}
	
	putchar('\n');
	sort(array);
	
	for (int i = 0; i < 5; i++)
	{
		array[i] = rand() % 10;
		printf("%d", array[i]);
	}
	
	putchar('\n');
	system("pause");
}
