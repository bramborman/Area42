/*
	Name: unigfcs.h (Universal game functions) v1.4
	Copyright: (c) 2016 Marian Dolinský
	Author: Marian Dolinský
	Date: 10/07/16 14:50
	Description: Lots of useful functions for creating games in Windows console.
	
	DEBUG						- enables DEBUG mode
	DISABLE_HOTSEAT				- disables hotseat from mainmenu
	DISABLE_DIFFICULTY			- disables difficulty menu
	DISABLE_CUSTOMDIFFICULTY	- disables custom difficulty option
	DISABLE_CHANGELOG			- disables changelogs
	DISABLE_CHEATS				- disables all cheats and functions used with cheats
	DISABLE_BUFFERASWINDOW		- buffer height will be only by 1 greater than window height
*/

#ifndef UNIGFCS_H
#define UNIGFCS_H

#include "..\Project Superior CFC\superior.hpp"
#include <time.h>
#include <math.h>

#ifdef DEBUG
	#warning DEBUG enabled
#endif

#define IF_ARROW(KEY) (KEY == Up || KEY == Down || KEY == Left || KEY == Right)
#define IF_WASD(KEY) (KEY == 'W' || KEY == 'S' || KEY == 'A' || KEY == 'D')

// Using macros so don't have to pass so much arguments
#ifdef DEBUG
	#define DEBUG_CHEATS \
		printf("\n"); \
		for (int i = 0; i < sizeof(cheats) / sizeof(cheats[0]) - 1; i++) \
		{ \
			printf("cheats[%d]: %d | ", i, cheats[i]); \
		} \
		printf("cheats[%d]: %d", sizeof(cheats) / sizeof(cheats[0]) - 1, cheats[sizeof(cheats) / sizeof(cheats[0]) - 1])
	
	#define DEBUG_KEY(KEY) \
		printf("key: %c", printarrow(KEY))
	
	// Cannot use #ifdef etc in MACROs
	#ifndef DISABLE_CHEATS
		#define DEBUG_MAIN \
			movecursor(COORD_ORIGIN); \
			printf("selection: %d | ", selection); \
			printf("cursorPosition: %*d %*d | ", consoleSizeXPrecision, cursorPosition.X, consoleSizeXPrecision, cursorPosition.Y); \
			printf("consoleSizeChanged: %d | ", consoleSizeChanged); \
			DEBUG_KEY(key); \
			DEBUG_CHEATS
	#else
		#define DEBUG_MAIN \
			movecursor(COORD_ORIGIN); \
			printf("selection: %d | ", selection); \
			printf("cursorPosition: %*d %*d | ", consoleSizeXPrecision, cursorPosition.X, consoleSizeXPrecision, cursorPosition.Y); \
			printf("consoleSizeChanged: %d | ", consoleSizeChanged); \
			DEBUG_KEY(key)
	#endif
#endif

typedef enum
{
	Easy,
	Medium,
	Hard,
	Custom,
	NoDifficulty
} DIFFICULTY;

typedef enum
{
	Restart,
	Menu,
	Quit
} QUITACTION;

const char *gameName, *gameVersion, *gameBranch;
#ifndef DISABLE_CHANGELOG
const char *CHANGELOG_UNIGFCS[] =
{
	"1.4:                        (5/30/2016)",
	"- Using Project Superior CFC v1.0 beta 1",
	"1.3:                        (5/29/2016)",
	"- Real time responsivity",
	"- Added custom difficulty",
	"- Added timer",
	"- Added cheats support",
	"- Added ability to move cursor",
	"- Added custom console title",
	"- Fully removed screen flashing",
	"- Lots of improvements",
	"- Lots of code optimalizations",
	"- Lots of new features",
	"- Some bugs were fixed",
	"1.2:                        (12/18/2015)",
	"- Added macros for ENTER, ESC and SPACE",
	"- Added unigfcs.h changelog",
	"- Improved responsive design",
	"- Some bugs were fixed",
	"1.1:",
	"- Code were optimized",
	"- Some bugs were fixed",
	"1.0:                        (11/24/2015)",
	"- First release",
	"- Universal game menus",
	"- Custom font"
};
#endif
#ifndef DISABLE_BUFFERASWINDOW
const int BUFFER_ADDITION = 1;
#else
const int BUFFER_ADDITION = 2;
#endif
const int MENU_SLEEP = 15;
const UINT CP_OEM = 437;

