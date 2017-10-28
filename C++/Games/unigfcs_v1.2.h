//
//
//	Universal game functions v1.2
//	(c) Marian Dolinský 2015
//
//
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <time.h>

#define ENTER 13
#define ESC 27
#define SPACE 32

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define IF_ARROWS(a) (a == UP || a == DOWN || a == LEFT || a == RIGHT)
#define IF_WASD(a) (a == 'W' || a == 'S' || a == 'A' || a == 'D')

#define GET_ARROWS(key) if(key == 0 || key == 224) key = getch()

#define MAJOR 1
#define MINOR 2

int i, j, k, min, temp;
int consoleWidth, consoleHeight, minimalConsoleWidth, minimalConsoleHeight, forcedConsoleWidth, forcedConsoleHeight;
char gameName[10], gameVersion[30], gameBranch[6];

void initialize();
void changeconsolesize();
void checkconsolesize();
bool forceconsolesize();
void center(const int STRLEN);
void center(const char TEXT[]);
void center(const int CUSTSTRLEN, const char TEXT[]);
void verticalcenter(const int ROWS);
void repeat(const char CHAR, const int COUNT);
void mainmenu();
bool difficulty(const bool HOTSEAT);
void about();
void changelog();
bool pausemenu(const bool HOTSEAT);
bool quitmessage(const int ACTION, const bool PLAYING, const bool HOTSEAT);
void showscore(const bool WON, const int SCORE, const int DIFFICULTY, const char GAMEMODE[]);
void showscore(const bool WON[], const int SCORE[], const int DIFFICULTY, const char GAMEMODE[]);
void customfont(const char STRG[]);

// These are in each program
void controls();
void gamechangelog();
bool game(int difficulty, const bool HOTSEAT);

void initialize()
{
	checkconsolesize();
	
	// Hide the cursor
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = false;
	SetConsoleCursorInfo(consoleHandle, &info);
	
	system("color 0F");
	srand(time(0));
	
	return;
}

void changeconsolesize()
{
	// Get console sizes and assign consoleWidth and consoleHeight
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	
	return;
}

void checkconsolesize()
{
	changeconsolesize();
    
    while(consoleWidth < minimalConsoleWidth || consoleHeight < minimalConsoleHeight)
    {
    	system("cls");
    	
    	printf("Your console size is %dx%d\n", consoleWidth, consoleHeight);
    	printf("Minimal required size is %dx%d\n", minimalConsoleWidth, minimalConsoleHeight);
    	printf("Change the size and press any key to continue . . .\n");
    	printf("Or press ENTER to quit the game . . .");
    	
    	temp = getch();
    	
    	if(temp == ENTER)
    	{
    		system("cls");
    		printf("Are you sure you want to quit the game?\n");
    		printf("Press ENTER to quit the game or ESC to return . . .\n");
    		
    		temp = getch();
    		
	    	if(temp == ENTER)
	    	{
	    		exit(0);
			}
		}
    	
    	changeconsolesize();
	}
	
	return;
}

bool forceconsolesize()
{
	changeconsolesize();
	
	while(consoleWidth != forcedConsoleWidth || consoleHeight != forcedConsoleHeight)
	{
		system("cls");
    	
    	printf("You cannot change console size during game!\n");
    	printf("Your console size is %dx%d\n", consoleWidth, consoleHeight);
    	printf("Change the size back to %dx%d and press any key to continue . . .\n", forcedConsoleWidth, forcedConsoleHeight);
    	printf("Or press ENTER to go to main menu . . .");
    	
    	temp = getch();
    	
    	if(temp == ENTER)
    	{
    		system("cls");
    		printf("Are you sure you want to go to main menu?\n");
    		printf("Your game progress will be lost!\n");
    		printf("Press ENTER to go to main menu or ESC to return . . .\n");
    		
    		temp = getch();
    		
	    	if(temp == ENTER)
	    	{
	    		return true;
			}
		}
    	
    	changeconsolesize();
	}
	
    system("cls");
	return false;
}

// WARNING!!! Do not use more than one '\n' at the end of the TEXT[] string
// If so every \n will increase string length
void center(const int STRLEN)
{
	repeat(' ', (consoleWidth - STRLEN) / 2);
	return;
}

void center(const char TEXT[])
{
	repeat(' ', (consoleWidth - strlen(TEXT)) / 2);
	printf("%s", TEXT);
	return;
}

