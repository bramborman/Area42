/*
	Name: Snake v1.7 'A better way'
	Copyright: (c) 2016 Marian Dolinský
	Author: Marian Dolinský
	Date: 10/07/16 14:50
	Description: Simple Snake game for console in Windows.
	
	TODO:
		hotseat arrows bug - sometimes rewrite
		obstacles
		responsive gameboard
		slowdown, poison
		increase speed with time in snake
		settings - controls etc
		save high scores
		save stats
			- berries eated
			- win/loose rate
			- specials eated
			- time played
			- bend counts :D
			- specials eated
			- games played
			- difficulties played
					.
					.
					.
	
	!!! The game is fully responsive but when playing, board size cannot be changed and is resetted to size on game start original.
	!!! Responsivity works better on Windows 10 than on older Windowses because console in W10 is resizable and can be maximized as another window apps.
	!!! Don't use Dev-C++ project, it will not recompile outside-project files (unigfcs.h) each project compilation (some files must be manually deleted to recompile them).
*/

//#define DEBUG
#define DISABLE_BUFFERASWINDOW

const char *CHEATS[] =
{
	"fisa",
	"hamster"
};

const char *CHANGELOG_GAME[] =
{
	"1.7 'A better way':         (05/29/2016)",
	"- Rewrited game engine",
	"- Showing score in title",
	"- Added new cheats",
	"- Added specials",
	"- Fixed bug with right bottom corner",
	"- Fully removed screen flashing",
	"- Some bugs were fixed",
	"1.6 'FISA is your hero':    (12/18/2015)",
	"- Added a little secret",
	"- Changed controls",
	"- Fixed screen flashing",
	"- Improved game performance",
	"- Some bugs were fixed",
	"1.5 'Make a way!':          (11/29/2015)",
	"- Added borderless mode",
	"- Better game performance",
	"1.4 'It grows':             (11/24/2015)",
	"- Game is now responsive designed",
	"- Code were optimized",
	"1.3 'Let me continue':      (11/22/2015)",
	"- Hotseat continues if one player dies",
	"- Added changelog",
	"- Some bugs were fixed",
	"1.2 'Do it twice':          (11/17/2015)",
	"- Added multiplayer",
	"- Code is more effective",
	"- Some bugs were fixed",
	"1.1 'When meowside flies':  (11/13/2015)",
	"- Added menus",
	"- Some bugs were fixed",
	"1.0 'First release':        (11/12/2015)",
	"- Only singleplayer",
	"- Without menus"
};

#include "unigfcs.h"

const char BERRY_CHAR		= 249;
const char NEUTRAL			= -5;
const int CHEATS_HAMSTER	= 3;
//const int NAME_LENGTH_MAX	= 16;

const int SLEEP_EASY	= 200;
const int SLEEP_MEDIUM	= 50;
const int SLEEP_HARD	= 30;

const int SNAKE_LENGTH_START = 3;
const int SNAKE_LENGTH_MAX	 = SNAKE_LENGTH_START + 100;

#define SPECIAL_SPAWN rand() % 1000000 == 53
const int SPECIAL_BONUS = 3;
const int LENGTH_PRECISION = (int)floor(log10(SNAKE_LENGTH_MAX)) + 1;
const char CONTROLS[2][4] =
{
	{ 'W', 'A', 'S', 'D'},
	{ Up, Left, Down, Right }
};

typedef enum
{
	Fisa,
	Hamster
} CHEAT;

typedef enum
{
	Bonus,
	Mine/*,
	Slowdown,
	Poison*/
} SPECIAL;

typedef struct
{
	char Direction;
	COORD Position;
} VECTOR;

typedef struct
{
	COORD Position;
	VISUAL Visual;
} BERRY;

typedef struct
{
	bool Collision;
	int Active;
	int Shown;
	VECTOR Head;
	VECTOR Tail;
	
	struct BEND
	{
		int Active;
		int ToAssign;
		VECTOR Vector[SNAKE_LENGTH_MAX];
	} Bend;
	
	VISUAL Visual;/*
	char PlayerName[NAME_LENGTH_MAX];
	bool Poison;
	int PoisonTimer;*/
} SNAKE;

typedef enum
{
	WASD,
	Arrows
} CONTROLTYPE;

typedef enum
{
	KUp,
	KLeft,
	KDown,
	KRight
} CONTROL;

char liveTitle[35] = {0};
BERRY specials[] = 
{
	// Bonus
	{
		{ }, { '+', Green }
	},
	
	// Mine
	{
		{ }, { 148, Red }
	}/*,
	
	// Slowdown
	{
		{ }, { 233, Yellow }
	},
	
	// Poison
	{
		{ }, { 233, DarkYellow }
	}*/
};

int main();
//void controls(); - already declared in unigfcs.h
//bool game(DIFFICULTY difficulty, bool hotseat); - already declared in unigfcs.h
int customdifficultyselection();
//bool strrem(char *str, int index);
bool playername(int sleep, bool hotseat, bool borders);
bool snakecreator(int sleep, bool hotseat, bool borders, const char *playersNames[2]);
// In-game functions
void livetitle(int score);
void livetitle(const char *playerName1, int score1, const char *playerName2, int score2);
void setrandomcolors();
void recreateboard(bool *gameBoard, VISUAL snake, BERRY berry, bool isSpecialShown, SPECIAL shownSpecial);
void recreateboard(bool *gameBoard, SNAKE snakes[2], BERRY berries[2], bool isSpecialShown, SPECIAL shownSpecial);
void newberry(BERRY *berry, bool randomColor, bool *gameBoard);
void playsnake(int sleep, bool borders, VISUAL visual, const char *playerName);
void playhotseat(int sleep, bool borders, VISUAL visuals[2], const char *playersNames[2]);

int main()
{
	initialize("Snake", "v1.7 'A better way'", "beta 4", 79, 24);
	mainmenu(Green);
	
	// Program should not get there
	cls();
	vcenter(3);
	hcenter("SOMETHING WENT WRONG :-(\n");
	hcenter("Press any key to close the game . . .");
	
	getch();
	
	exit(EXIT_FAILURE);
}

