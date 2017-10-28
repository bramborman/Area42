#include <stdio.h>
#include <windows.h>
#include <time.h>

int main()
{
	const int WIDTH = 120;
	
	system("color 0a");
	srand(time(NULL));
	
	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 10;
	cursor.bVisible = false;
	
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
	
	char ch;
	char buffer[WIDTH + 1];
	char *spaces;
	int temp;
	
	for (int i = 0; i < WIDTH; i++)
	{
		buffer[i] = rand() % (0xff - 33) + 33;
	}
	buffer[WIDTH] = '\0';
	
	while (true)
	{
		while (buffer[temp] == ' ')
		{
			temp = rand() % WIDTH;
		}
		
		ch = buffer[temp];
		buffer[temp] = ' ';
		
		printf("\r%s", buffer);
		
		spaces = (char *)malloc(temp + 1);
		memset(spaces, ' ', temp);
		*(spaces + temp) = '\0';
		
		for (int i = 0; i < 29; i++)
		{
			printf("%s%c", spaces, ch);
			Sleep(rand() % 50);
			printf("\b \n");
		}
		
		free(spaces);
		system("cls");
	}
}
