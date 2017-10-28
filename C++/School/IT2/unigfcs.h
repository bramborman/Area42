/*
	Name: Universal game functions v1.3
	Copyright: (c) 2016 Marian Dolinský
	Author: Marian Dolinský
	Date: 28/03/16 21:41
	Description: Lots of useful functions for creating console games
	
	DEBUG					- enables DEBUG mode
	HIDE_HOTSEAT			- removes hotseat from mainmenu
	HIDE_CUSTOMDIFFICULTY	- removes custom difficulty option
	HIDE_CHANGELOG			- removes changelogs
	BUFFER_NORESIZE			- buffer height 1 greater than window height
*/

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <time.h>

char toupper(const char CHAR)
{
    if(CHAR >= 'a' && CHAR <= 'z')
    {
        return CHAR + ('A' - 'a');
    }
    
    return CHAR;
}

#if !defined HIDE_CHANGELOG && !defined CHANGELOG_COLUMNS
	#error CHANGELOG_COLUMNS not defined
#endif

#ifdef DEBUG
	#warning DEBUG enabled
#endif

#ifndef BUFFER_NORESIZE
	#define BUFFER_ADDITION 1
#else
	#define BUFFER_ADDITION 2
#endif

#define ENTER 13
#define ESC 27
#define SPACE 32

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define IF_ARROW(key) (key == -32 || key == 224)
#define IF_ARROWS(key) (key == UP || key == DOWN || key == LEFT || key == RIGHT)
#define IF_WASD(key) (key == 'W' || key == 'S' || key == 'A' || key == 'D')

#define CURSOR_RESET SetConsoleCursorPosition(OUTPUTBUFFER, ORIGIN)

#ifdef DEBUG
	#define DEBUG_CHEATS \
		printf("\n"); \
		for(int i = 0; i < sizeof(cheats) / sizeof(cheats[0]) - 1; i++) \
		{ \
			printf("cheats[%d]: %d | ", i, cheats[i]); \
		} \
		printf("cheats[%d]: %d", sizeof(cheats) / sizeof(cheats[0]) - 1, cheats[sizeof(cheats) / sizeof(cheats[0]) - 1])
	
	#define DEBUG_KEY(key) \
		printf("key: %c", printarrow(key));
	
	#define DEBUG_MAIN \
		CURSOR_RESET; \
		printf("selection: %d | ", selection); \
		printf("cursorPosition: %*d %*d | ", consoleSizeXPrecision, cursorPosition.X, consoleSizeXPrecision, cursorPosition.Y); \
		DEBUG_KEY(temp); \
		DEBUG_CHEATS
#endif

typedef enum
{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
} COLOR;

typedef enum
{
	EASY,
	MEDIUM,
	HARD,
	CUSTOM
} DIFFICULTY;

typedef enum
{
	RESTART,
	MENU,
	QUIT
} QUITACTION;

typedef enum
{
	FISA,
	HAMSTER
} CHEAT;

typedef struct
{
	char body;
	COLOR color;
} VISUAL;

const char CHEATS[][10] =
{
	{"fisa"},
	{"hamster"}
};
#ifndef HIDE_CHANGELOG
const char CHANGELOG_UNIGFCS[][CHANGELOG_COLUMNS] =
{
	{"1.3:"},
	{"- Added custom difficulty"},
	{"- Added timer"},
	{"- Enabled cursor moving"},
	{"- Added custom console title"},
	{"- Fully removed screen flashing"},
	{"- Lots of code optimalizations"},
	{"- Some bugs were fixed"},
	{"1.2:"},
	{"- Added macros for ENTER, ESC and SPACE"},
	{"- Added unigfcs.h changelog"},
	{"- Improved responsive design"},
	{"- Some bugs were fixed"},
	{"1.1:"},
	{"- Code were optimized"},
	{"- Some bugs were fixed"},
	{"1.0:"},
	{"- First release"},
	{"- Universal game menus"},
	{"- Custom font"}
};
#endif
const char *GAMENAME, *GAMEVERSION, *GAMEBRANCH;
const COORD ORIGIN = {0, 0};
const HANDLE OUTPUTBUFFER = GetStdHandle(STD_OUTPUT_HANDLE);

bool cheats[sizeof(CHEATS) / sizeof(CHEATS[0])] = {false};
int temp;
#ifdef DEBUG
int consoleSizeXPrecision;
#endif
COLOR backgroundColor, foregroundColor;
CONSOLE_SCREEN_BUFFER_INFO consoleBuffer;
// Console sizes are decreased by 1 because of first line (y axis) and body (x axis)
COORD consoleSize, minimalConsoleSize, forcedConsoleSize, commonCursorPosition;

