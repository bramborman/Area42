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
	char buffer[WIDTH];
	char *spaces;
	int temp;
	
	for (int i = 0; i < WIDTH; i++)
	{
		buffer[i] = rand() % (0xff - 20) + 20;
	}
	
	fputs(buffer, stdout);
	
	while (true)
	{
		while (buffer[temp] == ' ')
		{
			temp = rand() % WIDTH;
		}
		
		ch = buffer[temp];
		buffer[temp] = ' ';
		
		printf("\r%s", buffer);
		
		spaces = (char *)malloc(temp);
		memset(spaces, ' ', temp);
		
		for (int i = 0; i < 29; i++)
		{
			printf("%s%c", spaces, ch);
			Sleep(10);
			printf("\b ");
		}
		
		free(spaces);
	}
}