void controls()
{
	const int CENTERING = 35;
	
	bool render = true;
	char key;
	
	while (true)
	{
		if (consoleSizeChanged || render)
		{
			
			cls();
			
#ifdef DEBUG
			vcenter(9);
#else
			vcenter(8);
#endif
			
			hcenter("CONTROLS");
			fputs("\n\n", stdout);
			
			hcenter(CENTERING, "Player 1:          Arrow keys\n");
			hcenter(CENTERING, "Player 2:          WASD\n");
			
#ifdef DEBUG
			hcenter(CENTERING, "Freeze game:       SPACE\n");
#endif
			
			hcenter(CENTERING, "Pause game:        ESC\n");
			hcenter(CENTERING, "Menus navigation:  Arrow keys, ENTER, ESC");
			fputs("\n\n", stdout);
			
			hcenter("> Back  ");
			
			consoleSizeChanged = false;
			render = false;
		}
		
#ifdef DEBUG
		movecursor(COORD_ORIGIN);
		DEBUG_CHEATS;
#endif
			
		if (kbhit())
		{
			key = getch();
			
			if (key == Enter || key == Esc)
			{
				return;
			}
		}
		
		Sleep(MENU_SLEEP);
	}
}

bool game(DIFFICULTY difficulty, bool hotseat)
{
	const int CENTERING = 6;
	
	bool renderMain = true, renderSelection = true;
	char key;
	int outDifficulty, selection = 0;
	COORD cursorPosition;
	
	if (difficulty == Custom)
	{
		outDifficulty = customdifficultyselection();
		
		if (outDifficulty == 0)
		{
			return false;
		}
	}
	else
	{
		outDifficulty = (difficulty == Easy ? SLEEP_EASY : (difficulty == Medium ? SLEEP_MEDIUM : SLEEP_HARD));
	}
	
	while (true)
	{
		if (consoleSizeChanged || renderMain)
		{
			cls();
			
			vcenter(5);
			hcenter("CHOOSE GAME MODE");
			fputs("\n\n", stdout);
			
			cursorPosition = hcenter(CENTERING, "Normal\n");
			cursorPosition.X -= 2;
			
			hcenter(CENTERING, "Borderless\n");
			putchar('\n');
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
			for (int i = (selection == 2 ? -2 : -1); i <= (selection == 1 ? 2 : 1); i++)
			{
				movecursor(cursorPosition.X, cursorPosition.Y + selection + (selection == 2 ? 1 : 0) + i);
				putchar(' ');
			}
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection + (selection == 2 ? 1 : 0));
			putchar('>');
			
			renderSelection = false;
		}
		
		if (kbhit())
		{
			key = getkey(getcheat(getch()));
			
			if ((key == Enter && selection == 2) || key == Esc)
			{
				return false;
			}
			else if (key == Enter)
			{
				if (playername(outDifficulty, hotseat, (selection == 0 ? true : false)))
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
			else if (key == Down && selection != 2)
			{
				selection++;
				renderSelection = true;
			}
		}
		
		Sleep(MENU_SLEEP);
	}
}

int customdifficultyselection()
{
	const int CENTERING = 7;
	const int MIN = 10;
	const int MAX = 300;
	const int STEP = 5;
	
	bool renderMain = true, renderSelection = true;
	char key;
	int selection = 0, wheelSelection = MIN;
	COORD cursorPosition, wheelCursorPosition;
	
	while (true)
	{
		if (consoleSizeChanged || renderMain)
		{
			cls();
			
			vcenter(7);
			hcenter("CHOOSE CUSTOM DELAY");
			fputs("\n\n", stdout);
			
			wheelCursorPosition = getcursorposition();
			
			printf("\n\n\n");
			
			cursorPosition = hcenter(CENTERING, "Confirm\n");
			cursorPosition.X -= 2;
			
			hcenter(CENTERING, "Back");
			
			consoleSizeChanged = false;
			renderMain = false;
			renderSelection = true;
		}
		
#ifdef DEBUG
		DEBUG_MAIN;
		printf("\nwheelSelection: %3d | ", wheelSelection);
		printf("wheelCursorPosition: %*d %*d", consoleSizeXPrecision, wheelCursorPosition.X, consoleSizeXPrecision, wheelCursorPosition.Y);
#endif
		
		if (renderSelection)
		{
			wheelselection(wheelCursorPosition, wheelSelection, MIN, MAX, STEP);
			
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
				return 0;
			}
			else if (key == Enter)
			{
				return wheelSelection;
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
			else if (key == Left)
			{
				wheelSelection -= STEP;
				
				if (wheelSelection == MIN - STEP)
				{
					wheelSelection = MAX;
				}
				
				renderSelection = true;
			}
			else if (key == Right)
			{
				wheelSelection += STEP;
				
				if (wheelSelection == MAX + STEP)
				{
					wheelSelection = MIN;
				}
				
				renderSelection = true;
			}
		}
		
		Sleep(MENU_SLEEP);
	}
}

bool playername(int sleep, bool hotseat, bool borders)
{
	char playersNames[2][1] = {0};
	
	if (snakecreator(sleep, hotseat, borders, (const char **)playersNames))
	{
		return true;
	}
	
	return false;
	
	// Here should be TextBox for selecting names
}

