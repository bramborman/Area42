#include <stdio.h>
#include <windows.h>
#include <time.h>

void minmax(int min, int max)
{
	printf("\n\nmin: %d\nmax: %d\n", min, max);
}

void foo(size_t size, int arr[])
{
	int temp, max;
	
	for (int i = 0; i < size; i++)
	{
		max = i;
		
		for (int j = i + 1; j < size; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		
		if (max != i)
		{
			temp = arr[i];
			arr[i] = arr[max];
			arr[max] = temp;
		}
	}
	
	minmax(arr[size - 1], arr[0]);
}

int main()
{
	srand(time(NULL));
	
	int arr[10];
	size_t size = sizeof(arr) / sizeof(arr[0]);
	
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100 + 1;
		printf("%d ", arr[i]);
	}
	
	foo(size, arr);
	putchar('\n');
	
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}
