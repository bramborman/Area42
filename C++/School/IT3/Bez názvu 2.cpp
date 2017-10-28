#include <stdio.h>
#include <windows.h>

int main()
{
	int size = 0;
	
	while (size % 2 == 0 || size < 0)
	{
		printf("Zadej lichou velikost pole: ");
		scanf("%d", &size);
	}
	
	int array[size];
	memset(array, 0, size * sizeof(int));
	array[size / 2] = 1;
	
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	
	printf("\n");
	system("pause");
}