bool snakecreator(int sleep, bool hotseat, bool borders, const char *playersNames[2])
{
	const char BODIES[] = {'O', 'X', 176, 177, 219, '\0'};
	const int CENTERING = 7;
	const int COLOR_CHAR = 254;
	const int COLOR_MIN = Blue;
	const int COLOR_MAX = White;
	
	bool changing, resetVisual = true, renderMain = true, renderMainSelection = true, renderSnakeSelection = true;
	char key;
	int actualSnake, bodySelection, colorSelection, selection;
	COORD bodyCursorPosition, colorCursorPosition, snakeCursorPosition, cursorPosition;
	VISUAL snakeVisual[2];
	
	changing = false;
	actualSnake = 0;
	
	while (true)
	{
		if (consoleSizeChanged || renderMain)
		{
			if (resetVisual)
			{
				bodySelection = 0;
				colorSelection = White;
				selection = 0;
				
				snakeVisual[actualSnake].Char = BODIES[bodySelection];
				snakeVisual[actualSnake].Color = (COLOR)colorSelection;
				
				resetVisual = false;
			}
			
			cls();
			vcenter(15);
			
			if (!hotseat)
			{
				hcenter("CREATE YOUR OWN SNAKE");
			}
			else
			{
				hcenter(strlen("PLAYER X - CREATE YOUR OWN SNAKE"));
				printf("PLAYER %d - CREATE YOUR OWN SNAKE", actualSnake + 1);
			}
			
			fputs("\n\n", stdout);
			
			// Go to absolute center on X axis
			colorCursorPosition = snakeCursorPosition = hcenter(0);
			
			// Set coordinates for snake preview
			snakeCursorPosition.X--;
			snakeCursorPosition.Y += 2;
			
			// Get coordinates for body selection
			movecursor(0, colorCursorPosition.Y + 8);
			bodyCursorPosition = hcenter(9);
			
			// Print color selection
			colorCursorPosition.X += 10;
			
			for (int i = COLOR_MAX; i >= COLOR_MIN; i--)
			{
				setforeground((COLOR)i);
				
				movecursor(colorCursorPosition.X, colorCursorPosition.Y + (COLOR_MAX - i));
				putchar(COLOR_CHAR);
			}
			
			colorCursorPosition.X += 2;
			
			putchar('\n');
			// Get coordinates for main selection
			cursorPosition = hcenter(CENTERING);
			cursorPosition.X -= 2;
			cursorPosition.Y += 3;
			
			consoleSizeChanged = false;
			renderMain = false;
			renderMainSelection = true;
			renderSnakeSelection = true;
		}
		
#ifdef DEBUG
		setforeground(White);
		DEBUG_MAIN;
		printf("\nbodyCursor: %*d %*d | ", consoleSizeXPrecision, bodyCursorPosition.X, consoleSizeXPrecision, bodyCursorPosition.Y);
		printf("colorCursor: %*d %*d | ", consoleSizeXPrecision, colorCursorPosition.X, consoleSizeXPrecision, colorCursorPosition.Y);
		printf("snakeCursor: %*d %*d", consoleSizeXPrecision, snakeCursorPosition.X, consoleSizeXPrecision, snakeCursorPosition.Y);
		printf("\nbodySelection: %2d | ", bodySelection);
		printf("colorSelection: %2d | ", colorSelection);
		printf("changing: %d | ", changing);
		printf("snakeVisual[%d].Char: %c | ", actualSnake, snakeVisual[actualSnake].Char);
		printf("snakeVisual[%d].Color: %2d", actualSnake, snakeVisual[actualSnake].Color);
#endif
		
		if (renderSnakeSelection)
		{
			// Print snake preview
			setforeground((COLOR)colorSelection);
			
			for (int i = 0; i < 3; i++)
			{
				movecursor(snakeCursorPosition.X, snakeCursorPosition.Y + i);
				putchar(BODIES[bodySelection]);
			}
			
			// Print body selection
			movecursor(bodyCursorPosition);
			
			setforeground(DarkGray);
			printf("%c ", (bodySelection == 1 ? BODIES[strlen(BODIES) - 1] : (bodySelection == 0 ? BODIES[strlen(BODIES) - 2] : BODIES[bodySelection - 2])));
			
			setforeground(Gray);
			printf("%c ", (bodySelection == 0 ? BODIES[strlen(BODIES) - 1] : BODIES[bodySelection - 1]));
			
			setforeground(White);
			printf("%c ", BODIES[bodySelection]);
			
			setforeground(Gray);
			printf("%c ", (bodySelection == strlen(BODIES) - 1 ? BODIES[0] : BODIES[bodySelection + 1]));
			
			setforeground(DarkGray);
			printf("%c", (bodySelection == strlen(BODIES) - 2 ? BODIES[0] : (bodySelection == strlen(BODIES) - 1 ? BODIES[1] : BODIES[bodySelection + 2])));
			
			setforeground(White);
		}
			
		if (renderSnakeSelection)
		{
			for (int i = 0; i < COLOR_MAX; i++)
			{
				movecursor(colorCursorPosition.X, colorCursorPosition.Y + i);
				putchar(' ');
			}
			
			if (changing)
			{
				movecursor(colorCursorPosition.X, colorCursorPosition.Y + (COLOR_MAX - colorSelection));
				putchar('<');
				
				setforeground(DarkGray);
			}
			
			renderSnakeSelection = false;
		}
		
		if (renderMainSelection)
		{
			movecursor(0, cursorPosition.Y);
			hcenter(CENTERING, "Confirm\n");
			hcenter(CENTERING, "Change\n");
			hcenter(CENTERING, "Back");
			
			for (int i = -1; i <= 1; i += 2)
			{
				movecursor(cursorPosition.X, cursorPosition.Y + selection + i);
				putchar(' ');
			}
			
			movecursor(cursorPosition.X, cursorPosition.Y + selection);
			putchar('>');
			
			renderMainSelection = false;
		}
		
		if (kbhit())
		{
			key = getkey(getcheat(getch()));
			
			if (changing)
			{
				if (key == Enter)
				{
					changing = false;
					renderMainSelection = true;
					renderSnakeSelection = true;
					
					// Assign snakeVisual from selection
					snakeVisual[actualSnake].Char = BODIES[bodySelection];
					snakeVisual[actualSnake].Color = (COLOR)colorSelection;
				}
				else if (key == Esc)
				{
					changing = false;
					resetVisual = true;
					renderMainSelection = true;
					renderSnakeSelection = true;
					
					// Assign selection from snakeVisual
					colorSelection = (int)snakeVisual[actualSnake].Color;
					
					for (int i = 0; i < strlen(BODIES); i++)
					{
						if (BODIES[i] == snakeVisual[actualSnake].Char)
						{
							bodySelection = i;
							break;
						}
					}
				}
				else if (key == Up && colorSelection != COLOR_MAX)
				{
					colorSelection++;
					renderSnakeSelection = true;
				}
				else if (key == Down && colorSelection != COLOR_MIN)
				{
					colorSelection--;
					renderSnakeSelection = true;
				}
				else if (key == Left)
				{
					if (bodySelection == 0)
					{
						bodySelection = strlen(BODIES) - 1;
					}
					else
					{
						bodySelection--;
					}
					
					renderSnakeSelection = true;
				}
				else if (key == Right)
				{
					if (bodySelection == strlen(BODIES) - 1)
					{
						bodySelection = 0;
					}
					else
					{
						bodySelection++;
					}
					
					renderSnakeSelection = true;
				}
			}
			else //if (!changing)
			{
				if ((key == Enter && selection == 2) || key == Esc)
				{
					if (actualSnake == 0)
					{
						return false;
					}
					else
					{
						actualSnake = 0;
						renderMain = true;
					
						// Assign selection from snakeVisual
						colorSelection = (int)snakeVisual[actualSnake].Color;
						
						for (int i = 0; i < strlen(BODIES); i++)
						{
							if (BODIES[i] == snakeVisual[actualSnake].Char)
							{
								bodySelection = i;
								break;
							}
						}
					}
				}
				else if (key == Enter)
				{
					if (selection == 1)
					{
						changing = true;
						renderMainSelection = true;
						renderSnakeSelection = true;
					}
					else //if (selection == 0)
					{
						if (!hotseat)
						{
							playsnake(sleep, borders, snakeVisual[actualSnake], playersNames[0]);
							return true;
						}
						else
						{
							if (actualSnake == 0)
							{
								actualSnake = 1;
								resetVisual = true;
								renderMain = true;
							}
							else
							{
								playhotseat(sleep, borders, snakeVisual, playersNames);
								return true;
							}
						}
						
					}
				}
				else if (key == Up && selection != 0)
				{
					selection--;
					renderMainSelection = true;
				}
				else if (key == Down && selection != 2)
				{
					selection++;
					renderMainSelection = true;
				}
			}
		}
		
		Sleep(MENU_SLEEP);
	}
}