#ifndef DISABLE_CHEATS
bool cheatActivated, showCheatPrompt, consoleSizeChangedCheatPrompt;
#endif
bool consoleSizeChanged;
bool cheats[sizeof(CHEATS) / sizeof(CHEATS[0])];
#ifdef DEBUG
int consoleSizeXPrecision;
#endif
// Console sizes are decreased by 1 so it can be compared with COORDs
COORD consoleSize, minimalConsoleSize, forcedConsoleSize;
HANDLE sizecheckthreadHandle = NULL;
#ifndef DISABLE_CHEATS
HANDLE cheatpromptthreadHandle = NULL;
#endif

// Applicable for bool-returning functions: returns true to make caller return too
void initialize(const char *name, const char *version, const char *branch, int minimalConsoleWidth, int minimalConsoleHeight);
DWORD WINAPI consolesizecheckthread(LPVOID lpvoid);
#ifndef DISABLE_CHEATS
DWORD WINAPI cheatpromptthread(LPVOID lpvoid);
#endif
void setconsolesize(COORD size);
// Returns true if consoleSize was changed
bool assignconsolesize();
void forceconsolesize();
void copybuffer(const HANDLE *dest, const HANDLE *source);
void setforeground(COLOR foreground);
void setbackground(COLOR background);
char getcheat(char key);
#ifdef DEBUG
char printarrow(char arrow);
#endif
void mainmenu(COLOR titleColor);
bool difficultyselection(bool hotseat);
void wheelselection(COORD position, int selected, int min, int max, int step);
void about();
#ifndef DISABLE_CHANGELOG
void changelog(const char *changelog[], int size);
#endif
bool pausemenu(bool hotseat);
bool quitdialog(QUITACTION action, bool playing, bool hotseat);
void showscore(bool won, int score, DIFFICULTY difficulty, const char *gameMode);
void showscore(bool won[2], int score[2], DIFFICULTY difficulty, const char *gameMode);
void timer(bool isColored);
// WARNING!!! Prints only alphabet, numbers and space
void bigtext(const char *text);
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
	
	// Assign variables
#ifndef DISABLE_CHEATS
	consoleSizeChangedCheatPrompt = true;
#endif
	consoleSizeChanged = true;
	memset(cheats, false, sizeof(cheats));
	
	assignconsolesize();
	sizecheckthreadHandle = CreateThread(NULL, 0, consolesizecheckthread, NULL, 0, NULL);
	
	// Set Lucida Console font
	CONSOLE_FONT_INFOEX font;
	
    font.cbSize = sizeof(font);
    font.nFont = 7;
    font.dwFontSize.X = 12;
    font.dwFontSize.Y = 16;
    font.FontFamily = FF_DONTCARE;
    font.FontWeight = FW_NORMAL;
    wcscpy(font.FaceName, L"Lucida Console");
    
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, &font);
	
	// Use OEM Code Page
	SetConsoleOutputCP(CP_OEM);
	SetConsoleTitle(name);
	
	setforeground(White);
	setbackground(Black);
}

DWORD WINAPI consolesizecheckthread(LPVOID lpvoid)
{
	while (true)
	{
		if (!consoleSizeChanged)
		{
			consoleSizeChanged = assignconsolesize();
			consoleSizeChangedCheatPrompt = consoleSizeChanged;
			
			if (consoleSizeChanged)
			{
				if (consoleSize < minimalConsoleSize)
			    {
			    	consoleSize = minimalConsoleSize;
					setconsolesize(consoleSize);
				}
				else if (consoleSize.X < minimalConsoleSize.X)
				{
					consoleSize.X = minimalConsoleSize.X;
					setconsolesize(consoleSize);
				}
				else if (consoleSize.Y < minimalConsoleSize.Y)
				{
					consoleSize.Y = minimalConsoleSize.Y;
					setconsolesize(consoleSize);
				}
			}
		}
		
		Sleep(50);
	}
	
	return EXIT_FAILURE;
}

