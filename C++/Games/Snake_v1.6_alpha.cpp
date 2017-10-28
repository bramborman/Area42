//
//
//	Snake v1.6 'FISA is your hero'
//	(c) Marian Dolinský 2015
//
//
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "unigfcs.h"

const int COUNT = 100;

void snake(const int WAIT, const bool BORDERS);
void hotseat(const int WAIT, const bool BORDERS);

int main()
{
	strcpy(gamename, "Snake");
	strcpy(gameversion, "v1.6 'FISA is your hero'");
	strcpy(gamebranch, "alpha");
	minimalconsolewidth = 80;
	minimalconsoleheight = 25;
	
	initialize();
	mainmenu();
	
	// Program should not get to there
	printf("Internal error has occured\nPress any key to close the game . . .");
	getch();
	
	return 1;
}

void controls()
{
	const int CENTERING = 35;
	
	system("cls");
	
	repeat('\n', verticalcenter(8));
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
		
		// 13 - carriage return (ENTER) 27 - ESC
		if(temp == 13 || temp == 27)
		{
			return;
		}
	}
}

void changelog()
{
	const int MAXROWS = 15;
	const int CENTERING = 37;
	const int VERTICALCENTER = verticalcenter(MAXROWS + 4);
	const char CHANGELOG[][50] =
	{
		{"1.6 'FISA is your hero':"},
		{"- Added a little secret"},
		{"- Better game performance"},
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
		
		repeat('\n', VERTICALCENTER);
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
			
			if(temp >= 97 && temp <= 122)
			{
				temp -= 32;
			}
			
			// 13 - carriage return (ENTER) 27 - ESC
			if(temp == 13 || temp == 27)
			{
				return;
			}
			else if(temp == 'W' && row != 0)
			{
				row--;
				break;
			}
			// 7 is number of CHANGELOG rows - 1 - MAXROWS
			else if(temp == 'S' && row != sizeof CHANGELOG / sizeof CHANGELOG[0] - MAXROWS)
			{
				row++;
				break;
			}
		}
	}
}

bool game(int difficulty, const bool HOTSEAT)
{
	const int CENTERING = 14;
	const int VERTICALCENTER = verticalcenter(6);
	int selection = 1;
	
	difficulty = (difficulty == 1 ? 200 : (difficulty == 2 ? 120 : 70));
	
	while(1)
	{
		system("cls");
		
		repeat('\n', VERTICALCENTER);
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
			
			if(temp >= 97 && temp <= 122)
			{
				temp -= 32;
			}
			
			// 13 - carriage return (ENTER) 27 - ESC
			if((temp == 13 && selection == 3) || temp == 27)
			{
				return false;
			}
			else if(temp == 13)
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
			else if(temp == 'W' && selection != 1)
			{
				selection--;
				break;
			}
			else if(temp == 'S' && selection != 3)
			{
				selection++;
				break;
			}
		}
	}
}

