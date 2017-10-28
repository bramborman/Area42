/*
	Name: unigfcs.h (Universal game functions) v1.3 beta
	Copyright: (c) 2016 Marian Dolinský
	Author: Marian Dolinský
	Date: 29/04/16 21:42
	Description: Lots of useful functions for creating games in Windows console.
	
	TODO:
		add/edit coments
		add threads for console size checking
		use Project Superior
		pass arguments by reference to some functions - foo(STRUCT &struct);
		check for functions workings with memory etc success and if needed terminate the program
		revamp *center functions to work as formated output (printf)
	
	Possible MACROs:
	DEBUG					- enables DEBUG mode
	HIDE_HOTSEAT			- removes hotseat from mainmenu
	HIDE_DIFFICULTY			- removes difficulty menu
	HIDE_CUSTOMDIFFICULTY	- removes custom difficulty option
	HIDE_CHANGELOG			- removes changelogs
	BUFFER_NORESIZE			- buffer height will be only by 1 greater than window height
*/

#ifndef UNIGFCS_H
#define UNIGFCS_H

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#if !defined HIDE_CHANGELOG && !defined CHANGELOG_COLUMNS
	#error CHANGELOG_COLUMNS not defined
#endif

#ifdef DEBUG
	#warning DEBUG enabled
#endif

#define IS_ARROW(key) (key == -32 || key == 224)
#define IF_ARROW(key) (key == Up || key == Down || key == Left || key == Right)
#define IF_WASD(key) (key == 'W' || key == 'S' || key == 'A' || key == 'D')

// Using macros so don't have to pass so much arguments
#ifdef DEBUG
	#define DEBUG_CHEATS \
		printf("\n"); \
		for (int i = 0; i < sizeof(cheats) / sizeof(cheats[0]) - 1; i++) \
		{ \
			printf("cheats[%d]: %d | ", i, cheats[i]); \
		} \
		printf("cheats[%d]: %d", sizeof(cheats) / sizeof(cheats[0]) - 1, cheats[sizeof(cheats) / sizeof(cheats[0]) - 1])
	
	#define DEBUG_KEY(key) \
		printf("key: %c", printarrow(key));
	
	#define DEBUG_MAIN \
		movecursor(0, 0); \
		printf("selection: %d | ", selection); \
		printf("cursorPosition: %*d %*d | ", consoleSizeXPrecision, cursorPosition.X, consoleSizeXPrecision, cursorPosition.Y); \
		DEBUG_KEY(key); \
		DEBUG_CHEATS
#endif

typedef enum
{
    Black,
    Blue,
    Green,
    Cyan,
    Red,
    Magenta,
    Brown,
    LightGray,
    DarkGray,
    LightBlue,
    LightGreen,
    LightCyan,
    LightRed,
    LightMagenta,
    Yellow,
    White
} COLOR;

typedef enum
{
	Backspace = 8,
	Enter = 13,
	Esc = 27,
	Space = 32,
	Up = 72,
	Left = 75,
	Right = 77,
	Down = 80,
	Delete = 127
} KEY;

typedef enum
{
	Easy,
	Medium,
	Hard,
	Custom,
	None
} DIFFICULTY;

typedef enum
{
	Restart,
	Menu,
	Quit
} QUITACTION;

typedef enum
{
	Fisa,
	Hamster
} CHEAT;

typedef struct
{
	char Char;
	COLOR Color;
} VISUAL;

const char CHEATS[][10] =
{
	{ "fisa" },
	{ "hamster" }
};
#ifndef HIDE_CHANGELOG
const char CHANGELOG_UNIGFCS[][CHANGELOG_COLUMNS] =
{
	{ "1.3:" },
	{ "- Real time responsivity" },
	{ "- Added custom difficulty" },
	{ "- Added timer" },
	{ "- Added ability to move cursor" },
	{ "- Added custom console title" },
	{ "- Fully removed screen flashing" },
	{ "- Lots of improvements" },
	{ "- Lots of code optimalizations" },
	{ "- Some bugs were fixed" },
	{ "1.2:" },
	{ "- Added macros for ENTER, ESC and SPACE" },
	{ "- Added unigfcs.h changelog" },
	{ "- Improved responsive design" },
	{ "- Some bugs were fixed" },
	{ "1.1:" },
	{ "- Code were optimized" },
	{ "- Some bugs were fixed" },
	{ "1.0:" },
	{ "- First release" },
	{ "- Universal game menus" },
	{ "- Custom font" }
};
#endif
const char *gameName, *gameVersion, *gameBranch;
#ifndef BUFFER_NORESIZE
const int BUFFER_ADDITION = 1;
#else
const int BUFFER_ADDITION = 2;
#endif
const int MENU_SLEEP = 15;
const unsigned int CP_OEM = 437;
const COORD ORIGIN = {0, 0};
const HANDLE OUTPUTBUFFER = GetStdHandle(STD_OUTPUT_HANDLE);

bool consoleSizeChanged = true;
bool cheats[sizeof(CHEATS) / sizeof(CHEATS[0])] = { false };
char key;
#ifdef DEBUG
int consoleSizeXPrecision;
#endif
COLOR backgroundColor, foregroundColor;
CONSOLE_SCREEN_BUFFER_INFO consoleBuffer;
// Console sizes are decreased by 1 because of first line (y axis) and body (x axis)
COORD consoleSize, minimalConsoleSize, forcedConsoleSize, commonCursorPosition;