#ifndef DISABLE_CHEATS
DWORD WINAPI cheatpromptthread(LPVOID lpvoid)
{
	char *message = NULL;
	int timer, length = 0;
	DWORD attribsWritten, charsWritten;
	COLOR foregroundBackup, backgroundBackup;
	
	while (true)
	{
		if (showCheatPrompt || consoleSizeChangedCheatPrompt)
		{
			showCheatPrompt = false;
			consoleSizeChangedCheatPrompt = false;
			timer = 0;
			
			FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backgroundColor + (backgroundColor << 4), length, COORD_ORIGIN, &attribsWritten);
			message = strdup(cheatActivated ? " Cheat activated " : " Cheat deactivated ");
			length = strlen(message);
			
			// Print message
			foregroundBackup = foregroundColor;
			backgroundBackup = backgroundColor;
			
			setforeground(Black);
			setbackground(Gray);
			
			movecursor(COORD_ORIGIN);
			fputs(message, stdout);
			
			setforeground(foregroundBackup);
			setbackground(backgroundBackup);
			
			//	char *strdup(const char *src)
			//	{
			//		char *output = (char *)malloc(strlen(src) + 1);
			//		
			//		if (output == NULL)
			//		{
			//			return NULL;
			//		}
			//		
			//		strcpy(output, src);
			//		return output;
			//	}
			//
			// ^ this is how strdup works
			// So the string returned from strdup is dynamically allocated and should be freed
			// If not it'll be allocated 'till program closes and another apps couldn't use it
			free(message);
		}
		
		Sleep(200);
		timer += 200;
		
		if (timer == 2000)
		{
			FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backgroundColor + (backgroundColor << 4), length, COORD_ORIGIN, &attribsWritten);
			SuspendThread(cheatpromptthreadHandle);
		}
	}
	
	return EXIT_FAILURE;
}
#endif

void setconsolesize(COORD size)
{
	SMALL_RECT windowSize = { 0 };
	
	// Cannot set greater size than (buffer - 1) and buffer size cannot be less than window size
	if (consoleSize.X < size.X || consoleSize.Y < size.Y)
	{
		windowSize.Right = consoleSize.X < size.X ? consoleSize.X : size.X;
		windowSize.Bottom = consoleSize.Y < size.Y ? consoleSize.Y : size.Y;
		
		SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &windowSize);
	}
	
	COORD bufferSize = { size.X + 1, size.Y + BUFFER_ADDITION };
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);
	
	windowSize.Right = size.X;
	windowSize.Bottom = size.Y;
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &windowSize);
	
	assignconsolesize();
	consoleSizeChanged = true;
}

bool assignconsolesize()
{
	COORD temp;
	CONSOLE_SCREEN_BUFFER_INFO stdOutInfo;
	
	// Get console sizes and assign consoleSize
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &stdOutInfo);
    
    temp.X = stdOutInfo.srWindow.Right - stdOutInfo.srWindow.Left + 1;
	temp.Y = stdOutInfo.srWindow.Bottom - stdOutInfo.srWindow.Top + BUFFER_ADDITION;
	
	// Do not write in consoleSize if console window size does not really changed
	if (temp.X - 1 != consoleSize.X || temp.Y - BUFFER_ADDITION != consoleSize.Y)
	{
		SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), temp);
		
		consoleSize.X = temp.X - 1;
		consoleSize.Y = temp.Y - BUFFER_ADDITION;
	    
#ifdef DEBUG
		consoleSizeXPrecision = (int)floor(log10(consoleSize.X)) + 1;
#endif
		
		return true;
	}
	
	return false;
}