// Applicable for bool-returning functions: returns true to make caller return too
// checkconsolesize() returns true when console size was changed
void initialize(const char *NAME, const char *VERSION, const char *BRANCH, const int MIN_X, const int MIN_Y);
void setconsolesize(const COORD SIZE);
void getconsolesize();
bool checkconsolesize();
void forceconsolesize();
void copybuffer(const HANDLE *DESTINATION, const HANDLE *SOURCE);
void getcurrentcursorposition(COORD *cursorPosition);
void movecursor(const int X, const int Y);
void movecursor(const COORD POSITION);
void setbackground(const COLOR BACKGROUND);
void setforeground(const COLOR FOREGROUND);
void cleaninput();
char getcheat(const char CHAR);
char getarrow(const char KEY);
#ifdef DEBUG
char printarrow(const char DIRECTION);
#endif
void printvisual(const VISUAL VISUAL1);
// WARNING!!! Do not use more than one '\n' at the end of the TEXT string in center functions
// If so every \n will increase string length
void center(const int STRLEN);
void center(const char *TEXT);
void center(const int CUSTOMSTRLEN, const char *TEXT);
void verticalcenter(const int ROWS);
void mainmenu(const COLOR TITLE);
bool difficulty(const bool HOTSEAT);
void wheelselection(COORD cursorPosition, const int SELECTION, const int MIN, const int MAX, const int STEP);
void about();
#ifndef HIDE_CHANGELOG
void changelog(const char CHANGELOG[][CHANGELOG_COLUMNS], const int SIZE);
#endif
bool pausemenu(const bool HOTSEAT);
bool quitmessage(const QUITACTION ACTION, const bool PLAYING, const bool HOTSEAT);
void showscore(const bool WON, const int SCORE, const DIFFICULTY DIFF, const char *GAMEMODE);
void showscore(const bool WON[2], const int SCORE[2], const DIFFICULTY DIFF, const char *GAMEMODE);
void timer();
// WARNING!!! Prints only alphabet, numbers and space
void bigtext(const char *TEXT);
bool operator ==(const COORD COORD1, const COORD COORD2);
bool operator !=(const COORD COORD1, const COORD COORD2);
bool operator <(const COORD COORD1, const COORD COORD2);
bool operator >(const COORD COORD1, const COORD COORD2);
bool operator <=(const COORD COORD1, const COORD COORD2);
bool operator >=(const COORD COORD1, const COORD COORD2);
// These are in each game
void controls();
bool game(const DIFFICULTY DIFFIFULTY1, const bool HOTSEAT);
//void customdifficulty(); - data type depends on game

void initialize(const char *NAME, const char *VERSION, const char *BRANCH, const int MIN_X, const int MIN_Y)
{
	checkconsolesize();
	SetConsoleTitle(NAME);
	
	system("color 0F");
	
	GAMENAME = strdup(NAME);
	GAMEVERSION = strdup(VERSION);
	GAMEBRANCH = strdup(BRANCH);
	
	minimalConsoleSize.X = MIN_X;
	minimalConsoleSize.Y = MIN_Y;
	
	// Hide the cursor
	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 20;
	
#ifndef DEBUG
	cursor.bVisible = false;
	srand(time(NULL));
#else
	cursor.bVisible = true;
#endif

	SetConsoleCursorInfo(OUTPUTBUFFER, &cursor);
	/*
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
	*/
	return;
}

void setconsolesize(const COORD SIZE)
{
	SMALL_RECT windowSize = {0};
	
	// Cannot set greater size than buffer - 1 and buffer size cannot be less than window size
	if(consoleSize.X < SIZE.X || consoleSize.Y < SIZE.Y)
	{
		windowSize.Right = consoleSize.X < SIZE.X ? consoleSize.X : SIZE.X;
		windowSize.Bottom = consoleSize.Y < SIZE.Y ? consoleSize.Y : SIZE.Y;
		
		SetConsoleWindowInfo(OUTPUTBUFFER, true, &windowSize);
	}
	
	COORD bufferSize = {SIZE.X + 1, SIZE.Y + BUFFER_ADDITION};
	SetConsoleScreenBufferSize(OUTPUTBUFFER, bufferSize);
	
	windowSize.Right = SIZE.X;
	windowSize.Bottom = SIZE.Y;
	SetConsoleWindowInfo(OUTPUTBUFFER, true, &windowSize);
	
	getconsolesize();
	return;
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
	
	return;
}

bool checkconsolesize()
{
	COORD lastConsoleSize = consoleSize;
	getconsolesize();
    
    if(!(consoleSize >= minimalConsoleSize))
    {
    	setconsolesize(minimalConsoleSize);
    	
#ifdef DEBUG
	consoleSizeXPrecision = (consoleSize.X < 100 ? 2 : 3);
#endif
		
    	return true;
	}
	
#ifdef DEBUG
	consoleSizeXPrecision = (consoleSize.X < 100 ? 2 : 3);
#endif
	
	return lastConsoleSize != consoleSize;
}

void forceconsolesize()
{
	getconsolesize();
	
	if(consoleSize != forcedConsoleSize)
	{
		setconsolesize(forcedConsoleSize);
	}
	
	return;
}

void copybuffer(const HANDLE *DESTINATION, const HANDLE *SOURCE)
{
	COORD bufferSize = {consoleSize.X + 1, consoleSize.Y + 1};
	CHAR_INFO charInfo[bufferSize.Y][bufferSize.X];
	
	SMALL_RECT region = {0, 0, consoleSize.X, consoleSize.Y};
	
	ReadConsoleOutput(*SOURCE, &charInfo[0][0], bufferSize, ORIGIN, &region);
	WriteConsoleOutput(*DESTINATION, &charInfo[0][0], bufferSize, ORIGIN, &region);
	
	return;
}

void getcurrentcursorposition(COORD *cursorPosition)
{
	GetConsoleScreenBufferInfo(OUTPUTBUFFER, &consoleBuffer);
	*cursorPosition = consoleBuffer.dwCursorPosition;
	
	return;
}