void center(const int CUSTSTRLEN, const char TEXT[])
{
	center(CUSTSTRLEN);
	printf("%s", TEXT);
	
	return;
}

void verticalcenter(const int ROWS)
{
	repeat('\n', (consoleHeight - ROWS) / 2);
	return;
}

void repeat(const char CHAR, const int COUNT)
{
	for(int i = 0; i < COUNT; i++)
	{
		printf("%c", CHAR);
	}
	
	return;
}

void mainmenu()
{
#define CENTERING 14

	checkconsolesize();
	
	int selection = 1;
	
	while(1)
	{
		system("cls");
		
		verticalcenter(13);
		customfont(gameName);
		printf("\n\n\n");
		
		center(CENTERING, selection == 1 ? "> Start game\n" : "  Start game\n");
		center(CENTERING, selection == 2 ? "> Hotseat\n" : "  Hotseat\n");
		center(CENTERING, selection == 3 ? "> Controls\n" : "  Controls\n");
		center(CENTERING, selection == 4 ? "> About\n" : "  About\n");
		printf("\n");
		center(CENTERING, selection == 5 ? "> Quit game" : "  Quit game");
		
		// Used to reduce screen refresh
		while(1)
		{
			temp = getch();
			GET_ARROWS(temp);
			
			if((temp == ENTER && selection == 5) || temp == ESC)
			{
				quitmessage(5, false, false);
				break;
			}
			else if(temp == ENTER)
			{
				if(selection == 1)
				{
					difficulty(false);
				}
				else if(selection == 2)
				{
					difficulty(true);
				}
				else if(selection == 3)
				{
					controls();
				}
				else
				{
					about();
				}
				
				break;
			}
			else if(temp == UP && selection != 1)
			{
				selection--;
				break;
			}
			else if(temp == DOWN && selection != 5)
			{
				selection++;
				break;
			}
		}
		
		checkconsolesize();
	}

#undef CENTERING
}

bool difficulty(const bool HOTSEAT)
{
#define CENTERING 10

	checkconsolesize();
	
	int selection = 2;
	
	while(1)
	{
		system("cls");
		
		verticalcenter(7);
		center("CHOOSE DIFFICULTY:");
		printf("\n\n");
		
		center(CENTERING, selection == 1 ? "> Easy\n" : "  Easy\n");
		center(CENTERING, selection == 2 ? "> Medium\n" : "  Medium\n");
		center(CENTERING, selection == 3 ? "> Hard\n" : "  Hard\n");
		printf("\n");
		center(CENTERING, selection == 4 ? "> Back" : "  Back");
		
		// Used to reduce screen refresh
		while(1)
		{
			temp = getch();
			GET_ARROWS(temp);
			
			if((temp == ENTER && selection == 4) || temp == ESC)
			{
				return false;
			}
			else if(temp == ENTER)
			{
				if(game(selection, HOTSEAT) == true)
				{
					return true;
				}
				
				break;
			}
			else if(temp == UP && selection != 1)
			{
				selection--;
				break;
			}
			else if(temp == DOWN && selection != 4)
			{
				selection++;
				break;
			}
		}
		
		checkconsolesize();
	}

#undef CENTERING
}

void about()
{
#define CENTERING 24

	// Must be set to Czech because of 'ý'
	setlocale(LC_ALL, "Czech");
	
	checkconsolesize();
	
	int selection = 3;
	
	while(1)
	{
		system("cls");
		
		verticalcenter(11);
		center("ABOUT:");
		printf("\n\n");
		
		center(CENTERING);
		printf("%s %s\n", gameName, gameVersion);
		center(CENTERING);
		printf("Current branch: %s\n", gameBranch);
		center(CENTERING);
		printf("Created using unigfcs.h v%d.%d\n", MAJOR, MINOR);
		center(CENTERING);
    	printf("Console size: %dx%d\n\n", consoleWidth, consoleHeight);
		center(CENTERING, "(c) Marian Dolinský 2015\n\n");
		
		center(15, selection == 1 ? "> Changelog\n" : "  Changelog\n");
		center(15, selection == 2 ? "> Changelog (unigfcs.h)\n" : "  Changelog (unigfcs.h)\n");
		center(15, selection == 3 ? "> Back" : "  Back");
		
		// Used to reduce screen refresh
		while(1)
		{
			temp = getch();
			GET_ARROWS(temp);
			
			if((temp == ENTER && selection == 3) || temp == ESC)
			{
				// Reset back to english
				setlocale(LC_ALL, "English");
				
				return;
			}
			else if(temp == ENTER)
			{
				if(selection == 1)
				{
					gamechangelog();
				}
				else
				{
					changelog();
				}
				
				selection = 3;
				break;
			}
			else if(temp == UP && selection != 1)
			{
				selection--;
				break;
			}
			else if(temp == DOWN && selection != 3)
			{
				selection++;
				break;
			}
		}
		
		checkconsolesize();
	}

#undef CENTERING
}

