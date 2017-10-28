#include <stdio.h>
#include <windows.h>

void foo(size_t size, int arr[])
{
	int temp;
	
	for (int i = 0; i < size / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
	}
}

int main()
{
	int arr[] = { 1, 2, 3 };
	size_t size = sizeof(arr) / sizeof(arr[0]);
	
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	
	foo(size, arr);
	putchar('\n');
	
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}
