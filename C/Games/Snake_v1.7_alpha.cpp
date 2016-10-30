/*
	Name: Snake v1.7 'A better way'
	Copyright: (c) 2016 Marian Dolinský
	Author: Marian Dolinský
	Date: 27.01.16 14:23
	Description: Simple Snake game in console
*/

#define DEBUG

#define CHANGELOG_COLUMNS 50
const char GAMECHANGELOG[][CHANGELOG_COLUMNS] =
{
	{"1.7 'A better way':"},
	{"- Improved game engine"},
	{"- Fixed bug with right bottom corner"},
	{"- Code were optimized"},
	{"- Some bugs were fixed"},
	{"1.6 'FISA is your hero':"},
	{"- Added a little secret"},
	{"- Changed controls"},
	{"- Fixed screen flashing"},
	{"- Improved game performance"},
	{"- Some bugs were fixed"},
	{"1.5 'Make a way!':"},
	{"- Added borderless mode"},
	{"- Better game performance"},
	{"1.4 'It grows':"},
	{"- Game is now responsive designed"},
	{"- Code were optimized"},
	{"1.3 'Let me continue':"},
	{"- Hotseat continues if one player dies"},
	{"- Added changelog"},
	{"- Some bugs were fixed"},
	{"1.2 'Do it twice':"},
	{"- Added multiplayer"},
	{"- Code is more effective"},
	{"- Some bugs were fixed"},
	{"1.1 'When meowside flies':"},
	{"- Added menus"},
	{"- Some bugs were fixed"},
	{"1.0 'First release':"},
	{"- Only singleplayer"},
	{"- Without menus"}
};

#include "unigfcs.h"

#define STARTLENGHT 3
#define LENGHT 100

#define SNAKE 'O'
#define BERRY 'X'
#define NEUTRALKEY '!'

void snake(const int WAIT, const bool BORDERS);
void hotseat(const int WAIT, const bool BORDERS);

int main()
{
	initialize("Snake", "v1.7 'A better way'", "alpha", 79, 24, "0F");
	mainmenu();
	
	// Program should not get there
	system("cls");
	puts("Internal error has occured\nPress any key to close the game . . .");
	getch();
	
	return 1;
}

void controls()
{
#define CENTERING 35

	checkconsolesize();
	
	while(1)
	{
		system("cls");
		
		verticalcenter(8);
		center("CONTROLS:");
		printf("\n\n");
		
		center(CENTERING, "Player 1:          Arrow keys\n");
		center(CENTERING, "Player 2:          WASD\n");
		center(CENTERING, "Pause game:        ESC\n");
		center(CENTERING, "Menu navigation:   Arrow keys, ENTER, ESC");
		printf("\n\n");
		
		center("> Back  ");
		
		// Used to reduce screen refresh
		while(1)
		{
			temp = getch();
			
			if(temp == ENTER || temp == ESC)
			{
				return;
			}
			
			if(checkconsolesize())
			{
				break;
			}
		}
	}

#undef CENTERING
}

