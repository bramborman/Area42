//
//
//	(c) Marian Dolinský 2015
//
//
#include <stdio.h>
#include <windows.h>

int main()
{
	int size, i, j, min;
	
	do
	{
		printf("Zadej velikost pole: ");
		scanf("%d", &size);
	} while(size < 1);
	
	int array[size], differences[size - 1];
	
	for(i = 0; i < size; i++)
	{
		printf("Zadej %d. hodnotu: ", i + 1);
		scanf("%d", &array[i]);
	}
	
	for(i = 0; i < size; i++)
	{
		min = i;
		
		for(j = i + 1; j < size; j++)
		{
			if(array[j] < array[min])
			{
				min = j;
			}
		}
		
		if(min != i)
		{
			j = array[i];
			array[i] = array[min];
			array[min] = j;
		}
	}
	
	for(i = 0; i < size - 1; i++)
	{
		differences[i] = array[i + 1] - array[i];
		
		printf("%d ", differences[i]);
	}
	
	printf("\n");
	system("pause");
}
