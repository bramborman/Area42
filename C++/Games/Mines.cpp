//
//
//	Mines v1.0 'Ehm OK'
//	(c) Marian Dolinský 2015
//
//
#include "unigfcs_v1.2.h"

#define BLANK '.'
#define MINE 207
#define MARK 184

int minesCount, rows, columns;

void generateminefield(unsigned char *mineField);
void mines(const bool HARDCORE);

int main()
{
	strcpy(gameName, "Mines");
	strcpy(gameVersion, "v1.0 'Ehm OK'");
	strcpy(gameBranch, "alpha");
	minimalConsoleWidth = 80;
	minimalConsoleHeight = 25;
	
	initialize();
	/*rows = 10;
	columns = 10;
	minesCount = 10;
	
	game(1, false);
	return 0;*/
	mainmenu();
	
	// Program should not get there
	system("cls");
	printf("Internal error has occured\nPress any key to close the game . . .");
	getch();
	
	return 1;
}

void controls()
{
#define CENTERING 35

	system("cls");
	
	verticalcenter(8);
	center("CONTROLS:");
	printf("\n\n");
	
	center(CENTERING, "Player 1:          WASD\n");
	center(CENTERING, "Player 2:          8456\n");
	center(CENTERING, "Pause game:        ESC\n");
	center(CENTERING, "Menu navigation:   WASD, ENTER, ESC");
	printf("\n\n");
	
	center("> Back  ");

	while(1)
	{	
		temp = getch();
		
		if(temp == ENTER || temp == ESC)
		{
			return;
		}
	}

#undef CENTERING
}

void gamechangelog()
{
#define CENTERING 37

	system("cls");
	
	verticalcenter(6);
	center("CHANGELOG:");
	printf("\n\n");
	
	center(CENTERING + 5, "1.0 'Ehm OK':\n");
	center(CENTERING, "- First release\n");
	printf("\n");
	
	center("> Back  ");

	while(1)
	{	
		temp = getch();
		
		if(temp == ENTER || temp == ESC)
		{
			return;
		}
	}

#undef CENTERING
}

bool game(int difficulty, const bool HOTSEAT)
{
#define CENTERING 14

	checkconsolesize();
	
	int selection = 1;
	
	rows = (difficulty == 1 ? 10 : 17);
	columns = (difficulty == 1 ? 10 : (difficulty == 2 ? 20 : 50));
	minesCount = (difficulty == 1 ? 10 : (difficulty == 2 ? 100 : 200));
	
	while(1)
	{
		system("cls");
		
		verticalcenter(6);
		center("CHOOSE GAME MODE:");
		printf("\n\n");
		
		center(CENTERING, selection == 1 ? "> Normal\n" : "  Normal\n");
		center(CENTERING, selection == 2 ? "> Hardcore\n" : "  Hardcore\n");
		printf("\n");
		center(CENTERING, selection == 3 ? "> Back" : "  Back");
		
		// Used to reduce screen refresh
		while(1)
		{
			temp = getch();
			GET_ARROWS(temp);
			checkconsolesize();
			
			if((temp == ENTER && selection == 3) || temp == ESC)
			{
				return false;
			}
			else if(temp == ENTER)
			{
				if(HOTSEAT == false)
				{
					mines(selection == 1 ? false : true);
				}
				else
				{
					//hotseat(difficulty, selection == 1 ? true : false);
				}
				
				return true;
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
	}

#undef CENTERING
}

void generateminefield(unsigned char *mineField)
{
	unsigned char *address;
	
	for(i = 0; i < minesCount; i++)
	{
		do
		{
			address = mineField + (columns * (rand() % rows)) + (rand() % columns);
			
		// Collision - new mine with another mines
		} while(*address == MINE);
		
		*address = MINE;
	}
	
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < columns; j++)
		{
			if(*(mineField + (columns * i) + j) != MINE)
			{
				temp = 0;
				
				// For pass through y - 1 to y + 1 (i represents y)
				for(k = -1; k <= 1; k++)
				{
					// Continue if i + k points out of mineField in y axis
					if((i == 0 && k == -1) || (i == rows - 1 && k == 1))
					{
						continue;
					}
					
					// For pass through x - 1 to x + 1 (j represents x)
					for(int l = -1; l <= 1; l++)
					{
						// Continue if j + l points out of mineField in x axis
						if((j == 0 && l == -1) || (j == columns - 1 && l == 1))
						{
							continue;
						}
						
						if(*(mineField + (columns * (i + k)) + (j + l)) == MINE)
						{
							temp++;
						}
					}
				}
				
				if(temp != 0)
				{
					*(mineField + (columns * i) + j) = temp + 48;
				}
			}
		}
	}
}

