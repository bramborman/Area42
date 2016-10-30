//
//
//	Snake v1.6 'FISA is your hero'
//	(c) Marian Dolinský 2015
//
//
#include "unigfcs_v1.2.h"

#define COUNT 100

void snake(const int WAIT, const bool BORDERS);
void hotseat(const int WAIT, const bool BORDERS);

int main()
{
	strcpy(gameName, "Snake");
	strcpy(gameVersion, "v1.6 'FISA is here'");
	strcpy(gameBranch, "stable");
	minimalConsoleWidth = 80;
	minimalConsoleHeight = 25;
	
	initialize();
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

	checkconsolesize();
	
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

void gamechangelog()
{
#define CENTERING 37
#define MAXROWS 15

	checkconsolesize();
	
	const char CHANGELOG[][50] =
	{
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
	
	int row = 0;
	
	while(1)
	{
		system("cls");
		
		verticalcenter(MAXROWS + 4);
		center("CHANGELOG:");
		printf("\n\n");
		
		for(i = 0; i < MAXROWS; i++)
		{
			center(CENTERING + (CHANGELOG[row + i][0] == '1' ? 5 : 0));
			printf("%s\n", CHANGELOG[row + i]);
		}
		
		printf("\n");
		center("> Back  ");
		
		// Used to reduce screen refresh
		while(1)
		{
			temp = getch();
			GET_ARROWS(temp);
			
			if(temp == ENTER || temp == ESC)
			{
				return;
			}
			else if(temp == UP && row != 0)
			{
				row--;
				break;
			}
			// 7 is number of CHANGELOG rows - 1 - MAXROWS
			else if(temp == DOWN && row != (sizeof(CHANGELOG) / sizeof(CHANGELOG[0])) - MAXROWS)
			{
				row++;
				break;
			}
		}
		
		checkconsolesize();
	}

#undef CENTERING
#undef MAXROWS
}

bool game(int difficulty, const bool HOTSEAT)
{
#define CENTERING 14

	checkconsolesize();
	
	int selection = 1;
	
	difficulty = (difficulty == 1 ? 200 : (difficulty == 2 ? 120 : 70));
	
	while(1)
	{
		system("cls");
		
		verticalcenter(6);
		center("CHOOSE GAME MODE:");
		printf("\n\n");
		
		center(CENTERING, selection == 1 ? "> Normal\n" : "  Normal\n");
		center(CENTERING, selection == 2 ? "> Borderless\n" : "  Borderless\n");
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
					snake(difficulty, selection == 1 ? true : false);
				}
				else
				{
					hotseat(difficulty, selection == 1 ? true : false);
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

void snake(const int WAIT, const bool BORDERS)
{
	checkconsolesize();
	forcedConsoleWidth = consoleWidth;
	forcedConsoleHeight = consoleHeight;
	
	bool collision;
	int overflow, inRow, active;
	int x[COUNT + 1], y[COUNT + 1], xTemp[COUNT + 1], order[COUNT + 1];
	char course[COUNT], lastCourse[COUNT];	
	
	// First run assignment
	system("cls");
	
	collision = false;
	active = 3;
	
	for(i = 0; i < COUNT + 1; i++)
	{
		x[i] = y[i] = consoleWidth;
		order[i] = i;
		
		if(i != COUNT)
		{
			course[i] = 'X';
			lastCourse[i] = 'X';
		}
	}
	
	for(i = 0; i < active; i++)
	{
		x[i] = (consoleWidth / 2) - 1;
		y[i] = i + ((consoleHeight - active) / 2);
		course[i] = UP;
	}
	
	// Generate new x and y for berry
	do
	{
		x[COUNT] = rand() % consoleWidth;
		y[COUNT] = rand() % consoleHeight;
		
		// Determine if there is a collision with some body
		for(i = 0; i < active; i++)
		{
			if(x[COUNT] == x[i] && y[COUNT] == y[i])
			{
				break;
			}
		}
	// Regenerate x and y for berry if there is a collision with some body or when berry is in right bottom corner
	// Console size must be decreased by 1 because of body (x axis) and first line (y axis)
	} while(i != active || (x[COUNT] == consoleWidth - 1 && y[COUNT] == consoleHeight - 1));
	
	// Main game cycle
	while(1)
	{
		// Arrange by y
		for(i = 0; i < COUNT + 1; i++)
		{
			min = i;
			
			// Find smallest y and write its index to min
			for(j = i + 1; j < COUNT + 1; j++)
			{
				if(y[j] < y[min])
				{
					min = j;
				}
			}
			
			if(min != i)
			{
				temp = y[i];
				y[i] = y[min];
				y[min] = temp;
				
				temp = x[i];
				x[i] = x[min];
				x[min] = temp;
				
				temp = order[i];
				order[i] = order[min];
				order[min] = temp;
			}
		}
		
		// Print snake
		for(i = 0; i < active + 1; i++)
		{
			// Continue if there were more bodies in previous row
			if(y[i] == y[i - 1] && i != 0)
			{
				continue;
			}
			
			// Reset values
			inRow = 0;
			
			for(j = 0; j < COUNT + 1; j++)
			{
				xTemp[j] = consoleWidth;
			}
			
			// Copy every x with y that equals y[i]
			for(j = i; j < active + 1; j++)
			{
				if(y[i] == y[j])
				{
					xTemp[j] = x[j];
					inRow++;
					
					continue;
				}
				
				break;
			}
			
			// Arrange xTemp
			for(j = 0; j < COUNT + 1; j++)
			{
				min = j;
				
				// Find smallest xTemp and write its index to min
				for(k = j + 1; k < COUNT + 1; k++)
				{				
					if(xTemp[k] < xTemp[min])
					{
						min = k;
					}
				}
				
				if(min != j)
				{
					temp = xTemp[j];
					xTemp[j] = xTemp[min];
					xTemp[min] = temp;
				}
			}
			
			// Get to relative row
			repeat('\n', (i == 0 ? y[i] : y[i] - y[i - 1]) - (overflow == consoleWidth && i != 0 ? 1 : 0));
			
			// Print body
			overflow = 0;
			
			for(j = 0; j < inRow; j++)
			{
				temp = (j == 0 ? xTemp[j] : (xTemp[j] - xTemp[j - 1] - 1));
				
				repeat(' ', temp);
				printf("O");
				
				overflow += temp + 1;
			}
		}
		
		// Arrange by order
		for(i = 0; i < COUNT + 1; i++)
		{
			min = i;
			
			// Find smallest order and write its index to min
			for(j = i + 1; j < COUNT + 1; j++)
			{
				if(order[j] < order[min])
				{
					min = j;
				}
			}
			
			if(min != i)
			{
				temp = y[i];
				y[i] = y[min];
				y[min] = temp;
				
				temp = x[i];
				x[i] = x[min];
				x[min] = temp;
				
				temp = order[i];
				order[i] = order[min];
				order[min] = temp;
			}
		}
		
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
		if(kbhit() == true)
		{
			temp = getch();
			GET_ARROWS(temp);
			
			if(IF_ARROWS(temp) && temp != (course[0] == UP ? DOWN : (course[0] == DOWN ? UP : (course[0] == LEFT ? RIGHT : LEFT))))
			{
				course[0] = temp;
			}
			else if(temp == ESC)
			{
				if(pausemenu(false) == true)
				{
					return;
				}
			}
		}
		
		// Change positions + Move snake to opposite console edge + Collision between head and bodies
		for(i = 0; i < active; i++)
		{
			x[i] += (course[i] == LEFT ? -1 : (course[i] == RIGHT ? 1 : 0));
			y[i] += (course[i] == UP ? -1 : (course[i] == DOWN ? 1 : 0));
			
			// Move snake to opposite console edge
			if(BORDERS == false)
			{
				if(x[i] < 0)
				{
					x[i] = consoleWidth - 1;
				}
				else if(x[i] > consoleWidth - 1)
				{
					x[i] = 0;
				}
				else if(y[i] < 0)
				{
					y[i] = consoleHeight - 1;
				}
				else if(y[i] > consoleHeight - 1)
				{
					y[i] = 0;
				}
			}
			
			// Collision - head with bodies
			if(i != 0)
			{
				if(x[0] == x[i] && y[0] == y[i])
				{
					collision = true;
					break;
				}
			}
		}
		
		// Collision - head with borders
		// Console size must be decreased by 1 because of body (x axis) and first line (y axis)
		if(BORDERS == true)
		{
			if(x[0] < 0 || x[0] > consoleWidth - 1 || y[0] < 0 || y[0] > consoleHeight - 1)
			{
				collision = true;
			}
		}
		
		// Eat berry
		if(x[0] == x[COUNT] && y[0] == y[COUNT])
		{
			// Create new body
			// Course does't have to be assigned here - it will be assigned from lastCourse in next cycle
			x[active] = x[active - 1] + (course[active - 1] == LEFT ? 1 : (course[active - 1] == RIGHT ? -1 : 0));
			y[active] = y[active - 1] + (course[active - 1] == UP ? 1 : (course[active - 1] == DOWN ? -1 : 0));
			
			active++;
			
			// Generate new x and y for berry
			do
			{
				x[COUNT] = rand() % consoleWidth;
				y[COUNT] = rand() % consoleHeight;
				
				// Collision - new berry with snake
				for(i = 0; i < active; i++)
				{
					if(x[COUNT] == x[i] && y[COUNT] == y[i])
					{
						break;
					}
				}
			// Regenerate x and y for berry if there is a collision with some body or when berry is in right bottom corner
			// Console size must be decreased by 1 because of body (x axis) and first line (y axis)
			} while(i != active || (x[COUNT] == consoleWidth - 1 && y[COUNT] == consoleHeight - 1));
		}
		
		// Game end
		if(collision == true || active == COUNT)
		{
			showscore(active == COUNT ? true : false, active, WAIT == 200 ? 1 : (WAIT == 120 ? 2 : 3), BORDERS == true ? "Normal" : "Borderless");
			return;
		}
	}
}

void hotseat(const int WAIT, const bool BORDERS)
{
	checkconsolesize();
	forcedConsoleWidth = consoleWidth;
	forcedConsoleHeight = consoleHeight;
	
	bool collision[2], gotNewCourse[2], won[2];
	int overflow, inRow, actualBerry;
	int x[COUNT + 2], y[COUNT + 2], xTemp[COUNT + 2], order[COUNT + 2], active[2], score[2];
	char course[COUNT], lastCourse[COUNT];	
	
	// First run assignment
	system("cls");
	
	collision[0] = collision[1] = false;
	won[0] = won[1] = false;
	active[0] = active[1] = 3;
	score[0] = score[1] = 0;
	
	for(i = 0; i < COUNT + 2; i++)
	{
		x[i] = y[i] = consoleWidth;
		order[i] = i;
		
		if(i < COUNT)
		{
			course[i] = 'X';
			lastCourse[i] = 'X';
		}
	}
	
	for(i = 0; i < active[0]; i++)
	{
		x[i] = consoleWidth / 4;
		y[i] = i + ((consoleHeight - active[0]) / 2);
		course[i] = 'W';
	}
	
	for(i = COUNT / 2; i < (COUNT / 2) + active[1]; i++)
	{
		x[i] = ((consoleWidth / 4) * 3) - 1;
		y[i] = i + ((consoleHeight - active[1]) / 2) - (COUNT / 2);
		course[i] = UP;
	}
	
	// Generate new x and y for berry
	for(actualBerry = 0; actualBerry <= 1; actualBerry++)
	{
		do
		{
			x[COUNT + actualBerry] = rand() % consoleWidth;
			y[COUNT + actualBerry] = rand() % consoleHeight;
			
			// Collision - new berry with snakes
			for(i = 0; i < (COUNT / 2) + active[1]; i++)
			{
				if(y[COUNT + actualBerry] == y[i])
				{
					break;
				}
				
				// Skip some cells to get to second snake
				if(i == active[0] - 1)
				{
					// Must be (COUNT / 2) - 1 instead of (COUNT / 2) because i++ at the end of this cycle
					i = (COUNT / 2) - 1;
				}
			}
		// Regenerate x and y for berry if there is collision with some body or with another berry or when berry is in bottom right corner
		// Console size must be decreased by 1 because of body (x axis) and first line (y axis)
		} while(i != (COUNT / 2) + active[1] || (x[COUNT + actualBerry] == consoleWidth - 1 && y[COUNT + actualBerry] == consoleHeight - 1) || y[COUNT + actualBerry] == y[COUNT + (actualBerry == 0 ? 1 : 0)]);
	}
	
	// Main game cycle
	while(1)
	{
		// Arrange by y
		for(i = 0; i < COUNT + 2; i++)
		{
			min = i;
			
			// Find smallest y and write its index to min
			for(j = i + 1; j < COUNT + 2; j++)
			{
				if(y[j] < y[min])
				{
					min = j;
				}
			}
			
			if(min != i)
			{
				temp = y[i];
				y[i] = y[min];
				y[min] = temp;
				
				temp = x[i];
				x[i] = x[min];
				x[min] = temp;
				
				temp = order[i];
				order[i] = order[min];
				order[min] = temp;
			}
		}
		
		// Print snakes
		for(i = 0; i < active[0] + active[1] + 2; i++)
		{
			// Continue if there were more bodies in previous row
			if(y[i] == y[i - 1] && i != 0)
			{
				continue;
			}
			
			// Reset values
			inRow = 0;
			
			for(j = 0; j < COUNT + 2; j++)
			{
				xTemp[j] = consoleWidth;
			}
			
			// Copy every x with y that equals y[i]
			for(j = i; j < active[0] + active[1] + 2; j++)
			{
				if(y[i] == y[j])
				{
					xTemp[j] = x[j];
					inRow++;
					
					continue;
				}
				
				break;
			}
			
			// Arrange xTemp
			for(j = 0; j < COUNT + 2; j++)
			{
				min = j;
				
				// Find smallest xTemp and write its index to min
				for(k = j + 1; k < COUNT + 2; k++)
				{				
					if(xTemp[k] < xTemp[min])
					{
						min = k;
					}
				}
				
				if(min != j)
				{
					temp = xTemp[j];
					xTemp[j] = xTemp[min];
					xTemp[min] = temp;
				}
			}
			
			// Get to relative row
			repeat('\n', (i == 0 ? y[i] : y[i] - y[i - 1]) - (overflow == consoleWidth && i != 0 ? 1 : 0));
			
			// Print body
			overflow = 0;
			
			for(j = 0; j < inRow; j++)
			{
				temp = (j == 0 ? xTemp[j] : (xTemp[j] - xTemp[j - 1] - 1));
				
				repeat(' ', temp);
				printf("O");
				
				overflow += temp + 1;
			}
		}
		
		// Arrange by order
		for(i = 0; i < COUNT + 2; i++)
		{
			min = i;
			
			// Find smallest order and write its index to min
			for(j = i + 1; j < COUNT + 2; j++)
			{
				if(order[j] < order[min])
				{
					min = j;
				}
			}
			
			if(min != i)
			{
				temp = y[i];
				y[i] = y[min];
				y[min] = temp;
				
				temp = x[i];
				x[i] = x[min];
				x[min] = temp;
				
				temp = order[i];
				order[i] = order[min];
				order[min] = temp;
			}
		}
		
		// Copy course to lastCourse before new assign of heads
		if(collision[0] == false)
		{
			lastCourse[0] = course[0];
			
			for(i = 1; i < active[0]; i++)
			{
				lastCourse[i] = course[i];
				course[i] = lastCourse[i - 1];
			}
		}
		
		if(collision[1] == false)
		{
			lastCourse[COUNT / 2] = course[COUNT / 2];
			
			for(i = (COUNT / 2) + 1; i < (COUNT / 2) + active[1]; i++)
			{
				lastCourse[i] = course[i];
				course[i] = lastCourse[i - 1];
			}
		}
		
		Sleep(WAIT);
		system("cls");
		
		// Get new courses for heads
		gotNewCourse[0] = gotNewCourse[1] = false;
		
		if(kbhit() == true)
		{
			temp = toupper(getch());
			GET_ARROWS(temp);
			
			if(collision[0] == false && IF_WASD(temp) && temp != (course[0] == 'W' ? 'S' : (course[0] == 'S' ? 'W' : (course[0] == 'A' ? 'D' : 'A'))))
			{
				course[0] = temp;
				gotNewCourse[0] = true;
			}
			else if(collision[1] == false && IF_ARROWS(temp) && temp != (course[COUNT / 2] == UP ? DOWN : (course[COUNT / 2] == DOWN ? UP : (course[COUNT / 2] == LEFT ? RIGHT : LEFT))))
			{
				course[COUNT / 2] = temp;
				gotNewCourse[1] = true;
			}
			else if(temp == ESC)
			{
				if(pausemenu(true) == true)
				{
					return;
				}
			}
		}
		
		if(collision[0] == false && collision[1] == false && kbhit() == true)
		{
			temp = toupper(getch());
			GET_ARROWS(temp);
			
			if(gotNewCourse[0] == false && IF_WASD(temp) && temp != (course[0] == 'W' ? 'S' : (course[0] == 'S' ? 'W' : (course[0] == 'A' ? 'D' : 'A'))))
			{
				course[0] = temp;
			}
			else if(gotNewCourse[1] == false && IF_ARROWS(temp) && temp != (course[COUNT / 2] == UP ? DOWN : (course[COUNT / 2] == DOWN ? UP : (course[COUNT / 2] == LEFT ? RIGHT : LEFT))))
			{
				course[COUNT / 2] = temp;
			}
			else if(temp == ESC)
			{
				if(pausemenu(true) == true)
				{
					return;
				}
			}
		}
		
		// Change positions + Move snake to opposite console edge + Collision between snakes heads and all bodies
		if(collision[0] == false)
		{
			for(i = 0; i < active[0]; i++)
			{
				x[i] += (course[i] == 'A' ? -1 : (course[i] == 'D' ? 1 : 0));
				y[i] += (course[i] == 'W' ? -1 : (course[i] == 'S' ? 1 : 0));
				
				// Move first snake to opposite console edge
				if(BORDERS == false)
				{
					if(x[i] < 0)
					{
						x[i] = consoleWidth - 1;
					}
					else if(x[i] > consoleWidth - 1)
					{
						x[i] = 0;
					}
					else if(y[i] < 0)
					{
						y[i] = consoleHeight - 1;
					}
					else if(y[i] > consoleHeight - 1)
					{
						y[i] = 0;
					}
				}
				
				// Collision - first snake head with first snake bodies
				if(i != 0)
				{
					if(x[0] == x[i] && y[0] == y[i])
					{
						collision[0] = true;
						break;
					}
				}
				
				// Collision - second snake head with first snake bodies
				if(collision[1] == false)
				{
					if(x[COUNT / 2] == x[i] && y[COUNT / 2] == y[i])
					{
						collision[0] = collision[1] = true;
						break;
					}
				}
			}
		}
		
		if(collision[1] == false)
		{
			for(i = COUNT / 2; i < (COUNT / 2) + active[1]; i++)
			{
				x[i] += (course[i] == LEFT ? -1 : (course[i] == RIGHT ? 1 : 0));
				y[i] += (course[i] == UP ? -1 : (course[i] == DOWN ? 1 : 0));
				
				// Move second snake to opposite console edge
				if(BORDERS == false)
				{
					if(x[i] < 0)
					{
						x[i] = consoleWidth - 1;
					}
					else if(x[i] > consoleWidth - 1)
					{
						x[i] = 0;
					}
					else if(y[i] < 0)
					{
						y[i] = consoleHeight - 1;
					}
					else if(y[i] > consoleHeight - 1)
					{
						y[i] = 0;
					}
				}
				
				// Collision - second snake head with second snake bodies
				if(i != COUNT / 2)
				{
					if(x[COUNT / 2] == x[i] && y[COUNT / 2] == y[i])
					{
						collision[1] = true;
						break;
					}
				}
				
				// Collision - first snake head with second snake bodies
				if(collision[0] == false)
				{
					if(x[0] == x[i] && y[0] == y[i])
					{
						collision[0] = collision[1] = true;
						break;
					}
				}
			}
		}
		
		// Collision - heads with console borders
		// Console size must be decreased by 1 because of body (x axis) and first line (y axis)
		if(BORDERS == true)
		{
			if(collision[0] == false && (x[0] < 0 || x[0] > consoleWidth - 1 || y[0] < 0 || y[0] > consoleHeight - 1))
			{
				collision[0] = true;
			}
			
			if(collision[1] == false && (x[COUNT / 2] < 0 || x[COUNT / 2] > consoleWidth - 1 || y[COUNT / 2] < 0 || y[COUNT / 2] > consoleHeight - 1))
			{
				collision[1] = true;
			}
		}
		
		// Eat berry
		if(collision[0] == false)
		{
			for(actualBerry = 0; actualBerry <= 1; actualBerry++)
			{
				if(x[0] == x[COUNT + actualBerry] && y[0] == y[COUNT + actualBerry])
				{
					// Create new body
					// Course does't have to be assigned here. It will be assigned from lastCourse in next cycle
					x[active[0]] = x[active[0] - 1] + (course[active[0] - 1] == 'A' ? 1 : (course[active[0] - 1] == 'D' ? -1 : 0));
					y[active[0]] = y[active[0] - 1] + (course[active[0] - 1] == 'W' ? 1 : (course[active[0] - 1] == 'S' ? -1 : 0));
					
					active[0]++;
					
					// Generate new x and y for berry
					do
					{
						x[COUNT + actualBerry] = rand() % consoleWidth;
						y[COUNT + actualBerry] = rand() % consoleHeight;
						
						// Collision - new berry with snakes
						for(i = 0; i < (COUNT / 2) + active[1]; i++)
						{
							if(y[COUNT + actualBerry] == y[i])
							{
								break;
							}
							
							// Skip some cells to get to second snake
							if(i == active[0] - 1)
							{
								// Must be (COUNT / 2) - 1 instead of (COUNT / 2) because i++ at the end of this cycle
								i = (COUNT / 2) - 1;
							}
						}
					// Regenerate x and y for berry if there is collision with some body or with another berry or when berry is in bottom right corner
					// Console size must be decreased by 1 because of body (x axis) and first line (y axis)
					} while(i != (COUNT / 2) + active[1] || (x[COUNT + actualBerry] == consoleWidth - 1 && y[COUNT + actualBerry] == consoleHeight - 1) || y[COUNT + actualBerry] == y[COUNT + (actualBerry == 0 ? 1 : 0)]);
				}
			}
		}
		
		if(collision[1] == false)
		{
			for(actualBerry = 0; actualBerry <= 1; actualBerry++)
			{
				if(x[COUNT / 2] == x[COUNT + actualBerry] && y[COUNT / 2] == y[COUNT + actualBerry])
				{
					// Create new body
					// Course does't have to be assigned here. It will be assigned from lastCourse in next cycle
					temp = (COUNT / 2) + active[1];
					
					x[temp] = x[temp - 1] + (course[temp - 1] == LEFT ? 1 : (course[temp - 1] == RIGHT ? -1 : 0));
					y[temp] = y[temp - 1] + (course[temp - 1] == UP ? 1 : (course[temp - 1] == DOWN ? -1 : 0));
					
					active[1]++;
					
					// Generate new x and y for berry
					do
					{
						x[COUNT + actualBerry] = rand() % consoleWidth;
						y[COUNT + actualBerry] = rand() % consoleHeight;
						
						// Collision - new berry with snakes
						for(i = 0; i < (COUNT / 2) + active[1]; i++)
						{
							if(y[COUNT + actualBerry] == y[i])
							{
								break;
							}
							
							// Skip some cells to get to second snake
							if(i == active[0] - 1)
							{
								// Must be (COUNT / 2) - 1 instead of (COUNT / 2) because i++ at the end of this cycle
								i = (COUNT / 2) - 1;
							}
						}
					// Regenerate x and y for berry if there is collision with some body or with another berry or when berry is in bottom right corner
					// Console size must be decreased by 1 because of body (x axis) and first line (y axis)
					} while(i != (COUNT / 2) + active[1] || (x[COUNT + actualBerry] == consoleWidth - 1 && y[COUNT + actualBerry] == consoleHeight - 1) || y[COUNT + actualBerry] == y[COUNT + (actualBerry == 0 ? 1 : 0)]);
				}
			}
		}
		
		// Remove dead snakes
		// Does not do this if there is only one dead snake to save some time
		if(collision[0] == true && collision[1] == false && active[0] != 0)
		{
			for(i = 0; i < active[0]; i++)
			{
				x[i] = y[i] = consoleWidth;
				course[i] = 'X';
			}
			
			score[0] = active[0];
			active[0] = 0;
		}
		
		if(collision[1] == true && collision[0] == false && active[1] != 0)
		{
			for(i = COUNT / 2; i < (COUNT / 2) + active[1]; i++)
			{
				x[i] = y[i] = consoleWidth;
				course[i] = 'X';
			}
			
			score[1] = active[1];
			active[1] = 0;
		}
		
		// Game end
		if((collision[0] == true && collision[1] == true) || active[0] == COUNT / 2 || active[1] == COUNT / 2)
		{
			if(score[0] == 0)
			{
				score[0] = active[0];
			}
			
			if(score[1] == 0)
			{
				score[1] = active[1];
			}
			
			if(active[0] == COUNT / 2)
			{
				won[0] = true;
			}
			
			if(active[1] == COUNT / 2)
			{
				won[1] = true;
			}
			
			showscore(won, score, WAIT == 200 ? 1 : (WAIT == 120 ? 2 : 3), BORDERS == true ? "Normal" : "Borderless");
			return;
		}
	}
}