void snake(const int WAIT, const bool BORDERS)
{
	bool collision;
	int yRelative, overflow, inRow, active;
	int x[COUNT + 1], y[COUNT + 1], xTemp[COUNT + 1], order[COUNT + 1];
	char course[COUNT], histCourse[COUNT];	
	
	// First-run reset
	system("cls");
	
	collision = false;
	active = 3;
	
	for(i = 0; i < COUNT + 1; i++)
	{
		x[i] = y[i] = consolewidth + 1;
		order[i] = i;
		
		if(i != COUNT)
		{
			course[i] = 'X';
			histCourse[i] = 'X';
		}
	}
	
	for(i = 0; i < active; i++)
	{
		x[i] = (consolewidth / 2) - 1;
		y[i] = i + ((consoleheight - active) / 2);
		course[i] = 'W';
	}
	
	// Generate new x and y for berry
	do
	{
		x[COUNT] = rand() % consolewidth;
		y[COUNT] = rand() % consoleheight;
		
		// Determine if there is collision with some body
		for(i = 0; i < active; i++)
		{
			if(x[COUNT] == x[i] && y[COUNT] == y[i])
			{
				break;
			}
		}
	// Generate new x and y for berry if there is collision with some body or when berry is in right bottom corner
	// Console size must be decreased by 1 because of body (X axis) and first line (Y axis)
	} while(i != active || (x[COUNT] == consolewidth - 1 && y[COUNT] == consoleheight - 1));
	
	// Main game cycle
	while(1)
	{
		// Arrange by Y
		for(i = 0; i < COUNT + 1; i++)
		{
			min = i;
			
			// Find smallest Y and write its index to min
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
				
				temp = course[i];
				course[i] = course[min];
				course[min] = temp;
				
				temp = order[i];
				order[i] = order[min];
				order[min] = temp;
			}
		}
		
		// Print snake
		for(i = 0; i < active + 1; i++)
		{
			// Continue if there were more bodies in previous row
			if((y[i] == y[i - 1]) && !(y[0] == 0 && i == 0))
			{
				continue;
			}
			
			// Reset values
			inRow = 0;
			
			for(j = 0; j < COUNT + 1; j++)
			{
				xTemp[j] = consolewidth + 1;
			}
			
			// Assign relative positions
			yRelative = (i == 0 ? y[i] : (y[i] - y[i - 1]));
			
			for(j = 0; j < active + 1; j++)
			{
				if(y[i] == y[j])
				{
					xTemp[j] = x[j];
					inRow++;
				}
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
			
			// Get to yRelative row
			repeat('\n', yRelative - (overflow == consolewidth && i != 0 ? 1 : 0));
			
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
		
		Sleep(WAIT);
		system("cls");
		
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
				
				temp = course[i];
				course[i] = course[min];
				course[min] = temp;
				
				temp = order[i];
				order[i] = order[min];
				order[min] = temp;
			}
		}
		
		// Copy course to histCourse before new assign of course[0]
		for(i = 0; i < active; i++)
		{
			histCourse[i] = course[i];
		}
		
		// Get new course for head
		if(kbhit() == true)
		{
			temp = getch();
			
			if(temp >= 97 && temp <= 122)
			{
				temp -= 32;
			}
			
			if((temp == 'W' || temp == 'A' || temp == 'S' || temp == 'D') && temp != (course[0] == 'W' ? 'S' : (course[0] == 'S' ? 'W' : (course[0] == 'A' ? 'D' : 'A'))))
			{
				course[0] = temp;
			}
			else if(temp == 27)
			{
				if(pausemenu(false) == true)
				{
					return;
				}
			}
		}
		
		// Change positions
		x[0] += (course[0] == 'A' ? -1 : (course[0] == 'D' ? 1 : 0));
		y[0] += (course[0] == 'W' ? -1 : (course[0] == 'S' ? 1 : 0));
		
		for(i = 1; i < active; i++)
		{
			course[i] = histCourse[i - 1];
			
			x[i] += (course[i] == 'A' ? -1 : (course[i] == 'D' ? 1 : 0));
			y[i] += (course[i] == 'W' ? -1 : (course[i] == 'S' ? 1 : 0));
		}
		
		// Collision with console borders
		// Console size must be decreased by 1 because of body (X axis) and first line (Y axis)
		if(BORDERS == true)
		{
			if(x[0] < 0 || x[0] > consolewidth - 1 || y[0] < 0 || y[0] > consoleheight - 1)
			{
				collision = true;
			}
		}
		// Moving snake to opposite console edge
		else
		{
			for(i = 0; i < active; i++)
			{
				if(x[i] < 0)
				{
					x[i] = consolewidth - 1;
				}
				else if(x[i] > consolewidth - 1)
				{
					x[i] = 0;
				}
				else if(y[i] < 0)
				{
					y[i] = consoleheight - 1;
				}
				else if(y[i] > consoleheight - 1)
				{
					y[i] = 0;
				}
			}
		}
		
		// Eating berry
		if(x[0] == x[COUNT] && y[0] == y[COUNT])
		{
			// Create new body
			// Course does't have to be assigned here. It will be assigned from histCourse in next cycle
			x[active] = x[active - 1] + (course[active - 1] == 'A' ? 1 : (course[active - 1] == 'D' ? -1 : 0));
			y[active] = y[active - 1] + (course[active - 1] == 'W' ? 1 : (course[active - 1] == 'S' ? -1 : 0));
			
			active++;
			
			// Generate new x and y for berry
			do
			{
				x[COUNT] = rand() % consolewidth;
				y[COUNT] = rand() % consoleheight;
				
				// Determine if there is collision with some body
				for(i = 0; i < active; i++)
				{
					if(x[COUNT] == x[i] && y[COUNT] == y[i])
					{
						break;
					}
				}
			// Generate new x and y for berry if there is collision with some body or when berry is in right bottom corner
			// Console size must be decreased by 1 because of body (X axis) and first line (Y axis)
			} while(i != active || (x[COUNT] == consolewidth - 1 && y[COUNT] == consoleheight - 1));
		}
		
		// Collision between head and bodies
		for(i = 1; i < active; i++)
		{
			if(x[0] == x[i] && y[0] == y[i])
			{
				collision = true;
				break;
			}
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
	bool collision[2], gotNewCourse[2], won[2];
	int yRelative, overflow, inRow, actualBerry;
	int x[COUNT + 2], y[COUNT + 2], xTemp[COUNT + 2], order[COUNT + 2], active[2], score[2];
	char course[COUNT], histCourse[COUNT];	
	
	// First-run reset
	system("cls");
	
	collision[0] = collision[1] = false;
	won[0] = won[1] = false;
	active[0] = active[1] = 3;
	score[0] = score[1] = 0;
	
	for(i = 0; i < COUNT + 2; i++)
	{
		x[i] = y[i] = consolewidth + 1;
		order[i] = i;
		
		if(i < COUNT)
		{
			course[i] = 'X';
			histCourse[i] = 'X';
		}
	}
	
	for(i = 0; i < active[0]; i++)
	{
		x[i] = consolewidth / 4;
		y[i] = i + ((consoleheight - active[0]) / 2);
		course[i] = 'W';
	}
	
	for(i = COUNT / 2; i < (COUNT / 2) + active[1]; i++)
	{
		x[i] = ((consolewidth / 4) * 3) - 1;
		y[i] = i + ((consoleheight - active[1]) / 2) - (COUNT / 2);
		course[i] = '8';
	}
	
	// Generate new x and y for berry
	for(actualBerry = 0; actualBerry <= 1; actualBerry++)
	{
		do
		{
			x[COUNT + actualBerry] = rand() % consolewidth;
			y[COUNT + actualBerry] = rand() % consoleheight;
			
			// Determine if there is collision with some body
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
		// Generate new X and Y for berry if there is collision with some body or with another berry or when berry is in bottom right corner
		// Console size must be decreased by 1 because of body (X axis) and first line (Y axis)
		} while(i != (COUNT / 2) + active[1] || (x[COUNT + actualBerry] == consolewidth - 1 && y[COUNT + actualBerry] == consoleheight - 1) || y[COUNT + actualBerry] == y[COUNT + (actualBerry == 0 ? 1 : 0)]);
	}
	
	// Main game cycle
	while(1)
	{
		// Arrange by Y
		for(i = 0; i < COUNT + 2; i++)
		{
			min = i;
			
			// Find smallest Y and write its index to min
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
				
				temp = course[i];
				course[i] = course[min];
				course[min] = temp;
				
				temp = order[i];
				order[i] = order[min];
				order[min] = temp;
			}
		}
		
		// Print snake
		for(i = 0; i < active[0] + active[1] + 2; i++)
		{
			// Continue if there were more bodies in previous row
			if((y[i] == y[i - 1]) && !(y[0] == 0 && i == 0))
			{
				continue;
			}
			
			// Reset values
			inRow = 0;
			
			for(j = 0; j < COUNT + 2; j++)
			{
				xTemp[j] = consolewidth + 1;
			}
			
			// Assign relative positions
			yRelative = (i == 0 ? y[i] : (y[i] - y[i - 1]));
			
			for(j = 0; j < active[0] + active[1] + 2; j++)
			{
				if(y[i] == y[j])
				{
					xTemp[j] = x[j];
					inRow++;
				}
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
			
			// Get to yRelative row
			repeat('\n', yRelative - (overflow == consolewidth && i != 0 ? 1 : 0));
			
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
		
		Sleep(WAIT);
		system("cls");
		
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
				
				temp = course[i];
				course[i] = course[min];
				course[min] = temp;
				
				temp = order[i];
				order[i] = order[min];
				order[min] = temp;
			}
		}
		
		// Copy course to histCourse before new assign of course[0]
		if(collision[0] == false)
		{
			for(i = 0; i < active[0]; i++)
			{
				histCourse[i] = course[i];
			}
		}
		
		if(collision[1] == false)
		{
			for(i = COUNT / 2; i < (COUNT / 2) + active[1]; i++)
			{
				histCourse[i] = course[i];
			}
		}
		
		// Get new course for heads
		gotNewCourse[0] = gotNewCourse[1] = false;
		
		if(kbhit() == true)
		{
			temp = getch();
			
			if(temp >= 97 && temp <= 122)
			{
				temp -= 32;
			}
			
			if(collision[0] == false && ((temp == 'W' || temp == 'A' || temp == 'S' || temp == 'D')
				&& temp != (course[0] == 'W' ? 'S' : (course[0] == 'S' ? 'W' : (course[0] == 'A' ? 'D' : 'A')))
				))
			{
				course[0] = temp;
				gotNewCourse[0] = true;
			}
			else if(collision[1] == false && ((temp == '8' || temp == '4' || temp == '5' || temp == '6')
				&& temp != (course[COUNT / 2] == '8' ? '5' : (course[COUNT / 2] == '5' ? '8' : (course[COUNT / 2] == '4' ? '6' : '4')))
				))
			{
				course[COUNT / 2] = temp;
				gotNewCourse[1] = true;
			}
			else if(temp == 27)
			{
				if(pausemenu(true) == true)
				{
					return;
				}
			}
		}
		
		if(collision[0] == false && collision[1] == false && kbhit() == true)
		{
			temp = getch();
			
			if(temp >= 97 && temp <= 122)
			{
				temp -= 32;
			}
			
			if(gotNewCourse[0] == false && collision[0] == false && ((temp == 'W' || temp == 'A' || temp == 'S' || temp == 'D')
				&& temp != (course[0] == 'W' ? 'S' : (course[0] == 'S' ? 'W' : (course[0] == 'A' ? 'D' : 'A')))
				))
			{
				course[0] = temp;
				gotNewCourse[0] = true;
			}
			else if(gotNewCourse[1] == false && collision[1] == false && ((temp == '8' || temp == '4' || temp == '5' || temp == '6')
				&& temp != (course[COUNT / 2] == '8' ? '5' : (course[COUNT / 2] == '5' ? '8' : (course[COUNT / 2] == '4' ? '6' : '4')))
				))
			{
				course[COUNT / 2] = temp;
				gotNewCourse[1] = true;
			}
			else if(temp == 27)
			{
				if(pausemenu(true) == true)
				{
					return;
				}
			}
		}
		
		// Change positions
		if(collision[0] == false)
		{
			x[0] += (course[0] == 'A' ? -1 : (course[0] == 'D' ? 1 : 0));
			y[0] += (course[0] == 'W' ? -1 : (course[0] == 'S' ? 1 : 0));
			
			for(i = 1; i < active[0]; i++)
			{
				course[i] = histCourse[i - 1];
				
				x[i] += (course[i] == 'A' ? -1 : (course[i] == 'D' ? 1 : 0));
				y[i] += (course[i] == 'W' ? -1 : (course[i] == 'S' ? 1 : 0));
			}
		}
		
		if(collision[1] == false)
		{
			x[COUNT / 2] += (course[COUNT / 2] == '4' ? -1 : (course[COUNT / 2] == '6' ? 1 : 0));
			y[COUNT / 2] += (course[COUNT / 2] == '8' ? -1 : (course[COUNT / 2] == '5' ? 1 : 0));
			
			for(i = (COUNT / 2) + 1; i < (COUNT / 2) + active[1]; i++)
			{
				course[i] = histCourse[i - 1];
				
				x[i] += (course[i] == '4' ? -1 : (course[i] == '6' ? 1 : 0));
				y[i] += (course[i] == '8' ? -1 : (course[i] == '5' ? 1 : 0));
			}
		}
		
		// Collision with console borders
		// Console size must be decreased by 1 because of body (X axis) and first line (Y axis)
		if(BORDERS == true)
		{
			if(collision[0] == false && (x[0] < 0 || x[0] > consolewidth - 1 || y[0] < 0 || y[0] > consoleheight - 1))
			{
				collision[0] = true;
			}
			
			if(collision[1] == false && (x[COUNT / 2] < 0 || x[COUNT / 2] > consolewidth - 1 || y[COUNT / 2] < 0 || y[COUNT / 2] > consoleheight - 1))
			{
				collision[1] = true;
			}
		}
		// Moving snakes to opposite console edge
		else
		{
			if(collision[0] == false)
			{
				for(i = 0; i < active[0]; i++)
				{
					if(x[i] < 0)
					{
						x[i] = consolewidth - 1;
					}
					else if(x[i] > consolewidth - 1)
					{
						x[i] = 0;
					}
					else if(y[i] < 0)
					{
						y[i] = consoleheight - 1;
					}
					else if(y[i] > consoleheight - 1)
					{
						y[i] = 0;
					}
				}
			}
			
			if(collision[1] == false)
			{
				for(i = COUNT / 2; i < (COUNT / 2) + active[1]; i++)
				{
					if(x[i] < 0)
					{
						x[i] = consolewidth - 1;
					}
					else if(x[i] > consolewidth - 1)
					{
						x[i] = 0;
					}
					else if(y[i] < 0)
					{
						y[i] = consoleheight - 1;
					}
					else if(y[i] > consoleheight - 1)
					{
						y[i] = 0;
					}
				}
			}
		}
		
		// Eating berry
		if(collision[0] == false)
		{
			for(actualBerry = 0; actualBerry <= 1; actualBerry++)
			{
				if(x[0] == x[COUNT + actualBerry] && y[0] == y[COUNT + actualBerry])
				{
					// Create new body
					// Course does't have to be assigned here. It will be assigned from histCourse in next cycle
					x[active[0]] = x[active[0] - 1] + (course[active[0] - 1] == 'A' ? 1 : (course[active[0] - 1] == 'D' ? -1 : 0));
					y[active[0]] = y[active[0] - 1] + (course[active[0] - 1] == 'W' ? 1 : (course[active[0] - 1] == 'S' ? -1 : 0));
					
					active[0]++;
					
					// Generate new x and y for berry
					do
					{
						x[COUNT + actualBerry] = rand() % consolewidth;
						y[COUNT + actualBerry] = rand() % consoleheight;
						
						// Determine if there is collision with some body
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
					// Generate new X and Y for berry if there is collision with some body or with another berry or when berry is in bottom right corner
					// Console size must be decreased by 1 because of body (X axis) and first line (Y axis)
					} while(i != (COUNT / 2) + active[1] || (x[COUNT + actualBerry] == consolewidth - 1 && y[COUNT + actualBerry] == consoleheight - 1) || y[COUNT + actualBerry] == y[COUNT + (actualBerry == 0 ? 1 : 0)]);
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
					// Course does't have to be assigned here. It will be assigned from histCourse in next cycle
					x[(COUNT / 2) + active[1]] = x[(COUNT / 2) + active[1] - 1] + (course[(COUNT / 2) + active[1] - 1] == '4' ? 1 : (course[(COUNT / 2) + active[1] - 1] == '6' ? -1 : 0));
					y[(COUNT / 2) + active[1]] = y[(COUNT / 2) + active[1] - 1] + (course[(COUNT / 2) + active[1] - 1] == '8' ? 1 : (course[(COUNT / 2) + active[1] - 1] == '5' ? -1 : 0));
					
					active[1]++;
					
					// Generate new x and y for berry
					do
					{
						x[COUNT + actualBerry] = rand() % consolewidth;
						y[COUNT + actualBerry] = rand() % consoleheight;
						
						// Determine if there is collision with some body
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
					// Generate new X and Y for berry if there is collision with some body or with another berry or when berry is in bottom right corner
					// Console size must be decreased by 1 because of body (X axis) and first line (Y axis)
					} while(i != (COUNT / 2) + active[1] || (x[COUNT + actualBerry] == consolewidth - 1 && y[COUNT + actualBerry] == consoleheight - 1) || y[COUNT + actualBerry] == y[COUNT + (actualBerry == 0 ? 1 : 0)]);
				}
			}
		}
		
		// Collision between snakes heads and all bodies
		if(collision[0] == false)
		{
			// Collision with first snake bodies
			for(i = 1; i < active[0]; i++)
			{
				if(x[0] == x[i] && y[0] == y[i])
				{
					collision[0] = true;
					break;
				}
			}
			
			// Collision with second snake
			if(collision[1] == false)
			{
				for(i = COUNT / 2; i < (COUNT / 2) + active[1]; i++)
				{
					if(x[0] == x[i] && y[0] == y[i])
					{
						collision[0] = collision[1] = true;
						break;
					}
				}
			}
		}
		
		if(collision[1] == false)
		{
			// Collision with second snake bodies
			for(i = (COUNT / 2) + 1; i < (COUNT / 2) + active[1]; i++)
			{
				if(x[COUNT / 2] == x[i] && y[COUNT / 2] == y[i])
				{
					collision[1] = true;
					break;
				}
			}
			
			// Collision with first snake bodies
			if(collision[0] == false)
			{
				for(i = 0; i < active[0]; i++)
				{
					if(x[COUNT / 2] == x[i] && y[COUNT / 2] == y[i])
					{
						collision[0] = collision[1] = true;
						break;
					}
				}
			}
		}
		
		// Reset dead snakes
		// When only one snake is dead to save some time and not reset both snakes when both are dead
		if(collision[0] == true && collision[1] == false && active[0] != 0)
		{
			for(i = 0; i < active[0]; i++)
			{
				x[i] = y[i] = 100;
				course[i] = 'X';
			}
			
			score[0] = active[0];
			active[0] = 0;
		}
		
		if(collision[1] == true && collision[0] == false && active[1] != 0)
		{
			for(i = COUNT / 2; i < (COUNT / 2) + active[1]; i++)
			{
				x[i] = y[i] = 100;
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