void movecursor(const int X, const int Y)
{
	const COORD POSITION = {X, Y};
	SetConsoleCursorPosition(OUTPUTBUFFER, POSITION);
	
	return;
}

void movecursor(const COORD POSITION)
{
	SetConsoleCursorPosition(OUTPUTBUFFER, POSITION);
	return;
}

void setbackground(const COLOR BACKGROUND)
{
    backgroundColor = BACKGROUND;
    SetConsoleTextAttribute(OUTPUTBUFFER, foregroundColor + (backgroundColor << 4));
    
    return;
}

void setforeground(const COLOR FOREGROUND)
{
    foregroundColor = FOREGROUND;
    SetConsoleTextAttribute(OUTPUTBUFFER, foregroundColor + (backgroundColor << 4));
    
    return;
}

void cleaninput()
{
	while(kbhit())
	{
		getch();
	}
	
	return;
}

char getcheat(const char CHAR)
{
	for(int i = 0; i < sizeof(CHEATS) / sizeof(CHEATS[0]); i++)
	{
		if(!IF_ARROW(CHAR) && (CHAR == CHEATS[i][0] || CHAR == toupper(CHEATS[i][0])))
		{
			for(int j = 1; j < strlen(CHEATS[i]); j++)
			{
				temp = getch();
				
				if(temp != CHEATS[i][j] && temp != toupper(CHEATS[i][j]))
				{
					return 'X';
				}
			}
			
			cheats[i] = !cheats[i];
			return 'X';
		}
	}
	
	return CHAR;
}

char getarrow(const char KEY)
{
	if(IF_ARROW(KEY))
	{
		return getch();
	}
	
	return KEY;
}

#ifdef DEBUG
char printarrow(const char KEY)
{
	switch(KEY)
	{
		case UP:
			return 'U';
			
		case DOWN:
			return 'D';
			
		case LEFT:
			return 'L';
			
		case RIGHT:
			return 'R';
		
		default:
			return 'N';
	}
}
#endif

void printvisual(const VISUAL VISUAL1)
{
	const COLOR FOREGROUNDCOLORBACKUP = foregroundColor;
	
	setforeground(VISUAL1.color);
	putchar(VISUAL1.body);
	setforeground(FOREGROUNDCOLORBACKUP);
	
	return;
}

void center(const int STRLEN)
{
	getcurrentcursorposition(&commonCursorPosition);
	commonCursorPosition.X += (consoleSize.X + 1 - STRLEN) / 2;
	
	movecursor(commonCursorPosition);
	return;
}

void center(const char *TEXT)
{
	getcurrentcursorposition(&commonCursorPosition);
	commonCursorPosition.X += (consoleSize.X + 1 - strlen(TEXT)) / 2;
	
	movecursor(commonCursorPosition);
	fputs(TEXT, stdout);
	
	return;
}

void center(const int CUSTOMSTRLEN, const char *TEXT)
{
	getcurrentcursorposition(&commonCursorPosition);
	commonCursorPosition.X += (consoleSize.X + 1 - CUSTOMSTRLEN) / 2;
	
	movecursor(commonCursorPosition);
	fputs(TEXT, stdout);
	
	return;
}

void verticalcenter(const int ROWS)
{
	getcurrentcursorposition(&commonCursorPosition);
	commonCursorPosition.Y += (consoleSize.Y + 1 - ROWS) / 2;
	movecursor(commonCursorPosition);
	
	return;
}

void mainmenu(const COLOR TITLE)
{
#define CENTERING 10

#ifndef HIDE_HOTSEAT
	#define SELECTION_MAX 4
#else
	#define SELECTION_MAX 3
#endif

	checkconsolesize();
	
	int selection = 0;
	COORD cursorPosition;
	
	while(true)
	{
		system("cls");
		
		verticalcenter(13);
		
		setforeground(TITLE);
		bigtext(GAMENAME);
		setforeground(WHITE);
		
#ifdef DEBUG
	putchar('\n');
	center(-20, "DEBUG MODE\n");
	putchar('\n');
#else
	printf("\n\n\n");
#endif
		
		center(CENTERING, "Start game\n");
		
		cursorPosition = commonCursorPosition;
		cursorPosition.X -= 2;
		
#ifndef HIDE_HOTSEAT
		center(CENTERING, "Hotseat\n");
#endif
		
		center(CENTERING, "Controls\n");
		center(CENTERING, "About\n");
		putchar('\n');
		center(CENTERING, "Quit game");
		
		// Used to reduce screen refresh
		while(true)
		{
			
#ifdef DEBUG
	DEBUG_MAIN;
#endif
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection + (selection == SELECTION_MAX ? 1 : 0));
			putchar('>');
			
			temp = getarrow(getcheat(getch()));
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection + (selection == SELECTION_MAX ? 1 : 0));
			putchar(' ');
			
			if((temp == ENTER && selection == SELECTION_MAX) || temp == ESC)
			{
				quitmessage(QUIT, false, false);
				break;
			}
			else if(temp == ENTER)
			{
				if(selection == 0)
				{
					difficulty(false);
				}
				
#ifndef HIDE_HOTSEAT
	else if(selection == 1)
	{
		difficulty(true);
	}
#endif
				
				else if(selection == SELECTION_MAX - 2)
				{
					controls();
				}
				else
				{
					about();
				}
				
				break;
			}
			else if(temp == UP && selection != 0)
			{
				selection--;
			}
			else if(temp == DOWN && selection != SELECTION_MAX)
			{
				selection++;
			}
			
			if(checkconsolesize())
			{
				break;
			}
		}
	}