void livetitle(int score)
{
	sprintf(liveTitle, "%s - score: %d", gameName, score - SNAKE_LENGTH_START);
	SetConsoleTitle(liveTitle);
}

void livetitle(const char *playerName1, int score1, const char *playerName2, int score2)
{
	sprintf(liveTitle, "%s - %s: %d, %s: %d", gameName, playerName1, score1 - SNAKE_LENGTH_START, playerName2, score2 - SNAKE_LENGTH_START);
	SetConsoleTitle(liveTitle);
}

void setrandomcolors()
{
	DWORD written;
	
	do
	{
		setforeground((COLOR)(rand() % 16));
		setbackground((COLOR)(rand() % 16));
	} while (foregroundColor == backgroundColor);
	
	FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foregroundColor + (backgroundColor << 4), (forcedConsoleSize.X + 1) * (forcedConsoleSize.Y + 1), COORD_ORIGIN, &written);
}

void recreateboard(bool *gameBoard, VISUAL snake, BERRY berry, bool isSpecialShown, SPECIAL shownSpecial)
{
	cls();
	
	if (cheats[Fisa])
	{
		setrandomcolors();
	}
	
	// Print snake
	for (int y = 0; y < forcedConsoleSize.Y + 1; y++)
	{
		for (int x = 0; x < forcedConsoleSize.X + 1; x++)
		{
			if (*(gameBoard + (y * (forcedConsoleSize.X + 1)) + x))
			{
				movecursor(x, y);
				
				if (!cheats[Fisa])
				{
					draw(snake);
				}
				else
				{
					putchar(BLOCK_NORMAL);
				}
			}
		}
	}
	
	// Print berry
	movecursor(berry.Position);
	
	if (!cheats[Fisa])
	{
		draw(berry.Visual);
	}
	else
	{
		putchar(berry.Visual.Char);
	}
	
	// Print special
	if (isSpecialShown)
	{
		movecursor(specials[shownSpecial].Position);
		
		if (!cheats[Fisa])
		{
			draw(specials[shownSpecial].Visual);
		}
		else
		{
			putchar(specials[shownSpecial].Visual.Char);
		}
	}
}

void recreateboard(bool *gameBoard, SNAKE snakes[2], BERRY berries[2], bool isSpecialShown, SPECIAL shownSpecial)
{
	// TODO: everything here
}

void newberry(BERRY *berry, bool randomColor, bool *gameBoard)
{
	bool collision;
	
	do
	{
		collision = false;
		
		berry->Position.X = rand() % (forcedConsoleSize.X + 1);
		berry->Position.Y = rand() % (forcedConsoleSize.Y + 1);
		
		// Collision - new berry with snake
		for (int y = -1; y <= 1; y++)
		{
			// Skip this cycle step when variables points out of GAMEBOARD range
			if ((berry->Position.Y == 0 && y == -1) || (berry->Position.Y == forcedConsoleSize.Y && y == 1))
			{
				continue;
			}
			
			for (int x = -1; x <= 1; x++)
			{
				// Skip this cycle step when variables points out of GAMEBOARD range
				if ((berry->Position.X == 0 && x == -1) || (berry->Position.X == forcedConsoleSize.X && x == 1))
				{
					continue;
				}
				
				if (*(gameBoard + ((berry->Position.Y + y) * (forcedConsoleSize.X + 1)) + (berry->Position.X + x)))
				{
					collision = true;
					break;
				}
			}
			
			if (collision)
			{
				break;
			}
		}
	} while (collision);
	
	if (randomColor)
	{
		berry->Visual.Color = (COLOR)(rand() % 8 + 8);
	}
	
	// Print berry
	movecursor(berry->Position);
	draw(berry->Visual);
}