// Applicable for bool-returning functions: returns true to make caller return too
// checkconsolesize() returns true when console size was changed
void initialize(const char *name, const char *version, const char *branch, int minimalConsoleWidth, int minimalConsoleHeight);
DWORD WINAPI sizecheckthread(LPVOID lpvoid);
void setconsolesize(COORD size);
void getconsolesize();
bool checkconsolesize();
void forceconsolesize();
void copybuffer(const HANDLE *destination, const HANDLE *source);
void setcursor(bool isVisible);
void getcursorposition(COORD *cursorPosition);
void movecursor(int x, int y);
void movecursor(COORD position);
void setbackground(COLOR background);
void setforeground(COLOR foreground);
char getcheat(char ch);
char getarrow(char ch);
#ifdef DEBUG
char printarrow(char arrow);
#endif
void print(VISUAL visual);
// WARNING!!! Do not use more than one '\n' at the end of the TEXT string in center functions
// If so every \n will increase string length
void hcenter(int length);
void hcenter(int length, const char *text);
void hcenter(const char *text);
void vcenter(int rows);
void mainmenu(COLOR titleColor);
bool difficultyselection(bool hotseat);
void wheelselection(COORD cursorPosition, int selected, int min, int max, int step);
void about();
#ifndef HIDE_CHANGELOG
void changelog(const char CHANGELOG[][CHANGELOG_COLUMNS], int size);
#endif
bool pausemenu(bool hotseat, bool showTimer, bool isTimerColored);
bool quitmessage(QUITACTION action, bool playing, bool hotseat);
void showscore(bool won, int score, DIFFICULTY difficulty, const char *gameMode);
void showscore(bool won[2], int score[2], DIFFICULTY difficulty, const char *gameMode);
void timer(bool isColored);
// WARNING!!! Prints only alphabet, numbers and space
void bigtext(const char *text);
bool operator ==(COORD coord1, COORD coord2);
bool operator !=(COORD coord1, COORD coord2);
bool operator <(COORD coord1, COORD coord2);
bool operator >(COORD coord1, COORD coord2);
bool operator <=(COORD coord1, COORD coord2);
bool operator >=(COORD coord1, COORD coord2);
// These must be in each game
void controls();
bool game(DIFFICULTY difficulty, bool hotseat);
//void customdifficultyselection(); - returned data type depends on game

void initialize(const char *name, const char *version, const char *branch, int minimalConsoleWidth, int minimalConsoleHeight)
{
	gameName = strdup(name);
	gameVersion = strdup(version);
	gameBranch = strdup(branch);
	
	minimalConsoleSize.X = minimalConsoleWidth;
	minimalConsoleSize.Y = minimalConsoleHeight;
	
#ifndef DEBUG
	setcursor(false);
	srand(time(NULL));
#else
	setcursor(true);
#endif
	
	// Set Lucida Console font
	CONSOLE_FONT_INFOEX font;
    font.cbSize = sizeof(font);
    font.nFont = 7;
    font.dwFontSize.X = 12;
    font.dwFontSize.Y = 16;
    font.FontFamily = FF_DONTCARE;
    font.FontWeight = FW_NORMAL;
    wcscpy(font.FaceName, L"Lucida Console");
    
    SetCurrentConsoleFontEx(OUTPUTBUFFER, false, &font);
    
	checkconsolesize();
	SetConsoleTitle(name);
	
	// Use OEM Code Page
	SetConsoleOutputCP(CP_OEM);
	system("color 0F");
	
	CreateThread(NULL, 0, sizecheckthread, NULL, 0, NULL);
}

DWORD WINAPI sizecheckthread(LPVOID lpvoid)
{
	while (true)
	{
		consoleSizeChanged = checkconsolesize();
		Sleep(100);
	}
	
	return EXIT_SUCCESS;
}

void setconsolesize(COORD size)
{
	SMALL_RECT windowSize = {0};
	
	// Cannot set greater size than (buffer - 1) and buffer size cannot be less than window size
	if (consoleSize.X < size.X || consoleSize.Y < size.Y)
	{
		windowSize.Right = consoleSize.X < size.X ? consoleSize.X : size.X;
		windowSize.Bottom = consoleSize.Y < size.Y ? consoleSize.Y : size.Y;
		
		SetConsoleWindowInfo(OUTPUTBUFFER, true, &windowSize);
	}
	
	COORD bufferSize = { size.X + 1, size.Y + BUFFER_ADDITION };
	SetConsoleScreenBufferSize(OUTPUTBUFFER, bufferSize);
	
	windowSize.Right = size.X;
	windowSize.Bottom = size.Y;
	SetConsoleWindowInfo(OUTPUTBUFFER, true, &windowSize);
	
	getconsolesize();
}

void getconsolesize()
{
	// Get console sizes and assign consoleSize
    GetConsoleScreenBufferInfo(OUTPUTBUFFER, &consoleBuffer);
    
    consoleSize.X = consoleBuffer.srWindow.Right - consoleBuffer.srWindow.Left + 1;
	consoleSize.Y = consoleBuffer.srWindow.Bottom - consoleBuffer.srWindow.Top + BUFFER_ADDITION;
	
	SetConsoleScreenBufferSize(OUTPUTBUFFER, consoleSize);
	
	consoleSize.X--;
	consoleSize.Y -= BUFFER_ADDITION;
}