bool game(int difficulty, const bool HOTSEAT)
{
#define CENTERING 10

	checkconsolesize();
	
	int selection = 0;
	COORD cursorPosition;
	
	difficulty = (difficulty == 1 ? 200 : (difficulty == 2 ? 120 : 70));
	
	while(1)
	{
		system("cls");
		
		verticalcenter(6);
		center("CHOOSE GAME MODE:");
		printf("\n\n");
		
		center(CENTERING, "Normal\n");
		center(CENTERING, "Borderless\n");
		putch('\n');
		center(CENTERING, "Back");
		
		// Used to reduce screen refresh
		while(1)
		{
			MOVE_CURSOR(cursorPosition);
			putch(' ');
			
			cursorPosition.X = (consoleSize.X + 1 - 9) / 2 - 2;
			cursorPosition.Y = (consoleSize.Y + 1) / 2 + selection - (selection == 2 ? 0 : 1);
			
			MOVE_CURSOR(cursorPosition);
			putch('>');
			
			temp = getch();
			GET_ARROWS(temp);
			
			if((temp == ENTER && selection == 2) || temp == ESC)
			{
				return false;
			}
			else if(temp == ENTER)
			{
				if(!HOTSEAT)
				{
					snake(difficulty, selection == 0 ? true : false);
				}
				else
				{
					hotseat(difficulty, selection == 0 ? true : false);
				}
				
				return true;
			}
			else if(temp == UP && selection != 0)
			{
				selection--;
			}
			else if(temp == DOWN && selection != 2)
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

void snake(const int WAIT, const bool BORDERS)
{
	bool collision;
	char course[LENGHT], lastCourse[LENGHT];
	int active;
	COORD berry;
	COORD snake[LENGHT];
	
	system("cls");
	checkconsolesize();
	forcedConsoleSize = consoleSize;
	
	collision = false;
	active = STARTLENGHT;
	
	for(i = 0; i < LENGHT; i++)
	{
		snake[i].X = snake[i].Y = 0;
		course[i] = lastCourse[i] = NEUTRALKEY;
	}
	
	for(i = 0; i < active; i++)
	{
		snake[i].X = ((consoleSize.X + 1) / 2) - 1;
		snake[i].Y = ((consoleSize.Y + 1 - active) / 2) + i;
		course[i] = UP;
	}
	
	// Generate new coordinates for berry
	do
	{
		berry.X = rand() % (consoleSize.X + 1);
		berry.Y = rand() % (consoleSize.Y + 1);
		
		// Collision - new berry with snakes
		for(i = 0; i < active; i++)
		{
			if(berry == snake[i])
			{
				break;
			}
		}
	// Regenerate coordinates if there is a collision with some body
	} while(i != active);
	
	// Main game cycle
	while(1)
	{
		FISA_ACTION;
		
		// Print snake
		for(i = 0; i < active; i++)
		{
			MOVE_CURSOR(snake[i]);
			putch(SNAKE);
		}
		
		// Print berry
		MOVE_CURSOR(berry);
		putch(BERRY);
		
		// Set cursor position to 0,0
		RESET_CURSOR;
		
		// Copy course to lastCourse before new assignment of course[0]
		lastCourse[0] = course[0];
		
		for(i = 1; i < active; i++)
		{
			lastCourse[i] = course[i];
			course[i] = lastCourse[i - 1];
		}
		
		Sleep(WAIT);
		system("cls");
		
		// Get new course for head
		if(kbhit())
		{
			temp = getch();
			GET_ARROWS(temp);
			
			if(IF_ARROWS(temp) && temp != (course[0] == UP ? DOWN : (course[0] == DOWN ? UP : (course[0] == LEFT ? RIGHT : LEFT))))
			{
				course[0] = temp;
			}
			else if(temp == ESC)
			{
				if(pausemenu(false))
				{
					return;
				}
			}
		}
		
		for(i = 0; i < active; i++)
		{
			// Change coordinates
			if(course[i] == UP)
			{
				snake[i].Y--;
			}
			else if(course[i] == DOWN)
			{
				snake[i].Y++;
			}
			else if(course[i] == LEFT)
			{
				snake[i].X--;
			}
			else if(course[i] == RIGHT)
			{
				snake[i].X++;
			}
			
			// Move snake to opposite console edge
			if(!BORDERS)
			{
				if(snake[i].X < 0)
				{
					snake[i].X = consoleSize.X;
				}
				else if(snake[i].X > consoleSize.X)
				{
					snake[i].X = 0;
				}
				else if(snake[i].Y < 0)
				{
					snake[i].Y = consoleSize.Y;
				}
				else if(snake[i].Y > consoleSize.Y)
				{
					snake[i].Y = 0;
				}
			}
			
			// Collision - head with bodies
			if(i != 0)
			{
				if(snake[0] == snake[i])
				{
					collision = true;
					break;
				}
			}
		}
		
		// Collision - head with borders
		if(BORDERS)
		{
			if(snake[0].X < 0 || snake[0].Y < 0 || !(snake[0] <= consoleSize))
			{
				collision = true;
			}
		}
		
		// Eat berry
		if(snake[0] == berry)
		{
			// Create new snake body
			// Course does't have to be assigned here - it will be assigned from lastCourse in next cycle
			snake[active].X = snake[active - 1].X + (course[active - 1] == LEFT ? 1 : (course[active - 1] == RIGHT ? -1 : 0));
			snake[active].Y = snake[active - 1].Y + (course[active - 1] == UP ? 1 : (course[active - 1] == DOWN ? -1 : 0));
			
			active++;
			
			// Generate new coordinates for berry
			do
			{
				berry.X = rand() % (consoleSize.X + 1);
				berry.Y = rand() % (consoleSize.Y + 1);
				
				// Collision - new berry with snakes
				for(i = 0; i < active; i++)
				{
					if(berry == snake[i])
					{
						break;
					}
				}
			// Regenerate coordinates if there is a collision with some body
			} while(i != active);
		}
		
		// Game end
		if(collision || active == LENGHT)
		{
			showscore(active == LENGHT ? true : false, active, WAIT == 200 ? 1 : (WAIT == 120 ? 2 : 3), BORDERS ? "Normal" : "Borderless");
			return;
		}
	}
}

void hotseat(const int WAIT, const bool BORDERS)
{
	bool collision[2], gotNewCourse[2], won[2];
	int actualBerry;
	int active[2], score[2];
	char course0[LENGHT], course1[LENGHT], lastCourse0[LENGHT], lastCourse1[LENGHT];
	COORD berries[2], snake0[LENGHT], snake1[LENGHT];
	
	system("cls");
	checkconsolesize();
	forcedConsoleSize = consoleSize;
	
	collision[0] = collision[1] = false;
	won[0] = won[1] = false;
	active[0] = active[1] = STARTLENGHT;
	score[0] = score[1] = 0;
	
	for(i = 0; i < LENGHT; i++)
	{
		snake0[i].X = snake1[i].X = snake0[i].Y = snake1[i].Y = 0;
		course0[i] = course1[i] = lastCourse0[i] = lastCourse1[i] = NEUTRALKEY;
	}
	
	for(i = 0; i < active[0]; i++)
	{
		snake0[i].X = (consoleSize.X + 1) / 4;
		snake0[i].Y = ((consoleSize.Y + 1 - active[0]) / 2) + i;
		course0[i] = 'W';
	}
	
	for(i = 0; i < active[1]; i++)
	{
		snake1[i].X = (((consoleSize.X + 1) / 4) * 3) - 1;
		snake1[i].Y = ((consoleSize.Y + 1 - active[1]) / 2) + i;
		course1[i] = UP;
	}
	
	// Generate new coordinates for berry
	for(actualBerry = 0; actualBerry <= 1; actualBerry++)
	{
		do
		{
			berries[actualBerry].X = rand() % (consoleSize.X + 1);
			berries[actualBerry].Y = rand() % (consoleSize.Y + 1);
			
			// Collision - new berry with snake0
			for(i = 0; i < active[0]; i++)
			{
				if(berries[actualBerry] == snake0[i])
				{
					break;
				}
			}
			
			// Collision - new berry with snake1
			for(j = 0; j < active[1]; j++)
			{
				if(berries[actualBerry] == snake1[j])
				{
					break;
				}
			}
		// Regenerate coordinates for berry if there is collision with some body or with another berry
		} while(i != active[0] || j != active[1] || berries[actualBerry] == berries[actualBerry == 0 ? 1 : 0]);
	}
	
	// Main game cycle
	while(1)
	{
		FISA_ACTION;
		
		// Print snakes
		for(i = 0; i < active[0]; i++)
		{
			MOVE_CURSOR(snake0[i]);
			putch(SNAKE);
		}
	
		for(i = 0; i < active[1]; i++)
		{
			MOVE_CURSOR(snake1[i]);
			putch(SNAKE);
		}
		
		// Print berries
		MOVE_CURSOR(berries[0]);
		putch(BERRY);
		
		MOVE_CURSOR(berries[1]);
		putch(BERRY);
		
		// Set cursor position to 0,0
		RESET_CURSOR;
		
		// Copy course to lastCourse before new assign of heads
		if(!collision[0])
		{
			lastCourse0[0] = course0[0];
			
			for(i = 1; i < active[0]; i++)
			{
				lastCourse0[i] = course0[i];
				course0[i] = lastCourse0[i - 1];
			}
		}
		
		if(!collision[1])
		{
			lastCourse1[0] = course1[0];
			
			for(i = 1; i < active[1]; i++)
			{
				lastCourse1[i] = course1[i];
				course1[i] = lastCourse1[i - 1];
			}
		}
		
		Sleep(WAIT);
		system("cls");
		
		// Get new courses for heads
		gotNewCourse[0] = gotNewCourse[1] = false;
		
		if(kbhit())
		{
			temp = toupper(getch());
			GET_ARROWS(temp);
			
			if(!collision[0] && IF_WASD(temp) && temp != (course0[0] == 'W' ? 'S' : (course0[0] == 'S' ? 'W' : (course0[0] == 'A' ? 'D' : 'A'))))
			{
				course0[0] = temp;
				gotNewCourse[0] = true;
			}
			else if(!collision[1] && IF_ARROWS(temp) && temp != (course1[0] == UP ? DOWN : (course1[0] == DOWN ? UP : (course1[0] == LEFT ? RIGHT : LEFT))))
			{
				course1[0] = temp;
				gotNewCourse[1] = true;
			}
			else if(temp == ESC)
			{
				if(pausemenu(true))
				{
					return;
				}
			}
		}
		
		if(!collision[0] && !collision[1] && kbhit())
		{
			temp = toupper(getch());
			GET_ARROWS(temp);
			
			if(!gotNewCourse[0] && IF_WASD(temp) && temp != (course0[0] == 'W' ? 'S' : (course0[0] == 'S' ? 'W' : (course0[0] == 'A' ? 'D' : 'A'))))
			{
				course0[0] = temp;
			}
			else if(!gotNewCourse[1] && IF_ARROWS(temp) && temp != (course1[0] == UP ? DOWN : (course1[0] == DOWN ? UP : (course1[0] == LEFT ? RIGHT : LEFT))))
			{
				course1[0] = temp;
			}
			else if(temp == ESC)
			{
				if(pausemenu(true))
				{
					return;
				}
			}
		}
		
		for(i = 0; i < active[0]; i++)
		{
			// Change coordinates
			if(course0[i] == 'W')
			{
				snake0[i].Y--;
			}
			else if(course0[i] == 'S')
			{
				snake0[i].Y++;
			}
			else if(course0[i] == 'A')
			{
				snake0[i].X--;
			}
			else if(course0[i] == 'D')
			{
				snake0[i].X++;
			}
			
			// Move snake0 to opposite console edge
			if(!BORDERS)
			{
				if(snake0[i].X < 0)
				{
					snake0[i].X = consoleSize.X;
				}
				else if(snake0[i].X > consoleSize.X)
				{
					snake0[i].X = 0;
				}
				else if(snake0[i].Y < 0)
				{
					snake0[i].Y = consoleSize.Y;
				}
				else if(snake0[i].Y > consoleSize.Y)
				{
					snake0[i].Y = 0;
				}
			}
			
			// Collision - snake0 head with snake0 bodies
			if(i != 0)
			{
				if(snake0[0] == snake0[i])
				{
					collision[0] = true;
					break;
				}
			}
			
			// Collision - snake1 head with snake0 bodies
			if(!collision[1])
			{
				if(snake1[0] == snake0[i])
				{
					collision[0] = collision[1] = true;
					break;
				}
			}
		}
		
		for(i = 0; i < active[1]; i++)
		{
			// Change coordinates
			if(course1[i] == UP)
			{
				snake1[i].Y--;
			}
			else if(course1[i] == DOWN)
			{
				snake1[i].Y++;
			}
			else if(course1[i] == LEFT)
			{
				snake1[i].X--;
			}
			else if(course1[i] == RIGHT)
			{
				snake1[i].X++;
			}
			
			// Move snake1 to opposite console edge
			if(!BORDERS)
			{
				if(snake1[i].X < 0)
				{
					snake1[i].X = consoleSize.X;
				}
				else if(snake1[i].X > consoleSize.X)
				{
					snake1[i].X = 0;
				}
				else if(snake1[i].Y < 0)
				{
					snake1[i].Y = consoleSize.Y;
				}
				else if(snake1[i].Y > consoleSize.Y)
				{
					snake1[i].Y = 0;
				}
			}
			
			// Collision - snake1 head with snake1 bodies
			if(i != 0)
			{
				if(snake1[0] == snake1[i])
				{
					collision[1] = true;
					break;
				}
			}
			
			// Collision - snake0 head with snake1 bodies
			if(!collision[0])
			{
				if(snake0[0] == snake1[i])
				{
					collision[0] = collision[1] = true;
					break;
				}
			}
		}
		
		// Collision - heads with console borders
		if(BORDERS)
		{
			if(!collision[0] && (snake0[0].X < 0 || snake0[0].Y < 0 || !(snake0[0] <= consoleSize)))
			{
				collision[0] = true;
			}
			
			if(!collision[1] && (snake1[0].X < 0 || snake1[0].Y < 0 || !(snake1[0] <= consoleSize)))
			{
				collision[1] = true;
			}
		}
		
		// Eat berry
		if(!collision[0])
		{
			if(snake0[0] == berries[0] || snake0[0] == berries[1])
			{
				actualBerry = (snake0[0] == berries[0] ? 0 : 1);
				
				// Create new body
				// Course does't have to be assigned here. It will be assigned from lastCourse in next cycle
				snake0[active[0]].X = snake0[active[0] - 1].X + (course0[active[0] - 1] == 'A' ? 1 : (course0[active[0] - 1] == 'D' ? -1 : 0));
				snake0[active[0]].Y = snake0[active[0] - 1].Y + (course0[active[0] - 1] == 'W' ? 1 : (course0[active[0] - 1] == 'S' ? -1 : 0));
				
				active[0]++;
				
				// Generate new coordinates for berry
				do
				{
					berries[actualBerry].X = rand() % (consoleSize.X + 1);
					berries[actualBerry].Y = rand() % (consoleSize.Y + 1);
					
					// Collision - new berry with snake0
					for(i = 0; i < active[0]; i++)
					{
						if(berries[actualBerry] == snake0[i])
						{
							break;
						}
					}
					
					// Collision - new berry with snake1
					for(j = 0; j < active[1]; j++)
					{
						if(berries[actualBerry] == snake1[j])
						{
							break;
						}
					}
				// Regenerate coordinates for berry if there is collision with some body or with another berry
				} while(i != active[0] || j != active[1] || berries[actualBerry] == berries[actualBerry == 0 ? 1 : 0]);
			}
		}
		
		if(!collision[1])
		{
			if(snake1[0] == berries[0] || snake1[0] == berries[1])
			{
				actualBerry = (snake1[0] == berries[0] ? 0 : 1);
				
				// Create new body
				// Course does't have to be assigned here. It will be assigned from lastCourse in next cycle
				snake1[active[1]].X = snake1[active[1] - 1].X + (course1[active[1] - 1] == LEFT ? 1 : (course1[active[1] - 1] == RIGHT ? -1 : 0));
				snake1[active[1]].Y = snake1[active[1] - 1].Y + (course1[active[1] - 1] == UP ? 1 : (course1[active[1] - 1] == DOWN ? -1 : 0));
				
				active[1]++;
				
				// Generate new coordinates for berry
				do
				{
					berries[actualBerry].X = rand() % (consoleSize.X + 1);
					berries[actualBerry].Y = rand() % (consoleSize.Y + 1);
					
					// Collision - new berry with snake0
					for(i = 0; i < active[0]; i++)
					{
						if(berries[actualBerry] == snake0[i])
						{
							break;
						}
					}
					
					// Collision - new berry with snake1
					for(j = 0; j < active[1]; j++)
					{
						if(berries[actualBerry] == snake1[j])
						{
							break;
						}
					}
				// Regenerate coordinates for berry if there is collision with some body or with another berry
				} while(i != active[0] || j != active[1] || berries[actualBerry] == berries[actualBerry == 0 ? 1 : 0]);
			}
		}
		
		// Remove dead snakes
		if(collision[0] && active[0] != 0)
		{
			score[0] = active[0];
			active[0] = 0;
		}
		
		if(collision[1] && active[1] != 0)
		{
			score[1] = active[1];
			active[1] = 0;
		}
		
		// Game end
		if((collision[0] && collision[1]) || active[0] == LENGHT || active[1] == LENGHT)
		{
			if(score[0] == 0)
			{
				score[0] = active[0];
			}
			
			if(score[1] == 0)
			{
				score[1] = active[1];
			}
			
			if(active[0] == LENGHT)
			{
				won[0] = true;
			}
			
			if(active[1] == LENGHT)
			{
				won[1] = true;
			}
			
			showscore(won, score, WAIT == 200 ? 1 : (WAIT == 120 ? 2 : 3), BORDERS ? "Normal" : "Borderless");
			return;
		}
	}
}