void forceconsolesize()
{
	assignconsolesize();
	
	if (consoleSize != forcedConsoleSize)
	{
		setconsolesize(forcedConsoleSize);
	}
}

void copybuffer(const HANDLE *dest, const HANDLE *source)
{
	COORD bufferSize = { consoleSize.X + 1, consoleSize.Y + 1 };
	CHAR_INFO charInfo[bufferSize.Y][bufferSize.X];
	SMALL_RECT region = { 0, 0, consoleSize.X, consoleSize.Y };
	
	ReadConsoleOutput(*source, charInfo[0], bufferSize, COORD_ORIGIN, &region);
	WriteConsoleOutput(*dest, charInfo[0], bufferSize, COORD_ORIGIN, &region);
}

char getcheat(char key)
{
#ifndef DISABLE_CHEATS
	if (key == -32 || key == 224)
	{
		return key;
	}
	
	for (int i = 0; i < sizeof(CHEATS) / sizeof(CHEATS[0]); i++)
	{
		// Compare key with first letter on every line
		if (key == CHEATS[i][0] || key == toupper(CHEATS[i][0]))
		{
			// If key equals first letter continue reading keys for cheat
			for (int j = 1; j < strlen(CHEATS[i]); j++)
			{
				key = getch();
				
				if (key != CHEATS[i][j] && key != toupper(CHEATS[i][j]))
				{
					return key;
				}
			}
			
			cheats[i] = !cheats[i];
			
#ifndef DEBUG
			showCheatPrompt = true;
			cheatActivated = cheats[i];
			
			if (cheatpromptthreadHandle == NULL)
			{
				cheatpromptthreadHandle = CreateThread(NULL, 0, cheatpromptthread, NULL, 0, NULL);
			}
			else
			{
				ResumeThread(cheatpromptthreadHandle);
			}
#endif
			
			return key;
		}
	}
#endif //DISABLE_CHEATS
	
	return key;
}

#ifdef DEBUG
char printarrow(char arrow)
{
	switch(arrow)
	{
		case Up:	return 'U';
		case Down:	return 'D';
		case Left:	return 'L';
		case Right:	return 'R';
		default:	return 'N';
	}
}
#endif