bool checkconsolesize()
{
	COORD lastConsoleSize = consoleSize;
	getconsolesize();
    	
#ifdef DEBUG
	consoleSizeXPrecision = (consoleSize.X < 100 ? 2 : 3);
#endif
    
    if (consoleSize < minimalConsoleSize)
    {
    	setconsolesize(minimalConsoleSize);
    	return true;
	}
	else if (consoleSize.X < minimalConsoleSize.X)
	{
		consoleSize.X = minimalConsoleSize.X;
		setconsolesize(consoleSize);
		return true;
	}
	else if (consoleSize.Y < minimalConsoleSize.Y)
	{
		consoleSize.Y = minimalConsoleSize.Y;
		setconsolesize(consoleSize);
		return true;
	}
	
	return lastConsoleSize != consoleSize;
}

void forceconsolesize()
{
	getconsolesize();
	
	if (consoleSize != forcedConsoleSize)
	{
		setconsolesize(forcedConsoleSize);
	}
}

void copybuffer(const HANDLE *dest, const HANDLE *source)
{
	COORD bufferSize = {consoleSize.X + 1, consoleSize.Y + 1};
	CHAR_INFO charInfo[bufferSize.Y][bufferSize.X];
	
	SMALL_RECT region = {0, 0, consoleSize.X, consoleSize.Y};
	
	ReadConsoleOutput(*source, &charInfo[0][0], bufferSize, ORIGIN, &region);
	WriteConsoleOutput(*dest, &charInfo[0][0], bufferSize, ORIGIN, &region);
}

void setcursor(bool isVisible)
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 20;
	cursor.bVisible = isVisible;
	
	SetConsoleCursorInfo(OUTPUTBUFFER, &cursor);
}

void getcursorposition(COORD *cursorPosition)
{
	GetConsoleScreenBufferInfo(OUTPUTBUFFER, &consoleBuffer);
	*cursorPosition = consoleBuffer.dwCursorPosition;
}

void movecursor(int x, int y)
{
	COORD position = { x, y };
	SetConsoleCursorPosition(OUTPUTBUFFER, position);
}

void movecursor(COORD position)
{
	SetConsoleCursorPosition(OUTPUTBUFFER, position);
}

void setbackground(COLOR background)
{
    backgroundColor = background;
    SetConsoleTextAttribute(OUTPUTBUFFER, foregroundColor + (backgroundColor << 4));
}

void setforeground(COLOR foreground)
{
    foregroundColor = foreground;
    SetConsoleTextAttribute(OUTPUTBUFFER, foregroundColor + (backgroundColor << 4));
}

char getcheat(char ch)
{
	for (int i = 0; i < sizeof(CHEATS) / sizeof(CHEATS[0]); i++)
	{
		if (!IS_ARROW(ch) && (ch == CHEATS[i][0] || ch == toupper(CHEATS[i][0])))
		{
			for (int j = 1; j < strlen(CHEATS[i]); j++)
			{
				key = getch();
				
				if (key != CHEATS[i][j] && key != toupper(CHEATS[i][j]))
				{
					return 'X';
				}
			}
			
			cheats[i] = !cheats[i];
			return 'X';
		}
	}
	
	return ch;
}

char getarrow(char ch)
{
	if (IS_ARROW(ch))
	{
		return getch();
	}
	
	return ch;
}

#ifdef DEBUG
char printarrow(char arrow)
{
	switch(arrow)
	{
		case Up:
			return 'U';
			
		case Down:
			return 'D';
			
		case Left:
			return 'L';
			
		case Right:
			return 'R';
		
		default:
			return 'N';
	}
}
#endif

void print(VISUAL visual)
{
	COLOR foregroundColorBackup = foregroundColor;
	
	setforeground(visual.Color);
	putchar(visual.Char);
	setforeground(foregroundColorBackup);
}

void hcenter(int length)
{
	getcursorposition(&commonCursorPosition);
	commonCursorPosition.X += (consoleSize.X + 1 - length) / 2;
	
	movecursor(commonCursorPosition);
}

void hcenter(int length, const char *text)
{
	hcenter(length);
	fputs(text, stdout);
}

void hcenter(const char *text)
{
	hcenter(strlen(text), text);
}

void vcenter(int rows)
{
	getcursorposition(&commonCursorPosition);
	commonCursorPosition.Y += (consoleSize.Y + 1 - rows) / 2;
	movecursor(commonCursorPosition);
}

void cls()
{
	//FillConsoleOutputCharacter(OUTPUTBUFFER, 0, consoleSize.X * consoleSize.Y)
}