void playsnake(int sleep, bool borders, VISUAL visual, const char *playerName)
{
#ifndef DEBUG
	timer(true);
#endif
	
	forcedConsoleSize = consoleSize;
	SuspendThread(sizecheckthreadHandle);
	SuspendThread(cheatpromptthreadHandle);
	cls();
	
	bool isSpecialShown, lastFisaState;
	bool gameBoard[forcedConsoleSize.Y + 1][forcedConsoleSize.X + 1];
	char key;
	SPECIAL shownSpecial;
	BERRY berry;
	SNAKE snake;
	
	// Assign variables
	isSpecialShown = false;
	lastFisaState  = cheats[Fisa];
	memset(gameBoard, false, (forcedConsoleSize.X + 1) * (forcedConsoleSize.Y + 1));
	shownSpecial = (SPECIAL)0;
	
	berry.Visual.Char = BERRY_CHAR;
	
	snake.Collision			= false;
	snake.Active			= SNAKE_LENGTH_START;
	snake.Shown				= 0;
	snake.Bend.Active		= 0;
	snake.Bend.ToAssign		= 0;
	snake.Head.Position.X	= (forcedConsoleSize.X + 1) / 2;
	snake.Head.Position.Y	= (forcedConsoleSize.Y + 1) / 2;
	snake.Tail.Position		= snake.Head.Position;
	snake.Head.Direction	= CONTROLS[Arrows][KUp];
	snake.Tail.Direction	= snake.Head.Direction;
	snake.Visual			= visual;
	//strcpy(snake.PlayerName, playerName);
	
	gameBoard[snake.Head.Position.Y][snake.Head.Position.X] = true;
	
	for (int i = 0; i < SNAKE_LENGTH_MAX; i++)
	{
		snake.Bend.Vector[i].Position.X = NEUTRAL;
		snake.Bend.Vector[i].Position.Y = NEUTRAL;
		snake.Bend.Vector[i].Direction  = NEUTRAL;
	}
	
	// Create berry
	newberry(&berry, true, gameBoard[0]);
	livetitle(snake.Active);
	
	// Main game cycle
	while (true)
	{
		forceconsolesize();
		
		if (consoleSizeChanged)
		{
			movecursor(berry.Position);
			draw(berry.Visual);
			
			consoleSizeChanged = false;
		}
		
		if (cheats[Fisa])
		{
			setrandomcolors();
		}
		
		// Print snake
		gameBoard[snake.Head.Position.Y][snake.Head.Position.X] = true;
		movecursor(snake.Head.Position);
		
		if (!cheats[Fisa])
		{
			draw(snake.Visual);
		}
		else
		{
			putchar(BLOCK_NORMAL);
		}
		
		if (snake.Shown < snake.Active)
		{
			snake.Shown++;
		}
		else
		{
			// Remove tail
			gameBoard[snake.Tail.Position.Y][snake.Tail.Position.X] = false;
			movecursor(snake.Tail.Position);
			
			if (!cheats[Fisa])
			{
				setforeground(Black);
				putchar(snake.Visual.Char);
				setforeground(White);
			}
			else
			{
				putchar(' ');
			}
			
			// Change tail direction
			if (snake.Tail.Position == snake.Bend.Vector[snake.Bend.Active].Position)
			{
				snake.Tail.Direction = snake.Bend.Vector[snake.Bend.Active++].Direction;
				
				if (snake.Bend.Active == SNAKE_LENGTH_MAX)
				{
					snake.Bend.Active = 0;
				}
			}
			
			// Change tail position
			if (snake.Tail.Direction == CONTROLS[Arrows][KUp])
			{
				snake.Tail.Position.Y--;
			}
			else if (snake.Tail.Direction == CONTROLS[Arrows][KDown])
			{
				snake.Tail.Position.Y++;
			}
			else if (snake.Tail.Direction == CONTROLS[Arrows][KLeft])
			{
				snake.Tail.Position.X--;
			}
			else if (snake.Tail.Direction == CONTROLS[Arrows][KRight])
			{
				snake.Tail.Position.X++;
			}
			
			// Move tail to opposite console edges
			if (!borders)
			{
				if (snake.Tail.Position.X < 0)
				{
					snake.Tail.Position.X = forcedConsoleSize.X;
				}
				else if (snake.Tail.Position.X > forcedConsoleSize.X)
				{
					snake.Tail.Position.X = 0;
				}
				else if (snake.Tail.Position.Y < 0)
				{
					snake.Tail.Position.Y = forcedConsoleSize.Y;
				}
				else if (snake.Tail.Position.Y > forcedConsoleSize.Y)
				{
					snake.Tail.Position.Y = 0;
				}
			}
		}
	
		movecursor(COORD_ORIGIN);
	
#ifdef DEBUG
		printf("head: %*d %*d %c | ", consoleSizeXPrecision, snake.Head.Position.X, consoleSizeXPrecision, snake.Head.Position.Y, printarrow(snake.Head.Direction));
		printf("bend[%*d]:% *d% *d %c | ", LENGTH_PRECISION, snake.Bend.Active, consoleSizeXPrecision + 1, snake.Bend.Vector[snake.Bend.Active].Position.X, consoleSizeXPrecision + 1, snake.Bend.Vector[snake.Bend.Active].Position.Y,
			printarrow(snake.Bend.Vector[snake.Bend.Active].Direction));
		printf("active: %*d | ", LENGTH_PRECISION, snake.Active);
		printf("berry: %*d %*d | ", consoleSizeXPrecision, berry.Position.X, consoleSizeXPrecision, berry.Position.Y);
		printf("color: %c%c", (foregroundColor < 10 ? foregroundColor + '0' : foregroundColor - 10 + 'A'), (backgroundColor < 10 ? backgroundColor + '0' : backgroundColor - 10 + 'A'));
		
		printf("\ntail: %*d %*d %c | ", consoleSizeXPrecision, snake.Tail.Position.X, consoleSizeXPrecision, snake.Tail.Position.Y, printarrow(snake.Tail.Direction));
		
		if (snake.Bend.ToAssign > 0)
		{
			printf("bend[%*d]: %*d %*d %c | ",
					LENGTH_PRECISION, snake.Bend.ToAssign,
					consoleSizeXPrecision, snake.Bend.Vector[snake.Bend.ToAssign - 1].Position.X,
					consoleSizeXPrecision, snake.Bend.Vector[snake.Bend.ToAssign - 1].Position.Y,
					printarrow(snake.Bend.Vector[snake.Bend.ToAssign - 1].Direction)
					);
		}
		else
		{
			printf("bend[%*d]: %s %s - | ", LENGTH_PRECISION, snake.Bend.ToAssign, createline('-', consoleSizeXPrecision),  createline('-', consoleSizeXPrecision));
		}
		
		printf("shown:  %*d | ", LENGTH_PRECISION, snake.Shown);
		printf("sleep: %3d", sleep);
		printf("\nisSpecialShown: %d | ", isSpecialShown);
		printf("specials[%d]: %*d %*d", shownSpecial, consoleSizeXPrecision, specials[shownSpecial].Position.X, consoleSizeXPrecision, specials[shownSpecial].Position.Y);
		DEBUG_CHEATS;
#endif
		
		Sleep(sleep);
		
		if (kbhit())
		{
			key = getch();
			
			if (key == -32 || key == 224)
			{
				// Get new direction for head
				key = getch();
				
				if (IF_ARROW(key) && key != snake.Head.Direction && key != (snake.Head.Direction == Up ? Down : (snake.Head.Direction == Down ? Up : (snake.Head.Direction == Left ? Right : Left))))
				{
					// Assign new bend
					snake.Head.Direction = snake.Bend.Vector[snake.Bend.ToAssign].Direction = key;
					snake.Bend.Vector[snake.Bend.ToAssign++].Position = snake.Head.Position;
					
					if (snake.Bend.ToAssign == SNAKE_LENGTH_MAX)
					{
						snake.Bend.ToAssign = 0;
					}
				}
			}
			else if (key == Esc)
			{
				ResumeThread(sizecheckthreadHandle);
				ResumeThread(cheatpromptthreadHandle);
				SetConsoleTitle(gameName);
				
				setforeground(White);
				setbackground(Black);
				
				if (pausemenu(false))
				{
					return;
				}
				
				SuspendThread(sizecheckthreadHandle);
				SuspendThread(cheatpromptthreadHandle);
				livetitle(snake.Active);
				
				if (cheats[Fisa] != lastFisaState)
				{
					recreateboard(gameBoard[0], snake.Visual, berry, isSpecialShown, shownSpecial);
					lastFisaState = cheats[Fisa];
				}
			}
#ifdef DEBUG
			else if (key == Space)
			{
				while (getch() != Space);
			}
#endif
		}
		
		// Change snake position
		if (snake.Head.Direction == CONTROLS[Arrows][KUp])
		{
			snake.Head.Position.Y--;
		}
		else if (snake.Head.Direction == CONTROLS[Arrows][KDown])
		{
			snake.Head.Position.Y++;
		}
		else if (snake.Head.Direction == CONTROLS[Arrows][KLeft])
		{
			snake.Head.Position.X--;
		}
		else if (snake.Head.Direction == CONTROLS[Arrows][KRight])
		{
			snake.Head.Position.X++;
		}
		
		if (!borders)
		{
			// Move head to opposite console edge
			if (snake.Head.Position.X < 0)
			{
				snake.Head.Position.X = forcedConsoleSize.X;
			}
			else if (snake.Head.Position.X > forcedConsoleSize.X)
			{
				snake.Head.Position.X = 0;
			}
			else if (snake.Head.Position.Y < 0)
			{
				snake.Head.Position.Y = forcedConsoleSize.Y;
			}
			else if (snake.Head.Position.Y > forcedConsoleSize.Y)
			{
				snake.Head.Position.Y = 0;
			}
		}
		
		// Eat berry
		if (snake.Head.Position == berry.Position)
		{
			snake.Active += (cheats[Hamster] ? CHEATS_HAMSTER : 1);
			livetitle(snake.Active);
			
			newberry(&berry, true, gameBoard[0]);
		}
		
		// Specials
		if (!isSpecialShown && SPECIAL_SPAWN)
		{
			// Create new special berry
			shownSpecial = (SPECIAL)(rand() % (sizeof(specials) / sizeof(specials[0])));
			newberry(&specials[shownSpecial], false, gameBoard[0]);
			
			isSpecialShown = true;
		}
		else if (isSpecialShown)
		{
			if (snake.Head.Position == specials[shownSpecial].Position)
			{
				// Eat special berry
				switch (shownSpecial)
				{
					case Bonus:
						snake.Active += SPECIAL_BONUS;
						livetitle(snake.Active);
						break;
					
					case Mine:
						snake.Collision = true;
						break;
					/*
					case Slowdown:
						// TODO: slowdown
						break;
					
					case Poison:
						// TODO: poison
						break;*/
				}
				
				isSpecialShown = false;
			}
			else if (SPECIAL_SPAWN)
			{
				// Remove special berry
				movecursor(specials[shownSpecial].Position);
				putchar(' ');
				
				isSpecialShown = false;
			}
		}
		
		// Collision
		if (!snake.Collision)
		{
			snake.Collision = borders && !(snake.Head.Position >= COORD_ORIGIN && snake.Head.Position <= forcedConsoleSize) || gameBoard[snake.Head.Position.Y][snake.Head.Position.X];
		}
		
		// Game end
		if (snake.Collision || snake.Active == SNAKE_LENGTH_MAX)
		{
			SetConsoleTitle(gameName);
			ResumeThread(sizecheckthreadHandle);
			ResumeThread(cheatpromptthreadHandle);
			
			setforeground(White);
			setbackground(Black);
			
			showscore(snake.Active == SNAKE_LENGTH_MAX, snake.Active - SNAKE_LENGTH_START, sleep == SLEEP_EASY ? Easy : (sleep == SLEEP_MEDIUM ? Medium : (sleep == SLEEP_HARD ? Hard : Custom)), borders ? "Normal" : "Borderless");
			return;
		}
	}
}