void mines(const bool HARDCORE)
{
	checkconsolesize();
	/*forcedConsoleWidth = consoleWidth;
	forcedConsoleHeight = consoleHeight;*/
	
	bool explosion;
	int selectionY, selectionX, marked, rightMarked, remaining;
	unsigned char mineField[rows][columns], shownField[rows][columns];
	
	// First run assignment
	explosion = false;
	selectionY = selectionX = marked = rightMarked = 0;
	
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < columns; j++)
		{
			mineField[i][j] = 0;
			shownField[i][j] = BLANK;
		}
	}
	
	// Assign mineField
	generateminefield(mineField[0]);
	
	// Main game cycle
	while(1)
	{
		checkconsolesize();
		system("cls");
		
		remaining = minesCount - marked;
		temp = (remaining >= 1000 || remaining <= -100 ? 0 : (remaining >= 100 || remaining <= -10 ? 1 : (remaining >= 10 || remaining <= -1 ? 2 : 3)));
		
		printf("\n");
		repeat(' ', consoleWidth - 22);
		printf("Remaining mines: ");
		repeat(' ', temp);
		printf("%d ", remaining);
		
		// rows + 7 (not rows + 4) beacuse of Remaining mines counter on second line
		verticalcenter(rows + 7);
		center(columns);
		
		for(i = 0; i < columns; i++)
		{
			printf(selectionX == i ? "\xC2" : " ");
		}
		
		printf("\n");
		center(columns + 4);
		printf(" \xDA");
		repeat('\xC4', columns);
		printf("\xBF\n");
		
		for(i = 0; i < rows; i++)
		{
			center(columns + 4, selectionY == i ? "\xC3\xB3" : " \xB3");
			
			for(j = 0; j < columns; j++)
			{
				printf("%c", shownField[i][j]);
			}
			
			printf(selectionY == i ? "\xB3\xB4\n" : "\xB3\n");
		}
		
		center(columns + 4);
		
		printf(" \xC0");
		repeat('\xC4', columns);
		printf("\xD9\n");
		
		center(columns);
		
		for(i = 0; i < columns; i++)
		{
			printf(selectionX == i ? "\xC1" : " ");
		}
		printf("\nmarked:%d rightMarked:%d", marked, rightMarked);
		if(explosion == true)
		{
			printf("\n");
			center("You lose!\n");
			center("Press any key to continue . . .");
			getch();
			
			return;
		}
		
		// Used to reduce screen refresh
		while(1)
		{
			temp = getch();
			GET_ARROWS(temp);
			checkconsolesize();
			
			if(temp == UP && selectionY != 0)
			{
				selectionY--;
				break;
			}
			else if(temp == DOWN && selectionY != rows - 1)
			{
				selectionY++;
				break;
			}
			else if(temp == LEFT && selectionX != 0)
			{
				selectionX--;
				break;
			}
			else if(temp == RIGHT && selectionX != columns - 1)
			{
				selectionX++;
				break;
			}
			else if(temp == ENTER)
			{
#define SHOWN shownField[selectionY][selectionX]

				if(SHOWN != MARK && SHOWN != '?')
				{
					if(mineField[selectionY][selectionX] != MINE)
					{
						if(HARDCORE == false)
						{
							printf("fak");
							getchar();
							
						}
						else
						{
							SHOWN = mineField[selectionY][selectionX];
						}
					}
					else
					{
						for(i = 0; i < rows; i++)
						{
							for(j = 0; j < columns; j++)
							{
								if(shownField[i][j] != MARK && mineField[i][j] == MINE)
								{
									shownField[i][j] = MINE;
								}
								else if(shownField[i][j] == MARK && mineField[i][j] != MINE)
								{
									shownField[i][j] = 'x';
								}
							}
						}
						
						explosion = true;
					}
					
					break;
				}
			}
			else if(temp == SPACE)
			{
				if(SHOWN == BLANK || SHOWN == MARK || SHOWN == '?')
				{
					SHOWN = (SHOWN == BLANK ? MARK : (SHOWN == MARK ? '?' : BLANK));
					marked += (SHOWN == MARK ? 1 : (SHOWN == '?' ? -1 : 0));
					
					if(mineField[selectionY][selectionX] == MINE)
					{
						rightMarked += (SHOWN == MARK ? 1 : (SHOWN == '?' ? -1 : 0));
					}
				
					break;
				}
#undef SHOWN
			}
			else if(temp == ESC)
			{
				if(pausemenu(false) == true)
				{
					return;
				}
				
				break;
			}
		}
	}
}