void changelog()
{
#define CENTERING 37

	checkconsolesize();
	
	system("cls");
	
	verticalcenter(15);
	center("CHANGELOG (UNIGFCS.H):");
	printf("\n\n");
	
	center(CENTERING + 5, "1.2:\n");
	center(CENTERING, "- Added macros for ENTER, ESC and SPACE\n");
	center(CENTERING, "- Added unigfcs.h changelog\n");
	center(CENTERING, "- Improved responsive design\n");
	center(CENTERING, "- Some bugs were fixed\n");
	center(CENTERING + 5, "1.1:\n");
	center(CENTERING, "- Code were optimized\n");
	center(CENTERING, "- Some bugs were fixed\n");
	center(CENTERING + 5, "1.0:\n");
	center(CENTERING, "- First release\n");
	center(CENTERING, "- Universal game menus\n");
	center(CENTERING, "- Custom font\n");
	printf("\n");
	
	center("> Back  ");

	while(1)
	{
		temp = getch();
		checkconsolesize();
		
		if(temp == ENTER || temp == ESC)
		{
			return;
		}
	}

#undef CENTERING
}

bool pausemenu(const bool HOTSEAT)
{
#define CENTERING 12

	checkconsolesize();
	
	int selection = 1;
	
	while(1)
	{
		system("cls");
		
		verticalcenter(7);
		center("PAUSE MENU:");
		printf("\n\n");
		
		center(CENTERING, selection == 1 ? "> Resume\n" : "  Resume\n");
		center(CENTERING, selection == 2 ? "> Restart\n" : "  Restart\n");
		center(CENTERING, selection == 3 ? "> Controls\n" : "  Controls\n");
		center(CENTERING, selection == 4 ? "> Go to main menu\n" : "  Go to main menu\n");
		center(CENTERING, selection == 5 ? "> Quit game" : "  Quit game");
		
		// Used to reduce screen refresh
		while(1)
		{
			temp = toupper(getch());
			GET_ARROWS(temp);
			
			if((temp == ENTER && selection == 1) || temp == ESC)
			{
				system("cls");
				
				if(forceconsolesize() == true)
				{
					return true;
				}
				
				return false;
			}
			else if(temp == ENTER)
			{
				if(selection == 3)
				{
					controls();
				}
				else
				{
					if(quitmessage(selection, true, HOTSEAT) == true)
					{
						return true;
					}
				}
				
				break;
			}
			else if(temp == UP && selection != 1)
			{
				selection--;
				break;
			}
			else if(temp == DOWN && selection != 5)
			{
				selection++;
				break;
			}
			else if(temp == 'F' && getch() == 'I' && getch() == 'S' && getch() == 'A')
			{
				system("color 0A");
			}
		}
		
		checkconsolesize();
	}

#undef CENTERING
}

bool quitmessage(const int ACTION, const bool PLAYING, const bool HOTSEAT)
{
	// return true - caller will return too
	// ACTION code depends on selection in pausemenu()
	// ACTION 2 - restart game
	// ACTION 4 - go to main menu
	// ACTION 5 - quit game
	
	checkconsolesize();
	
	int selection = 2;
	
	while(1)
	{
		system("cls");
		
		verticalcenter(PLAYING == true ? 4 : 3);
		center(ACTION == 2 ? "Are you sure you want to restart the game?" : (ACTION == 4 ?  "Are you sure you want to go to main menu?" : "Are you sure you want to quit the game?"));
		
		if(PLAYING == true)
		{
			printf("\n");
			center("Your game progress will be lost!");
		}
		
		printf("\n\n");
		center(20, selection == 1 ? "> Yes" : "  Yes");
		
		repeat(' ', 9);
		printf(selection == 2 ? "> No" : "  No");
		
		// Used to reduce screen refresh
		while(1)
		{
			temp = getch();
			GET_ARROWS(temp);
			
			if((temp == ENTER && selection == 2) || temp == ESC)
			{
				return false;
			}
			else if(temp == ENTER)
			{
				if(ACTION == 2)
				{
					if(difficulty(HOTSEAT) == false)
					{
						return false;
					}
				}
				else if(ACTION == 4)
				{
					return true;
				}
				else
				{
					exit(0);
				}
			}
			else if(temp == LEFT && selection != 1)
			{
				selection--;
				break;
			}
			else if(temp == RIGHT && selection != 2)
			{
				selection++;
				break;
			}
		}
		
		checkconsolesize();
	}
}