void playhotseat(int sleep, bool borders, VISUAL visuals[2], const char *playersNames[2])
{
#ifndef DEBUG
	timer(true);
#endif
	
	forcedConsoleSize = consoleSize;
	SuspendThread(sizecheckthreadHandle);
	SuspendThread(cheatpromptthreadHandle);
	cls();
	
	bool isSpecialShown, lastFisaState;
	bool gotNewDirection[2];
	bool gameBoard[forcedConsoleSize.Y + 1][forcedConsoleSize.X + 1];
	char key;
	// Represents actual snake index from snakes array
	int s;
	// Represents actual berry index from berries array
	int b;
	SPECIAL shownSpecial;
	BERRY berries[2];
	SNAKE snakes[2];
	
	// Assign variables
	isSpecialShown = false;
	lastFisaState  = cheats[Fisa];
	memset(gameBoard, false, (forcedConsoleSize.X + 1) * (forcedConsoleSize.Y + 1));
	shownSpecial = (SPECIAL)0;
	
	for (s = 0; s <= 1; s++)
	{
		berries[s].Visual.Char = BERRY_CHAR;
	
		snakes[s].Collision			= false;
		snakes[s].Active			= SNAKE_LENGTH_START;
		snakes[s].Shown				= 0;
		snakes[s].Bend.Active		= 0;
		snakes[s].Bend.ToAssign		= 0;
		snakes[s].Head.Position.X	= (forcedConsoleSize.X + 1) * (1 + (2 * s)) / 4;
		snakes[s].Head.Position.Y	= (forcedConsoleSize.Y + 1) / 2;
		snakes[s].Tail.Position		= snakes[s].Head.Position;
		snakes[s].Head.Direction	= CONTROLS[s][KUp];
		snakes[s].Tail.Direction	= snakes[s].Head.Direction;
		snakes[s].Visual			= visuals[s];
		//strcpy(snakes[s].PlayerName, playersNames[s]);
		
		gameBoard[snakes[s].Head.Position.Y][snakes[s].Head.Position.X] = true;
		
		for (int i = 0; i < SNAKE_LENGTH_MAX; i++)
		{
			snakes[s].Bend.Vector[i].Position.X = NEUTRAL;
			snakes[s].Bend.Vector[i].Position.Y = NEUTRAL;
			snakes[s].Bend.Vector[i].Direction  = NEUTRAL;
		}
	}
	
	// Create berries
	newberry(&berries[0], true, gameBoard[0]);
	
	do
	{
		newberry(&berries[1], true, gameBoard[0]);
	} while (berries[0].Position == berries[1].Position);
	
	livetitle("Player 1", snakes[0].Active, "Player 2", snakes[1].Active);
	
	// Main game cycle
	while (true)
	{
		forceconsolesize();
		
		if (consoleSizeChanged)
		{
			movecursor(berries[0].Position);
			draw(berries[0].Visual);
			
			movecursor(berries[1].Position);
			draw(berries[1].Visual);
			
			consoleSizeChanged = false;
		}
		/*
		if (cheats[Fisa])
		{
			setrandomcolors();
		}
		*/
		for (s = 0; s <= 1; s++)
		{
			if (!snakes[s].Collision)
			{
				// Print snake
				gameBoard[snakes[s].Head.Position.Y][snakes[s].Head.Position.X] = true;
				movecursor(snakes[s].Head.Position);
				/*
				if (!cheats[Fisa])
				{*/
					draw(snakes[s].Visual);
				/*}
				else
				{
					putchar(BLOCK_NORMAL);
				}*/
				
				if (snakes[s].Shown < snakes[s].Active)
				{
					snakes[s].Shown++;
				}
				else
				{
					// Remove tail
					gameBoard[snakes[s].Tail.Position.Y][snakes[s].Tail.Position.X] = false;
					movecursor(snakes[s].Tail.Position);
					/*
					if (!cheats[Fisa])
					{*/
						setforeground(Black);
						putchar(snakes[s].Visual.Char);
						setforeground(White);
					/*}
					else
					{
						putchar(' ');
					}*/
					
					// Change tail direction
					if (snakes[s].Tail.Position == snakes[s].Bend.Vector[snakes[s].Bend.Active].Position)
					{
						snakes[s].Tail.Direction = snakes[s].Bend.Vector[snakes[s].Bend.Active++].Direction;
						
						if (snakes[s].Bend.Active == SNAKE_LENGTH_MAX)
						{
							snakes[s].Bend.Active = 0;
						}
					}
					
					// Change tail position
					if (snakes[s].Tail.Direction == CONTROLS[s][KUp])
					{
						snakes[s].Tail.Position.Y--;
					}
					else if (snakes[s].Tail.Direction == CONTROLS[s][KDown])
					{
						snakes[s].Tail.Position.Y++;
					}
					else if (snakes[s].Tail.Direction == CONTROLS[s][KLeft])
					{
						snakes[s].Tail.Position.X--;
					}
					else if (snakes[s].Tail.Direction == CONTROLS[s][KRight])
					{
						snakes[s].Tail.Position.X++;
					}
					
					// Move tail to opposite console edges
					if (!borders)
					{
						if (snakes[s].Tail.Position.X < 0)
						{
							snakes[s].Tail.Position.X = forcedConsoleSize.X;
						}
						else if (snakes[s].Tail.Position.X > forcedConsoleSize.X)
						{
							snakes[s].Tail.Position.X = 0;
						}
						else if (snakes[s].Tail.Position.Y < 0)
						{
							snakes[s].Tail.Position.Y = forcedConsoleSize.Y;
						}
						else if (snakes[s].Tail.Position.Y > forcedConsoleSize.Y)
						{
							snakes[s].Tail.Position.Y = 0;
						}
					}
				}
				
				movecursor(COORD_ORIGIN);
			}
		}
		
		Sleep(sleep);
		
		// Get new directions for heads
		// Not really efficient, should be rewrited
		gotNewDirection[0] = false;
		gotNewDirection[1] = false;
		
		if (kbhit())
		{
			key = toupper(getch());
			
			if (!snakes[0].Collision && IF_WASD(key) && key != (snakes[0].Head.Direction == 'W' ? 'S' : (snakes[0].Head.Direction == 'S' ? 'W' : (snakes[0].Head.Direction == 'A' ? 'D' : 'A'))))
			{
				// Assign new bend
				snakes[0].Head.Direction = snakes[0].Bend.Vector[snakes[0].Bend.ToAssign].Direction = key;
				snakes[0].Bend.Vector[snakes[0].Bend.ToAssign++].Position = snakes[0].Head.Position;
				
				if (snakes[0].Bend.ToAssign == SNAKE_LENGTH_MAX)
				{
					snakes[0].Bend.ToAssign = 0;
				}
				
				gotNewDirection[0] = true;
			}
			else if (key == -32 || key == 224)
			{
				key = getch();
				
				if (!snakes[1].Collision && IF_ARROW(key) && key != (snakes[1].Head.Direction == Up ? Down : (snakes[1].Head.Direction == Down ? Up : (snakes[1].Head.Direction == Left ? Right : Left))))
				{
					// Assign new bend
					snakes[1].Head.Direction = snakes[1].Bend.Vector[snakes[1].Bend.ToAssign].Direction = key;
					snakes[1].Bend.Vector[snakes[1].Bend.ToAssign++].Position = snakes[1].Head.Position;
					
					if (snakes[1].Bend.ToAssign == SNAKE_LENGTH_MAX)
					{
						snakes[1].Bend.ToAssign = 0;
					}
					
					gotNewDirection[1] = true;
				}
			}
			else if (key == Esc)
			{
				ResumeThread(sizecheckthreadHandle);
				ResumeThread(cheatpromptthreadHandle);
				SetConsoleTitle(gameName);
				
				setforeground(White);
				setbackground(Black);
				
				if (pausemenu(true))
				{
					return;
				}
				
				SuspendThread(sizecheckthreadHandle);
				SuspendThread(cheatpromptthreadHandle);
				livetitle("Player 1", snakes[0].Active, "Player 2", snakes[1].Active);
				
				/*
				if (cheats[Fisa] != lastFisaState)
				{
					recreateboard(gameBoard[0], snake.Visual, berry, isSpecialShown, shownSpecial);
					lastFisaState = cheats[Fisa];
				}*/
			}
#ifdef DEBUG
			else if (key == Space)
			{
				while (getch() != Space);
			}
#endif
		}
		
		if (!snakes[0].Collision && !snakes[1].Collision && kbhit())
		{
			key = toupper(getch());
			
			if (!gotNewDirection[0] && IF_WASD(key) && key != (snakes[0].Head.Direction == 'W' ? 'S' : (snakes[0].Head.Direction == 'S' ? 'W' : (snakes[0].Head.Direction == 'A' ? 'D' : 'A'))))
			{
				// Assign new bend
				snakes[0].Head.Direction = snakes[0].Bend.Vector[snakes[0].Bend.ToAssign].Direction = key;
				snakes[0].Bend.Vector[snakes[0].Bend.ToAssign++].Position = snakes[0].Head.Position;
				
				if (snakes[0].Bend.ToAssign == SNAKE_LENGTH_MAX)
				{
					snakes[0].Bend.ToAssign = 0;
				}
				
				gotNewDirection[0] = true;
			}
			else if (key == -32 || key == 224)
			{
				key = getch();
				
				if (!snakes[1].Collision && IF_ARROW(key) && key != (snakes[1].Head.Direction == Up ? Down : (snakes[1].Head.Direction == Down ? Up : (snakes[1].Head.Direction == Left ? Right : Left))))
				{
					// Assign new bend
					snakes[1].Head.Direction = snakes[1].Bend.Vector[snakes[1].Bend.ToAssign].Direction = key;
					snakes[1].Bend.Vector[snakes[1].Bend.ToAssign++].Position = snakes[1].Head.Position;
					
					if (snakes[1].Bend.ToAssign == SNAKE_LENGTH_MAX)
					{
						snakes[1].Bend.ToAssign = 0;
					}
					
					gotNewDirection[1] = true;
				}
			}
			else if (key == Esc)
			{
				ResumeThread(sizecheckthreadHandle);
				ResumeThread(cheatpromptthreadHandle);
				SetConsoleTitle(gameName);
				
				setforeground(White);
				setbackground(Black);
				
				if (pausemenu(true))
				{
					return;
				}
				
				SuspendThread(sizecheckthreadHandle);
				SuspendThread(cheatpromptthreadHandle);
				livetitle("Player 1", snakes[0].Active, "Player 2", snakes[1].Active);
				/*
				if (cheats[Fisa] != lastFisaState)
				{
					recreateboard(gameBoard[0], snake.Visual, berry, isSpecialShown, shownSpecial);
					lastFisaState = cheats[Fisa];
				}*/
			}
#ifdef DEBUG
			else if (key == Space)
			{
				while (getch() != Space);
			}
#endif
		}
		
		for (s = 0; s <= 1; s++)
		{
			if (!snakes[s].Collision)
			{
				// Change snake position
				if (snakes[s].Head.Direction == CONTROLS[s][KUp])
				{
					snakes[s].Head.Position.Y--;
				}
				else if (snakes[s].Head.Direction ==  CONTROLS[s][KDown])
				{
					snakes[s].Head.Position.Y++;
				}
				else if (snakes[s].Head.Direction ==  CONTROLS[s][KLeft])
				{
					snakes[s].Head.Position.X--;
				}
				else if (snakes[s].Head.Direction ==  CONTROLS[s][KRight])
				{
					snakes[s].Head.Position.X++;
				}
				
				if (!borders)
				{
					// Move head to opposite console edge
					if (snakes[s].Head.Position.X < 0)
					{
						snakes[s].Head.Position.X = forcedConsoleSize.X;
					}
					else if (snakes[s].Head.Position.X > forcedConsoleSize.X)
					{
						snakes[s].Head.Position.X = 0;
					}
					else if (snakes[s].Head.Position.Y < 0)
					{
						snakes[s].Head.Position.Y = forcedConsoleSize.Y;
					}
					else if (snakes[s].Head.Position.Y > forcedConsoleSize.Y)
					{
						snakes[s].Head.Position.Y = 0;
					}
				}
				
				// Eat berry
				for (b = 0; b <= 1; b++)
				{
					if (snakes[s].Head.Position == berries[b].Position)
					{
						snakes[s].Active += (cheats[Hamster] ? CHEATS_HAMSTER : 1);
						livetitle("Player 1", snakes[0].Active, "Player 2", snakes[1].Active);
						
						do
						{
							newberry(&berries[b], true, gameBoard[0]);
						} while (berries[b].Position == berries[1 - b].Position);
					}
				}
				
				// Specials
				if (!isSpecialShown && SPECIAL_SPAWN)
				{
					// Create new special berry
					shownSpecial = (SPECIAL)(rand() % (sizeof(specials) / sizeof(specials[0])));
					
					newberry(&specials[shownSpecial], false, gameBoard[0]);
					isSpecialShown = true;
				}
				else if (isSpecialShown)
				{
					if (snakes[s].Head.Position == specials[shownSpecial].Position)
					{
						// Eat special berry
						switch (shownSpecial)
						{
							case Bonus:
								snakes[s].Active += SPECIAL_BONUS;
								livetitle("Player 1", snakes[0].Active, "Player 2", snakes[1].Active);
								break;
							
							case Mine:
								snakes[s].Collision = true;
								break;
							/*
							case Slowdown:
								// TODO: slowdown
								break;
							
							case Poison:
								// TODO: poison
								break;*/
						}
						
						isSpecialShown = false;
					}
					else if (SPECIAL_SPAWN)
					{
						// Remove special berry
						movecursor(specials[shownSpecial].Position);
						putchar(' ');
						
						isSpecialShown = false;
					}
				}
				
				// Collision
				if (!snakes[s].Collision)
				{
					snakes[s].Collision = borders && !(snakes[s].Head.Position >= COORD_ORIGIN && snakes[s].Head.Position <= forcedConsoleSize) || gameBoard[snakes[s].Head.Position.Y][snakes[s].Head.Position.X];
				}
			}
		}
		
		// Game end
		if ((snakes[0].Collision || snakes[0].Active == SNAKE_LENGTH_MAX) && (snakes[1].Collision || snakes[1].Active == SNAKE_LENGTH_MAX))
		{
			bool won[2] = { snakes[0].Active == SNAKE_LENGTH_MAX, snakes[1].Active == SNAKE_LENGTH_MAX };
			int scores[2] = { snakes[0].Active - SNAKE_LENGTH_START, snakes[1].Active - SNAKE_LENGTH_START};
			
			SetConsoleTitle(gameName);
			ResumeThread(sizecheckthreadHandle);
			ResumeThread(cheatpromptthreadHandle);
			
			setforeground(White);
			setbackground(Black);
			
			showscore(won, scores, sleep == SLEEP_EASY ? Easy : (sleep == SLEEP_MEDIUM ? Medium : (sleep == SLEEP_HARD ? Hard : Custom)), borders ? "Normal" : "Borderless");
			return;
		}
	}
}