void mainmenu(COLOR titleColor)
{
#ifndef DISABLE_HOTSEAT
	const int SELECTION_MAX = 4;
#else
	const int SELECTION_MAX = 3;
#endif
	
	const int CENTERING = 10;
	
	bool renderMain = true, renderSelection = true;
	char key;
	int selection = 0;
	COORD cursorPosition;
	
	while (true)
	{
		if (consoleSizeChanged || renderMain)
		{
			cls();
			
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
			
			cursorPosition = hcenter(CENTERING, "Start game\n");
			cursorPosition.X -= 2;
			
#ifndef DISABLE_HOTSEAT
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
			key = getkey(getcheat(getch()));
			
			if ((key == Enter && selection == SELECTION_MAX) || key == Esc)
			{
				quitdialog(Quit, false, false);
				renderMain = true;
			}
			else if (key == Enter)
			{
				if (selection == 0)
				{
					difficultyselection(false);
				}
#ifndef DISABLE_HOTSEAT
				else if (selection == 1)
				{
					difficultyselection(true);
				}
#endif
				
				else if (selection == SELECTION_MAX - 2)
				{
					controls();
				}
				else //if (selection == SELECTION_MAX - 1)
				{
					about();
				}
				
				renderMain = true;
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
#ifdef DISABLE_DIFFICULTY
	game(NoDifficulty, hotseat);
#else
	
#ifndef DISABLE_CUSTOMDIFFICULTY
	const int SELECTION_MAX = 4;
#else
	const int SELECTION_MAX = 3;
#endif
	
	const int CENTERING = 6;
	
	bool renderMain = true, renderSelection = true;
	char key;
	int selection = 1;
	COORD cursorPosition;
	
	while (true)
	{
		if (consoleSizeChanged || renderMain)
		{
			cls();
		
			vcenter(7);
			hcenter("CHOOSE DIFFICULTY");
			fputs("\n\n", stdout);
			
			cursorPosition = hcenter(CENTERING, "Easy\n");
			cursorPosition.X -= 2;
			
			hcenter(CENTERING, "Medium\n");
			hcenter(CENTERING, "Hard\n");
			putchar('\n');
			
#ifndef DISABLE_CUSTOMDIFFICULTY
			hcenter(CENTERING, "Custom\n");
#endif
			
			hcenter(CENTERING, "Back");
			
			consoleSizeChanged = false;
			renderMain = false;
			renderSelection = true;
		}
		
#ifdef DEBUG
		DEBUG_MAIN;
#endif
		
		if (renderSelection)
		{
			for (int i = (selection == 3 ? -2 : -1); i <= (selection == 2 ? 2 : 1); i++)
			{
				movecursor(cursorPosition.X, cursorPosition.Y + selection + (selection >= 3 ? 1 : 0) + i);
				putchar(' ');
			}
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection + (selection >= 3 ? 1 : 0));
			putchar('>');
			
			renderSelection = false;
		}
		
		if (kbhit())
		{
			key = getkey(getcheat(getch()));
			
			if ((key == Enter && selection == SELECTION_MAX) || key == Esc)
			{
				return false;
			}
			else if (key == Enter)
			{
				if (game((DIFFICULTY)selection, hotseat))
				{
					return true;
				}
				
				renderMain = true;
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
#endif
}

void wheelselection(COORD position, int selected, int min, int max, int step)
{
	int temp;
	COLOR foregroundBackup = foregroundColor;
	
	movecursor(position);
	hcenter(19);
	
	for (int i = -2; i <= 2; i++)
	{
		setforeground(i == 0 ? White : (i == -1 || i == 1 ? Gray : DarkGray));
		
		temp = selected + (i * step);
		printf("%3d ", (temp >= min && temp <= max ? temp : (temp < min ? max - (min - temp) + step : min + (temp - max) - step)));
	}
	
	setforeground(foregroundBackup);
}

void about()
{
	const int CENTERING = 24;
	
	bool renderMain = true, renderSelection = true;
	bool printGameBranch = gameBranch != NULL && strcmp(gameBranch, "");
	char key;
	int selection = 2;
	COORD cursorPosition;
	
	while (true)
	{
		if (consoleSizeChanged || renderMain)
		{
			cls();
	
#ifndef DISABLE_CHANGELOG
			vcenter(10 + (printGameBranch ? 1 : 0));
#else
			vcenter(7 + (printGameBranch ? 1 : 0));
#endif
			
			hcenter("ABOUT");
			fputs("\n\n", stdout);
			
			hcenter(CENTERING, "%s %s\n", gameName, gameVersion);
			
#ifndef DEBUG
			if (printGameBranch)
			{
#endif
				hcenter(CENTERING, "Current branch: %s", gameBranch);
#ifndef DEBUG
			}
#endif
			
#ifdef DEBUG
			printf("%s(DEBUG)", (printGameBranch ? " " : ""));
#endif
			
			putchar('\n');
			hcenter(CENTERING, "Using unigfcs.h v1.4\n");
			hcenter(CENTERING, "Using Project Superior CFC v1.0 beta 1\n");
			hcenter(CENTERING, "Current console size: %dx%d\n\n", consoleSize.X + 1, consoleSize.Y + 1);
	    	
			SetConsoleOutputCP(1250);
			hcenter(CENTERING, "(c) 2016 Marian Dolinský\n\n");
			SetConsoleOutputCP(CP_OEM);
	
#ifndef DISABLE_CHANGELOG
			cursorPosition = hcenter(9, "Changelog\n");
			cursorPosition.X -= 2;
			
			hcenter(9, "Changelog (unigfcs.h)\n");
			hcenter(9, "Back");
#else
			hcenter("> Back");
#endif
			
			consoleSizeChanged = false;
			renderMain = false;
			renderSelection = true;
		}
					
#ifdef DEBUG
		DEBUG_MAIN;
#endif
			
#ifndef DISABLE_CHANGELOG
		if (renderSelection)
		{
			for (int i = -1; i <= 1; i += 2)
			{
				movecursor(cursorPosition.X, cursorPosition.Y + selection + i);
				putchar(' ');
			}
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection);
			putchar('>');
			
			renderSelection = false;
		}
		
		if (kbhit())
		{
			key = getkey(getcheat(getch()));
		
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
				else //if (selection == 1)
				{
					changelog(CHANGELOG_UNIGFCS, sizeof(CHANGELOG_UNIGFCS));
				}
				
				selection = 2;
				renderMain = true;
			}
			else if (key == Up && selection != 0)
			{
				selection--;
				renderSelection = true;
			}
			else if (key == Down && selection != 2)
			{
				selection++;
				renderSelection = true;
			}
		}
		
		Sleep(MENU_SLEEP);
#else
		if (kbhit())
		{
			key = getch();
		
			if (key == Enter || key == Esc)
			{
				return;
			}
		}
		
		Sleep(MENU_SLEEP);
#endif
	}
}

#ifndef DISABLE_CHANGELOG
void changelog(const char *changelog[], int size)
{
	const int CENTERING = 37;
	const int ROWS_MAX = 15;
	
	bool renderMain = true, renderChangelog = true;
	char key;
	int row = 0;
	COORD changelogPosition;
	
	while (true)
	{
		if (consoleSizeChanged || renderMain)
		{
			cls();
			
			vcenter(ROWS_MAX + 4);
			hcenter(changelog == CHANGELOG_GAME ? "CHANGELOG" : "CHANGELOG (UNIGFCS.H)");
			fputs("\n\n", stdout);
			
			changelogPosition = getcursorposition();
			
			movecursor(0, changelogPosition.Y + ROWS_MAX + 1);
			hcenter("> Back  ");
			
			consoleSizeChanged = false;
			renderMain = false;
			renderChangelog = true;
		}
		
		if (renderChangelog)
		{
			movecursor(changelogPosition);
			
			for (int i = 0; i < ROWS_MAX; i++)
			{
				hcenter(CENTERING, "%s%-*s \n", (*changelog[row + i] == '-' ? "  " : ""), 50, changelog[row + i]);
			}
			
			renderChangelog = false;
		}
		
#ifdef DEBUG
		movecursor(COORD_ORIGIN);
		printf("row: %2d | ", row);
		printf("size: %d | ", size);
		DEBUG_KEY(key);
		DEBUG_CHEATS;
#endif
		
		if (kbhit())
		{
			key = getkey(getcheat(getch()));
			
			if (key == Enter || key == Esc)
			{
				return;
			}
			else if (key == Up && row != 0)
			{
				row--;
				renderChangelog = true;
			}
			else if (key == Down && row != (size / sizeof(char *)) - ROWS_MAX)
			{
				row++;
				renderChangelog = true;
			}
		}
		
		Sleep(MENU_SLEEP);
	}
}
#endif

bool pausemenu(bool hotseat)
{
	const int CENTERING = 8;
	
	bool renderMain = true, renderSelection = true;
	char key;
	int selection = 0;
	COORD cursorPosition;
	HANDLE gameBoardBuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	
	copybuffer(&gameBoardBuffer, &stdOut);
	
	while (true)
	{
		if (consoleSizeChanged || renderMain)
		{
			cls();
			
			vcenter(7);
			hcenter("PAUSE MENU");
			fputs("\n\n", stdout);
			
			cursorPosition = hcenter(CENTERING, "Resume\n");
			cursorPosition.X -= 2;
			
			hcenter(CENTERING, "Restart\n");
			hcenter(CENTERING, "Controls\n");
			hcenter(CENTERING, "Go to main menu\n");
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
			for (int i = -1; i <= 1; i += 2)
			{
				movecursor(cursorPosition.X, cursorPosition.Y + selection + i);
				putchar(' ');
			}
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection);
			putchar('>');
			
			renderSelection = false;
		}
		
		if (kbhit())
		{
			key = getkey(getcheat(getch()));
			
			if ((key == Enter && selection == 0) || key == Esc)
			{
				forceconsolesize();
				copybuffer(&stdOut, &gameBoardBuffer);
				
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
					if (quitdialog(selection == 1 ? Restart : (selection == 3 ? Menu : Quit), true, hotseat))
					{
						return true;
					}
				}
				
				renderMain = true;
			}
			else if (key == Up && selection != 0)
			{
				selection--;
				renderSelection = true;
			}
			else if (key == Down && selection != 4)
			{
				selection++;
				renderSelection = true;
			}
		}
		
		Sleep(MENU_SLEEP);
	}
}

bool quitdialog(QUITACTION action, bool playing, bool hotseat)
{
	bool renderMain = true, renderSelection = true;
	char key;
	int selection = 1;
	COORD cursorPosition;
	
	while (true)
	{
		if (consoleSizeChanged || renderMain)
		{
			cls();
			
			vcenter(playing ? 4 : 3);
			hcenter(action == Restart ? "Are you sure you want to restart the game?" : (action == Menu ?  "Are you sure you want to go to main menu?" : "Are you sure you want to quit the game?"));
			
			if (playing)
			{
				putchar('\n');
				hcenter("Your game progress will be lost!");
			}
			
			fputs("\n\n", stdout);
			
			cursorPosition = hcenter(18, "Yes");
			cursorPosition.X += 14;
			
			movecursor(cursorPosition.X + 2, cursorPosition.Y);
			fputs("No", stdout);
			
			consoleSizeChanged = false;
			renderMain = false;
			renderSelection = true;
		}
		
#ifdef DEBUG
		DEBUG_MAIN;
#endif
		
		if (renderSelection)
		{
			movecursor(cursorPosition.X - (selection == 1 ? 16 : 0), cursorPosition.Y);
			putchar(' ');
			
			movecursor(cursorPosition.X - (selection == 0 ? 16 : 0), cursorPosition.Y);
			putchar('>');
			
			renderSelection = false;
		}
		
		if (kbhit())
		{
			key = getkey(getcheat(getch()));
			
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
				else //if (action == Quit)
				{
					cls();
					exit(EXIT_SUCCESS);
				}
				
				renderMain = true;
			}
			else if (key == Left && selection != 0)
			{
				selection--;
				renderSelection = true;
			}
			else if (key == Right && selection != 1)
			{
				selection++;
				renderSelection = true;
			}
		}
		
		Sleep(MENU_SLEEP);
	}
}