#undef CENTERING
#undef SELECTION_MAX
}

bool difficulty(const bool HOTSEAT)
{
#define CENTERING 6

#ifndef HIDE_CUSTOMDIFFICULTY
	#define SELECTION_MAX 4
#else
	#define SELECTION_MAX 3
#endif
	
	checkconsolesize();
	
	int selection = 1;
	COORD cursorPosition;
	
	while(true)
	{
		system("cls");
		
		verticalcenter(7);
		center("CHOOSE DIFFICULTY");
		printf("\n\n");
		
		center(CENTERING, "Easy\n");
		
		cursorPosition = commonCursorPosition;
		cursorPosition.X -= 2;
		
		center(CENTERING, "Medium\n");
		center(CENTERING, "Hard\n");
		putchar('\n');
		
#ifndef HIDE_CUSTOMDIFFICULTY
	center(CENTERING, "Custom\n");
#endif
		
		center(CENTERING, "Back");
		
		// Used to reduce screen refresh
		while(true)
		{
			
#ifdef DEBUG
	DEBUG_MAIN;
#endif
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection + (selection >= 3 ? 1 : 0));
			putchar('>');
			
			temp = getarrow(getcheat(getch()));
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection + (selection >= 3 ? 1 : 0));
			putchar(' ');
			
			if((temp == ENTER && selection == 4) || temp == ESC)
			{
				return false;
			}
			else if(temp == ENTER)
			{
				if(game((DIFFICULTY)selection, HOTSEAT))
				{
					return true;
				}
				
				break;
			}
			else if(temp == UP && selection != 0)
			{
				selection--;
			}
			else if(temp == DOWN && selection != SELECTION_MAX)
			{
				selection++;
			}
			
			if(checkconsolesize())
			{
				break;
			}
		}
	}

#undef CENTERING
#undef SELECTION_MAX
}

void wheelselection(COORD cursorPosition, const int SELECTION, const int MIN, const int MAX, const int STEP)
{
	movecursor(cursorPosition);
	center(19);
	
	setforeground(DARKGRAY);
	printf("%3d ", (SELECTION == MIN + STEP ? MAX : (SELECTION == MIN ? MAX - STEP : SELECTION - (2 * STEP))));
	
	setforeground(LIGHTGRAY);
	printf("%3d ", (SELECTION == MIN ? MAX : SELECTION - STEP));
	
	setforeground(WHITE);
	printf("%3d ", SELECTION);
	
	setforeground(LIGHTGRAY);
	printf("%3d ", (SELECTION == MAX ? MIN : SELECTION + STEP));
	
	setforeground(DARKGRAY);
	printf("%3d", (SELECTION == MAX - STEP ? MIN : (SELECTION == MAX ? MIN + STEP : SELECTION + (2 * STEP))));
	
	setforeground(WHITE);
	
	return;
}