void mainmenu(COLOR titleColor)
{
	const int CENTERING = 10;

#ifndef HIDE_HOTSEAT
	const int SELECTION_MAX = 4;
#else
	const int SELECTION_MAX = 3;
#endif
	
	bool renderMain = true;
	bool renderSelection = true;
	int selection = 0;
	COORD cursorPosition;

	checkconsolesize();
	
	while (true)
	{
		if (consoleSizeChanged || renderMain)
		{
			system("cls");
			
			vcenter(13);
			
			setforeground(titleColor);
			bigtext(gameName);
			setforeground(White);
			
			#ifdef DEBUG
				putchar('\n');
				hcenter(-20, "DEBUG MODE\n");
				putchar('\n');
			#else
				printf("\n\n\n");
			#endif
			
			hcenter(CENTERING, "Start game\n");
			
			cursorPosition = commonCursorPosition;
			cursorPosition.X -= 2;
			
			#ifndef HIDE_HOTSEAT
				hcenter(CENTERING, "Hotseat\n");
			#endif
			
			hcenter(CENTERING, "Controls\n");
			hcenter(CENTERING, "About\n");
			putchar('\n');
			hcenter(CENTERING, "Quit game");
			
			consoleSizeChanged = false;
			renderMain = false;
			renderSelection = true;
		}
		
		#ifdef DEBUG
			DEBUG_MAIN;
		#endif
		
		if (renderSelection)
		{
			for (int i = (selection == SELECTION_MAX ? -2 : -1); i <= (selection == SELECTION_MAX - 1 ? 2 : 1); i++)
			{
				movecursor(cursorPosition.X, cursorPosition.Y + selection + (selection == SELECTION_MAX ? 1 : 0) + i);
				putchar(' ');
			}
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection + (selection == SELECTION_MAX ? 1 : 0));
			putchar('>');
			renderSelection = false;
		}
		
		if (kbhit())
		{
			key = getarrow(getcheat(getch()));
			
			if ((key == Enter && selection == SELECTION_MAX) || key == Esc)
			{
				quitmessage(Quit, false, false);
				renderMain = true;
				continue;
			}
			else if (key == Enter)
			{
				if (selection == 0)
				{
					difficultyselection(false);
				}
				
				#ifndef HIDE_HOTSEAT
					else if (selection == 1)
					{
						difficultyselection(true);
					}
				#endif
				
				else if (selection == SELECTION_MAX - 2)
				{
					controls();
				}
				else
				{
					about();
				}
				
				renderMain = true;
				continue;
			}
			else if (key == Up && selection != 0)
			{
				selection--;
				renderSelection = true;
			}
			else if (key == Down && selection != SELECTION_MAX)
			{
				selection++;
				renderSelection = true;
			}
		}
		
		Sleep(MENU_SLEEP);
	}
}

bool difficultyselection(bool hotseat)
{
#ifdef HIDE_DIFFICULTY
	game(None, hotseat);
#else
	const int CENTERING = 6;
	
	#ifndef HIDE_CUSTOMDIFFICULTY
		const int SELECTION_MAX = 4;
	#else
		const int SELECTION_MAX = 3;
	#endif
	
	int selection = 1;
	COORD cursorPosition;
		
	checkconsolesize();
	
	while (true)
	{
		system("cls");
		
		vcenter(7);
		hcenter("CHOOSE DIFFICULTY");
		fputs("\n\n", stdout);
		
		hcenter(CENTERING, "Easy\n");
		
		cursorPosition = commonCursorPosition;
		cursorPosition.X -= 2;
		
		hcenter(CENTERING, "Medium\n");
		hcenter(CENTERING, "Hard\n");
		putchar('\n');
		
#ifndef HIDE_CUSTOMDIFFICULTY
	hcenter(CENTERING, "Custom\n");
#endif
		
		hcenter(CENTERING, "Back");
		
		while (true)
		{
			
#ifdef DEBUG
	DEBUG_MAIN;
#endif
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection + (selection >= 3 ? 1 : 0));
			putchar('>');
			
			key = getarrow(getcheat(getch()));
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection + (selection >= 3 ? 1 : 0));
			putchar(' ');
			
			if ((key == Enter && selection == 4) || key == Esc)
			{
				return false;
			}
			else if (key == Enter)
			{
				if (game((DIFFICULTY)selection, hotseat))
				{
					return true;
				}
				
				break;
			}
			else if (key == Up && selection != 0)
			{
				selection--;
			}
			else if (key == Down && selection != SELECTION_MAX)
			{
				selection++;
			}
			
			if (checkconsolesize())
			{
				break;
			}
		}
	}
#endif
}

void wheelselection(COORD cursorPosition, int selected, int min, int max, int step)
{
	movecursor(cursorPosition);
	hcenter(19);
	
	setforeground(DarkGray);
	printf("%3d ", (selected == min + step ? max : (selected == min ? max - step : selected - (2 * step))));
	
	setforeground(LightGray);
	printf("%3d ", (selected == min ? max : selected - step));
	
	setforeground(White);
	printf("%3d ", selected);
	
	setforeground(LightGray);
	printf("%3d ", (selected == max ? min : selected + step));
	
	setforeground(DarkGray);
	printf("%3d", (selected == max - step ? min : (selected == max ? min + step : selected + (2 * step))));
	
	setforeground(White);
}

void about()
{
	const int CENTERING = 24;
	
	bool printGameBranch = gameBranch != NULL && gameBranch != "";
	int selection = 2;
	COORD cursorPosition;
	
	checkconsolesize();
	
	while (true)
	{
		system("cls");

#ifndef HIDE_CHANGELOG
	vcenter(10 + (printGameBranch ? 1 : 0));
#else
	vcenter(7 + (printGameBranch ? 1 : 0));
#endif
		
		hcenter("ABOUT");
		fputs("\n\n", stdout);
		
		hcenter(CENTERING);
		printf("%s %s\n", gameName, gameVersion);
		
		if (printGameBranch)
		{
			hcenter(CENTERING);
			printf("Current branch: %s", gameBranch);
		}
		
#ifdef DEBUG
	fputs(" (DEBUG)", stdout);
#endif
		
		putchar('\n');
		hcenter(CENTERING, "Created using unigfcs.h v1.3\n");
		hcenter(CENTERING);
    	printf("Current console size: %dx%d\n\n", consoleSize.X + 1, consoleSize.Y + 1);
    	
		SetConsoleOutputCP(1250);
		hcenter(CENTERING, "(c) 2016 Marian Dolinský\n\n");
		SetConsoleOutputCP(CP_OEM);

#ifndef HIDE_CHANGELOG	
	hcenter(9, "Changelog\n");
	
	cursorPosition = commonCursorPosition;
	cursorPosition.X -= 2;
	
	hcenter(9, "Changelog (unigfcs.h)\n");
	hcenter(9, "Back");
#else
	hcenter("> Back");
#endif
		
		while (true)
		{
			
#ifdef DEBUG
	DEBUG_MAIN;
#endif
			
#ifndef HIDE_CHANGELOG
	movecursor(cursorPosition.X, cursorPosition.Y + selection);
	putchar('>');
	
	key = getarrow(getcheat(getch()));
	
	movecursor(cursorPosition.X, cursorPosition.Y + selection);
	putchar(' ');
	
	if ((key == Enter && selection == 2) || key == Esc)
	{
		return;
	}
	else if (key == Enter)
	{
		if (selection == 0)
		{
			changelog(CHANGELOG_GAME, sizeof(CHANGELOG_GAME));
		}
		else
		{
			changelog(CHANGELOG_UNIGFCS, sizeof(CHANGELOG_UNIGFCS));
		}
		
		selection = 2;
		break;
	}
	else if (key == Up && selection != 0)
	{
		selection--;
	}
	else if (key == Down && selection != 2)
	{
		selection++;
	}
#else
	key = getcheat(getch());
	
	if (key == Enter || key == Esc)
	{
		return;
	}
#endif
			
			if (checkconsolesize())
			{
				break;
			}
		}
	}
}

