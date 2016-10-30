#include <stdio.h>
#include <windows.h>
#include <time.h>

int main()
{
	const int COUNT = 5;
	
	const char *numbers[]  = { "one", "two", "three", "four", "five" };
	const char *enteredNumbers[COUNT];
	
	bool mistakeWrited = false;
	char input[6];
	int word = 0;
	
	do
	{
		printf("Enter %d as a word: ", word + 1);
		scanf("%6s", input);
		
		enteredNumbers[word++] = strdup(input);
	} while (word < COUNT);
	
	for (int i = 0; i < COUNT; i++)
	{
		if (strcmp(numbers[i], enteredNumbers[i]))
		{
			if (!mistakeWrited)
			{
				printf("\nYou made a mistake!");
				mistakeWrited = true;
			}
			
			printf("\n\"%s\" should be \"%s\"", enteredNumbers[i], numbers[i]);
		}
	}
	
	if (!mistakeWrited)
	{
		printf("You got damn right!");
	}
	
	printf("\n\n");
	system("pause");
}