void about()
{
#define CENTERING 24
	
	checkconsolesize();
	
	char *localeBackup = setlocale(LC_ALL, NULL);;
	int selection = 2;
	COORD cursorPosition;
	
	while(true)
	{
		system("cls");

#ifndef HIDE_CHANGELOG
	verticalcenter(11);
#else
	verticalcenter(8);
#endif
		
		center("ABOUT");
		printf("\n\n");
		
		center(CENTERING);
		printf("%s %s\n", GAMENAME, GAMEVERSION);
		center(CENTERING);
		printf("Current branch: %s", GAMEBRANCH);
		
#ifdef DEBUG
	fputs(" (DEBUG)", stdout);
#endif
		
		putchar('\n');
		center(CENTERING, "Created using unigfcs.h v1.3\n");
		center(CENTERING);
    	printf("Current console size: %dx%d\n\n", consoleSize.X + 1, consoleSize.Y + 1);
    	
		setlocale(LC_ALL, "Czech");
		center(CENTERING, "(c) 2016 Marian Dolinský\n\n");
		setlocale(LC_ALL, localeBackup);

#ifndef HIDE_CHANGELOG	
	center(9, "Changelog\n");
	
	cursorPosition = commonCursorPosition;
	cursorPosition.X -= 2;
	
	center(9, "Changelog (unigfcs.h)\n");
	center(9, "Back");
#else
	center("> Back");
#endif
		
		// Used to reduce screen refresh
		while(true)
		{
			
#ifdef DEBUG
	DEBUG_MAIN;
#endif
			
#ifndef HIDE_CHANGELOG
	movecursor(cursorPosition.X, cursorPosition.Y + selection);
	putchar('>');
	
	temp = getarrow(getcheat(getch()));
	
	movecursor(cursorPosition.X, cursorPosition.Y + selection);
	putchar(' ');
	
	if((temp == ENTER && selection == 2) || temp == ESC)
	{
		return;
	}
	else if(temp == ENTER)
	{
		if(selection == 0)
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
	else if(temp == UP && selection != 0)
	{
		selection--;
	}
	else if(temp == DOWN && selection != 2)
	{
		selection++;
	}
#else
	temp = getcheat(getch());
	
	if(temp == ENTER || temp == ESC)
	{
		return;
	}
#endif
			
			if(checkconsolesize())
			{
				break;
			}
		}
	}

#undef CENTERING
}

#ifndef HIDE_CHANGELOG
void changelog(const char CHANGELOG[][CHANGELOG_COLUMNS], const int SIZE)
{
#define CENTERING 37
#define ROWS_MAX 15

	checkconsolesize();
	
	bool consoleSizeChanged;
	int row = 0;
	
	while(true)
	{
		consoleSizeChanged = false;
		system("cls");
		
		verticalcenter(ROWS_MAX + 4);
		center(CHANGELOG == CHANGELOG_GAME ? "CHANGELOG" : "CHANGELOG (UNIGFCS.H)");
		printf("\n\n");
		
		for(int i = 0; i < ROWS_MAX; i++)
		{
			center(CENTERING + (CHANGELOG[row + i][0] != '-' ? 5 : 0));
			puts(CHANGELOG[row + i]);
		}
		
		putchar('\n');
		center("> Back  ");
		
		// Used to reduce screen refresh
		while(true)
		{
			
#ifdef DEBUG
	CURSOR_RESET;
	printf("row: %2d | ", row);
	printf("SIZE: %d | ", SIZE);
	printf("consoleSizeChanged: %d | ", consoleSizeChanged);
	DEBUG_KEY(temp);
	DEBUG_CHEATS;
#endif
			
			temp = getarrow(getcheat(getch()));
			
			// Console size must be checked before cycle is breaked from
			consoleSizeChanged = checkconsolesize();
			
			if(temp == ENTER || temp == ESC)
			{
				return;
			}
			else if(temp == UP && row != 0)
			{
				row--;
				break;
			}
			else if(temp == DOWN && row != SIZE / sizeof(CHANGELOG[0]) - ROWS_MAX)
			{
				row++;
				break;
			}
			
			if(consoleSizeChanged)
			{
				break;
			}
		}
	}

#undef CENTERING
#undef ROWS_MAX
}
#endif

bool pausemenu(const bool HOTSEAT)
{
#define CENTERING 8

	checkconsolesize();
	
	HANDLE gameBoardBuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,  FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	copybuffer(&gameBoardBuffer, &OUTPUTBUFFER);
	
	int selection = 0;
	COORD cursorPosition;
	
	while(true)
	{
		system("cls");
		system("color 0F");
		
		verticalcenter(7);
		center("PAUSE MENU");
		printf("\n\n");
		
		center(CENTERING, "Resume\n");
		
		cursorPosition = commonCursorPosition;
		cursorPosition.X -= 2;
		
		center(CENTERING, "Restart\n");
		center(CENTERING, "Controls\n");
		center(CENTERING, "Go to main menu\n");
		center(CENTERING, "Quit game");
		
		// Used to reduce screen refresh
		while(true)
		{
			
#ifdef DEBUG
	DEBUG_MAIN;
#endif
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection);
			putchar('>');
			
			temp = getarrow(getcheat(getch()));
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection);
			putchar(' ');
			
			if((temp == ENTER && selection == 0) || temp == ESC)
			{
				copybuffer(&OUTPUTBUFFER, &gameBoardBuffer);
				forceconsolesize();
				
				return false;
			}
			else if(temp == ENTER)
			{
				if(selection == 2)
				{
					controls();
				}
				else
				{
					if(quitmessage(selection == 1 ? RESTART : (selection == 3 ? MENU : QUIT), true, HOTSEAT))
					{
						copybuffer(&OUTPUTBUFFER, &gameBoardBuffer);
						return true;
					}
				}
				
				break;
			}
			else if(temp == UP && selection != 0)
			{
				selection--;
			}
			else if(temp == DOWN && selection != 4)
			{
				selection++;
			}
			
			if(checkconsolesize())
			{
				break;
			}
		}
	}

#undef CENTERING
}

bool quitmessage(const QUITACTION ACTION, const bool PLAYING, const bool HOTSEAT)
{
	checkconsolesize();
	
	int selection = 1;
	COORD cursorPosition;
	
	while(true)
	{
		system("cls");
		
		verticalcenter(PLAYING ? 4 : 3);
		center(ACTION == RESTART ? "Are you sure you want to restart the game?" : (ACTION == MENU ?  "Are you sure you want to go to main menu?" : "Are you sure you want to quit the game?"));
		
		if(PLAYING)
		{
			putchar('\n');
			center("Your game progress will be lost!");
		}
		
		printf("\n\n");
		center(18, "Yes");
		
		
		cursorPosition = commonCursorPosition;
		cursorPosition.X += 14;
		
		for(int i = 0; i < 13; i++)
		{
			putchar(' ');
		}
		
		fputs("No", stdout);
		
		// Used to reduce screen refresh
		while(true)
		{
			
#ifdef DEBUG
	DEBUG_MAIN;
#endif
			
			movecursor(cursorPosition.X - (selection == 0 ? 16 : 0), cursorPosition.Y);
			putchar('>');
			
			temp = getarrow(getcheat(getch()));
			
			movecursor(cursorPosition.X - (selection == 0 ? 16 : 0), cursorPosition.Y);
			putchar(' ');
			
			if((temp == ENTER && selection == 1) || temp == ESC)
			{
				return false;
			}
			else if(temp == ENTER)
			{
				if(ACTION == RESTART)
				{
					return difficulty(HOTSEAT);
				}
				else if(ACTION == MENU)
				{
					return true;
				}
				else
				{
					system("cls");
					exit(0);
				}
			}
			else if(temp == LEFT && selection != 0)
			{
				selection--;
			}
			else if(temp == RIGHT && selection != 1)
			{
				selection++;
			}
			
			if(checkconsolesize())
			{
				break;
			}
		}
	}
}