void showscore(bool won, int score, DIFFICULTY difficulty, const char *gameMode)
{
	const int CENTERING = 7;
	
	bool renderMain = true, renderSelection = true;
	char key;
	int selection = 1;
	COORD cursorPosition;
		
	while (true)
	{
		if (consoleSizeChanged || renderMain)
		{
			cls();
			vcenter(14);
			
			if (won)
			{
				setforeground(Green);
				bigtext("YOU WON");
			}
			else
			{
				setforeground(Red);
				bigtext("GAME OVER");
			}
			
			setforeground(White);
			printf("\n\n\n");
			
			hcenter(14, "Your score: %d\n\n", score);
			hcenter(18, "Difficulty: %s\n", difficulty == Easy ? "Easy" : (difficulty == Medium ? "Medium" : (difficulty == Hard ? "Hard" : "Custom")));
			hcenter(18, "Game mode: %s\n\n", gameMode);
			
			cursorPosition = hcenter(CENTERING, "Restart\n");
			cursorPosition.X -= 2;
			
			hcenter(CENTERING, "Back");
			
			consoleSizeChanged = false;
			renderMain = false;
			renderSelection = true;
		}
		
#ifdef DEBUG
		DEBUG_MAIN;
#endif
		
		if (renderSelection)
		{
			movecursor(cursorPosition.X, cursorPosition.Y + (selection == 0 ? 1 : 0));
			putchar(' ');
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection);
			putchar('>');
			
			renderSelection = false;
		}
		
		if (kbhit())
		{
			key = getkey(getcheat(getch()));
			
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
				renderSelection = true;
			}
			else if (key == Down && selection != 1)
			{
				selection++;
				renderSelection = true;
			}
		}
		
		Sleep(MENU_SLEEP);
	}
}