#ifndef HIDE_CHANGELOG
void changelog(const char CHANGELOG[][CHANGELOG_COLUMNS], int size)
{
	const int CENTERING = 37;
	const int ROWS_MAX = 15;
	
	bool consoleSizeChanged;
	int row = 0;
	
	checkconsolesize();
	
	while (true)
	{
		consoleSizeChanged = false;
		system("cls");
		
		vcenter(ROWS_MAX + 4);
		hcenter(CHANGELOG == CHANGELOG_GAME ? "CHANGELOG" : "CHANGELOG (UNIGFCS.H)");
		fputs("\n\n", stdout);
		
		for (int i = 0; i < ROWS_MAX; i++)
		{
			hcenter(CENTERING + (CHANGELOG[row + i][0] != '-' ? 5 : 0));
			puts(CHANGELOG[row + i]);
		}
		
		putchar('\n');
		hcenter("> Back  ");
		
		while (true)
		{
			
#ifdef DEBUG
	movecursor(0, 0);
	printf("row: %2d | ", row);
	printf("size: %d | ", size);
	printf("consoleSizeChanged: %d | ", consoleSizeChanged);
	DEBUG_KEY(key);
	DEBUG_CHEATS;
#endif
			
			key = getarrow(getcheat(getch()));
			
			// Console size must be checked before cycle is breaked from
			consoleSizeChanged = checkconsolesize();
			
			if (key == Enter || key == Esc)
			{
				return;
			}
			else if (key == Up && row != 0)
			{
				row--;
				break;
			}
			else if (key == Down && row != size / sizeof(CHANGELOG[0]) - ROWS_MAX)
			{
				row++;
				break;
			}
			
			if (consoleSizeChanged)
			{
				break;
			}
		}
	}
}
#endif

bool pausemenu(bool hotseat, bool showTimer, bool isTimerColored)
{
	const int CENTERING = 8;
	
	int selection = 0;
	COORD cursorPosition;

	checkconsolesize();
	
	HANDLE gameBoardBuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,  FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	copybuffer(&gameBoardBuffer, &OUTPUTBUFFER);
	
	while (true)
	{
		system("cls");
		system("color 0F");
		
		vcenter(7);
		hcenter("PAUSE MENU");
		fputs("\n\n", stdout);
		
		hcenter(CENTERING, "Resume\n");
		
		cursorPosition = commonCursorPosition;
		cursorPosition.X -= 2;
		
		hcenter(CENTERING, "Restart\n");
		hcenter(CENTERING, "Controls\n");
		hcenter(CENTERING, "Go to main menu\n");
		hcenter(CENTERING, "Quit game");
		
		while (true)
		{
			
#ifdef DEBUG
	DEBUG_MAIN;
#endif
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection);
			putchar('>');
			
			key = getarrow(getcheat(getch()));
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection);
			putchar(' ');
			
			if ((key == Enter && selection == 0) || key == Esc)
			{
				
#ifndef DEBUG
	if (showTimer)
	{
		timer(isTimerColored);
	}
#endif
				
				copybuffer(&OUTPUTBUFFER, &gameBoardBuffer);
				forceconsolesize();
				
				return false;
			}
			else if (key == Enter)
			{
				if (selection == 2)
				{
					controls();
				}
				else
				{
					if (quitmessage(selection == 1 ? Restart : (selection == 3 ? Menu : Quit), true, hotseat))
					{
						copybuffer(&OUTPUTBUFFER, &gameBoardBuffer);
						return true;
					}
				}
				
				break;
			}
			else if (key == Up && selection != 0)
			{
				selection--;
			}
			else if (key == Down && selection != 4)
			{
				selection++;
			}
			
			if (checkconsolesize())
			{
				break;
			}
		}
	}
}

