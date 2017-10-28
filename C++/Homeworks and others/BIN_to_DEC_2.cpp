/*
	Name: BIN to DEC
	Copyright: (c) 2016 Marian Dolinský
	Author: Marian Dolinský
	Date: 26/05/16 16:10
	Description: BIN to DEC numbers converter.
	
	DEBUG		- enables DEBUG mode
	BIT			- program will get result using bit shifting
*/

//#define DEBUG
//#define BIT

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#ifndef BIT
	#include <math.h>
#endif

#define BACKSPACE 8
#define ENTER 13
#define ESC 27
#define LEFT 75
#define RIGHT 77
#define DEL 83

int bintodec(const char *bin);
char *stradd(char *str, char ch, int index);
char *strrem(char *str, int index);
COORD getcursorposition();
void movecursor(int x, int y);
void movecursor(COORD position);

int main()
{
	system("color 0F");
	
	char key;
	char bin[9] = { 0 };
	int length, horizontalCursorPosition = 8;
	COORD inputCursorPosition;
	
#ifdef DEBUG
	fputs("\n\n\n", stdout);
#endif
	
	fputs("Enter any binary number (max 1B): ", stdout);
	inputCursorPosition = getcursorposition();
	
	while (key != ENTER || *bin == 0)
	{
		length = strlen(bin);
		
#ifdef DEBUG
		movecursor(0, 0);
		printf("key: %3d | ", key);
		printf("inputCursorPosition: %d %d | ", inputCursorPosition.X, inputCursorPosition.Y);
		printf("horizontalCursorPosition: %d | ", horizontalCursorPosition);
		printf("length: %d\n", length);
		
		printf("bin: %-8s | ", (length == 0 ? "N/A" : bin));
		
#ifdef BIT
		printf("mode: bit shift");
#else
		printf("mode: pow");
#endif
#endif
		
		movecursor(inputCursorPosition);
		
		for (int i = 0; i < 8 - length; i++)
		{
			putchar(' ');
		}
		
		if (length <= 4)
		{
			putchar(' ');
		}
		
		for (int i = 0; i < length; i++)
		{
			putchar(bin[i]);
			
			if (i == length - 5)
			{
				putchar(' ');
			}
		}
		
		movecursor(inputCursorPosition.X + horizontalCursorPosition + (horizontalCursorPosition >= 4 ? 1 : 0), inputCursorPosition.Y);
		key = getch();
		
		if (key == -32 || key == 224)
		{
			key = getch();
			
			if (key == LEFT && horizontalCursorPosition != 8 - length)
			{
				horizontalCursorPosition--;
			}
			else if (key == RIGHT && horizontalCursorPosition != 8)
			{
				horizontalCursorPosition++;
			}
			else if (key == DEL && horizontalCursorPosition != 8)
			{
				strrem(bin, length - 8 + horizontalCursorPosition);
				horizontalCursorPosition++;
			}
		}
		else
		{
			if (key == BACKSPACE && horizontalCursorPosition != 0)
			{
				//strrem(bin, length - 8 + horizontalCursorPosition - 1);
				strrem(bin, length - 9 + horizontalCursorPosition);
			}
			else if ((key == '0' || key == '1') && length != 8)
			{
				stradd(bin, key, length - 8 + horizontalCursorPosition);
			}
		}
	}
	
	system("cls");
	
	for (int i = 0; i < 8 - length; i++)
	{
		putchar('0');
		
		if (i == 3)
		{
			putchar(' ');
		}
	}
	
	for (int i = 0; i < length; i++)
	{
		putchar(bin[i]);
		
		if (i == length - 5)
		{
			putchar(' ');
		}
	}
	
	printf(" = %d\n\n", bintodec(bin));
	system("pause");
}

int bintodec(const char *bin)
{
	int dec = 0;
	int length = strlen(bin);
	
	for (int i = 0; i < length; i++)
	{
#ifdef BIT
		dec += *(bin + i) - '0' << length - 1 - i;
#else
		dec += (*(bin + i) - '0') * pow(2, length - 1 - i);
#endif
	}
	
	return dec;
}

char *stradd(char *str, char ch, int index)
{
	if (index >= 0 && index <= strlen(str))
	{
		memmove(str + index + 1, str + index, strlen(str) - index + 1);
		*(str + index) = ch;
	}
	
	return str;
}

char *strrem(char *str, int index)
{
	if (index >= 0 && index < strlen(str))
	{
		memmove(str + index, str + index + 1, strlen(str) - index);
	}
	
	return str;
}

COORD getcursorposition()
{
	CONSOLE_SCREEN_BUFFER_INFO stdOutBufferInfo;
	
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &stdOutBufferInfo);
	return stdOutBufferInfo.dwCursorPosition;
}

void movecursor(int x, int y)
{
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void movecursor(COORD position)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