void showscore(bool won[2], int score[2], DIFFICULTY difficulty, const char *gameMode)
{
	const int CENTERING = 7;
	
	bool renderMain = true, renderSelection = true;
	char key;
	int selection = 1;
	COORD cursorPosition;
		
	while (true)
	{
		if (consoleSizeChanged || renderMain)
		{
			cls();
			vcenter(15);
			
			if (won[0] || won[1])
			{
				setforeground(Green);
				bigtext("YOU WON");
			}
			else
			{
				setforeground(Red);
				bigtext("GAME OVER");
			}
			
			setforeground(White);
			printf("\n\n\n");
			
			hcenter(27, won[0] ? "Player 1 won with score %d\n" : "Player 1 died with score %d\n", score[0]);
			hcenter(27, won[1] ? "Player 2 won with score %d\n" : "Player 2 died with score %d\n\n", score[1]);
			hcenter(18, "Difficulty: %s\n", difficulty == Easy ? "Easy" : (difficulty == Medium ? "Medium" : (difficulty == Hard ? "Hard" : "Custom")));
			hcenter(18, "Game mode: %s\n\n", gameMode);
			
			cursorPosition = hcenter(CENTERING, "Restart\n");
			cursorPosition.X -= 2;
			
			hcenter(CENTERING, "Back");
			
			consoleSizeChanged = false;
			renderMain = false;
			renderSelection = true;
		}
		
#ifdef DEBUG
		DEBUG_MAIN;
#endif
		
		if (renderSelection)
		{
			movecursor(cursorPosition.X, cursorPosition.Y + (selection == 0 ? 1 : 0));
			putchar(' ');
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection);
			putchar('>');
			
			renderSelection = false;
		}
		
		if (kbhit())
		{
			key = getkey(getcheat(getch()));
			
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
				renderSelection = true;
			}
			else if (key == Down && selection != 1)
			{
				selection++;
				renderSelection = true;
			}
		}
		
		Sleep(MENU_SLEEP);
	}
}

