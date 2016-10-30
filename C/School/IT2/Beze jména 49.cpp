#include <stdio.h>
#include <windows.h>
#include <time.h>

int main()
{
	const char *week[]  = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	const char *tyden[] = { "Pondeli", "Utery", "Streda", "Ctvrtek", "Patek", "Sobota", "Nedele" };
	
	bool regenerate;
	char input[10];
	int word, usedIndex = 0, right = 0, round = 3;
	int used[round];
	
	srand(time(NULL));
	 
	do
	{
		do
		{
			word = rand() % 7;
			
			for (int i = 0; i < usedIndex; i++)
			{
				if (regenerate = used[i] == word)
				{
					break;
				}
			}
		} while (regenerate);
		
		printf("%-9s = ", week[word]);
		scanf("%10s", input);
		input[0] = toupper(input[0]);
		
		for (int i = 1; i < strlen(input); i++)
		{
			input[i] = tolower(input[i]);
		}
		
		if (!strcmp(tyden[word], input))
		{
			used[usedIndex++] = word;
			right++;
		}
	} while (--round != 0);
	
	system("cls");
	printf("GAME OVER\nYou got %d word%s right.\n\n", right, right == 1 ? "" : "s");
	system("pause");
}
