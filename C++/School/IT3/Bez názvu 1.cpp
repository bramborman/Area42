#include <stdio.h>
#include <windows.h>
#include <time.h>

typedef enum COLOR
{
	Black,
	DarkBlue,
	DarkGreen,
	DarkCyan,
	DarkRed,
	DarkMagenta,
	DarkYellow,
	Gray,
	DarkGray,
	Blue,
	Green,
	Cyan,
	Red,
	Magenta,
	Yellow,
	White
};

COLOR foregroundColor = White;
COLOR backgroundColor = Black;

void setforegroundcolor(COLOR foreground)
{
	foregroundColor = foreground;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foregroundColor + (backgroundColor << 4));
}

int main()
{
	srand(time(NULL));
	
	char ch;
	int size;
	
	printf("Zadej velikost ctverce: ");
	scanf("%d", &size);
	getchar();
	
	printf("Zadej znak: ");
	scanf("%c", &ch);
	
	for (int i = 0; i < size; i++)
	{
		setforegroundcolor((COLOR)(rand() % 16));
		putchar('\n');
		
		for (int j = 0; j < size; j++)
		{
			putchar(ch);
		}
	}
	
	setforegroundcolor(Gray);
	printf("\n\n");
	system("pause");
}