bool quitmessage(QUITACTION action, bool playing, bool hotseat)
{
	checkconsolesize();
	
	int selection = 1;
	COORD cursorPosition;
	
	while (true)
	{
		system("cls");
		
		vcenter(playing ? 4 : 3);
		hcenter(action == Restart ? "Are you sure you want to restart the game?" : (action == Menu ?  "Are you sure you want to go to main menu?" : "Are you sure you want to quit the game?"));
		
		if (playing)
		{
			putchar('\n');
			hcenter("Your game progress will be lost!");
		}
		
		fputs("\n\n", stdout);
		hcenter(18, "Yes");
		
		
		cursorPosition = commonCursorPosition;
		cursorPosition.X += 14;
		
		for (int i = 0; i < 13; i++)
		{
			putchar(' ');
		}
		
		fputs("No", stdout);
		
		while (true)
		{
			
#ifdef DEBUG
	DEBUG_MAIN;
#endif
			
			movecursor(cursorPosition.X - (selection == 0 ? 16 : 0), cursorPosition.Y);
			putchar('>');
			
			key = getarrow(getcheat(getch()));
			
			movecursor(cursorPosition.X - (selection == 0 ? 16 : 0), cursorPosition.Y);
			putchar(' ');
			
			if ((key == Enter && selection == 1) || key == Esc)
			{
				return false;
			}
			else if (key == Enter)
			{
				if (action == Restart)
				{
					return difficultyselection(hotseat);
				}
				else if (action == Menu)
				{
					return true;
				}
				else
				{
					system("cls");
					exit(EXIT_SUCCESS);
				}
			}
			else if (key == Left && selection != 0)
			{
				selection--;
			}
			else if (key == Right && selection != 1)
			{
				selection++;
			}
			
			if (checkconsolesize())
			{
				break;
			}
		}
	}
}

void showscore(bool won, int score, DIFFICULTY difficulty, const char *gameMode)
{
	const int CENTERING = 7;

	checkconsolesize();
	
	int selection = 1;
	COORD cursorPosition;
		
	while (true)
	{
		system("cls");
		system("color 0F");
		
		vcenter(14);
		
		if (won)
		{
			setforeground(LightGreen);
			bigtext("YOU WON");
		}
		else
		{
			setforeground(LightRed);
			bigtext("GAME OVER");
		}
		
		setforeground(White);
		printf("\n\n\n");
		
		hcenter(14);
		printf("Your score: %d\n\n", score);
		
		hcenter(18);
		printf("Difficulty: %s\n", difficulty == Easy ? "Easy" : (difficulty == Medium ? "Medium" : (difficulty == Hard ? "Hard" : "Custom")));
		
		hcenter(18);
		printf("Game mode: %s\n\n", gameMode);
		
		hcenter(CENTERING, "Restart\n");
		
		cursorPosition = commonCursorPosition;
		cursorPosition.X -= 2;
		
		hcenter(CENTERING, "Back");
		
		while (true)
		{
			
#ifdef DEBUG
	DEBUG_MAIN;
#endif
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection);
			putchar('>');
			
			key = getarrow(getcheat(getch()));
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection);
			putchar(' ');
			
			if ((key == Enter && selection == 1) || key == Esc)
			{
				return;
			}
			else if (key == Enter)
			{
				difficultyselection(false);
				return;
			}
			else if (key == Up && selection != 0)
			{
				selection--;
			}
			else if (key == Down && selection != 1)
			{
				selection++;
			}
			
			if (checkconsolesize())
			{
				break;
			}
		}
	}
}

void showscore(bool won[2], int score[2], DIFFICULTY difficulty, const char *gameMode)
{
	const int CENTERING = 7;

	checkconsolesize();
	
	int selection = 1;
	COORD cursorPosition;
		
	while (true)
	{
		system("cls");
		system("color 0F");
		
		vcenter(15);
		
		if (won[0] || won[1])
		{
			setforeground(LightGreen);
			bigtext("YOU WON");
		}
		else
		{
			setforeground(LightRed);
			bigtext("GAME OVER");
		}
		
		setforeground(White);
		printf("\n\n\n");
		
		hcenter(27);
		printf(won[0] ? "Player 1 won with score %d\n" : "Player 1 died with score %d\n", score[0]);
		
		hcenter(27);
		printf(won[1] ? "Player 2 won with score %d\n" : "Player 2 died with score %d\n\n", score[1]);
		
		hcenter(18);
		printf("Difficulty: %s\n", difficulty == Easy ? "Easy" : (difficulty == Medium ? "Medium" : (difficulty == Hard ? "Hard" : "Custom")));
		
		hcenter(18);
		printf("Game mode: %s\n\n", gameMode);
		
		hcenter(CENTERING, "Restart\n");
		
		cursorPosition = commonCursorPosition;
		cursorPosition.X -= 2;
		
		hcenter(CENTERING, "Back");
	
		while (true)
		{
			
#ifdef DEBUG
	DEBUG_MAIN;
#endif
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection);
			putchar('>');
			
			key = getarrow(getcheat(getch()));
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection);
			putchar(' ');
			
			if ((key == Enter && selection == 1) || key == Esc)
			{
				return;
			}
			else if (key == Enter)
			{
				difficultyselection(true);
				return;
			}
			else if (key == Up && selection != 0)
			{
				selection--;
			}
			else if (key == Down && selection != 1)
			{
				selection++;
			}
			
			if (checkconsolesize())
			{
				break;
			}
		}
	}
}

void timer(bool isColored)
{
	const int SLEEP = 1100;
	system("cls");
	
	if (isColored)
	{
		setforeground(LightRed);
	}
	
	vcenter(5);
	bigtext("3");
	Sleep(SLEEP);
	system("cls");
	
	if (isColored)
	{
		setforeground(Yellow);
	}
	
	vcenter(5);
	bigtext("2");
	Sleep(SLEEP);
	system("cls");
	
	if (isColored)
	{
		setforeground(LightGreen);
	}
	
	vcenter(5);
	bigtext("1");
	Sleep(SLEEP);
	system("cls");
	
	vcenter(5);
	bigtext("GO!");
	Sleep(SLEEP);
	
	setforeground(White);
}