void showscore(const bool WON, const int SCORE, const DIFFICULTY DIFF, const char *GAMEMODE)
{
#define CENTERING 7

	checkconsolesize();
	
	int selection = 1;
	COORD cursorPosition;
		
	while(true)
	{
		system("cls");
		system("color 0F");
		
		verticalcenter(14);
		
		if(WON)
		{
			setforeground(LIGHTGREEN);
			bigtext("YOU WON");
		}
		else
		{
			setforeground(LIGHTRED);
			bigtext("GAME OVER");
		}
		
		setforeground(WHITE);
		printf("\n\n\n");
		
		center(14);
		printf("Your score: %d\n\n", SCORE);
		
		center(18);
		printf("Difficulty: %s\n", DIFF == EASY ? "Easy" : (DIFF == MEDIUM ? "Medium" : (DIFF == HARD ? "Hard" : "Custom")));
		
		center(18);
		printf("Game mode: %s\n\n", GAMEMODE);
		
		center(CENTERING, "Restart\n");
		
		cursorPosition = commonCursorPosition;
		cursorPosition.X -= 2;
		
		center(CENTERING, "Back");
		
		// Used to reduce screen refresh
		while(true)
		{
			
#ifdef DEBUG
	DEBUG_MAIN;
#endif
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection);
			putchar('>');
			
			temp = getarrow(getcheat(getch()));
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection);
			putchar(' ');
			
			if((temp == ENTER && selection == 1) || temp == ESC)
			{
				return;
			}
			else if(temp == ENTER)
			{
				difficulty(false);
				return;
			}
			else if(temp == UP && selection != 0)
			{
				selection--;
			}
			else if(temp == DOWN && selection != 1)
			{
				selection++;
			}
			
			if(checkconsolesize())
			{
				break;
			}
		}
	}

#undef CENTERING
}

void showscore(const bool WON[2], const int SCORE[2], const DIFFICULTY DIFF, const char *GAMEMODE)
{
#define CENTERING 7

	checkconsolesize();
	
	int selection = 1;
	COORD cursorPosition;
		
	while(true)
	{
		system("cls");
		system("color 0F");
		
		verticalcenter(15);
		
		if(WON[0] || WON[1])
		{
			setforeground(LIGHTGREEN);
			bigtext("YOU WON");
		}
		else
		{
			setforeground(LIGHTRED);
			bigtext("GAME OVER");
		}
		
		setforeground(WHITE);
		printf("\n\n\n");
		
		center(27);
		printf(WON[0] ? "Player 1 won with score %d\n" : "Player 1 died with score %d\n", SCORE[0]);
		
		center(27);
		printf(WON[1] ? "Player 2 won with score %d\n" : "Player 2 died with score %d\n\n", SCORE[1]);
		
		center(18);
		printf("Difficulty: %s\n", DIFF == EASY ? "Easy" : (DIFF == MEDIUM ? "Medium" : (DIFF == HARD ? "Hard" : "Custom")));
		
		center(18);
		printf("Game mode: %s\n\n", GAMEMODE);
		
		center(CENTERING, "Restart\n");
		
		cursorPosition = commonCursorPosition;
		cursorPosition.X -= 2;
		
		center(CENTERING, "Back");
	
		// Used to reduce screen refresh
		while(true)
		{
			
#ifdef DEBUG
	DEBUG_MAIN;
#endif
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection);
			putchar('>');
			
			temp = getarrow(getcheat(getch()));
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection);
			putchar(' ');
			
			if((temp == ENTER && selection == 1) || temp == ESC)
			{
				return;
			}
			else if(temp == ENTER)
			{
				difficulty(true);
				return;
			}
			else if(temp == UP && selection != 0)
			{
				selection--;
			}
			else if(temp == DOWN && selection != 1)
			{
				selection++;
			}
			
			if(checkconsolesize())
			{
				break;
			}
		}
	}

#undef CENTERING
}

void timer()
{
#define SLEEP 1100
	system("cls");
	
	verticalcenter(5);
	bigtext("3");
	Sleep(SLEEP);
	system("cls");
	
	verticalcenter(5);
	bigtext("2");
	Sleep(SLEEP);
	system("cls");
	
	verticalcenter(5);
	bigtext("1");
	Sleep(SLEEP);
	system("cls");
	
	verticalcenter(5);
	bigtext("GO!");
	Sleep(SLEEP);
	
	cleaninput();
	
#undef SLEEP
}