void timer(bool isColored)
{
	const int SLEEP = 1100;
	cls();
	
	if (isColored)
	{
		setforeground(Red);
	}
	
	vcenter(5);
	bigtext("3");
	Sleep(SLEEP);
	cls();
	
	if (isColored)
	{
		setforeground(Yellow);
	}
	
	vcenter(5);
	bigtext("2");
	Sleep(SLEEP);
	cls();
	
	if (isColored)
	{
		setforeground(Green);
	}
	
	vcenter(5);
	bigtext("1");
	Sleep(SLEEP);
	cls();
	
	vcenter(5);
	bigtext("GO!");
	Sleep(SLEEP);
	
	setforeground(White);
}

void bigtext(const char *text)
{
	// centering is assigned to 4 because of four spaces on left and on right side
	// strlen(text) - 1 = count of spaces between each letters
	// int centering = 4 + strlen(text) - 1;
	int centering = 3 + strlen(text);
	char str[strlen(text)];
	
	strcpy(str, text);
	
	// Rewrite str as uppercase and set centering
	for (int i = 0; i < strlen(str); i++)
	{
		str[i] = toupper(str[i]);
		
		if (str[i] == 'M' || str[i] == 'N' || str[i] == 'Q' || str[i] == 'T' || str[i] == 'W' || str[i] == 'X' || str[i] == 'Y')
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
		else if (str[i] == 'I' || str[i] == ' ')
		{
			centering += 2;
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

#endif