void showscore(const bool WON, const int SCORE, const int DIFFICULTY, const char GAMEMODE[])
{
	checkconsolesize();
	
	verticalcenter(13);
	
	if(WON == true)
	{
		customfont("YOU WON");
	}
	else
	{
		customfont("GAME OVER");
	}
	
	printf("\n\n\n");
	center(14);
	printf("Your score: %d\n\n", SCORE);
	
	center(18);
	printf("Difficulty: %s\n", DIFFICULTY == 1 ? "Easy" : (DIFFICULTY == 2 ? "Medium" : (DIFFICULTY == 3 ? "Hard" : "Custom")));
	
	center(18);
	printf("Game mode: %s\n\n", GAMEMODE);
	
	center("> Back  ");
	
	while(1)
	{
		temp = getch();
		checkconsolesize();
		
		if(temp == ENTER || temp == ESC)
		{
			return;
		}
	}
}

void showscore(const bool WON[], const int SCORE[], const int DIFFICULTY, const char GAMEMODE[])
{
	checkconsolesize();
	
	verticalcenter(15);
	
	if(WON[0] == true || WON[1] == true)
	{
		customfont("YOU WON");
	}
	else
	{
		customfont("GAME OVER");
	}
	
	printf("\n\n\n");
	
	center(27);
	printf(WON[0] == true ? "Player 1 won with score %d\n" : "Player 1 died with score %d\n", SCORE[0]);
	
	center(27);
	printf(WON[1] == true ? "Player 2 won with score %d\n" : "Player 2 died with score %d\n\n", SCORE[1]);
	
	center(18);
	printf("Difficulty: %s\n", DIFFICULTY == 1 ? "Easy" : (DIFFICULTY == 2 ? "Medium" : (DIFFICULTY == 3 ? "Hard" : "Custom")));
	
	center(18);
	printf("Game mode: %s\n\n", GAMEMODE);
	
	center("> Back  ");

	while(1)
	{
		temp = getch();
		checkconsolesize();
		
		if(temp == ENTER || temp == ESC)
		{
			return;
		}
	}
}