void bigtext(const char *TEXT)
{
	// centering assigned to 4 because of four spaces on right and left side
	// strlen(TEXT) - 1 = count of spaces between each letters
	// int centering = 4 + strlen(TEXT) - 1;
	int centering = 3 + strlen(TEXT);
	char text[strlen(TEXT)];
	
	strcpy(text, TEXT);
	
	// Rewrite text as upper case and set centering
	for(int i = 0; i < strlen(text); i++)
	{
		text[i] = toupper(text[i]);
		
		if(text[i] == 'I' || text[i] == ' ')
		{
			centering += 2;
		}
		else if(text[i] == 'M' || text[i] == 'N' || text[i] == 'Q' || text[i] == 'T' || text[i] == 'W' || text[i] == 'X' || text[i] == 'Y')
		{
			centering += 8;
		}
		else if(text[i] == 'V' || text[i] == '0' || (text[i] >= '2' && text[i] <= '9'))
		{
			centering += 6;
		}
		else if(text[i] == '1')
		{
			centering += 4;
		}
		else if(text[i] == '!')
		{
			centering++;
		}
		else
		{
			centering += 7;
		}
	}
	
	for(int i = 0; i < 5; i++)
	{
		center(centering);
		
		for(int j = 4; j > i; j--)
		{
			putchar(' ');
		}
		
		for(int j = 0; j < strlen(text); j++)
		{
			switch(text[j])
			{
				case ' ':
					fputs("  ", stdout);
					break;
					
				case 'A':
					if(i == 0 || i == 2)
					{
						fputs("///////", stdout);
					}
					else
					{
						fputs("//   //", stdout);
					}
					
					break;
					
				case 'B':
					if(i == 1 || i == 3)
					{
						fputs("//   //", stdout);
					}
					else
					{
						fputs("////// ", stdout);
					}
					
					break;
					
				case 'C':
					if(i == 0 || i == 4)
					{
						fputs("///////", stdout);
					}
					else
					{
						fputs("//     ", stdout);
					}
					
					break;
					
				case 'D':
					if(i == 0 || i == 4)
					{
						fputs("////// ", stdout);
					}
					else
					{
						fputs("//   //", stdout);
					}
					
					break;
					
				case 'E':
					if(i == 0 || i == 4)
					{
						fputs("///////", stdout);
					}
					else if(i == 2)
					{
						fputs("/////  ", stdout);
					}
					else
					{
						fputs("//     ", stdout);
					}
					
					break;
					
				case 'F':
					if(i == 0)
					{
						fputs("///////", stdout);
					}
					else if(i == 2)
					{
						fputs("/////  ", stdout);
					}
					else
					{
						fputs("//     ", stdout);
					}
					
					break;
					
				case 'G':
					if(i == 1)
					{
						fputs("//     ", stdout);
					}
					else if(i == 2)
					{
						fputs("// ////", stdout);
					}
					else if(i == 3)
					{
						fputs("//   //", stdout);
					}
					else
					{
						fputs("///////", stdout);
					}
					
					break;
					
				case 'H':
					if(i != 2)
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
					if(i < 3)
					{
						fputs("     //", stdout);
					}
					else if(i == 3)
					{
						fputs("//   //", stdout);
					}
					else
					{
						fputs("///////", stdout);
					}
					
					break;
					
				case 'K':
					if(i == 0 || i == 4)
					{
						fputs("//   //", stdout);
					}
					else if(i == 2)
					{
						fputs("///    ", stdout);
					}
					else
					{
						fputs("// //  ", stdout);
					}
					
					break;
					
				case 'L':
					if(i < 4)
					{
						fputs("//     ", stdout);
					}
					else
					{
						fputs("///////", stdout);
					}
					
					break;
					
				case 'M':
					if(i == 1)
					{
						fputs("///  ///", stdout);
					}
					else if(i == 2)
					{
						fputs("// // //", stdout);
					}
					else
					{
						fputs("//    //", stdout);
					}
					
					break;
					
				case 'N':
					if(i == 1)
					{
						fputs("///   //", stdout);
					}
					else if(i == 2)
					{
						fputs("// // //", stdout);
					}
					else if(i == 3)
					{
						fputs("//   ///", stdout);
					}
					else
					{
						fputs("//    //", stdout);
					}
					
					break;
					
				case 'O':
					if(i == 0 || i == 4)
					{
						fputs("///////", stdout);
					}
					else
					{
						fputs("//   //", stdout);
					}
					
					break;
					
				case 'P':
					if(i == 0 || i == 2)
					{
						fputs("///////", stdout);
					}
					else if(i == 1)
					{
						fputs("//   //", stdout);
					}
					else
					{
						fputs("//     ", stdout);
					}
					
					break;
					
				case 'Q':
					if(i == 0)
					{
						fputs("/////// ", stdout);
					}
					else if(i == 3)
					{
						fputs("//  /// ", stdout);
					}
					else if(i == 4)
					{
						fputs("////////", stdout);
					}
					else
					{
						fputs("//   // ", stdout);
					}
					
					break;
					
				case 'R':
					if(i == 0)
					{
						fputs("///////", stdout);
					}
					else if(i == 2)
					{
						fputs("////// ", stdout);
					}
					else
					{
						fputs("//   //", stdout);
					}
					
					break;
					
				case 'S':
					if(i == 1)
					{
						fputs("//     ", stdout);
					}
					else if(i == 3)
					{
						fputs("     //", stdout);
					}
					else
					{
						fputs("///////", stdout);
					}
					
					break;
					
				case 'T':
					if(i != 0)
					{
						fputs("   //   ", stdout);
					}
					else
					{
						fputs("////////", stdout);
					}
					
					break;
					
				case 'U':
					if(i != 4)
					{
						fputs("//   //", stdout);
					}
					else
					{
						fputs("///////", stdout);
					}
					
					break;
					
				case 'V':
					if(i != 4)
					{
						fputs("//  //", stdout);
					}
					else
					{
						fputs("  //  ", stdout);
					}
					
					break;
					
				case 'W':
					if(i == 0)
					{
						fputs("//    //", stdout);
					}
					else if(i == 4)
					{
						fputs(" //  // ", stdout);
					}
					else
					{
						fputs("// // //", stdout);
					}
					
					break;
					
				case 'X':
					if(i == 0 || i == 4)
					{
						fputs("//    //", stdout);
					}
					else if(i == 2)
					{
						fputs("   //   ", stdout);
					}
					else
					{
						fputs(" //  // ", stdout);
					}
					
					break;
					
				case 'Y':
					if(i == 0)
					{
						fputs("//    //", stdout);
					}
					else if(i == 1)
					{
						fputs(" //  // ", stdout);
					}
					else
					{
						fputs("   //   ", stdout);
					}
					
					break;
					
				case 'Z':
					if(i == 1)
					{
						fputs("     //", stdout);
					}
					else if(i == 2)
					{
						fputs("  ///  ", stdout);
					}
					else if(i == 3)
					{
						fputs("//     ", stdout);
					}
					else
					{
						fputs("///////", stdout);
					}
					
					break;
					
				case '1':
					if(i == 0)
					{
						fputs("////", stdout);
					}
					else
					{
						fputs("  //", stdout);
					}
					
					break;
					
				case '2':
					if(i == 0 || i == 4)
					{
						fputs("//////", stdout);
					}
					else if(i == 1)
					{
						fputs("    //", stdout);
					}
					else if(i == 2)
					{
						fputs("  //  ", stdout);
					}
					else
					{
						fputs("//    ", stdout);
					}
					
					break;
					
				case '3':
					if(i == 0 || i == 4)
					{
						fputs("//////", stdout);
					}
					else if(i == 2)
					{
						fputs(" /////", stdout);
					}
					else
					{
						fputs("    //", stdout);
					}
					
					break;
					
				case '4':
					if(i == 0 || i == 1)
					{
						fputs("//  //", stdout);
					}
					else if(i == 2)
					{
						fputs("//////", stdout);
					}
					else
					{
						fputs("    //", stdout);
					}
					
					break;
					
				case '5':
					if(i == 3)
					{
						fputs("    //", stdout);
					}
					else if(i == 1)
					{
						fputs("//    ", stdout);
					}
					else
					{
						fputs("//////", stdout);
					}
					
					break;
					
				case '6':
					if(i == 3)
					{
						fputs("//  //", stdout);
					}
					else if(i == 1)
					{
						fputs("//    ", stdout);
					}
					else
					{
						fputs("//////", stdout);
					}
					
					break;
					
				case '7':
					if(i == 0)
					{
						fputs("//////", stdout);
					}
					else if(i == 1)
					{
						fputs("    //", stdout);
					}
					else if(i == 2)
					{
						fputs("   // ", stdout);
					}
					else if(i == 3)
					{
						fputs("  //  ", stdout);
					}
					else
					{
						fputs(" //   ", stdout);
					}
					
					break;
					
				case '8':
					if(i % 2 == 0)
					{
						fputs("//////", stdout);
					}
					else
					{
						fputs("//  //", stdout);
					}
					
					break;
					
				case '9':
					if(i % 2 == 0)
					{
						fputs("//////", stdout);
					}
					else if(i == 1)
					{
						fputs("//  //", stdout);
					}
					else
					{
						fputs("    //", stdout);
					}
					
					break;
					
				case '0':
					if(i == 0 || i == 4)
					{
						fputs("//////", stdout);
					}
					else
					{
						fputs("//  //", stdout);
					}
					
					break;
					
				case '!':
					if(i == 3)
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
			
			if(j < strlen(text) - 1)
			{
				putchar(' ');
			}
		}
		
		putchar('\n');
	}
}

bool operator ==(const COORD COORD1, const COORD COORD2)
{
	if(COORD1.X == COORD2.X && COORD1.Y == COORD2.Y)
	{
		return true;
	}
	
	return false;
}

bool operator !=(const COORD COORD1, const COORD COORD2)
{
	if(COORD1.X != COORD2.X || COORD1.Y != COORD2.Y)
	{
		return true;
	}
	
	return false;
}

bool operator <(const COORD COORD1, const COORD COORD2)
{
	if(COORD1.X < COORD2.X && COORD1.Y < COORD2.Y)
	{
		return true;
	}
	
	return false;
}

bool operator >(const COORD COORD1, const COORD COORD2)
{
	if(COORD1.X > COORD2.X && COORD1.Y > COORD2.Y)
	{
		return true;
	}
	
	return false;
}

bool operator <=(const COORD COORD1, const COORD COORD2)
{
	if(COORD1.X <= COORD2.X && COORD1.Y <= COORD2.Y)
	{
		return true;
	}
	
	return false;
}

bool operator >=(const COORD COORD1, const COORD COORD2)
{
	if(COORD1.X >= COORD2.X && COORD1.Y >= COORD2.Y)
	{
		return true;
	}
	
	return false;
}