void bigtext(const char *text)
{
	// centering assigned to 4 because of four spaces on right and left side
	// strlen(text) - 1 = count of spaces between each letters
	// int centering = 4 + strlen(text) - 1;
	int centering = 3 + strlen(text);
	char str[strlen(text)];
	
	strcpy(str, text);
	
	// Rewrite str as upper case and set centering
	for (int i = 0; i < strlen(str); i++)
	{
		str[i] = toupper(str[i]);
		
		if (str[i] == 'I' || str[i] == ' ')
		{
			centering += 2;
		}
		else if (str[i] == 'M' || str[i] == 'N' || str[i] == 'Q' || str[i] == 'T' || str[i] == 'W' || str[i] == 'X' || str[i] == 'Y')
		{
			centering += 8;
		}
		else if (str[i] == 'V' || str[i] == '0' || (str[i] >= '2' && str[i] <= '9'))
		{
			centering += 6;
		}
		else if (str[i] == '1')
		{
			centering += 4;
		}
		else if (str[i] == '!')
		{
			centering++;
		}
		else
		{
			centering += 7;
		}
	}
	
	for (int i = 0; i < 5; i++)
	{
		hcenter(centering);
		
		for (int j = 4; j > i; j--)
		{
			putchar(' ');
		}
		
		for (int j = 0; j < strlen(str); j++)
		{
			switch(str[j])
			{
				case ' ':
					fputs("  ", stdout);
					break;
					
				case 'A':
					if (i == 0 || i == 2)
					{
						fputs("///////", stdout);
					}
					else
					{
						fputs("//   //", stdout);
					}
					
					break;
					
				case 'B':
					if (i == 1 || i == 3)
					{
						fputs("//   //", stdout);
					}
					else
					{
						fputs("////// ", stdout);
					}
					
					break;
					
				case 'C':
					if (i == 0 || i == 4)
					{
						fputs("///////", stdout);
					}
					else
					{
						fputs("//     ", stdout);
					}
					
					break;
					
				case 'D':
					if (i == 0 || i == 4)
					{
						fputs("////// ", stdout);
					}
					else
					{
						fputs("//   //", stdout);
					}
					
					break;
					
				case 'E':
					if (i == 0 || i == 4)
					{
						fputs("///////", stdout);
					}
					else if (i == 2)
					{
						fputs("/////  ", stdout);
					}
					else
					{
						fputs("//     ", stdout);
					}
					
					break;
					
				case 'F':
					if (i == 0)
					{
						fputs("///////", stdout);
					}
					else if (i == 2)
					{
						fputs("/////  ", stdout);
					}
					else
					{
						fputs("//     ", stdout);
					}
					
					break;
					
				case 'G':
					if (i == 1)
					{
						fputs("//     ", stdout);
					}
					else if (i == 2)
					{
						fputs("// ////", stdout);
					}
					else if (i == 3)
					{
						fputs("//   //", stdout);
					}
					else
					{
						fputs("///////", stdout);
					}
					
					break;
					
				case 'H':
					if (i != 2)
					{
						fputs("//   //", stdout);
					}
					else
					{
						fputs("///////", stdout);
					}
					
					break;
					
				case 'I':
					fputs("//", stdout);
					break;
					
				case 'J':
					if (i < 3)
					{
						fputs("     //", stdout);
					}
					else if (i == 3)
					{
						fputs("//   //", stdout);
					}
					else
					{
						fputs("///////", stdout);
					}
					
					break;
					
				case 'K':
					if (i == 0 || i == 4)
					{
						fputs("//   //", stdout);
					}
					else if (i == 2)
					{
						fputs("///    ", stdout);
					}
					else
					{
						fputs("// //  ", stdout);
					}
					
					break;
					
				case 'L':
					if (i < 4)
					{
						fputs("//     ", stdout);
					}
					else
					{
						fputs("///////", stdout);
					}
					
					break;
					
				case 'M':
					if (i == 1)
					{
						fputs("///  ///", stdout);
					}
					else if (i == 2)
					{
						fputs("// // //", stdout);
					}
					else
					{
						fputs("//    //", stdout);
					}
					
					break;
					
				case 'N':
					if (i == 1)
					{
						fputs("///   //", stdout);
					}
					else if (i == 2)
					{
						fputs("// // //", stdout);
					}
					else if (i == 3)
					{
						fputs("//   ///", stdout);
					}
					else
					{
						fputs("//    //", stdout);
					}
					
					break;
					
				case 'O':
					if (i == 0 || i == 4)
					{
						fputs("///////", stdout);
					}
					else
					{
						fputs("//   //", stdout);
					}
					
					break;
					
				case 'P':
					if (i == 0 || i == 2)
					{
						fputs("///////", stdout);
					}
					else if (i == 1)
					{
						fputs("//   //", stdout);
					}
					else
					{
						fputs("//     ", stdout);
					}
					
					break;
					
				case 'Q':
					if (i == 0)
					{
						fputs("/////// ", stdout);
					}
					else if (i == 3)
					{
						fputs("//  /// ", stdout);
					}
					else if (i == 4)
					{
						fputs("////////", stdout);
					}
					else
					{
						fputs("//   // ", stdout);
					}
					
					break;
					
				case 'R':
					if (i == 0)
					{
						fputs("///////", stdout);
					}
					else if (i == 2)
					{
						fputs("////// ", stdout);
					}
					else
					{
						fputs("//   //", stdout);
					}
					
					break;
					
				case 'S':
					if (i == 1)
					{
						fputs("//     ", stdout);
					}
					else if (i == 3)
					{
						fputs("     //", stdout);
					}
					else
					{
						fputs("///////", stdout);
					}
					
					break;
					
				case 'T':
					if (i != 0)
					{
						fputs("   //   ", stdout);
					}
					else
					{
						fputs("////////", stdout);
					}
					
					break;
					
				case 'U':
					if (i != 4)
					{
						fputs("//   //", stdout);
					}
					else
					{
						fputs("///////", stdout);
					}
					
					break;
					
				case 'V':
					if (i != 4)
					{
						fputs("//  //", stdout);
					}
					else
					{
						fputs("  //  ", stdout);
					}
					
					break;
					
				case 'W':
					if (i == 0)
					{
						fputs("//    //", stdout);
					}
					else if (i == 4)
					{
						fputs(" //  // ", stdout);
					}
					else
					{
						fputs("// // //", stdout);
					}
					
					break;
					
				case 'X':
					if (i == 0 || i == 4)
					{
						fputs("//    //", stdout);
					}
					else if (i == 2)
					{
						fputs("   //   ", stdout);
					}
					else
					{
						fputs(" //  // ", stdout);
					}
					
					break;
					
				case 'Y':
					if (i == 0)
					{
						fputs("//    //", stdout);
					}
					else if (i == 1)
					{
						fputs(" //  // ", stdout);
					}
					else
					{
						fputs("   //   ", stdout);
					}
					
					break;
					
				case 'Z':
					if (i == 1)
					{
						fputs("     //", stdout);
					}
					else if (i == 2)
					{
						fputs("  ///  ", stdout);
					}
					else if (i == 3)
					{
						fputs("//     ", stdout);
					}
					else
					{
						fputs("///////", stdout);
					}
					
					break;
					
				case '1':
					if (i == 0)
					{
						fputs("////", stdout);
					}
					else
					{
						fputs("  //", stdout);
					}
					
					break;
					
				case '2':
					if (i == 0 || i == 4)
					{
						fputs("//////", stdout);
					}
					else if (i == 1)
					{
						fputs("    //", stdout);
					}
					else if (i == 2)
					{
						fputs("  //  ", stdout);
					}
					else
					{
						fputs("//    ", stdout);
					}
					
					break;
					
				case '3':
					if (i == 0 || i == 4)
					{
						fputs("//////", stdout);
					}
					else if (i == 2)
					{
						fputs(" /////", stdout);
					}
					else
					{
						fputs("    //", stdout);
					}
					
					break;
					
				case '4':
					if (i == 0 || i == 1)
					{
						fputs("//  //", stdout);
					}
					else if (i == 2)
					{
						fputs("//////", stdout);
					}
					else
					{
						fputs("    //", stdout);
					}
					
					break;
					
				case '5':
					if (i == 3)
					{
						fputs("    //", stdout);
					}
					else if (i == 1)
					{
						fputs("//    ", stdout);
					}
					else
					{
						fputs("//////", stdout);
					}
					
					break;
					
				case '6':
					if (i == 3)
					{
						fputs("//  //", stdout);
					}
					else if (i == 1)
					{
						fputs("//    ", stdout);
					}
					else
					{
						fputs("//////", stdout);
					}
					
					break;
					
				case '7':
					if (i == 0)
					{
						fputs("//////", stdout);
					}
					else if (i == 1)
					{
						fputs("    //", stdout);
					}
					else if (i == 2)
					{
						fputs("   // ", stdout);
					}
					else if (i == 3)
					{
						fputs("  //  ", stdout);
					}
					else
					{
						fputs(" //   ", stdout);
					}
					
					break;
					
				case '8':
					if (i % 2 == 0)
					{
						fputs("//////", stdout);
					}
					else
					{
						fputs("//  //", stdout);
					}
					
					break;
					
				case '9':
					if (i % 2 == 0)
					{
						fputs("//////", stdout);
					}
					else if (i == 1)
					{
						fputs("//  //", stdout);
					}
					else
					{
						fputs("    //", stdout);
					}
					
					break;
					
				case '0':
					if (i == 0 || i == 4)
					{
						fputs("//////", stdout);
					}
					else
					{
						fputs("//  //", stdout);
					}
					
					break;
					
				case '!':
					if (i == 3)
					{
						fputs("  ", stdout);
					}
					else
					{
						fputs("//", stdout);
					}
					
					break;
					
				default:
					fputs("!ERROR!", stdout);
					break;
			}
			
			if (j < strlen(str) - 1)
			{
				putchar(' ');
			}
		}
		
		putchar('\n');
	}
}

bool operator ==(COORD coord1, COORD coord2)
{
	return coord1.X == coord2.X && coord1.Y == coord2.Y;
}

bool operator !=(COORD coord1, COORD coord2)
{
	return coord1.X != coord2.X || coord1.Y != coord2.Y;
}

bool operator <(COORD coord1, COORD coord2)
{
	return coord1.X < coord2.X && coord1.Y < coord2.Y;
}

bool operator >(COORD coord1, COORD coord2)
{
	return coord1.X > coord2.X && coord1.Y > coord2.Y;
}

bool operator <=(COORD coord1, COORD coord2)
{
	return coord1.X <= coord2.X && coord1.Y <= coord2.Y;
}

bool operator >=(COORD coord1, COORD coord2)
{
	return coord1.X >= coord2.X && coord1.Y >= coord2.Y;
}

#endif