// WARNING!!! Prints only alphabet and space
void customfont(const char STRG[])
{
	// center assigned to 4 because of four spaces on right and left side
	// strlen(STRG) - 1 because of spaces between word
	// int centering = 4 + strlen(STRG) - 1;
	int centering = 3 + strlen(STRG);
	char text[strlen(STRG)];
	
	strcpy(text, STRG);
	
	// Rewrite text as upper case
	for(i = 0; i < strlen(text); i++)
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
		else if(text[i] == 'V')
		{
			centering += 6;
		}
		else
		{
			centering += 7;
		}
	}
	
	for(i = 0; i < 5; i++)
	{
		center(centering);
		
		for(j = 4; j > i; j--)
		{
			printf(" ");
		}
		
		for(j = 0; j < strlen(text); j++)
		{
			if(text[j] == ' ')
			{
				printf("  ");
			}
			else if(text[j] == 'A')
			{
				if(i == 0 || i == 2)
				{
					printf("///////");
				}
				else
				{
					printf("//   //");
				}
			}
			else if(text[j] == 'B')
			{
				if(i == 1 || i == 3)
				{
					printf("//   //");
				}
				else
				{
					printf("////// ");
				}
			}
			else if(text[j] == 'C')
			{
				if(i == 0 || i == 4)
				{
					printf("///////");
				}
				else
				{
					printf("//     ");
				}
			}
			else if(text[j] == 'D')
			{
				if(i == 0 || i == 4)
				{
					printf("////// ");
				}
				else
				{
					printf("//   //");
				}
			}
			else if(text[j] == 'E')
			{
				if(i == 2)
				{
					printf("/////  ");
				}
				else if(i == 0 || i == 4)
				{
					printf("///////");
				}
				else
				{
					printf("//     ");
				}
			}
			else if(text[j] == 'F')
			{
				if(i == 0)
				{
					printf("///////");
				}
				else if(i == 2)
				{
					printf("/////  ");
				}
				else
				{
					printf("//     ");
				}
			}
			else if(text[j] == 'G')
			{
				if(i == 1)
				{
					printf("//     ");
				}
				else if(i == 2)
				{
					printf("// ////");
				}
				else if(i == 3)
				{
					printf("//   //");
				}
				else
				{
					printf("///////");
				}
			}
			else if(text[j] == 'H')
			{
				if(i != 2)
				{
					printf("//   //");
				}
				else
				{
					printf("///////");
				}
			}
			else if(text[j] == 'I')
			{
				printf("//");
			}
			else if(text[j] == 'J')
			{
				if(i < 3)
				{
					printf("     //");
				}
				else if(i == 3)
				{
					printf("//   //");
				}
				else
				{
					printf("///////");
				}
			}
			else if(text[j] == 'K')
			{
				if(i == 2)
				{
					printf("///    ");
				}
				else if(i == 0 || i == 4)
				{
					printf("//   //");
				}
				else
				{
					printf("// //  ");
				}
			}
			else if(text[j] == 'L')
			{
				if(i < 4)
				{
					printf("//     ");
				}
				else
				{
					printf("///////");
				}
			}
			else if(text[j] == 'M')
			{
				if(i == 1)
				{
					printf("///  ///");
				}
				else if(i == 2)
				{
					printf("// // //");
				}
				else
				{
					printf("//    //");
				}
			}
			else if(text[j] == 'N')
			{
				if(i == 1)
				{
					printf("///   //");
				}
				else if(i == 2)
				{
					printf("// // //");
				}
				else if(i == 3)
				{
					printf("//   ///");
				}
				else
				{
					printf("//    //");
				}
			}
			else if(text[j] == 'O')
			{
				if(i == 0 || i == 4)
				{
					printf("///////");
				}
				else
				{
					printf("//   //");
				}
			}
			else if(text[j] == 'P')
			{
				if(i == 0 || i == 2)
				{
					printf("///////");
				}
				else if(i == 1)
				{
					printf("//   //");
				}
				else
				{
					printf("//     ");
				}
			}
			else if(text[j] == 'Q')
			{
				if(i == 0)
				{
					printf("/////// ");
				}
				else if(i == 3)
				{
					printf("//  /// ");
				}
				else if(i == 4)
				{
					printf("////////");
				}
				else
				{
					printf("//   // ");
				}
			}
			else if(text[j] == 'R')
			{
				if(i == 0)
				{
					printf("///////");
				}
				else if(i == 2)
				{
					printf("////// ");
				}
				else
				{
					printf("//   //");
				}
			}
			else if(text[j] == 'S')
			{
				if(i == 1)
				{
					printf("//     ");
				}
				else if(i == 3)
				{
					printf("     //");
				}
				else
				{
					printf("///////");
				}
			}
			else if(text[j] == 'T')
			{
				if(i != 0)
				{
					printf("   //   ");
				}
				else
				{
					printf("////////");
				}
			}
			else if(text[j] == 'U')
			{
				if(i < 4)
				{
					printf("//   //");
				}
				else
				{
					printf("///////");
				}
			}
			else if(text[j] == 'V')
			{
				if(i < 4)
				{
					printf("//  //");
				}
				else
				{
					printf("  //  ");
				}
			}
			else if(text[j] == 'W')
			{
				if(i == 0)
				{
					printf("//    //");
				}
				else if(i == 4)
				{
					printf(" //  // ");
				}
				else
				{
					printf("// // //");
				}
			}
			else if(text[j] == 'X')
			{
				if(i == 2)
				{
					printf("   //   ");
				}
				else if(i == 0 || i == 4)
				{
					printf("//    //");
				}
				else
				{
					printf(" //  // ");
				}
			}
			else if(text[j] == 'Y')
			{
				if(i > 1)
				{
					printf("   //   ");
				}
				else if(i == 0)
				{
					printf("//    //");
				}
				else
				{
					printf(" //  // ");
				}
			}
			else if(text[j] == 'Z')
			{
				if(i == 1)
				{
					printf("     //");
				}
				else if(i == 2)
				{
					printf("  ///  ");
				}
				else if(i == 3)
				{
					printf("//     ");
				}
				else
				{
					printf("///////");
				}
			}
		
			if(j < strlen(text) - 1)
			{
				printf(" ");
			}
			
		}
		
		printf("\n");
	}
}
